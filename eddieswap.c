#include "monty.h"

/**
 * eddieswap - swaps the top 2 elements in a stack
 * @stack: double pointer to the stack
 * @line_number: line number of the file
 */
void eddieswap(stack_t **stack, unsigned int line_number)
{
	int e_tmp;
	stack_t *eddiecurr = *stack;

	if (!stack || !*stack || !(*stack)->next)
	{
		fprintf(stderr, "L%d: can't swap, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}
	e_tmp = eddiecurr->n;
	eddiecurr->n = eddiecurr->next->n;
	eddiecurr->next->n = e_tmp;
}
