/* canopen.c Checks whether a file passed as an argument can be opened for reading */

#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
    FILE *fp;
            
    if (argc != 2) {
        fprintf(stderr, "usage: canopen <filename>\n");
        exit(EXIT_FAILURE);
    }

    printf("first argument is %s\n", argv[0]);

    if ((fp = fopen(argv[1], "r")) == NULL) {
        fprintf(stderr, "%s can't be opened\n", argv[1]);
        exit(EXIT_FAILURE);
    }
                    
    printf("%s can be opened\n", argv[1]);
    fclose(fp);
                            
    return 0;
}
