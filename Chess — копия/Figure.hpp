//
//  Figure.hpp
//  Chess
//
//  Created by Кирилл Грибанов  on 08.10.2024.
//

#pragma once

#include "Table.hpp"

class PawnCell : public Cell {
private:
    PawnCell(Coord coord, Colour colour);
    Colour getColour() const override;
    std::vector<Coord> getHits() const override;
    std::string Name() const override;
    Colour colour_;
};

class RookCell : public Cell {
private:
    RookCell(Coord coord, Colour colour);
    Colour getColour() const override;
    std::vector<Coord> getHits() const override;
    std::string Name() const override;
    Colour colour_;
};

class KnightCell : public Cell {
private:
    KnightCell(Coord coord, Colour colour);
    Colour getColour() const override;
    std::vector<Coord> getHits() const override;
    std::string Name() const override;
    Colour colour_;
};

class BishopCell : public Cell {
private:
    BishopCell(Coord coord, Colour colour);
    Colour getColour() const override;
    std::vector<Coord> getHits() const override;
    std::string Name() const override;
    Colour colour_;
};

class KingCell : public Cell {
private:
    KingCell(Coord coord, Colour colour);
    Colour getColour() const override;
    std::vector<Coord> getHits() const override;
    std::string Name() const override;
    Colour colour_;
};

class QueenCell : public Cell {
private:
    QueenCell(Coord coord, Colour colour);
    Colour getColour() const override;
    std::vector<Coord> getHits() const override;
    std::string Name() const override;
    Colour colour_;
};



