READ THIS FILE BEFORE YOU USE THE PROGRAM
-------------------------------------------------------------------------------------------------------------

Introduction:
	
	This program is to create a Binary Search Tree and visit every path from root to leaf node. In each
node, there are two data in it, one is the data, and the other one is the number of coins. After visiting 
every path, the program determine the total number of coins collected durint the path. Then find out the route
that collect most coin in the tree. After that, print out the path that collect the most coin. 	

-------------------------------------------------------------------------------------------------------------

Solving Logic:
	
	By using the structure of Binary Tree and combine the comparison before insertion. The first integer
inserted into the tree is "root", and then the numbers belowed are going to compare before insertion. On the 
left hand side of the root, the number of every node is smaller than the root node. And on the other side are
greater. 
	
	While processing the input, I decided to scan a sentence once a time and the use a functino called 
"getWord" to seperate the words and special characters. After that, using function "atoi()" to transfer the
word into numbers, so the data type would be character array into integer. And the second number represents
the number of coin in the node.

	By the end of processing the input data, then use the function "BSTinsert()" to create the Tree.

	While finding the path, I decided to use recursive function to visit from root to leaf node. When 
reaching the leaf node, the record the path and the coin collected in the path. If the total coin collected 
in the path is equal to or greater than the max coin, then save the path. Each path is stored in an integer
array, but I decided to change them into string. So I use a function "sprintf()" to transform the data type.

	After that, print out the path that collect the most number of coin and the number of max coin. 

	By this way, I can satisfy the requirement of the assignment.
	
-------------------------------------------------------------------------------------------------------------

Input:

	10,2\n	<----- '\n' represent the new line symbol
	5,1\n
	7,2\n
	6,1\n
	2,4\n            
	17,2\n
	1,1\n
	13,2\n
	9,1\n
	15,2\n
	00      <----- end of input

-------------------------------------------------------------------------------------------------------------

Output:

	Trajectory 1: 10 5 2 1
	Trajectory 2: 10 5 7 6
	Trajectory 3: 10 17 13 15
	Coins: 11
	
-------------------------------------------------------------------------------------------------------------

Contact us

If you have any question about the program, contack me by e-mial address below.

Name:Yu Hung Kung
ID:408410046
DEPARTMENT:Department of Computer Science and Information Engineering
EMAIL ADDRESS:yuhongg374@gmail.com

-------------------------------------------------------------------------------------------------------------