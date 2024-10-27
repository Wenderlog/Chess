//
//  Figure.hpp
//  Chess
//
//  Created by Кирилл Грибанов  on 08.10.2024.
//

#pragma once

#include <string>
#include <cstddef>
#include <vector>
#include <memory>

/*! \brief enum class Colour
 *   This class was created to separate white and black pieces in the game "Chess".
 */

enum class Colour {
    BLACK,
    WHITE
};

/*! \brief enum struct Coord
 *   Created colored squares in chess
 */

struct Coord {
    int row = 8;
    int col = 8;
};

/*! \brief Cell base class
 *  Supports the basic functions of a regular cell in chess
 */

class Cell {
public:
    virtual Colour getColour() const = 0;///< The method was created to obtain chess board squares
    Cell(Coord coord); ///< The Cell constructor and deconstructor have been created with parameters of the Coord type for further implementation of board coordinates>
    virtual ~Cell() = default;
    virtual std::vector<Coord> getHits() const = 0; ///< Displays a vector of possible impacts
    virtual std::vector<Coord> getReservedSteps() const = 0; ///< The method calculates possible moves of the figure
    virtual std::string Name() const = 0; ///< Name( )  :Created for assigning a name to a figure
    virtual Cell* Copy() const = 0; ///< Created to copy a cell but so far not used anywhere in the code
    
protected:
    Coord coord_; ///< The coordinates are protected so they should be visible to other figures but not changeable.
};

/*! \brief EmptyCell class
 *   Inherits from the Cell class and implements abstract methods to obtain
 cell color, available moves and cell name.
 */

class EmptyCell : public Cell {
public:
    Colour getColour() const override; ///< Similar to the same method in the Pawn class
    std::vector<Coord> getHits() const override; ///< Similar to the same method in the Pawn class
    std::string Name() const override; ///< Similar to the same method in the Pawn class
    Cell* Copy() const override; ///< Similar to the same method in the Pawn class
};

/*!
 * \classPawnCell
 * \details
 *  A class representing a pawn cell on a chessboard.
 * Inherits from the Cell class and implements methods to get the cell's color, the pawn's
 * available moves, and its name.
 */

class PawnCell : public Cell {
public:
    
    /*! \brief Function PawnCell( )
     Constructor for the PawnCell class.
     Initializes the cell with the coordinates and color of the pawn.
    */
    
    PawnCell(Coord coord, Colour colour);
    
    /*! \brief Function getColour( )
    * Return the color of the pawn.
    * Overrides the getColour method of the base Cell class.
    */
    
    Colour getColour() const override;
    
    /*! \brief Function getHits( )
     * Returns a vector of cells under attack by the pawn.
     * Determines the cells that the pawn can attack based on its
     * color and current position.
     * \return std::vector<Coord> Vector of coordinates of the cells under attack.
     */
    
    std::vector<Coord> getHits() const override;
    
    /*! \brief Function Name() :
     *  Returns the name of the piece.
     *
     * Overrides the Name method of the base Cell class, returning the name of the piece "Pawn".
     *
     * \return std::string The name of the piece.
     */
    
    std::string Name() const override;
    
    /*! \brief Funcrtion getReservedSteps( )
     *  Returns the vector of possible pawn moves.
     * Determines the possible moves of the pawn given its color and position on the board,
     * including a double move at the initial position.
     *
     * \return std::vector<Coord> Vector of possible moves.
     */
    
    std::vector<Coord> getReservedSteps() const override;
    
    /*! \brief Function Copy( ):
     * Overriding the copy method for a pawn
     */
    Cell* Copy() const override;
    
protected:
    Colour colour_;
};

/*!
 \brief class RookCell representing a rook piece on a chessboard cell.
 \details
 The rook is a chess piece that can move across the board only vertically or horizontally until it reaches the end of the board or encounters another piece.This class inherits from the base class Cell and provides methods to obtain the available moves of the rook, attacked cells, and its name.
 */

class RookCell : public Cell {
public:
    RookCell(Coord coord, Colour colour); ///< Similar to the same method in the Pawn class
    Colour getColour() const override; ///< Similar to the same method in the Pawn class
    std::vector<Coord> getHits() const override; ///< Similar to the same method in the Pawn class
    std::vector<Coord> getReservedSteps() const override; ///< Similar to the same method in the Pawn class
    std::string Name() const override; ///< Similar to the same method in the Pawn class
    Cell* Copy() const override; ///< Similar to the same method in the Pawn class
protected:
    Colour colour_; ///< Similar to the same method in the Pawn class
};

/*! \brief Class KnightCell representing a knight piece on a chessboard cell.
 
 details The knight is a unique chess piece that moves in an "L" shape,
 moving two squares in one direction (vertical or horizontal) and one square
 perpendicular to that direction. This class inherits from the base class Cell
 and provides methods to obtain the knight's moves, attacked cells, and its name.
 
 */

class KnightCell : public Cell {
public:
    KnightCell(Coord coord, Colour colour); ///< Similar to the same method in the Pawn class
    Colour getColour() const override; ///< Similar to the same method in the Pawn class
    std::vector<Coord> getHits() const override; ///< Similar to the same method in the Pawn class
    std::vector<Coord> getReservedSteps() const override; ///< Similar to the same method in the Pawn class
    std::string Name() const override; ///< Similar to the same method in the Pawn class
    Cell* Copy() const override; ///< Similar to the same method in the Pawn class
protected:
    Colour colour_; ///< Similar to the same method in the Pawn class
};

class BishopCell : public Cell {
public:
    BishopCell(Coord coord, Colour colour); ///< Similar to the same method in the Pawn class
    Colour getColour() const override; ///< Similar to the same method in the Pawn class
    std::vector<Coord> getHits() const override; ///< Similar to the same method in the Pawn class
    std::vector<Coord> getReservedSteps() const override; ///< Similar to the same method in the Pawn class
    std::string Name() const override; ///< Similar to the same method in the Pawn class
    Cell* Copy() const override; ///< Similar to the same method in the Pawn class
protected:
    Colour colour_; ///< Similar to the same method in the Pawn class
};

class KingCell : public Cell {
public:
    KingCell(Coord coord, Colour colour); ///< Similar to the same method in the Pawn class
    Colour getColour() const override; ///< Similar to the same method in the Pawn class
    std::vector<Coord> getHits() const override; ///< Similar to the same method in the Pawn class
    std::vector<Coord> getReservedSteps() const override; ///< Similar to the same method in the Pawn class
    std::string Name() const override; ///< Similar to the same method in the Pawn class
    Cell* Copy() const override; ///< Similar to the same method in the Pawn class
protected:
    Colour colour_; ///< Similar to the same method in the Pawn class
};

class QueenCell : public Cell {
public:
    QueenCell(Coord coord, Colour colour); ///< Similar to the same method in the Pawn class
    Colour getColour() const override; ///< Similar to the same method in the Pawn class
    std::vector<Coord> getHits() const override; ///< Similar to the same method in the Pawn class
    std::vector<Coord> getReservedSteps() const override; ///< Similar to the same method in the Pawn class
    std::string Name() const override; ///< Similar to the same method in the Pawn class
    Cell* Copy() const override; ///< Similar to the same method in the Pawn class
protected:
    Colour colour_; ///< Similar to the same method in the Pawn class
};



