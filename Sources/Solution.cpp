#include "../Headers/Solution.h"
#include <stdlib.h>
#include <time.h>
#include <math.h>

#define M_PI 3.14159265


Solution::Solution(const Problem& pbm) : _pbm(pbm), _solution(std::vector<double>(pbm.dimension())), _current_fitness(INT_MAX)
{}

Solution::Solution(const Solution& sol) : _pbm(sol._pbm), _solution(sol._solution), _current_fitness(sol._current_fitness)
{}

Solution::~Solution()
{
    delete this;
}

const Problem& Solution::pbm() const
{
    return _pbm;
}

Solution& Solution::operator=(const Solution& sol)
{
    _solution = sol._solution;
    _current_fitness = sol._current_fitness;
    return *this;
}

bool Solution::operator==(const Solution& sol) const
{
    if (_pbm.dimension() != sol._pbm.dimension() || _pbm.idBenchmark() != sol._pbm.idBenchmark() ||
            _solution.size() != sol._solution.size() || _current_fitness != sol.get_fitness() )
        return false;

    for (int i = 0 ; i < _solution.size() ; i++)
    {
        if (_solution[i] != sol._solution[i])
            return false;
    }
    return true;
}

bool Solution::operator!=(const Solution& sol) const
{
    return !(*this == sol);
}

void Solution::initialize()
{
//    srand (time(NULL));
    // A confirmer :
    // attribution de valeur random dans le vector _solution
    // calcul de la fitness du vector _solution --> _currentFitness = fitness() (qui calcule la fitness et la renvoie)
    // initialisation du problem
    int nbVal = (_pbm.UpperLimit*100 - _pbm.LowerLimit*100) +1;
    //std::cout << nbVal;
    for (int i = 0; i < _solution.size() ; ++i)
    {
        //std::cout << rand() %nbVal << std::endl;
        _solution[i] = (rand() % nbVal + _pbm.LowerLimit*100) /100;
//       _solution[i] = 0 ;

    }


}

double Solution::fitness()
{
    // parcours du vector _solution et calcule de la fitness de l'individu
    // renvoie une valeur absolue
    // calcule de la fitness des membres 2 par 2 et faire +=
    _current_fitness = 0;
    double sum1 = 0;
    double sum2 = 0;
    switch (_pbm.idBenchmark())
    {
        // Rosenbrock
        case 1 :
            for ( int i = 0 ; i < _solution.size() -1; i++)
            {
              _current_fitness += 100.0 * pow((_solution[i+1] - pow(_solution[i],2)),2) + pow(1.0 - _solution[i],2);
            }
            break;

        // Rastrigin
        case 2 :
            for ( int i = 0 ; i < _solution.size() ; i++)
            {
                _current_fitness += ( pow(_solution[i],2) - 10.0 * cos(2.0 * M_PI * _solution[i]));
            }
            _current_fitness += 10.0 * _pbm.dimension();
            break;

            // Ackley
        case 3 :

            for (int i = 0; i < _solution.size() ; i++)
            {
                sum1 += pow(_solution[i], 2);
                sum2 += cos(2.0 * M_PI * _solution[i]);
            }
            _current_fitness =  -20.0 * exp((-0.2) * sqrt((1.0/_pbm.dimension()) * sum1) ) - exp( (1.0/_pbm.dimension()) * sum2 ) + 20.0 + exp(1) ;
            break;

            // Schwefel
        case 4 :
            for ( int i = 0 ; i < _solution.size() ; i++)
            {
                _current_fitness -= _solution[i] * sin(sqrt(std::abs(_solution[i])));
            }
            _current_fitness += 418.9829 * _pbm.dimension() ;
            break;

            // Schaffer
        case 5 :
            for ( int i = 0 ; i < _solution.size() -1 ; i++)
            {
                _current_fitness += ( pow ( sin( pow( _solution[i], 2) - pow( _solution[i+1], 2) ), 2) - 0.5) / pow ( (1.0 + 0.001 * ( pow( _solution[i], 2) - pow( _solution[i+1], 2), 2 )) , 2);
            }

            _current_fitness += 0.5;

            break;

        case 6 :
            for ( int i = 0 ; i < _solution.size() ; i++)
            {
                _current_fitness += pow ( 0.5, i ) * cos ( M_PI * 2.0 * pow ( 3.0, i ) * ( _solution[i] + 0.5 )) ;
            }

            break;

        default:
            break;
    }
    return std::abs(_current_fitness);
}

double Solution::get_fitness() const
{
    return _current_fitness;
}

unsigned int Solution::size() const
{
    return _solution.size();
}

std::vector<double>& Solution::solution()
{
    return _solution;
}

double& Solution::position(const int index)
{
    return _solution[index];
}

void Solution::position(const int index, const double value)
{
    _solution[index] = value;
}
