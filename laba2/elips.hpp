//
// Created by ivan on 09.10.2021.
//

#ifndef SONYA2_ELIPS_HPP
#define SONYA2_ELIPS_HPP

#include <iostream>
#include <cmath>

namespace Elips {
    class spiral {// общее уравнение x^2/a^2+y^2/b^2=r^2
    private:
        double a;
        double b;
        double r;
    public:
        spiral() {
            a = 1;
            b = 1;
            r = 1;
        }

        spiral(double x, double y, double z) {
            a = x;
            b = y;
            r = z;
        }

        void change(double x, double y, double z) {
            a = x;
            b = y;
            r = z;
        }

        void get_parameters() const;

        [[nodiscard]] double focal_distance() const {
            return (sqrt(pow(a, 2) - pow(b, 2)));
        }

        [[nodiscard]] double e() const {
            return (sqrt(1 - (pow(b, 2) / pow(a, 2))));
        }

        [[nodiscard]] double length() const {
            return (4 * (M_PI * a * b + pow(a - b, 2)) / (a + b));
        }

        [[nodiscard]] double area() const {
            return (M_PI * a * b);
        }

        [[nodiscard]] double min() const {
            return (a * (1 - e()));
        }

        [[nodiscard]] double max() const {
            return (a * (1 + e()));
        }

        void *y(double x,double **mas);
    };
}
#endif //SONYA2_ELIPS_HPP
