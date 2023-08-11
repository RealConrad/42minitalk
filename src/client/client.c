/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwenz <cwenz@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/11 15:33:09 by cwenz             #+#    #+#             */
/*   Updated: 2023/08/11 18:56:03 by cwenz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

char	*get_bits(char c)
{
	static char	bits[9];
	int		i;

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

	i = 0;
	length = ft_strlen(message);
	result = ft_calloc(1, sizeof(char) * (length * 9));
	if (!result)
		error_and_exit(FAIL, "Failed to allocate memory.");
	while (message[i])
	{
		ft_strlcat(result, get_bits(message[i]), (i + 1) * 9);
		i++;
	}
	result[length * 9 - 1] = '\0';
	return (result);
}

int	main(int argc, char **argv)
{
	int		pid;
	int		i;
	char	*message_in_binary;
	if (argc != 3)
		error_and_exit(FAIL, "Invalid number of command line arguments.");
	i = 0;
	pid	= ft_atoi(argv[1]);
	message_in_binary = convert_string_to_binary(argv[2]);
	
	while (message_in_binary[i])
	{
		if (message_in_binary[i] == '0')
			kill(pid, SIGUSR1);
		else
			kill(pid, SIGUSR2);
		i++;
	}
	return (SUCCESS);
}
