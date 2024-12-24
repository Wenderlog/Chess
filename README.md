# Chess

This is a chess game implementation in C++ that simulates a standard chessboard, handles moves, checks for game states (such as checkmate, stalemate), and allows interaction through a command-line interface. The game follows standard chess rules and includes features like piece movement, castling, pawn promotion, and turn management.

## Features

- **Chessboard Representation**: An 8x8 grid representing the chessboard with pieces.
- **Move Validation**: Ensures that moves follow the rules of chess (e.g., piece-specific movement, checks, checkmates).
- **Game States**: Checks for check, checkmate, stalemate, and draw conditions.
- **Turn Management**: Alternates between white and black players.
- **Pawn Promotion**: Allows pawns to be promoted to any other piece.
- **Castling**: Supports castling moves.
- **Input Handling**: Accepts algebraic notation for moves (e.g., "e2 e4", "O-O" for castling).

## Installation

1. Clone the repository:
   ```bash
   git clone https://github.com/yourusername/Chess.git
   
2.	Navigate to the project directory:
   ```bash
    cd Chess - копия
```
3. Compile the project:
   ```bash
   g++ -o chess Bishop_Cell.cpp Bishop_Cell.h Cell.cpp Cell.h Chess Chess.xcodeproj Empty_Cell.cpp Empty_Cell.h Game.cpp Game.h html King_Cell.cpp King_Cell.h Knight_Cell.cpp Knight_Cell.h latex Manager.cpp Manager.h Pawn_Cell.cpp Pawn_Cell.h Queen_Cell.cpp Queen_Cell.h Rook_Cell.cpp Rook_Cell.h Table.cpp Table.h
   ```
4.	Run the game:
```bash
./chess
```

- **Usage**: When prompted, input your moves in algebraic notation (e.g., “e2 e4” for moving a pawn). Type exit to end the game. NB!!! The pieces for White are placed at the top (row 1-2), and the pieces for Black are placed at the bottom (row 7-8) of the board.

## Classes and Structure

- **Table**

Represents the chessboard and manages the state of the game. It includes methods to handle piece placement, move validation, and the overall game state, such as checking for checkmate, stalemate, and draw conditions. The Table class uses a 2D array to store the positions of the pieces on the board and provides methods to interact with the board, such as moving pieces and generating the current board state.

- **Game**

Handles the game logic, including move validation, checkmate, and draw conditions. It interacts with the Table class to execute moves and evaluate game states. The Game class tracks the game’s progress, ensuring that the rules are followed, and provides methods for starting, ending, and managing the game flow.

- **Manager**

A utility class for managing and interpreting chess moves and coordinates. It helps convert algebraic notation into board coordinates and assists with input validation. The Manager class processes user input, checks for valid moves, and updates the game state accordingly.

- **Chess Pieces**

Each piece in chess has its own movement rules. The following classes represent the chess pieces:
	•	Pawn: Moves forward one square, but captures diagonally. On its first move, it can move two squares forward. When a pawn reaches the opponent’s back rank, it can be promoted to any other piece (except a king).
	•	Rook: Moves horizontally or vertically any number of squares. It is involved in castling with the king.
	•	Knight: Moves in an “L” shape: two squares in one direction and then one square perpendicular to that. Knights can jump over other pieces.
	•	Bishop: Moves diagonally any number of squares. Each bishop is restricted to one color (light or dark squares) for the entire game.
	•	Queen: Combines the movement of both the rook and bishop, moving horizontally, vertically, or diagonally any number of squares.
	•	King: Moves one square in any direction. The king is also involved in castling with the rook. The game ends if the king is checkmated.

## Contributing

If you’d like to contribute to this project, feel free to fork the repository, make changes, and submit a pull request. Please ensure that your code follows the existing style and includes appropriate tests.

## License

This project is licensed under the MIT License - see the LICENSE file for details.





