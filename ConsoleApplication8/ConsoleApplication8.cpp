#include <iostream>
#include <vector>
#include <algorithm>
#include <fstream>


int main() {
    // 1.  Organizar la lectura de un archivo de vector unidimensional entero
    std::vector<int> v;
    std::ifstream file("Texto.txt");
    if (!file.is_open()) {
        std::cout << "No se puede abrir el archivo" << std::endl;
        return 1;
    }
    int x;
    while (file >> x) {
        v.push_back(x);
    }
    file.close();

    // 2. Invertir la secuencia de elementos del vector
    reverse(v.begin(), v.end());

    // 3. Encuentra el elemento mínimo
    auto min_element = *std::min_element(v.begin(), v.end());

    // 4. Elimine todos los elementos pares del vector
    v.erase(remove_if(v.begin(), v.end(), [](int x) { return x % 2 == 0; }), v.end());

    // 5. Ordene el vector en secuencia descendente o ascendente
    sort(v.begin(), v.end(), std::greater<int>()); // убывающая последовательность
    // sort(v.begin(), v.end()); // возрастающая последовательность

    // 6. Inserte un elemento arbitrario en el vector sin romper la clasificación
    v.insert(upper_bound(v.begin(), v.end(), 5), 5); // вставить 5 в отсортированный вектор

    // 7.  Defina el índice del elemento especificado
    auto it = find(v.begin(), v.end(), 5);
    if (it != v.end()) {
        std::cout << "Índice del elemento:" << distance(v.begin(), it) << std::endl;
    }
    else {
        std::cout << "Elemento no encontrado" << std::endl;
    }

    // 8. Elimine los elementos duplicados del vector..
    sort(v.begin(), v.end()); // сортируем вектор
    v.erase(unique(v.begin(), v.end()), v.end()); // удаляем дубликаты

    // Salida del resultado

    for (int x : v) {
        std::cout << x << " ";
    }
    std::cout << std::endl;

    return 0;
}
