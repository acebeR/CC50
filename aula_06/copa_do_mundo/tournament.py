# Simulate a sports tournament

import csv
import sys
import random

# Number of simluations to run
N = 1000


def main():
    # Variáveis
    counts = {}
    teams = []

    # Verifica argumentos
    if len(sys.argv) != 2:
        sys.exit("Usage: python tournament.py FILENAME")

    # Lê times do arquivo
    arquivo = sys.argv[1]
    teams = lerArquivo(arquivo)

    # Simula N torneios
    for i in range(N):
        vencedor = simular_torneio(teams.copy())
        if vencedor in counts:
            counts[vencedor] += 1
        else:
            counts[vencedor] = 1

    # Imprime resultados
    print("-------- Tabelinha de Probabilidades ---------")
    print("  Time            |        Chances de vencer  ")
    for team in sorted(counts, key=lambda team: counts[team], reverse=True):
        resposta = f"{counts[team] * 100 / N:.1f}"
        print(f"{team:<15}   | {resposta:>18}%")
    print("----------------------------------------------")

def simular_torneio(teams):
    while len(teams) > 1:
        teams = simulate_round(teams)
    return teams[0]["team"]

def lerArquivo(arquivo):
    times = []
    with open(arquivo, mode='r', encoding='utf-8') as arquivo:
        leitor = csv.DictReader(arquivo)
        for linha in leitor:
            linha["rating"] = int(linha["rating"])
            times.append(linha)
    return times

def simulate_game(team1, team2):
    """Simulate a game. Return True if team1 wins, False otherwise."""
    rating1 = team1["rating"]
    rating2 = team2["rating"]
    probability = 1 / (1 + 10 ** ((rating2 - rating1) / 600))
    return random.random() < probability


def simulate_round(teams):
    """Simulate a round. Return a list of winning teams."""
    winners = []

    # Simulate games for all pairs of teams
    for i in range(0, len(teams), 2):
        if simulate_game(teams[i], teams[i + 1]):
            winners.append(teams[i])
        else:
            winners.append(teams[i + 1])

    return winners


def simulate_tournament(teams):
    """Simulate a tournament. Return name of winning team."""
    # TODO


if __name__ == "__main__":
    main()
