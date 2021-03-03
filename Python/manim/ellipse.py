import manim
import numpy as np

class Ellipse(manim.Ellipse):
    """
        Classe para os dados da elipse.
        Possui as seguintes propriedades:\\
        width, height, a, b, c, f1 e f2
    """
    def __init__(self, width: float = 5, height: float = 4) -> None:
        """
            Construtor para a classe EllipseFigure.\\
            Herda da Classe Ellipse da bilioteca Manim.
        """
        self.config_properties(width = width, height = height)

    def config_properties(self, width: float = 5, height: float = 4) -> None:
        """
            Pega a largura e a altura e calcula as\\ 
            seguintes propriedades: a, b, c, f1 e f2
        """
        self.width = width
        self.height = height
        
        if width > height:
            self.a_size = width/2
            self.b_size = height/2
            self.c_size = np.sqrt(self.a_size**2 - self.b_size**2)
            focus1_coordinate = (-self.c_size, 0, 0)
            focus2_coordinate = (self.c_size, 0, 0)
            self.focuses_coords = [focus1_coordinate, focus2_coordinate]
        else:
            self.a_size = height/2
            self.b_size = width/2
            self.c_size = np.sqrt(self.a**2 - self.b**2)
            focus1_coordinate = (0, -self.c, 0)
            focus2_coordinate = (0, self.c, 0)
            self.focuses_coords = [focus1_coordinate, focus2_coordinate]
        
        super().__init__(width=width, height=height)        

class CenaElipse(manim.Scene):
    def construct(self):
        self.init_figs()
        self.set_axis_and_focus()
        self.draw_ellipse()

    def init_figs(self):
        """
            Inicia as figuras da cena sem animá-las ou adicioná-las à cena
        """
        # ----------------- Configuração da elipse ----------------- #
        self.ellipse = Ellipse()

        # ----------------- Configuração dos eixos ----------------- # 
        a = self.ellipse.a_size
        b = self.ellipse.b_size

        start_x_axis_coord = manim.LEFT*(a + 1)
        end_x_axis_coord = manim.RIGHT*(a + 1)
        start_y_axis_coord = manim.DOWN*(b + 1)
        end_y_axis_coord = manim.UP*(b + 1)

        x_axis = manim.Line(
            start = start_x_axis_coord, 
            end = end_x_axis_coord
        )
        y_axis = manim.Line(
            start = start_y_axis_coord, 
            end = end_y_axis_coord
        )

        self.axes_fig = manim.VGroup(x_axis, y_axis)

        # ----------------- Confguração dos focos ----------------- #
        focus_coords = self.ellipse.focuses_coords
        focus_coord1, focus_coord2 = focus_coords

        focus1_fig = manim.Dot(point = focus_coord1)
        focus2_fig = manim.Dot(point = focus_coord2)

        self.focuses = manim.VGroup(focus1_fig, focus2_fig)

        # ----------------- Configuração do lápis ----------------- #
        start_pencil_proportion = 0
        start_pencil_coord = self.ellipse.point_from_proportion(start_pencil_proportion)
        self.pencil = manim.Dot(point=start_pencil_coord)

        # ----------------- Configuração das linhas ----------------- #
        self.line1 = manim.Line(start = focus_coord1, end = start_pencil_coord)
        self.line2 = manim.Line(start = focus_coord2, end = start_pencil_coord)

    def set_axis_and_focus(self):
        """
            Desenha os eixos e os focos da elipse
        """
        # ----------------- Eixos e focos ----------------- #
        self.play(manim.Write(self.axes_fig))
        self.play(manim.Write(self.focuses))
    
    def draw_ellipse(self):
        """
            Desenha a ellipse e a trajetória do ponto 
        """
        move_pencil_animation_time = 10
        animation_time_rate = 1/move_pencil_animation_time
        self.pencil_position = 0
        self.raw_ellipse = manim.VGroup()
        self.previous_position = [0, 0, 0]

        def pencil_draw_ellipse(pencil: manim.Dot, dt):
            """
                Função para mover o ponto enquanto desenha a elipse
            """
            self.pencil_position += (animation_time_rate * dt)
            pencil_coords = self.ellipse.point_from_proportion(alpha = self.pencil_position % 1)
            self.raw_ellipse.add(manim.Line(start = self.previous_position, end = pencil_coords))
            self.previous_position = pencil_coords
            self.add(self.raw_ellipse)
            pencil.move_to(point_or_mobject = pencil_coords)        

        def draw_line1():
            """
                Desenha a reta do foco 1 ao ponto da elipse
            """
            focus1, focus2 = self.ellipse.focuses_coords
            line1 = manim.Line(
                start = focus1, 
                end = self.pencil.get_center()
            )
            return line1

        def draw_line2():
            """
                Desenha a reta do foco 2 ao ponto da elipse
            """
            focus1, focus2 = self.ellipse.focuses_coords
            line2 = manim.Line(
                start = focus2, 
                end = self.pencil.get_center()
            )
            return line2

        self.play(manim.Write(self.pencil))

        self.wait(duration = 1)

        # self.play(manim.Write(self.ellipse), run_time = 2)
        self.pencil.add_updater(pencil_draw_ellipse)
        
        line_redraw1 = manim.always_redraw(draw_line1)
        line_redraw2 = manim.always_redraw(draw_line2)
        
        self.add(self.pencil, line_redraw1, line_redraw2)

        fps = self.camera.frame_rate
        fps_offset = 0

        if fps < 60:
            fps_offset = 0.05
        else:
            fps_offset = 0.01

        self.wait(duration = move_pencil_animation_time + fps_offset)
        self.pencil.remove_updater(pencil_draw_ellipse)

        self.wait(duration = 1)