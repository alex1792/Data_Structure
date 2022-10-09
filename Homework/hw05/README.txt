READ THIS FILE BEFORE YOU USE THE PROGRAM
-------------------------------------------------------------------------------------------------------------

Introduction:
	
	This program is use to find the best place to hold a party between friends. We can see each person as
a vertex, and between every two vertices, there exist at most one edges. Also, each edge has its own cost. The
program is to find the best vertex that the other vertices have the least cost to reach the specific vertex. 

-------------------------------------------------------------------------------------------------------------

Solving Logic:
	
	Firstly, I scan two integers from input, which represent the number of vertices and edges. If both two
integers are '0', then the program terminate. Second, the program inputs the name of every vertex and the edges.
	
	I create a adjacency matrix to represent the relationships between vertices. If two vertices are 
connected, then the value of adjacency matrix (i, j) is the cost of the edge.

		
	By using "Dijkstra Algorithm", the program keep updating the shortest path from every vertex to the 
target vertex. I use a 1-D array called "state" to record that whether the vertex has been chosen. If so, the
value of state would be '1'. Untill every vertex were chosen, the integer "sum" is the total cost of every vertex
to the target vertex.
	
	After that, I let every vertex as the target vertex in dijkstra function. By doing so, I can have every
total cost so that I can find the least cost in them.

	By this way, I can satisfy the requirement of the assignment.
	
-------------------------------------------------------------------------------------------------------------

Input:

	4 5\n	<----- '\n' represent the new line symbol
	a\n     <----- every name of vertex are less than 20 characters
	b\n
	c\n
	d\n            
	1 2 1\n
	1 3 1\n
	1 4 5\n
	2 3 1\n
	2 4 1\n
	3 4 1\n
	4 3\n
	tim\n
	jack\n
	rick\n
	jeff\n
	1 2 10\n
	1 3 5\n
	1 4 6\n
	0 0\0      <----- end of input

-------------------------------------------------------------------------------------------------------------

Output:

	Case #1 c\n
	Case #2 tim\0
	
-------------------------------------------------------------------------------------------------------------

Contact us

If you have any question about the program, contack me by e-mial address below.

Name:Yu Hung Kung
ID:408410046
DEPARTMENT:Department of Computer Science and Information Engineering
EMAIL ADDRESS:yuhongg374@gmail.com

-------------------------------------------------------------------------------------------------------------