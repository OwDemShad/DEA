#include "../Headers/MyAlgorithm.h"
#include <time.h>
#include <stdlib.h>
#include <vector>
#include <cfloat>
#include <cmath>

MyAlgorithm::MyAlgorithm(const Problem &pbm, const SetUpParams &setup ) : _solutions(setup.population_size()), _setup(setup), _fitnessPop(std::vector<double>(setup.population_size(),DBL_MAX))
{
    for (int i = 0; i < setup.population_size() ; ++i)
    {
        _solutions[i] = new Solution(pbm);
    }

}

const SetUpParams &MyAlgorithm::setup() const
{
    return _setup;
}


void MyAlgorithm::initialize()
{
    for (int i = 0; i < _setup.population_size(); ++i)
    {
        _solutions[i]->initialize();
    }
}

void MyAlgorithm::evaluate()
{
    for (int i = 0 ; i < _setup.population_size() ; ++i)
    {
        _fitnessPop[i] = _solutions[i]->fitness();
    }
}


const std::vector<Solution *> &MyAlgorithm::solutions() const
{
    return _solutions;
}

Solution &MyAlgorithm::solution(const unsigned int index) const
{
    return *_solutions[index];
}

double MyAlgorithm::fitness(const unsigned int index) const
{
    return _solutions[index]->get_fitness();
}

MyAlgorithm::~MyAlgorithm() {

}

double MyAlgorithm::best_cost() const
{
    double minCost = DBL_MAX;
    double cost;

    for (int i = 0; i < _fitnessPop.size(); i++)
    {
        cost = _fitnessPop[i];
        if ( cost < minCost)
            minCost = cost;
    }

    return minCost;
}

double MyAlgorithm::worst_cost() const
{
    double maxCost = DBL_MIN;
    double cost = 0.0;

    for ( int i = 0 ; i < _fitnessPop.size() ; i++)
    {
        cost = _fitnessPop[i];
        if ( cost > maxCost)
            maxCost = cost;
    }
    return maxCost;
}

Solution& MyAlgorithm::best_solution() const
{
    double bestCost = best_cost();
    int i = 0;
    while ( _fitnessPop[i] != bestCost)
    {
        ++i;
    }
    return  *_solutions[i];

}

Solution &MyAlgorithm::worst_solution() const
{
    double worstCost = best_cost();
    int i = 0;
    while ( _fitnessPop[i] != worstCost)
    {
        ++i;
    }
    return  *_solutions[i];

}

Solution* MyAlgorithm::substractSolutions(Solution &solution1, Solution &solution2)
{
    Solution *newSolution = new Solution(solution1.pbm());
    for (int i = 0; i < _setup.solution_size(); ++i)
    {
        newSolution->solution()[i] = solution1.solution()[i] - solution2.solution()[i];
    }
    return newSolution;
}

Solution* MyAlgorithm::multiplySolutions(Solution *solution1, const double constMutation)
{
    for (int i = 0; i < _setup.solution_size(); ++i)
    {
        solution1->solution()[i] = solution1->solution()[i] * constMutation;
    }
    return solution1;
}

Solution* MyAlgorithm::additionSolutions(Solution &solution1, Solution *solution2)
{
    //Solution newSolution{solution1.pbm()};
    Solution *newSolution = new Solution(solution1.pbm());

    for (int i = 0; i < _setup.solution_size(); ++i)
    {
        newSolution->solution()[i] = solution1.solution()[i] + solution2->solution()[i];
    }
    return newSolution;
}



int MyAlgorithm::indexBestSolution() const
{
    double bestFitness = best_cost();
    int i = 0;
    while( _fitnessPop[i] != bestFitness )
    {
        ++i;
    }
    return  i;
}

std::vector<int> MyAlgorithm::randomParentSelector(int bestSolution, int populationSize, int sizeVector){
    std::vector<int>  populationIndex ; // vecteur qui va attibuer un "id" aux solutions
    std::vector<int> parents; // vecteur qui va contenir l'indice des solutions qui vont etre tirees
    populationIndex.reserve(populationSize);
    parents.reserve(sizeVector);
    if (sizeVector != 0)
    {
        int nbRandom = 0;
        for (int i = 0; i < populationSize; i++)
        {
            populationIndex.push_back(i);
        }

        int temporarySize = populationSize;

        parents.push_back(populationIndex[bestSolution]); // ajout de la meilleure solution dans le vecteur
        populationIndex.erase(populationIndex.begin() + bestSolution); // on enleve le meilleur vecteur pour le tirage aleatoire

        temporarySize--;
        while (populationIndex.size() > populationSize - sizeVector)
        {
            nbRandom = rand() % temporarySize;
            parents.push_back(populationIndex[nbRandom]);
            populationIndex.erase(populationIndex.begin() + nbRandom);
            temporarySize--;
        }


    }
    return parents;

}



Solution* MyAlgorithm::mutation(/*Solution &currentSolution*/)
{
    //indexBestSolution fini toujours par renvoyer 0, il faut trouver le probleme
    std::vector <int> selectedSolution = randomParentSelector(indexBestSolution(),_setup.population_size(), 3);
    int indexSolutionA = selectedSolution[0]; // toujours égal à 25 la premiere fois
    int indexSolutionB = selectedSolution[1];
    int indexSolutionC = selectedSolution[2];

    Solution *mutatedSolution = additionSolutions(*_solutions[indexSolutionA], multiplySolutions(substractSolutions(*_solutions[indexSolutionB],*_solutions[indexSolutionC]), _mutationConst));

    return mutatedSolution;
}

Solution* MyAlgorithm::crossover(Solution &currentSolution, Solution *mutatedSolution)
{
//    srand (time(NULL));

    for ( int i = 0; i < _setup.solution_size(); ++i)
    {
        int randomIndex = rand() % (i+1);
        double crossoverRand = (rand() % 100) /100;
        if ((crossoverRand > _crossoverRate) || (randomIndex != i)) // si la proba > a constante ou si l'index aleatoire == index
        {
            mutatedSolution->position(i,currentSolution.position(i)); // la solution mutee prend la valeur de la solution pere
        }
    }

    return mutatedSolution;
}



void MyAlgorithm::selection(Solution *currentSolution, Solution *mutatedSolution, int index)
{
    double currentSolFitness = currentSolution->fitness();
    double mutatedSolFitness = mutatedSolution->fitness();

    if (currentSolFitness > mutatedSolFitness) {
        Solution *tempoS = currentSolution;
        _solutions[index] = mutatedSolution;
        mutatedSolution = tempoS; // mutatedSolution sera efface car il pointe sur le meme element de S qui sera detruit a la fin de la fonction
    }


}



double MyAlgorithm::moyenne() const
{
    double moyenne =0.0;
    for (int i = 0; i < _setup.solution_size(); ++i)
    {
        moyenne += _fitnessPop[i];
    }

    moyenne = moyenne/_setup.solution_size();
    return moyenne;
}



void MyAlgorithm::saveInCsvWithCalcul(std::vector<double> &tabMoyenne) const
{
    double moyCarre = 0.0;
    double varianceMoyenne = 0.0;
    double ecartType = 0.0;

    std::ofstream myfile;
    myfile.open("Moyenne.csv");
    double moyenneExec=0;
    for (int j = 0; j < tabMoyenne.size() ; ++j) {
        myfile << tabMoyenne[j]<< "\n";
        moyenneExec+=tabMoyenne[j];
    }
    moyenneExec=moyenneExec/tabMoyenne.size();

    //Calcul de la variance
    for (int k = 0; k < tabMoyenne.size() ; ++k) {
        moyCarre += pow(tabMoyenne[k],2);
    }
    moyCarre = moyCarre/tabMoyenne.size();

    varianceMoyenne =  moyCarre - pow(moyenneExec,2);

    //Ecart type
    ecartType = sqrt(varianceMoyenne);


    myfile << "\n" << "Fitness Moyenne \n" << moyenneExec << " \n\n Variance de la moyenne \n " << varianceMoyenne << " \n " << "\n Ecart Type " << "\n" << ecartType ;

    myfile.close();

    std::cout << "Variance de la moyenne " << varianceMoyenne << std::endl;
}

void MyAlgorithm::evolution(int iter)
{

    int nbGen = 0;
    int currentStep = 0;
    double bestCost ;
    double bestCostPerRun ;

    double moyenneRun = 0.0;
    double moyenneGen = 0.0;

    double mediane = 0.0;

    std::vector<double> tabMoyenne;


    while (currentStep < iter) // va effectuer les run independants
    {
        initialize();
        evaluate();
        nbGen = 0;
        bestCostPerRun = DBL_MAX;
        bestCost = DBL_MAX;
        while (nbGen < _setup.nb_evolution_steps())
        {

            for (int i = 0; i < _setup.population_size(); ++i)
            {
                double currentSolFit = 0;
                Solution *s = mutation(/*solution(i)*/); // creation de la solution mutee
                crossover(solution(i), s);

                selection(&solution(i), s, i);

                currentSolFit = s->fitness();
                if ( currentSolFit < bestCostPerRun )
                {
                    bestCostPerRun = currentSolFit;
                    if (currentSolFit < bestCost)
                    {
                        bestCost = currentSolFit;
                        std::cout << "Step : " << currentStep << " ; generation : " << nbGen << " ; Best fitness = "
                                  << bestCost << std::endl;
                    }
                }
            }


            evaluate();
            ++nbGen;
        }



        currentStep++;
        tabMoyenne.push_back(bestCost);
    }

    saveInCsvWithCalcul(tabMoyenne);

}
