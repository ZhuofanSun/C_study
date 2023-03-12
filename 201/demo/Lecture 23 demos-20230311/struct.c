#include <stdio.h>
#include <string.h>

int main(){
    struct{
        int age;
        char name[20];
        char sex;
    }person1, person2, person3;

    struct{
        int age;
        char name[20];
        char sex;
    }employee1 = {23, "Bob", 'm'}, employee2 = {.name ="Alice", .age=23, .sex= 'f'};


    //accessing uninitialized variables!
    printf("-------------\n");
    printf("Person1 is uninitialized: name:%s, age:%d, sex:%c\n", person1.name, person1.age, person1.sex);
    printf("Person2 is uninitialized: name:%s, age:%d, sex:%c\n", person2.name, person2.age, person2.sex);

    printf("-------------\n");

    printf("Employee1: name:%s, age:%d, sex:%c\n", employee1.name, employee1.age, employee1.sex);
    printf("Employee2: name:%s, age:%d, sex:%c\n", employee2.name, employee2.age, employee2.sex);
    
    
    printf("-------------\n");
    person1.age = 20;
    person1.sex = 'f';
    strcpy(person1.name, "Mary");
    

    person2.age = 30;
    person2.sex = 'm';
    strcpy(person2.name, "Jack");


    printf("Person1 is now initialized: name:%s, age:%d, sex:%c\n", person1.name, person1.age, person1.sex);
    printf("Person2 is now initialized: name:%s, age=%d, sex:%c\n", person2.name, person2.age, person2.sex);

    person3 = person1;
    
    printf("-------------\n");
    printf("Person3 is a copy of person1: name=%s, age=%d, sex=%c\n", person3.name, person3.age, person3.sex);
    return 0;
}

