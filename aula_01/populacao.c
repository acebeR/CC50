// Digamos que temos uma população de n lhamas. A cada ano, nascem n/3 novas lhamas e n/4 morrem.
// Por exemplo, se começarmos com n = 1.200 lhamas, no primeiro ano, 1.200 / 3 = 400 novas
// lhamas nascerão e 1.200 / 4 = 300 lhamas morrerão. No final daquele ano, teríamos 1.200 + 400 - 300 = 1.300 lhamas.
// Para tentar outro exemplo, se começarmos com n = 1000 lhamas, no final do ano teremos 1000/3 = 333,33 novas lhamas.
// Não podemos ter uma parte decimal de uma lhama, entretanto, vamos truncar o decimal para que 333 novas lhamas nasçam.
// 1000/4 = 250 lhamas passarão, então terminaremos com um total de 1000 + 333 - 250 = 1083 lhamas no final do ano.
#include <cs50.h>
#include <stdio.h>
#include <math.h>
// Funções
void home(void);
int calculoLhamas(int qtdLhamasInit);
int emAnos(int populacao_inicial, int populacao_final);
// ===========
int main(void)
{
    char resposta;
    home();
    int qtdLhamasInit = 1;
    int retorno = 0;
    int anos = 0 ;
    do{
        qtdLhamasInit = get_int("Digite a quantidade inicial de lhamas: ");
        retorno = retorno + calculoLhamas(qtdLhamasInit);
        anos ++;
    }while(qtdLhamasInit >= 1);
    printf("Teremos %i de lhamas neste ano. \n",retorno);
    printf("Anos: %i: \n",anos);
}
void home(void){
     printf("====== Bem Vindo ======\n");
     return;
}
int calculoLhamas(int qtdLhamasInit){
    return qtdLhamasInit + ( (qtdLhamasInit/3) - (qtdLhamasInit/4) );
}
