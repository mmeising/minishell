/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmeising <mmeising@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/09 18:22:43 by mmeising          #+#    #+#             */
/*   Updated: 2022/03/17 02:31:33 by mmeising         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/*
 *	test hier und so
 */
char	**get_paths(char **envp)
{
	int		i;
	char	**temp;
	char	**paths;

	i = 0;
	while (envp[i] && (ft_strncmp(envp[i], "PATH=", 5) != 0))
		i++;
	if (envp[i] == NULL)
		error(NO_PATHS);
	temp = ft_split(envp[i] + 5, ':');
	i = ft_2d_char_len(temp);
	paths = malloc(sizeof(*paths) * (i + 1));
	if (paths == NULL)
		return (NULL);
	i = 0;
	while (temp[i])
	{
		paths[i] = ft_strjoin(temp[i], "/");
		free(temp[i]);
		i++;
	}
	paths[i] = NULL;
	free(temp);
	return (paths);
}

int	get_cmd_count(t_cmd	*cmd_list)
{
	int	cmd_count;

	cmd_count = 0;
	while (cmd_list)
	{
		cmd_count++;
		cmd_list = cmd_list->next;
	}
	return (cmd_count);
	// need cmd_count - 1 pipes and cmd_count forks
	// have to close all but 
	// while (iterator < maximum && pid != 0)
	// 	pid = fork();
	// i indicates if first, one of middle, or last cmd! and how often need to go to cmd->next
	// at end: while (wait(NULL) != -1 || errno != ECHILD);
}

//	piping has to set the redirs before redirections function does it
//	because redirections overwrite the pipe redirection
void	redirections(t_cmd *cmd)
{
	t_files	*red;

	red = cmd->redirs;
	while (red)
	{
		if (cmd->fd_in  > 2 && (red->type == IN || red->type == HEREDOC))
		{
			close(cmd->fd_in);
			cmd->fd_in = 0;
		}
		else if (cmd->fd_out > 2 && (red->type == OUT || red->type == APPEND))
		{
			close(cmd->fd_out);
			cmd->fd_out = 0;
		}
		if (red->type == IN)
			cmd->fd_in = open(red->file, O_RDONLY, 0644);
		else if (red->type == HEREDOC)
			do_heredoc();//heredoc behaviour, need to implement this
		else if (red->type == OUT)
			cmd->fd_out = open(red->file, O_WRONLY | O_CREAT | O_TRUNC, 0644);
		else if (red->type == APPEND)
			cmd->fd_out = open(red->file, O_WRONLY | O_CREAT | O_APPEND, 0644);
		red = red->next;
	}
}

//	close write-end of pipe and wait for child
//	maybe don't wait for the child, open file descriptors take care of waiting
void	parent(int pid, int *fd)
{
	close(fd[1]);
	close(fd[0]);
	// waitpid(pid, NULL, 0);
}

//	go through all redirections, dup the redirs into stdin and stdout, execve
void	child(t_cmd *cmds, char **envp)
{
	if (cmds->redirs)
		redirections(cmds);
}

void	free_cmd_struct(t_cmd **cmd_addr)
{
	while ((*cmd_addr)->redirs)
	{
		free((*cmd_addr)->redirs->file);
		(*cmd_addr)->redirs = (*cmd_addr)->redirs->next;
	}
	while (*((*cmd_addr)->cmd))//does this work like this? does it point to one string in the 2d array?
	{
		free(*((*cmd_addr)->cmd));
		*((*cmd_addr)->cmd) += sizeof(char *);//does this make the pointer point to the next string?
	}
}

t_cmd	*cmds_free_and_next(t_cmd **cmds_addr)
{
	t_cmd	*temp;

	temp = *cmds_addr;
	*cmds_addr = (*cmds_addr)->next;
	free_cmd_struct(&temp);
}

int	piping(t_cmd *cmds, char **envp)
{
	char	**paths;
	// int		i;
	// int		cmd_count;
	int		fd[2];
	int		pid;

	// i = 0;
	(void)envp;
	paths = get_paths(envp);
	// cmd_count = get_cmd_count(cmds);
	// while (paths[i])
	// {
	// 	printf("%s\n", paths[i]);
	// 	free(paths[i]);
	// 	i++;
	// }
	// free(paths);
	// printf("cmd_count: %i\n", cmd_count);

	// here_doc_prep(cmds);
	while (cmds)
	{
		if (pipe(fd) < 0)
			error(PIPE);
		pid = fork();
		if (pid < 0)
			error(FORK);
		else if (pid == 0)
			child(cmds, envp);//child
		else
		{
			parent(pid, fd);
			// exit(4);//parent
		}
		cmds = cmds_free_and_next(&cmds);
	}
	return (0);
}

int	main(int argc, char **argv, char **envp)
{
	t_cmd	*cmds;

	(void)argc;
	(void)argv;
	cmds = malloc (sizeof(*cmds));
	if (cmds == NULL)
		return (5);
	cmds->redirs = NULL;
	cmds->cmd = ft_split("ls -l", ' ');
	cmds->next = NULL;
	piping(cmds, envp);
	ft_free_2d_char(&(cmds->cmd));
	free(cmds);
}
