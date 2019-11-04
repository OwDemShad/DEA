#include "../Headers/SetUpParams.h"
SetUpParams::SetUpParams() : _independent_runs(0), _nb_evolution_steps(0), _population_size(0),
                             _solution_size(0)
{}

const unsigned int   SetUpParams::independent_runs() const
{
    return _independent_runs;
}

const unsigned int   SetUpParams::nb_evolution_steps() const
{
    return _nb_evolution_steps;
}
const unsigned int    SetUpParams::population_size() const
{
    return _population_size;
}

const unsigned int    SetUpParams::solution_size() const
{
    return _solution_size;
}

void SetUpParams::independent_runs(const unsigned int val)
{
    _independent_runs = val;
}

void SetUpParams::nb_evolution_steps(const unsigned int val)
{
    _nb_evolution_steps = val;
}

void SetUpParams::population_size(const unsigned int val)
{
    _population_size = val;
}

void SetUpParams::solution_size(const unsigned int val)
{
    _solution_size = val;
}

void SetUpParams::print(std::ostream& os) const
{
    os<<'['<<_independent_runs <<','<<  _nb_evolution_steps << ',' << _population_size << ',' << _solution_size << ']';
}

void SetUpParams::read(std::istream& is )
{
    unsigned int indep_runs,nb_evol_steps,popul_size,solut_size;
    std::cout << "Entrer les valeurs pour les differents parametres :" << std::endl
        << "Nombre de run : " << std::endl;
    is >> indep_runs ;

    std::cout << "Nombre d'iteration par run : " << std::endl;
    is >> nb_evol_steps;

    std::cout << "Taille de la population : " << std::endl;
    is >> popul_size;

    std::cout << "Taille de la solution : " << std::endl;
    is >> solut_size;

    _independent_runs = indep_runs;
    _nb_evolution_steps = nb_evol_steps;
    _population_size = popul_size;
    _solution_size = solut_size;
}

SetUpParams::~SetUpParams() {

}
