/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muxammad <muxammad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/21 18:38:02 by mukibrok          #+#    #+#             */
/*   Updated: 2025/01/05 08:57:58 by muxammad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/checker.h"

// checks if number contains any alpha
bool	ft_iserror(char **argv)
{
	int	i;
	int	j;

	i = 0;
	while (argv[i])
	{
		j = 0;
		while (argv[i][j])
		{
			if (!ft_isdigit(argv[i][j]))
				return (true);
			j++;
		}
		i++;
	}
	return (false);
}

// if already sorted
bool	ft_sorted(t_list *stack)
{
	while (stack->next)
	{
		if (stack->content > stack->next->content)
			return (false);
		stack = stack->next;
	}
	return (true);
}

// checks if numbers are doubled
bool	ft_isdouble(t_list *stack)
{
	t_list	*seen;
	t_list	*temp;

	seen = NULL;
	while (stack)
	{
		temp = seen;
		while (temp)
		{
			if (temp->content == stack->content)
				return (ft_free(&seen), true);
			temp = temp->next;
		}
		ft_lstadd_back(&seen, ft_lstnew(stack->content));
		stack = stack->next;
	}
	return (ft_free(&seen), false);
}

// free stack
void	ft_free(t_list **stack)
{
	t_list	*tmp;

	if (!stack)
		return ;
	while (*stack)
	{
		tmp = *stack;
		*stack = (*stack)->next;
		free(tmp);
	}
}

void	ft_free_arr(char **arr)
{
	int	i;

	i = 0;
	if (!arr)
		return ;
	while (arr[i])
	{
		free(arr[i]);
		i++;
	}
	free(arr);
}
