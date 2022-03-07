/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrasser <jrasser@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/07 17:03:47 by jrasser           #+#    #+#             */
/*   Updated: 2022/03/07 21:04:18 by jrasser          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>
#include <stdarg.h>

int AddNumbers(int n, ...)
{
    int Sum = 0;
 
    va_list ptr;
    va_start(ptr, n);
    for (int i = 0; i < n; i++)
        Sum += va_arg(ptr, int);
    va_end(ptr);
    return Sum;
}

int	main(void)
{
	printf("test int : %d\n", 123);
	ft_printf("test str : %s\n", "testtesteteteteteeee");
	
	//printf("sum : %d\n", AddNumbers(5, 1, 2, 3, 4, 5));

	return (0);
}
