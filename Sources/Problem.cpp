#include "../Headers/Problem.h"


Problem::Problem() : _dimension(20), _idBenchmarks(0)
{}

Problem::Problem(int dimension, int idBenchmark) : _dimension(dimension), _idBenchmarks(idBenchmark)
{
    switch(_idBenchmarks)
    {
        // Rosenbrock
        case 1 :    LowerLimit = -2.0;
                    UpperLimit = 2.0;
                    break;

        // Rastrigin
        case 2 :    LowerLimit = -5.12;
                    UpperLimit = 5.12;
                    break;

        // Ackley
        case 3 :    LowerLimit = -5.0;
                    UpperLimit = 5.0;
                    break;

        // Schwefel
        case 4 :    LowerLimit = -500.0;
                    UpperLimit = 500.0;
                    break;

        // Schaffer
        case 5 :    LowerLimit = -100.0;
                    UpperLimit = 100.0;
                    break;

        // Weierstrass
        case 6 :    LowerLimit = -2.0;
                    UpperLimit = 2.0;
                    break;
        default: break;
    }
}

Problem::~Problem()
{

}

Problem& Problem::operator=(const Problem& pbm)
{
    _dimension = pbm._dimension;
    _idBenchmarks = pbm._idBenchmarks;
    return *this;
}

bool Problem::operator==(const Problem& pbm) const
{
    return _dimension == pbm._dimension && _idBenchmarks == pbm._idBenchmarks;
}

bool Problem::operator!=(const Problem& pbm) const
{
    return ! (_dimension == pbm._dimension && _idBenchmarks == pbm._idBenchmarks);
}

int Problem::dimension() const
{
    return _dimension;
}

int Problem::idBenchmark() const
{
    return _idBenchmarks;
}

void Problem::changerDimension(int dimension)
{
    _dimension = dimension;
}

void Problem::changerIdBenchmark(int idBenchmark)
{
    _idBenchmarks = idBenchmark;
    switch(_idBenchmarks)
    {
        // Rosenbrock
        case 1 :    LowerLimit = -2.0;
            UpperLimit = 2.0;
            break;

            // Rastrigin
        case 2 :    LowerLimit = -5.12;
            UpperLimit = 5.12;
            break;

            // Ackley
        case 3 :    LowerLimit = -5.0;
            UpperLimit = 5.0;
            break;

            // Schwefel
        case 4 :    LowerLimit = -500.0;
            UpperLimit = 500.0;
            break;

            // Schaffer
        case 5 :    LowerLimit = -100.0;
            UpperLimit = 100.0;
            break;

            // Weierstrass
        case 6 :    LowerLimit = -2.0;
            UpperLimit = 2.0;
            break;
        default: break;
    }
}
