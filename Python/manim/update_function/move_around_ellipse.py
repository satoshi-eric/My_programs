from manim import *

class MoveAroundEllipse(Scene):
    def construct(self):
        circle = Ellipse()
        dot = Dot()
        rate = 0.25
        self.t_offset = 0

        # dt = 1/frame_rate
        def move_dot(dot: Dot, dt):
            self.t_offset += dt * rate
            dot.move_to(point_or_mobject=circle.point_from_proportion(self.t_offset % 1))

        def get_line_to_circle1():
            line = Line(LEFT, dot.get_center(), color=BLUE)
            self.line_length = line.get_length()
            return line

        def get_line_to_circle2():
            line = Line(RIGHT, dot.get_center(), color=BLUE)
            self.line_length = line.get_length()
            return line

        def get_text_line_length1():
            line_length = round(self.line_length, 2)
            return TexMobject(line_length).move_to(3*RIGHT + 3*UP)

        def get_text_line_length2():
            line_length = round(self.line_length, 2)
            return TexMobject(line_length).move_to(3*RIGHT + 2*UP)

        self.add(circle, dot)
        dot.add_updater(move_dot)

        origin_to_elipse_line1 = always_redraw(get_line_to_circle1)
        text_line_length1 = always_redraw(get_text_line_length1)
        origin_to_elipse_line2 = always_redraw(get_line_to_circle2)
        text_line_length2 = always_redraw(get_text_line_length2)

        self.add(dot, origin_to_elipse_line1, text_line_length1, origin_to_elipse_line2, text_line_length2)
        self.wait(10)
        dot.remove_updater(move_dot)