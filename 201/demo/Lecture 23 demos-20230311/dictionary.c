/* Demonstrates creating a dictionary using structs */

#include <stdio.h>
#include <string.h>

struct dialing_code{
  char *country; //note use of pointer here instead of array. Works here because I will not be changing the values of the countries & just need to point to the string literals
  int code;
};

int main(){
  const struct dialing_code country_codes[] =
    {{"Argentina", 54}, {"Bangladesh", 880},
    {"Brazil",  55}, {"Burma (Myanmar)",  95},
    {"China", 86}, {"Colombia", 57},
    {"Congo, Dem. Rep. of", 243}, {"Egypt", 20},
    {"Ethiopia", 251}, {"France", 33},
    {"Germany", 49}, {"India", 91},
    {"Indonesia", 62}, {"Iran",  98},
    {"Italy", 39}, {"Japan", 81},
    {"Mexico",  52}, {"Nigeria", 234},
    {"Pakistan",  92}, {"Philippines", 63},
    {"Poland",  48}, {"Russia", 7},
    {"South Africa", 27}, {"South Korea", 82},
    {"Spain", 34}, {"Sudan", 249},
    {"Thailand",  66}, {"Turkey", 90},
    {"Ukraine",  380}, {"United Kingdom", 44},
    {"United States", 1}, {"Vietnam",  84}};

    int arraySize = sizeof(country_codes)/sizeof(struct dialing_code);
  
    //read country from stdin
    char country[30];
    printf("Enter country:");
    fgets(country, 30, stdin);
    country[strlen(country) - 1] = '\0';

    for(int i = 0 ; i < arraySize; i++ ){
      if(strcmp(country_codes[i].country, country) == 0){
        printf("Code for %s is %d\n", country, country_codes[i].code);
        return 0;
      }
    }

    printf("Code for %s not found\n", country);
    
    return 0;
}

