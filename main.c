/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrasser <jrasser@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/07 17:03:47 by jrasser           #+#    #+#             */
/*   Updated: 2022/03/08 03:27:38 by jrasser          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

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
	char	*ptr;

	ptr = "test";

	printf("\n**********  STRING  ********\n");
	printf(   "real : %s apres\n", "coucou");
	ft_printf("mine : %s apres\n", "coucou");

	printf("\n**********  CHAR  ********\n");
	printf(   "real : %c\n", 't');
	ft_printf("mine : %c\n", 't');

	printf("\n**********  INT  ********\n");
	printf(	  "real : %d\n", -123.5);
	ft_printf("mine : %d\n", -123.5);

	printf("\n**********  ENTIER  ********\n");
	printf(	  "real : %i\n", 123.5);
	ft_printf("mine : %i\n", 123.5);

	printf("\n**********  UOCTAL  ********\n");
	printf(   "real : %o\n", 123);
	ft_printf("mine : %o\n", 123);

	printf("\n**********  UDECIMAL  ********\n");
	printf(   "real : %u\n", 40000000000);
	ft_printf("mine : %u\n", 40000000000);

	printf("\n**********  UDECIMAL  ********\n");
	printf(   "real : %u\n", -40);
	ft_printf("mine : %u\n", -40);

	printf("\n**********  UHexa  ********\n");
	printf(   "real : %x\n", 1456890);
	ft_printf("mine : %x\n", 1456890);

	printf("\n**********  UHexa  ********\n");
	printf(   "real : %X\n", 59856495489540);
	ft_printf("mine : %X\n", 59856495489540);

	printf("\n**********  UHexa  ********\n");
	printf(   "real : %x\n", -1);
	ft_printf("mine : %x\n", -1);

	printf("\n**********  LONG INT  ********\n");
	printf(   "real : %ld\n", 9223372036854775807);
	ft_printf("mine : %ld\n", 9223372036854775807);

	printf("\n**********  LONG INT  ********\n");
	printf(   "real : %ld\n", -54775807);
	ft_printf("mine : %ld\n", -54775807);

	printf("\n**********  LONG OCTAL  ********\n");
	printf(   "real : %lo\n", 54775807);
	ft_printf("mine : %lo\n", 54775807);

	printf("\n**********  LONG INT  ********\n");
	printf(   "real : %lu\n", -54775807);
	ft_printf("mine : %lu\n", -54775807);

	printf("\n**********  LONG INT  ********\n");
	printf(   "real : %%\n", -54775807);
	ft_printf("mine : %%\n", -54775807);

	printf("\n**********  LONG INT  ********\n");
	printf(   "real : %p\n", ptr);
	ft_printf("mine : %p\n", ptr);


	//printf("sum : %d\n", AddNumbers(5, 1, 2, 3, 4, 5));

	return (0);
}
