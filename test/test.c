#include <stdio.h>
#include <stdlib.h>

void	ft(char **str)
{
	*str = "world";
}

int	main(void)
{
	char	*str;
	char	*temp;

	str = "hello";
	temp = (char *) malloc(3);
	temp[0] = 'h';
	temp[1] = 'i';
	temp[2] = '\0';
	ft(&str);
	printf("%s\n", str);
	printf("%s\n", temp);
	free(temp);
	return (0);
}
