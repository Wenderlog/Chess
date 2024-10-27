//
//  Table_of_Chess.hpp
//  Chess
//
//  Created by Кирилл Грибанов  on 12.10.2024.
//

#pragma once

#include "Figure.hpp"
#include <memory>


class Table {
private:
    std::vector<std::vector<std::shared_ptr<Cell>>> body_;
    
    bool w_king_moves_;
    bool b_king_moves_;
    
    bool wl_rook_moves_;
    bool wr_rook_moves_;
    bool bl_rook_moves_;
    bool br_rook_moves_;
    
    bool last_move_is_w_pawn;
    bool last_move_is_b_pawn;
    
    Coord coord_w_pawn;
    Coord coord_b_pawn;
    
public:
    std::vector<std::shared_ptr<Cell>>& operator[] (size_t i);
    const std::vector<std::shared_ptr<Cell>>& operator[] (size_t i) const;
    std::vector<Coord> RealOpportunitiesToStrike(Coord) const;
    Table();
    
};


