#include <iostream>
#include <vector>
#include <windows.h>

// Tec 1: descifrado de cadenas en tiempo de ejecución (XOR)
void decryptString(char* data, size_t dataLen, char key) {
    for (size_t i = 0; i < dataLen; ++i) {
        data[i] ^= key;
    }
}

int main() {
    // cadena cifrada con XOR (key: 0x55)
    char secretMessage[] = { 0x1c, 0x3b, 0x3c, 0x36, 0x3c, 0x24, 0x3b, 0x21, 0x3a, 0x65, 0x36, 0x2c, 0x28, 0x30, 0x29, 0x24, 0x26, 0x2c, 0x2a, 0x3b, 0x6d, 0x6d, 0x6d, 0x00 };
    decryptString(secretMessage, 23, 0x55);
    std::cout << "[+] Mensaje descifrado: " << secretMessage << std::endl;

    // Tec 5: función sensible simulada (Sleep y CreateFileA)[cite: 2]
    std::cout << "[!] Ejecutando funciones sensibles..." << std::endl;
    Sleep(2000);
    HANDLE hFile = CreateFileA("evidencia_benigna.txt", GENERIC_WRITE, 0, NULL, CREATE_ALWAYS, FILE_ATTRIBUTE_NORMAL, NULL);
    if (hFile != INVALID_HANDLE_VALUE) {
        std::cout << "[+] Archivo creado correctamente." << std::endl;
        CloseHandle(hFile);
    }

    // Tec 3: simulación de inyección en memoria (RWX)[cite: 2]
    std::cout << "[!] Reservando region de memoria RWX..." << std::endl;
    LPVOID remoteBuffer = VirtualAlloc(NULL, 1024, MEM_COMMIT | MEM_RESERVE, PAGE_EXECUTE_READWRITE);

    if (remoteBuffer) {
        std::cout << "[+] Memoria RWX reservada en: " << remoteBuffer << std::endl;
        memset(remoteBuffer, 0x90, 10); // llena con NOPs para el analisis[cite: 2]
    }

    std::cout << "\nPresiona ENTER para salir y liberar memoria..." << std::endl;
    std::cin.get();

    if (remoteBuffer) VirtualFree(remoteBuffer, 0, MEM_RELEASE);
    return 0;
}