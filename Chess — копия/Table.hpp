//
//  Table.hpp
//  Chess
//
//  Created by Кирилл Грибанов  on 05.10.2024.
//

#pragma once

#include <string>
#include <cstddef>
#include <vector>

enum class Colour {
    black,
    white
};

struct Coord {
    size_t row;
    size_t col;
};

/*! \brief Cell base class
 *   Full description
 */
class Cell {
public:
    virtual Colour getColour() const = 0;
    virtual ~Cell() = default;
    virtual std::vector<Coord> getHits() const = 0;
    virtual std::string Name() const = 0;
    Cell(Coord coord);
    
protected:
    Coord coord_;
};

class EmptyCell : public Cell {
public:
    Colour getColour() const override;
    std::vector<Coord> getHits() const override;
    std::string Name() const override;
};

class PawnCell : public Cell {
private:
    Colour getColour() const override;
    std::vector<Coord> getHits() const override;
    std::string Name() const override;
};

class TableChess{};
//Наследование, методы для различных фигур (стоим и хотим ударить, вывести координаты возможных ударов)
//Добавить комментарии к интерфейсным методам
//Standart Doxygen
