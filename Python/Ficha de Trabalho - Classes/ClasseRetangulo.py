from math import sqrt

class Retangulo:
    def __init__(self, l1, l2, cor):
        self.lado1 = l1
        self.lado2 = l2
        self.cor = cor
    
    def verficar_quadrado(self):
        """
        if self.lado1 == self.lado2:
            print("É um quadrado.")
        else 
            return False
        """
        return self.lado1 == self.lado2
    
    def diagonal_retangulo(self):
        diagonal = (self.lado1 ** 2) + (self.lado2 ** 2)
        return sqrt(diagonal)

    def calcular_perimetro(self):
        perimetro = lado1 * 2 + lado2 * 2
    
    def comparar_perimetro(self, outro):
        # self.calcular_perimetro() pega o perímetro deste retângulo que está a ser feito
        # outro.calcular_perimetro() pega o perímetro do segundo retângulo, passado no atributo novo "outro"
        return self.calcular_perimetro() == outro.calcular_perimetro()

    def comparar_cor(self,outro):
        return self.cor.lower() == outro.cor.lower() 
        # o .lower() transforma todas as letras em minúsculas assim empedindo erros como letras maiusculas inesperadas