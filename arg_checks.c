/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arg_checks.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hakotu <hakotu@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/23 15:38:58 by hakotu            #+#    #+#             */
/*   Updated: 2025/02/28 17:47:12 by hakotu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	check_spaces(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == ' ' && !str[i])
			return (1);
		i++;
	}
	return (0);
}

char    **read_numbers(char **argv, int argc , char **str)
{
    int     i;
    char    **str;
    i = 0;
	if (argc > 2)
	{
		while (i < argv)
        {
            str[i] = argv[i];
            i++;
        }
	}
    else
    {
        str = ft_split(argv[1], ' ');
    }
    return (str);
}
void argumans_controller(char **argv, int argc)
{
	char **str;
	
	str = read_numbers(argv, argc, str);
	 

}
 //is_arg_null(argv);