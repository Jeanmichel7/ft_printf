/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrasser <jrasser@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/07 17:03:47 by jrasser           #+#    #+#             */
/*   Updated: 2022/03/10 21:59:01 by jrasser          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_printf.h>
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
	printf("%d\n", printf(   "real : %s apres\n", "coucou"));
	printf("%d\n", ft_printf("mine : %s apres\n", "coucou"));

	printf("\n**********  CHAR  ********\n");
	printf("%d\n", printf(   "real : %c\n", 't'));
	printf("%d\n", ft_printf("mine : %c\n", 't'));

	printf("\n**********  INT  ********\n");
	printf("%d\n", printf(   "real : %d\n", -123.5));
	printf("%d\n", ft_printf("mine : %d\n", -123.5));

	printf("\n**********  ENTIER  ********\n");
	printf("%d\n", printf(	  "real : %i\n", 123.5));
	printf("%d\n", ft_printf("mine : %i\n", 123.5));

	printf("\n**********  UOCTAL  ********\n");
	printf("%d\n", printf(   "real : %o\n", 123));
	printf("%d\n", ft_printf("mine : %o\n", 123));

	printf("\n**********  UDECIMAL  ********\n");
	printf("%d\n", printf(   "real : %u\n", 40000000000));
	printf("%d\n", ft_printf("mine : %u\n", 40000000000));

	printf("\n**********  UDECIMAL  ********\n");
	printf("%d\n", printf(   "real : %u\n", -40));
	printf("%d\n", ft_printf("mine : %u\n", -40));

	printf("\n**********  UHexa  ********\n");
	printf("%d\n", printf(   "real : %x\n", 1456890));
	printf("%d\n", ft_printf("mine : %x\n", 1456890));

	printf("\n**********  UHexa  ********\n");
	printf("%d\n", printf(   "real : %X\n", 59856495489540));
	printf("%d\n", ft_printf("mine : %X\n", 59856495489540));

	printf("\n**********  UHexa  ********\n");
	printf("%d\n", printf(   "real : %x\n", -1));
	printf("%d\n", ft_printf("mine : %x\n", -1));

	printf("\n**********  LONG INT  ********\n");
	printf("%d\n", printf(   "real : %ld\n", 9223372036854775807));
	printf("%d\n", ft_printf("mine : %ld\n", 9223372036854775807));

	printf("\n**********  LONG INT  ********\n");
	printf("%d\n", printf(   "real : %ld\n", -54775807));
	printf("%d\n", ft_printf("mine : %ld\n", -54775807));

	printf("\n**********  LONG OCTAL  ********\n");
	printf("%d\n", printf(   "real : %lo\n", 54775807));
	printf("%d\n", ft_printf("mine : %lo\n", 54775807));

	printf("\n**********  LONG INT  ********\n");
	printf("%d\n", printf(   "real : %lu\n", -54775807));
	printf("%d\n", ft_printf("mine : %lu\n", -54775807));

	printf("\n**********  LONG INT  ********\n");
	printf("%d\n", printf(   "real : %%\n", -54775807));
	printf("%d\n", ft_printf("mine : %%\n", -54775807));

	printf("\n**********  LONG INT  ********\n");
	printf("%d\n", printf(   "real : %p\n", ptr));
	printf("%d\n", ft_printf("mine : %p\n", ptr));

	printf("\n**********  S NULL  ********\n");
	printf("%d\n", printf(   " NULL %s NULL", NULL));
	printf("%d\n", ft_printf(" NULL %s NULL", NULL));

	//printf("sum : %d\n", AddNumbers(5, 1, 2, 3, 4, 5));

	printf("\n**********  P  ********\n");
	printf("%d\n", printf(   " %p ", -1));
	printf("%d\n", ft_printf(" %p ", -1));

	printf("\n**********  P  ********\n");
	printf("%d\n", printf(   " %p ", 0));
	printf("%d\n", ft_printf(" %p ", 0));


	printf("\n\n**********  BONUS  ********\n");
	printf("%d\n", printf(   "%0 s %-s\n", "a que bla-- 0la0", "boub0lou"));
	printf("%d\n", ft_printf("-", 0));


	printf("\n**********  P  ********\n");
	printf("%-d\n",    42);
	printf("%-d\n",    42);
	printf("%0-.5d\n",  42);
	printf("%-5d\n\n", 42);

	printf("%0-s\n",    "voici une phrqse 0 qvec 00 des mots ");
	printf("%-0s\n",    "voici une phrqse 0 qvec 00 des mots ");
	printf("%-0.5s\n",  "    voici une phrqse 0 qvec 00 des mots ");
	printf("%-0s\n\n",  "voici une phrqse 0 qvec 00 des mots ");


	printf("%0d\n",    42);
	printf("%0 5d\n",  42);
	printf("%05d\n", 42);
	printf("%.5d\n\n", 42);

	printf(   "%.d\n",    42);
	//ft_printf("%.d\n",    42);
	printf(   "%.50d\n",   42);
	//ft_printf("%.5d\n",   42);
	printf(   "%.0d\n",   42);
	//ft_printf("% 0.5d\n",   42);


	return (0);
}
