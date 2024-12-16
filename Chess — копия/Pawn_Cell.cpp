//
//  Pawn_Cell.cpp
//  Chess
//
//  Created by Кирилл Грибанов  on 06.12.2024.
//

#include "Pawn_Cell.h"

PawnCell::PawnCell(Coord coord, Colour colour): Cell(coord), colour_(colour){}

Colour PawnCell::getColour() const {
    return colour_;
}

std::vector<Coord> PawnCell::getHits() const {
    std::vector<Coord> Hits;
    if (colour_ == Colour::BLACK) {
        if(coord_.row > 0 && coord_.col > 0){
            Hits.push_back({coord_.row - 1, coord_.col - 1});
        }
        if(coord_.row > 0 && coord_.col < 7) {
            Hits.push_back({coord_.row - 1, coord_.col + 1});
        }
    }
    else {
        if(coord_.row < 7 && coord_.col > 0){
            Hits.push_back({coord_.row + 1, coord_.col - 1});
        }
        if(coord_.row < 7 && coord_.col < 7) {
            Hits.push_back({coord_.row + 1, coord_.col + 1});
        }
    }
    return Hits;
}

std::vector<Coord> PawnCell::getReservedSteps() const{
    std::vector<Coord> moves;
    
    if (colour_ == Colour::BLACK) {
        if(coord_.row > 0){
            moves.push_back({coord_.row - 1, coord_.col});
        }
        if(coord_.row == 6) {
            moves.push_back({coord_.row - 2, coord_.col});
        }
    }
    else {
        if(coord_.row < 7){
            moves.push_back({coord_.row + 1, coord_.col});
        }
        if(coord_.row == 1) {
            moves.push_back({coord_.row + 2, coord_.col});
        }
    }
    return moves;
}

const std::string& PawnCell::Name() const {
    return PawnName;
}

char PawnCell::getSymbol() const {
    return (colour_ == Colour::WHITE) ? 'P' : 'p';
}
