#include <stdlib.h>
#include <stdio.h>

struct s_node
{
	int				data;
	struct s_node	*next;
};

void	ft_push(struct s_node **head, int data)
{
	struct s_node	*new_node;

	new_node = (struct s_node *) malloc(sizeof(struct s_node));
	if (new_node == NULL)
		return ;
	new_node->data = data;
	new_node->next = *head;
	*head = new_node;
}

void	ft_putnode(struct s_node *node)
{
	while (node != NULL)
	{
		printf("%i\n", node->data);
		node = node->next;
	}
}

void	ft_freelist(struct s_node *head)
{
	struct s_node	*current;
	struct s_node	*next;

	current = head;
	while (current != NULL)
	{
		next = current->next;
		free(current);
		current = next;
	}
}

int	main(void)
{
	struct s_node	*head;

	head = NULL;
	ft_push(&head, 2);
	ft_push(&head, 4);
	ft_putnode(head);
	ft_freelist(head);
	return (0);
}
