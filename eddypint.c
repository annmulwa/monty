#include "monty.h"

/**
 * eddiepint - prints the element at the top of the stack
 * @stack: double pointer to the stack
 * @line_number: line number of the file
 */
void eddiepint(stack_t **stack, unsigned int line_number)
{
	if (!stack || !*stack)
	{
		fprintf(stderr, "L%d: can't pint, stack empty\n", line_number);
		exit(EXIT_FAILURE);
	}
	printf("%d\n", (*stack)->n);
}
