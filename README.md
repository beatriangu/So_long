# So Long

<p align="left">
  <img src="https://github.com/beatriangu/So_long/blob/main/image.png?raw=true" alt="So Long" width="100"/>
</p>


The objective of the So_Long project is to develop a fully functional 2D game using the MinilibX, a simple graphic library provided by 42.It incorporates various game elements, such as map rendering, player movement, collision detection, item collection, and win/lose conditions. By completing this project, you will enhance your understanding of game development concepts and gain practical experience in using the MinilibX library.
Features
Map Rendering So_Long allows you to load and render game maps stored in a specific format, typically a file with a .ber extension. The map consists of different tiles representing walls, paths, collectible items, the player's starting position, and the exit. The MinilibX library provides functions to render graphical elements on the screen, enabling you to display the map with the appropriate textures and colors.
Player Movement
The player can move in four directions: up, down, left, and right, within the bounds of the map. By handling keyboard inputs, you can update the player's position on the screen accordingly. The MinilibX library provides functions to capture key events and perform actions based on the pressed keys.
Collision Detection
To ensure the player doesn't move through walls or outside the boundaries of the map, collision detection is implemented. The game checks if the player's desired movement will result in a collision with a wall or if the player has reached the exit. If a collision is detected, the player's movement is restricted.
Item Collection
Throughout the map, there may be collectible items that the player can interact with. When the player reaches a tile containing an item, it is collected, and the player's score is incremented. This feature adds an additional layer of gameplay and encourages exploration.
Win/Lose Conditions
The win condition is achieved when the player successfully reaches the exit tile. In contrast, the lose condition can be triggered by specific events, such as colliding with enemies or running out of lives. Implementing win and lose conditions adds a sense of challenge and completion to the game.
Installation
To install and run the So_Long project, follow these steps:
Clone the project repository:

		git clone https://github.com/your_username/42-so_long.git
Navigate to the project directory:

				cd 42-so_long
Compile the project using the provided Makefile:

				make
Run the game executable:

			./so_long maps/map1.ber
   
   ![image](https://github.com/user-attachments/assets/abab43f6-44ba-4da3-a8bc-74f15cc56fd2)


Make sure you have the MinilibX library installed on your system. If it's not already installed, you can find the library and installation instructions in the project repository.

Testing
To test the game and validate its functionality, follow these steps:

Game


Launch the game using the installation steps mentioned above. Navigate through the map using the arrow keys or WASD keys. Ensure the player can move freely within the map and is restricted by walls and boundaries. Collect items on the map and verify that the score is updated accordingly. Reach the exit tile and confirm that the game ends with a win condition. Trigger any lose conditions (if implemented) and verify that the game ends accordingly. Test various edge cases, such as reaching invalid tiles or unexpected input, to ensure the game handles them gracefully. During testing, monitor the game's performance, responsiveness, and adherence to the specified game rules. Make adjustments and improvements as necessary to enhance the gameplay experience.

![image](https://github.com/user-attachments/assets/203b16a9-c864-40a5-ae53-f09e6071390a)

<p align="left">
  <img src="https://github.com/beatriangu/Libft/blob/main/100.png?raw=true" alt="100.png" width="150"/>
</p>

