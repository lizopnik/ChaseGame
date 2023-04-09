#include "Arena.h"

std::ostream& operator<<(std::ostream& out, const Arena& a) {
    for (int i = 0; i < a.width + 1; i++) {
        for (int j = 0; j < a.length + 1; j++) {
            if (i == 0) {
                if (j > 9) out << "  " << j;
                else out << "   " << j;
            }
            else {
                if (j == 0) {
                    if (i > 9) out << "  " << i << "  ";
                    else out << "   " << i << "  ";
                }
                else if ((i == a.prey->getLocation().get_x()) && (j == a.prey->getLocation().get_y())) out << "_O_|";
                else if ((i == a.predator->getLocation().get_x()) && (j == a.prey->getLocation().get_y())) out << "_X_|";
                else out << "___|";
            }
        }
        out << "\n";

    }
    return out;
}