# Análisis Estático
En esta fase se analizó el binario sin ejecutarlo para identificar sus capacidades.

* **Técnica de Ofuscación:** Se identifico el uso de un cifrado **XOR** simple para ocultar cadenas de texto críticas.
* **Hallazgos de CAPA:** El reporte detecto capacidades de inyección de procesos 
* **APIs de Windows detectadas:** Se encontraron llamadas a "VirtualAlloc" y "WriteProcessMemory", lo que confirma la reserva de memoria para el shellcode.
