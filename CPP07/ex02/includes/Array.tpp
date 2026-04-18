#ifndef ARRAY_TPP
#define ARRAY_TPP

// Constructeur par defaut : tableau vide, aucune allocation
template <typename T>
Array<T>::Array() : _array(NULL), _size(0)
{}

// Constructeur avec taille : alloue n elements initialises a leur valeur par defaut
// new T[n]() : le () force l'initialisation (0 pour int, "" pour string, etc.)
template <typename T>
Array<T>::Array(size_t n) : _array(new T[n]()), _size(n)
{}

// Constructeur par copie : copie profonde
// Alloue un nouveau tableau independant et copie les valeurs une par une
// Modifier la copie ne modifie pas l'original
template <typename T>
Array<T>::Array(const Array& other) : _array(new T[other._size]()), _size(other._size)
{
    for (size_t i = 0; i < _size; ++i)
        _array[i] = other._array[i];
}

// Operateur d'affectation : copie profonde avec protection contre l'auto-affectation
// delete[] l'ancien tableau avant d'allouer le nouveau
template <typename T>
Array<T>& Array<T>::operator=(const Array& other)
{
    if (this != &other)
    {
        delete[] _array;
        _size  = other._size;
        _array = new T[_size]();
        for (size_t i = 0; i < _size; ++i)
            _array[i] = other._array[i];
    }
    return *this;
}

// Destructeur : libere la memoire allouee par new[]
template <typename T>
Array<T>::~Array()
{
    delete[] _array;
}

// operator[] non-const : permet la lecture et l'ecriture (arr[i] = 42)
// Leve std::out_of_range si index >= _size
// Note : index est size_t (non signe), donc -2 devient un tres grand nombre -> exception
template <typename T>
T& Array<T>::operator[](size_t index)
{
    if (index >= _size)
        throw std::out_of_range("Index out of bounds");
    return _array[index];
}

// operator[] const : acces en lecture seule sur un objet const
// Meme logique de verification que la version non-const
template <typename T>
const T& Array<T>::operator[](size_t index) const
{
    if (index >= _size)
        throw std::out_of_range("Index out of bounds");
    return _array[index];
}

// size() const : retourne le nombre d'elements, ne modifie pas l'objet
template <typename T>
size_t Array<T>::size() const
{
    return _size;
}

#endif
