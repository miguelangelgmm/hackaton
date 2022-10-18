from datetime import datetime
import sqlite3
import serial
import time

date = datetime.now()

arduino = serial.Serial('COM6', 9600)

time.sleep(2)

datos = str(arduino.readline())

valores = datos.split("A")

"Eliminar primer y ultimo elemento"
del valores[0]
valores.pop()

print(valores)

print(datos)

def insertListAlumnos(lista):
    #conectamos con la bbdd
    conn = sqlite3.connect('basededatos.db')

    # creamos un cursor

    cursor = conn.cursor()

    query = '''INSERT INTO sensores(temperatura,humedad,humedadTierra,clima,tiempo) VALUES(?,?,?,?,?) '''

    #añadimos todos los alumnos a la bbdd                       #date.date() --> devuelve fecha , date te va a devolver fecha y tiempo
    cursor.execute(query,(lista[0], lista[1], lista[2],lista[3],date.date()))
    conn.commit()

    # cerramos el cursor
    cursor.close()
    # cerramos la conexión
    conn.close()

arduino.close()

insertListAlumnos(valores)
