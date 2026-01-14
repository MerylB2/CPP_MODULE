#include <iostream>

class Exemple
{
    private:
        int _valeur;

    public:
        void afficherValeur(void){
            std::cout << "Adresse de l'objet courant: " << this << std::endl;
            std::cout << "Adresse  de l'attribut _valeur: " << &(this->_valeur) << std::endl;
        }
};

int main()
{
    Exemple obj1;
    Exemple obj2;
    Exemple obj3;

    obj1.afficherValeur();
    obj2.afficherValeur();
    obj3.afficherValeur();
}
