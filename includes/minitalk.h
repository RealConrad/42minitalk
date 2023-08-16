/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwenz <cwenz@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/10 16:22:32 by cwenz             #+#    #+#             */
/*   Updated: 2023/08/16 13:31:01 by cwenz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H

# include <unistd.h>
# include <signal.h>
# include <stdlib.h>

/* Include libraries */
# include "../libraries/42c-library/c_library.h" 

typedef enum e_error_type {
	FAIL = 1,
	SUCCESS = 0,
}	t_error_type;

typedef struct s_signal_data {
	struct sigaction	sa0;
	struct sigaction	sa1;
	int					num_bits_received;
	char				byte;
}	t_signal_data;

t_signal_data	server_data;

/* Error */
void	error_and_exit(t_error_type error_type, char *error_msg);

/* Client */
void	setup_confirmation_from_server();

/* Utils */
void	send_signal_back_to_client(siginfo_t *sig_info);

# endif /* MINITALK_H */
