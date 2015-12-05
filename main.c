#include <stdio.h>
#include <string.h>
#include <unistd.h>

int	main(void)
{
	if (!isatty(0))
	{
		puts("NO");
		return (1);
	}
	return (0);
}
