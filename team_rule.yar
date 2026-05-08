rule Team_Payload_Detection {
    meta:
        description = "Detecta el payload de la Tarea 4 con ofuscación XOR y conexión a puerto 8080"
        author = "Estefani Melendez"
        date = "2026-05-08"

    strings:
        // Buscamos la cadena del puerto que usa el malware
        $network_port = "8080"
        
        // Buscamos funciones de inyeccion de memoria comunes en codigo
        $func1 = "VirtualAlloc"
        $func2 = "WriteProcessMemory"
        
        // Buscamos el patrón del mensaje "Bienvenidos" aunque esté ofuscado
        $s1 = "Bienvenidos" xor(0x01-0xff)

    condition:
        uint16(0) == 0x5A4D and (all of them)
}
