#include  "driving_record.h"
#include "legal_record.h"
#include <stdio.h>

int main(){

    Age age = 20;
    printf("driving record = %d\n", check_driving_record(age));
    printf("legal record = %d\n", check_legal_record(age));

    return 0;    
}
