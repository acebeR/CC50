# Para rodar: python dna.py databases/small.csv sequences/1.txt

import csv
import sys


def main():
    # Verificar argumentos da linha de comando
    if len(sys.argv) != 3:
        print("Usage: python dna.py data.csv sequence.txt")
        sys.exit(1)

    # Ler arquivo CSV (banco de dados de DNA)
    database_filename = sys.argv[1]
    with open(database_filename, newline='') as csvfile:
        reader = csv.DictReader(csvfile)
        database = list(reader)
        str_keys = reader.fieldnames[1:]  # Ignora a primeira coluna (name)

    # Ler arquivo de sequência de DNA
    sequence_filename = sys.argv[2]
    with open(sequence_filename, 'r') as file:
        dna_sequence = file.read()

    # Calcular maior repetição de cada STR na sequência
    str_counts = {}
    for str_seq in str_keys:
        str_counts[str_seq] = longest_match(dna_sequence, str_seq)

    # Comparar com cada pessoa do banco de dados
    for person in database:
        match = True
        for str_seq in str_keys:
            if int(person[str_seq]) != str_counts[str_seq]:
                match = False
                break
        if match:
            print("A pessoa com sequencia combinada é: ", person['name'])
            return

    # Se nenhum nome combinou
    print("No match")


def longest_match(sequence, subsequence):
    """Retorna o número máximo de repetições consecutivas de `subsequence` em `sequence`."""
    longest_run = 0
    subsequence_length = len(subsequence)
    sequence_length = len(sequence)

    for i in range(sequence_length):
        count = 0

        while True:
            start = i + count * subsequence_length
            end = start + subsequence_length

            if sequence[start:end] == subsequence:
                count += 1
            else:
                break

        longest_run = max(longest_run, count)

    return longest_run


if __name__ == "__main__":
    main()
