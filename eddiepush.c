#include "monty.h"

/**
 * eddiepush - adds an element on to the stack
 * @line_number: number of line in the file
 * @stack: double pointer to the stack
 * @stackelem: element to be added to the stack
 */
void eddiepush(stack_t **stack, unsigned int line_number, int stackelem)
{
	stack_t *eddie_node;

	if (stack == NULL)
	{
		fprintf(stderr, "L%d: Stack Underflow\n", line_number);
		exit(EXIT_FAILURE);
	}
	eddie_node = malloc(sizeof(stack_t));
	if (eddie_node == NULL)
	{
		fprintf(stderr, "L%d: Error: malloc failed\n", line_number);
		exit(EXIT_FAILURE);
	}
	eddie_node->n = stackelem;
	eddie_node->prev = NULL;
	eddie_node->next = *stack;
	if (*stack != NULL)
		(*stack)->prev = eddie_node;
	*stack = eddie_node;
}
