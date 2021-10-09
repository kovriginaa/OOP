//
// Created by ivan on 09.10.2021.
//

#include "elips.hpp"

void Elips::spiral::get_parameters() const {
    std::cout<<"Parametrs: "<<std::endl;
    std::cout<<"a: "<<a<<" b: "<<b<<" r: "<<r<<std::endl;
}

void *Elips::spiral::y(double x, double **mas) {
    if(x>a*r){
        *mas=nullptr;
    }
    else {
        (*mas)[0] = sqrt((pow(r, 2) - pow(x / a, 2))) * b;
        (*mas)[1] = 0-(sqrt((pow(r, 2) - pow(x / a, 2))) * b);

    }
    return nullptr;
}

