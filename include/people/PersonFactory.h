#ifndef TRANSITTYCOON_PERSONFACTORY_H
#define TRANSITTYCOON_PERSONFACTORY_H

#pragma once

#include "Person.h"
#include <memory>

class PersonFactory {
public:
    static std::shared_ptr<Person> createRandom(int id);

    static std::shared_ptr<Person> createStudent(int id);
    static std::shared_ptr<Person> createBusinessPerson(int id);
    static std::shared_ptr<Person> createTourist(int id);
    static std::shared_ptr<Person> createElderly(int id);
    static std::shared_ptr<Person> createWorker(int id);
    static std::shared_ptr<Person> createAthlete(int id);
};

#endif