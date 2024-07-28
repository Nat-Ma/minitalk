/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nrauh <nrauh@student.42berlin.de>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/28 15:20:46 by nrauh             #+#    #+#             */
/*   Updated: 2024/07/28 17:52:21 by nrauh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	*char_to_bit(char c)
{
	int	i;
	int	bits[8];

	i = 8;
	while (i--)
		bits[i] = (c << (7 - i) & 1);
	return (bits);
}

int	main(int argc, char**argv)
{
	(void)argv;

	if (argc == 3)
	{
		// first argv is PID
		// second argv is message
		// encrypt the message via bits
		// send message to the server via PID
		// create a stop condition for server once message is finished
		return (0);
	}
	return (0);
}
