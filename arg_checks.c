/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arg_checks.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hakotu <hakotu@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/23 15:38:58 by hakotu            #+#    #+#             */
/*   Updated: 2025/02/23 16:45:49 by hakotu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void is_argv_empty(char **str)
{
    int i;

    i = 0;
    while (str[i])
    {
        if (!str[i][0] || (str[i][0] == ' ' && !str[i][1]))
            error();
        i++;
    }
    return(0);   
}
void argc_control(char **str, int argc)
{
    if (argc == 2)
    {
        ft_split();
    }
    
}