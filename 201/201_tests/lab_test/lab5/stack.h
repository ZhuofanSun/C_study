/*
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

*/
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

void overflow(void);
void underflow(void);

void empty(void);

_Bool check_empty(void);
_Bool check_full(void);

void push(char ch);
char pop(void);

char pair(void);
void print_all(void);