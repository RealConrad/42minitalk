/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwenz <cwenz@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/15 16:01:32 by cwenz             #+#    #+#             */
/*   Updated: 2023/08/16 16:21:20 by cwenz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

static void	print_acknowledgement(int signo);

void	send_signal_back_to_client(siginfo_t *sig_info)
{
	if (server_data.byte == '\0')
	{
		kill(sig_info->si_pid, SIGUSR1);
		write(1, "\n", 1);
	}
}

void	setup_confirmation_from_server()
{
	struct sigaction	client;
	
	client.sa_handler = print_acknowledgement;
	client.sa_flags = 0;
	sigaction(SIGUSR1, &client, NULL);
}

static void	print_acknowledgement(int signo)
{
	(void)signo;
	write(1, "Server recevied message!\n", 26);
}
