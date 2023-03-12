#include <stdio.h>
#include <stdlib.h>
typedef struct{
    int hours;
    int minutes;
    int seconds;
} time;

time split_time(long total_seconds){
    time splitted_time;

    int max_sec = 23*60*60 + 59*60 + 59;  // max seconds per day
    if(total_seconds > max_sec){
        fprintf(stderr, "Total time limit exceeded.\n");
        exit(EXIT_FAILURE);
    }

    splitted_time.hours = total_seconds / 3600;  // get hours
    total_seconds %= 3600;  // minus hours from total seconds
    splitted_time.minutes = total_seconds / 60;  // get minutes
    splitted_time.seconds = total_seconds % 60;  // minus minutes from remaining total seconds

    return splitted_time;
}


int main(){

    printf("Enter time as seconds since midnight: ");
    long total_seconds = 0;
    if (scanf("%ld", &total_seconds) != 1 || total_seconds < 0){
        fprintf(stderr, "Input positive integer.\n");
        return 1;
    }

    time splitted_time = split_time(total_seconds);
    printf("hours: %d\n", splitted_time.hours);
    printf("minutes: %d\n",splitted_time.minutes);
    printf("seconds: %d\n", splitted_time.seconds);

    return 0;
}