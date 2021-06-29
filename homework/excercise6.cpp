#include<memory>
#include <algorithm>
#include <vector>
#include "cargo.hpp"


class Ship {
public:
    void load(std::shared_ptr<Cargo> cargo) {
        auto match_cargo = findMatchCargo(cargo);
        if (match_cargo) {
            *match_cargo += cargo->getAmount();
            return;
        }
        cargo_.push_back(std::move(cargo));
        //cargo(std::move(match_cargo));
        //match_cargo(std::move(cargo));
    }

    void unload(Cargo* cargo) {
        removeFromStorage(cargo);
    }

    Cargo* findMatchCargo(std::shared_ptr<Cargo> cargo) {
        for (auto el : cargo_) {
            if (el->getName() == "Fruit") {
                if (el->getName() == cargo->getName() &&
                    el->getBasePrice() == cargo->getBasePrice() &&
                   dynamic_cast<Fruit*>(el.get())->getExpiryDate() == dynamic_cast<Fruit*>(cargo.get())->getExpiryDate())
                    return el.get();
            } else if (el->getName() == "Alcohol") {
                if (el->getName() == cargo->getName() &&
                    el->getBasePrice() == cargo->getBasePrice() &&
                    dynamic_cast<Alcohol*>(el.get())->getPercentage() == dynamic_cast<Alcohol*>(cargo.get())->getPercentage())
                    return el.get();
            } else {
                if (el->getName() == cargo->getName() &&
                    el->getBasePrice() == cargo->getBasePrice() &&
                    dynamic_cast<Item*>(el.get())->getRarity() == dynamic_cast<Item*>(cargo.get())->getRarity())
                    return el.get();
            }
        }
    }

    void removeFromStorage(Cargo* cargo) {
        cargo_.erase(std::find_if(std::begin(cargo_), std::end(cargo_),
                                  [&](const auto& el) {
                                      return *el == *cargo;
                                  }));
    }
private:
    std::vector<std::shared_ptr<Cargo>>cargo_{};
};