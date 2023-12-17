#ifndef MONTY_H
#define MONTY_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 *
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO
 */
typedef struct stack_s
{
        int n;
        struct stack_s *prev;
        struct stack_s *next;
} stack_t;
/**
 * struct instruction_s - opcode and its function
 * @opcode: the opcode
 * @f: function to handle the opcode
 *
 * Description: opcode and its function
 * for stack, queues, LIFO, FIFO
 */
typedef struct instruction_s
{
        char *opcode;
        void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;

void eddiepush(stack_t **stack, unsigned int line_number, const char *eddiearg);
void annpall(stack_t **stack);
FILE *open_annfile(const char *fileann);
void eddie_execute(FILE *annfile, stack_t **stack, int line_number, char opcode[], int *stackelem);
void eddie_push(stack_t **stack, int line_number, FILE *annfile, int *stackelem);
void ann_print_error(void);
void ann_open_error(const char *fileann);
void ann_unknown_instruction(int line_number, char opcode[]);
void ann_push_error(int line_number);
void eddiepint(stack_t **stack, unsigned int line_number);
void annpop(stack_t **stack, unsigned int line_number);
void eddieswap(stack_t **stack, unsigned int line_number);
void annadd(stack_t **stack, unsigned int line_number);
#endif
