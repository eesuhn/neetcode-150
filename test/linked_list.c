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

void	ft_insert_after(struct s_node *prev_node, int data)
{
	struct s_node	*new_node;

	if (prev_node == NULL)
		return ;
	new_node = (struct s_node *) malloc(sizeof(struct s_node));
	new_node->data = data;
	new_node->next = prev_node->next;
	prev_node->next = new_node;
}

void	ft_insert_after_value(struct s_node *head, int target, int data)
{
	struct s_node	*current;

	current = head;
	while (current != NULL)
	{
		if (current->data == target)
			ft_insert_after(current, data);
		current = current->next;
	}
}

void	ft_putnode(struct s_node *head)
{
	struct s_node	*current;

	current = head;
	while (current != NULL)
	{
		printf("%i\n", current->data);
		current = current->next;
	}
}

// void	ft_reverse(struct s_node *head)
// {
// 	struct s_node	*current;

// 	current = head;
// }

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
	ft_push(&head, 6);
	ft_push(&head, 8);
	ft_insert_after_value(head, 4, 88);
	ft_putnode(head);
	ft_freelist(head);
	return (0);
}
