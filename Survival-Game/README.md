In this program, I created a "survival" game where the user controls a character wandering through a world searching for food and water while trying to avoid danger. 
The world will be represented by a polymorphic 2d array where each element contains a pointer to a "land" base class. 
The land base class will be a pure virtual class which will provide an interface for various derived land types, such as a forest, desert, lake, etc. 
The user will be represented by a player class which tracks the player's position within the world and levels of thirst and hunger.
