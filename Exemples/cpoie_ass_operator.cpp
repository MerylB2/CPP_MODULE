
#include <iostream>

class Tableau
{
    private:
        int* _data;
        int _taille;

    public:
        // constructeur par defaut 
        Tableau(void) : _data(NULL), _taille(0) {
            std::cout << "Constructeur par défaut appelé" << std::endl;
        }

        // constructeur avec taille
        Tableau(int taille) : _taille(taille) {
            this->_data = new int[taille];
            std::cout << "Constructeur avec taille appelé" << std::endl;
            for (int i = 0; i < taille; i++) {
                this->_data[i] = 0;
            }
            std::cout << "Construction d'un tableau de (" << taille << ")" << std::endl;
        }

        // construvteur de copie
        Tableau(const Tableau& other) : _taille(other._taille) {
            std::cout << "Constructeur de copie appelé" << std::endl;
            this->_data = new int[other._taille];
            for (int i = 0; i < other._taille; i++) {
                this->_data[i] = other._data[i];
            }
        }

        // operateur d'affectation
        Tableau& operator=(const Tableau& other) {
            std::cout << "Operateur d'affectation appelé" << std::endl;
            if (this != &other) {
                delete[] this->_data;
                this->_taille = other._taille;
                this->_data = new int[other._taille];
                for (int i = 0; i < other._taille; i++) {
                    this->_data[i] = other._data[i];
                }
            }
            return *this;
        }

        // destructeur
        ~Tableau(void) {
            std::cout << "Destructeur appelé" << std::endl;
            delete[] this->_data;
        }

        // Methodes utiles
        int& operator[](int index) {
            return this->_data[index];
        }
};

int main()
{
    Tableau t1(5);               // Constructeur avec taille
    t1[0] = 10;
    t1[1] = 20;

    Tableau t2 = t1;            // Constructeur de copie
    Tableau t3;                 
    t3 = t1;                    // Operateur d'affectation

    std::cout << "t2[1]: " << t2[1] << std::endl;
    std::cout << "t3[0]: " << t3[0] << std::endl;

    return 0;
}