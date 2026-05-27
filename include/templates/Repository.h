#ifndef TRANSITTYCOON_REPOSITORY_H
#define TRANSITTYCOON_REPOSITORY_H

#pragma once

#include <algorithm>
#include <concepts>
#include <iostream>
#include <memory>
#include <vector>

template <typename T>
concept Printable = requires(std::ostream& os, const T& t) {
    { os << t } -> std::same_as<std::ostream&>;
};

template <typename T>
class Repository {
    std::vector<T> items;

public:
    void add(T item) { items.push_back(std::move(item)); }

    void clear() { items.clear(); }

    std::size_t size() const { return items.size(); }

    bool empty() const { return items.empty(); }

    T& at(std::size_t i) { return items.at(i); }
    const T& at(std::size_t i) const { return items.at(i); }

    const std::vector<T>& all() const { return items; }
    std::vector<T>& all() { return items; }

    template <typename Pred>
    void removeIf(Pred predicate) {
        items.erase(
            std::remove_if(items.begin(), items.end(), predicate),
            items.end()
        );
    }

    template <typename Func>
    void forEach(Func f) {
        for (auto& item : items) f(item);
    }

    template <typename Func>
    void forEach(Func f) const {
        for (const auto& item : items) f(item);
    }

    template <typename Pred>
    T* findIf(Pred predicate) {
        for (auto& item : items) {
            if (predicate(item)) return &item;
        }
        return nullptr;
    }
};

template <Printable T>
void printRepository(const Repository<T>& repo, const std::string& title) {
    std::cout << "=== " << title << " (" << repo.size() << ") ===\n";
    repo.forEach([](const T& item) {
        std::cout << "  - " << item << "\n";
    });
}

template <Printable T>
void printRepository(const Repository<std::shared_ptr<T>>& repo,
                      const std::string& title) {
    std::cout << "=== " << title << " (" << repo.size() << ") ===\n";
    repo.forEach([](const std::shared_ptr<T>& ptr) {
        if (ptr) std::cout << "  - " << *ptr << "\n";
    });
}

#endif