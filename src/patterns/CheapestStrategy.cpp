#include "../include/patterns/CheapestStrategy.h"
#include "../include/people/Person.h"

int CheapestStrategy::choose(
    const Person& p,
    const std::vector<std::shared_ptr<TransportMode>>& options) {

    int bestIdx = -1;
    int bestPrice = -1;

    for (std::size_t i = 0; i < options.size(); ++i) {
        if (!options[i]->hasRoom() || options[i]->getTicketPrice() > p.getBudget()) continue;

        int price = options[i]->getTicketPrice();
        if (bestIdx == -1 || price < bestPrice) {
            bestIdx = static_cast<int>(i);
            bestPrice = price;
        }
    }
    return bestIdx;
}