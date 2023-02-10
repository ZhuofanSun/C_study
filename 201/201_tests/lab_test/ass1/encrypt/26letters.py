import random

letters = []
letters_random = []
for i in range(ord('a'), ord('z') + 1):
    letters.append(i)
    letters_random.append(i)

random.shuffle(letters_random)

mapping_file = open("mapping_encryption.csv", "w")

for i in range(25):
    mapping_file.write("{},{}\n".format(chr(letters[i]), chr(letters_random[i])))

mapping_file.write("{},{}".format(chr(letters[25]), chr(letters_random[25])))
mapping_file.close()

mapping_file = open("mapping_encryption.csv", "r")
input_encryption = open("input_encryption.txt", "w")
output_encryption = open("output_encryption.txt", "w")

en_in_message = "this\nis\na\nnew\ntest"
en_out_message = ""

en_in_lst = []
en_out_lst = []

for char in en_in_message:
    en_in_lst.append(char)
    if char != "\n":
        en_out_lst.append(chr(letters_random[letters.index(ord(char))]))
    else:
        en_out_lst.append("\n")

lst = []
i = 0
while i != len(en_out_lst):
    if en_out_lst[i] != '\n':
        lst.append(en_out_lst[i])
    else:
        lst.reverse()
        lst.append('\n')
        output_encryption.write(''.join(lst))
        lst = []
    i += 1
lst.reverse()
output_encryption.write(''.join(lst))
input_encryption.write(en_in_message)

mapping_file.close()
input_encryption.close()
output_encryption.close()




letters = []
letters_random = []
for i in range(ord('a'), ord('z') + 1):
    letters.append(i)
    letters_random.append(i)

random.shuffle(letters_random)

mapping_file = open("mapping_decryption.csv", "w")

for i in range(25):
    mapping_file.write("{},{}\n".format(chr(letters[i]), chr(letters_random[i])))

mapping_file.write("{},{}".format(chr(letters[25]), chr(letters_random[25])))
mapping_file.close()

de_in_message = "today\nis\na\ngood\nday"
de_out_message = ""
de_in_lst = []
de_out_lst = []

for char in de_in_message:
    de_in_lst.append(char)
    if char != "\n":
        de_out_lst.append(chr(letters_random[letters.index(ord(char))]))
    else:
        de_out_lst.append("\n")
input_decryption = open("input_decryption.txt", "w")
output_decryption = open("output_decryption.txt", "w")

i = 0
lst = []
while i != len(de_out_lst):
    if de_out_lst[i] != '\n':
        lst.append(de_out_lst[i])
    else:
        lst.reverse()
        lst.append('\n')
        input_decryption.write(''.join(lst))
        lst = []
    i += 1
lst.reverse()
input_decryption.write(''.join(lst))
output_decryption.write(de_in_message)

"""

#!/bin/bash
make
./encrypt -t mapping_encryption.csv -m 1 -i input_encryption.txt
make clean




"""
