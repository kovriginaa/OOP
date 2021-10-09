#include <iostream>
#include "dialog.hpp"
#include "elips.hpp"

using namespace Elips;
namespace dialog {
    void menu(spiral l) {
        l.get_parameters();
        std::cout << "Menu:" << std::endl;
        std::cout << "0.Exit" << std::endl << "1.Change parameters" << std::endl << "2. Focal distance" << std::endl
                  << "3. E" << std::endl << "4. Length" << std::endl
                  << "5. Area" << std::endl << "6.Min" << std::endl << "7.Max"
                  << std::endl << "8.Y"
                  << std::endl;;
        std::cout << "Choose:" << std::endl;
    }

    void Dialog() {
        const char *pr, *s;
        bool vvod = true;
        int ans, n;
        double x, y, z;
        std::cout << "Line is  x^2/a^2+y^2/b^2=r^2" << std::endl;
        spiral line(1, 1, 1);
        while (vvod) {
            menu(line);
            pr = "";
            s = "";
            do {
                std::cout << pr << std::endl;
                pr = "You are wrong; repeat please!";
                dialog::getNum(ans);
            } while (ans > 8 || ans < 0);

            if (ans == 0) {
                vvod = false;

            } else if (ans == 1) {
                std::cout << "Write parameter a:" << std::endl;
                dialog::getNum(x);
                std::cout << "Write parameter b:" << std::endl;
                dialog::getNum(y);
                do {
                    std::cout << "Write parameter b:" << std::endl;
                    dialog::getNum(y);
                } while (y > x);
                std::cout << "Write parameter r:" << std::endl;
                dialog::getNum(z);
                line.change(x, y, z);
                std::cout << "Successful change" << std::endl;
            } else if (ans == 2) {
                std::cout << line.focal_distance() << std::endl;

            } else if (ans == 3) {
                std::cout << line.e() << std::endl;

            } else if (ans == 4) {
                std::cout << line.length() << std::endl;

            } else if (ans == 5) {
                std::cout << line.area() << std::endl;

            } else if (ans == 6) {
                std::cout << line.min() << std::endl;

            } else if (ans == 7) {
                std::cout << line.max() << std::endl;
            } else if (ans == 8) {
                std::cout << "Write x" << std::endl;
                dialog::getNum(x);
                double *mas;
                mas = new double[2];
                mas[0] = 1;
                mas[1] = 1;
                line.y(x, &mas);
                if (mas == nullptr) {
                    std::cout << "Wrong x" << std::endl;
                } else {
                    std::cout << mas[0] << " " << mas[1] << std::endl;
                }
                delete[] mas;
            }
        }
    }
}

