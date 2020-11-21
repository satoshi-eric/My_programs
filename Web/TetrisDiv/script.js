let tabuleiro = document.querySelector('.board')

const largura = 10
const altura = 20

// Criando divs que serão representarão o tabuleiro
for (let i=0; i<largura*altura; i++) {
    let div = document.createElement('div')
    tabuleiro.appendChild(div)
}

// Criando um vetor com todas as divs dentro da div board. Esse método está aqui para que possamos trabalhar com as divs. Apenas o querySelector não é o suficiente
let divs = Array.from(document.querySelectorAll('.board > div'))

const telaPontuacao = document.querySelector('#score')

// Formas dos tetrominos
const tetrominoL = [
    [1, 1+largura, 1+2*largura, 2+2*largura],
    [largura, largura+1, largura+2, largura*2],
    [0, 1, largura, largura*2],
    [2, largura, largura+1, largura+2]
]

const terominoJ = [
    [1, largura+1, 2*largura+1, 2*largura],
    [largura, largura+1, largura+2, 2*largura],
    [1, 2, largura+1, 2*largura+1],
    [largura, largura+1, largura+2, 2*largura+2]
]

const tetrominoO = [
    [0, 1, largura, largura+1],
    [0, 1, largura, largura+1],
    [0, 1, largura, largura+1],
    [0, 1, largura, largura+1]
]

const tetrominoI = [
    [1, largura+1, 2*largura+1, 3*largura+1],
    [largura, largura+1, largura+2, largura+3],
    [1, largura+1, 2*largura+1, 3*largura+1],
    [largura, largura+1, largura+2, largura+3]
]

const tetrominoT = [
    [0, 1, 2, largura+1],
    [1, largura, largura+1, 2*largura+1],
    [1, largura, largura+1, largura+2],
    [1, largura+1, largura+2, 2*largura+1],
]

const tetrominoU = [
    [0, 2, largura, largura+1, largura+2],
    [1, 2, largura+1, 2*largura+1, 2*largura+2],
    [largura, largura+1, largura+2, 2*largura, 2*largura+2],
    [0, 1, largura+1, 2*largura, 2*largura+1]
]

// Os tetrominos devem ser acessados da seguinte maneira.
// tetromino[t][r].forEach() onde
// t: é o tipo do tetromino
// r: é a rotação atual do tetromino
// forEach serve para iterar pelo tetromino e desenhá-lo ou fazer qualquer outra operação
const tetrominos = [tetrominoL, terominoJ, tetrominoO, tetrominoI, tetrominoT, tetrominoU]

let rotacaoAtual = 0 // Variável para indicar qual a rotação do tetromino O tetromino é um array de arrays, então, para acessar cada um desses arrays que representam cada posição dos tetrominos, é necessário ter uma variável para controlar o index atual desses vetor.
let posAtual = 4 // variável que irá controlar a posição do tetromino. Se somarmos ou subtraírmos 1 dessa variável, ela irá se mover para a esquerda ou para a direita. Se somarmos ou subtraírmos a largura dessa variável, o tetromino irá subir ou descer
let indexAleatorio = Math.floor(Math.random() * tetrominos.length) // Precisamos inicializar diferentes tetrominos por vez
let tetrominoAtual = tetrominos[indexAleatorio][rotacaoAtual] // seleciona qual será o primeiro tetromino a cair.

// Função para desenhar o tetromino
function desenhar() {
    tetrominoAtual.forEach(index => {
        // Precisamos adicionar a variável posXtual para podermos mover o tetromino. Se somarmos ou subtraírmos 1, o tetromino irá se mover para a direita ou para a esquerda. Se adicionarmos ou subtraírmos a largura, moveremos o tetromino para cima ou para baixo
        divs[posAtual + index].classList.add('tetromino')
    })
}

// Função para apagar o tetromino. Precisamos dessa função para que possamos atualizar o tetromino toda vez que ele se mover. Se não tiveros essa função, mesmo que o tetromino deça, uma cópia dele ainda estará em cima desse tetromino
function apagar() {
    tetrominoAtual.forEach(index => {
        divs[posAtual + index].classList.remove('tetromino')
    })
}

desenhar()
// Atualizando a posição do tetromino a cada 1 segundo
let temporizador = setInterval(descer, 100)

function descer() {
    parar()
    apagar()
    posAtual += largura
    desenhar()
}

// Função para parar o tetromino quando ele estiver no fundo do tabuleiro, ou quando houver um tetromino embaixo do tetromino atual
function parar() {
    // verificar se o tetromino atual está no fundo do tabuleiro
    // Verificar se há um tetromino embaixo do tetromino atual
    //  largura representa a próxima linha a ser verificada
    // divs com a classe parado representam os tetrominos que não podem mais se mover
    if ((tetrominoAtual[3] + posAtual >= largura * (altura - 1)) || tetrominoAtual.some(index => {divs[index + posAtual + largura]})) {
        // se a resposta for sim para as duas verificações, criaremos um novo tetromino que irá cair da próxima vez
        // precisamos adicionar o estado parado para que o joga pare de somar à posição atual
        tetrominoAtual.forEach(index => {
            divs[posAtual + index].classList.add('parado')
        })

        indexAleatorio = Math.floor(Math.random() * tetrominos.length)
        tetrominoAtual = tetrominos[indexAleatorio][rotacaoAtual]
        posAtual = 4
        desenhar()

    } 
    
    
}








