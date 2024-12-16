//
//  Knight_Cell.cpp
//  Chess
//
//  Created by Кирилл Грибанов  on 06.12.2024.
//

#include "Knight_Cell.h"

KnightCell::KnightCell(Coord coord, Colour colour): Cell(coord), colour_(colour){}

Colour KnightCell::getColour() const {
    return colour_;
}

std::vector<Coord> KnightCell::getReservedSteps() const {
    std::vector<Coord> moves;
    moves.reserve(8);
    
    int drows[] = {-2, -2, -1, -1, 1, 1, 2, 2};
    int dcols[] = {-1, 1, -2 , 2, -2, 2, 1, -1};
    
    for(int i = 0; i < 8; ++i){
        int new_row = coord_.row + drows[i];
        int new_col = coord_.col + dcols[i];
        if(new_row >= 0 && new_row < 8 && new_col >= 0 && new_col < 8)
            moves.push_back({coord_.row, coord_.col});
    }
    return moves;
}

std::vector<Coord> KnightCell::getHits() const {
    return getReservedSteps();
}

const std::string& KnightCell::Name() const {
    return KnightName;
}

char KnightCell::getSymbol() const {
    return (colour_ == Colour::WHITE) ? 'N' : 'n';
}
