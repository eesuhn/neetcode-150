#include <stdio.h>
#include <stdbool.h>

bool	contains_duplicate(int *nums, int nums_size);

int	main(void)
{
	int		nums[10] = {1, 1, 1, 3, 3, 4, 3, 2, 4, 2};
	int		nums_size = 10;
	bool	res;

	res = contains_duplicate(nums, nums_size);
	printf("%d\n", res);
	return (0);
}
