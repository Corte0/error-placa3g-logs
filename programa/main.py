from functions.file import filtrar 
from functions.busqueda import buscar_error
from classes.registro import reg

adress = input ("ingrese la direccion de su archivo: ")

try:
        file = open(adress,"r")          
except:
    print("no se pudo abrir el archivo")

registro = filtrar (file)
file.close()

errores = buscar_error(registro)
for i in errores:
   print ("error en la linea:",i.nlinea)
