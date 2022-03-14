/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrasser <jrasser@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/07 17:03:47 by jrasser           #+#    #+#             */
/*   Updated: 2022/03/14 11:02:35 by jrasser          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./include/ft_printf.h"
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
	char	**ptr2;

	ptr = "test";
	ptr2 = &ptr;
	char *s2 = "Mussum Ipsum, cacilds vidis litro abertis. Posuere libero varius. Nullam a nisl ut ante blandit hendrerit. Aenean sit amet nisi. Atirei o pau no gatis, per gatis num morreus.";

	printf("\n**********  STRING  ********\n");
	printf("%d\n", printf(   "real : %s apres ", "coucou"));
	printf("%d\n", ft_printf("mine : %s apres ", "coucou"));

	printf("%d\n", printf(   "real :%s", ""));
	printf("%d\n", ft_printf("mine :%s", ""));
	
	printf("%d\n", printf(   "real : %s", ""));
	printf("%d\n", ft_printf("mine : %s", ""));
	
	printf("%d\n", printf(   "real :  %s %s %s %s %s", " - ", "", "4", "", s2));
	printf("%d\n", ft_printf("mine :  %s %s %s %s %s", " - ", "", "4", "", s2));
	
	
	
	
	printf("\n**********  CHAR  ********\n");
	printf("%d\n", printf(   "real : %c ", 't'));
	printf("%d\n", ft_printf("mine : %c ", 't'));


	printf("%d\n", printf(   "real : %c ;'0'));
	printf("%d\n", ft_printf("mine : %c ", '0'));

	printf("%d\n", printf(   "real : %c ", '0' - 256));
	printf("%d\n", ft_printf("mine : %c ", '0' - 256));

	printf("\n**********  INT  ********\n");
	printf("%d\n", printf(   "real : %d ", 12456835));
	printf("%d\n", ft_printf("mine : %d ", 12456835));

	printf("\n**********  ENTIER  ********\n");
	printf("%d\n", printf(	 "real : %i ", 123));
	printf("%d\n", ft_printf("mine : %i ", 123));


	printf("\n**********  UOCTAL  ********\n");
	printf("%d\n", printf(   "real : %o ", 123));
	printf("%d\n", ft_printf("mine : %o ", 123));

	printf("\n**********  UDECIMAL  ********\n");
	printf("%d\n", printf(   "real : %u ", 400000000));
	printf("%d\n", ft_printf("mine : %u ", 400000000));

	printf("\n**********  UDECIMAL  ********\n");
	printf("%d\n", printf(   "real : %u ", 1234567123));
	printf("%d\n", ft_printf("mine : %u ", 1234567123));

	printf("\n**********  UHexa  ********\n");
	printf("%d\n", printf(   "real : %x ", 1456890));
	printf("%d\n", ft_printf("mine : %x ", 1456890));

	printf("\n**********  UHexa  ********\n");
	printf("%d\n", printf(   "real : %X ", 398564540));
	printf("%d\n", ft_printf("mine : %X ", 398564540));

	printf("\n**********  UHexa  ********\n");
	printf("%d\n", printf(   "real : %x ", -1));
	printf("%d\n", ft_printf("mine : %x ", -1));

/*
	printf("\n**********  LD  ********\n");
	printf("%d\n", printf(   "real : %ld\n", 92233720363807));
	printf("%d\n", ft_printf("mine : %ld\n", 92233720363807));

	printf("\n**********  LD  ********\n");
	printf("%d\n", printf(   "real : %ld\n", -5474567507));
	printf("%d\n", ft_printf("mine : %ld\n", -5474567507));

	printf("\n**********  LO  ********\n");
	printf("%d\n", printf(   "real : %lo\n", 54775845607));
	printf("%d\n", ft_printf("mine : %lo\n", 54775845607));

	printf("\n**********  LU  ********\n");
	printf("%d\n", printf(   "real : %lu\n", -54777895807));
	printf("%d\n", ft_printf("mine : %lu\n", -54777895807));
*/
	printf("\n**********  LONG INT  ********\n");
	printf("%d\n", printf(   "real : %% "));
	printf("%d\n", ft_printf("mine : %% "));

	printf("\n**********  LONG INT  ********\n");
	printf("%d\n", printf(   "real : %p ", ptr));
	printf("%d\n", ft_printf("mine : %p ", ptr));

	printf("\n**********  S NULL  ********\n");
	printf("%d\n", printf(   " NULL %s NULL", (char *)0));
	printf("%d\n", ft_printf(" NULL %s NULL", (char *)0));

	//printf("sum : %d\n", AddNumbers(5, 1, 2, 3, 4, 5));

	printf("\n**********  P  ********\n");
	printf("%d\n", printf(   " %p ", ptr2));
	printf("%d\n", ft_printf(" %p ", ptr2));

	printf("\n**********  P  ********\n");
	printf("%d\n", printf(   " %p ", NULL));
	printf("%d\n", ft_printf(" %p ", NULL));


	printf("\n\n*******************************  BONUS  *****************************\n");

	// - . accumulable (nb / str)
	printf("\n*****************  %%-   XXduxs  ***************\n");

	printf("%d\n", printf(     "'%-50d' ",    42));
	printf("%d\n\n", ft_printf("'%-50d' ",    42));

	//printf("%d\n", printf(     "'%-0d'",    42));
	//printf("%d\n\n", ft_printf("'%-0d'",    42));

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



	printf("\n*****************  %%0  XXduxs  ***************\n\n");

	printf("%d\n", printf(     "'%05d' ",      123));
	printf("%d\n\n", ft_printf("'%05d' ",      123));

	printf("%d\n", printf(     "'%0d' ",   123));
	printf("%d\n\n", ft_printf("'%0d' ",   123));

	printf("%d\n", printf(     "'%02d' ",   123));
	printf("%d\n\n", ft_printf("'%02d' ",   123));

	printf("%d\n", printf(     "'%03d' ",   123));
	printf("%d\n\n", ft_printf("'%03d' ",   123));

	printf("%d\n", printf(     "'%030d' ",   123));
	printf("%d\n\n", ft_printf("'%030d' ",   123));

	printf("%d\n", printf(     "'%030u' ",   456));
	printf("%d\n\n", ft_printf("'%030u' ",   456));

/*
	printf("%d\n", printf(     "'%030p'\n",   123));
	printf("%d\n\n", ft_printf("'%030p'\n",   123));

	printf("%d\n", printf(   "%0p'\n", 0));
	printf("%d\n\n", ft_printf("%0p'\n", 0));

	printf("%d\n", printf(   "real : %0p\n", ptr));
	printf("%d\n\n", ft_printf("mine : %0p\n", ptr));

	printf("%d\n", printf(     "'%03s'\n",   "123"));
	printf("%d\n\n", ft_printf("'%03s'\n",   "123"));

	printf("%d\n", printf(     "'%030s'\n",   "123"));
	printf("%d\n\n", ft_printf("'%030s'\n",   "123"));

	printf("%d\n", printf(     "'%030c'\n",   'e'));
	printf("%d\n\n", ft_printf("'%030c'\n",   'e'));

	printf("%d\n", printf(     "'%01s'\n",   "123"));
	printf("%d\n\n", ft_printf("'%01s'\n",   "123"));

	printf("%d\n", printf(     "'%01p'\n",   "123"));
	printf("%d\n\n", ft_printf("'%01p'\n",   "123"));
*/

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

	//printf("%d\n", printf(     "'%.p'\n",    "123"));
	//printf("%d\n\n", ft_printf("'%.p'\n",    "123"));




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

	printf("%d\n", printf(          "'%+d' ",    123456789));
	printf("%d\n\n", ft_printf(     "'%+d' ",    123456789));

	printf("%d\n", printf(          "'%+20d' ",  -123456789));
	printf("%d\n\n", ft_printf(     "'%+20d' ",  -123456789));

	printf("%d\n", printf(          "'%+20d' ",  123456789));
	printf("%d\n\n", ft_printf(     "'%+20d' ",  123456789));

	printf("%d\n", printf(          "'%+2d' ",    123456789));
	printf("%d\n\n", ft_printf(     "'%+2d' ",    123456789));

	printf("%d\n", printf(          "'%+20d' ",    0));
	printf("%d\n\n", ft_printf(     "'%+20d' ",    0));



	return (0);
}

