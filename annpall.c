#include "monty.h"

/**
 * annpall - displays the elements of the stack
 * @stack: double pointer to the stack
 */
void annpall(stack_t **stack)
{
	stack_t *anncurr = *stack;

	while (anncurr)
	{
		printf("%d\n", anncurr->n);
		anncurr = anncurr->next;
	}
}
