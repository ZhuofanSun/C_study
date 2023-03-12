#include <stdio.h>

struct Member{
    int id;
    char sex;
    int type;
    union {
        int officeNum;
        double gpa;
    }info;
};

int main(){
    struct Member student1 = {.type=0, .id = 1, .sex = 'f', .info.gpa = 3.2};
    struct Member faculty1 = {.type=1, .id = 10, .sex = 'm', .info.officeNum = 427836};

    printf("Student has id=%d, sex=%c, gpa=%f, officeNum=%d\n", student1.id, student1.sex, student1.info.gpa, student1.info.officeNum);
    printf("Faculty member has id=%d, sex=%c, gpa=%f, officeNum=%d\n", faculty1.id, faculty1.sex, faculty1.info.gpa, faculty1.info.officeNum);

    return 0;
}
