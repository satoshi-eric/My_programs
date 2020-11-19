document.addEventListener('DOMContentLoaded', () => {

    const pincel = {
        ativo: false,
        movendo: false,
        pos: {x: 0, y:0},
        posAnterior: null,

    }

    const tela = document.querySelector('#tetris')
    const contexto = tela.getContext('2d')

    tela.width = 1280
    tela.height = 720

    contexto.lineWidth = 10
    contexto.strokeStyle = 'pink'

    const desenharLinha = (linha) => {

        contexto.beginPath()
        contexto.moveTo(linha.posAnterior.x, linha.posAnterior.y)
        contexto.lineTo(linha.pos.x, linha.pos.y)
        contexto.stroke()
    }

    tela.onmousedown = (evento) => {
        pincel.ativo = true
    }

    tela.onmouseup = (evento) => {
        pincel.ativo = false
    }

    tela.onmousemove = (evento) => {
        pincel.pos.x = evento.clientX
        pincel.pos.y = evento.clientY
        pincel.movendo = true
    }

    const ciclo = () => {
        if (pincel.ativo && pincel.movendo) {
            desenharLinha(
                {
                    pos: pincel.pos, 
                    posAnterior: pincel.posAnterior
                }
            )
            pincel.movendo = false
        }
        pincel.posAnterior = {x: pincel.pos.x, y: pincel.pos.y}

        setTimeout(ciclo, 1)
    }

    ciclo()

})