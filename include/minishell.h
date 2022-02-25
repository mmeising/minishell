/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmeising <mmeising@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/09 18:23:22 by mmeising          #+#    #+#             */
/*   Updated: 2022/02/09 18:23:22 by mmeising         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include "libft.h"
# include <signal.h>
# include <sys/wait.h>
# include <sys/types.h>
# include <fcntl.h>
# include <string.h>
# include <errno.h>

# define EXIT_NO_PATHS 2//couldn't find PATH= in envp
# define E_MALLOC_FAIL 3//malloc failed

typedef enum e_type
{
	INFILE,
	OUTFILE,
	HEREDOC,
	APPEND
}	t_type;

typedef enum e_error
{
	PIPE,
	FORK
}	t_error;

typedef struct s_files
{
	char	*file;
	t_type	type;
	struct s_file *next;
}		t_files;

typedef struct s_cmd
{
	t_files			*in_out_files;
	char			**cmd;
	struct s_cmd	*next;
}		t_cmd;

// typedef struct s_list
// {

// 	struct s_list	*next;
// }		t_list;
#endif