#include "monty.h"

/**
 * annpop - removes the top element from stack
 * @stack: double pointer to the stack
 * @line_number: line number of the file
 */
void annpop(stack_t **stack, unsigned int line_number)
{
	stack_t *annhead;

	if (!*stack || !stack)
	{
		fprintf(stderr, "L%d: can't pop an empty stack\n", line_number);
		exit(EXIT_FAILURE);
	}

	annhead = *stack;
	*stack = annhead->next;

	if (*stack)
		(*stack)->prev = NULL;
	free(annhead);
}
