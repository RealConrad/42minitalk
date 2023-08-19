/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwenz <cwenz@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/15 16:01:32 by cwenz             #+#    #+#             */
/*   Updated: 2023/08/19 15:08:49 by cwenz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

static void	send_signal_back_to_client(siginfo_t *sig_info, char byte);

bool	check_byte_printable(siginfo_t *sig_info, char *byte, int num_bits)
{
	kill(sig_info->si_pid, SIGUSR2);
	if (num_bits == 8)
	{
		write(1, byte, 1);
		send_signal_back_to_client(sig_info, *byte);
		*byte = 0;
		return (true);
	}
	return (false);
}

static void	send_signal_back_to_client(siginfo_t *sig_info, char byte)
{
	if (byte == '\0')
	{
		kill(sig_info->si_pid, SIGUSR1);
		write(1, "\n", 1);
	}
}

