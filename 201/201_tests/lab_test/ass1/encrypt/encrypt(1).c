#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void check_errors(char * mapping_file, char * encrypt_mode,char * input_file, int argc, char * argv[] ){
    // using strcmp function for returning differences
    // use array for judgeing, suggested by Zhuofan Sun(CCID: zhuofan3)
    int flag[3] = {0}; // a bool, for checking if flag have entered, 0 means flags not preceded
    for (int a = 1; a < 7; a+=2){ // "-t","-m", "-i" only occurs at argv[1],argv[3],argv[5] randomly 
        if (strcmp(argv[a], "-t") == 0 ){
            if (flag[0]) {
                mapping_file = argv[a + 1];
                flag[0] == 1;
            }
        }
        else if ( strcmp(argv[a], "-m") == 0 ){
            if(flag[1]){
                encrypt_mode = argv[a + 1];
                flag[1] = 0;
            }
        }
        else if ( strcmp(argv[a], "-i") == 0 ) {
            if(flag[2]){
                input_file = argv[a + 1];
                flag[2] = 0;
            }
        }
    }
    /*the input file mappingfile is not found*/
    FILE *f1;
    f1 = fopen(mapping_file, "r");
    if (f1==NULL){
        fprintf(stderr, "Error: Mapping file %s does not exist\n", mapping_file);
        exit(3);
    }

    /*the format of the input file mappingfile is incorrect*/
    int current_line = 1; //the line is reading 
    char plaintext_letter, ciphertext_letter; //two differnt letters which are reading
    
    int plaintext_repeat[26] = {0}, ciphertext_repeat[26] = {0}; //a bool, for checking repeated letter
    
    int file_read;
    while (current_line<=26 && fscanf(f1, "%c,%c\n", &plaintext_letter, &ciphertext_letter) == 2){// use fscaf to read 2 letters ineach line 
        if (plaintext_letter < 'a' || plaintext_letter > 'z' || ciphertext_letter < 'a' || ciphertext_letter > 'z'){  
            // both letter must be a lowercase letter
            fprintf(stderr, "Error: The format of mapping file %s is incorrect\n", mapping_file); // the letter must be 
            exit(4);
        }
        // checking the repearted letters 
        
        // get the position of the two letters in alphabet order
        int index_plaintext = plaintext_letter - 'a';  
        int index_ciphertext = ciphertext_letter - 'a';

        // current_lines starts from 1
        plaintext_repeat[index_plaintext-1] = index_ciphertext;  
        ciphertext_repeat[index_ciphertext-1] = index_ciphertext;

        // letters have apeared to be 0
        plaintext_repeat[index_plaintext] = 1;  
        ciphertext_repeat[index_ciphertext] = 1;

        if (plaintext_repeat[index_plaintext] == 1 || ciphertext_repeat[index_ciphertext] == 1){
            fprintf(stderr, "Error: The format of mapping file %s is incorrect\n", mapping_file);
            exit(4);
        }
        current_line ++;
    }

    // the mapping file has exactly 26 lines
    while ((file_read = fgetc(f1)) != EOF){ //the index of the line will be 27 after the loop
        if (current_line != 27){
            fprintf(stderr, "Error: The format of mapping file %s is incorrect\n", mapping_file);
            exit(4);
        }
    }
        
    /*the input file inputfile is not found*/
    FILE *f2 = fopen(input_file, "r");
    if (f2 == NULL) {
        fprintf(stderr, "Error: Mapping file %s does not exist\n", input_file);
        exit(5);
    }

    /*passes in an incorrect mode which other than 1 or 2)*/
    int mode = atoi(encrypt_mode);
    if (mode != 1 || mode != 2) {
        fprintf(stderr, "You entered %s. Sorry, your mode must be 1 for encryption or 2 for decryption\n", encrypt_mode);
        exit(6);
    }

    /*For any other incorrect invocations of the program*/
    if (argc != 7) {  // handling extra arguments
        fprintf(stderr, "Usage: ./encrypt -t <mappingfile> -m <encryption mode> -i <inputfile>");
        exit(7);
    }
    if (flag[0] == 1 || flag[1] == 1 ||flag[2] == 1){  // repeated or wrong flag
        fprintf(stderr, "Usage: ./encrypt -t %s -m %s -i %s\n",mapping_file, encrypt_mode, input_file);
        exit(7);
    }
    fclose(f1);
    fclose(f2); 
}

void encrypt(char *p_text, char *c_text, char *input_file){
    FILE * input = fopen(input_file, "r");

    int index; // index of the letter in p_text and c_text
    char p_letter; // read from the letter in plaintext
    char string[100]; // a large array to store single word
    int index_output = 0; // a pointer for output
    
    while (fscanf(input,"%c", &p_letter) != EOF){  // stop when reach the end of file
        if (p_letter == '\n') {  // turn to next line
            index_output --; 
            while (index_output >= 0){
                fprintf(stdout,"%c", string[index_output]);  // 
                index_output--;
            } 
            fprintf(stdout,"\n");  // output start a new line
            index_output = 0;  // initiate the output index for the next line
        }
        else{ // find the index in the related two tests
            for (int i = 0; i < 26; ++i) {
                if (pt_text[i] == pt_chr){
                    index = i;
                    break;
                }
            }
        }
        string[index_output] = c_text[index];  // store the plain letter
        index_output ++; 
    }
    index_output--;  // minus 1 index with no data
    while (index_output >= 0) {
        fprintf(stdout,"%c", word[index_output]);
        index_output--;
    }

    fclose(input);
}

void decrypt(char *p_text, char *c_text, char *input_file){
    FILE * input = fopen(input_file, "r");

    int index; // index of the letter in p_text and c_text
    char c_letter; // read from the letter in ciphertext
    char string[100]; // a large array to store single word
    int index_output = 0; // a pointer for output
    
    while (fscanf(input,"%c", &c_letter) != EOF){  // stop when reach the end of file
        if (c_letter == '\n') {  // turn to next line
            index_output --; 
            while (index_output >= 0){
                fprintf(stdout,"%c", string[index_output]);  // 
                index_output--;
            } 
            fprintf(stdout,"\n");  // output start a new line
            index_output = 0;  // initiate the output index for the next line
        }
        else{ // find the index in the related two tests
            for (int i = 0; i < 26; ++i) {
                if (c_text[i] == c_letter){
                    index = i;
                    break;
                }
            }
        }
        string[index_output] = p_text[index];  // store the cipher letter
        index_output ++;  
    }
    index_output--;  // minus 1 index with no data
    while (index_output >= 0) {
        fprintf(stdout,"%c", word[output_index]);
        index_output--;
    }

    fclose(input);
}

int main(char * mapping_file, char * encrypt_mode,char * input_file, int argc, char * argv[],char p_text[26],char c_text[26]){
    check_errors(mapping_file,encrypt_mode,input_file,argc,argv[] );
    
    if (strcmp(encrypt_mode, "1") == 0) encrypt_file(p_text, c_text, input_file);
    else if(strcmp(encrypt_mode, "2") == 0) decrypt_file(p_text, c_text, input_file);
    return 0;
}