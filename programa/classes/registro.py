class reg:
    def __init__(self,nlinea,valor):
        self.nlinea = nlinea
        self.valor = valor
    
    def __str__(self):
        return f"linea {self.nlinea}: {self.valor}"
        