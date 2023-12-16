#include "monty.h"

/**
 * main - the main entry point
 * @argc: argument count
 * @argv: argument vector
 * Return: 0 on success else exit
 */
int main(int argc, char *argv[])
{
	FILE *annfile;
	char opcode[120];
	int stackelem, line_number = 0;
	stack_t *stack = NULL;

	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
	annfile = fopen(argv[1], "r");
	if (!annfile)
	{
		fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}
	while (fscanf(annfile, "%s", opcode) != EOF)
	{
		line_number++;
		if (strcmp(opcode, "push") == 0)
		{
			if (fscanf(annfile, "%d", &stackelem) != 1)
			{
				fprintf(stderr, "L%d: usage: push integer\n", line_number);
				exit(EXIT_FAILURE);
			}
			eddiepush(&stack, line_number, stackelem);
		}
		else if (strcmp(opcode, "pall") == 0)
		{
			annpall(&stack);
		}
		else
		{
			fprintf(stderr, "L%d: Unknown instruction %s\n", line_number, opcode);
			exit(EXIT_FAILURE);
		}
	}
	fclose(annfile);
	return (0);
}
