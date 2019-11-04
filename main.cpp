#include <iostream>
#include <cfloat>
#include <stdlib.h>
#include <ctime>
#include "Headers/Problem.h"
#include "Headers/SetUpParams.h"
#include "Headers/MyAlgorithm.h"

int main() {

    srand(time(NULL));

    int idBenchmarks;
    std::cout << "Entrer le chiffre correspondant a la fontion souhaite :" << std::endl
              << "1 : Rosenbrock" << std::endl
              << "2 : Rastrigin" << std::endl
              << "3 : Ackley " << std::endl
              << "4 : Schwefel" << std::endl
              << "5 : Schaffer " << std::endl
              << "6 : Weirstrass" << std::endl;
    std::cin >> idBenchmarks;

    Problem pbm (20, idBenchmarks);

    char paramDefault;
    std::cout << "Voulez vous utiliser les parametres par defaut ?" << std::endl
        << "Nombre de run : 30" << std::endl
        << "Nombre de generation : 1666" << std::endl
        << "Taille de la population : 40 "<< std::endl
        << "Taille de l'individus : 20 " << std::endl
        << "Tappez o pour oui ou n pour non " << std::endl;
    std::cin >> paramDefault;

    // Initialisation des parametres par defaut
    SetUpParams params ;
    if ( paramDefault == 'o' )
    {
        params.independent_runs(30);
        params.nb_evolution_steps(1666);
        params.population_size(40);
        params.solution_size(20);
    }
    else
    {
        params.read(std::cin);
    }





    //params.read(std::cin);


    MyAlgorithm myAlgo(pbm, params);
//    myAlgo.initialize();
//    myAlgo.evaluate();


    myAlgo.evolution(params.independent_runs());



    std::cout << "Hello, World!" << std::endl;
    return 0;
}
