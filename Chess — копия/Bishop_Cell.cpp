//
//  Bishop_Cell.cpp
//  Chess
//
//  Created by Кирилл Грибанов  on 06.12.2024.
//

#include "Bishop_Cell.h"

BishopCell::BishopCell(Coord coord, Colour colour): Cell(coord), colour_(colour){}

Colour BishopCell::getColour() const {
    return colour_;
}

std::vector<Coord> BishopCell::getReservedSteps() const {
    std::vector<Coord> moves;
    moves.reserve(13);
    
    for(int i = 1; i < 8; ++i) {
        
        if(coord_.row + i < 8 && coord_.col + i < 8) moves.push_back({coord_.row + i, coord_. col + i});
        
        if(coord_.row >= i && coord_.col  >= i) moves.push_back({coord_.row - i, coord_.col - i});
        
        if(coord_.col + i < 8  && coord_.row >= i) moves.push_back({coord_.row - i, coord_. col + i});
        
        if(coord_.col >= i  && coord_.row + i < 8) moves.push_back({coord_.row + i, coord_.col - i});
    }
    return moves;
}

std::vector<Coord> BishopCell::getHits() const {
    return getReservedSteps();
}

const std::string& BishopCell::Name() const {
    return BishopName;
}

char BishopCell::getSymbol() const {
    return (colour_ == Colour::WHITE) ? 'B' : 'b';
}

