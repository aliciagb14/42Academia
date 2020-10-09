#include "ft_printf.h"

int		main(void)
{
	printf("%d\n", ft_printf("%7.5s", "bombastic"));
	printf("%d\n", printf("%7.5s", "bombastic"));
	return (0);
}