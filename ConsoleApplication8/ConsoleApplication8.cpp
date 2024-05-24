#include <iostream>
#include <vector>
#include <algorithm>
#include <fstream>


int main() {
    // 1. Организуйте чтение из файла целочисленного одномерного вектора
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

    // 2. Реверсируйте последовательность элементов вектора
    reverse(v.begin(), v.end());

    // 3. Найдите минимальный элемент
    auto min_element = *std::min_element(v.begin(), v.end());

    // 4. Удалите из вектора все четные элементы
    v.erase(remove_if(v.begin(), v.end(), [](int x) { return x % 2 == 0; }), v.end());

    // 5. Отсортируйте вектор в убывающей или возрастающей последовательности
    sort(v.begin(), v.end(), std::greater<int>()); // убывающая последовательность
    // sort(v.begin(), v.end()); // возрастающая последовательность

    // 6. Вставьте в вектор произвольный элемент, не нарушая сортировку
    v.insert(upper_bound(v.begin(), v.end(), 5), 5); // вставить 5 в отсортированный вектор

    // 7. Определите индекс заданного элемента
    auto it = find(v.begin(), v.end(), 5);
    if (it != v.end()) {
        std::cout << "Índice del elemento:" << distance(v.begin(), it) << std::endl;
    }
    else {
        std::cout << "Elemento no encontrado" << std::endl;
    }

    // 8. Удалите из вектора дублированные элементы.
    sort(v.begin(), v.end()); // сортируем вектор
    v.erase(unique(v.begin(), v.end()), v.end()); // удаляем дубликаты

    // Выводим результат
    for (int x : v) {
        std::cout << x << " ";
    }
    std::cout << std::endl;

    return 0;
}