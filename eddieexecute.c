#include "monty.h"

/**
 * open_annfile - opens a file
 * @fileann: pointer to the file
 * Return: file
 */
FILE *open_annfile(const char *fileann)
{
	FILE *annfile = fopen(fileann, "r");

	if (!annfile)
	{
		ann_open_error(fileann);
		exit(EXIT_FAILURE);
	}
	return (annfile);
}

/**
 * eddie_execute - executes the file
 * @annfile: file name
 * @stack: double pointer to the stack
 * @line_number: line number in the file
 * @opcode: operation code
 * @stackelem: element in the stack
 */
void eddie_execute(FILE *annfile, stack_t **stack,
		int line_number, char opcode[], int *stackelem)
{
	while (++line_number, fscanf(annfile, "%s", opcode) != EOF)
	{
		if (strcmp(opcode, "push") == 0)
			eddie_push(stack, line_number, annfile, stackelem);
		else if (strcmp(opcode, "pall") == 0)
			annpall(stack);
		else if (strcmp(opcode, "pint") == 0)
			eddiepint(stack, line_number);
		else if (strcmp(opcode, "pop") == 0)
			annpop(stack, line_number);
		else if (strcmp(opcode, "swap") == 0)
			eddieswap(stack, line_number);
		else if (strcmp(opcode, "add") == 0)
			annadd(stack, line_number);
		else
		{
			ann_unknown_instruction(line_number, opcode);
			fclose(annfile);
			exit(EXIT_FAILURE);
		}
	}
}

/**
 * eddie_push - handles the push error
 * @stack: double pointer to the stack
 * @line_number: line number in the file
 * @annfile: contains the file
 * @stackelem: element in the stack
 */
void eddie_push(stack_t **stack, int line_number,
		FILE *annfile, int *stackelem)
{
	char eddiearg[120];

	if (fscanf(annfile, "%s", eddiearg) != 1)
	{
		ann_push_error(line_number);
		fclose(annfile);
		exit(EXIT_FAILURE);
	}
	*stackelem = atoi(eddiearg);
	eddiepush(stack, line_number, eddiearg);
}
