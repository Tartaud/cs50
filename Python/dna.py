import sys
import csv


def main():
    if len(sys.argv) != 3:
        print("Usage: python dna.py data.csv sequence.txt")
        sys.exit()
    csvfilename = sys.argv[1]
    sequencefilename = sys.argv[2]
    plzWork = []
    with open(sequencefilename) as f:
        sequence = csv.reader(f)
        for row in sequence:
            plzWork.append(row)
    names = []
    with open(csvfilename) as f:
        reader = csv.DictReader(f)
        for name in reader:
            names.append(name)
    a = []
    with open(csvfilename) as f:
        reader = csv.reader(f)
        for row in reader:
            a.append(row)

    strs = str(a[0])
    strs = strs.split(",")
    for i in range(len(strs)):
        strs[i] = strs[i].replace("[", "")
        strs[i] = strs[i].replace("'", "")
        strs[i] = strs[i].replace("]", "")
        strs[i] = strs[i].replace(" ", "")
    for j in range(len(names)):
        for i in range(1, len(strs), 1):
            if names[j][strs[i]] != str(CountSTRinDNA(strs[i], str(plzWork[0]))):
                break
            elif i == len(strs) - 1:
                sys.exit(names[j]["name"])
    sys.exit("No match")


def CountSTRinDNA(strSequence, dnaSequence):
    totalNumber = 0
    maxNumber = 0
    for i in range(len(dnaSequence)):
        if dnaSequence[i] == strSequence[0]:
            totalNumber = CountSTRfromX(strSequence, dnaSequence, i)
            if(totalNumber > maxNumber):
                maxNumber = totalNumber
    return maxNumber


def CountSTRfromX(strSequence, dnaSequence, startSequence):
    number = 0
    for i in range(startSequence, len(dnaSequence), len(strSequence)):
        for j in range(len(strSequence)):
            if dnaSequence[i + j] != strSequence[j]:
                return number
                break
            elif j == len(strSequence) - 1:
                number += 1


main()