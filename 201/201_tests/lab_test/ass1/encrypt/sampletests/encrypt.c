#include <stdio.h>
#include <stdlib.h>
#include <string.h>


void check_errors(char *mapping_file[], char *encrypt_mode[], char *input_file[], int argc, char * argv[] ){
    if (argc != 7) {  // handling extra arguments
        fprintf(stderr, "Usage: ./encrypt -t <mappingfile> -m <encryption mode> -i <inputfile>");
        exit(7);
    }

    // using strcmp function for returning differences
    // use array for judging, suggested by Zhuofan Sun(CCID: zhuofan3)

    int flag[3] = {0}; // a bool, for checking if flag have entered, 0 means flags not preceded
    for (int a = 1; a < 7; a+=2){ // "-t","-m", "-i" only occurs at argv[1],argv[3],argv[5] randomly
        if (strcmp(argv[a], "-t") == 0 ){
            if (!flag[0]) {
                *mapping_file = argv[a + 1];
                flag[0] = 1;
            }
        }
        else if ( strcmp(argv[a], "-m") == 0 ){
            if(!flag[1]){
                *encrypt_mode = argv[a + 1];
                flag[1] = 1;
            }
        }
        else if ( strcmp(argv[a], "-i") == 0 ) {
            if(!flag[2]){
                *input_file = argv[a + 1];
                flag[2] = 1;
            }
        }
    }

    if (!flag[0] || !flag[1] || !flag[2]){  // repeated or wrong flag
        fprintf(stderr, "Usage: ./encrypt -t <mappingfile> -m <encryption mode> -i <inputfile>");
        exit(7);
    }

    /*the input file mappingfile is not found*/
    FILE *f1;
    f1 = fopen(*mapping_file, "r");
    if (f1==NULL){
        fprintf(stderr, "Error: Mapping file %s does not exist\n", *mapping_file);
        exit(3);
    }

    /*the format of the input file mappingfile is incorrect*/
    int current_line = 1; //the line is reading
    char plaintext_letter, ciphertext_letter; //two different letters which are reading

    int plaintext_repeat[26] = {0}, ciphertext_repeat[26] = {0}; //a bool, for checking repeated letter


    // read from the mapping file
    while (fscanf(f1, "%c,%c\n", &plaintext_letter, &ciphertext_letter) == 2){// use fscanf to read 2 letters in each line
        if (plaintext_letter < 'a' || plaintext_letter > 'z' || ciphertext_letter < 'a' || ciphertext_letter > 'z'){
            // both letter must be a lowercase letter
            fprintf(stderr, "Error: The format of mapping file %s is incorrect\n", *mapping_file); // the letter must be
            exit(4);
        }
        // checking the repearted letters

        // any one is true(1) -->  have appeared once
        if (plaintext_repeat[plaintext_letter - 'a'] || ciphertext_repeat[ciphertext_letter - 'a']){
            fprintf(stderr, "Error: The format of mapping file %s is incorrect\n", *mapping_file);
            exit(4);
        }

        // set letters have appeared to be 1
        plaintext_repeat[plaintext_letter - 'a'] = 1;
        ciphertext_repeat[ciphertext_letter - 'a'] = 1;
        current_line ++;
    }

    if(current_line != 27){
        fprintf(stderr, "Error: The format of mapping file %s is incorrect\n", *mapping_file);
        exit(4);
    }


    /*the input file inputfile is not found*/
    FILE *f2 = fopen(*input_file, "r");
    if (f2 == NULL) {
        fprintf(stderr, "Error: Mapping file %s does not exist\n", *input_file);
        exit(5);
    }

    /*passes in an incorrect mode which other than 1 or 2)*/
    int mode = atoi(*encrypt_mode);
    if (mode != 1 && mode != 2) {
        fprintf(stderr, "You entered %s. Sorry, your mode must be 1 for encryption or 2 for decryption\n", *encrypt_mode);
        exit(6);
    }

    /*For any other incorrect invocations of the program*/

    fclose(f1);
    fclose(f2);
}

void reverse_output_string(char *string, int length) {
    int line_start = 0, line_end;
    for (int i = 0; i <= length; i++) {
        if (string[i] == '\n' || string[i] == '\0') {
            line_end = i - 1;
            for (int j = line_end; j >= line_start; j--) {
                fprintf(stdout,"%c", string[j]);
            }
            fprintf(stdout, "%c", '\n');
            line_start = i + 1;
        }

    }
}

void encrypt(char * mapping_file, char *input_file){
    FILE * input = fopen(input_file, "r");
    FILE * mapping = fopen(mapping_file, "r");

    char plaintext_key[26];
    char ciphertext_key[26];
    for (int index = 0; index < 26; ++index)
        fscanf(mapping, "%c,%c\n", &plaintext_key[index], &ciphertext_key[index]);

    int index; // index of the letter in p_text and c_text
    char p_letter; // read from the letter in plaintext
    char string[100]; // a large array to store single word
    int index_output = 0; // a pointer for output

    while (fscanf(input,"%c", &p_letter) != EOF){  // stop when reach the end of file
        if (p_letter == '\n') {  // turn to next line
            string[index_output++] = '\n';
        }
        else{ // find the index in the related two tests
            for (int i = 0; i < 26; ++i) {
                if (plaintext_key[i] == p_letter){
                    index = i;
                    break;
                }
            }
            string[index_output++] = ciphertext_key[index];
        }
    }

    string[index_output] = '\0';
    reverse_output_string(string, index_output+1);

    fclose(input);
}



void decrypt(char * mapping_file, char *input_file){
    FILE * input = fopen(input_file, "r");
    FILE * mapping = fopen(mapping_file, "r");

    char plaintext_key[26];
    char ciphertext_key[26];
    for (int index = 0; index < 26; ++index)
        fscanf(mapping, "%c,%c\n", &plaintext_key[index], &ciphertext_key[index]);

    int index; // index of the letter in p_text and c_text
    char p_letter; // read from the letter in plaintext
    char string[100]; // a large array to store single word
    int index_output = 0; // a pointer for output

    while (fscanf(input,"%c", &p_letter) != EOF){  // stop when reach the end of file
        if (p_letter == '\n') {  // turn to next line
            string[index_output++] = '\n';
        }
        else{ // find the index in the related two tests
            for (int i = 0; i < 26; ++i) {
                if (ciphertext_key[i] == p_letter){
                    index = i;
                    break;
                }
            }
            string[index_output++] = plaintext_key[index];
        }
    }
    string[index_output] = '\0';
    reverse_output_string(string, index_output+1);

    fclose(input);
}

int main(int argc, char * argv[]){


    char  *mapping_file, *encrypt_mode,  *input_file;

    check_errors(&mapping_file,&encrypt_mode,&input_file, argc, argv);

    //if (strcmp(encrypt_mode, "1") == 0) encrypt("mapping_encryption.csv", input_file);
    //else if(strcmp(encrypt_mode, "2") == 0) decrypt("input_encryption.txt", input_file);
    if (strcmp(encrypt_mode, "1") == 0) encrypt(mapping_file, input_file);
    else if(strcmp(encrypt_mode, "2") == 0) decrypt(mapping_file, input_file);
    return 0;

    // ./encrypt -t mapping_encryption.csv -m 1 -i input_encryption.txt
}