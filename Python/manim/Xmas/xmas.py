from manimlib.imports import *
import random

class XmasScene(Scene):
    def construct(self):
        
        tops = VGroup()

        for i in range(1, 6):
            tops.add(
                Triangle(
                    fill_color="#15db0b", 
                    fill_opacity=1, 
                    color="#15db0b"
                ).scale(i).shift(1.4*i*DOWN)
            )


        tops.shift(1.5*TOP)
        tops.scale(0.4)

        trunk = Rectangle(width=1, height=2, fill_color="#963a05", fill_opacity=1, color="#963a05")
        trunk.next_to(tops, DOWN, 0.04)

        snow = Rectangle(color=WHITE, fil_color=WHITE, fill_opacity=1, width=20, height=3).next_to(trunk, DOWN, -1)

        self.play(FadeIn(snow))
        self.play(FadeIn(tops), FadeIn(trunk))

        balls = []
        colors = ["#ffea00", "#008218", "#ff0800", "#0048ff", "#00b3ff", "#000dff", "#8600b3"]
        
        for i in range(12):
            color = colors[random.randint(0, len(colors) -1)]
            balls.append(
                Circle(
                    fill_color=color,
                    fill_opacity=1, 
                    color=color
                    )
                        .move_to(
                            (random.randrange(0, 10) * 0.04)*TOP + (random.randint(-10, 10) * 0.06)*RIGHT
                        )
                        .scale(0.1)
            )
            balls.append(
                Circle(
                    fill_color=color,
                    fill_opacity=1, 
                    color=color
                    )
                        .move_to(
                            (random.randrange(0, 10) * 0.15)*DOWN + (random.randint(-10, 10) * 0.1)*LEFT
                        )
                        .scale(0.1)
            )

        for ball in balls:
            self.play(FadeIn(ball))