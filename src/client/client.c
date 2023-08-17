/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwenz <cwenz@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/11 15:33:09 by cwenz             #+#    #+#             */
/*   Updated: 2023/08/17 14:59:24 by cwenz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

static void	send_bit_to_server(pid_t pid, char bit);
static char	*convert_string_to_binary(char *message);
static char	*get_bits(char c);

int	main(int argc, char **argv)
{
	int		pid;
	int		i;
	char	*message_in_binary;

	if (argc != 3)
		error_and_exit(FAIL, "Invalid number of command line arguments.");
	i = 0;
	setup_confirmation_from_server();
	pid = ft_atoi(argv[1]);
	message_in_binary = convert_string_to_binary(argv[2]);
	while (message_in_binary[i])
	{
		send_bit_to_server(pid, message_in_binary[i]);
		i++;
	}
	free(message_in_binary);
	message_in_binary = NULL;
	return (SUCCESS);
}

static char	*get_bits(char c)
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

static char	*convert_string_to_binary(char *message)
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

static void	send_bit_to_server(pid_t pid, char bit)
{
	if (bit == '0')
		kill(pid, SIGUSR1);
	else if (bit == '1')
		kill(pid, SIGUSR2);
	usleep(80);
}
