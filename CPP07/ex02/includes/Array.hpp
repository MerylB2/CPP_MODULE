#ifndef ARRAY_HPP
#define ARRAY_HPP

#include <stdexcept>
#include <cstddef>

// Classe template Array<T> : tableau dynamique securise
// T peut etre n'importe quel type (int, float, std::string...)
template <typename T>
class Array
{
    private:
        T*     _array; // pointeur vers le tableau alloue sur le tas
        size_t _size;  // nombre d'elements

    public:
        Array();              // tableau vide
        Array(size_t n);      // n elements initialises par defaut
        Array(const Array& other); // copie profonde
        Array& operator=(const Array& other); // affectation profonde
        ~Array();             // libere la memoire allouee

        T&       operator[](size_t index);       // acces en lecture/ecriture
        const T& operator[](size_t index) const; // acces en lecture seule (objet const)
        size_t   size() const;                   // retourne le nombre d'elements
};

// L'implementation est separee dans Array.tpp et incluse ici :
// les templates doivent etre entierement visibles depuis le header
// pour que le compilateur puisse les instancier
#include "Array.tpp"

#endif
