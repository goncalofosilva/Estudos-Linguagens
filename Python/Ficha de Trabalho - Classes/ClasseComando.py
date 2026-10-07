class ComandoTv:
    def __init__(self,marca,ano_fabrico,canal):
        self.marca = marca
        self.ano = ano_fabrico
        # Podiamos fazer assim já no construtor:
        """
        if canal < 1 or canal > 99:
            self.canal = 20
        else:
            self.canal = canal
        """
        self.canal = canal
        self.volume = 15 # Começa com volume 15 ao ligar
        self.ligado = False # Começa desligado
    
    def __str__(self):
        # Codigo para mostrar os dados do comando
        return f"Comando {self.marca} do ano {self.ano} está no canal {self.canal} com volume {self.volume}" 
    # / para continuar o codigo noutra linha

    def mudarCanal(self, novoCanal):
        # se o novo canal estiver entre 1 e 99 ele entra no novoCanal senao retorna o canal antigo
        if novoCanal >= 1 and novoCanal <= 99:
            return novoCanal
        return self.canal
    
    def alterarVolume(self, sinal):
        if sinal == '-' and self.volume != 0:  # se o volume nao for 0
            self.volume -= 1
        if sinal == '+' and self.volume != 50:  # se o volume nao for 50
            self.volume += 1
        else:
            print("Volume máximo.")
    
    def mute(self):
        self.volume = 0
    
    def ligar_desligar(self):
        if self.ligado:
            self.ligado = False
        self.ligado = True