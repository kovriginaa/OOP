//
// Created by ivan on 09.10.2021.
//

#ifndef SONYA1_PROGA_HPP
#define SONYA1_PROGA_HPP
#include <iostream>

namespace proga11 {

    struct Elem {
        int column; // колонка
        int val; // значение
        Elem *next;
    };

    struct Row {
        int n; // количество элементов в строке матрицы
        Elem *el; // массив элементов этой строки
    };

    struct Table {
        int n_column;
        int n_row;
        Row *Line;
    };

    template<typename T>
    void getNum(T &a) {
        while (!(std::cin >> a)) {
            if (std::cin.eof()) {
                throw std::runtime_error("EOF");
            }
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout << "You are wrong; repeat please!" << std::endl;
        }
    }

    Table *input();

    void output(Table *);

    void erase(Table *);

    bool change(Table *);

    void output_element(Table *matr);
}
#endif //SONYA1_PROGA_HPP
