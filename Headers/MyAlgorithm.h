#ifndef PROJIA_MYALGORITHM_H
#define PROJIA_MYALGORITHM_H

#include <iostream>
#include <fstream>
#include <cmath>
#include <vector>
#include "Solution.h"
#include "SetUpParams.h"


static double _mutationConst = 0.9;
static double _crossoverRate = 0.1;


class Problem;

class MyAlgorithm {
private:
    /**
     * Soustraction des valeurs de deux individus dans une nouvelle solution
     * @param [in] solution1 - Premier individus
     * @param [in] solution2  - deuxieme individus
     * @return Solution - retourne la nouvelle solution creee
     */
    Solution* substractSolutions(Solution &solution1, Solution& solution2);


    /**
     * Multiplication des valeurs d'un individus avec une constante
     * @param [in] solution1 - Premier individus
     * @param [in] constMutation  - deuxieme individus
     * @return Solution - Solution1 modifie suite a la multiplication
     */
    Solution* multiplySolutions(Solution *solution1, const double constMutation);


    /**
     * Addition des valeurs de deux individus
     * @param [in] solution1 - Premier individus
     * @param [in] solution2  - deuxieme individus
     * @return Solution - retourne la nouvelle solution creee
     */
    Solution* additionSolutions(Solution &solution1, Solution* solution2);

    /**
     * Vecteur d'individus
     */
    std::vector<Solution*> _solutions;     // individuals in population

    /**
     * Parametres de l'algorithme
     */
    const SetUpParams& _setup;

    /**
     * Indice de la plus grande et de la plus petite fitness parmi la population
     */
    unsigned int _upper_cost,_lower_cost; // lower and upper fitness of individuals in population

    /**
     * Vecteur de fitness de la population
     */
    std::vector<double> _fitnessPop; // fitness des individus de la population, la fitness de l'individus i est en index


public:
    /**
     * Contructeur de myAlgorithm
     * @param [in] pbm - benchmark
     * @param [in] setup - parametre
     * @param [in] moyenne
     */
    MyAlgorithm(const Problem& pbm,const SetUpParams& setup);


    /**
     * destructeur de myAlgorithm
     */
    ~MyAlgorithm();


    /**
     * retourn les parametres de l'algo
     * @return les parametres de la class SetUpParam
     */
    const SetUpParams& setup() const;


    /**
     * Initialisation de l'algo en initialisant tous les individus
     */
    void initialize();



    // creates a array with fitness of all solutions in MyAlgorithm and its position in the MyAlgorithm
    /**
     * Fonction qui va evaluer la fitness de tous les individus de la population
     */
    void evaluate();

    /**
     * Fonction qui retourne l'individus en indice i
     * @param [in] i - indice de l'individus souhaite
     * @return - l'individus a indice i
     */
    Solution& solution(const unsigned int index) const;




    /**
     * Retourne la fitness du meilleur individus
     * @return double - fitness de l'individus
     */
    double best_cost() const;


    /**
     * Retourne la fitness du pire individus
     * @return double - fitness de l'individus
     */
    double worst_cost() const;


    /**
     * Retourne l'individus qui a la meilleure fitness
     * @return Solution - le meilleur individus
     */
    Solution& best_solution() const;


    /**
     * Retourne l'individus qui a la pire fitness
     * @return  Solution - le pire individus
     */
    Solution& worst_solution() const;


    /**
     * retourne l'indice du meilleur individus
     * @return int - indice de la meilleure solution
     */
    int indexBestSolution() const;


    /**
     * Selectionne 2 individus au hasard et le meilleur individus
     * @param [in] bestSolution - indice du meilleur individus
     * @param [in] populationSize - taille de la population
     * @param [in] sizeVector - nombre d'individus a selectionner
     * @return vector - vecteur contenant les indices des solutions selectionnees
     */
    std::vector<int> randomParentSelector(int bestSolution, int populationSize, int sizeVector);


    /**
     * Retourne un individus mutee
     * @param currentSolution
     * @return Solution - l'individus mutee cree a partir de 3 autres solutions
     */
    Solution* mutation();


    /**
     * La fonction va croisé les deux solutions et retourner la solution croisee
     * @param currentSolution
     * @param mutatedSolution
     * @return Solution - la nouvelle solution issue du croisement
     */
    Solution* crossover(Solution &currentSolution, Solution *mutatedSolution);


    /**
     * Fonction qui va selectionner la meilleur solution apres avoir compare leur fitness
     * @param [in] currentSolution - la solution pere
     * @param [in] mutatedSolution - la solution mutee
     * @param [in] index - l'indice de la solution pere
     */
    void selection(Solution *currentSolution, Solution *mutatedSolution, int index);


    /**
     * Fonction qui calcul la moyenne et la retourne
     * @return double - la moyenne
     */
    double moyenne() const;


    /**
     * Fonction qui va faire tourner l'algo un nombre iter de fois
     * @param iter - nombre de run a effectuer
     */
    void evolution(int iter); /*makes an evolution step*/




    /**
     * Retourne la fitness d'un individus à l'indice <index>
     * @param [in] index - indice de l'individus souhaite
     * @return double - fitness de l'individus
     */
    double fitness(const unsigned int index) const;

    /**
     * Sauvegarder la moyenne des bestFitness de chaque run dans un fichier csv cree
     * dans la methode
     * Calcule la variance et l'ecart-type total aussi
     * @param [in] tabMoyenne - tableau dans lequel sont renseignees
     */
    void saveInCsvWithCalcul(std::vector<double> &tabMoyenne) const;


    unsigned int upper_cost() const;
    const std::vector<Solution*>& solutions() const;
    unsigned int lower_cost() const;


};


#endif //PROJIA_MYALGORITHM_H