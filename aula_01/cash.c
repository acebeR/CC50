// Para executar: make "nome arquivo", depois ./"nome do arquivo"
// Implemente, em um arquivo chamado cash.c em um diretório ~/pset1/cash, um programa que pergunta ao
// usuário quanto dinheiro é devido e em seguida imprime o número mínimo de moedas com as quais essa troca pode ser feita.


#include <cs50.h>
#include <stdio.h>
#include <math.h>
// Funções
void home(void);
float validaEntrada();
void trocaPorMoedas(float size);
void tabelinhaMoedas(int moedas25,int moedas10,int moedas5,int moedas1);
// ===========
int main(void)
{
    char resposta;
    home();
    do{
        float size = validaEntrada();
        trocaPorMoedas(size);
        resposta = get_char("Deseja fazer outra operação? ");
    }while(resposta == 's' || resposta == 'S');
}
void home(void){
     printf("====== Bem Vindo ao Cash ======\n");
     return;
}
float validaEntrada(){
     float resposta;
     int validacao = 0;
     do
     {
          resposta = get_float("Digite o valor, em dinheiro, para que seja formatado em moedas: ");
          if((resposta >= 0)){
            validacao = 1;
          }else{
            printf("O tamanho precisa ser maior que 0.00\n");
          }
	 }while(validacao == 0);
     return resposta;
}
void tabelinhaMoedas(int moedas25,int moedas10,int moedas5,int moedas1){
    printf("======== Tabela de Moedas ======\n");
    printf(" Moedas de 25: %i\n",moedas25);
    printf(" Moedas de 10: %i\n",moedas10);
    printf(" Moedas de 5: %i\n",moedas5);
    printf(" Moedas de 1: %i\n",moedas1);
    printf("================================\n");
}
void trocaPorMoedas(float valor) {
    // Converte o valor para centavos (evita problemas com float)
    int centavos = (int)(valor * 100 + 0.5);  // arredonda corretamente

    int moedas25 = 0;
    int moedas10 = 0;
    int moedas5 = 0;
    int moedas1 = 0;

    while (centavos >= 25) {
        centavos -= 25;
        moedas25++;
    }

    while (centavos >= 10) {
        centavos -= 10;
        moedas10++;
    }

    while (centavos >= 5) {
        centavos -= 5;
        moedas5++;
    }

    while (centavos >= 1) {
        centavos -= 1;
        moedas1++;
    }
    tabelinhaMoedas(moedas25, moedas10, moedas5, moedas1);
}
