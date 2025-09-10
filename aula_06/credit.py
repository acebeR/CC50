def verificar_luhn(numero_cartao):
    total = 0
    digitos_reverso = numero_cartao[::-1]

    for i in range(len(digitos_reverso)):
        digito = int(digitos_reverso[i])
        # Dobra os dígitos nas posições ímpares (índice 1, 3, 5, ...)
        if i % 2 == 1:
            digito *= 2
            if digito > 9:
                digito -= 9
        total += digito

    return total % 10 == 0

def tipo_cartao(numero_cartao):
    tamanho = len(numero_cartao)
    dois_primeiros = int(numero_cartao[:2])
    primeiro = int(numero_cartao[0])

    if tamanho == 15 and (dois_primeiros == 34 or dois_primeiros == 37):
        return "AMEX"
    elif tamanho == 16 and 51 <= dois_primeiros <= 55:
        return "MASTERCARD"
    elif (tamanho == 13 or tamanho == 16) and primeiro == 4:
        return "VISA"
    else:
        return "INVALID"

def principal():
    numero_cartao = input("Número: ")

    if not numero_cartao.isdigit():
        print("INVALID")
        return

    if verificar_luhn(numero_cartao):
        print(tipo_cartao(numero_cartao))
    else:
        print("INVALID")

if __name__ == "__main__":
    principal()
