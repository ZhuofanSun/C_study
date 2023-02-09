/* Demo different writing modes */

#include <stdio.h>
int main (void) {

    FILE *fp_out = fopen("out.txt", "w");
    FILE *fp_out_a = fopen("append.txt", "a");

    fprintf(fp_out, "Let's add one more line\n");
    fprintf(fp_out_a, "Let's add one more line\n");

    fclose(fp_out);
    fclose(fp_out_a);

    return 0;

}
