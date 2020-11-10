""" Programa que renomea todos os arquivos de um diretório """

import os

""" Regra de nomeação """
# No caso, eu quis retirar as 3 primeiras letras de cada arquivo e diretório 
# Retorna o 'nome_arquivo' sem as 3 primeiras letras
def retirar_3_primeiras_letras(nome_arquivo):
    i = 0
    substituir_nome = ''
    # string com as 3 primeiras letras de nome_arquivo
    for letra in nome_arquivo:
        if i == 3:
            break
        substituir_nome += letra
        i += 1
    # substitui as 3 primeiras letras por uma string vazia
    nome_res = nome_arquivo.replace(substituir_nome, "")
    return nome_res

# pasta que se deseja modificar os arquivos dentro
pasta = 'Node'

# lista com o nome de cada arquivos dentro do diretório 'pasta'
arquivos = os.listdir('./{}'.format(pasta))

""" Módulo os renomeia todos os arquivos dentro do diretório usando o método rename """
for i in range(len(os.listdir('./{}'.format(pasta)))):
    nome_atual = arquivos[i]
    novo_nome = retirar_3_primeiras_letras(nome_atual)

    os.rename('./{}/'.format(pasta) +  nome_atual, './{}/'.format(pasta) + novo_nome)