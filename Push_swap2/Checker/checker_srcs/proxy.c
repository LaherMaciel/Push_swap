/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   proxy.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lwencesl <lwencesl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/27 13:55:49 by lwencesl          #+#    #+#             */
/*   Updated: 2023/05/27 13:56:51 by lwencesl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

char	**proxy_cut(char commands[])
{
	char	**vals;

	vals = the_split(commands);
	if (!vals)
		return (NULL);
	return (vals);
}

void	proxy_cut2(t_stack **stack_a, t_stack **stack_b,
	char **vals, char *commands)
{
	int	i;

	i = -1;
	while (vals[++i] != NULL)
	{
		vals[i] = commands_check_aux2(&vals[i], 0);
		if (user_sort(stack_a, stack_b, vals[i]) == 0)
		{
			while (vals[i])
				free(vals[i++]);
			free(vals);
			free(commands);
			exit (1);
		}
		free(vals[i]);
	}
}

// if the user introduz the numbers and the commands or just numbers | main
void	proxy(t_stack **stack_a, t_stack **stack_b)
{
	char	*commands;
	char	**vals;

	commands = get_next_line(0);
	if (commands == NULL)
		return ;
	while (commands != NULL && ft_strncmp(commands, "  ", 2))
	{
		vals = proxy_cut(commands);
		if (!vals)
		{
			free(vals);
			free(commands);
			return ;
		}
		proxy_cut2(**stack_a, **stack_b, **vals, *commands);
		free(vals);
		free(commands);
		commands = get_next_line(0);
	}
	end_code(stack_a, stack_b, commands);
}
