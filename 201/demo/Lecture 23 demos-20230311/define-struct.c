#include <stdio.h>
#include <string.h>

struct Person{
    char name[20];
    int age;
    char gender;
};

typedef struct{
    char name[20];
    int age;
    char gender;
} Employee;


void printPerson(char* varName, struct Person person);
void printEmployee(char* varName, Employee employee);
struct Person createPerson(char* name, int age, char gender);
Employee createEmployee(char* name, int age, char gender);

int main(){
    struct Person person1, person2;
    Employee employee1, employee2;

    strcpy(person1.name, "Bob");
    person1.age = 20;
    person1.gender = 'm';

    person2 = person1;

    printf("------\n");
    printPerson("person1", person1);
    printPerson("person2", person2);
    
    strcpy(employee1.name, "Alice");
    employee1.age = 23;
    employee1.gender = 'f';

    employee2 = employee1;


    printf("------\n");
    printEmployee("employee1", employee1);
    printEmployee("employee2", employee2);


    printf("------\n");
    struct Person person3 = createPerson("Mark", 40, 'm');
    printPerson("person3", person3);
    
    Employee employee3 = createEmployee("Sally", 30, 'f');
    printEmployee("employee3", employee3);
    return 0;
}

void printPerson(char* varName, struct Person person){
    
    printf("%s: name=%s, age=%d, gender=%c\n", varName, person.name, person.age, person.gender);

}


void printEmployee(char* varName, Employee employee){
    
    printf("%s: name=%s, age=%d, gender=%c\n", varName, employee.name, employee.age, employee.gender);

}

struct Person createPerson(char* name, int age, char gender){
    
    struct Person person = {.age = age, .gender = gender};
    strcpy(person.name, name);

    return person;
}

Employee createEmployee(char* name, int age, char gender){
    Employee employee = {.age = age, .gender = gender};
    strcpy(employee.name, name);

    return employee;
}
