//
// Created by ivan on 09.10.2021.
//
#include "iostream"
#ifndef SONYA2_DIALOG_HPP
#define SONYA2_DIALOG_HPP

namespace dialog {
    template<typename T>
    void getNum(T& a) {
        while (!(std::cin >> a)) {
            if (std::cin.eof()) {
                throw std::runtime_error("EOF");
            }
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout<<"You are wrong; repeat please!"<<std::endl;
        }
    }
    void Dialog();
}
#endif //SONYA2_DIALOG_HPP
