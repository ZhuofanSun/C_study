#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void check_usage(int argc, char * argv[], char * params[]);  // check usage
char** check_puzzle(char *file_name, int *n);  // check puzzle file, get size, return the matrix
int check_word_len(const char * len_str, int max_num);  // check word length, convert into int and return
void check_wordlist(char * file_name, int word_len);  // check wordlist file, uses word length