#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

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

struct s_node	*ft_reverse(struct s_node *head)
{
	struct s_node	*prev;
	struct s_node	*current;
	struct s_node	*next;

	prev = NULL;
	current = head;
	next = NULL;
	while (current != NULL)
	{
		next = current->next;
		current->next = prev;
		prev = current;
		current = next;
	}
	head = prev;
	return (head);
}

void	ft_append(struct s_node **head, int data)
{
	struct s_node	*new;
	struct s_node	*cur;

	new = (struct s_node *) malloc(sizeof(struct s_node));
	new->data = data;
	new->next = NULL;
	cur = *head;
	if (cur == NULL)
	{
		*head = new;
		return ;
	}
	while (cur->next != NULL)
		cur = cur->next;
	cur->next = new;
}

void	ft_rev(struct s_node **head)
{
	struct s_node	*prev;
	struct s_node	*cur;
	struct s_node	*next;

	cur = *head;
	prev = NULL;
	next = NULL;
	while (cur != NULL)
	{
		next = cur->next;
		cur->next = prev;
		prev = cur;
		cur = next;
	}
	*head = prev;
}

bool	ft_search(struct s_node *head, int data)
{
	struct s_node	*cur;

	cur = head;
	while (cur->next != NULL)
	{
		if (cur->data == data)
			return (1);
		cur = cur->next;
	}
	return (0);
}

bool	ft_search_rec(struct s_node *head, int data)
{
	if (head == NULL)
		return (0);
	if (head->data == data)
		return (1);
	return (ft_search_rec(head->next, data));
}

int	ft_listlen(struct s_node *head)
{
	struct s_node	*cur;
	int				count;

	cur = head;
	if (cur == NULL)
		return (0);
	count = 1;
	while (cur->next != NULL)
	{
		count++;
		cur = cur->next;
	}
	return (count);
}

void	ft_del_fval(struct s_node **head, int data)
{
	struct s_node	*cur;
	struct s_node	*prev;

	cur = *head;
	prev = NULL;
	while (cur != NULL && cur->data != data)
	{
		prev = cur;
		cur = cur->next;
	}
	if (cur != NULL)
	{
		if (prev == NULL)
			*head = cur->next;
		else
			prev->next = cur->next;
		free(cur);
	}
}

void	ft_del_aval(struct s_node **head, int data)
{
	struct s_node	*cur;
	struct s_node	*prev;
	struct s_node	*next;

	cur = *head;
	prev = NULL;
	next = NULL;
	while (cur != NULL)
	{
		next = cur->next;
		if (cur->data == data)
		{
			if (prev == NULL)
				*head = next;
			else
				prev->next = next;
			free(cur);
		}
		else
			prev = cur;
		cur = next;
	}
}

int	main(void)
{
	struct s_node	*head;

	head = NULL;
	ft_push(&head, 2);
	ft_push(&head, 4);
	ft_push(&head, 6);
	ft_push(&head, 4);
	ft_putnode(head);
	ft_del_aval(&head, 4);
	printf("\n");
	ft_putnode(head);
	ft_freelist(head);
	return (0);
}
