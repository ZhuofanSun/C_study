#include <stdio.h>

struct Member{
    int id;
    char sex;
    double gpa;
    int officeNum;
};

int main(){

    struct Member student1 = {.id = 1, .sex = 'f', .gpa=3.2};
    struct Member faculty1 = {.id = 10, .sex = 'm', .officeNum=427};

    printf("The student has id=%d, sex=%c, gpa=%f, officeNum=%d\n", student1.id, student1.sex, student1.gpa, student1.officeNum);
    printf("The faculty member has id=%d, sex=%c, gpa=%f, officeNum=%d\n", faculty1.id, faculty1.sex, faculty1.gpa, faculty1.officeNum);

    return 0;
}
