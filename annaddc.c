#include "monty.h"

/**
 * annadd - adds the top 2 elements of a stack
 * @stack: double pointer to the stack
 * @line_number: line number of the file
 */
void annadd(stack_t **stack, unsigned int line_number)
{
	stack_t *anntmp;

	if (!*stack || !stack || !(*stack)->next)
	{
		fprintf(stderr, "L%d: can't add, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}
	anntmp = *stack;
	(*stack)->next->n += (*stack)->n;
	*stack = (*stack)->next;

	if (*stack)
		(*stack)->prev = NULL;
	free(anntmp);
}

