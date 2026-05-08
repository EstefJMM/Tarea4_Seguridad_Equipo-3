# Análisis Dinámico de Memoria
Se utilizó el depurador **x64dbg** para observar el comportamiento del malware en tiempo de ejecución.

* **Reserva de Memoria:** Se confirmó que el programa solicita memoria con permisos **RWX** .
* **Depuración:** Se colocaron puntos de interrupción en las funciones de memoria, verificando que el shellcode se carga correctamente antes de ser ejecutado por el payload.
