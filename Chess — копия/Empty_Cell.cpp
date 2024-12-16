//
//  Cell_File.h
//  Chess
//
//  Created by Кирилл Грибанов  on 06.12.2024.
//

#include "Empty_Cell.h"

Colour EmptyCell::getColour() const {
    return Colour::WHITE;
}

std::vector<Coord> EmptyCell::getReservedSteps() const{
    return {};
}

std::vector<Coord> EmptyCell::getHits() const {
    return {};
}

const std::string& EmptyCell::Name() const {
    return EmptyName;
}

char EmptyCell::getSymbol() const {
    return Symbol;
}

