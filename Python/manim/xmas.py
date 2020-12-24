from manimlib.imports import *
import random

class XmasScene(Scene):
    def construct(self):
        tree = VGroup()
        for i in range(3):
            tree.add(Triangle(fill_color="#03fc07").scale(0.3*i).shift(-0.3*i))
        self.play(FadeIn(tree))