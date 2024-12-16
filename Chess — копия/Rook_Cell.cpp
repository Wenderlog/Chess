//
//  Rook_Cell.cpp
//  Chess
//
//  Created by Кирилл Грибанов  on 06.12.2024.
//

#include "Rook_Cell.h"

RookCell::RookCell(Coord coord, Colour colour): Cell(coord), colour_(colour){}

Colour RookCell::getColour() const {
    return colour_;
}

std::vector<Coord> RookCell::getReservedSteps() const {
    std::vector<Coord> moves;
    moves.reserve(14);
    
    for(int i = 1; i <= 7; ++i) {
        if(coord_.row + i <= 7) moves.push_back({coord_.row + i, coord_. col});
        if(coord_.row >= i) moves.push_back({coord_.row - i, coord_.col});
        if(coord_.col + i <= 7) moves.push_back({coord_.row, coord_. col + i});
        if(coord_.col >= i) moves.push_back({coord_.row, coord_.col - i});
    }
    return moves;
}

std::vector<Coord> RookCell::getHits() const {
    return getReservedSteps();
}



const std::string& RookCell::Name() const {
    return RookName;
}

char RookCell::getSymbol() const {
    return (colour_ == Colour::WHITE) ? 'R' : 'r';
}

bool RookCell::hasMoved() const {
    return hasMoved_;
}

void RookCell::markMoved() {
    hasMoved_ = true;
}
