# Height: 4
#    #
#   ##
#  ###
# ####
# Execute seu programa como python mario.py e aguarde uma solicitação de entrada. 
# - Digite -1 e pressione enter. Seu programa deve rejeitar esta entrada como inválida, 
# solicitando novamente que o usuário digite outro número.
# - Digite 0 e pressione enter. Seu programa deve rejeitar esta entrada como inválida, 
# solicitando novamente que o usuário digite outro número.
# - Digite 1 e pressione enter. Seu programa deve gerar a saída abaixo. 
# Certifique-se de que a pirâmide esteja alinhada com o canto inferior esquerdo do seu terminal e 
# que não haja espaços extras no final de cada linha.

def main():
    resultado = ""
    tamanho = dadoUsuario()
    for i in range(tamanho):
        resultado = qtdJogoVelha(i+1)
    print(resultado)

def menu():
     print("-------------- Bem vindo -------------")

def dadoUsuario():
    tamanho = 0
    while tamanho == 0:
        menu()
        tamanho = int(input("Digite o tamanho da escada: "))
        if(tamanho <= 0):
            print("Resultado inválido, Digite novamente.")
            tamanho = 0
    return tamanho

def espaco(tamanho, linha):
    # linha começa em 1 até tamanho
    espacos = tamanho - linha
    return " " * espacos

def qtdJogoVelha(tamanho):
    resultado = ""
    for i in range(1, tamanho + 1):
        texto = "#" * i
        resultado += espaco(tamanho, i) + texto + " " + texto + "\n"
    return resultado


if __name__ == "__main__":
    main()
