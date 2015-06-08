# Roboter-Labyrinth

1.) Compile the program with 'make'
2.) Run with labrob FILENAME_OF_MAZE options

Available options are:
  -t1: Starts robot that always goes left
  -t2: Starts robot that fills all dead ends and then always goes right (has recursisive behaviour for filling dead ends -> not suitable for very big mazes)
  -t3: Starts robot that finds the shortest path on base of a breadth first search
  -h:  Shows usage message and quits
  Any combination of options is possible but -h always ends the program
  
If someone wants to compile this on Windows (for example using mingw w64), POSIX threads are needed and options might need to be specified before entering the filename...
