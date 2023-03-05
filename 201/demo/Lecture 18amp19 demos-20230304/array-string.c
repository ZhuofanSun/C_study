#include <stdio.h>

int main(void){

    char* weekdays[] = {"Monday", "Tuesday", "Wednesday", "Thursday", "Friday"};

    char **p = weekdays;

    for(; p < &weekdays[5]; p++ )
        if (*p[0] == 'T')
            printf("%s starts with T\n", *p);

    return 0;
}
