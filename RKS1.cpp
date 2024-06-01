// Primeramente, diseñé una estructura que permite almacenar cada número con su frecuencia y la posición de su primera aparición. 
// Luego, use QuickSort para ordenar los números según su frecuencia y posición. Permitiendo que los números con mayor frecuencia 
// salgan primero y, si hay un empate, los números que aparecen primero en la entrada también salen primero en la salida. Finalmente, 
// se imprimen los números en el orden obtenido. Considero que el código funciona porque QuickSort es un algoritmo eficiente que 
// ordena los números exactamente como se necesita para este problema.
#include <iostream>
#include <vector>
#include <utility>

struct Numero {
    int valor;
    int cantidad;
    int primera_aparicion;
};

int particion(std::vector<Numero>& numeros, int low, int high) {
    Numero pivot = numeros[high];
    int i = (low - 1);

    for (int j = low; j <= high - 1; j++) {
        if (numeros[j].cantidad > pivot.cantidad || 
            (numeros[j].cantidad == pivot.cantidad && numeros[j].primera_aparicion < pivot.primera_aparicion)) {
            i++;
            std::swap(numeros[i], numeros[j]);
        }
    }
    std::swap(numeros[i + 1], numeros[high]);
    return (i + 1);
}

void quickSort(std::vector<Numero>& numeros, int low, int high) {
    if (low < high) {
        int pi = particion(numeros, low, high);
        quickSort(numeros, low, pi - 1);
        quickSort(numeros, pi + 1, high);
    }
}

int main() {
    int N, C;
    std::cin >> N >> C;

    std::vector<int> entradas(N);
    std::vector<Numero> numeros;

    for (int i = 0; i < N; i++) {
        std::cin >> entradas[i];
        bool identificado = false;
        for (auto &num : numeros) {
            if (num.valor == entradas[i]) {
                num.cantidad++;
                identificado = true;
                break;
            }
        }
        if (!identificado) {
            numeros.push_back({entradas[i], 1, i});
        }
    }

    quickSort(numeros, 0, numeros.size() - 1);

    for (const auto &num : numeros) {
        for (int i = 0; i < num.cantidad; i++) {
            std::cout << num.valor << " ";
        }
    }

    return 0;
}
