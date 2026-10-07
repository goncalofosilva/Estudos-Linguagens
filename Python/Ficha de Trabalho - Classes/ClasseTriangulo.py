from math import sqrt 
# from math import * (isto importa tudo da biblioteca math 
# so que com este codigo nao temos de por o "math." antes de usarmos as funcoes da biblioteca)

# import math (desta forma temos sempre de por math. (por exemplo: math.sqrt))

class Triangulo :
    # Atritubo da classe
    num_triangulos = 0
    
    # Construtor
    def __init__(self, l1, l2, l3):
        # lado1,lado2,lado3 são atributos da instância
        self.lado1 = l1
        self.lado2 = l2
        self.lado3 = l3
        Triangulo.num_triangulos += 1
    
    
    def __str__(self):
        perimetro = self.lado1 + self.lado2 + self.lado3
        antes_da_raiz = perimetro*(perimetro-lado1)*(perimetro-lado2)*(perimetro-lado3)
        
        # Fazer a raiz quadrada
        area_triangulo = sqrt(antes_da_raiz)
    
    
    
    def formarTriangulo (self):
        """
        if self.lado1 + lado2 < lado3:
            print("É possivel formar um triângulo com os lados dados.")
        
        elif lado2 + lado3 < lado1:
            print("É possivel formar um triângulo com os lados dados.")
        
        elif lado1 + lado3 < lado2:
            print("É possivel formar um triângulo com os lados dados.")
        
        else:
            print("Não é possivel formar um triângulo com os lados dados.")
        """
        if self.lado1 > self.lado2 + self.lado3:
            return False
        if self.lado2 > self.lado1 + self.lado3:
            return False
        if self.lado3 > self.lado2 + self.lado1:
            return False
        return True
    
    def perimetro(self):
        perimetro = self.lado1 + self.lado2 + self.lado3
    
    def areaTriangulo(self):
        p = self.perimetro()/2
        return sqrt(p*(p-self.lado1)*(p-self.lado2)*(p-self.lado3))
    
    def tipo_triangulo(self):
        if self.lado1 == self.lado2 and self.lado3:
            return "Equilátero"
        if self.lado1 != self.lado2 and self.lado1 != self.lado3 and self.lado2 != self.lado3:
            return "Escaleno"
        return "Isósceles"