/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmeising <mmeising@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/09 18:23:22 by mmeising          #+#    #+#             */
/*   Updated: 2022/02/25 16:57:13 by mmeising         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include "libft.h"
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <readline/readline.h>
# include <readline/history.h>
# include <termios.h>
# include <string.h>
# include <signal.h>
# include <sys/wait.h>
# include <sys/types.h>
# include <fcntl.h>
# include <string.h>
# include <errno.h>

# define TRUE 1
# define FALSE 0

# define PROMT "minishell$"

typedef struct s_node
{
	char			*value;
	int				type;	
	int				index;

	struct s_node	*next;
}	t_node;

typedef enum e_type
{
	INFILE,
	OUTFILE,
	HEREDOC,
	APPEND,
	MALLOC,
	NO_PATHS
}	t_type;

typedef enum e_error
{
	PIPE,
	FORK
}	t_error;

typedef struct s_files
{
	char			*file;
	t_type			type;
	struct s_file	*next;
}		t_files;

typedef struct s_cmd
{
	t_files			*in_out_files;
	char			**cmd;
	struct s_cmd	*next;
}		t_cmd;

void	error(t_error err);

#endif