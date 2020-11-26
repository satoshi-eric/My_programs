from manimlib.imports import *

class Cena(Scene):
    def construct(self):
        text = TextMobject("texto")
        self.play(FadeIn(text))