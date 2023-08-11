/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwenz <cwenz@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/11 15:29:38 by cwenz             #+#    #+#             */
/*   Updated: 2023/08/11 16:47:23 by cwenz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	message_handler(int signum)
{
	ft_printf("Received SIGUSR1: %d\n", signum);
	exit(SUCCESS);
}

int	main() {
	ft_printf("Server PID: %d\n", getpid());
	
	struct sigaction action;
	sigemptyset(&action.sa_mask);
	sigaddset(&action.sa_mask, SIGUSR1);
	action.sa_handler = message_handler;
	sigaction(SIGUSR1, &action, NULL);

	while (1) {
		pause();
	}

	return 0;
}