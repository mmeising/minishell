/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmeising <mmeising@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/09 18:22:43 by mmeising          #+#    #+#             */
/*   Updated: 2022/02/17 16:53:03 by mmeising         ###   ########.fr       */
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
		exit(EXIT_NO_PATHS);
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

int	piping(t_cmd *cmds, char **envp)
{
	char	**paths;
	int		i;
	int		cmd_count;
	int		fd[2];
	int		pid;

	i = 0;
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
	while (cmds)
	{
		if (pipe(fd) < 0)
			error(PIPE);
		pid = fork();
		if (pid < 0)
			error(FORK);
		
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
		return (E_MALLOC_FAIL);
	cmds->infiles = NULL;
	cmds->outfiles = NULL;
	cmds->flag_here_doc = 0;
	cmds->flag_append = 0;
	cmds->cmd = ft_split("ls -l", ' ');
	cmds->next = NULL;
	piping(cmds, envp);
	ft_free_2d_char(&(cmds->cmd));
	free(cmds);
}
