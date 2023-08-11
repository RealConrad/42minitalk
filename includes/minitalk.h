/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwenz <cwenz@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/10 16:22:32 by cwenz             #+#    #+#             */
/*   Updated: 2023/08/11 18:28:30 by cwenz            ###   ########.fr       */
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


/* Error */
void	error_and_exit(t_error_type error_type, char *error_msg);

# endif /* MINITALK_H */
