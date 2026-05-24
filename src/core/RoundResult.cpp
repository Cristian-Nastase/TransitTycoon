#include "core/RoundResult.h"

std::ostream& operator<<(std::ostream& os, const RoundResult& r) {
    os << "Runda " << r.roundNumber
       << ": " << r.satisfiedPassengers << "/" << r.totalPassengers
       << " pasageri multumiti, fericire medie "
       << r.averageHappiness << "%, venit " << r.revenue;
    return os;
}