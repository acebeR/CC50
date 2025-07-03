// Em um arquivo chamado credit.c em um diretório ~/pset1/credit/,
// escreva um programa que solicite ao usuário um número de cartão de crédito e, em seguida,
// informe (por printf) se é um número de cartão American Express,
// MasterCard ou Visa válido, de acordo com as definições de formato de cada um neste documento.
#include <cs50.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
// Funções
void home(void);
long validaEntrada(void);
void validaCartao(long nCard);
void imprimeString(char texto[]);
char* tiraEspacosTexto(char texto[]);
void imprimeInt(int texto[],int tamanho);
void verificaTipoCartao(int numeroDocartao[21]);
// ===========
int main(void)
{
    char resposta;
    home();
    do{
        long nCard = validaEntrada();
        validaCartao(nCard);
        resposta = get_char("Deseja fazer outra operação? ");
    }while(resposta == 's' || resposta == 'S');
}
void home(void){
     printf("====== Bem Vindo ======\n");
     return;
}
long validaEntrada(){
     long resposta;
     int validacao = 0;
     do
     {
          resposta = get_long("Digite o número do cartão: ");
          if((resposta >= 0)){
            validacao = 1;
          }else{
            printf("O tamanho precisa ser maior que 0\n");
          }
	 }while(validacao == 0);
     return resposta;
}
char* tiraEspacosTexto(char texto[]) {
    int tamanho = strlen(texto);
    char *resposta = malloc(tamanho + 1);
    if (resposta == NULL) return NULL;

    int j = 0;
    for (int i = 0; i < tamanho; i++) {
        if (!isspace((unsigned char)texto[i])) {
            resposta[j++] = texto[i];
        }
    }
    resposta[j] = '\0';
    return resposta;
}
int* intParaDigitos(int numero, int* tamanho) {
    int temp = numero;
    *tamanho = 0;

    // Conta quantos dígitos o número tem
    if (numero == 0) {
        *tamanho = 1;
    } else {
        while (temp > 0) {
            (*tamanho)++;
            temp /= 10;
        }
    }

    // Aloca array para os dígitos
    int* digitos = malloc(*tamanho * sizeof(int));

    // Preenche o array de trás pra frente
    for (int i = *tamanho - 1; i >= 0; i--) {
        digitos[i] = numero % 10;
        numero /= 10;
    }

    return digitos;
}
void validaCartao(long nCard) {
    printf("================\n");
    int numeroCartao[20];
    int numeroCartaoOriginal[20];
    char str[21];

    sprintf(str, "%ld", nCard);
    int tamanho = strlen(str);

    for (int i = 0; i < tamanho; i++) {
        numeroCartao[i] = str[i] - '0';
    }

    int somaMult = 0;
    int somaNaoMult = 0;
    int somaTotal = 0;
    for (int i = tamanho - 1; i >= 0; i--) {
        int temp = numeroCartao[i];
        int posicaoDireita = tamanho - 1 - i;
        numeroCartaoOriginal[i] = temp;
        if (posicaoDireita % 2 == 1) {
            temp *= 2;
            if (temp > 9) {
                temp = (temp / 10) + (temp % 10);
            }
            somaMult = somaMult + temp;
        }else{
            somaNaoMult = somaNaoMult + temp;
        }
        numeroCartao[i] = temp;
    }
    somaTotal = somaMult + somaNaoMult;
    printf("A soma total é: %i\n",somaTotal);
    if (somaTotal % 10 == 0) {
        printf("Cartão válido!\n");
        verificaTipoCartao(numeroCartaoOriginal);
    } else {
        printf("O número do cartão está incorreto!\n");
    }
    printf("================\n");
}
void imprimeString(char texto[]) {
    int tamanho = strlen(texto);
    for (int i = 0; i < tamanho; i++) {
        printf("%c", texto[i]);
    }
    printf("\n");
}
void imprimeInt(int texto[],int tamanho) {
    for (int i = 0; i < tamanho; i++) {
        printf("%i", texto[i]);
    }
    printf("\n");
}
void verificaTipoCartao(int numeroDocartao[21]){
    if(numeroDocartao[0] == 4){
        printf( "Visa\n");
        return;
    }
    if(numeroDocartao[0] == 5){
        if(numeroDocartao[0] == 5){
            if(numeroDocartao[1] == 1 || numeroDocartao[1] == 5){
                printf( "MasterCard\n");
                return;
            }
        }
    }
    if(numeroDocartao[0] == 3){
        if(numeroDocartao[1] == 4 || numeroDocartao[1] == 5){
            printf( "American Express\n");
            return;
        }
    }
    if(numeroDocartao[0] == 2){
        if(numeroDocartao[1] == 2){
            if(numeroDocartao[2] == 2){
                if(numeroDocartao[3] == 1){
                    printf( "MasterCard\n");
                    return;
                }
            }
        }
        if(numeroDocartao[1] == 7){
            if(numeroDocartao[2] == 2){
                if(numeroDocartao[3] == 0){
                    printf( "MasterCard\n");
                    return;
                }
            }
        }
    }
    printf( "Cartão inválido\n");
    return;
}

