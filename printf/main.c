#include "ft_printf.h"

int		main(void)
{
	static char	a01;
	static unsigned char a02;
	static short a03;
	static unsigned short a04;
	static int a05;
	static unsigned int a06;
	static long a07;
	static unsigned long a08;
	static long long a09;
	static unsigned long long a10;
	static char *a11;
	static void *a12;

	//static char *s_hello = "hello world"; //test hexap
	static char *s_hidden = "hi low\0don't print me lol\0"; //test s
	printf("%d\n", ft_printf("%1.s", "\0"));
	printf("%d\n", printf("%1.s", "\0"));
	getchar();
	return (0);
}
