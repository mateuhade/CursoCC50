import csv
import sys


def main():

    # Check for incorrect usage of command
    if len(sys.argv) != 3:
        print("Usage: python dna.py [databases/size.csv] [sequences/0.txt]")
        return 1

    # Creates a list containing dictionaries of every name and dna subsequence of every person in the database
    listOfDatabaseDicts = []
    with open(sys.argv[1]) as file:
        reader = csv.DictReader(file)
        for item in reader:
            listOfDatabaseDicts.append(item)

    # Stores the dna sequence that the subsequences will be compared to in a string
    dnaSequence = ""
    with open(sys.argv[2]) as file:
        for STR in file:
            dnaSequence += STR

    # Creates a list containing each header from the database, item 0 being the name of the person and the subsequent ones
    # being the dna subsequences
    dnaSubsequences = []
    for key in listOfDatabaseDicts[0]:
        dnaSubsequences.append(key)

    # Creates a list containing the number of matches for each subsequence in the dna sequence
    dnaMatches = []
    for subsequence in range(1, len(dnaSubsequences)):
        currentMatch = longest_match(dnaSequence, dnaSubsequences[subsequence])
        dnaMatches.append(currentMatch)

    dnaSearchResult = check_for_dna_match(listOfDatabaseDicts, dnaSubsequences, dnaMatches)
    print(dnaSearchResult)

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

def check_for_dna_match(database, dnaSubsequences, dnaMatches):

    # TODO: Check database for matching profiles
    isCurrentPersonMatch = True
    for person in database:
        
        for subsequence in range(1, len(dnaSubsequences)):
            currentSubsequence = dnaSubsequences[subsequence]
            if not (dnaMatches[subsequence-1] == int(person[currentSubsequence])):
                isCurrentPersonMatch = False

        if isCurrentPersonMatch:
            return person["name"]
        
        isCurrentPersonMatch = True
    
    return "No match found"


main()
