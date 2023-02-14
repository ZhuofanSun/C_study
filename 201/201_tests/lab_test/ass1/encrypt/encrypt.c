/*
// -----------------------------------------------
// Student name:        Zhuofan Sun
// Student ID:          1740983
// CCID:                zhuofan3
// Lecture section:     B1
// instructor's name:   Henry Tang
// Lab section:         H01
// -----------------------------------------------

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
void check_error(int argc, char * argv[], char * mf_em_if[], char *pt_text, char *ct_text);  // include all check
void check_usage(int argc, char * argv[], char * mf_em_if[]);
void check_mapf_exist(char * mapping_file);
void check_mode(char * encryption_mode);
void check_inputf_exist(char * input_file);
void check_mapf_format(char * mapping_file, char pt_text[], char ct_text[]);

void run(char * mf_em_if[], char pt_text[], char ct_text[]);  // include encrypt and decrypt
void encrypt_file(const char *pt_text, const char *ct_text, char *input_file);
void decrypt_file(const char pt_text[], const char ct_text[], char input_file[]);

void check_mapf_exist(char * mapping_file){
    FILE *map_f = fopen(mapping_file, "r");  // try to open the mapping file
    if (map_f == NULL) {  // fail to find the file
        fprintf(stderr, "Error: Mapping file %s does not exist\n", mapping_file);
        exit(3);
    }
    fclose(map_f);  // close the file only if success to open

}

void check_mapf_format(char * mapping_file, char pt_text[], char ct_text[]){

    FILE *map_f = fopen(mapping_file, "r");  // open file with read only

    int curr_lines = 1;  // which line currently watch, maximum 26 lines
    char curr_pt, curr_ct;  // the plaintext and ciphertext in current line
    _Bool flag_pt[26], flag_ct[26];  // used to check repeated letter, from a to z
    for (int i = 0; i < 26; ++i) {  //  initially all true

        flag_pt[i] = 1;
        flag_ct[i] = 1;

    }

    // fscanf returns 2 if successfully get the two char
    // loop end if can't get the two chars or currently at the 26 lines
    while(curr_lines <= 26 && fscanf(map_f, "%c,%c\n", &curr_pt, &curr_ct) == 2){

        if (curr_pt < 'a' || curr_pt > 'z' || curr_ct < 'a' || curr_ct > 'z'){  // both chars must be a lowercase letter

            fprintf(stderr, "Error: The format of mapping file %s is incorrect\n", mapping_file);
            exit(4);

        }

        int index_curr_pt = curr_pt - 'a';  // get the position of the two letters in alphabet order, start from 0
        int index_curr_ct = curr_ct - 'a';
        if (!flag_ct[index_curr_ct] || !flag_pt[index_curr_pt]){  // should be !1 if not used

            fprintf(stderr, "Error: The format of mapping file %s is incorrect\n", mapping_file);
            exit(4);

        }

        flag_pt[index_curr_pt] = 0;
        flag_ct[index_curr_ct] = 0;
        pt_text[curr_lines-1] = curr_pt;  // curr_lines starts from 1
        ct_text[curr_lines-1] = curr_ct;

        curr_lines ++;
    }

    if (fscanf(map_f,"%s", &curr_pt) != EOF || curr_lines != 27){  // check the numbers of lines, should be 27 agter loop

        fprintf(stderr, "Error: The format of mapping file %s is incorrect\n", mapping_file);
        exit(4);

    }

    fclose(map_f);

}

void check_inputf_exist(char * input_file){  // similar to check_mapf_exist
    FILE *in_f = fopen(input_file, "r");
    if (in_f == NULL) {
        fprintf(stderr, "Error: Mapping file %s does not exist\n", input_file);
        exit(5);
    }
    fclose(in_f);
}


void check_mode(char * encryption_mode) {
    if (!(strcmp(encryption_mode, "1") != 0 || strcmp(encryption_mode, "2") != 0)) {  // if not (equal to 1 or 2)
        fprintf(stderr, "You entered %s. Sorry, your mode must be 1 for encryption or 2 for decryption", encryption_mode);
        exit(6);
    }
}

void check_usage(int argc, char * argv[], char * mf_em_if[]){

    if (argc != 7) {  // number of arguments
        fprintf(stderr, "Usage: ./encrypt -t <mappingfile> -m <encryption mode> -i <inputfile>");
        exit(7);
    }
    char * mapping_file;
    char * encryption_mode;
    char * input_file;
    _Bool used[3] = {1, 1, 1};  // used to check usage of arguments, true means not used
    // index0 is for "-t", index1 is for "m", index2 is for "-1"

    for (int i = 1; i < 7; i+=2) {  // flags only occurs at index1,3,5   followed by file name or mode num.

        // strcmp function return differences between of ASCII of chars of two strings
        if ( strcmp(argv[i], "-t") == 0 ) {
            if (used[0]) {  // not used gives 1
                used[0] = 0;
                mapping_file = argv[i + 1];
            }
        }
        else if ( strcmp(argv[i], "-m") == 0 ){
            if(used[1]){
                used[1] = 0;
                encryption_mode = argv[i + 1];
            }
        }
        else if ( strcmp(argv[i], "-i") == 0 ) {
            if(used[2]){
                used[2] = 0;
                input_file = argv[i + 1];
            }
        }
    }

    if (used[0] == 1 || used[1] == 1 || used[2] == 1){  // repeated usage or wrong flag will cause empty
        fprintf(stderr, "Usage: ./encrypt -t <mappingfile> -m <encryption mode> -i <inputfile>");
        exit(7);
    }


    mf_em_if[0] = mapping_file;
    mf_em_if[1] = encryption_mode;
    mf_em_if[2] = input_file;


}

void encrypt_file(const char *pt_text, const char *ct_text, char *input_file){

    FILE * in_f = fopen(input_file, "r");

    char pt_chr;  // char, used to read from plaintext
    int index;  // index of the char in pt_text and ct_text
    int output_index = 0;  // index of the output string pointer, also indicate the (length of a word)-1
    char word[25];  // size should be large enough to store a single word

    while (fscanf(in_f,"%c", &pt_chr) != EOF){  // stop when reach the end of file

        if (pt_chr == '\n') {  // go to a new line
            output_index --;  // read from the previous char, instead of from '\n'
            for (; output_index >= 0; output_index--) fprintf(stdout, "%c", word[output_index]);  // print the word in the line
            fprintf(stdout, "\n");  // output also goes to a new line
            output_index = 0;  // initiate the output_index for the next line
        }
        else{

            for (int i = 0; i < 26; ++i) {  // find the char in the corresponding relationship between pt and ct
                if (pt_text[i] == pt_chr){
                    index = i;  // to find the index of the ciphertext for the char at current line
                    break;
                }
            }

            word[output_index] = ct_text[index];  // store the cipher letter
            output_index ++;  // index + 1

        }

    }
    // still need to print the last line
    output_index--;  // minus 1 index with no data
    for (; output_index >= 0; output_index--) fprintf(stdout, "%c", word[output_index]);

}


void decrypt_file(const char pt_text[], const char ct_text[], char input_file[]){  // same method as encrypt_file

    FILE * in_f = fopen(input_file, "r");
    char ct_chr;
    int index;
    int output_index = 0;
    char word[25];
    while (fscanf(in_f,"%c", &ct_chr) != EOF){

        if (ct_chr == '\n') {
            output_index--;
            for ( ; output_index >= 0; output_index--) {
                fprintf(stdout, "%c", word[output_index]);
            }
            fprintf(stdout, "\n");
            output_index = 0;
        }
        else{

            for (int i = 0; i < 26; ++i) {
                if (ct_text[i] == ct_chr){
                    index = i;
                    break;
                }
            }

            word[output_index] = pt_text[index];
            output_index ++;

        }

    }
    output_index--;
    for (; output_index >= 0; output_index--) fprintf(stdout, "%c", word[output_index]);

}

void run(char * mf_em_if[], char pt_text[], char ct_text[]){
    char * encryption_mode = mf_em_if[1], * input_file = mf_em_if[2];
    if (strcmp(encryption_mode, "1") == 0){  // 1 or 2 mode

        encrypt_file(pt_text, ct_text, input_file);

    }
    else decrypt_file(pt_text, ct_text, input_file);

}


void check_error(int argc, char * argv[], char * mf_em_if[], char *pt_text, char *ct_text){

    check_usage(argc, argv, mf_em_if);  // check arguments, store necessary arguments. exit code 7
    check_mapf_exist(mf_em_if[0]);  // check if mapping file can be found
    check_mode(mf_em_if[1]);  // check if mode is 1 or 2
    check_inputf_exist(mf_em_if[2]);  // check if input file can be found
    check_mapf_format(mf_em_if[0], pt_text, ct_text);  // check format of mapping file
    // and get the corresponding relationship between plaintext and ciphertext

}




int main(int argc, char * argv[]) {
    // this will store mapping_file name, encryption_mode, input_file name in that order
    char * mf_em_if[3];

    // store the plaintext alphabet and corresponding ciphertext alphabet
    char pt_text[26], ct_text[26];

    // error checking, exit program and print error to stderr if anything wrong
    check_error(argc, argv, mf_em_if, pt_text, ct_text);

    // main function of decrypt/ encrypt
    run(mf_em_if, pt_text,ct_text);

    return 0;
}
*/

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