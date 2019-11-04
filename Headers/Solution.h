#ifndef PROJIA_SOLUTION_H
#define PROJIA_SOLUTION_H

#include <iostream>
#include <fstream>
#include <cmath>
#include <vector>

#include "Problem.h"


// les individus
class Solution {
//contient la déclaration d'une solution
public:

    /**
    * Constructeur de la class Solution : initialise une Solution avec
    * Problem = &pbm un objet de la class Problem passe en paramètre
    * @param [in] pbm - Le problem auquel la solution(l'individu) va devoir repondre
    */
    Solution (const Problem& pbm);  // _solution prend la valeur 20 car un Individu est defini par un tableau de 20 cases

    /**
    * Constructeur de la class Solution : initialise une Solution avec
    * Solution = &sol un objet de la classe Solution passer en parametre
    * @param [in] sol - La solution avec laquelle on construire notre objet Solution courant
    */
    Solution (const Solution& sol);

    /**
     * Destructeur de solution : detruit la solution
     */
    ~Solution();

    /**
     * Retourne un objet Problem
     * @return le probleme que la solution doit regler
     */
    const Problem& pbm() const;


    /**
     * Surcharge de l'operateur d'affectation (operator=)
     * @return un objet solution avec les attributs de la solution passer en parametres
     * @param [in] sol - l'objet Solution que l'on va affecter a l'objet Solution courant
     */
    Solution& operator=  (const Solution& sol);

    /**
    * Surcharge de l'operateur de comparaison egale  (operator==)
    * @return true si les deux objet Solution sont égaux ou false si ils sont différents
    * @param [in] sol - l'objet Solution que l'on va comparer a l'objet Solution courant
    */
    bool operator== (const Solution& sol) const;

    /**
    * Surcharge de l'operateur de comparaison different de (operator!=)
    * @return true si les deux objet Solution sont differents l'une de l'autre ou false si ils sont egaux
    * @param [in] sol - l'objet Solution que l'on va comparer a l'objet Solution courant
    */
    bool operator!= (const Solution& sol) const;

    /**
    * Initialise un objet Solution
    */
    void initialize();

    /**
    * Calcule la fitness courante
    * @return un double qui represente une fitness
    */
    double fitness();   // test des benchmarks

    /**
    * Retourne la fitness courante de l'objet Solution
    * @return un double qui represente la fitness courante de la Solution
    */
    double get_fitness() const;

    /**
    * Retourne la taille de la Solution
    * @return un unsigned int qui represente la taille de la Solution
    */
    unsigned int size() const;


    /**
    * Retourne la Solution
    * @return un std::vector<double> qui represente la Solution (l'individu)
    */
    std::vector<double>& solution();

    /**
    * Retourne une Solution a une position donnee
    * @param [in] index - l'indice auquel se trouve la Solution
    * @return un double qui represente une Solution
    */
    double& position(const int index); //retournera une position du tableau _solution

    /**
    * Change la valeur à l'indice <index> à la valeur <value>
    * @param [in] index - l'indice dans le tableau _solution
    * @param [in] value - la nouvelle valeur
    */
    void  position(const int index, const double value);




private:
    // Cases du tableau d'un individu
    std::vector<double> _solution;      // minimum = 20

    // Fitness de l'individu courant
    double _current_fitness;

    // Fonction a optimiser
    const Problem& _pbm;
};


#endif //PROJIA_SOLUTION_H