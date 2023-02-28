#include <stdio.h>
#include <string.h>
#define MAX_SIZE 20

int get_extension(const char *file_name);
int main(int argc, char* argv[]){

	//simplifying things and not doing any argument validation
    printf("The index value of the extension of the input file is: %d\n", get_extension(argv[1]));
}



int get_extension(const char *file_name) {
    static const char* extensions[] = {".txt", ".out", ".bkp", ".dot", ".tx"};
    int name_len = strlen(file_name), extension_len;
    char * substring;  // pointer of the expected extension

    for (int i = 0; i < 5; i++) {
        extension_len = strlen(extensions[i]);
        if (name_len < extension_len){
            continue;
        }

        substring = file_name + name_len - extension_len;
        if (strcmp(substring, extensions[i]) == 0) {  // true expected extension
            return i;
        }
    }
    return -1;
}
