#include <iostream>

class Calculatrice
{
    private :
        int _res;

    public :
        Calculatrice(void) : _res(0) {}

        Calculatrice& ajouter(int val) {
            this-> _res += val;
            return *this;
        }

        Calculatrice& soustraire(int val) {
            this-> _res -= val;
            return *this;
        }

        Calculatrice& multiplier(int val) {
            this-> _res *= val;
            return *this;
        }

        Calculatrice& diviser(int val) {
            if (val != 0) {
                this-> _res /= val;
            } else {
                std::cerr << "Erreur : Division par zéro !" << std::endl;
            }
            return *this;
        }

        int getResultat(void) const {
            return this->_res;
        }
};

int main()
{
    Calculatrice calc;

    calc.ajouter(5).soustraire(0).multiplier(2).ajouter(10);

    std::cout << "Le résultat est : " << calc.getResultat() << std::endl;

    calc.diviser(0);

    std::cout << "Le résultat final est : " << calc.getResultat() << std::endl;

    return 0;
}
