# Group 54 - Keith Sarkar, Rajvir Parmar, Eseosa Atekha, Toluwanimi Popoola
# SmashTheMole

SmashTheMole is a Whac-A-Mole style game built in C++ using SFML 2.x. It features:
- A start menu with a custom background.
- Gameplay with a separate background image.
- Targets (moles and bombs) that appear on a grid.
- A custom cursor (whacker) replacing the system mouse cursor.
- Dynamic scoring and a countdown timer.

## Directory Structure

Assuming your files are organized as follows:

SmashTheMole/ ├── main.cpp ├── Game.cpp ├── Game.h ├── Menu.cpp ├── Menu.h ├── Target.cpp ├── Target.h ├── Makefile ├── arial.ttf ├── mole.png ├── bomb.png ├── menu_background.jpg ├── background.jpeg ├── whacker.png └── README.md

ll asset files (font and images) are in the project’s root directory.



## Building the Game on macOS

### Prerequisites

- A C++17 compliant compiler (e.g., g++ or clang++).
- SFML 2.x (Recommended version: SFML 2.6.2).  
  Install via Homebrew (sfml@2):
  - brew install sfml@2

1. Open Terminal and navigate to your project directory:

cd /path/to/SmashTheMole


2. Build the game by running:

make


3. Run the game:

./SmashTheMole




## Building the Game on Windows

### Prerequisites

- A C++17 compliant compiler (e.g., Visual Studio or MinGW).

- SFML 2.x (download from SFML's website).

### Setting Up Your Project
- Create a new project in your IDE (e.g., Visual Studio).
 
- Add all source files (main.cpp, Game.cpp, Game.h, Menu.cpp, Menu.h, Target.cpp, Target.h) to your project.

### Configure your project to:

- Include the SFML 2.x include directory.

- Link against the SFML libraries (sfml-graphics, sfml-window, sfml-system).

- Copy all asset files (arial.ttf, mole.png, bomb.png, menu_background.jpg, background.jpeg, whacker.png) into your project’s working directory (typically the same folder as the executable).

- Build and run your project according to your IDE’s instructions.

