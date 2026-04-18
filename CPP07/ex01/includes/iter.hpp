#ifndef ITER_HPP
#define ITER_HPP
#include <cstddef>
#include <iostream>

// T = type des elements du tableau
// F = type de la fonction (deduit automatiquement)
// Deux parametres template pour accepter n'importe quelle signature :
// func peut prendre T& ou const T& selon le contexte
template <typename T, typename F>
void iter(T *array, size_t len, F func)
{
    for (size_t i = 0; i < len; ++i)
        func(array[i]);
}

// Fonction template d'exemple : affiche chaque element suivi d'un espace
// Doit etre instanciée explicitement a l'appel : iter(arr, n, print_arr<int>)
// car le compilateur ne peut pas deduire T depuis un template non instancié
template <typename T>
void print_arr(T &array_element)
{
    std::cout << array_element << " ";
}

#endif
