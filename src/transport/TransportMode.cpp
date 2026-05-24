#include "transport/TransportMode.h"

TransportMode::TransportMode(std::string name, int capacity, int ticketPrice)
    : name(std::move(name)),
      capacity(capacity),
      currentLoad(0),
      ticketPrice(ticketPrice),
      weatherMultiplier(1.0f) {}

void TransportMode::applyDiscount(float percent) {
    ticketPrice = static_cast<int>(ticketPrice * (1.0f - percent));
    if (ticketPrice < 0) ticketPrice = 0;
}