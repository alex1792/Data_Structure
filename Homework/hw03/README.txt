READ THIS FILE BEFORE YOU USE THE PROGRAM
-------------------------------------------------------------------------------------------------------------

Introduction:

	This program is to replace the repeted word in a sentence with a number. The number
represents the order of the node in the linked list. Once the word is found in the linked list,
the node must be move to the head of the linked list. Also, the rule of insertion is "insert at head".

-------------------------------------------------------------------------------------------------------------

Rules:

1. The index of linked list starts from 1.
2. Special character can't be inserted into linked list.
3. Case sensitive, such as "Love" and "love" are different.

-------------------------------------------------------------------------------------------------------------
Solving Logic:

	I decided to scan one line each time, and use a function called "getWord" to cut the
sentence into words. Inside the getWord function, there is a condition that I want to determin.
That is whether the character is alphabet or not. By using a pointer "ptr" pointed to the sentence
and keep runing a function called "isAlpha". If the character the pointer pointed to is alphabet,
then copy into the word array.

	After the program get each word in the sentence, then search the word in every node of 
the linked list. If the program found the same word, then print out the index of the node and
adjust the node to the head of the linked list. Otherwise, which means that the word is not found
in the linked list, then creat a new node and add to the head of linked list and print it out.

	At the end of processing every sentence, the program then free the linked list. 

-------------------------------------------------------------------------------------------------------------

Input:

	I love dogs. Dogs love me.
	I have a pen, and pen is good.

-------------------------------------------------------------------------------------------------------------

Output:
	I love dogs. Dogs 3 me.
	I have a pen, and 2 is good.

-------------------------------------------------------------------------------------------------------------
Notice:
	
	For example, the sentence is "I have a pen, and pen is good.", linked list would be like:

	1. I
	2. have -> I
	3. a -> have -> I
	4. pen -> a -> have -> I
	5. and -> pen -> a -> have -> I
	6. pen -> and -> a -> have -> I
	7. is -> pen -> and -> a -> have -> I
	8. good -> is -> pen -> and -> a -> have -> I
index:       1      2     3      4     5      6     7

-------------------------------------------------------------------------------------------------------------

Contact us

If you have any question about the program, contack me by e-mial address below.

Name:Yu Hung Kung
ID:408410046
DEPARTMENT:Department of Computer Science and Information Engineering
EMAIL ADDRESS:yuhongg374@gmail.com

-------------------------------------------------------------------------------------------------------------