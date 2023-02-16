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