// -----------------------------------------------
// Student name:        Zhuofan Sun
// Student ID:          1740983
// CCID:                zhuofan3
// Lecture section:     B1
// instructor's name:   Henry Tang
// Lab section:         H01
// -----------------------------------------------

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
// find short_str from matrix, using Rabin-Karp algorithm
// return distance, from (x, y) in *direction <--after function.
int find(char** matrix, int* x, int* y, char* short_str, int * direction, int matrix_size);