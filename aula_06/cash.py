# Seu programa deve perguntar ao usuário quanto dinheiro é devido e em seguida 
# imprime o número mínimo de moedas com as quais essa troca pode ser feita.
# Onde a gaveta desse caixa estejam moedas de 25, 10, 5 e 1 centavo(s).

def main():
    menu()

def menu():
    valor = 0
    retorno = 0
    print("-------------- Bem vindo -------------")
    valor = dadoUsuario()
    retorno = calcular(valor)
    imprimeResposta(retorno)

def dadoUsuario():
    return  float(input("Digite o valor: "))

def calcular(valor):
    teste = valor
    vetor = [0,0,0,0]

    while teste >= 0:
        teste = teste - 0.25
        teste = round(teste, 2)
        if(teste < 0):
           teste = teste + 0.25
           teste = round(teste, 2)
           break
        vetor[0] += 1

    while teste >= 0:
        teste = teste - 0.10
        teste = round(teste, 2)
        if(teste < 0):
           teste = teste + 0.10
           teste = round(teste, 2)
           break
        vetor[1] += 1

    while teste >= 0:
        teste = teste - 0.05
        teste = round(teste, 2)
        if(teste < 0):
           teste = teste + 0.05
           teste = round(teste, 2)
           break
        vetor[2] += 1

    while teste >= 0:
        teste = teste - 0.01
        teste = round(teste, 2)
        if(teste < 0):
           teste = teste + 0.01
           teste = round(teste, 2)
           break
        vetor[3] += 1

    return vetor

def imprimeResposta(resposta):
    print("--------- Retorno ---------")
    print("Moedas de 25: ", resposta[0])
    print("Moedas de 10: ", resposta[1])
    print("Moedas de 5: ", resposta[2])
    print("Moedas de 1: ", resposta[3])

if __name__ == "__main__":
    main()

