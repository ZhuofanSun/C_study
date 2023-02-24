#include "puzzle2D.h"
#include "error_checking.h"

int main(){

    int argc = 9;
    char * argv[] = {"wordSearch2D", "-p", "../../tests/sample_tests/student_1_table.txt",
                     "-l", "4", "-w", "../../tests/sample_tests/student_1_wordlist.txt", "-o", "ddd"};
    char *pf_wl_wf_sf[4];
    check_usage(argc, argv, pf_wl_wf_sf);


}