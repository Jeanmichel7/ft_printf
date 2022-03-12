/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrasser <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/21 14:33:55 by jrasser           #+#    #+#             */
/*   Updated: 2022/03/01 22:49:59 by jrasser          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

//memcmp a tester en cour
//#include "libbsd/src/strlcpy.c"
//#include "libbsd/src/strlcat.c"
//#include "libbsd/src/strnstr.c"

char f(unsigned int n, char c)
{
	if (c == ' ')
		return ('_');
	return (c - 1);
}

void fct_striteri(unsigned int i, char *s)
{
	*(s + i) = *(s + i) - 1;
}

void fct_striteri2(unsigned int i, char *s)
{
	if (s[i] >= 'a' && s[i] <= 'z')
		*(s + i) = *(s + i) - 32;
}

void print_list(t_list *list)
{
	int i = 0;
		while (list)
	{
		//printf("%s\n", list->content);
		printf("block : %d, adress %p, next : %p, content : %s\n", i, list, list-> next, list-> content);
		list = list->next;
		i++;
	}
	printf("\n");
}

// fct del content
void del_content(void *elem)
{
	char		*tmp;
	int			i;

	i = 0;
	tmp = elem;
	//printf("element avt : %p, content : %s\n",elem, (char *)elem);
	//printf("tmp     avt : %p, content : %s\n", tmp, tmp);

	while (*(tmp + i))
	{
		*(tmp + i) = 0;
		i++;
	}
}

// fct del list
void del_liste(void *elem)
{
	char	*tmp;
	int		i;

	tmp = elem;
	//printf("avant sup : %p, content : %s\n", tmp, tmp);
	i = 0;	
	while (*(tmp + i))
	{
		*(tmp + i) = 0;
		i++;
	}
	//printf("apres sup : %p, content : %s\n\n", tmp, tmp);
}

// fonction a appliquer
void fct_lstiter(void *elem)
{
	t_list		*tmp;
	tmp = elem;
	//printf("avant modif : %p, content : %s\n", tmp, tmp->content);
	if (tmp->content == NULL)
		tmp->content = "Hello world";
	else
		tmp->content = "blablablou";
	//printf("apres modif : %p, content : %s\n", tmp, tmp->content);
}

void	*fct_lstmap(void *elem)
{
	char	*str;
	t_list	*temp;

	temp = elem;
	temp->content = "Hello";
	printf("temp : %p %p %s\n", temp, temp->next, temp->content);
	return (0);
}

void fct_del_lstmap(void *elem)
{
	t_list		*tmp;
	tmp = elem;
		//printf("avant sup : %p, content : \n", tmp);
	//tmp->content = NULL;
	//printf("apres sup : %p, content : %s\n\n", tmp, tmp->content);
}




int	main(void)
{
	char 	test;
	test = '5';

	printf("isalpha : %d\n", isalpha(123));
	printf("ft_isalpha : %d\n\n", ft_isalpha(123));
	
	printf("isdigit : %d\n", isdigit(test));
	printf("ft_isdigit : %d\n\n", ft_isdigit(test));
	
	printf("isalnum : %d\n", isalnum(test));
	printf("ft_isalnum : %d\n\n", ft_isalnum(test));
	
	printf("isascii : %d\n", isascii(test));
	printf("ft_isascii : %d\n\n", ft_isascii(test));
	
	printf("isprint : %d\n", isprint(test));
	printf("ft_isprint : %d\n", ft_isprint(test));



	// *************  strlen ***************
	printf("\n\n**************** strlen *************\n");
	
	printf("%lu\n", ft_strlen("Bien le bonjour"));
	printf("%lu\n",    strlen("Bien le bonjour"));

	printf("%lu\n", ft_strlen(""));
	printf("%lu\n",    strlen(""));

	printf("%lu\n", ft_strlen("1"));
	printf("%lu\n",    strlen("1"));



	// *************  memset ***************
	printf("\n\n**************** memset *************\n");
	
	char array[] = "Bonjour";
	char array_real[] = "Bonjour";
	size_t size = sizeof(char) * 4;
	int i;

	i = 0;
	/*Display the initial values 
	printf("memset :      ");
	while (i < length)
	{
		printf( "%c", array_real[i]);
		i++;
	}*/

	ft_memset(array, 112, size);
	memset(array_real, 112, size);
	printf( "%s\n", array);
	printf( "%s\n", array_real);
	
	ft_memset(array, 150, size);
	memset(array_real, 150, size);
	printf( "%s\n", array);
	printf( "%s\n", array_real);

	ft_memset(array, 50, sizeof(char) * 7);
	memset(array_real, 50, sizeof(char) * 7);
	printf( "%s\n", array);
	printf( "%s\n", array_real);


	int array43[] = {0,1,2,3,4,5,6,7,8,9};
	int array_real43[] = {0,1,2,3,4,5,6,7,8,9};
	size = sizeof(int) * 10;
	
	ft_memset(array43, 1, size);
	memset(array_real43, 1, size);
	//Display the new values
	i = 0;
	printf("\nretour mine : ");
	while (i < 10)
	{
		printf( "%d ", array_real43[i]);
		i++;
	}
	i = 0;
	printf("\nretour real : ");
	while (i < 10)
	{
		printf( "%d ", array43[i]);
		i++;
	}   



	// *************  bzero  ***************
	printf("\n\n**************** bzero *************\n");
	
	int array2_real[] = {1, 12, 13, 33, 42};
	int array2[] = {1, 12, 13, 33, 42};
	int length2;

	size = sizeof(int) * 3;
	//Display the initial values
	printf("bzero :       ");
	i = 0;
	length2 = 5;
	while(i < length2)
	{
		printf( "%d ", array2[i] );
		i++;
	}

	//Reset the memory bloc 
	bzero(array2_real, size);
	ft_bzero(array2, size);

	//Display the new values
	i = 0;
	printf("\nretour real : ");
	while (i < length2)
	{
		printf( "%d ", array2_real[i]);
		i++;
	}
	printf("\nretour mine : ");
	i = 0;
	while (i < length2)
	{
		printf( "%d ", array2[i] );
		i++;
	}
	printf("\n\n");





	// *************  memcpy  *************** 
	printf("\n\n**************** memcpy *************\n");
	
	printf("memcpy :      ");
	int 	array3_real[] = {1, 12, 13, 33, 42};
	int		dest_real[5];
	int 	array3[] = {1, 12, 13, 33, 42};
	int		dest[5];
	int 	length3;
	int 	*p_real;
	int 	*p;

	size = sizeof(int) * 3;
	length3 = 5;

	//Display the initial values
	i = 0;
	while(i < length3)
	{
		printf( "%d ", array3[i] );
		i++;
	}
	printf( "\n=> i3");
	//Reset the memory bloc 
	p_real = memcpy(dest_real, array3_real, size);
	p = ft_memcpy(dest, array3, size);

	//Display the new values
	i = 0;
	printf("\nretour real : ");
	while (i < length3)
	{
		printf( "%d ", *(char*)(dest_real + i));
		i++;
	}
	printf("%p \nretour mine : ", &p_real);
	i = 0;
	while (i < length3)
	{
		printf( "%d ", *(char*)(dest + i));
		i++;
	}
	printf("%p \n\n", &p);




	printf( "\n=> i5");
	//Reset the memory bloc 
	p_real = memcpy(dest_real, array3_real, sizeof(int) * 5);
	p = ft_memcpy(dest, array3, sizeof(int) * 5);
	//Display the new values
	i = 0;
	printf("\nretour real : ");
	while (i < length3)
	{
		printf( "%d ", *(char*)(dest_real + i));
		i++;
	}
	printf("%p \nretour mine : ", &p_real);
	i = 0;
	while (i < length3)
	{
		printf( "%d ", *(char*)(dest + i));
		i++;
	}
	printf("%p \n\n", &p);








	/*
	//  ************   mememove   ************
	int length4;
	int data[] = { 20, 30, 40, 50, 60, 70, 80, 90, 100, 0 };

	length4 = 10;
	// On affiche le contenu de la collection
	for(int i = 0; i < length4; i++)
   	{
		printf( "%d ", data[i]);
	}
	printf("\n");

	// On décale les éléménts dans la collection ...
	const void * source = (void *) data;
	void * destination = (void *) (data + 3);

	const void * src2 = (void *) data;
	void * dest2 = (void *) (data + 1);
	
	size = 5 * sizeof(int);

	printf("data : %p, src : %p, dest : %p\n", &data, &source, &destination);

	int	*tab = memmove(destination, source, size);
	//ft_memmove(dest2, src2, size);

	// On affiche le contenu de la collection
	for(int i=0; i<length4; i++)
	{
		printf( "%d ", tab[i] );
	}
	printf("\n");
	
	for(int i=0; i<length4; i++)
	{
		printf( "%d ", *((int *)(destination + i)));
	}
	printf("\n");
	
	for(int i=0; i<length4; i++)
	{
		printf( "%d ", data[i] );
	}
	printf("\n");
	
	for(int i=0; i<length4; i++)
	{
		printf( "%d ", *((int *)(source + i)));
	}
	printf("\n");
	 */



	// *****************  memmove  ***************
	printf("\n\n**************** mememove *************\n");

	const char *src_mememove;
	char dst_mememove[12];

	src_mememove = "Hello world";
	printf("src  : %s %p\n", src_mememove, &src_mememove);

	i = -1;
	while (src_mememove[++i])
		dst_mememove[i] = src_mememove[i + 6];
	dst_mememove[5] = ' ';
	dst_mememove[6] = 't';
	dst_mememove[7] = 'h';
	dst_mememove[8] = 'e';
	dst_mememove[9] = 'r';
	dst_mememove[10] = 'e';
	dst_mememove[11] = '!';
	printf("dest : %s %p\n", dst_mememove, &dst_mememove);
	
	printf("%s\n", ft_memmove(dst_mememove, src_mememove, 0));
	printf("%s\n",    memmove(dst_mememove, src_mememove, 0));

	printf("%s\n", ft_memmove(dst_mememove, src_mememove, sizeof(char) * 6));
	printf("%s\n",    memmove(dst_mememove, src_mememove, sizeof(char) * 6));



	// **************** mememove tab int ****************
	int decalage = 6;
	printf("\n\n*************** mememove_int **********\ndecalage : %d\n", decalage);


	
	int data2[12] = {0,1,2,3,4,5,6,7,8,9,10,11};
	const int    *source2 = data2;
	int *destination2 = data2 + decalage;

	i = 0;
	//printf("src :  ");
	while (i < 12)
	{
		//printf("src  : %d %p\n", *((int *)source2+ i), (int *)source2 + i);
		//printf("%d ", *((int *)source2+ i));
		i++;
	}
	//printf("\ndest : ");
	i = 0;
	while (i < 12)
	{
		if (i >= decalage)
		{
		   *((int *)destination2 + i) = i + decalage;
		}
		//printf("dest : %d %p\n", *((int *)destination2 + i), ((int *)destination2 + i));
		//printf("%d ", *((int *)destination2 + i));
		i++;
	}
	printf("\nretour mine : ");
	void *str_res2 = ft_memmove(destination2, source2, sizeof(int) * 5);
	i = 0;
	while (i < 12)
	{
		//printf("retour mine  : %d %p\n", *((int *)str_res2 + i),  ((int *)str_res2 + i));
		printf("%d ", *((int *)str_res2 + i));
		i++;
	}



	int data[12] = {0,1,2,3,4,5,6,7,8,9,10,11};
	const int    *source = data;
	int *destination = data + decalage;

	i = 0;
	//printf("src :  ");
	while (i < 12)
	{
		//printf("src  : %d %p\n", *((int *)source+ i), (int *)source + i);
		//printf("%d ", *((int *)source+ i));
		i++;
	}
	//printf("\ndest : ");
	i = 0;
	while (i < 12)
	{
		if (i >= decalage)
		{
		   *((int *)destination + i) = i + decalage;
		}
		//printf("dest : %d %p\n", *((int *)destination + i), ((int *)destination + i));
		//printf("%d ", *((int *)destination + i));
		i++;
	}
	printf("\n");
	void *str_res;
	str_res = memmove(destination, source, sizeof(int) * 5);
	i = 0;
	printf("retour real : ");
	while (i < 12)
	{
		//printf("retour real  : %d %p\n", *((int *)str_res + i),  ((int *)str_res + i));
		printf("%d ", *((int *)str_res + i));
		i++;
	}
	printf("\n");




	// ****************  strlcpy  *****************
	printf("\n\n**************** strlcpy *************\n");
	char            dest_strlcpy[100];
	char            dest_strlcpy_real[100];

	printf("res : %zu, %s\n", ft_strlcpy(dest_strlcpy, "Message numero 1", 10), dest_strlcpy);
	printf("res : %zu, %s\n",    strlcpy(dest_strlcpy_real, "Message numero 1", 10), dest_strlcpy_real);

	printf("res : %zu, %s\n", ft_strlcpy(dest_strlcpy, "Message numero 1", 1), dest_strlcpy);
	printf("res : %zu, %s\n",    strlcpy(dest_strlcpy_real, "Message numero 1", 1), dest_strlcpy_real);

	printf("res : %zu, %s\n", ft_strlcpy(dest_strlcpy, "haaa", 30), dest_strlcpy);
	printf("res : %zu, %s\n",    strlcpy(dest_strlcpy_real, "haaa", 30), dest_strlcpy_real);

	printf("res : %zu, %s\n", ft_strlcpy(dest_strlcpy, "haaa", 2), dest_strlcpy);
	printf("res : %zu, %s\n",    strlcpy(dest_strlcpy_real, "haaa", 2), dest_strlcpy_real);



	// ****************  strlcat  *****************
	printf("\n\n**************** strlcat *************\n");
	char    dest_cat_mine[200] = "Debut du message"; //16
	char    dest_cat_real[200] = "Debut du message";

	printf("dest : %zu, %s\n", ft_strlcat(dest_cat_mine, " ,fin du message", 20), dest_cat_mine);
	printf("dest : %zu, %s\n",    strlcat(dest_cat_real, " ,fin du message", 20), dest_cat_real);
	
	dest_cat_mine[16] = '\0';
	dest_cat_real[16] = '\0';
	printf("dest : %zu, %s\n", ft_strlcat(dest_cat_mine, " ,fin du message", 35), dest_cat_mine);
	printf("dest : %zu, %s\n",    strlcat(dest_cat_real, " ,fin du message", 35), dest_cat_real);
	
	dest_cat_mine[16] = '\0';
	dest_cat_real[16] = '\0';
	printf("dest : %zu, %s\n", ft_strlcat(dest_cat_mine, "bla", 10), dest_cat_mine);
	printf("dest : %zu, %s\n",    strlcat(dest_cat_real, "bla", 10), dest_cat_real);

	dest_cat_mine[16] = '\0';
	dest_cat_real[16] = '\0';
	printf("dest : %zu, %s\n", ft_strlcat(dest_cat_mine, "ibla", 0), dest_cat_mine);
	printf("dest : %zu, %s\n",    strlcat(dest_cat_real, "ibla", 0), dest_cat_real);



	// ****************  toupper  *****************
	printf("\n\n**************** toupper *************\n");

	printf("%c\n", ft_toupper('a'));
	printf("%c\n",    toupper('a'));

	printf("%c\n", ft_toupper('z'));
	printf("%c\n",    toupper('z'));

	printf("%c\n", ft_toupper('m'));
	printf("%c\n",    toupper('m'));

	printf("%c\n", ft_toupper('n'));
	printf("%c\n",    toupper('n'));

	printf("%c\n", ft_toupper('-'));
	printf("%c\n",    toupper('-'));



	// ****************  toupper  *****************
	printf("\n\n**************** toupper *************\n");

	printf("%c\n", ft_tolower('A'));
	printf("%c\n",    tolower('A'));

	printf("%c\n", ft_tolower('Z'));
	printf("%c\n",    tolower('Z'));

	printf("%c\n", ft_tolower('N'));
	printf("%c\n",    tolower('N'));

	printf("%c\n", ft_tolower('M'));
	printf("%c\n",    tolower('M'));

	printf("%c\n", ft_tolower('-'));
	printf("%c\n",    tolower('-'));



	// ****************  strchr  *****************
	printf("\n\n**************** strchr *************\n");

	printf("%s\n", ft_strchr("Un message ici assez long", 'e'));
	printf("%s\n",    strchr("Un message ici assez long", 'e'));

	printf("%s\n", ft_strchr("Un message ici assez long", '\0'));
	printf("%s\n",    strchr("Un message ici assez long", '\0'));

	printf("%s\n", ft_strchr("Un message ici assez long", 'b'));
	printf("%s\n",    strchr("Un message ici assez long", 'b'));
  
  

	// ****************  strrchr  *****************
	printf("\n\n**************** strrchr *************\n");

	printf("%s\n", ft_strrchr("Un message ici assez long", 'e'));
	printf("%s\n",    strrchr("Un message ici assez long", 'e'));

	printf("%s\n", ft_strchr("Un message ici assez long", '\0'));
	printf("%s\n",    strchr("Un message ici assez long", '\0'));

	printf("%s\n", ft_strrchr("Un message ici assez long", 'b'));
	printf("%s\n",    strrchr("Un message ici assez long", 'b'));




	// ****************  strncmp  *****************
	printf("\n\n**************** strncmp *************\n");

	printf("res : %d\n", ft_strncmp("Bonjour", "Bonjoyr", 0));
	printf("res : %d\n",    strncmp("Bonjour", "Bonjoyr", 0));

	printf("res : %d\n", ft_strncmp("Bonjour", "Bonjoyr", 7));
	printf("res : %d\n",    strncmp("Bonjour", "Bonjoyr", 7));

	printf("res : %d\n", ft_strncmp("Bonjour", "Bonjour", 100));
	printf("res : %d\n",    strncmp("Bonjour", "Bonjour", 100));

	printf("res : %d\n", ft_strncmp("Bonjour", "", 1));
	printf("res : %d\n",    strncmp("Bonjour", "", 1));

	printf("res : %d\n", ft_strncmp("", "BonJour", 1));
	printf("res : %d\n",    strncmp("", "BonJour", 1));



	// ****************  memchr  *****************
	printf("\n\n**************** memchr *************\n");
	const char  *str_memchr;
	str_memchr = "Bonjour today";

	printf("res : %s\n", ft_memchr(str_memchr, 'j', 15));
	printf("res : %s\n",    memchr(str_memchr, 'j', 15));

	printf("res : %s\n", ft_memchr(str_memchr, ' ', 120));
	printf("res : %s\n",    memchr(str_memchr, ' ', 120));

	printf("res : %s\n", ft_memchr(str_memchr, 'j', 1));
	printf("res : %s\n",    memchr(str_memchr, 'j', 1));

	printf("res : %s\n", ft_memchr(str_memchr, 1236, 0));
	printf("res : %s\n",    memchr(str_memchr, 1236, 0));



	// ****************  memcmp  *****************
	printf("\n\n**************** memcmp *************\n");
	char *str_memcmp1;
	char *str_memcmp2;

	str_memcmp1 = "Message";
	str_memcmp2 = "MesSage";
	printf("res : %d\n", ft_memcmp(str_memcmp1, str_memcmp2, 11));
	printf("res : %d\n",    memcmp(str_memcmp1, str_memcmp2, 11));

	printf("res : %d\n", ft_memcmp(str_memcmp1, str_memcmp2, 7));
	printf("res : %d\n",    memcmp(str_memcmp1, str_memcmp2, 7));

	printf("res : %d\n", ft_memcmp(str_memcmp1, str_memcmp2, 2));
	printf("res : %d\n",    memcmp(str_memcmp1, str_memcmp2, 2));

	printf("res : %d\n", ft_memcmp(str_memcmp1, "", 0));
	printf("res : %d\n",    memcmp(str_memcmp1, "", 0));

	printf("res : %d\n", ft_memcmp("", str_memcmp2, 1));
	printf("res : %d\n",    memcmp("", str_memcmp2, 1));

	printf("res : %d\n", ft_memcmp(str_memcmp2, "", 1));
	printf("res : %d\n",    memcmp(str_memcmp2, "", 1));

	printf("res : %d\n", ft_memcmp("ijbsq", "j", 3));
	printf("res : %d\n",    memcmp("ijbsq", "j", 3));

	printf("res : %d\n", ft_memcmp("j", "i", 10));
	printf("res : %d\n",    memcmp("j", "i", 10));



	// ****************  strnstr  *****************
	printf("\n\n**************** strnstr *************\n");
	char    *str_strnstr_big;
	char    *str_strnstr_little;
	size_t    len;

	len = 14;
	str_strnstr_big = "Un gros message ici parparce que j'ai aucune inspi";
	str_strnstr_little = "parce que j'ai";

	printf("%s\n", ft_strnstr(str_strnstr_big, str_strnstr_little, 36));
	printf("%s\n",    strnstr(str_strnstr_big, str_strnstr_little, 36));

	printf("%s\n", ft_strnstr(str_strnstr_big, str_strnstr_little, 37));
	printf("%s\n",    strnstr(str_strnstr_big, str_strnstr_little, 37));

	printf("%s\n", ft_strnstr(str_strnstr_big, str_strnstr_little, 0));
	printf("%s\n",    strnstr(str_strnstr_big, str_strnstr_little, 0));

	printf("%s\n", ft_strnstr(str_strnstr_big, "", len));
	printf("%s\n",    strnstr(str_strnstr_big, "", len));

	printf("%s\n", ft_strnstr( "", "a", len));
	printf("%s\n",    strnstr( "", "a", len));

	printf("%s\n", ft_strnstr( "A", "A", 1));
	printf("%s\n",    strnstr( "A", "A", 1));

	printf("%s\n", ft_strnstr(str_strnstr_big, str_strnstr_little, 1023));
	printf("%s\n",    strnstr(str_strnstr_big, str_strnstr_little, 1023));



	// ****************  atoi  *****************
	printf("\n\n**************** atoi *************\n");

	printf("%d\n", ft_atoi("          -10230  "));
	printf("%d\n",    atoi("          -10230  "));

	printf("%d\n", ft_atoi("+456a1 2"));
	printf("%d\n",    atoi("+456a1 2"));

	printf("%d\n", ft_atoi("-001  "));
	printf("%d\n",    atoi("-001  "));

	printf("%d\n", ft_atoi("  	 -2147483648"));
	printf("%d\n",    atoi("  	 -2147483648"));

	printf("%d\n", ft_atoi("  	 -92147483648"));
	printf("%d\n",    atoi("  	 -92147483648"));

	printf("%d\n", ft_atoi("2147483647"));
	printf("%d\n",    atoi("2147483647"));

	printf("%d\n", ft_atoi("-99999999999999999999999999999999999999992147483647"));
	printf("%d\n",    atoi("-99999999999999999999999999999999999999992147483647"));

	printf("%d\n", ft_atoi("-abc123"));
	printf("%d\n",    atoi("-abc123"));

	printf("%d\n", ft_atoi("-0"));
	printf("%d\n",    atoi("-0"));

	printf("%d\n", ft_atoi("  	 12292147483648"));
	printf("%d\n",    atoi("  	 12292147483648"));

	printf("%d\n", ft_atoi("  	 922337203685477587"));
	printf("%d\n",    atoi("  	 922337203685477587"));


	// ****************  calloc  *****************
	printf("\n\n**************** calloc *************\n");

	int len_calloc = 0;
	void	*str_calloc      = ft_calloc(len_calloc, sizeof(char));
	void	*str_calloc_real =    calloc(len_calloc, sizeof(char));
	printf("%zu\n", ft_strlen(str_calloc));
	printf("%zu\n", ft_strlen(str_calloc_real));

	i = 0;
	while (i < len_calloc)
	{
		//printf("%d", *(str_calloc_real + i));
		i++;
	}
	printf("\n");
	i = 0;
	while (i < len_calloc)
	{
		//printf("%d", *(str_calloc_real + i));
		i++;
	}
	printf("\n");



	// ****************  strdup  *****************
	printf("\n\n**************** strdup *************\n");
	
	printf("%s\n", ft_strdup("Bonjour a tous"));
	printf("%s\n",    strdup("Bonjour a tous"));

	printf("%s\n", ft_strdup(""));
	printf("%s\n",    strdup(""));

	printf("%s\n", ft_strdup("a"));
	printf("%s\n",    strdup("a"));



	// ****************  substr  *****************
	printf("\n\n**************** substr *************\n");

	printf("%s\n", ft_substr("Un message !", 3, 3));
	printf("mes\n");

	printf("%s\n", ft_substr("Un message !", 3, 20));
	printf("message !\n");
	
	printf("%s\n", ft_substr("Un message !", 0, 12));
	printf("Un message !\n");

	printf("%s\n", ft_substr("Un message !", 0, 5));
	printf("Un me\n");
	
	printf("%s\n", ft_substr("Un message !", 0, 20));
	printf("Un message !\n");
	
	printf("%s\n", ft_substr("Un", 13, 2));
	printf("(null)\n");
	
	printf("%s\n", ft_substr("Un", 2, 20));
	printf("(null)\n");

	printf("%s\n", ft_substr("Un", 2, 20));
	printf("(null)\n");


	// ****************  strjoin  *****************
	printf("\n\n**************** strjoin *************\n");

	printf("%s\n", ft_strjoin("Un message !", " Et un autre"));
	printf(                   "Un message ! Et un autre\n");

	printf("%s\n", ft_strjoin("", " Et un autre"));
	printf(                   " Et un autre\n");

	printf("%s\n", ft_strjoin("", ""));
	printf(                   "\n");

	printf("%s\n", ft_strjoin("Un message !", ""));
	printf(                   "Un message !\n");



	// ****************  strtrim  *****************
	printf("\n\n**************** strtrim *************\n");

	printf("%s\n", ft_strtrim("abcUn message !abc", "abc"));
	printf(                   "Un message !\n");

	printf("%s\n", ft_strtrim("abeUn mesabcsage !aec", "abc"));
	printf(                   "eUn mesabcsage !ae\n");

	printf("%s\n", ft_strtrim("abeUn message !ac", "abc"));
	printf(                   "eUn message !\n");

	printf("%s\n", ft_strtrim("Un message 			!", "	 "));
	printf(                   "Unmessage!\n");

	printf("%s\n", ft_strtrim("                     ", " "));
	printf(                   "(vide)");



	// ****************  split  *****************
	printf("\n\n**************** split *************\n");
	char    **tab;
	
	tab = ft_split("         un grand message ici et       la et aussi là! fin        ", ' ');
	i = -1;
	while (tab[++i] != NULL)
		printf("%s ", tab[i]);
	printf("%s\n", tab[i]);
	printf("un grand message ici et la et aussi là! fin (null)\n");

	tab = ft_split("   a z e r        ", ' ');
	i = -1;
	while (tab[++i] != NULL)
		printf("%s ", tab[i]);
	printf("%s\n", tab[i]);
	printf("a z e r (null)\n");

	tab = ft_split("Hello World", ' ');
	i = -1;
	while (tab[++i] != NULL)
		printf("%s ", tab[i]);
	printf("%s\n", tab[i]);
	printf("Hello World (null)\n");

	tab = ft_split(" H ", ' ');
	i = -1;
	while (tab[++i] != NULL)
		printf("%s ", tab[i]);
	printf("%s\n", tab[i]);
	printf("H (null)\n");

	tab = ft_split("         ", ' ');
	i = -1;
	while (tab[++i] != NULL)
		printf("%s ", tab[i]);
	printf("%s\n", tab[i]);
	printf("(null)\n");



	// ****************  itoa  *****************
	printf("\n\n**************** itoa *************\n");

	printf("%s\n", ft_itoa(123));
	printf("123\n");
	printf("%s\n", ft_itoa(100));
	printf("100\n");
	printf("%s\n", ft_itoa(1000));
	printf("1000\n");
	printf("%s\n", ft_itoa(1));
	printf("1\n");
	printf("%s\n", ft_itoa(123456789));
	printf("123456789\n");
	printf("%s\n", ft_itoa(0));
	printf("0\n");
	printf("%s\n", ft_itoa(2147483647));
	printf("2147483647\n\n");
	

	printf("%s\n", ft_itoa(-123));
	printf("-123\n");
	printf("%s\n", ft_itoa(-100));
	printf("-100\n");
	printf("%s\n", ft_itoa(-1000));
	printf("-1000\n");
	printf("%s\n", ft_itoa(-2));
	printf("-2\n");
	printf("%s\n", ft_itoa(-0));
	printf("0\n");
	printf("%s\n", ft_itoa(-123456789));
	printf("-123456789\n");
	printf("%s\n", ft_itoa(-2147483648));
	printf("-2147483648\n");


	// ****************  strmapi  *****************
	printf("\n\n**************** strmapi *************\n");


	printf("%s\n", ft_strmapi("Vo nfttbhf", &f));
	printf("Un_message\n");

	printf("%s\n", ft_strmapi("", &f));
	printf("\n");

	printf("%s\n", ft_strmapi("abc def ghi", &f));
	printf("'ab_cde_fgh\n");



	// ****************  striteri  *****************
	printf("\n\n**************** striteri *************\n");

	char    str_striteri[] = "Vo!nfttbhf!psjhjobm";
	char    str_striteri2[] = "un message original!";
	char    str_striteri3[] = "";


	ft_striteri(str_striteri, &fct_striteri);
	printf("%s\n", str_striteri);
	printf("Un message original\n");

	ft_striteri(str_striteri3, &fct_striteri2);
	printf("%s\n", str_striteri3);
	printf("\n");

	ft_striteri(str_striteri2, &fct_striteri2);
	printf("%s\n", str_striteri2);
	printf("UN MESSAGE ORIGINAL!\n");





	// ****************   putchar_fd  *****************
	printf("\n\n**************** put****_fd  *************\n");
	int fd;

	fd = open("text.txt", O_WRONLY | O_CREAT | O_APPEND, S_IRUSR | S_IWUSR);
	printf("FD : %d\n", fd);
	if (fd == -1){
		printf("impossible d'ouvrir le fichier \"test\"\n");
		return (1);
	}

	ft_putchar_fd('b', fd);
	ft_putchar_fd('o', fd);
	ft_putchar_fd('n', fd);
	ft_putchar_fd('j', fd);
	ft_putchar_fd('o', fd);
	ft_putchar_fd('u', fd);
	ft_putchar_fd('r', fd);
	ft_putchar_fd('\n', fd);





	// ****************  putstr_fd  *****************

	ft_putstr_fd("Bonjour", fd);
	ft_putchar_fd(' ', fd);
	ft_putstr_fd("à", fd);
	ft_putchar_fd(' ', fd);
	ft_putstr_fd("tous", fd);
	ft_putchar_fd(' ', fd);
	ft_putchar_fd('\n', fd);


	// ****************  putendl_fd  *****************

	ft_putendl_fd("test de putend", fd);
	ft_putendl_fd("test de putend", fd);



	// ****************  putnbr_fd  *****************

	ft_putnbr_fd(123, fd);
	ft_putchar_fd('\n', fd);
	ft_putnbr_fd(123456, fd);
	ft_putchar_fd('\n', fd);
	ft_putnbr_fd(1000, fd);
	ft_putchar_fd('\n', fd);
	ft_putnbr_fd(1, fd);
	ft_putchar_fd('\n', fd);
	ft_putnbr_fd(0, fd);
	ft_putchar_fd('\n', fd);

	ft_putnbr_fd(-120, fd);
	ft_putchar_fd('\n', fd);
	ft_putnbr_fd(-2147483648, fd);
	ft_putchar_fd('\n', fd);
	ft_putnbr_fd(-10000, fd);
	ft_putchar_fd('\n', fd);
	ft_putnbr_fd(-0, fd);
	ft_putchar_fd('\n', fd);

	if (close(fd) == -1)
	{
		printf("impossible de fermer le fichier \"test\"\n");
		return (1);
	}


	printf("\n\n**************** test fct_fd ******************\n\n");
	printf("***********************************************\n");
	printf("***********************************************\n");
	printf("******                                   ******\n");
	printf("******    diff text.txt text_test.txt    ******\n");
	printf("******                                   ******\n");
	printf("***********************************************\n");
	printf("***********************************************\n");



















	// ******************************************
	// ****************  BONUS  *****************
	// ******************************************

	printf("\n\n*********************************************\n");
	printf("*******************  BONUS  *****************\n");
	printf("*********************************************\n");




	printf("\n\n**************** lstnew  *************\n");

	t_list *liste;
	liste = ft_lstnew("blablabli");
	print_list(liste);



	printf("\n\n**************** lstadd_front  *************\n");
	t_list	*tmp;
	tmp = malloc(sizeof(t_list));
	if (tmp == NULL)
		return (1);
	char	str_1[] = "new content";
	tmp->content = str_1;
	tmp->next = liste;

	ft_lstadd_front(&liste, tmp);
	print_list(liste);

	t_list	*tmp2;
	tmp2 = malloc(sizeof(t_list));
	if (tmp2 == NULL)
		return (1);
	char	str_2[] = "other new content";
	tmp2->content = str_2;
	tmp2->next = liste;

	ft_lstadd_front(&liste, tmp2);
	print_list(liste);


	printf("\n\n**************** lstsize  *************\n");
	printf("liste size : %d\n", ft_lstsize(liste));


	printf("\n\n**************** lstlast  *************\n");
	print_list(ft_lstlast(liste));


	printf("\n\n**************** lstadd_back  *************\n");
	print_list(liste);

	t_list	*tmp3;
	tmp3 = malloc(sizeof(t_list));
	if (tmp3 == NULL)
		return (1);
	char	str_3[] = "en dernier";
	tmp3->content = str_3;
	tmp3->next = NULL;

	ft_lstadd_back(&liste, tmp3);
	print_list(liste);


	t_list	*tmp4;
	tmp4 = malloc(sizeof(t_list));
	if (tmp4 == NULL)
		return (1);
	char	str_4[] = "encore plus dernier";
	tmp4->content = str_4;
	tmp4->next = NULL;

	ft_lstadd_back(&liste, tmp4);
	print_list(liste);





	printf("\n\n**************** lstdelone *************\n");

	// ajout un nouvelle élement
	t_list	*tmp5;
	tmp5 = malloc(sizeof(t_list));
	if (tmp5 == NULL)
		return (1);
	char	str_5[] = "fin de la chaine";
	tmp5->content = str_5;
	tmp5->next = NULL;
	ft_lstadd_back(&liste, tmp5);

	
	// pointeur sur 3eme élement a supprimer
	t_list *elem_3_to_del;
	t_list *temporaire;
	i = 0;
	temporaire = liste;
	while (i < 3){
		liste = liste -> next;
		i++;
	}
	elem_3_to_del = liste;
	liste = temporaire;
	printf("elem 3: %s\n", elem_3_to_del->content);

	print_list(liste);
	ft_lstdelone(elem_3_to_del, &del_content);
	print_list(liste);

	
	// pointeur sur dernier élement a supprimer
	t_list	*element_to_del;
	element_to_del = ft_lstlast(liste);
	printf("dernier elem : %s\n", element_to_del->content);

	//ft_lstdelone(element_to_del, &del_content);
	//print_list(liste);
	



/*

	// ajout un nouvelle élement
	t_list	*tmp6;
	tmp6 = malloc(sizeof(t_list));
	if (tmp6 == NULL)
		return (1);
	char	str_6[] = "ajout de text";
	tmp6->content = str_6;
	tmp6->next = NULL;
	ft_lstadd_back(&liste, tmp6);

	print_list(liste);
*/
/*

	// ajout un nouvelle élement
	t_list	*tmp7;
	tmp7 = malloc(sizeof(t_list));
	if (tmp7 == NULL)
		return (1);
	char	str_7[] = "parce que cest vide";
	tmp7->content = str_7;
	tmp7->next = NULL;
	ft_lstadd_back(&liste, tmp7);


	// ajout un nouvelle élement
	t_list	*tmp8;
	tmp8 = malloc(sizeof(t_list));
	if (tmp8 == NULL)
		return (1);
	char	str_8[] = "et mtn plus rempli !";
	tmp8->content = str_8;
	tmp8->next = NULL;
	ft_lstadd_back(&liste, tmp8);

*/	
	print_list(liste);


/*


	printf("\n\n**************** lstclear *************\n");

	print_list(liste);
	printf("elem de depart : %s\n", tmp6->content);
	ft_lstclear(&tmp6, &del_liste);
	print_list(liste);
*/	
/*
	printf("\n\n**************** lstiter *************\n");

	// pointeur sur 4eme élement
	t_list *elem_4;
	i = 0;
	temporaire = liste;
	while (i < 4){
		liste = liste -> next;
		i++;
	}
	elem_4 = liste;
	liste = temporaire;
	print_list(liste);
	printf("elem 4 de départ :%p, %s \n", elem_4, elem_4->content);

	ft_lstiter(elem_4, &fct_lstiter);
	print_list(liste);




	printf("\n\n**************** lstmap *************\n");

	
	t_list	*new_list;

	new_list = ft_lstmap(liste, &fct_lstmap, &fct_del_lstmap);

	printf("\n\nancienne liste \n");
	print_list(liste);
	printf("\n\nnouvelle liste \n");
	print_list(new_list);
*/

	return (0);
}
