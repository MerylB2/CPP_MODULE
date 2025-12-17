#include <iostream>
#include <string>

class Etudiant
{
    private:
        std::string nom;
        int note;
    
    public:

        // recuperer une valeur via GETTER
        std::string getNom(void) const
        {
            return this->nom;
        }

        int getNote(void) const
        {
            return this->note;
        }

        // modifier une valeur via SETTER
        void setNom(std::string newnom)
        {
            this->nom = newnom;
        }

        void setNote(int newnote)
        {
            if (newnote >= 0 && newnote <=20)
                this->note = newnote;
        }

};

int main()
{
    Etudiant etude;

    etude.setNom("Alice"); // on modifier via SETTER
    etude.setNote(19);

    std::cout << etude.getNom() << std::endl; // on recupere via GETTER
    std::cout << etude.getNote() << std::endl;
}