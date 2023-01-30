#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void check_mapf_exist(char * mapping_file ){
    FILE *map_f = fopen(mapping_file, "r");
    if (map_f == NULL) {
        fprintf(stderr, "Error: Mapping file %s does not exist\n", mapping_file);
        exit(3);
    }
    fclose(map_f);

}

void check_mapf_format(char * mapping_file, char pt_text[], char ct_text[]){

    FILE *map_f = fopen(mapping_file, "r");

    int curr_lines = 1;
    char curr_pt, curr_ct;
    _Bool flag_pt[26], flag_ct[26];
    for (int i = 0; i < 26; ++i) {

        flag_pt[i] = 1;
        flag_ct[i] = 1;

    }


    while(curr_lines <= 26 && fscanf(map_f, "%c,%c\n", &curr_pt, &curr_ct) == 2){

        if (curr_pt < 'a' || curr_pt > 'z' || curr_ct < 'a' || curr_ct > 'z'){

            fprintf(stderr, "Error: The format of mapping file %s is incorrect\n", mapping_file);
            exit(4);

        }

        int index_curr_pt = curr_pt - 'a';
        int index_curr_ct = curr_ct - 'a';
        if (!flag_ct[index_curr_ct] || !flag_pt[index_curr_pt]){

            fprintf(stderr, "Error: The format of mapping file %s is incorrect\n", mapping_file);
            exit(4);

        }

        flag_pt[index_curr_pt] = 0;
        flag_ct[index_curr_ct] = 0;

        pt_text[curr_lines-1] = curr_pt;
        ct_text[curr_lines-1] = curr_ct;

        curr_lines ++;
    }

    if (fscanf(map_f,"%s", &curr_pt) != EOF || curr_lines != 27){

        fprintf(stderr, "Error: The format of mapping file %s is incorrect\n", mapping_file);
        exit(4);

    }



}

void check_inputf_exist(char * input_file){
    FILE *in_f = fopen(input_file, "r");
    if (in_f == NULL) {
        fprintf(stderr, "Error: Mapping file %s does not exist\n", input_file);
        exit(5);
    }
    fclose(in_f);
}


void check_mode(char * encryption_mode) {
    if (!(strcmp(encryption_mode, "1") == 0 || strcmp(encryption_mode, "2") == 0)) {
        fprintf(stderr, "You entered %s. Sorry, your mode must be 1 for encryption or 2 for decryption", encryption_mode);
        exit(6);
    }
}

void check_usage(int argc, char * argv[], char * mf_em_if[]){

    if (argc != 7) {
        fprintf(stderr, "Usage: ./encrypt -t <mappingfile> -m <encryption mode> -i <inputfile>");
        exit(7);
    }
    char * mapping_file;
    char * encryption_mode;
    char * input_file;
    _Bool used[3] = {1, 1, 1};
    for (int i = 1; i < 7; i+=2) {
        if ( strcmp(argv[i], "-t") == 0 ) {
            if (used[0]) {
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



    if (used[0] == 1 || used[1] == 1 || used[2] == 1){
        fprintf(stderr, "Usage: ./encrypt -t <mappingfile> -m <encryption mode> -i <inputfile>");
        exit(7);
    }

    if (mapping_file == NULL){
        fprintf(stderr, "Usage: ./encrypt -t <mappingfile> -m <encryption mode> -i <inputfile>");
        exit(7);
    }

    mf_em_if[0] = mapping_file;
    mf_em_if[1] = encryption_mode;
    mf_em_if[2] = input_file;


}


void encrypt_file(const char *pt_text, const char *ct_text, char *input_file){

    FILE * in_f = fopen(input_file, "r");
    char pt_chr;
    int index;
    int output_index = 0;
    char word[30];

    while (fscanf(in_f,"%c", &pt_chr) != EOF){

        if (pt_chr == '\n') {
            output_index --;
            for (; output_index >= 0; output_index--) fprintf(stdout, "%c", word[output_index]);
            fprintf(stdout, "\n");
            output_index = 0;
        }
        else{

            for (int i = 0; i < 26; ++i) {
                if (pt_text[i] == pt_chr){
                    index = i;
                    break;
                }
            }

            word[output_index] = ct_text[index];
            output_index ++;

        }

    }
    output_index--;
    for (; output_index >= 0; output_index--) fprintf(stdout, "%c", word[output_index]);

}


void decrypt_file(const char pt_text[], const char ct_text[], char input_file[]){

    FILE * in_f = fopen(input_file, "r");
    char ct_chr;
    int index;
    int output_index = 0;
    char word[30];
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



int run(char * mf_em_if[], char pt_text[], char ct_text[]){
    char * encryption_mode = mf_em_if[1], * input_file = mf_em_if[2];
    if (strcmp(encryption_mode, "1") == 0){

        encrypt_file(pt_text, ct_text, input_file);

    }
    else decrypt_file(pt_text, ct_text, input_file);

}




int main() {

    int argc = 7;
    char * argv[7] = {"0","-t", "mapping_decryption.csv", "-m", "2", "-i", "input_decryption.txt"};

    char * mf_em_if[3];
    check_usage(argc, argv, mf_em_if);
    check_mapf_exist(mf_em_if[0]);
    check_mode(mf_em_if[1]);
    check_inputf_exist(mf_em_if[2]);
    char pt_text[26], ct_text[26];
    check_mapf_format(mf_em_if[0], pt_text, ct_text);
    run(mf_em_if, pt_text,ct_text);



}