#include <stdio.h>
#include <string.h>

struct PersonName{
    char firstName[20];
    char lastName[20];
};

struct Person{
    struct PersonName name;
    int age;
    char gender;
};

typedef int count;

void printPerson(struct Person person);
void printPeople(struct Person people[], int size);

int main(){

    struct Person person1;

    strcpy(person1.name.firstName, "John");
    strcpy(person1.name.lastName, "Smith");

    person1.age = 25;
    person1.gender = 'm';    

    printPerson(person1);

    struct Person people[3];
    struct Person person2 = {.name.firstName="Mary", .name.lastName="Noble", .age=20, .gender='f'};

    people[0] = person1;
    people[1] = person2;
    people[2] = person1;
    
    printPeople(people, 3);

    strcpy(people[0].name.firstName,"James");

    printPeople(people, 3);
    return 0;
}

void printPeople(struct Person people[], int size){
    printf("---------\n");
    for(int i = 0; i < size; i++)
        printPerson(people[i]);
}

void printPerson(struct Person person){
    
    printf("LastName, FirstName = %s,%s; age=%d; gender=%c\n", person.name.lastName, person.name.firstName, person.age, person.gender);

}
