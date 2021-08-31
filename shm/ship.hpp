#pragma once
#include <vector>
#include <algorithm>
#include <iterator>
#include <memory>
#include "cargo.hpp"

/*
    Create Ship class to store Cargos,
    each Player will be used own Ship to buy sell and sail from Island to Island
*/
class Ship {
public:
    Ship();
    Ship(int capacity, int maxCrew, int speed, const std::string& name, size_t id, std::vector<std::shared_ptr<Cargo>> cargo, size_t coins);
    Ship(int maxCrew, int speed, size_t id, std::vector<std::shared_ptr<Cargo>> cargo);

    void setName(const std::string& name) { name_ = name; }
    size_t setCoins(size_t coins) { return coins_ = coins; }
    Ship& operator-=(size_t num);
    Ship& operator+=(size_t num);
    size_t getCapacity() const { return capacity_; }
    size_t getMaxCrew() const { return maxCrew_; }
    size_t getCrew() const { return crew_; }
    size_t getSpeed() const { return speed_; }
    std::string getName() const { return name_; }
    size_t getId() const { return id_; }
    size_t getAmountOfCargosCapacity() const;
    std::vector<std::shared_ptr<Cargo>> getCargo() const { return cargo_; }
    void addAmounntToShipCargo( std::shared_ptr<Cargo>, size_t );
    void dellAmounntFromShipCargo( std::shared_ptr<Cargo>, size_t );
    size_t getCoins() const { return coins_; }
private:
    size_t capacity_;
    size_t maxCrew_;
    size_t crew_;
    size_t speed_;
    std::string name_;
    const size_t id_;
    std::vector<std::shared_ptr<Cargo>> cargo_;
    size_t coins_;
};
