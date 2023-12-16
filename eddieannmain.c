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
		ann_print_error();
		exit(EXIT_FAILURE);
	}
	annfile = open_annfile(argv[1]);
	eddie_execute(annfile, &stack, line_number, opcode, &stackelem);

	fclose(annfile);
	return (0);
}
