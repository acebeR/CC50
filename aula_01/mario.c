//Para executar: make "nome arquivo", depois ./"nome do arquivo"
#include <cs50.h>
#include <stdio.h>

// Funções
void home(void);
int getNumberHashs(void);
void assemble(int size);
void tabulacao(int size,int linha);
void hashs(int linha);
// ===========
int main(void)
{
    home();
    int size = getNumberHashs();
    assemble(size);
}
// Iniciar tela
void home(void){
     printf("====== Bem Vindo ======\n");
     printf("Digite o tamanho da piramide que deseja. Podendo variar de 1 a 8\n");
     return;
}
// Pedir a quantidade para o tamanho da piramide
int getNumberHashs(void)
{
     int resposta;
     int validacao = 0;
     do
     {
          resposta = get_int("Tamanho: ");
          if((resposta >= 1) && (resposta <= 8)){
            validacao = 1;
          }else{
            printf("O tamanho precisa ser de 1 até 8!\n");
          }
	 }while(validacao == 0);
     return resposta;
}
// Montar
void assemble(int size){
    printf("====== Resposta ======\n");
    int lin = 1;
    do
    {
        tabulacao(size,lin);
        hashs(lin);
        printf("\n");
        lin ++;
    }
    while(lin <= size);
    return;
}
void tabulacao(int size,int linha){
    int tab = 0;
    while(tab < (size-linha)){
        printf(" ");
        tab ++;
    }
}
void hashs(int linha){
    int qtd = 0;
    while(qtd < linha){
        printf("#");
        qtd ++;
    }

}
