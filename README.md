---------i fixed the bugs you can pass first paragraph----------
i am developing a basic snakegame that works on command line but it's not working properly, and it has some fps problems.
the game rewriting entire screen for every game circle even not changed areas and thats why game looks horrible. but i have an idea to fix this.
i'll use gotoxy function which can move coursur anywhere in the screen, to write only changed characters in the screen.
---------how to play------------
you can play game with a,s,d,w keys
w for going up
s for going down
a for going left
d for going right
--------how to adjust game area---------
you change xcoord and ycoord values where on top of the source code, to fit game area to your individual screen i setted them 168 to 50 for my laptop.
-------warning for mac and linux users----------
this code may not be compile in linux or mac computers because of windows.h header file
