/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmeising <mmeising@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/14 22:43:58 by rrajaobe          #+#    #+#             */
/*   Updated: 2022/02/25 17:06:03 by mmeising         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void handle_sigint(int sig)
{
	rl_on_new_line();
	rl_replace_line("", 0);
	rl_redisplay();

}


int main(int argc, char **argv)
{
	char	*arg;

	while (TRUE)
	{
		signal (SIGINT, handle_sigint);
		//signal(SIGQUIT, handle_sigint);
		signal(SIGQUIT, SIG_IGN);

		arg = readline(PROMT);

		add_history(arg);
		free(arg);
		if (argc == 2)
			printf("hello");
	
	}
	return (0);
}