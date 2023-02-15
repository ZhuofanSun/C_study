#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
typedef char ELEMENT_TYPE;
void make_empty(void);  // not used
bool is_empty(void);
bool is_full(void);
void push(ELEMENT_TYPE i);
int pop(void);
ELEMENT_TYPE get_top(void);
ELEMENT_TYPE get_top_paired(void);
void print_all(void);  // not used

