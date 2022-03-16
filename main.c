/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrasser <jrasser@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/07 17:03:47 by jrasser           #+#    #+#             */
/*   Updated: 2022/03/16 01:45:18 by jrasser          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./include/ft_printf.h"
#include <stdio.h>
#include <limits.h> 

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
	char	**ptr2;

	ptr = "test";
	ptr2 = &ptr;
	char *s2 = "Mussum Ipsum, cacilds vidis litro abertis. Posuere libero varius. Nullam a nisl ut ante blandit hendrerit. Aenean sit amet nisi. Atirei o pau no gatis, per gatis num morreus.";

	printf("\n**********  STRING  ********\n");
	printf("%d\n", printf(   "real : %s apres ", "coucou"));
	printf("%d\n\n", ft_printf("mine : %s apres ", "coucou"));

	printf("%d\n", printf(   "real :%s", ""));
	printf("%d\n\n", ft_printf("mine :%s", ""));
	
	printf("%d\n", printf(   "real : %s", ""));
	printf("%d\n\n", ft_printf("mine : %s", ""));
	
	printf("%d\n", printf(   "real :  %s %s %s %s %s", " - ", "", "4", "", s2));
	printf("%d\n\n", ft_printf("mine :  %s %s %s %s %s", " - ", "", "4", "", s2));

	
	printf("\n**********  CHAR  ********\n");
	printf("%d\n", printf(   "real : %c", '0'));
	printf("%d\n\n", ft_printf("mine : %c", '0'));

	printf("%d\n", printf(   "real :  %c ", '0'));
	printf("%d\n\n", ft_printf("mine :  %c ", '0'));

	printf("%d\n", printf(   "real :  %c", '0' - 256));
	printf("%d\n\n", ft_printf("mine :  %c", '0' - 256));

	printf("%d\n", printf(   "real : %c ", '0' + 256));
	printf("%d\n\n", ft_printf("mine : %c ", '0' + 256));

	printf("%d\n", printf(   "real : %c %c %c ", '0', 0, '1'));
	printf("%d\n\n", ft_printf("mine : %c %c %c ", '0', 0, '1'));

	printf("%d\n", printf(   "real : %c %c %c ", ' ', ' ', ' '));
	printf("%d\n\n", ft_printf("mine : %c %c %c ", ' ', ' ', ' '));

	printf("%d\n", printf(   "real : %c %c %c ", '1', '2', '3'));
	printf("%d\n\n", ft_printf("mine : %c %c %c ", '1', '2', '3'));

	printf("%d\n", printf(   "real : %c %c %c ", '2', '1', 0));
	printf("%d\n\n", ft_printf("mine : %c %c %c ", '2', '1', 0));

	printf("%d\n", printf(   "real : %c %c %c ", 0, '1', '2'));
	printf("%d\n\n", ft_printf("mine : %c %c %c ", 0, '1', '2'));
	

	printf("\n**********  INT  ********\n");
	printf("%d\n", printf(   "real : %d ", 12456835));
	printf("%d\n\n", ft_printf("mine : %d ", 12456835));

	printf("%d\n", printf(   "real : %d ", -1));
	printf("%d\n\n", ft_printf("mine : %d ", -1));

	printf("%d\n", printf(   "real : %d ", 0));
	printf("%d\n\n", ft_printf("mine : %d ", 0));

	printf("%d\n", printf(   "real : %d ", 1));
	printf("%d\n\n", ft_printf("mine : %d ", 1));

	printf("%d\n", printf(   "real : %d ", 9));
	printf("%d\n\n", ft_printf("mine : %d ", 9));

	printf("%d\n", printf(   "real : %d ", 11));
	printf("%d\n\n", ft_printf("mine : %d ", 11));

	printf("%d\n", printf(   "real : %d ", INT_MAX));
	printf("%d\n\n", ft_printf("mine : %d ", INT_MAX));

	printf("%d\n", printf(   "real : %d ", INT_MIN));
	printf("%d\n\n", ft_printf("mine : %d ", INT_MIN));

	printf("%d\n", printf(   "real : %d ", LONG_MAX));
	printf("%d\n\n", ft_printf("mine : %d ", LONG_MAX));

	printf("%d\n", printf(   "real : %d ", LONG_MIN));
	printf("%d\n\n", ft_printf("mine : %d ", LONG_MIN));

	printf("%d\n", printf(   "real : %d ", UINT_MAX));
	printf("%d\n\n", ft_printf("mine : %d ", UINT_MAX));

	printf("%d\n", printf(   "real : %d ", ULONG_MAX));
	printf("%d\n\n", ft_printf("mine : %d ", ULONG_MAX));

	printf("%d\n", printf(   "real : %d ", 9223372036854775807LL));
	printf("%d\n\n", ft_printf("mine : %d ", 9223372036854775807LL));

	printf("%d\n", printf(   "real : %d %d %d %d %d %d %d", INT_MAX, INT_MIN, LONG_MAX, LONG_MIN, ULONG_MAX, 0, -42));
	printf("%d\n\n", ft_printf("mine : %d %d %d %d %d %d %d", INT_MAX, INT_MIN, LONG_MAX, LONG_MIN, ULONG_MAX, 0, -42));


	printf("\n**********  ENTIER  ********\n");
	printf("%d\n", printf(	 "real : %i ", 123));
	printf("%d\n\n", ft_printf("mine : %i ", 123));

	printf("%d\n", printf(   "real : %i ", -1));
	printf("%d\n\n", ft_printf("mine : %i ", -1));

	printf("%d\n", printf(   "real : %i ", 0));
	printf("%d\n\n", ft_printf("mine : %i ", 0));

	printf("%d\n", printf(   "real : %i ", 1));
	printf("%d\n\n", ft_printf("mine : %i ", 1));

	printf("%d\n", printf(   "real : %i ", 9));
	printf("%d\n\n", ft_printf("mine : %i ", 9));

	printf("%d\n", printf(   "real : %i ", 11));
	printf("%d\n\n", ft_printf("mine : %i ", 11));

	printf("%d\n", printf(   "real : %i ", INT_MAX));
	printf("%d\n\n", ft_printf("mine : %i ", INT_MAX));

	printf("%d\n", printf(   "real : %i ", INT_MIN));
	printf("%d\n\n", ft_printf("mine : %i ", INT_MIN));

	printf("%d\n", printf(   "real : %i ", LONG_MAX));
	printf("%d\n\n", ft_printf("mine : %i ", LONG_MAX));

	printf("%d\n", printf(   "real : %i ", LONG_MIN));
	printf("%d\n\n", ft_printf("mine : %i ", LONG_MIN));

	printf("%d\n", printf(   "real : %i ", UINT_MAX));
	printf("%d\n\n", ft_printf("mine : %i ", UINT_MAX));

	printf("%d\n", printf(   "real : %i ", ULONG_MAX));
	printf("%d\n\n", ft_printf("mine : %i ", ULONG_MAX));

	printf("%d\n", printf(   "real : %i ", 9223372036854775807LL));
	printf("%d\n\n", ft_printf("mine : %i ", 9223372036854775807LL));


	printf("\n**********  UOCTAL  ********\n");
	printf("%d\n", printf(   "real : %o ", 123));
	printf("%d\n\n", ft_printf("mine : %o ", 123));



	printf("\n**********  UDECIMAL  ********\n");
	printf("%d\n", printf(   "real : %u ", 0));
	printf("%d\n\n", ft_printf("mine : %u ", 0));

	printf("%d\n", printf(   "real : %u ", -1));
	printf("%d\n\n", ft_printf("mine : %u ", -1));

	printf("%d\n", printf(   "real : %u ", 1));
	printf("%d\n\n", ft_printf("mine : %u ", 1));
	
	printf("%d\n", printf(   "real : %u ", 9));
	printf("%d\n\n", ft_printf("mine : %u ", 9));

	printf("%d\n", printf(   "real : %u ", 10));
	printf("%d\n\n", ft_printf("mine : %u ", 10));

	printf("%d\n", printf(   "real : %u ", 11));
	printf("%d\n\n", ft_printf("mine : %u ", 11));

	printf("%d\n", printf(   "real : %u ", 15));
	printf("%d\n\n", ft_printf("mine : %u ", 15));

	printf("%d\n", printf(   "real : %u ", 16));
	printf("%d\n\n", ft_printf("mine : %u ", 16));

	printf("%d\n", printf(   "real : %u ", 17));
	printf("%d\n\n", ft_printf("mine : %u ", 17));

	printf("%d\n", printf(   "real : %u ", 100));
	printf("%d\n\n", ft_printf("mine : %u ", 100));

	printf("%d\n", printf(   "real : %u ", 101));
	printf("%d\n\n", ft_printf("mine : %u ", 101));

	printf("%d\n", printf(   "real : %u ", -9));
	printf("%d\n\n", ft_printf("mine : %u ", -9));

	printf("%d\n", printf(   "real : %u ", -10));
	printf("%d\n\n", ft_printf("mine : %u ", -10));

	printf("%d\n", printf(   "real : %u ", -11));
	printf("%d\n\n", ft_printf("mine : %u ", -11));

	printf("%d\n", printf(   "real : %u ", -15));
	printf("%d\n\n", ft_printf("mine : %u ", -15));

	printf("%d\n", printf(   "real : %u ", -16));
	printf("%d\n\n", ft_printf("mine : %u ", -16));

	printf("%d\n", printf(   "real : %u ", -17));
	printf("%d\n\n", ft_printf("mine : %u ", -17));

	printf("%d\n", printf(   "real : %u ", -100));
	printf("%d\n\n", ft_printf("mine : %u ", -100));

	printf("%d\n", printf(   "real : %u ", -101));
	printf("%d\n\n", ft_printf("mine : %u ", -101));

	printf("%d\n", printf(   "real : %u ", INT_MAX));
	printf("%d\n\n", ft_printf("mine : %u ", INT_MAX));

	printf("%d\n", printf(   "real : %u ", INT_MIN));
	printf("%d\n\n", ft_printf("mine : %u ", INT_MIN));

	printf("%d\n", printf(   "real : %u ", LONG_MAX));
	printf("%d\n\n", ft_printf("mine : %u ", LONG_MAX));

	printf("%d\n", printf(   "real : %u ", LONG_MIN));
	printf("%d\n\n", ft_printf("mine : %u ", LONG_MIN));

	printf("%d\n", printf(   "real : %u ", UINT_MAX));
	printf("%d\n\n", ft_printf("mine : %u ", UINT_MAX));

	printf("%d\n", printf(   "real : %u ", ULONG_MAX));
	printf("%d\n\n", ft_printf("mine : %u ", ULONG_MAX));

	printf("%d\n", printf(   "real : %u ", 9223372036854775807LL));
	printf("%d\n\n", ft_printf("mine : %u ", 9223372036854775807LL));

	printf("%d\n", printf(   "real : %u %u %u %u %u %u %u", INT_MAX, INT_MIN, LONG_MAX, LONG_MIN, ULONG_MAX, 0, -42));
	printf("%d\n\n", ft_printf("mine : %u %u %u %u %u %u %u", INT_MAX, INT_MIN, LONG_MAX, LONG_MIN, ULONG_MAX, 0, -42));





	printf("\n**********  x - Hexa  ********\n");
	printf("%d\n", printf(   "real : %x ", 1456890));
	printf("%d\n\n", ft_printf("mine : %x ", 1456890));

	printf("%d\n", printf(   "real : %x ", -1));
	printf("%d\n\n", ft_printf("mine : %x ", -1));

	printf("%d\n", printf(   "real : %x ", 0));
	printf("%d\n\n", ft_printf("mine : %x ", 0));

	printf("%d\n", printf(   "real : %x ", -1));
	printf("%d\n\n", ft_printf("mine : %x ", -1));

	printf("%d\n", printf(   "real : %x ", 1));
	printf("%d\n\n", ft_printf("mine : %x ", 1));
	
	printf("%d\n", printf(   "real : %x ", 9));
	printf("%d\n\n", ft_printf("mine : %x ", 9));

	printf("%d\n", printf(   "real : %x ", 10));
	printf("%d\n\n", ft_printf("mine : %x ", 10));

	printf("%d\n", printf(   "real : %x ", 11));
	printf("%d\n\n", ft_printf("mine : %x ", 11));

	printf("%d\n", printf(   "real : %x ", 15));
	printf("%d\n\n", ft_printf("mine : %x ", 15));

	printf("%d\n", printf(   "real : %x ", 16));
	printf("%d\n\n", ft_printf("mine : %x ", 16));

	printf("%d\n", printf(   "real : %x ", 17));
	printf("%d\n\n", ft_printf("mine : %x ", 17));

	printf("%d\n", printf(   "real : %x ", 100));
	printf("%d\n\n", ft_printf("mine : %x ", 100));

	printf("%d\n", printf(   "real : %x ", 101));
	printf("%d\n\n", ft_printf("mine : %x ", 101));

	printf("%d\n", printf(   "real : %x ", -9));
	printf("%d\n\n", ft_printf("mine : %x ", -9));

	printf("%d\n", printf(   "real : %x ", -10));
	printf("%d\n\n", ft_printf("mine : %x ", -10));

	printf("%d\n", printf(   "real : %x ", -11));
	printf("%d\n\n", ft_printf("mine : %x ", -11));

	printf("%d\n", printf(   "real : %x ", -15));
	printf("%d\n\n", ft_printf("mine : %x ", -15));

	printf("%d\n", printf(   "real : %x ", -16));
	printf("%d\n\n", ft_printf("mine : %x ", -16));

	printf("%d\n", printf(   "real : %x ", -17));
	printf("%d\n\n", ft_printf("mine : %x ", -17));

	printf("%d\n", printf(   "real : %x ", -100));
	printf("%d\n\n", ft_printf("mine : %x ", -100));

	printf("%d\n", printf(   "real : %x ", -101));
	printf("%d\n\n", ft_printf("mine : %x ", -101));

	printf("%d\n", printf(   "real : %x ", INT_MAX));
	printf("%d\n\n", ft_printf("mine : %x ", INT_MAX));

	printf("%d\n", printf(   "real : %x ", INT_MIN));
	printf("%d\n\n", ft_printf("mine : %x ", INT_MIN));

	printf("%d\n", printf(   "real : %x ", LONG_MAX));
	printf("%d\n\n", ft_printf("mine : %x ", LONG_MAX));

	printf("%d\n", printf(   "real : %x ", LONG_MIN));
	printf("%d\n\n", ft_printf("mine : %x ", LONG_MIN));

	printf("%d\n", printf(   "real : %x ", UINT_MAX));
	printf("%d\n\n", ft_printf("mine : %x ", UINT_MAX));

	printf("%d\n", printf(   "real : %x ", ULONG_MAX));
	printf("%d\n\n", ft_printf("mine : %x ", ULONG_MAX));

	printf("%d\n", printf(   "real : %x ", 9223372036854775807LL));
	printf("%d\n\n", ft_printf("mine : %x ", 9223372036854775807LL));

	printf("%d\n", printf(   "real : %x %x %x %x %x %x %x", INT_MAX, INT_MIN, LONG_MAX, LONG_MIN, ULONG_MAX, 0, -42));
	printf("%d\n\n", ft_printf("mine : %x %x %x %x %x %x %x", INT_MAX, INT_MIN, LONG_MAX, LONG_MIN, ULONG_MAX, 0, -42));


	printf("\n**********  X - Hexa  ********\n");
	printf("%d\n", printf(   "real : %X ", 398564540));
	printf("%d\n\n", ft_printf("mine : %X ", 398564540));

	printf("%d\n", printf(   "real : %X ", 1456890));
	printf("%d\n\n", ft_printf("mine : %X ", 1456890));

	printf("%d\n", printf(   "real : %X ", -1));
	printf("%d\n\n", ft_printf("mine : %X ", -1));

	printf("%d\n", printf(   "real : %X ", 0));
	printf("%d\n\n", ft_printf("mine : %X ", 0));

	printf("%d\n", printf(   "real : %X ", -1));
	printf("%d\n\n", ft_printf("mine : %X ", -1));

	printf("%d\n", printf(   "real : %X ", 1));
	printf("%d\n\n", ft_printf("mine : %X ", 1));
	
	printf("%d\n", printf(   "real : %X ", 9));
	printf("%d\n\n", ft_printf("mine : %X ", 9));

	printf("%d\n", printf(   "real : %X ", 10));
	printf("%d\n\n", ft_printf("mine : %X ", 10));

	printf("%d\n", printf(   "real : %X ", 11));
	printf("%d\n\n", ft_printf("mine : %X ", 11));

	printf("%d\n", printf(   "real : %X ", 15));
	printf("%d\n\n", ft_printf("mine : %X ", 15));

	printf("%d\n", printf(   "real : %X ", 16));
	printf("%d\n\n", ft_printf("mine : %X ", 16));

	printf("%d\n", printf(   "real : %X ", 17));
	printf("%d\n\n", ft_printf("mine : %X ", 17));

	printf("%d\n", printf(   "real : %X ", 100));
	printf("%d\n\n", ft_printf("mine : %X ", 100));

	printf("%d\n", printf(   "real : %X ", 101));
	printf("%d\n\n", ft_printf("mine : %X ", 101));

	printf("%d\n", printf(   "real : %X ", -9));
	printf("%d\n\n", ft_printf("mine : %X ", -9));

	printf("%d\n", printf(   "real : %X ", -10));
	printf("%d\n\n", ft_printf("mine : %X ", -10));

	printf("%d\n", printf(   "real : %X ", -11));
	printf("%d\n\n", ft_printf("mine : %X ", -11));

	printf("%d\n", printf(   "real : %X ", -15));
	printf("%d\n\n", ft_printf("mine : %X ", -15));

	printf("%d\n", printf(   "real : %X ", -16));
	printf("%d\n\n", ft_printf("mine : %X ", -16));

	printf("%d\n", printf(   "real : %X ", -17));
	printf("%d\n\n", ft_printf("mine : %X ", -17));

	printf("%d\n", printf(   "real : %X ", -100));
	printf("%d\n\n", ft_printf("mine : %X ", -100));

	printf("%d\n", printf(   "real : %X ", -101));
	printf("%d\n\n", ft_printf("mine : %X ", -101));

	printf("%d\n", printf(   "real : %X ", INT_MAX));
	printf("%d\n\n", ft_printf("mine : %X ", INT_MAX));

	printf("%d\n", printf(   "real : %X ", INT_MIN));
	printf("%d\n\n", ft_printf("mine : %X ", INT_MIN));

	printf("%d\n", printf(   "real : %X ", LONG_MAX));
	printf("%d\n\n", ft_printf("mine : %X ", LONG_MAX));

	printf("%d\n", printf(   "real : %X ", LONG_MIN));
	printf("%d\n\n", ft_printf("mine : %X ", LONG_MIN));

	printf("%d\n", printf(   "real : %X ", UINT_MAX));
	printf("%d\n\n", ft_printf("mine : %X ", UINT_MAX));

	printf("%d\n", printf(   "real : %X ", ULONG_MAX));
	printf("%d\n\n", ft_printf("mine : %X ", ULONG_MAX));

	printf("%d\n", printf(   "real : %X ", 9223372036854775807LL));
	printf("%d\n\n", ft_printf("mine : %X ", 9223372036854775807LL));

	printf("%d\n", printf(   "real : %X %X %X %X %X %X %X", INT_MAX, INT_MIN, LONG_MAX, LONG_MIN, ULONG_MAX, 0, -42));
	printf("%d\n\n", ft_printf("mine : %X %X %X %X %X %X %X", INT_MAX, INT_MIN, LONG_MAX, LONG_MIN, ULONG_MAX, 0, -42));

/*
	printf("\n**********  LD  ********\n");
	printf("%d\n", printf(   "real : %ld\n", 92233720363807));
	printf("%d\n\n", ft_printf("mine : %ld\n", 92233720363807));

	printf("\n**********  LD  ********\n");
	printf("%d\n", printf(   "real : %ld\n", -5474567507));
	printf("%d\n\n", ft_printf("mine : %ld\n", -5474567507));

	printf("\n**********  LO  ********\n");
	printf("%d\n", printf(   "real : %lo\n", 54775845607));
	printf("%d\n\n", ft_printf("mine : %lo\n", 54775845607));

	printf("\n**********  LU  ********\n");
	printf("%d\n", printf(   "real : %lu\n", -54777895807));
	printf("%d\n\n", ft_printf("mine : %lu\n", -54777895807));
*/
	printf("\n**********  LONG INT  ********\n");
	printf("%d\n", printf(   "real : %% "));
	printf("%d\n\n", ft_printf("mine : %% "));

	printf("\n**********  LONG INT  ********\n");
	printf("%d\n", printf(   "real : %p ", ptr));
	printf("%d\n\n", ft_printf("mine : %p ", ptr));

	printf("\n**********  S NULL  ********\n");
	printf("%d\n", printf(   " NULL %s NULL", (char *)0));
	printf("%d\n\n", ft_printf(" NULL %s NULL", (char *)0));



	printf("\n**********  P  ********\n");
	printf("%d\n", printf(   " %p ", ptr2));
	printf("%d\n\n", ft_printf(" %p ", ptr2));

	printf("%d\n", printf(   " %p ", 1));
	printf("%d\n\n", ft_printf(" %p ", 1));

	printf("%d\n", printf(   " %p ", 15));
	printf("%d\n\n", ft_printf(" %p ", 15));

	printf("%d\n", printf(   " %p %p ", LONG_MIN, LONG_MAX));
	printf("%d\n\n", ft_printf(" %p %p ", LONG_MIN, LONG_MAX));

	printf("%d\n", printf(   " %p %p ", INT_MIN, INT_MAX));
	printf("%d\n\n", ft_printf(" %p %p ", INT_MIN, INT_MAX));

	printf("%d\n", printf(   " %p %p ", ULONG_MAX, -ULONG_MAX));
	printf("%d\n\n", ft_printf(" %p %p ", ULONG_MAX, -ULONG_MAX));

	printf("%d\n", printf(   " %p %p ", 0, 0));
	printf("%d\n\n", ft_printf(" %p %p ", 0, 0));



	printf("\n\n*******************************  BONUS  *****************************\n");

	// - . accumulable (nb / str)
	printf("\n*****************  %%-   XXduxs  ***************\n");

/*
	printf("%d\n", printf(     "'%-2d' ",    42));
	printf("%d\n\n", ft_printf("'%-2d' ",    42));

	printf("%d\n", printf(     "'%-50d' ",    42));
	printf("%d\n\n", ft_printf("'%-50d' ",    42));

	printf("%d\n", printf(     "'%-d' ",    42));
	printf("%d\n\n", ft_printf("'%-d' ",    42));

	printf("%d\n", printf(     "'%-5d' ",    42));
	printf("%d\n\n", ft_printf("'%-5d' ",    42));

	printf("%d\n", printf(     "'%-7d' ",    42));
	printf("%d\n\n", ft_printf("'%-7d' ",    42));

	printf("%d\n", printf(     "'%-2s' ",    "402"));
	printf("%d\n\n", ft_printf("'%-2s' ",    "402"));

	printf("%d\n", printf(     "'%-5s' ",    "402"));
	printf("%d\n\n", ft_printf("'%-5s' ",    "402"));

	printf("%d\n", printf(     "'%-5s' ",    "412302"));
	printf("%d\n\n", ft_printf("'%-5s' ",    "412302"));

	printf("%d\n", printf(     "'%-5p' ",    "412302"));
	printf("%d\n\n", ft_printf("'%-5p' ",    "412302"));

	printf("%d\n", printf(     "'%-5p' ",    (void*)0));
	printf("%d\n\n", ft_printf("'%-5p' ",    (void*)0));

	printf("%d\n", printf(      "' %-1p '", 0));
	printf("%d\n\n", ft_printf( "' %-1p '", 0));
	
	printf("%d\n", printf(      "' %-2p '", -1));
	printf("%d\n\n", ft_printf( "' %-2p '", -1));
*/
	printf("%d\n", printf(      "' %-4p '", 9));
	printf("%d\n\n", ft_printf( "' %-4p '", 9));
	
	printf("%d\n", printf(      "' %-1p '", 10));
	printf("%d\n\n", ft_printf( "' %-1p '", 10));
	
	printf("%d\n", printf(      "' %-2p '", 11));
	printf("%d\n\n", ft_printf( "' %-2p '", 11));
	
	printf("%d\n", printf(      "' %-3p '", 15));
	printf("%d\n\n", ft_printf( "' %-3p '", 15));

	printf("%d\n", printf(    "' %-4p '", 16));
	printf("%d\n\n", ft_printf( "' %-4p '", 16));
	
	printf("%d\n", printf(    "' %-5p '", 17));
	printf("%d\n\n", ft_printf( "' %-5p '", 17));
	
	printf("%d\n", printf(    "' %-1p '", 99));
	printf("%d\n\n", ft_printf( "' %-1p '", 99));

	printf("%d\n", printf(    "' %-2p '", 100));
	printf("%d\n\n", ft_printf( "' %-2p '", 100));
	
	printf("%d\n", printf(    "' %-3p '", 101));
	printf("%d\n\n", ft_printf( "' %-3p '", 101));
	
	printf("%d\n", printf(    "' %-1p '", -9));
	printf("%d\n\n", ft_printf( "' %-1p '", -9));
	
	printf("%d\n", printf(    "' %-2p '", -10));
	printf("%d\n\n", ft_printf( "' %-2p '", -10));
	
	printf("%d\n", printf(    "' %-3p '", -11));
	printf("%d\n\n", ft_printf( "' %-3p '", -11));
	
	printf("%d\n", printf(    "' %-4p '", -14));
	printf("%d\n\n", ft_printf( "' %-4p '", -14));
	
	printf("%d\n", printf(    "' %-5p '", -15));
	printf("%d\n\n", ft_printf( "' %-5p '", -15));
	
	printf("%d\n", printf(    "' %-6p '", -16));
	printf("%d\n\n", ft_printf( "' %-6p '", -16));
	
	printf("%d\n", printf(    "' %-1p '", -99));
	printf("%d\n\n", ft_printf( "' %-1p '", -99));
	
	printf("%d\n", printf(    "' %-2p '", -100));
	printf("%d\n\n", ft_printf( "' %-2p '", -100));
	
	printf("%d\n", printf(    "' %-3p '", -101));
	printf("%d\n\n", ft_printf( "' %-3p '", -101));
	
	printf("%d\n", printf(      "' %-9d '", INT_MAX));
	printf("%d\n\n", ft_printf( "' %-9d '", INT_MAX));
	
	printf("%d\n", printf(     "' %-10d '", INT_MIN));
	printf("%d\n\n", ft_printf("' %-10d '", INT_MIN));
	
	printf("%d\n", printf(     "' %-11d '", LONG_MAX));
	printf("%d\n\n", ft_printf("' %-11d '", LONG_MAX));
	
	printf("%d\n", printf(     "' %-12d '", LONG_MIN));
	printf("%d\n\n", ft_printf("' %-12d '", LONG_MIN));
	
	printf("%d\n", printf(     "' %-13d '", UINT_MAX));
	printf("%d\n\n", ft_printf("' %-13d '", UINT_MAX));
	
	printf("%d\n", printf(     "' %-14d '", ULONG_MAX));
	printf("%d\n\n", ft_printf("' %-14d '", ULONG_MAX));
	
	printf("%d\n", printf(     "' %-15d '", 9223372036854775807LL));
	printf("%d\n\n", ft_printf("' %-15d '", 9223372036854775807LL));
	
	printf("%d\n", printf(    "' %-9p %-10p %-11p %-12p %-13p %-14p %-15p'", INT_MAX, INT_MIN, LONG_MAX, LONG_MIN, ULONG_MAX, 0, -42));
	printf("%d\n\n", ft_printf( "' %-9p %-10p %-11p %-12p %-13p %-14p %-15p'", INT_MAX, INT_MIN, LONG_MAX, LONG_MIN, ULONG_MAX, 0, -42));





/*
	printf("\n*****************  %%0  XXduxs  ***************\n\n");

	printf("%d\n", printf(      "'%05d' ",      123));
	printf("%d\n\n", ft_printf( "'%05d' ",      123));

	printf("%d\n", printf(       "'%0d' ",   123));
	printf("%d\n\n", ft_printf(  "'%0d' ",   123));

	printf("%d\n", printf(      "'%02d' ",   123));
	printf("%d\n\n", ft_printf( "'%02d' ",   123));

	printf("%d\n", printf(      "'%03d' ",   123));
	printf("%d\n\n", ft_printf( "'%03d' ",   123));

	printf("%d\n", printf(     "'%030d' ",   123));
	printf("%d\n\n", ft_printf("'%030d' ",   123));

	printf("%d\n", printf(     "'%030u' ",   456));
	printf("%d\n\n", ft_printf("'%030u' ",   456));


	printf("%d\n", printf(    " %01x ", 0));
	printf("%d\n\n", ft_printf( " %01x ", 0));
	
	printf("%d\n", printf(    " %02x ", -1));
	printf("%d\n\n", ft_printf( " %02x ", -1));
	
	printf("%d\n", printf(    " %04x ", 9));
	printf("%d\n\n", ft_printf( " %04x ", 9));
	
	printf("%d\n", printf(    " %01x ", 10));
	printf("%d\n\n", ft_printf( " %01x ", 10));
	
	printf("%d\n", printf(    " %02x ", 11));
	printf("%d\n\n", ft_printf( " %02x ", 11));
	
	printf("%d\n", printf(    " %03x ", 15));
	printf("%d\n\n", ft_printf( " %03x ", 15));
	
	printf("%d\n", printf(    " %04x ", 16));
	printf("%d\n\n", ft_printf( " %04x ", 16));
	
	printf("%d\n", printf(    " %05x ", 17));
	printf("%d\n\n", ft_printf( " %05x ", 17));
	
	printf("%d\n", printf(    " %01x ", 99));
	printf("%d\n\n", ft_printf( " %01x ", 99));
	
	printf("%d\n", printf(    " %02x ", 100));
	printf("%d\n\n", ft_printf( " %02x ", 100));
	
	printf("%d\n", printf(    " %03x ", 101));
	printf("%d\n\n", ft_printf( " %03x ", 101));
	
	printf("%d\n", printf(    " %01x ", -9));
	printf("%d\n\n", ft_printf( " %01x ", -9));
	
	printf("%d\n", printf(    " %02x ", -10));
	printf("%d\n\n", ft_printf( " %02x ", -10));
	
	printf("%d\n", printf(    " %03x ", -11));
	printf("%d\n\n", ft_printf( " %03x ", -11));
	
	printf("%d\n", printf(    " %04x ", -14));
	printf("%d\n\n", ft_printf( " %04x ", -14));
	
	printf("%d\n", printf(    " %05x ", -15));
	printf("%d\n\n", ft_printf( " %05x ", -15));
	
	printf("%d\n", printf(    " %06x ", -16));
	printf("%d\n\n", ft_printf( " %06x ", -16));
	
	printf("%d\n", printf(    " %01x ", -99));
	printf("%d\n\n", ft_printf( " %01x ", -99));
	
	printf("%d\n", printf(    " %02x ", -100));
	printf("%d\n\n", ft_printf( " %02x ", -100));
	
	printf("%d\n", printf(    " %03x ", -101));
	printf("%d\n\n", ft_printf( " %03x ", -101));
	
	printf("%d\n", printf(    " %09x ", INT_MAX));
	printf("%d\n\n", ft_printf( " %09x ", INT_MAX));
	
	printf("%d\n", printf(   " %010x ", INT_MIN));
	printf("%d\n\n", ft_printf(" %010x ", INT_MIN));
	
	printf("%d\n", printf(   " %011x ", LONG_MAX));
	printf("%d\n\n", ft_printf(" %011x ", LONG_MAX));
	
	printf("%d\n", printf(   " %012x ", LONG_MIN));
	printf("%d\n\n", ft_printf(" %012x ", LONG_MIN));
	
	printf("%d\n", printf(   " %013x ", UINT_MAX));
	printf("%d\n\n", ft_printf(" %013x ", UINT_MAX));
	
	printf("%d\n", printf(   " %014x ", ULONG_MAX));
	printf("%d\n\n", ft_printf(" %014x ", ULONG_MAX));
	
	printf("%d\n", printf(   " %015x ", 9223372036854775807LL));
	printf("%d\n\n", ft_printf(" %015x ", 9223372036854775807LL));
	
	printf("%d\n", printf(    " %09X %010X %011X %012X %013x %014x %015x", INT_MAX, INT_MIN, LONG_MAX, LONG_MIN, ULONG_MAX, 0, -42));
	printf("%d\n\n", ft_printf( " %09X %010X %011X %012X %013x %014x %015x", INT_MAX, INT_MIN, LONG_MAX, LONG_MIN, ULONG_MAX, 0, -42));
	
	
	
	printf("\n***************  %%.  XXduxs  ***************\n\n");

	printf("%d\n", printf(     "'%.5d' ",      123));
	printf("%d\n\n", ft_printf("'%.5d' ",      123));

	printf("%d\n", printf(     "'%.d' ",   123));
	printf("%d\n\n", ft_printf("'%.d' ",   123));

	printf("%d\n", printf(     "'%.2d' ",   123));
	printf("%d\n\n", ft_printf("'%.2d' ",   123));

	printf("%d\n", printf(     "'%.3d' ",   123));
	printf("%d\n\n", ft_printf("'%.3d' ",   123));

	printf("%d\n", printf(     "'%.30d' ",   123));
	printf("%d\n\n", ft_printf("'%.30d' ",   123));

	printf("%d\n", printf(     "'%.30s' ",   "123"));
	printf("%d\n\n", ft_printf("'%.30s' ",   "123"));
	
	printf("%d\n", printf(     "'%.3s' ",    "123"));
	printf("%d\n\n", ft_printf("'%.3s' ",    "123"));

	printf("%d\n", printf(     "'%.1s' ",    "123"));
	printf("%d\n\n", ft_printf("'%.1s' ",    "123"));

	printf("%d\n", printf(     "'%.s' ",    "123"));
	printf("%d\n\n", ft_printf("'%.s' ",    "123"));

	
	
	printf("%d\n", printf(    " %.1x ", 0));
	printf("%d\n\n", ft_printf( " %.1x ", 0));
	
	printf("%d\n", printf(    " %.2x ", -1));
	printf("%d\n\n", ft_printf( " %.2x ", -1));
	
	printf("%d\n", printf(    " %.4x ", 9));
	printf("%d\n\n", ft_printf( " %.4x ", 9));
	
	printf("%d\n", printf(    " %.1x ", 10));
	printf("%d\n\n", ft_printf( " %.1x ", 10));
	
	printf("%d\n", printf(    " %.2x ", 11));
	printf("%d\n\n", ft_printf( " %.2x ", 11));
	
	printf("%d\n", printf(    " %.3x ", 15));
	printf("%d\n\n", ft_printf( " %.3x ", 15));
	
	printf("%d\n", printf(    " %.4x ", 16));
	printf("%d\n\n", ft_printf( " %.4x ", 16));
	
	printf("%d\n", printf(    " %.5x ", 17));
	printf("%d\n\n", ft_printf( " %.5x ", 17));
	
	printf("%d\n", printf(    " %.1x ", 99));
	printf("%d\n\n", ft_printf( " %.1x ", 99));
	
	printf("%d\n", printf(    " %.2x ", 100));
	printf("%d\n\n", ft_printf( " %.2x ", 100));
	
	printf("%d\n", printf(    " %.3x ", 101));
	printf("%d\n\n", ft_printf( " %.3x ", 101));
	
	printf("%d\n", printf(    " %.1x ", -9));
	printf("%d\n\n", ft_printf( " %.1x ", -9));
	
	printf("%d\n", printf(    " %.2x ", -10));
	printf("%d\n\n", ft_printf( " %.2x ", -10));
	
	printf("%d\n", printf(    " %.3x ", -11));
	printf("%d\n\n", ft_printf( " %.3x ", -11));
	
	printf("%d\n", printf(    " %.4x ", -14));
	printf("%d\n\n", ft_printf( " %.4x ", -14));
	
	printf("%d\n", printf(    " %.5x ", -15));
	printf("%d\n\n", ft_printf( " %.5x ", -15));
	
	printf("%d\n", printf(    " %.6x ", -16));
	printf("%d\n\n", ft_printf( " %.6x ", -16));
	
	printf("%d\n", printf(    " %.1x ", -99));
	printf("%d\n\n", ft_printf( " %.1x ", -99));
	
	printf("%d\n", printf(    " %.2x ", -100));
	printf("%d\n\n", ft_printf( " %.2x ", -100));
	
	printf("%d\n", printf(    " %.3x ", -101));
	printf("%d\n\n", ft_printf( " %.3x ", -101));
	
	printf("%d\n", printf(    " %.9x ", INT_MAX));
	printf("%d\n\n", ft_printf( " %.9x ", INT_MAX));
	
	printf("%d\n", printf(   " %.10x ", INT_MIN));
	printf("%d\n\n", ft_printf(" %.10x ", INT_MIN));
	
	printf("%d\n", printf(   " %.11x ", LONG_MAX));
	printf("%d\n\n", ft_printf(" %.11x ", LONG_MAX));
	
	printf("%d\n", printf(   " %.12x ", LONG_MIN));
	printf("%d\n\n", ft_printf(" %.12x ", LONG_MIN));
	
	printf("%d\n", printf(   " %.13x ", UINT_MAX));
	printf("%d\n\n", ft_printf(" %.13x ", UINT_MAX));
	
	printf("%d\n", printf(   " %.14x ", ULONG_MAX));
	printf("%d\n\n", ft_printf(" %.14x ", ULONG_MAX));
	
	printf("%d\n", printf(   " %.15x ", 9223372036854775807LL));
	printf("%d\n\n", ft_printf(" %.15x ", 9223372036854775807LL));
	
	printf("%d\n", printf(    " %.9X %.10X %.11X %.12X %.13x %.14x %.15x", INT_MAX, INT_MIN, LONG_MAX, LONG_MIN, ULONG_MAX, 0, -42));
	printf("%d\n\n", ft_printf( " %.9X %.10X %.11X %.12X %.13x %.14x %.15x", INT_MAX, INT_MIN, LONG_MAX, LONG_MIN, ULONG_MAX, 0, -42));
	




	printf("\n***************  %%combinaison -.  ***************\n\n");


	printf("%d\n", printf(     "'%-.s' ",    "123"));
	printf("%d\n\n", ft_printf("'%-.s' ",    "123"));

	printf("%d\n", printf(     "'%-.5s' ",    "123"));
	printf("%d\n\n", ft_printf("'%-.5s' ",    "123"));

	printf("%d\n", printf(     "'%-.1s' ",    "123"));
	printf("%d\n\n", ft_printf("'%-.1s' ",    "123"));

	printf("%d\n", printf(     "'%-.5d' ",    01123));
	printf("%d\n\n", ft_printf("'%-.5d' ",    01123));

	printf("%d\n", printf(     "'%-.1d' ",    13));
	printf("%d\n\n", ft_printf("'%-.1d' ",    13));

	printf("%d\n", printf(     "'%-.05s' ",    "123"));
	printf("%d\n\n", ft_printf("'%-.05s' ",    "123"));

	printf("%d\n", printf(     "'%-.01s' ",    "123"));
	printf("%d\n\n", ft_printf("'%-.01s' ",    "123"));

	printf("%d\n", printf(     "'%-.05d' ",    123));
	printf("%d\n\n", ft_printf("'%-.05d' ",    123));

	printf("%d\n", printf(     "'%-.02d' ",    123));
	printf("%d\n\n", ft_printf("'%-.02d' ",    123));

	//printf("%d\n", printf(     "'%-.02p'\n",    ptr2));
	//printf("%d\n\n", ft_printf("'%-.02p'\n",    ptr2));

	printf("%d\n", printf(     "'%-.020u' ",    123));
	printf("%d\n\n", ft_printf("'%-.020u' ",    123));

	printf("%d\n", printf(     "'%-.02s' ",    "123"));
	printf("%d\n\n", ft_printf("'%-.02s' ",    "123"));






	printf("\n***************  BONUS 2 ' ' ***************\n\n");

	printf("%d\n", printf(     "'% d' ",    123));
	printf("%d\n\n", ft_printf("'% d' ",    123));

	printf("%d\n", printf(     "'% 2d ' ",    123));
	printf("%d\n\n", ft_printf("'% 2d ' ",    123));

	printf("%d\n", printf(     "'% 6d ' ",    123));
	printf("%d\n\n", ft_printf("'% 6d ' ",    123));

	printf("%d\n", printf(     "'%s ' ",    "1234"));
	printf("%d\n\n", ft_printf("'%s ' ",    "1234"));

	//printf("%d\n", printf(     "'%- 10d'\n",    11234)); a faire ?
	//printf("%d\n\n", ft_printf("'%- 10d'\n",    11234));



	printf("\n***************  BONUS 2 # ***************\n\n");

	//printf("%d\n", printf(          "'%#30d'\n",    123456789));
	//printf("%d\n\n", ft_printf(     "'%#30d'\n",    123456789));

	//printf("%d\n", printf(          "'%#d'\n",    123456789));
	//printf("%d\n\n", ft_printf(     "'%#d'\n",    123456789));



	printf("%d\n", printf(          "'%#o' ",    123456789));
	printf("%d\n\n", ft_printf(     "'%#o' ",    123456789));

	printf("%d\n", printf(          "'%#20o' ",    123456789));
	printf("%d\n\n", ft_printf(     "'%#20o' ",    123456789));

	printf("%d\n", printf(          "'%#x' ",    123456789));
	printf("%d\n\n", ft_printf(     "'%#x' ",    123456789));

	printf("%d\n", printf(          "'%#20x' ",    123456789));
	printf("%d\n\n", ft_printf(     "'%#20x' ",    123456789));

	printf("%d\n", printf(          "'%#2x' ",    123456789));
	printf("%d\n\n", ft_printf(     "'%#2x' ",    123456789));

	printf("%d\n", printf(          "'%#X' ",    123456789));
	printf("%d\n\n", ft_printf(     "'%#X' ",    123456789));



	printf("\n***************  BONUS 2 + ***************\n\n");

	printf("%d\n", printf(          "'%+d' ",    -123456789));
	printf("%d\n\n", ft_printf(     "'%+d' ",    -123456789));

	printf("%d\n", printf(          "'%+20d' ",  -123456789));
	printf("%d\n\n", ft_printf(     "'%+20d' ",  -123456789));

	printf("%d\n", printf(          "'%+20d' ",  123456789));
	printf("%d\n\n", ft_printf(     "'%+20d' ",  123456789));

	printf("%d\n", printf(          "'%+2d' ",    123456789));
	printf("%d\n\n", ft_printf(     "'%+2d' ",    123456789));

	printf("%d\n", printf(          "'%+20d' ",    0));
	printf("%d\n\n", ft_printf(     "'%+20d' ",    0));
	
	printf("%d\n",printf(   " %+d ", 0));
	printf("%d\n",ft_printf(" %+d ", 0));

	printf("%d\n",printf(   " %+d ", -1));
	printf("%d\n",ft_printf(" %+d ", -1));

	printf("%d\n",printf(   " %+d ", 9));
	printf("%d\n",ft_printf(" %+d ", 9));

	printf("%d\n",printf(   " %+d ", 10));
	printf("%d\n",ft_printf(" %+d ", 10));

	printf("%d\n",printf(   " %+d ", 11));
	printf("%d\n",ft_printf(" %+d ", 11));

	printf("%d\n",printf(   " %+d ", 15));
	printf("%d\n",ft_printf(" %+d ", 15));

	printf("%d\n",printf(   " %+d ", 16));
	printf("%d\n",ft_printf(" %+d ", 16));

	printf("%d\n",printf(   " %+d ", 17));
	printf("%d\n",ft_printf(" %+d ", 17));

	printf("%d\n",printf(   " %+d ", 99));
	printf("%d\n",ft_printf(" %+d ", 99));

	printf("%d\n",printf(   " %+d ", 100));
	printf("%d\n",ft_printf(" %+d ", 100));

	printf("%d\n",printf(   " %+d ", 101));
	printf("%d\n",ft_printf(" %+d ", 101));

	printf("%d\n",printf(   " %+d ", -9));
	printf("%d\n",ft_printf(" %+d ", -9));

	printf("%d\n",printf(   " %+d ", -10));
	printf("%d\n",ft_printf(" %+d ", -10));

	printf("%d\n",printf(   " %+d ", -11));
	printf("%d\n",ft_printf(" %+d ", -11));

	printf("%d\n",printf(   " %+d ", -14));
	printf("%d\n",ft_printf(" %+d ", -14));

	printf("%d\n",printf(   " %+d ", -15));
	printf("%d\n",ft_printf(" %+d ", -15));

	printf("%d\n",printf(   " %+d ", -16));
	printf("%d\n",ft_printf(" %+d ", -16));

	printf("%d\n",printf(   " %+d ", -99));
	printf("%d\n",ft_printf(" %+d ", -99));

	printf("%d\n",printf(   " %+d ", -100));
	printf("%d\n",ft_printf(" %+d ", -100));

	printf("%d\n",printf(   " %+d ", -101));
	printf("%d\n",ft_printf(" %+d ", -101));

	printf("%d\n",printf(   " %+d ", INT_MAX));
	printf("%d\n",ft_printf(" %+d ", INT_MAX));

	printf("%d\n",printf(   " %+d ", INT_MIN));
	printf("%d\n",ft_printf(" %+d ", INT_MIN));

	printf("%d\n",printf(   " %+d ", LONG_MAX));
	printf("%d\n",ft_printf(" %+d ", LONG_MAX));

	printf("%d\n",printf(   " %+d ", LONG_MIN));
	printf("%d\n",ft_printf(" %+d ", LONG_MIN));

	printf("%d\n",printf(   " %+d ", UINT_MAX));
	printf("%d\n",ft_printf(" %+d ", UINT_MAX));

	printf("%d\n",printf(   " %+d ", ULONG_MAX));
	printf("%d\n",ft_printf(" %+d ", ULONG_MAX));

	printf("%d\n",printf(   " %+d ", 9223372036854775807LL));
	printf("%d\n",ft_printf(" %+d ", 9223372036854775807LL));

	printf("%d\n",printf(   " %+d %+d %+d %+d %+d %+d %+d", INT_MAX, INT_MIN, LONG_MAX, LONG_MIN, ULONG_MAX, 0, -42));
	printf("%d\n",ft_printf(" %+d %+d %+d %+d %+d %+d %+d", INT_MAX, INT_MIN, LONG_MAX, LONG_MIN, ULONG_MAX, 0, -42));


	printf("%d\n", printf(          "'%+i' ",    -123456789));
	printf("%d\n\n", ft_printf(     "'%+i' ",    -123456789));

	printf("%d\n", printf(          "'%+20i' ",  -123456789));
	printf("%d\n\n", ft_printf(     "'%+20i' ",  -123456789));

	printf("%d\n", printf(          "'%+20i' ",  123456789));
	printf("%d\n\n", ft_printf(     "'%+20i' ",  123456789));

	printf("%d\n", printf(          "'%+2i' ",    123456789));
	printf("%d\n\n", ft_printf(     "'%+2i' ",    123456789));

	printf("%d\n", printf(          "'%+20i' ",    0));
	printf("%d\n\n", ft_printf(     "'%+20i' ",    0));
	
	printf("%d\n",printf(   " %+i ", 0));
	printf("%d\n",ft_printf(" %+i ", 0));

	printf("%d\n",printf(   " %+i ", -1));
	printf("%d\n",ft_printf(" %+i ", -1));

	printf("%d\n",printf(   " %+i ", 9));
	printf("%d\n",ft_printf(" %+i ", 9));

	printf("%d\n",printf(   " %+i ", 10));
	printf("%d\n",ft_printf(" %+i ", 10));

	printf("%d\n",printf(   " %+i ", 11));
	printf("%d\n",ft_printf(" %+i ", 11));

	printf("%d\n",printf(   " %+i ", 15));
	printf("%d\n",ft_printf(" %+i ", 15));

	printf("%d\n",printf(   " %+i ", 16));
	printf("%d\n",ft_printf(" %+i ", 16));

	printf("%d\n",printf(   " %+i ", 17));
	printf("%d\n",ft_printf(" %+i ", 17));

	printf("%d\n",printf(   " %+i ", 99));
	printf("%d\n",ft_printf(" %+i ", 99));

	printf("%d\n",printf(   " %+i ", 100));
	printf("%d\n",ft_printf(" %+i ", 100));

	printf("%d\n",printf(   " %+i ", 101));
	printf("%d\n",ft_printf(" %+i ", 101));

	printf("%d\n",printf(   " %+i ", -9));
	printf("%d\n",ft_printf(" %+i ", -9));

	printf("%d\n",printf(   " %+i ", -10));
	printf("%d\n",ft_printf(" %+i ", -10));

	printf("%d\n",printf(   " %+i ", -11));
	printf("%d\n",ft_printf(" %+i ", -11));

	printf("%d\n",printf(   " %+i ", -14));
	printf("%d\n",ft_printf(" %+i ", -14));

	printf("%d\n",printf(   " %+i ", -15));
	printf("%d\n",ft_printf(" %+i ", -15));

	printf("%d\n",printf(   " %+i ", -16));
	printf("%d\n",ft_printf(" %+i ", -16));

	printf("%d\n",printf(   " %+i ", -99));
	printf("%d\n",ft_printf(" %+i ", -99));

	printf("%d\n",printf(   " %+i ", -100));
	printf("%d\n",ft_printf(" %+i ", -100));

	printf("%d\n",printf(   " %+i ", -101));
	printf("%d\n",ft_printf(" %+i ", -101));

	printf("%d\n",printf(   " %+i ", INT_MAX));
	printf("%d\n",ft_printf(" %+i ", INT_MAX));

	printf("%d\n",printf(   " %+i ", INT_MIN));
	printf("%d\n",ft_printf(" %+i ", INT_MIN));

	printf("%d\n",printf(   " %+i ", LONG_MAX));
	printf("%d\n",ft_printf(" %+i ", LONG_MAX));

	printf("%d\n",printf(   " %+i ", LONG_MIN));
	printf("%d\n",ft_printf(" %+i ", LONG_MIN));

	printf("%d\n",printf(   " %+i ", UINT_MAX));
	printf("%d\n",ft_printf(" %+i ", UINT_MAX));

	printf("%d\n",printf(   " %+i ", ULONG_MAX));
	printf("%d\n",ft_printf(" %+i ", ULONG_MAX));

	printf("%d\n",printf(   " %+i ", 9223372036854775807LL));
	printf("%d\n",ft_printf(" %+i ", 9223372036854775807LL));

	printf("%d\n",printf(   " %+i %+i %+i %+i %+i %+i %+i", INT_MAX, INT_MIN, LONG_MAX, LONG_MIN, ULONG_MAX, 0, -42));
	printf("%d\n",ft_printf(" %+i %+i %+i %+i %+i %+i %+i", INT_MAX, INT_MIN, LONG_MAX, LONG_MIN, ULONG_MAX, 0, -42));
*/
	return (0);
}

