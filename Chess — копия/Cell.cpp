//
//  Cell_File.cpp
//  Chess
//
//  Created by Кирилл Грибанов  on 06.12.2024.
//

#include "Cell.h"

Cell::Cell(Coord coord): coord_(coord){}

bool Coord::operator==(Coord other) const {
    return row == other.row && col == other.col;
}
