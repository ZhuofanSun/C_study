# Assignment 2

## Information about yourself

 * `Student name:`        Zhuofan Sun
 * `Student ID:`          1740983
 * `CCID:`                zhuofan3
 * `Lecture section:`     B1
 * `Instructor's name:`   Henry Tang
 * `Lab section:`         H01

## The purpose of your program

This assignment requires implementing a solver for word-search puzzles. Given a grid of random letters and a set of words, the program needs to find the location of the input words in the grid (if they exist). The orientation of the words can be horizontal, vertical, left diagonal, or right diagonal. The words can be read left to right, right to left, top to bottom (whether vertically or diagonally), and bottom to up (whether vertically or diagonally). The words can start at any place in this grid. The problem is approached using the Rabin-Karp algorithm.

## The exact commands we need to run your code

In root directory:
`make` to create a executable file called wordSearch2D
`./wordSearch2D -p <puzzle_file> -l <word_length> -w <wordlist_file> [-o <solution_file>]` to run the file, -o <solution_file> is optional, the output file will be in the root directory.
`./tests/local/sample_test.sh` to run test case
`make clean` to remove the executable file

## The files submitted in your assignment, how they are structured, and what they do

In root directory:
   * `src/wordSearch2D.c`  main function and helper function
   * `src/puzzle2D.c`  find-word functions
   * `src/puzzle2D.h`  header file
   * `src/error_checking.c`  error checking and get data functions
   * `src/error_checking.h`  header file
   * `Makefile`  makefile, to executable file is wordSearch2D
   * `README.md`  readme file
   * `License.md`  course license
   * Your test case files:
     * `tests/local/puzzle.txt`  test case puzzle file
     * `tests/local/wordlist.txt`  test case word list file
     * `tests/local/expected_solution.txt`  test case expected output file
     * `tests/local/sample_test.sh`  test case run script

## Verbal Collaboration 

No verbal collaborations from others.

## References

 * similar functions format in error_checking file from assignment1.
 * 
