//
//  Figure.cpp
//  Chess
//
//  Created by Кирилл Грибанов  on 08.10.2024.
//

#include "Figure.hpp"

Cell::Cell(Coord coord): coord_(coord){}

Colour EmptyCell::getColour() const {
    return Colour::WHITE;
}

std::vector<Coord> EmptyCell::getHits() const {
    return {};
}

std::string EmptyCell::Name() const {
    return "EMPTY";
}

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
    std::vector<Coord> moves(70); // moves
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

std::string PawnCell::Name() const {
    return "Pawn";
}

RookCell::RookCell(Coord coord, Colour colour): Cell(coord), colour_(colour){}

Colour RookCell::getColour() const {
    return colour_;
}

std::vector<Coord> RookCell::getReservedSteps() const {
    std::vector<Coord> moves(70);
    
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



std::string RookCell::Name() const {
    return "Rook";
}

KnightCell::KnightCell(Coord coord, Colour colour): Cell(coord), colour_(colour){}

Colour KnightCell::getColour() const {
    return colour_;
}

std::vector<Coord> KnightCell::getReservedSteps() const {
    std::vector<Coord> moves(70);
    int drows[] = {-2, -2, -1, -1, 1, 1, 2, 2};
    int dcols[] = {-1, 1, -2 , 2, -2, 2, 1, -1};
    
    for(int i = 0; i <= 7; ++i){
        int new_row = coord_.row + drows[i];
        int new_col = coord_.col + dcols[i];
        if(new_row >= 0 && new_row <=7 && new_col >= 0 && new_col <=7)
            moves.push_back({coord_.row, coord_.col});
    }
    return moves;
}

std::vector<Coord> KnightCell::getHits() const {
    return getReservedSteps();
}

std::string KnightCell::Name() const {
    return "Knight";
}

BishopCell::BishopCell(Coord coord, Colour colour): Cell(coord), colour_(colour){}

Colour BishopCell::getColour() const {
    return colour_;
}

std::vector<Coord> BishopCell::getReservedSteps() const {
    std::vector<Coord> moves(70);
    
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

std::string BishopCell::Name() const {
    return "Bishop";
}

KingCell::KingCell(Coord coord, Colour colour): Cell(coord), colour_(colour){}

Colour KingCell::getColour() const {
    return colour_;
}

std::vector<Coord> KingCell::getReservedSteps() const{
    std::vector<Coord> moves(70);
    for(int drow = -1; drow < 2; ++drow){
        for(int dcol = -1; dcol < 2; ++dcol){
            if(drow == 0 && dcol ==0) continue;
            int new_row = coord_.row + drow;
            int new_col = coord_.col + dcol;
            if(new_row < 8 && new_row >= 0 && new_col < 8 && new_col >= 0){
                moves.push_back({new_row, new_col});
            }
            
        }
    }
    return moves;
}

std::vector<Coord> KingCell::getHits() const {
    return getReservedSteps();
}

std::string KingCell::Name() const {
    return "King";
}

QueenCell::QueenCell(Coord coord, Colour colour): Cell(coord), colour_(colour){}

Colour QueenCell::getColour() const {
    return colour_;
}

std::vector<Coord> QueenCell::getReservedSteps() const {
    std::vector<Coord> moves(140);
    
    for(int i = 1; i <= 7; ++i) {
        if(coord_.row + i <= 7) moves.push_back({coord_.row + i, coord_. col});
        if(coord_.row >= i) moves.push_back({coord_.row - i, coord_.col});
        if(coord_.col + i <= 7) moves.push_back({coord_.row, coord_. col + i});
        if(coord_.col >= i) moves.push_back({coord_.row, coord_.col - i});
    }
    
    
    for(int i = 1; i < 8; ++i) {
        
        if(coord_.row + i < 8 && coord_.col + i < 8) moves.push_back({coord_.row + i, coord_. col + i});
        
        if(coord_.row >= i && coord_.col  >= i) moves.push_back({coord_.row - i, coord_.col - i});
        
        if(coord_.col + i < 8  && coord_.row >= i) moves.push_back({coord_.row - i, coord_. col + i});
        
        if(coord_.col >= i  && coord_.row + i < 8) moves.push_back({coord_.row + i, coord_.col - i});
    }
    return moves;
}

std::vector<Coord> QueenCell::getHits() const {
    return getReservedSteps();
}

std::string QueenCell::Name() const {
    return "Queen";
}


