//
//  Figure.cpp
//  Chess
//
//  Created by Кирилл Грибанов  on 08.10.2024.
//

#include "Figure.hpp"

PawnCell::PawnCell(Coord coord, Colour colour): Cell(coord), colour_(colour){}

Colour PawnCell::getColour() const{
    return Colour::white;
}

std::vector<Coord> PawnCell::getHits() const{
    std::vector<Coord> Hits;
    size_t direction = (colour_ == Colour::white) ? 1 : -1;
    
    if(coord_.row == 2 && colour_ == Colour::white) {
        Hits.push_back({coord_.row + 2*direction, coord_.col});
    }
    
    if(coord_.row == 7 && colour_ == Colour::black) {
        Hits.push_back({coord_.row + 2*direction, coord_.col});
    }
    Hits.push_back({coord_.row + direction, coord_.col});
    Hits.push_back({coord_.row + direction, coord_.col - 1});
    Hits.push_back({coord_.row + direction, coord_.col + 1});
    return Hits;
}

std::string PawnCell::Name() const{
    return "Pawn";
}

RookCell::RookCell(Coord coord, Colour colour): Cell(coord), colour_(colour){}

Colour RookCell::getColour() const{
    return Colour::white;
}

std::vector<Coord> RookCell::getHits() const{
    std::vector<Coord> Hits;
    for(int i = 1; i < 8; ++i){
        Hits.push_back({coord_.row + i, coord_.col});
        Hits.push_back({coord_.row - i, coord_.col});
        Hits.push_back({coord_.row, coord_.col + i});
        Hits.push_back({coord_.row, coord_.col - i});

    }
    return Hits;
}

std::string RookCell::Name() const{
    return "Rock";
}

KnightCell::KnightCell(Coord coord, Colour colour): Cell(coord), colour_(colour){}

Colour KnightCell::getColour() const{
    return Colour::white;
}

std::vector<Coord> KnightCell::getHits() const{
    return {
        {coord_.row + 2, coord_.col + 1},
        {coord_.row + 2, coord_.col - 1},
        {coord_.row - 2, coord_.col - 1},
        {coord_.row - 2, coord_.col + 1},
        {coord_.row - 1, coord_.col + 2},
        {coord_.row - 1, coord_.col - 2},
        {coord_.row + 1, coord_.col - 2},
        {coord_.row + 1, coord_.col + 2}
    };
}

std::string KnightCell::Name() const{
    return "Knight";
}

BishopCell::BishopCell(Coord coord, Colour colour): Cell(coord), colour_(colour){}

Colour BishopCell::getColour() const{
    return Colour::white;
}

std::vector<Coord> BishopCell::getHits() const{
    std::vector<Coord> Hits;
    for(int i = 1; i < 8; ++i){
        Hits.push_back({coord_.row + i, coord_.col + i});
        Hits.push_back({coord_.row - i, coord_.col + i});
        Hits.push_back({coord_.row + i, coord_.col - i});
        Hits.push_back({coord_.row - i, coord_.col - i});

    }
    return Hits;
}

std::string BishopCell::Name() const{
    return "Bishop";
}

KingCell::KingCell(Coord coord, Colour colour): Cell(coord), colour_(colour){}

Colour KingCell::getColour() const{
    return Colour::white;
}

std::vector<Coord> KingCell::getHits() const{
    return{
        {coord_.row + 1, coord_.col},
        {coord_.row - 1, coord_.col},
        {coord_.row, coord_.col + 1},
        {coord_.row, coord_.col - 1},
        {coord_.row + 1, coord_.col + 1},
        {coord_.row - 1, coord_.col - 1},
        {coord_.row + 1, coord_.col - 1},
        {coord_.row - 1, coord_.col + 1},
    };
}

std::string KingCell::Name() const{
    return "King";
}

QueenCell::QueenCell(Coord coord, Colour colour): Cell(coord), colour_(colour){}

Colour QueenCell::getColour() const{
    return Colour::white;
}

std::vector<Coord> QueenCell::getHits() const{
    std::vector<Coord> Hits;
    for(int i = 1; i < 8; ++i){
        Hits.push_back({coord_.row + i, coord_.col + i});
        Hits.push_back({coord_.row - i, coord_.col + i});
        Hits.push_back({coord_.row + i, coord_.col - i});
        Hits.push_back({coord_.row - i, coord_.col - i});
        Hits.push_back({coord_.row + i, coord_.col});
        Hits.push_back({coord_.row - i, coord_.col});
        Hits.push_back({coord_.row, coord_.col + i});
        Hits.push_back({coord_.row, coord_.col - i});

    }
    return Hits;
}

std::string QueenCell::Name() const{
    return "Queen";
}


