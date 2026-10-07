from ClasseTriangulo import Triangulo # Importar classe triangulo
from ClasseComando import ComandoTv # Importar classe ComandoTv
from ClasseRetangulo import Retangulo # Importar classe Retangulo


triangulo01 = Triangulo(12,7,4)
triangulo02 = Triangulo(10,8,6)
triangulo03 = Triangulo(15,11,9)

# Testar se é possivel formar o triângulo
if triangulo01.formarTriangulo():
    print("Possivel formar o triangulo 01")
    
if triangulo02.formarTriangulo():
    print("Possivel formar o triangulo 02")
    
if triangulo03.formarTriangulo():
    print(f"Perímetro: {triangulo03.perimetro()}")
    print(f"Área: {triangulo03.areaTriangulo():.2f}") # Arredondar a duas casas décimais
    print(f"Tipo: {triangulo03.tipo()}")

    

c1 = ComandoTv("LG",2019,20)
print(c1)
c1.canal = c1.mudarCanal(75)
print(f"Depois de alterar a 1ºvez o canal: {c1.canal}")
c1.canal = c1.mudarCanal(103)
print(f"Depois de alterar a 2ºvez o canal: {c1.canal}")

c1.alterarVolume('-')
print(c1.volume)
c1.alterarVolume('-')
print(c1.volume)
c1.alterarVolume('+')
print(c1.volume)
c1.alterarVolume('-')
print(c1.volume)
c1.alterarVolume('+')
print(c1.volume)



r1 = Retangulo(15,20, Azul)
r2 = Retangulo(20,25, Rosa)
print (r1)
if r1.verficar_quadrado:
    print("É um quadrado.")
else:
    print("Não é um quadrado.")
print(r1.diagonal_retangulo)
print(r1.calcular_perimetro)
print(r1.comparar_perimetro(r1.perimetro,r2.perimetro))
print(r1.comparar_cor(r1.cor,r2.cor))