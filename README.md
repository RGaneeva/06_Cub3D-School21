# CUB_3D

School 21 (Ecole42) 'cub3d' project. 

Score 120/120. Passed 2022/01/27

This project is inspired by the world-famous Wolfenstein 3D game, which
was the first FPS ever. It enable to explore ray-casting. The goal is to
make a dynamic view inside a maze. It is a team project, I made it with other peer from the school.

What is important: here I used MiniLibX - 42(21) school graphical library.  
I have added this library to the repository (for MacOS) - it shoul be installed on machine before using programm. 
https://qst0.github.io/ft_libgfx/man_mlx.html - man mlx

# USAGE

clone this repository

git clone https://github.com/RGaneeva/06_Cub3D-School21.git

!dont't forget to install Minilibx

then

| command | result |
|:----|:----|
| make | compile cub3d project |
| make bonus | compile cub3d with bonuses project |
| make clean | clean .o files |
| make fclean | clean .o and .a files |

Example of using programm:

> make

> ./cub file_name.cub

or

> make bonus

> ./cub map_bonus.cub

Examples of.cub files are in main directory.

# CONTROLS

| key | result |
|:----|:----|
| W A S D LEFT_ARROW RIGHT_ARROW | turn/move |
| M | toggle mouse hook  |
| ESC or "red cross" of window | quit program |

# MAP EDITING

You can also edit the map (.cub files) by yourself considering the following points:

* Map contains 1 for wall, 0 for empty "walkable" space and N/S/W/E for player position (2/3 for opened|closed doors in bonus part)
* The map must be sorrounded by walls(1)
* Also it should have the initial player position and direction (W- west, E- east, N-north, S-south)
* Ceiling (C) and floor (F) colors should be chosen from RGB
* The pictures on the walls can be also chaged: this pictures should be in .xpm format and in texs folder

# BONUSES

In bonus part we realised next featurres: wall collisions, a minimap system, doors which can open (2) and close(3)

# RESOURCES
Bresenham's line algorithm: https://en.wikipedia.org/wiki/Bresenham%27s_line_algorithm

Lode's raycasting walk through by Lode Vandevenne: https://lodev.org/cgtutor/raycasting.html

Ray-Casting Tutorial For Game Development And Other Purposes by F. Permadi: https://permadi.com/1996/05/ray-casting-tutorial-table-of-contents/
