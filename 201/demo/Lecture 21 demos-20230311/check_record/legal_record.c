#include "legal_record.h"


int check_legal_record(Age age){
    if (age < LEGAL_AGE)
        return 0;
    else
        return 1;
}
