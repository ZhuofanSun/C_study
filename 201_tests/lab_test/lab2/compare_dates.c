#include <stdio.h>
#include <stdlib.h>
int main(int argc, char *argv[]){


    FILE * input_file = fopen(argv[1], "r");
    int mm_file, dd_file, yy_file;
    fscanf(input_file, "%d/%d/%d", &mm_file, &dd_file, &yy_file);

    printf("Enter date to compare to (mm/dd/yy): ");
    int mm_input, dd_input, yy_input;
    scanf("%d/%d/%d", &mm_input, &dd_input, &yy_input);

    if(mm_input < 1 || mm_input > 12){
        fclose(input_file);
        fprintf(stderr, "Wrong date format. Program exited\n");
        exit(4);
    }

    if (yy_input < 1 || yy_input > 99){

        fclose(input_file);
        fprintf(stderr, "Wrong date format. Program exited\n");
        exit(4);

    }

    if (mm_input == 1 || mm_input == 3 ||mm_input == 5 ||mm_input == 7 ||mm_input == 8 ||
    mm_input == 10||mm_input == 12){
        if (dd_input > 31 || dd_input < 1){
            fclose(input_file);
            fprintf(stderr, "Wrong date format. Program exited\n");
            exit(4);
        }

    }
    else if (mm_input == 2){
        if (dd_input > 28 || dd_input < 1){
            fclose(input_file);
            fprintf(stderr, "Wrong date format. Program exited\n");
            exit(4);
        }

    }
    else {
        if (dd_input > 30 || dd_input < 1){

            fclose(input_file);
            fprintf(stderr, "Wrong date format. Program exited\n");
            exit(4);
        }
    }



    if (yy_file < yy_input){
        printf("%02d/%02d/%02d is earlier than %02d/%02d/%02d",mm_file,dd_file,yy_file,mm_input,dd_input,yy_input);
    }

    else if (yy_file == yy_input){

        if (mm_file < mm_input) {
            printf("%02d/%02d/%02d is earlier than %02d/%02d/%02d",mm_file,dd_file,yy_file,mm_input,dd_input,yy_input);
        }

        else if (mm_file == mm_input){

            if (dd_file < dd_input) {
                printf("%02d/%02d/%02d is earlier than %02d/%02d/%02d",mm_file,dd_file,yy_file,mm_input,dd_input,yy_input);
            }

            else if (dd_file == dd_input) printf("The same date");
            else printf("%02d/%02d/%02d is later than %02d/%02d/%02d",mm_file,dd_file,yy_file,mm_input,dd_input,yy_input);
        }
        else printf("%02d/%02d/%02d is later than %02d/%02d/%02d",mm_file,dd_file,yy_file,mm_input,dd_input,yy_input);
    }
    else printf("%02d/%02d/%02d is later than %02d/%02d/%02d",mm_file,dd_file,yy_file,mm_input,dd_input,yy_input);



}