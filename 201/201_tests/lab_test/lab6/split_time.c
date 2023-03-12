#include <stdio.h>
#include <stdlib.h>
void split_time(long total_sec, int *hr, int *min, int *sec){
    int max_sec = 23*60*60 + 59*60 + 59;  // max seconds per day
    if(total_sec > max_sec){
        fprintf(stderr, "Total time limit exceeded.\n");
        exit(EXIT_FAILURE);
    }

    *hr = total_sec / 3600;  // get hours
    total_sec %= 3600;  // minus hours from total seconds
    *min = total_sec / 60;  // get minutes
    *sec = total_sec % 60;  // minus minutes from remaining total seconds

}

long check_argument(char * argv){
    /* raise error if input second_total is not integer convert input string to long type and return */
    if (*argv == '\0' || argv == NULL){  // check empty input or null pointer
        fprintf(stderr, "Argument type error\n");
        exit(EXIT_FAILURE);
    }

    int index = 0;
    while (argv[index] != '\0'){
        if (argv[index] < '0' || argv[index] > '9'){  // case everything not a number
            fprintf(stderr, "Argument type error\n");
            exit(EXIT_FAILURE);
        }

        index ++;
    }
    return atol(argv);  // convert string to long

}
int main(int argc, char * argv[]){
    /*
    if (argc != 2){  // only accept 2 arguments
        fprintf(stderr, "Usage: ./split_time <The number of seconds>\n");
        return EXIT_FAILURE;
    }

    long total_sec = check_argument(argv[1]);  // check and convert str to long
     */
    int total_sec = 1000;
    int hr = -1, min = -1, sec = -1;  // initialize with -1
    split_time(total_sec, &hr, &min, &sec);  // main function

    printf("Converted time = %02d:%02d:%02d\n", hr, min, sec);

    return 0;
}