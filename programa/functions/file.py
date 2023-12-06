from classes.registro import reg    

def obtener_numero (linea):
    linea = linea.strip("--rain:(mm)\n")
    linea = linea.replace(',','')
    return int(linea)

def filtrar(file):
    registro = []
    i=1
    for linea in file:
        if linea.startswith("--rain:"):
            registro.append(reg(i,obtener_numero(linea)))
        i+=1
    return registro