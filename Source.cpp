//Ja'Den Martin

/*	This is a sample program of a doubly linked linked-list that takes two lists of numbers, 
	merges them, then sorts them.

*/

#include <iostream>

//The Node for the linked list
//Has data parameter x and two pointers next and prev.
struct Node
{
	double x;
	Node* next; //Points to the next node in a list
	Node* prev; //Points the previous node in a list

	//Pre: A newly defined node with no parameters
	//Post:	Node will be initialized with default values
	Node()
	{
		x = 0;
		next = nullptr;
		prev = nullptr;
	}

	//Pre: A newly defined node with parameters
	//Post:	Node will be intitlized to specified values
	Node(double a)
	{
		x = a;
		next = nullptr;
		prev = nullptr;
	}

	//Deconstructor
	~Node()
	{
		next = nullptr;
		prev = nullptr;
		delete[] next;
		delete[] prev;
	}

	//Pre: A statement to output the data of type Node.
	//Post: Data will outputted in the format below
	friend std::ostream& operator << (std::ostream& output, Node* number)
	{
		output << number->x;
		return output;
	}
};

//Linked List Class. Has a default constructor and standard constructors.
//Has functions to sort, display, and insert nodes.
class LinkedList
{
public:

	//Default constructor. Assigns the head node as Empty
	LinkedList()
	{
		head = nullptr;
		tail = nullptr;
	}

	//Deconstructor
	~LinkedList()
	{
		head = nullptr;
		tail = nullptr;
		delete[] head;
		delete[] tail;
	}

	//Pre: A newly created node
	//Post: The list will be formed by assigning the head to a new node
	void insertNode(double x)
	{
		Node* numberList = new Node{ x };

		if (head == nullptr) //Points head to the first node
		{
			head = numberList;
			return;
		}

		Node* temp = head; //Points to head

		while (temp->next != nullptr) //Iterates through the list while assigning next and prev to the appropiate nodes
		{
			numberList->prev = temp;
			temp = temp->next;//Iterates to the end of the list	
			
		}

		temp->next = numberList; //Inserts the newest node at the end of the list
		numberList->prev = temp; //Points the last node to its previous node
		tail = numberList;		//Sets the tail at the end of the list
	}

		//Pre: A linked list with defined nodes
		//Post: Will display the data within the nodes.
		void display()
		{
			Node* temp1 = head;
			Node* temp2 = tail;

			while (temp1 != nullptr)
			{
				std::cout << temp1 << ' ';

				temp1 = temp1->next;
			}

			std::cout << std::endl;
		}

		//Pre: A linked list with defined nodes
		//Post: Will display the data within the nodes, but in reverse
		void displayReverse()
		{
			Node* temp2 = tail;

			while (temp2 != nullptr)
			{
				std::cout << temp2 << ' ';

				temp2 = temp2->prev;
			}

			std::cout << std::endl;
		}

		//Pre: Takes in two existing lists
		//Post: Will return a new list that is made by merging the two given lists
		LinkedList merge(LinkedList listOne, LinkedList listTwo)
		{
			LinkedList tempList;
			Node* temp1 = listOne.head;
			Node* temp2 = listTwo.head;
			
			//Iterates through both lists and inserts each of the elements into a new list
			while (temp1 != nullptr && temp2 != nullptr)
			{		
				tempList.insertNode(temp1->x);
				tempList.insertNode(temp2->x);
				
				temp1 = temp1->next;
				temp2 = temp2->next;
			}
			
			return tempList;
		}

		//Pre: Will take in an unsorted list
		//Post: Will iterate through a list and compare each node to nodes further in the list
		//		checking if they are greater than the current spot. If so, the nodes will swap data.
		void sort()
		{
			Node* temp1 = head;
			Node* temp2 = head;
			double temp;

				while (temp1 != nullptr) //Iterates through list ine
				{
					temp2 = temp1->next; //Sets temp2 to be the next node in the list

					while (temp2 != nullptr)  //Iterates through the list with a new starting point each iteration
					{
						//Iterates through the entire list, checking if a node is less than any other node in the list
						if (temp1->x > temp2->x)
						{
							//Swaps data between the nodes.
							temp = temp2->x;
							temp2->x = temp1->x;
							temp1->x = temp;
						}

						temp2 = temp2->next; //Updates list to the next node, continuing till the end of the list
					}
					
					//Will iterate through each element, going to the next node when no more nodes 
					//after it are greater than the current node
					temp1 = temp1->next;
				}		
		}

private:

	Node* head;
	Node* tail;

};

int main()
{
	LinkedList allNumbers;
	LinkedList listOne;
	LinkedList listTwo;
	
	double y;
	double z;

	//Creates list one
	for (int i = 0; i < 5; i++)
	{
		std::cout << "Input a number" << std::endl;
		std::cin >> y;
		listOne.insertNode(y);
	}

	std::cout << std::endl;
	listOne.display();

	//Creates list two
	for (int i = 0; i < 5; i++)
	{
		std::cout << "Input a number" << std::endl;
		std::cin >> z;
		listTwo.insertNode(z);
	}

	std::cout << std::endl;
	listTwo.display();

	//Creates a list by merging two existing lists
	allNumbers = allNumbers.merge(listOne, listTwo);

	std::cout << "After Merge & Before Sort: ";
	allNumbers.display();
	std::cout << std::endl;

	//Sorts the new list
	allNumbers.sort();

	std::cout << "After Merge & After Sort: ";
	allNumbers.display();
	std::cout << std::endl;

	std::cout << "Sorted List Reversed: ";
	allNumbers.displayReverse();

	return 0;

}