#include <ctype.h>
#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char* ceasar(string texto, int k);

int main(void)
{
    string texto = get_string("Digite um texto: ");
    int chave = get_int("Digite a chave (k): ");

    char* cifrado = ceasar(texto, chave);

    if (cifrado != NULL) {
        printf("Texto cifrado: %s\n", cifrado);
        free(cifrado);
    }

    return 0;

}
// Ci = (Pi + k) % 26
char* ceasar(string texto, int k) {
        int tamanho = strlen(texto);
    char* retorno = malloc(tamanho + 1);

    if (retorno == NULL) {
        return NULL;
    }

    for (int i = 0; i < tamanho; i++) {
        char c = texto[i];

        if (c >= 'a' && c <= 'z') {
            retorno[i] = ((c - 'a' + k) % 26) + 'a';
        } else if (c >= 'A' && c <= 'Z') {
            retorno[i] = ((c - 'A' + k) % 26) + 'A';
        } else {
            retorno[i] = c;
        }
    }

    retorno[tamanho] = '\0';
    return retorno;
}
