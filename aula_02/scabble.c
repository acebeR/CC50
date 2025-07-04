// Em um arquivo chamado scrabble.c, dentro da pasta /pset2/scrabble,
// implemente um programa em C que determine o vencedor de um jogo curto semelhante ao Scrabble.
// Seu programa deve solicitar entrada duas vezes: uma vez para que "Jogador 1"
// insira sua palavra e outra vez para que "Jogador 2" insira sua palavra. Em seguida,
// dependendo de qual jogador marcar mais pontos, seu programa deve imprimir “Player 1 wins!”
// (caso o jogador 1 ganhe), “Player 2 wins!” (se o jogador 2 venceu) ou “Tie!” (caso os dois jogadores pontuem igualmente).
#include <ctype.h>
#include <cs50.h>
#include <stdio.h>
#include <string.h>



int compute_score(string word);
string entrada(char texto[]);
string vencedor(int somaPlayer1, int somaPlayer2);
int main(void)
{
    string entrada1;
    string entrada2;
    int somaPlayer1 = 0;
    int somaPlayer2 = 0;
    string resposta;
    // Solicitar ao usuário duas palavras
    entrada1 = entrada("Player 1: ");
    entrada2 = entrada("Player 2: ");
    // Calcular os pontos de cada palavra
    somaPlayer1 = compute_score(entrada1);
    somaPlayer2 = compute_score(entrada2);
    // Imprimir o vencedor
    printf("===============\n");
    printf("soma 1: %d\n", somaPlayer1);
    printf("soma 2: %d\n", somaPlayer2);
    resposta = vencedor(somaPlayer1,somaPlayer2);
    printf("Vencedor: %s\n", resposta);
    printf("===============\n");
}
string vencedor(int somaPlayer1, int somaPlayer2){
    if(somaPlayer1 > somaPlayer2){
        return "Player 1";
    }else{
        return "Player 2";
    }
}
string entrada(string texto){
    return get_string("%s",texto);
}
int compute_score(string word)
{
    char alfabeto[] = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm','n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z'};
    int pontos[] = {1, 3, 3, 2, 1, 4, 2, 4, 1, 8, 5, 1, 3, 1, 1, 3, 10, 1, 1, 1, 1, 4, 4, 8, 4, 10};
    int soma = 0;
    for(int i = 0; i < strlen(word); i++){
        for(int j = 0; j < strlen(alfabeto); j++){
            if(word[i] == alfabeto[j]){
                soma = soma + pontos[j];
            }
        }
    }
    return soma;
}
