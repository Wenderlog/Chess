//
//  Table.cpp
//  Chess
//
//  Created by Кирилл Грибанов  on 05.10.2024.
//

#include "Table.hpp"

Cell::Cell(Coord coord): coord_(coord){}

Colour EmptyCell::getColour() const{
    return Colour::WHITE;
}

std::vector<Coord> EmptyCell::getHits() const{
    return {};
}

std::string EmptyCell::Name() const{
    return "EMPTY";
}


