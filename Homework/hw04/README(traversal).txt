READ THIS FILE BEFORE YOU USE THE PROGRAM
-------------------------------------------------------------------------------------------------------------

Introduction:
	
	This program is to create a Binary Search Tree and use 2 different method of traversal to print out
the tree. The two traversal are "Inorder Traversal" and "Level Order Traversal".	

-------------------------------------------------------------------------------------------------------------

Solving Logic:
	
	By using the structure of Binary Tree and combine the comparison before insertion. The first integer
inserted into the tree is "root", and then the numbers belowed are going to compare before insertion. On the 
left hand side of the root, the number of every node is smaller than the root node. And on the other side are
greater. 
	
While processing the input, I decided to scan a sentence once a time and the use a functino called 
"getWord" to seperate the words and special characters. After that, using function "atoi()" to transfer the
word into numbers, so the data type would be character array into integer.

	By the end of processing the input data, then use the function "BSTinsert()" to create the Tree.

	Function "inOrderTraversal()", the method I use is recursive function. By using it, I can visit the
left leaf node and then print it out, then return to the root node of sub tree and print out, after that just
visit the right child and output. The precedence of "inOrderTraversal()": left_child > node > right_child.

	Function "levelOrderTraversal()", the idea I use is using the "queue" data structure. First enqueue
the root node, then use a pointer "tmp" pointed to the front of the queue. After that, the program print out
the data saved in tmp. Lastly, check tmp's children, if tmp's left child is not NULL, then enqueue it.
Likewise, if tmp's right child is not NULL, then enqueue it. Lastaly, while queue is not empty, the keep doing
the same thing.

	By this way, I can satisfy the requirement of the assignment.
	
-------------------------------------------------------------------------------------------------------------

Input:

	10\n	<----- '\n' represent the new line symbol
	5\n
	7\n
	6\n
	2\n
	17\n
	1\n
	13\n
	9\n
	15\n
	00      <----- end of input

-------------------------------------------------------------------------------------------------------------

Output:

	Infixorder: 1 2 5 6 7 9 10 13 15 17\n
	Levelorder: 10 5 17 2 7 13 1 6 9 15
	
-------------------------------------------------------------------------------------------------------------

Contact us

If you have any question about the program, contack me by e-mial address below.

Name:Yu Hung Kung
ID:408410046
DEPARTMENT:Department of Computer Science and Information Engineering
EMAIL ADDRESS:yuhongg374@gmail.com

-------------------------------------------------------------------------------------------------------------