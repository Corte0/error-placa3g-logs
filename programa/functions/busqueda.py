from classes.registro import reg

def buscar_error(registro):
    errores = []
    valor_a = 0
    for i in registro:
        if valor_a != 0 and i.valor != valor_a and i.valor != valor_a + 2:
            errores.append(i)
        valor_a = i.valor
    return errores 
