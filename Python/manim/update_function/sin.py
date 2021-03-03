from manim import *

class SineCurveUnitCircle(Scene):
    # contributed by heejin_park, https://infograph.tistory.com/230
    def construct(self):
        self.show_axis()
        self.show_circle()
        self.move_dot_and_draw_curve()
        self.wait()

    # Mostra os eixos horizontal e vertical
    def show_axis(self):
        # Coordenadas iniciais dos eixos
        x_start = np.array([-6,0,0])
        x_end = np.array([6,0,0])

        # Coordenadas finais dos eixos
        y_start = np.array([-4,-2,0])
        y_end = np.array([-4,2,0])

        # Criando as linhas com as coordenadas criadas
        x_axis = Line(x_start, x_end)
        y_axis = Line(y_start, y_end)

        # Adicionando as linhas à cena
        self.add(x_axis, y_axis)
        self.add_x_labels()


        self.origin_point = np.array([-4,0,0]) # Definindo ponto de origem onde na cena
        self.curve_start = np.array([-3,0,0]) # Definindo o ponto inicial pelo qual o ponto irá se mover pelo círculo

    # Mostra pi, 2pi, 3pi e 4pi no eixo horizontal
    def add_x_labels(self):
        # Definindo uma lista com os labels do eixo horizontal
        x_labels = [
            MathTex("\pi"), MathTex("2 \pi"),
            MathTex("3 \pi"), MathTex("4 \pi"),
        ]

        # Loop para iterar sobre os elementos da lista
        for i in range(len(x_labels)):
            # Posicionando as labels abaixo do eixo horizontal. -1 é a posição de pi e 2*i é o deslocamento a cada iteração
            x_labels[i].next_to(mobject_or_point=np.array([-1 + 2*i, 0, 0]), direction=DOWN)
            self.add(x_labels[i])

    # Mostra o Círculo por onde a linha vai girar
    def show_circle(self):
        circle = Circle(radius=1) # Criando um círulo de raio 1
        circle.move_to(self.origin_point) # movendo o círculo para a posição de origem definida no método show_axis()

        self.add(circle) # Adiciona o círculo à cena
        self.circle = circle # define uma propriedade da cena chamada circle como o círculo criado

    # Move o ponto pelo círculo enquanto a linha o acompanha e cria o gráfico de sin(x)
    def move_dot_and_draw_curve(self):
        orbit = self.circle # define uma órbita para o ponto
        origin_point = self.origin_point # define a origem

        dot = Dot(radius=0.08, color=YELLOW) # definindo o ponto para a animação
        dot.move_to(orbit.point_from_proportion(0)) # move o ponto para a posição do círculo de angulo 0
        self.t_offset = 0 # definindo um deslocamento de tempo
        rate = 0.25 # definindo uma taxa

        # Function updater para 
        def go_around_circle(mob, dt):
            self.t_offset += (dt * rate)
            # print(self.t_offset)
            mob.move_to(orbit.point_from_proportion(self.t_offset % 1))

        def get_line_to_circle():
            return Line(origin_point, dot.get_center(), color=BLUE)

        def get_line_to_curve():
            x = self.curve_start[0] + self.t_offset * 4
            y = dot.get_center()[1]
            return Line(dot.get_center(), np.array([x,y,0]), color=YELLOW_A, stroke_width=2 )


        self.curve = VGroup()
        self.curve.add(Line(self.curve_start,self.curve_start))
        def get_curve():
            last_line = self.curve[-1]
            x = self.curve_start[0] + self.t_offset * 4
            y = dot.get_center()[1]
            new_line = Line(last_line.get_end(),np.array([x,y,0]), color=YELLOW_D)
            self.curve.add(new_line)

            return self.curve

        dot.add_updater(go_around_circle)

        origin_to_circle_line = always_redraw(get_line_to_circle)
        dot_to_curve_line = always_redraw(get_line_to_curve)
        sine_curve_line = always_redraw(get_curve)

        self.add(dot)
        self.add(orbit, origin_to_circle_line, dot_to_curve_line, sine_curve_line)
        self.wait(8.5)

        dot.remove_updater(go_around_circle)