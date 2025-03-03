/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arg_checks.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hakotu <hakotu@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/23 15:38:58 by hakotu            #+#    #+#             */
/*   Updated: 2025/03/03 12:41:14 by hakotu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int check_spaces(char *str)
{
    int i;

    i = 0;
    while (str[i])
    {
        if (str[i] == ' ')
            return (1);
        i++;
    }
    return (0);
}

char **read_numbers(char **argv, int argc)
{
    char **str;
    int i;

    if (argc > 2)
    {
        str = (char **)malloc(sizeof(char *) * argc);
        if (!str)
            return (NULL); // Bellek ayrılmazsa NULL döndür
        i = 0;
        while (i < argc - 1)
        {
            str[i] = argv[i + 1]; // argv[0] program adı olduğu için atlanıyor
            i++;
        }
        str[i] = NULL; // Sonlandırıcı olarak NULL ekle
    }
    else
    {
        if (check_spaces(argv[1]))
            str = ft_split(argv[1], ' '); // Tek argüman boşluk içeriyorsa split
        else
            str = &argv[1]; // Boşluk yoksa argümanı doğrudan kullan
    }
    return (str);
}

char **argumans_controller(char **argv, int argc)
{
    char **str;

    str = read_numbers(argv, argc);
    if (!str)
    {
        // Hata işleme
        return (NULL);
    }
    return (str);
}
 //is_arg_null(argv);
 // argüman 2 ikise bunu kontrol et gerçekten bir sayımı var yoksa çift tırnak mı?
 