import csv
import sys


def main():

    # TODO: Check for command-line usage
    if len(sys.argv) != 3:
        sys.exit("Usage: python tournament.py FILENAME")
    profiles = []
    match = {}
    counter = 0
    winner = "No match"

    # TODO: Read database file into a variable
    with open(sys.argv[1]) as file:
        reader = csv.DictReader(file)
        for row in reader:
            profiles += [row]

    # TODO: Read DNA sequence file into a variable
    with open(sys.argv[2]) as file2:
        csv_file = csv.reader(file2)
        for line in csv_file:
            dna_sequence = line

    # TODO: Find longest match of each STR in DNA sequence
    for dna_sub in profiles[0]:
        if dna_sub == "name":
            continue
        else:
            match[dna_sub] = longest_match(dna_sequence[0], dna_sub)

    # TODO: Check database for matching profiles
    for x in range(len(profiles)-1):
        for t in profiles[0]:
            if t == "name":
                continue
            else:
                if int(profiles[x][t]) == int(match[t]):
                    counter += 1
                else:
                    counter = 0
                    break

        if counter == len(profiles[0])-1:
            winner = profiles[x]["name"]

    print(winner)

    return


def longest_match(sequence, subsequence):
    """Returns length of longest run of subsequence in sequence."""

    # Initialize variables
    longest_run = 0
    subsequence_length = len(subsequence)
    sequence_length = len(sequence)

    # Check each character in sequence for most consecutive runs of subsequence
    for i in range(sequence_length):

        # Initialize count of consecutive runs
        count = 0

        # Check for a subsequence match in a "substring" (a subset of characters) within sequence
        # If a match, move substring to next potential match in sequence
        # Continue moving substring and checking for matches until out of consecutive matches
        while True:

            # Adjust substring start and end
            start = i + count * subsequence_length
            end = start + subsequence_length

            # If there is a match in the substring
            if sequence[start:end] == subsequence:
                count += 1

            # If there is no match in the substring
            else:
                break

        # Update most consecutive matches found
        longest_run = max(longest_run, count)

    # After checking for runs at each character in seqeuence, return longest run found
    return longest_run


main()
