#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Objetivo: Fazer com que tenha gerações pai(AB) e mae(OB)-> AO, OB, AB e OO.
// OO, OA, OB, AO, AA, AB, BO, BA e BB.
typedef struct person
{
    char alleles[2];            // Alelos da pessoa, ex: ['A', 'O']
    struct person *parents[2];  // Pai e mãe
} person;
void imprime(person *p, int generation);


int main(void)
{
    // Aloca memória para uma pessoa
    person *anaDivina = malloc(sizeof(person));
    person *hebervaldo = malloc(sizeof(person));
    person *rebeca = malloc(sizeof(person));

    // if (p == NULL)
    // {
    //     fprintf(stderr, "Erro ao alocar memória\n");
    //     return 1;
    // }

    // Exemplo de como preencher os dados
    anaDivina->alleles[0] = 'A';
    anaDivina->alleles[1] = 'B';
    anaDivina->parents[0] = NULL;
    anaDivina->parents[1] = NULL;

    hebervaldo->alleles[0] = 'A';
    hebervaldo->alleles[1] = 'O';
    hebervaldo->parents[0] = NULL;
    hebervaldo->parents[1] = NULL;

    imprime(anaDivina, 1);
    imprime(hebervaldo, 1);

    rebeca->alleles[0] = 'B';
    rebeca->alleles[1] = 'A';
    rebeca->parents[0] = hebervaldo;
    rebeca->parents[1] = anaDivina;
    imprime(rebeca, 2);
    // Libera a memória ao final
    free(anaDivina);
    free(hebervaldo);
    free(rebeca);

    return 0;
}

void imprime(person *p, int generation)
{
    // Indentação para mostrar hierarquia
    for (int i = 0; i < generation - 1; i++)
    {
        printf("  ");  // duas espaços por geração
    }

    printf("Geração %d: Alelos %c%c\n", generation, p->alleles[0], p->alleles[1]);
}
