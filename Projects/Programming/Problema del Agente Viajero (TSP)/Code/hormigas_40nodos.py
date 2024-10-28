# -*- coding: utf-8 -*-
"""Hormigas_40nodos.ipynb

Automatically generated by Colaboratory.

Original file is located at
    https://colab.research.google.com/drive/1cLzMY_hUOdWu_aEfAHXmjF6jjG8QqGKO
"""

import random
import pandas as pd

# Parámetros del algoritmo
num_hormigas = 40
max_iteraciones = 1000
alfa = 1.0
beta = 3.0
evaporacion = 0.1
feromona_inicial = 0.1

# Cargar la matriz de distancias desde un archivo Excel
df = pd.read_excel('/content/matrices_40.xlsx', sheet_name=9, index_col=0)

# Obtener la lista de nombres de nodos desde las columnas y filas del DataFrame
nombres_nodos = df.columns.tolist()

# Número de nodos
num_nodos = len(nombres_nodos)

# Matriz de distancias a partir de los datos del DataFrame
distancias = df.values.tolist()

# Inicialización de feromonas
feromonas = [[feromona_inicial] * num_nodos for _ in range(num_nodos)]

# Restablecer la diagonal principal de la matriz de distancias a un valor grande (infinito)
for i in range(num_nodos):
    distancias[i][i] = float('inf')

# Función para calcular la probabilidad de selección
def calcular_probabilidad(nodo_actual, nodos_disponibles):
    epsilon = 0.001  # Pequeña constante para evitar divisiones por cero
    suma = sum(((feromonas[nodo_actual][nodo_destino] + epsilon) ** alfa) * ((1 / (distancias[nodo_actual][nodo_destino] + epsilon)) ** beta) for nodo_destino in nodos_disponibles)
    probabilidades = [((feromonas[nodo_actual][nodo_destino] + epsilon) ** alfa) * ((1 / (distancias[nodo_actual][nodo_destino] + epsilon)) ** beta) / suma for nodo_destino in nodos_disponibles]
    return probabilidades

# Función para seleccionar el siguiente nodo
def seleccionar_nodo(probabilidades):
    r = random.random()
    acumulado = 0
    for i, probabilidad in enumerate(probabilidades):
        acumulado += probabilidad
        if acumulado >= r:
            return i

# Función para actualizar las feromonas
def actualizar_feromonas(camino, distancia_camino):
    for i in range(len(camino) - 1):
        nodo_actual = camino[i]
        nodo_siguiente = camino[i + 1]
        feromonas[nodo_actual][nodo_siguiente] = (1 - evaporacion) * feromonas[nodo_actual][nodo_siguiente] + (1 / distancia_camino)

# Algoritmo de colonia de hormigas
mejor_camino_global = None
mejor_distancia_global = float('inf')

for _ in range(max_iteraciones):
    for hormiga_id in range(num_hormigas):
        camino_hormiga = []
        nodos_disponibles = list(range(num_nodos))
        distancia_camino_hormiga = 0

        # Seleccionar un nodo inicial al azar
        nodo_inicial = random.choice(nodos_disponibles)
        camino_hormiga.append(nodo_inicial)
        nodos_disponibles.remove(nodo_inicial)

        while nodos_disponibles:
            probabilidades = calcular_probabilidad(camino_hormiga[-1], nodos_disponibles)
            siguiente_nodo = seleccionar_nodo(probabilidades)
            camino_hormiga.append(nodos_disponibles[siguiente_nodo])
            nodos_disponibles.pop(siguiente_nodo)
            distancia_camino_hormiga += distancias[camino_hormiga[-2]][camino_hormiga[-1]]

        # Volver al nodo inicial para completar el ciclo
        distancia_camino_hormiga += distancias[camino_hormiga[-1]][camino_hormiga[0]]
        camino_hormiga.append(camino_hormiga[0])

        actualizar_feromonas(camino_hormiga, distancia_camino_hormiga)

        if distancia_camino_hormiga < mejor_distancia_global:
            mejor_camino_global = camino_hormiga
            mejor_distancia_global = distancia_camino_hormiga

print("Mejor camino encontrado:", " - ".join([str(nombres_nodos[nodo]) for nodo in mejor_camino_global]))
print("Costo final:", mejor_distancia_global)