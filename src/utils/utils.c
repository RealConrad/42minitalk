/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwenz <cwenz@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/15 16:01:32 by cwenz             #+#    #+#             */
/*   Updated: 2023/08/16 15:24:10 by cwenz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	send_signal_back_to_client(siginfo_t *sig_info)
{
	if (server_data.byte == '\0')
		kill(sig_info->si_pid, SIGUSR1);
}
