#include "ft_printf.h"

int	main(void)
{

	int	a = 2855588;
	ft_printf("%d",ft_printf("Prueba %c %s %p %d %i %u %x %X %%", 's', "Hola", &a, a, -5555, -324, 255, 255));
}