//
//  Table_of_Chess.cpp
//  Chess
//
//  Created by Кирилл Грибанов  on 12.10.2024.
//

#include "Table_of_Chess.hpp"


std::vector<std::shared_ptr<Cell>>& Table::operator[] (size_t i) {
    return body_[i];
}

const std::vector<std::shared_ptr<Cell>>& Table::operator[] (size_t i) const {
    return body_[i];
}

/*std::vector<Coord> Table::RealOpportunitiesToStrike(Coord) const{
    //Поставить настоящие поля для удара ( пример: Ладья не бьет дальше черной фигуры если она белая)
    
}*/

Table::Table(): body_(8, std::vector<std::shared_ptr<Cell>> (8)),

w_king_moves_ (false),
b_king_moves_ (false),

wl_rook_moves_ (false),
wr_rook_moves_ (false),
bl_rook_moves_ (false),
br_rook_moves_ (false),

last_move_is_w_pawn (false),
last_move_is_b_pawn (false),

coord_w_pawn ({0,0}),
coord_b_pawn ({0,0})    {
    
    body_[0][4].reset(new KingCell( {0,4}, Colour::WHITE));
    body_[0][3].reset(new QueenCell({0,3}, Colour::WHITE));
    body_[0][2].reset(new BishopCell({0,2}, Colour::WHITE));
    body_[0][1].reset(new KnightCell({0,1}, Colour::WHITE));
    body_[0][0].reset(new RookCell ({0,0}, Colour::WHITE));
    body_[0][7].reset(new RookCell ({0,7}, Colour::WHITE));
    body_[0][6].reset(new KnightCell({0,6}, Colour::WHITE));
    body_[0][5].reset(new BishopCell({0,5}, Colour::WHITE));
    for(int i = 0; i < 8; ++i){
        body_[1][i].reset(new PawnCell({1,i}, Colour::WHITE));
    }
    
    body_[7][4].reset(new KingCell( {7,4}, Colour::BLACK));
    body_[7][3].reset(new QueenCell({7,3}, Colour::BLACK));
    body_[7][2].reset(new BishopCell({7,2}, Colour::BLACK));
    body_[7][1].reset(new KnightCell({7,1}, Colour::BLACK));
    body_[7][0].reset(new RookCell ({7,0}, Colour::BLACK));
    body_[7][7].reset(new RookCell ({7,7}, Colour::BLACK));
    body_[7][6].reset(new KnightCell({7,6}, Colour::BLACK));
    body_[7][5].reset(new BishopCell({7,5}, Colour::BLACK));
    for(int i = 0; i < 8; ++i){
        body_[6][i].reset(new PawnCell({6,i}, Colour::BLACK));
    }
    
    
}

