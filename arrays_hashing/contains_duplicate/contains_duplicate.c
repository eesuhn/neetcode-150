#include <stdbool.h>
#include <stdlib.h>

typedef struct s_hash_table
{
	int					key;
	struct s_hash_table	*next;
}	t_hash_table;

void	ft_set_table(t_hash_table **hash)
{
	int	i;

	i = -1;
	while (++i < 1000)
	{
		hash[i] = (t_hash_table *) malloc(sizeof(t_hash_table));
		hash[i]->next = NULL;
	}
}

void	ft_free_table(t_hash_table **hash)
{
	int				i;
	t_hash_table	*current;
	t_hash_table	*next;

	i = -1;
	while (++i < 1000)
	{
		current = hash[i];
		while (current)
		{
			next = current->next;
			free(current);
			current = next;
		}
	}
}

void	ft_helper(t_hash_table **hash, int *nums, int nums_size, bool *flag)
{
	int				i;
	int				index;
	t_hash_table	*current;
	t_hash_table	*new;

	i = -1;
	while (++i < nums_size)
	{
		index = (nums[i] % 1000 + 1000) % 1000;
		current = hash[index];
		while (current)
		{
			if (current->key == nums[i])
			{
				*flag = true;
				break ;
			}
			current = current->next;
		}
		if (!*flag)
		{
			new = (t_hash_table *) malloc(sizeof(t_hash_table));
			new->key = nums[i];
			new->next = hash[index];
			hash[index] = new;
		}
		else
			break ;
	}
}

bool	contains_duplicate(int *nums, int nums_size)
{
	bool			flag;
	bool			*ptr;
	t_hash_table	*hash[1000];

	if (nums_size == 1)
		return (false);
	flag = false;
	ptr = &flag;
	ft_set_table(hash);
	ft_helper(hash, nums, nums_size, ptr);
	ft_free_table(hash);
	return (flag);
}
