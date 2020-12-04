from manimlib.imports import *

class Cene(Scene):
    def construct(self):
        text = TextMobject("Hello")
        self.play(FadeIn(text))