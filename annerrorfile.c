#include "monty.h"

/**
 * ann_print_error - prints the usage error
 */
void ann_print_error(void)
{
	fprintf(stderr, "USAGE: monty file\n");
}

/**
 * ann_open_error - prints the opening error
 * @fileann: contains the file
 */
void ann_open_error(const char *fileann)
{
	fprintf(stderr, "Error: Can't open file %s\n", fileann);
}

/**
 * ann_unknown_instruction - prints the opcode error
 * @line_number: line number of the file
 * @opcode: operation code
 */
void ann_unknown_instruction(int line_number, char opcode[])
{
	fprintf(stderr, "L%d: Unknown instruction %s\n", line_number, opcode);
}

/**
 * ann_push_error - prints the push error
 * @line_number: line number of the file
 */
void ann_push_error(int line_number)
{
	fprintf(stderr, "L%d: usage: push integer\n", line_number);
}
