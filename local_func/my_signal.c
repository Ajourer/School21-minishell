/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   my_signal.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nagrivan <nagrivan@21-school.ru>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/27 15:01:30 by nagrivan          #+#    #+#             */
/*   Updated: 2021/11/12 13:41:06 by nagrivan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	my_sigint(int signal)
{
	(void)signal;
	rl_on_new_line();
	rl_redisplay();
	write(1, "  \n", 3);
	rl_on_new_line();
	rl_replace_line("", 0);
	rl_redisplay();
	exit_status = 1;
}

void	my_sigquit(int signal)
{
	(void)signal;
	rl_on_new_line();
	rl_redisplay();
	write(1, "  \b\b", 4);
	exit_status = 0;
}

void	signal_on(void)
{
	signal(SIGQUIT, my_sigquit);
	signal(SIGINT, my_sigint);
}

void	signal_off(void)
{
	signal(SIGQUIT, SIG_IGN);
	signal(SIGINT, SIG_IGN);
}

void	signal_dother(int status)
{
	if (WTERMSIG(status) == 2)
	{
		exit_status = 130;
		write(1, "\n", 1);
	}
	if (WTERMSIG(status) == 3)
	{
		write(1, " \bQuit: 3\n", 10);
		exit_status = 131;
	}
}

static void	my_sigint_her(int signal)
{
	(void)signal;
	write(0, "\b\b  \b\b", 6);
	exit_status = 130;
	exit(130);
}

static void	my_sigquit_her(int signal)
{
	(void)signal;
	write(0, "\b\b  \b\b", 6);
	exit_status = 0;
}

void	signal_on_her(void)
{
	signal(SIGQUIT, my_sigquit_her);
	signal(SIGINT, my_sigint_her);
}