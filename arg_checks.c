/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arg_checks.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hakotu <hakotu@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/23 15:38:58 by hakotu            #+#    #+#             */
/*   Updated: 2025/03/10 13:58:28 by hakotu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	check_spaces(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == ' ')
			return (1);
		i++;
	}
	return (0);
}

static int	is_valid_number(char *str)
{
	int	i;

	i = 0;
	if (str[i] == '-' || str[i] == '+')
		i++;
	if (!str[i])
		return (0);
	while (str[i])
	{
		if (!ft_isdigit(str[i]))
			return (0);
		i++;
	}
	return (1);
}

char	**read_numbers(char **argv, int argc)
{
	char	**str;
	int		i;

	if (argc == 2)
	{
		if (check_spaces(argv[1]))
			return (ft_split(argv[1], ' '));
		str = (char **)malloc(sizeof(char *) * 2);
		if (!str)
			return (NULL);
		str[0] = ft_strdup(argv[1]);
		str[1] = NULL;
		return (str);
	}
	str = (char **)malloc(sizeof(char *) * argc);
	if (!str)
		return (NULL);
	i = -1;
	while (++i < argc - 1)
		str[i] = ft_strdup(argv[i + 1]);
	str[i] = NULL;
	return (str);
}

char	**argumans_controller(char **argv, int argc)
{
	char	**str;
	int		i;

	str = read_numbers(argv, argc);
	if (!str)
		return (NULL);
	i = 0;
	while (str[i])
	{
		if (!is_valid_number(str[i]))
		{
			i = 0;
			ft_printf("Error\n");
			while (str[i])
				free(str[i++]);
			free(str);
			exit(1);
		}
		i++;
	}
	return (str);
}

void	is_arg_digit(t_stack **a)
{
	t_stack	*head;
	long	num;

	if (!a || !*a)
		return ;
	head = *a;
	while (head)
	{
		num = head->data;
		if (num < INT_MIN || num > INT_MAX)
		{
			ft_printf("Error\n");
			exit(1);
		}
		head = head->next;
	}
}

void	is_arg_same(t_stack **a)
{
	t_stack	*head;
	t_stack	*current;

	if (!a || !*a)
		return ;
	head = *a;
	while (head)
	{
		current = head->next;
		while (current)
		{
			if (head->data == current->data)
			{
				ft_printf("Error\n");
				exit(1);
			}
			current = current->next;
		}
		head = head->next;
	}
}
 //is_arg_null(argv);
 // argüman 2 ikise bunu kontrol et gerçekten bir sayımı var yoksa çift tırnak mı?
 