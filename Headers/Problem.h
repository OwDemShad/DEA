#ifndef PROJIA_PROBLEM_H
#define PROJIA_PROBLEM_H

#include <iostream>
#include <fstream>
#include <cmath>
#include <vector>

// class qui va servir a entrer les benchmarks
class Problem {
public:
    /**
    * Constructeur par defaut de Problem : initialise un Problem avec
    * dimension = 0 et idBenchmark = 0
    */
    Problem();

    /**
     * Constructeur de Problem
     * @param dimension [in] - dimension du problem : nombre de variables
     * @param idBenchmark - identifiant de la fonction a optimiser
     */
    Problem(int dimension, int idBenchmark);

    // Pas utile pour le moment
    ~Problem();

    /**
     * Redefinition de l'operator=
     * @param pbm [in] - Problem a copier
     * @return le Problem courant (*this)
     */
    Problem& operator=  (const Problem& pbm);

    /**
     *  Redefinition de l'operator==
     * @param pbm [in] - Problem a comparer
     * @return vrai/faux
     */
    bool operator== (const Problem& pbm) const;

    /**
     * Redefinition de l'operator!=
     * @param pbm [in] - Problem a comparer
     * @return vrai/faux
     */
    bool operator!= (const Problem& pbm) const;


    /**
    * Retourne la dimension du Problem
    * @return la dimension du Problem
    */
    int dimension() const;

    /**
    * Retourne l'idBenchmark du Problem = la fonction d'optimisation mathematique
    * @return l'id du benchmark du Problem
    */
    int idBenchmark() const;

    /**
    * Change la dimension du Problem
    * @param [in] dimension - dimension du Problem
    */
    void changerDimension(int dimension);

    /**
    * Changer le benchmark par l'id
    * @param [in] idBenchmark - l'id du benchmark
    */
    void changerIdBenchmark(int idBenchmark);

    /**
    * Limites inferieure et superieure : intervalle d'etude de la fonction benchmark
    */
    double LowerLimit, UpperLimit;

private:

    int _dimension;

    /*
     * Identifiant correspondant a une fonction benchmark
     * 1 : Rosenbrock
     * 2 : Rastrigin
     * 3 : Ackley
     * 4 : Schwefel
     * 5 : Schaffer
     * 6 : Weierstrass
     */
    int _idBenchmarks; // identifiant que l'on va utiliser dans solution.fitness dans un switch case

};


#endif //PROJIA_PROBLEM_H