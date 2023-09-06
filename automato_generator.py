def parse_entries(alfabeto: str, estados: str, estados_finais: str) -> tuple[list[str], list[str], dict[str, str]]:
    if not alfabeto:
        alfabeto = []
    else:
        alfabeto = alfabeto.split()
    
    if not estados:
        estados = []
    else:
        estados = estados.split()

    if not estados_finais:
        estados_finais = {}
    else:
        estados_finais = estados_finais.split()
        estados_tokens = {}

        for estado_token in estados_finais:
            estado, token = estado_token.split(":")
            estados_tokens.update({estado: token})

    return alfabeto, estados, estados_tokens


def generate_matrix(alfabeto: list[str], estados: list[str]) -> list[tuple[str, ...]]:
    matrix = [['0'] * len(alfabeto) for _ in estados]

    print("Gerar matriz de transição")
    print("="*25)

    for i, estado in enumerate(estados):
        print(f"{estado}")
        for j, palavra in enumerate(alfabeto):
            matrix[i][j] = input(f"{palavra:>5}: ")
        print("="*25)
    
    return matrix


def generate_txt(alfabeto: list[str], estados: list[str], estados_finais: dict[str, str], transitions: list[tuple[str, ...]]) -> None:
    with open("automato_cpp.txt", "w") as file:
        alfbt = '", "'.join(alfabeto)
        file.write(f'const std::string alfabeto [] {{"{alfbt}"}};\n')
        
        stds = '", "'.join(estados)
        file.write(f'\nconst std::string estados [] {{"{stds}"}};\n')

        file.write("\nconst std::map<std::string, std::string> estados_finais {\n")
        for key, value in estados_finais.items():
            file.write(f'\t{{"{key}", "{value}"}},\n')
        file.write('};\n')

        file.write(f"\nconst std::string transicoes [][{len(alfabeto)}] {{\n")
        file.write(f"//{' '*8}")
        for palavra in alfabeto:
            file.write(f"{palavra:^10}")
        file.write("\n")

        qtd = len(alfabeto)
        for estado, transicoes in zip(estados, transitions):
            file.write(f'/*{estado:^5}*/{{')
            
            for i, transicao in enumerate(transicoes):
                if i == qtd - 1:
                    break
                
                transicao = f'"{transicao}",'
                file.write(f'{transicao:^10}')
            
            transicao = f'"{transicoes[qtd-1]}"'
            file.write(f'{transicao:^10}}},\n')

        file.write("};\n")


if __name__ == "__main__":
    print("Os valores devem ser fornecidos separados por um espaço em branco\n")
    alfabeto = input('Alfabeto: ')
    estados = input('Estados: ')
    estados_finais = input('Estados Finais (Nome do estado:Token)\n')

    alfabeto, estados, estados_finais = parse_entries(alfabeto, estados, estados_finais)
    
    transitions = generate_matrix(alfabeto, estados)

    generate_txt(alfabeto, estados, estados_finais, transitions)

