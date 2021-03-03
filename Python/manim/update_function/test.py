from manim import *

class Test(Scene):
    def construct(self):
        square = Square()
        dot = Dot()
        rate = 0.25
        self.time_offset = 0

        def get_line():
            return Line(start=ORIGIN, end=dot)

        # dt = 1/frame_rate
        def move_dot(dot: Dot, dt):
            self.time_offset += rate * dt
            dot.move_to(
                square.point_from_proportion(self.time_offset)
            )

        dot.add_updater(move_dot)
        draw_line = always_redraw(get_line)
        self.add(dot, square, draw_line)


def sum(x, y):
    return x + y

print(sum(x=10, y=20))