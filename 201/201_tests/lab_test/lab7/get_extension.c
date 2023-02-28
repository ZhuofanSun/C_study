#include <stdio.h>

#define MAX_SIZE 20

int get_extension(const char *file_name);

int main(int argc, char* argv[]){
	
	//simplifying things and not doing any argument validation
    printf("The index value of the extension of the input file is: %d\n", get_extension(argv[1]));
}
