# Análisis Dinámico de Memoria
Este documento detalla el comportamiento del payload en tiempo de ejecución, enfocándose en la manipulación de memoria y el descifrado de cadenas.

## 1. Identificación de Regiones RWX
Durante la ejecución en el depurador (x32dbg), se monitoreó el mapa de memoria para identificar secciones con permisos sospechosos, se detectó una región con protección **ERW** (Execute, Read, Write), lo cual es un indicador crítico de inyección de código.

* **Dirección de memoria:** "00580000" (según se observa en el Memory Map).
* **Estado:** Privado (PRV).
* **Propósito:** Esta región es utilizada para alojar el shellcode tras ser descifrado, permitiendo su ejecución directa desde la memoria RAM.

(imagen 1)

## 2. Proceso de Descifrado XOR
El payload utiliza un algoritmo de descifrado XOR para ocultar sus funciones sensibles y evitar la detección estática simple. 

* **Mecanismo:** El programa localiza las cadenas ofuscadas en la sección ".data" o ".rdata".
* **Descifrado en Caliente:** Antes de ejecutar las funciones críticas (como la conexión de red o la creación de archivos), el programa aplica la clave XOR para restaurar las cadenas originales en la memoria dinámica.
* **Confirmación:** Mediante el uso de breakpoints en el depurador, se verificó el momento exacto en que las cadenas pasan de ser texto cifrado a comandos legibles para el sistema operativo.

  
(imagen 2)

## 3. Evidencias de Ejecución
Se confirmó que el malware realiza las siguientes acciones una vez activo en memoria:
1. Reserva de memoria dinámica mediante APIs de Windows.
2. Inyección del payload descifrado en la región "00580000".
3. Creación de un archivo de evidencia en el disco local (C:\Users\UserPrueba\Documents\TAREA 4\evidencia) como prueba de compromiso exitoso.

(imagen 3)
