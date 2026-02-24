import sys


def analizar_lexico(texto):
    """funcion que realiza el analisis lexico del texto.

    parametros:
    texto: cadena de entrada que sera analizada caracter por caracter

    variables internas:
    i: indice entero que recorre la cadena
    n: longitud de la cadena
    tokens_encontrados: lista donde se almacenan los tokens detectados

    retorna:
    lista de tokens o None si se encuentra un caracter no valido
    """
    i = 0 
    n = len(texto)  
    tokens_encontrados = []  

    while i < n:  # recorrer mientras queden caracteres
        char = texto[i]  # caracter actual en la posicion i

        # si el caracter es espacio en blanco, avanzar
        if char.isspace():
            i += 1
            continue

        # detectar suma (+) o incremento (++)
        if char == '+':
            # si el siguiente caracter tambien es '+', es incremento
            if i + 1 < n and texto[i+1] == '+':
                tokens_encontrados.append("INCR")  # token de incremento
                i += 2  # saltar los dos signos ++
            else:
                tokens_encontrados.append("SUMA")  # token de suma simple
                i += 1  # avanzar un caracter
            continue

        # detectar identificadores que empiezan con mayuscula A-Z
        if 'A' <= char <= 'Z':
            i += 1  # consumir la letra inicial
            # mientras sigan minusculas o numeros, continuar consumiendo
            while i < n and (('a' <= texto[i] <= 'z') or ('0' <= texto[i] <= '9')):
                i += 1
            tokens_encontrados.append("ID")  # token identificador
            continue

        # si se alcanza un caracter no esperado, devolver error (None)
        return None

    return tokens_encontrados  # devolver la lista de tokens reconocidos


def main():
    if len(sys.argv) != 2:
        return

    try:
        with open(sys.argv[1], 'r') as archivo:
            for linea in archivo:
                linea = linea.strip()
                if not linea:
                    continue
                
                resultado = analizar_lexico(linea)
                
                if resultado is None:
                    print("NO ACEPTA")
                else:
                    for t in resultado:
                        print(t)
    except FileNotFoundError:
        print("error: archivo no encontrado")

if __name__ == "__main__":
    main()