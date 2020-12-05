from manimlib.imports import *
from numpy.core.fromnumeric import size

class Node:
    """ Classe que representa o né de uma lista ligada """
    def __init__(self, value: int, size: float, position: list, next_position: list):
        self.__value = value
        self.__size = size
        self.__position = position
        self.__next_position = next_position

    ######################## Getters e Setters ######################## 

    @property
    def value(self):
        return self.__value

    @value.setter
    def value(self, value):
        self.__value = value

    @property
    def size(self):
        return self.__size

    @size.setter
    def size(self):
        self.__size = size

    @property
    def position(self):
        return self.__position

    @position.setter
    def position(self, position):
        self.__position = position

    @property
    def next_position(self):
        return self.__next_position

    @next_position.setter
    def next_position(self, next_position):
        self.__next_position = next_position

    ######################## Métodos ########################

    def draw(self):
        square_value = Square(side_length=self.__size).move_to(np.array(self.__position))
        value = TextMobject(str(self.__value)).move_to(square_value).scale(self.__size)

        square_pointer = Square(side_length=self.__size).next_to(square_value, direction=RIGHT, buff=0)
        pointer = Arrow(start=square_pointer.get_center(), end=np.array(self.__next_position))

        node = VGroup(square_value, value, square_pointer, pointer)

        return node

class MainScene(Scene):
    def construct(self):
        node = Node(2, 0.5, [0, 0, 0], [3, 0, 0])
        self.play(Write(node.draw()))