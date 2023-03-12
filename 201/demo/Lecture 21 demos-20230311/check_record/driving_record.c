#include "driving_record.h"
#include "age.h"

int check_driving_record(Age age){
    int time = age - DRIVING_AGE;
    return time;
}
