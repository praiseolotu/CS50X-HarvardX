import csv
from sys import argv

if(len(argv) != 3):
    print("python dna.py databases/large.csv sequences/5.txt")
    exit(1)

# Opening data.csv on read mode
open_csv = open(argv[1], "r")

# Reading csv file while saving data to a list and a library
sequence = []
names = {}

for index, row in enumerate(open_csv):
    if index == 0:
        sequence = [strand for strand in row.strip().split(",")][1:]

    else:
        current_row = row.strip().split(",")
        names[current_row[0]] = [int(number) for number in current_row[1:]]

# Opening sequences.txt on read mode and reading all of it
dna_strand = open(argv[2], "r").read()

# Extracting the information we want from files
final_strands = []

for strand in sequence:
    index = 0
    max_strand = -1
    current_max = 0

    while index < len(dna_strand):
        current_block = dna_strand[index:index + len(strand)]

        if current_block == strand:
            current_max += 1
            max_strand = max(max_strand, current_max)
            index += len(strand)

        else:
            current_max = 0
            index += 1

    final_strands.append(max_strand)

# Printing the key from our library when it matches given dna strand
for name, data in names.items():
    if data == final_strands:
        print(name)
        exit(0)

# Else no match
print("No match")