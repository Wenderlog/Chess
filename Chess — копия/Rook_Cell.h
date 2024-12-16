//
//  Rook_Cell.h
//  Chess
//
//  Created by Кирилл Грибанов  on 06.12.2024.
//

#pragma once
#include "Cell.h"
#include <algorithm>

constexpr std::string RookName = "Rook";

/*!
 \class RookCell
 \brief Represents a rook piece on a chessboard cell.
 \details The rook is a chess piece that can move across the board only vertically or horizontally until it reaches the edge of the board or encounters another piece.
 This class inherits from the base `Cell` class and provides methods to get the rook's available moves, attacked cells, and its name.
 */
class RookCell : public Cell {
public:
    /*!
     \brief Constructor to create a rook object.
     \param coord The rook's coordinates on the board.
     \param colour The color of the rook (white or black).
     */
    RookCell(Coord coord, Colour colour);

    /*!
     \brief Returns the color of the rook.
     \return The color of the rook as a `Colour` enumeration.
     */
    Colour getColour() const override;

    /*!
     \brief Retrieves the list of cells attacked by the rook.
     \return A vector of coordinates representing the cells under attack by the rook.
     */
    std::vector<Coord> getHits() const override;

    /*!
     \brief Retrieves the list of valid moves for the rook.
     \return A vector of coordinates representing the cells the rook can move to.
     */
    std::vector<Coord> getReservedSteps() const override;

    /*!
     \brief Returns the name of the piece.
     \details For this class, it always returns "Rook".
     \return The name of the piece as a string.
     */
    const std::string& Name() const override;

    /*!
     \brief Returns the symbol representing the rook on the board.
     \details The symbol depends on the color: 'R' for a white rook and 'r' for a black rook.
     \return The character symbol for the rook.
     */
    char getSymbol() const override;

    /*!
     \brief Checks if the rook has moved.
     \return `true` if the rook has moved; otherwise, `false`.
     */
    bool hasMoved() const;

    /*!
     \brief Marks the rook as having moved.
     \details Sets the internal flag `hasMoved_` to `true`.
     */
    void markMoved();
    
protected:
    Colour colour_; ///< The color of the rook (white or black).
    bool hasMoved_ = false; ///< A flag indicating whether the rook has moved.
};
