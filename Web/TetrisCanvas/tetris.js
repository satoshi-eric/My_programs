/* ****************** peças e suas variações ****************** */

/* as matrizes representam o formato de cada peça do tabuleiro. cada peça é formada
* por um conjunto de 1s
*/

const A = [
    [
        [0, 0, 0, 0],
        [1, 1, 1, 1],
        [0, 0, 0, 0],
        [0, 0, 0, 0],
    ],
    [
        [0, 0, 1, 0],
        [0, 0, 1, 0],
        [0, 0, 1, 0],
        [0, 0, 1, 0],
    ],
    [
        [0, 0, 0, 0],
        [0, 0, 0, 0],
        [1, 1, 1, 1],
        [0, 0, 0, 0],
    ],
    [
        [0, 1, 0, 0],
        [0, 1, 0, 0],
        [0, 1, 0, 0],
        [0, 1, 0, 0],
    ]
];

const B = [
    [
        [1, 0, 0],
        [1, 1, 1],
        [0, 0, 0]
    ],
    [
        [0, 1, 1],
        [0, 1, 0],
        [0, 1, 0]
    ],
    [
        [0, 0, 0],
        [1, 1, 1],
        [0, 0, 1]
    ],
    [
        [0, 1, 0],
        [0, 1, 0],
        [1, 1, 0]
    ]
];

const C = [
    [
        [0, 0, 1],
        [1, 1, 1],
        [0, 0, 0]
    ],
    [
        [0, 1, 0],
        [0, 1, 0],
        [0, 1, 1]
    ],
    [
        [0, 0, 0],
        [1, 1, 1],
        [1, 0, 0]
    ],
    [
        [1, 1, 0],
        [0, 1, 0],
        [0, 1, 0]
    ]
];

const D = [
    [
        [0, 0, 0, 0],
        [0, 1, 1, 0],
        [0, 1, 1, 0],
        [0, 0, 0, 0],
    ]
];

const E = [
    [
        [1, 0, 1],
        [1, 1, 1],
        [0, 0, 0]
    ],
    [
        [0, 1, 1],
        [0, 1, 0],
        [0, 1, 1]
    ],
    [
        [0, 0, 0],
        [1, 1, 1],
        [1, 0, 1]
    ],
    [
        [1, 1, 0],
        [0, 1, 0],
        [1, 1, 0]
    ]
];

const F = [
    [
        [0, 1, 0],
        [1, 1, 1],
        [0, 0, 0]
    ],
    [
        [0, 1, 0],
        [0, 1, 1],
        [0, 1, 0]
    ],
    [
        [0, 0, 0],
        [1, 1, 1],
        [0, 1, 0]
    ],
    [
        [0, 1, 0],
        [1, 1, 0],
        [0, 1, 0]
    ]
];

const G = [
    [
        [0, 0, 0],
        [0, 1, 0],
        [0, 0, 0]
    ],
];


/* **************** código **************** */

const cvs = document.getElementById("tetris-canvas");  //constante cvs pega o id de canvas no doc hmtl
const ctx = cvs.getContext("2d");  //retorna um contexto de desenho para canvas
const pontosJogador = document.getElementById("pontuacao");

const linha = 20;
const coluna = COLUMN = 10;
const tamQuadrado = squareSize = 20;
const disponivel = "#F3F3F3"; // cor de fundo dos quadrados disponíveis
/* ^foram utilizadas constantes para facilitarem o uso dos valores na extensão do código. a quantidade de linhas,
*colunas e o tamanho do quadrado devem ficar dentro de suas respectivas constantes para facilitar a implementação
*dos dois tipos de tabuleiros
*/

function desenharQuadrado(x,y,cor) {
    ctx.fillStyle = cor;
    ctx.fillRect(x*tamQuadrado,y*tamQuadrado,tamQuadrado,tamQuadrado);
    /* ^para que o quadrado seja desenhado, serão passados os parametros de cor, coordenadas x e y e as dimensões
    * do quadrado (width & heigth) -- https://www.w3schools.com/tags/canvas_fillstyle.asp
    */

    ctx.strokeStyle = "#C4C4C4";
    ctx.strokeRect(x*tamQuadrado,y*tamQuadrado,tamQuadrado,tamQuadrado);
    // ^propriedades de borda para cada elemento em canvas -- https://www.w3schools.com/tags/canvas_strokerect.asp
}

let tabuleiro = []; // cria um novo tabuleiro -- no caso, uma array

for( r = 0; r <linha; r++) {
    tabuleiro[r] = []; //cria as linhas (ou "rows") do tabuleiro
    for(c = 0; c < coluna; c++){
        tabuleiro[r][c] = disponivel; //atribuirá a cor branca ("disponível") a todos os quadrados do novo tabuleiro
    }
}

function desenharTabuleiro() {
    for( r = 0; r <linha; r++){
        for(c = 0; c < coluna; c++){
            desenharQuadrado(c,r,tabuleiro[r][c]);
        }
    }
}
/* ^a função desenharTabuleiro será responsável por desenhar este tabuleiro recém criado na tela, exibindo uma série
*de quadrados em branco (cor de inicialização)
*/

desenharTabuleiro(); // chama a função construtora do tabuleiro

const TETROMINOS = [ //os tetrominos e suas respectivas cores
    [A,"#FE938C"],
    [B,"#B388EB"],
    [C,"#FFF282"],
    [D,"#90DDF0"],
    [E, "#F0B890"],
    [F,"#7BF1A8"],
    [G,"#FE4BC1"]
];

function pecaSortida() {
    let r = randomN = Math.floor(Math.random() * TETROMINOS.length) // 0 até 6
    return new Peca( TETROMINOS[r][0],TETROMINOS[r][1]);
}
/* ^a função peçaSprtida será responsavel por retornar a nova peça que será exibida. todas as peças têm a mesma
* probabilidade de aparecerem e são geradas randomicamente
*/

let p = pecaSortida(); // invoca a função peçaSortida para atribui à "p" a próxima peça a cair

function Peca(tetromino,cor){
    this.tetromino = tetromino;
    this.cor = cor;

    this.posicaoTetromino = 0; // partindo do zero, começamos da primeira orientação disponível de cada peça
    this.tetrominoAtivo = this.tetromino[this.posicaoTetromino]; // é a peça com a qual estaremos jogando

    this.x = 3; // deixa a peça posicionada na metade do tabuleiro
    this.y = -2;  // deixa a peça posicionada acima do tabuleiro para que só seja vista assim que começa a cair
}
/* ^com a função Peça, conseguimos ter controle sobre os tetrominos */

Peca.prototype.fill = function(cor) {
    for( r = 0; r < this.tetrominoAtivo.length; r++) {
        for(c = 0; c < this.tetrominoAtivo.length; c++) {
            if( this.tetrominoAtivo[r][c]){
                desenharQuadrado(this.x + c,this.y + r, cor); // preencheremos apenas os quadrados ocupados seguindo as coordenadas
            }
        }
    }
}
/* ^a função "fill" será responsável por preencher os quadrados que queremos que sejam preenchidos para que seja
* formado o formato dos tetrominos
*/

Peca.prototype.exibir = function() {
    this.fill(this.cor);
}
/* ^a função "exibir" irá preencher o quadrado com um atributo de cor */

Peca.prototype.remover = function() {
    this.fill(disponivel);
}
/* ^para que tenhamos movimento e progressão no movimento do tetromino, devemos apagar sua posição original antes de
*podermos recalcular sua nova posição e o exibir novamente na tela
*/

Peca.prototype.abaixar = function() {
    if(!this.temColisao(0,1,this.tetrominoAtivo)){ //aqui, verificaremos se a peça tem colisão com algo em baixo
        this.remover();
        this.y++;
        this.exibir(); // caso não tenha, podemos atualizar sua posição para y+1
    }
    else {
        this.manter();
        p = pecaSortida(); //caso tenha uma peça abaixo, mantemos a peça no lugar onde ela se encontra e solicitanos uma nova peça
    }

}

Peca.prototype.moverDireita = function(){
    if(!this.temColisao(1,0,this.tetrominoAtivo)){
        this.remover();
        this.x++;
        this.exibir();
    }
}
/* ^a função moverDireita irá movimentar a peça para a direita do tabuleiro quando for chamada, caso a peça atual
*não tenha colisão com outra peça ou limite do canvas
*/

Peca.prototype.moverEsquerda = function(){
    if(!this.temColisao(-1,0,this.tetrominoAtivo)){
        this.remover();
        this.x--;
        this.exibir();
    }
}
/* ^a função moverEsquerda irá movimentar a peça para a esquerda do tabuleiro quando for chamada, caso a peça atual
*não tenha colisão com outra peça ou limite do canvas
*/

Peca.prototype.rotacionar = function(){
    let proximaOrientacao = this.tetromino[(this.posicaoTetromino + 1)%this.tetromino.length];
    /* ^(posiçãoTetromino + 1)%tetromino.length vai resolver o problema de não conseguir acompanhar a mudança de
    * orientação da peça. fazemos isso para conseguirmos o seguinte: (0+1)%4 => 1, onde 0 = pos. inicial +1 % 4 => 1 (proxima
    * orientação da peça
    */
    let realocar = 0;

    if(this.temColisao(0,0,proximaOrientacao)){ // assim iremos saber onde temos colisão (0, 0 é usado pq a peça rotaciona em seu proprio eixo)
        if(this.x > coluna/2){ // todo : não entendi aqui, oh!
            realocar = -1; //como estamos fazendo contato com a coluna direita, devemos relocalizar a peça para a esquerda
        }else{
            realocar = 1; // se não, estamos fazendo contato com a coluna esquerda e devemos relocalizar a peça para a direita
        }
    }

    if(!this.temColisao(realocar,0,proximaOrientacao)){
        this.remover();
        this.x += realocar;
        this.posicaoTetromino = (this.posicaoTetromino + 1)%this.tetromino.length; // (0+1)%4 => 1
        this.tetrominoAtivo = this.tetromino[this.posicaoTetromino];
        this.exibir();
        /* ^caso a rotação não seja um problema, a peça será realocada e exibida na tela normalmente*/
    }
}
/* ^a função rotação alem de permitir que as pecinhas girem sobre seu proprio eixo, precisa analisar também se a
* rotação da peça fará com que ela tenha algum contato lateral
*/

let pontuacao = 0; // inicializa a pontuação do jogador em 0 pts.

Peca.prototype.manter = function() {
    for( r = 0; r < this.tetrominoAtivo.length; r++) {
        for(c = 0; c < this.tetrominoAtivo.length; c++) {
            if( !this.tetrominoAtivo[r][c]){
                continue; // estaremos pulando os quadrados que estiverem vazios
            }
            if(this.y + r < 0) { // se a peça for salva numa posição acima de y = 0, então game over -- acabaram-se as linhas
                alert("Game Over");
                gameOver = true;
                break;
            }
            tabuleiro[this.y+r][this.x+c] = this.cor; // mas, caso contrário, salvaremos a peça em sua posição
        }
    }

    for(r = 0; r < linha; r++){
        let linhaEstaCheia = true;
        for( c = 0; c < coluna; c++){
            linhaEstaCheia = linhaEstaCheia && (tabuleiro[r][c] !== disponivel);
        }
        /* ^no evento da linha estar cheia, o programa irá resetar a linha, ou seja, atribuirá "disponível"
        * aos quadrados que a compõem -- voltarão à cor de fundo normal
        */

        if(linhaEstaCheia){
            for( y = r; y > 1; y--){
                for( c = 0; c < coluna; c++){
                    tabuleiro[y][c] = tabuleiro[y-1][c];
                }
            }
            /* ^caso a linha esteja cheia, o programa vai descer o tabuleiro -- novo y = y-1 */

            for( c = 0; c < coluna; c++){
                tabuleiro[0][c] = disponivel; // a linha [0] não tem nenhuma outra linha acima dela
            }

            pontuacao += 10; // usuário removeu uma linha, então sua pontuação aumenta em 10 pts.
        }
    }
    desenharTabuleiro(); // atualiza o tabuleiro

    pontosJogador.innerHTML = pontuacao; // atualiza a pontuação atual do jogador
}
/* ^a função manter será resposnável por salvar a peça em sua posição de parada */

Peca.prototype.temColisao = function(x,y,peca) {
    for( r = 0; r < peca.length; r++) {
        for(c = 0; c < peca.length; c++) {
            if(!peca[r][c]) { // verifica se o campo está livre. se estiver, nada será feito
                continue;
            }
            let xAtualizado = this.x + c + x;
            let yAtualizado = this.y + r + y; // armazena as coordenadas atualizadas da peça após a movimentação

            if(yAtualizado < 0) {
                continue;
            } // yAtualizado deve ser maior que y, se não, isso indica que acabaram as linhas

            if(xAtualizado < 0 || xAtualizado >= coluna || yAtualizado >= linha){
                return true;
            }
            /*^nesta parte, estaremos analizando se a peça não está ultrapassando a margem da canvas pela direita
            * (ou seja, x < 0), pela esquerda (ou seja, x > coluna) e/ou por baixo (ou seja, y > linha)
            */

            if( tabuleiro[yAtualizado][xAtualizado] !== disponivel){
                return true; // checa se já não há uma peça no determinado lugar. caso não, é retornado o vcalor de verdadeiro -- lugar disponivel!!
            }
        }
    }
    return false;
}
/* ^a função temColisão vai analisar se, após a movimentação da pecinha, há a colisão dela com outra pecinha ou
* com as margens do tabuleiro */

document.addEventListener("keydown",CONTROL);

function CONTROL(event){
    if(event.keyCode === 37){
        p.moverEsquerda();
        retomadaDescida = Date.now();
    }else if(event.keyCode === 38){
        p.rotacionar();
        retomadaDescida = Date.now();
    }else if(event.keyCode === 39){
        p.moverDireita();
        retomadaDescida = Date.now();
    }else if(event.keyCode === 40){
        p.abaixar();
    }
}
/* ^as funções de controle acima esperam o evento de clique do teclado. assim que as setas forem clicadas,
*cada uma realizará uma função. a seta para cima (de keycode 38) irá rotacionar a peça; a seta para baixo (de
*key code 40) invocará novamente a função de abaixar, aumentando a velocidade de descida da peça; a seta para a direita
*(de key code 39) irá movimentar a peça para a direita e a tecla da esquerda (de key code 37) irá movimentar a
*peça para a esquerda. após cada função ser realizada, é importante que novamente o tempo de descida seja atualizado,
*pois se não o timing se vai completamente por agua abaixo
*/

let retomadaDescida = Date.now(); // inicia a descida no momento de agora
let gameOver = false; // começa em false pq se não.. bom.. né, acabou *O JOGO*
function descidaPeca(){
    let now = Date.now();
    let delta = now - retomadaDescida;
    if(delta > 1000){ // executa a função após 1000ms ou 1s
        p.abaixar(); // recalcula altura y da pecinha
        retomadaDescida = Date.now(); // atualiza timing
    }
    if( !gameOver){
        requestAnimationFrame(descidaPeca); // informa ao browser que haverá uma animação -- https://developer.mozilla.org/en-US/docs/Web/API/window/requestAnimationFrame
    }
}
/* ^a função "descidaPeça" permite que a peça comece a descer desde o topo, onde a peça fica originalmente
* escondida (x = -2+ até onde for possível. é feito também o controle da velocidade dessa decida, informando a
* retomadaDescida o momento atual e depois contando 10000ms (ou 1 segundo) até que a peça desça mais uma linha.
* É importante que esse controle do tempo seja atualizado ao final do ciclo para que a descida da peça não
* saia de ordem. é importante também verificar se não foi atingida a condição de game over, ou seja, o jogador
* subiu todas as linhas
*/

descidaPeca(); // chama a função de descida da peça automaticamente quando o código é executado
