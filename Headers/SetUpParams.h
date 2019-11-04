#ifndef PROJIA_SETUPPARAMS_H
#define PROJIA_SETUPPARAMS_H

#include <iostream>
#include <fstream>
#include <cmath>
#include <vector>


class SetUpParams {
//ici vous devez mettre quelques paramètres tels que :

private:
    /**
     * Nombre de runs de l'algorithme (defaut : 30)
     */
    unsigned int   _independent_runs;         //number of independent runs

    /**
     * Nombre de generations (defaut : 1666)
     */
    unsigned int   _nb_evolution_steps;       // number of iterations per run

    /**
     * Taille de la population (defaut : 40)
     */
    unsigned int   _population_size;		// number of solutions in the population

    /**
     * Taille d'un individu (defaut : 20)
     */
    unsigned int   _solution_size;	        // size of each particle

public:
    /**
     * Constructeur vide de SetUpParams
     */
    SetUpParams ();

    /**
     * Destructeur
     */
    ~SetUpParams();

    // Methodes d'acces

    /**
     * Nombre de run de l'algorithme
     * @return int - _independent_runs
     */
    const unsigned int   independent_runs() const;

    /**
     * Nombre de generations
     * @return int - _nb_evolution_steps
     */
    const unsigned int   nb_evolution_steps() const;

    /**
     * Taille de la population
     * @return int - _population_size
     */
    const unsigned int   population_size() const;


    /**
     * Taille d'un individu
     * @return int - _solution_size
     */
    const unsigned int   solution_size() const;

    // Methodes de modification

    /**
     * Modifie _independent_runs
     * @param [in] val - nouvelle valeur
     */
    void independent_runs(const unsigned int val);

    /**
     * Modifie _nb_evolution_steps
     * @param [in] val - nouvelle valeur
     */
    void nb_evolution_steps(const unsigned int val);

    /**
     * Modifie _population_size
     * @param [in] val - nouvelle valeur
     */
    void population_size(const unsigned int val);


    /**
     * Modifie _solution_size
     * @param [in] val - nouvelle valeur
     */
    void solution_size(const unsigned int val);

    // Methodes de lecture/ecriture

    /**
     * Affiche sur le flot os en parametre
     * @param [in/out] os - flot ostream
     */
    void print(std::ostream& os ) const;

    /**
     * Lit sur le flot is afin de remplir l'objet courant
     * @param [in/out] is -  flot istream
     */
    void read ( std::istream &is);
};


#endif //PROJIA_SETUPPARAMS_H