#include "proga.hpp"
#include <iostream>
#include <cstdlib>
#include "string"

namespace proga11 {
    int input_line(Row *line, int x, double val) {
        Elem *new_elem, *elem;
        try {
            new_elem = new Elem;
        }
        catch (const std::bad_alloc &ba) {
            std::cout << "------ Something goes wrong: " << ba.what() << std::endl;
            return 1;
        }
        new_elem->column = x;
        new_elem->val = val;
        new_elem->next = nullptr;
        if (line->n == 0) {
            line->el = new_elem;
        } else {
            elem = line->el;
            if (elem->column > x) {
                line->el = new_elem;
                new_elem->next = elem;
            } else {
                while ((elem->next != nullptr) && (elem->next->column < x)) {
                    elem = elem->next;
                }
                if (elem->column == x) {
                    elem->val = val;
                    delete new_elem;
                } else {
                    new_elem->next = elem->next;
                    elem->next = new_elem;
                }
            }
        }
        line->n++;
        return 0;
    }

    Table *input() {
        Table *matr;
        std::string answer;
        const char *pr = ""; // будущее сообщение об ошибке
        int n, m, x, y;
        int value;
        bool vvod;
// ввод количество строк
        do {
            std::cout << pr << std::endl;
            std::cout << "Enter number of lines: —> ";
            pr = "You are wrong; repeat please!";
            getNum(n);
        } while (n < 1);
// ввод количество столбцов
        pr = "";
        do {
            std::cout << pr << std::endl;
            std::cout << "Enter number of colomn: —> ";
            pr = "You are wrong; repeat please!";
            getNum(m);// обнаружена ошибка ввода или конец файла
        } while (m < 1);
        try {
            matr = new Table;
        }
        catch (const std::bad_alloc &ba) {
            std::cout << "------ Something goes wrong: " << ba.what() << std::endl;
            return nullptr;
        }

        matr->n_row = n;
        matr->n_column = m;
        Row *lines;
        try {
            lines = new Row[n];
        }
        catch (const std::bad_alloc &ba) {
            std::cout << "------ Something goes wrong: " << ba.what() << std::endl;
            erase(matr);
            return nullptr;
        }

        matr->Line = lines;
        for (int i = 0; i < matr->n_row; i++) {
            matr->Line[i].n = 0;
            matr->Line[i].el = nullptr;
        }
        vvod = true;
        while (vvod) {
            std::cout << std::endl;
            std::cout << "Enter element";
            std::cout << std::endl;
            pr = "";
            do {
                std::cout << pr << std::endl;
                std::cout << "Enter column: —> ";
                pr = "You are wrong; repeat please!";
                getNum(x);
            } while (x >= matr->n_column || x < 0);
            pr = "";
            do {
                std::cout << pr << std::endl;
                std::cout << "Enter Lines: —> ";
                pr = "You are wrong; repeat please!";
                getNum(y);
            } while (y >= matr->n_row || y < 0);
            std::cout << "Enter Value: —> ";
            getNum(value);
            if (input_line(&matr->Line[y], x, value) != 0) {
                erase(matr);
                return nullptr;
            }
            std::cout << "One more element? (y/n)";
            std::cout << std::endl;
            std::cin >> answer;
            if (answer != "y")
                vvod = false;
        }
        return matr;

    }


    void output_line(Row *line, int n_column) {
        int i = 0;
        Elem *el;
        if (line == nullptr) {
            for (; i < n_column; i++) {
                std::cout << "0 ";
            }
        } else {
            el = line->el;
            while (el != nullptr) {
                for (; i < el->column; i++) {
                    std::cout << "0 ";
                }
                std::cout << el->val << " ";
                i++;
                el = el->next;
            }
            for (; i < n_column; i++) {
                std::cout << "0 ";
            }
        }
    }

    void output(Table *matr) {
        if (matr != nullptr && matr->Line != nullptr) {
            for (int i = 0; i < matr->n_row; i++) {
                output_line(&matr->Line[i], matr->n_column);
                std::cout << std::endl;

            }
        }
    }

    void output_element(Table *matr) {
        Elem *el;
        if (matr != nullptr && matr->Line != nullptr) {
            for (int i = 0; i < matr->n_row; i++) {
                el = matr->Line[i].el;
                while (el != nullptr) {
                    std::cout << "Column: " << el->column << " Line: " << i << " Value: " << el->val;
                    std::cout << std::endl;
                    el = el->next;
                }

            }
        }
    }

    void erase(Table *matr) {
        Row *line;
        Elem *el, *x;
        if (matr != nullptr) {
            line = matr->Line;
            if (line != nullptr) {
                for (int i = 0; i < matr->n_row; i++) {
                    el = line[i].el;
                    while (el != nullptr) {
                        x = el;
                        el = el->next;
                        delete x;
                    }
                }
                delete[] line;
            }
        }
        delete matr;

    }


    bool change_line(Row *line) {
        Elem *min, *el, *x;
        int i = 0;
        if (line->n != 0) {
            el = line->el;
            min = el;
            el = el->next;
            while (el != nullptr) {
                if (el->val < min->val) {
                    delete min;
                    min = el;
                }
                el = el->next;

            }
            line->el = min;
            while (min != nullptr) {
                min->column = i;
                min = min->next;
                i++;
            }
        }
        return true;
    }

    bool change(Table *matr) {
        if (matr != nullptr && matr->Line != nullptr) {
            for (int i = 0; i < matr->n_row; i++) {
                if (!(change_line(&matr->Line[i]))) {
                    return false;
                };
            }
        }
        return true;
    }
}