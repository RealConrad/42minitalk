/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwenz <cwenz@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/19 14:20:39 by cwenz             #+#    #+#             */
/*   Updated: 2023/08/19 15:31:53 by cwenz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

char	*get_bits(char c)
{
	char	*bits;
	int		i;

	bits = ft_calloc(1, sizeof(char) * 9);
	i = 0;
	while (i < 8)
	{
		if (c & (1 << i))
			bits[7 - i] = '1';
		else
			bits[7 - i] = '0';
		i++;
	}
	return (bits);
}

char	*convert_string_to_binary(char *message)
{
	int		i;
	int		length;
	char	*result;
	char	*bits;

	i = 0;
	length = ft_strlen(message) + 1;
	result = ft_calloc(1, sizeof(char) * (length * 8));
	if (!result)
		error_and_exit(FAIL, "Failed to allocate memory.");
	while (i < length)
	{
		bits = get_bits(message[i]);
		ft_strlcat(result, bits, ((i + 1) * 8) + 1);
		i++;
		free(bits);
	}
	return (result);
}
