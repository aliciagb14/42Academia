#include "ft_printf.h"

int		main(void)
{
	printf("%d\n", ft_printf("%.0d", 0));
	printf("%d\n", printf("%.0d", 0));
	return (0);
}
