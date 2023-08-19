/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwenz <cwenz@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/10 16:22:32 by cwenz             #+#    #+#             */
/*   Updated: 2023/08/19 15:01:49 by cwenz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H

# include <unistd.h>
# include <signal.h>
# include <stdlib.h>
# include <stdbool.h>

/* Include libraries */
# include "../libraries/42c-library/c_library.h" 

typedef enum e_error_type {
	FAIL = 1,
	SUCCESS = 0,
}	t_error_type;

typedef struct s_signal_data {
	int		num_bits_received;
	char	byte;
}	t_signal_data;

/* Error */
void	error_and_exit(t_error_type error_type, char *error_msg);

/* Client */
char	*get_bits(char c);
char	*convert_string_to_binary(char *message);

/* Utils */
bool	check_byte_printable(siginfo_t *sig_info, char *byte, int num_bits);

#endif /* MINITALK_H */
