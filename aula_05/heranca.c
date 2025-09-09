#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Definição da struct
typedef struct person
{
    struct person *parents[2];
    char alleles[2];
} person;

// Protótipos
person *create_family(int generations);
void print_family(person *p, int generation);
void free_family(person *p);
char random_allele();

int main(void)
{
    // Inicializa o gerador de números aleatórios
    srand(time(0));

    // Define número de gerações (ex: 3)
    int generations = 3;

    // Cria a família
    person *p = create_family(generations);

    // Imprime a árvore genealógica
    print_family(p, 0);

    // Libera a memória
    free_family(p);

    return 0;
}

// Cria recursivamente uma árvore genealógica
person *create_family(int generations)
{
    person *p = malloc(sizeof(person));
    if (p == NULL)
    {
        fprintf(stderr, "Erro ao alocar memória\n");
        exit(1);
    }

    // Caso base: geração mais antiga
    if (generations <= 1)
    {
        p->parents[0] = NULL;
        p->parents[1] = NULL;
        p->alleles[0] = random_allele();
        p->alleles[1] = random_allele();
    }
    else
    {
        // Cria os pais
        p->parents[0] = create_family(generations - 1);
        p->parents[1] = create_family(generations - 1);

        // Herdar alelos aleatórios dos pais
        p->alleles[0] = p->parents[0]->alleles[rand() % 2];
        p->alleles[1] = p->parents[1]->alleles[rand() % 2];
    }

    return p;
}

// Imprime recursivamente a árvore genealógica
void print_family(person *p, int generation)
{
    // Indentação
    for (int i = 0; i < generation; i++)
    {
        printf("  ");
    }

    if (generation == 0)
    {
        printf("Pessoa (filho): genes %c%c\n", p->alleles[0], p->alleles[1]);
    }
    else
    {
        printf("Geração %i (pai/mãe): genes %c%c\n", generation, p->alleles[0], p->alleles[1]);
    }

    // Recursivamente imprime os pais
    if (p->parents[0] != NULL && p->parents[1] != NULL)
    {
        print_family(p->parents[0], generation + 1);
        print_family(p->parents[1], generation + 1);
    }
}

// Libera a memória recursivamente
void free_family(person *p)
{
    if (p == NULL)
    {
        return;
    }

    free_family(p->parents[0]);
    free_family(p->parents[1]);
    free(p);
}

// Retorna um alelo aleatório (A, B ou O)
char random_allele()
{
    char alleles[] = {'A', 'B', 'O'};
    return alleles[rand() % 3]; // o %3 são as OPCOES de A,B ou O
}
