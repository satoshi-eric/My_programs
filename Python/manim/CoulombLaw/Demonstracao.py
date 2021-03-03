import manim

class Carga(manim.VGroup):
    def __init__(self, *vmobjects, **kwargs):
        super().__init__(*vmobjects, **kwargs)
        circulo = manim.Circle()
        ponto = manim.Dot()
        self.add(circulo, ponto)

class Cena(manim.Scene):
    def construct(self):
        self.play(manim.Write(Carga()))