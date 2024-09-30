
# Monopoly Game - Final Project

**Course:** C++ Programming - Ariel University  
**Author:** [Your Name]  
**Date:** [Submission Date]

## Project Overview

This project is a C++ implementation of the classic Monopoly board game, designed for 2 to 8 players.
The game uses the Model-View-Controller (MVC) design pattern and employs the Simple and Fast Multimedia Library (SFML) for the graphical user interface. The implementation adheres to OCP and incorporates core OOP concepts such as polymorphism, inheritance, and design patterns like Factory, State,  Command and MVC.

## Features

- Supports 2 to 8 players in a single game.
- Dynamic game board consisting of properties, utilities, railroads, and special squares.
- Player interactions, including buying properties, paying rent, and managing money.
- A turn-based system controlled by dice rolls, property management, and game rules.
- Uses SFML for graphical display and player interaction.

## Directory Structure

```
/Monopoly
├── src/
│   ├── model/              # Game model components (Board, Player, Property, etc.)
│   │   ├── Board.cpp/.hpp
│   │   ├── Player.cpp/.hpp
│   │   ├── Square.cpp/.hpp
│   │   ├── Property.cpp/.hpp
│   │   ├── Railroad.cpp/.hpp
│   │   ├── Utility.cpp/.hpp
│   │   ├── Card.cpp/.hpp
│   │   └── GameState.cpp/.hpp
│   ├── view/               # View components (handles the graphical display using SFML)
│   │   ├── BoardView.cpp/.hpp
│   │   ├── PlayerView.cpp/.hpp
│   │   └── SFMLInterface.cpp/.hpp
│   ├── controller/         # Controller components (handles game logic and player interactions)
│   │   ├── GameController.cpp/.hpp
│   │   ├── commands/       # Command pattern implementation for player actions
│   │   │   ├── Command.cpp/.hpp
│   │   │   ├── BuyCommand.cpp/.hpp
│   │   │   ├── MoveCommand.cpp/.hpp
│   │   │   ├── PayRentCommand.cpp/.hpp
│   │   │   └── RollDiceCommand.cpp/.hpp
│   ├── main.cpp            # Main entry point of the program
├── assets/                 # Assets (images, fonts) for the game board and interface
└── CMakeLists.txt          # CMake build script
```

## Building the Project

This project uses CMake as its build system. Ensure that you have SFML installed on your system before building.

1. Clone the repository.
2. Navigate to the project's root directory.
3. Run the following commands to build the project:

   ```bash
   mkdir build
   cd build
   cmake ..
   make
   ```

## Running the Game

After building the project, an executable will be created in the `build` directory. Run the executable to start the game:

```bash
./MonopolyGame
```

## Dependencies

- **SFML**: The game uses the Simple and Fast Multimedia Library (SFML) for graphical rendering and user interaction. Make sure to install SFML on your system. You can find installation instructions [here](https://www.sfml-dev.org/download.php).

## How to Play

- Players take turns rolling the dice and moving around the board.
- Depending on where a player lands, they can buy properties, pay rent, or draw cards.
- The game implements classic Monopoly rules, such as property ownership, rent collection, and special squares like "Go to Jail."

## Future Enhancements

- Add support for trading properties between players.
- Implement more complex game rules, such as mortgages and auctions.
- Enhance the graphical interface for a more immersive experience.

---

Feel free to customize the README with your name, date, and any other information specific to your project.
