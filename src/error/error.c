/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwenz <cwenz@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/11 18:19:46 by cwenz             #+#    #+#             */
/*   Updated: 2023/08/11 18:25:10 by cwenz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	error_and_exit(t_error_type error_type, char *error_msg)
{
	ft_printf("Error\n%s\n", error_msg);
	exit(error_type);
}
