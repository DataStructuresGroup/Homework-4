#ifndef __LinkList__Implementation__		// For those using Visual Studio, lets try to avoid LNK2004 errors...
#define __LinkList__Implementation__

#define PlaneSize 80		// Small commercial plane [Boeing?]

#pragma region Inclusions
#include <iostream>			// Input and Output
#include <cstring>			// Used for the 'NULL' keyword, despite that it
							//  is '0' or 'OL', but keep this for convention
							//  sakes.
#include <stdlib.h>			// Used for the rand() function
#include <time.h>			// Used for the srand() funtion
#include "LinkedList.h"		// Implementation for Link List.
#pragma endregion



// Print Passenger List
// ===============================================
// Documentation:
//	This function will output all of the information within the link list.
// -----------------------------------------------
// Parameters:
//	head [Node*]
//		This will take any valid link list.
// ===============================================
inline void Print_Passenger_List(Node* head)
{
	// If head is empty, present an error message and leave this function.
	if (head == NULL)
	{
		std::cout << "<!> ERROR <!>: No entries within the list are present!" << std::endl
			<< "Nothing to print nor report!  Please generate or create a new list." << std::endl;
		return;
	} // if


	// Output the available list with the information required.
	while (head != NULL)
	{
		std::cout << "Passenger ID: " << head->passengerID << std::endl
			<< "Passenger Name: " << head->nameLast << ", " << head->nameFirst << std::endl
			<< "Telephone Number: " << head->telephoneNum << std::endl
			<< "Reservation Number: " << head->reservationNum << std::endl
			<< "Seat on the plane: " << head->seatNum << std::endl
			<< "Preferred Meal Plan: " << head->mealType << std::endl;

		head = head->next;	// Move to the next node
	} // while
} // Print_Passenger_List()



// Insert New Node Entry
// ===============================================
// Documentation:
//	This function will forward the new node (or data) onto
//  the primary link list (or pointer)
// -----------------------------------------------
// Parameters:
//	head [Node]
//		The primary list that is to be updated.
//	NewEntry [Node]
//		New information that is to be merged or imported into the 'head'.
// ===============================================
inline void InsertNode(Node** head, Node* newEntry)
{
	if (*head == NULL)			// if the current list contains no entries
		*head = newEntry;		//  then immediately add the temp entry to the list.
	else
	{
		newEntry->next = *head;	// Import the primary list to the temp entry.
		*head = newEntry;		// Export all of the entries from the temp
								// list to the primary list.
	}
} // InsertNode()



// Create a New Node
// ===============================================
// Documentation:
//	Generate a new entry to be imported into the primary list.
//  This function will merely make sure that all information is
//   present before allowing the new node to be official in the
//   primary list.
// -----------------------------------------------
// Parameters:
//	head [Node]
//		The primary list that will soon include the new node entry.
//  nameFirst [string]
//		Client's first name
//  nameLast [string]
//		Client's last name
//  passengerID [int]
//		Client's Passenger ID
//  reservationNum [int]
//		Client's reservation ID
//  telephoneNum [int]
//		Client's telephone number
//  seatNum [int]
//		Client's seat number
//  mealType [string]
//		Client's requested meal.
// ===============================================
inline void CreateNewNode(Node** head, std::string nameFirst, std::string nameLast, int passengerID, int reservationNum, int telephoneNum, int seatNum, std::string mealType)
{
	// Create a new node to store the new information
	Node* newEntry = new Node;
	

	// Generate the incoming data into the newly created node
	newEntry->nameFirst = nameFirst;
	newEntry->nameLast = nameLast;
	newEntry->passengerID = passengerID;
	newEntry->reservationNum = reservationNum;
	newEntry->telephoneNum = telephoneNum;
	newEntry->seatNum = seatNum;
	newEntry->mealType = mealType;

	newEntry->next = NULL;
	// Import the data into the primary list
	InsertNode(head, newEntry);
} // CreateNewNode()



// Autofill List [Numbers - Dependency]
// ===============================================
// Documentation:
//	This function will provide an easier way to manage
//   randomized numbers for populating the passenger
//	 information.
// -----------------------------------------------
// Parameters:
//	key [int]
//		This will allow us to provide a random number
//		based on what attribute we are requesting.
//		Acceptable Key Values:
//		0 = Passenger ID
//		1 = Reservation Number
//		2 = Telephone Number
// -----------------------------------------------
// Output:
//	Returns a specific, though randomized, integer based on the
//   key used.
// ===============================================
inline int Autofill_List_Numbers(int key)
{
	// Because we want serious randomness in this lousy program!
	srand(time(NULL));

	// Determine the requested type to return
	switch (key)
	{
	case 0:
		// Passenger ID
		return rand() % 9999 + 1;
		break;
	case 1:
		// Reservation Number
		return rand() % 999 + 100;
		break;
	case 2:
		// Telephone Numbers
		return rand() % 8999999999 + 1000000000;
		break;
	default:
		// Error
		return -255;
		break;
	} // switch
} // Autofill_List_Numbers()



// Autofill List [Meal Choice - Dependency]
// ===============================================
// Documentation:
//	This function will provide a randomized choice of
//  the <del>horrible</del> best foods available
//  in Blue-Sky Air Lines!
//
//  The list is inspired by Indiana Jones Temple of Doom
// -----------------------------------------------
// Output:
//	string
//		A randomized string output of the desired
//      food or meal that the passenger is willing
//      order.
// ===============================================
inline std::string Autofill_List_MealChoice()
{
	// Give us more randomness
	srand(time(NULL));

	// Randomly pick a number that will
	// allow us to choose which meal the
	// passenger is going to eat.
	int choice = rand() % 4;

	// Evaluate the choice and return the appropriate value.
	switch (choice)
	{
	case 0:
		return "Monkey Brains";
		break;
	case 1:
		return "Tuna Eyeballs";
		break;
	case 2:
		return "Raw Octopus";
		break;
	case 3:
		return "Fish"; // https://youtu.be/rQbj9uvYL8I
		break;
	default:
		return "Expired Peanuts";
		break;
	} // switch
} // Autofill_List_MealChoice()



// Find Available Seat
// ===============================================
// Documentation:
//	This function will merely provide the next available seat.
// -----------------------------------------------
// Output:
//	Returns the seat ID that is available.
// ===============================================
inline int GetSeatAvailable()
{
	srand(time(NULL));

	return rand() % 100 + 1;
} // GetSeatAvailable()



// Autofill List
// ===============================================
// Documentation:
//	This function will automatically populate and generate a reasonably
//   sized list.
// Notes:
//   I feel like a tool for using 'babynames.com' to populate
//   with random names....
// -----------------------------------------------
// Parameters:
//	head [Node*]
//		This will take any valid link list.
// ===============================================
inline void Autofill_List(Node** head)
{
	// __HARD_CODED__
	// Update this algorithm with caution!
	//---
	// To auto-generate, we are going to throw hard-coded values
	// to the link list.  This will greatly allow us to debug or
	// generally work with the list.
	for (int i = 0; i < 20; i++)
	{
		switch (i)
		{
		case 0:
			CreateNewNode(head,						// primary list
						"Fabian",					// First Name
						"Nadie",					// Last Name
						Autofill_List_Numbers(0),	// Passenger ID
						Autofill_List_Numbers(1),	// Reservation Num
						Autofill_List_Numbers(2),	// Telephone Num
						GetSeatAvailable(),			// Seat Num
						Autofill_List_MealChoice());// Preferred Meal
			break;
		case 1:
			CreateNewNode(head,						// primary list
						"Ganit",					// First Name
						"Ume",						// Last Name
						Autofill_List_Numbers(0),	// Passenger ID
						Autofill_List_Numbers(1),	// Reservation Num
						Autofill_List_Numbers(2),	// Telephone Num
						GetSeatAvailable(),			// Seat Num
						Autofill_List_MealChoice());// Preferred Meal
			break;
		case 2:
			CreateNewNode(head,						// primary list
						"Dan",						// First Name
						"Randi",					// Last Name
						Autofill_List_Numbers(0),	// Passenger ID
						Autofill_List_Numbers(1),	// Reservation Num
						Autofill_List_Numbers(2),	// Telephone Num
						GetSeatAvailable(),			// Seat Num
						Autofill_List_MealChoice());// Preferred Meal
			break;
		case 3:
			CreateNewNode(head,						// primary list
						"Reese",					// First Name
						"Nafisa",					// Last Name
						Autofill_List_Numbers(0),	// Passenger ID
						Autofill_List_Numbers(1),	// Reservation Num
						Autofill_List_Numbers(2),	// Telephone Num
						GetSeatAvailable(),			// Seat Num
						Autofill_List_MealChoice());// Preferred Meal
			break;
		case 4:
			CreateNewNode(head,						// primary list
						"Nina",						// First Name
						"Albany",					// Last Name
						Autofill_List_Numbers(0),	// Passenger ID
						Autofill_List_Numbers(1),	// Reservation Num
						Autofill_List_Numbers(2),	// Telephone Num
						GetSeatAvailable(),			// Seat Num
						Autofill_List_MealChoice());// Preferred Meal
			break;
		case 5:
			CreateNewNode(head,						// primary list
						"Alexis",					// First Name
						"Wayne",					// Last Name
						Autofill_List_Numbers(0),	// Passenger ID
						Autofill_List_Numbers(1),	// Reservation Num
						Autofill_List_Numbers(2),	// Telephone Num
						GetSeatAvailable(),			// Seat Num
						Autofill_List_MealChoice());// Preferred Meal
			break;
		case 6:
			CreateNewNode(head,						// primary list
						"Rani",						// First Name
						"Falcon",					// Last Name
						Autofill_List_Numbers(0),	// Passenger ID
						Autofill_List_Numbers(1),	// Reservation Num
						Autofill_List_Numbers(2),	// Telephone Num
						GetSeatAvailable(),			// Seat Num
						Autofill_List_MealChoice());// Preferred Meal
			break;
		case 7:
			CreateNewNode(head,						// primary list
						"Yasmine",					// First Name
						"Benicia",					// Last Name
						Autofill_List_Numbers(0),	// Passenger ID
						Autofill_List_Numbers(1),	// Reservation Num
						Autofill_List_Numbers(2),	// Telephone Num
						GetSeatAvailable(),			// Seat Num
						Autofill_List_MealChoice());// Preferred Meal
			break;
		case 8:
			CreateNewNode(head,						// primary list
						"Al",						// First Name
						"Bundy",					// Last Name
						Autofill_List_Numbers(0),	// Passenger ID
						Autofill_List_Numbers(1),	// Reservation Num
						Autofill_List_Numbers(2),	// Telephone Num
						GetSeatAvailable(),			// Seat Num
						Autofill_List_MealChoice());// Preferred Meal
			break;
		case 9:
			CreateNewNode(head,						// primary list
						"Janeeva",					// First Name
						"Zaina",					// Last Name
						Autofill_List_Numbers(0),	// Passenger ID
						Autofill_List_Numbers(1),	// Reservation Num
						Autofill_List_Numbers(2),	// Telephone Num
						GetSeatAvailable(),			// Seat Num
						Autofill_List_MealChoice());// Preferred Meal
			break;
		case 10:
			CreateNewNode(head,						// primary list
						"Ofra",						// First Name
						"Sable",					// Last Name
						Autofill_List_Numbers(0),	// Passenger ID
						Autofill_List_Numbers(1),	// Reservation Num
						Autofill_List_Numbers(2),	// Telephone Num
						GetSeatAvailable(),			// Seat Num
						Autofill_List_MealChoice());// Preferred Meal
			break;
		case 11:
			CreateNewNode(head,						// primary list
						"Nadalia",					// First Name
						"Hao",						// Last Name
						Autofill_List_Numbers(0),	// Passenger ID
						Autofill_List_Numbers(1),	// Reservation Num
						Autofill_List_Numbers(2),	// Telephone Num
						GetSeatAvailable(),			// Seat Num
						Autofill_List_MealChoice());// Preferred Meal
			break;
		case 12:
			CreateNewNode(head,						// primary list
						"Hana",						// First Name
						"Starr",					// Last Name
						Autofill_List_Numbers(0),	// Passenger ID
						Autofill_List_Numbers(1),	// Reservation Num
						Autofill_List_Numbers(2),	// Telephone Num
						GetSeatAvailable(),			// Seat Num
						Autofill_List_MealChoice());// Preferred Meal
			break;
		case 13:
			CreateNewNode(head,						// primary list
						"Ashia",					// First Name
						"Bäddan",					// Last Name
						Autofill_List_Numbers(0),	// Passenger ID
						Autofill_List_Numbers(1),	// Reservation Num
						Autofill_List_Numbers(2),	// Telephone Num
						GetSeatAvailable(),			// Seat Num
						Autofill_List_MealChoice());// Preferred Meal
			break;
		case 14:
			CreateNewNode(head,						// primary list
						"Qi",						// First Name
						"Wahponjea",				// Last Name
						Autofill_List_Numbers(0),	// Passenger ID
						Autofill_List_Numbers(1),	// Reservation Num
						Autofill_List_Numbers(2),	// Telephone Num
						GetSeatAvailable(),			// Seat Num
						Autofill_List_MealChoice());// Preferred Meal
			break;
		case 15:
			CreateNewNode(head,						// primary list
						"Hali",						// First Name
						"Eamon",					// Last Name
						Autofill_List_Numbers(0),	// Passenger ID
						Autofill_List_Numbers(1),	// Reservation Num
						Autofill_List_Numbers(2),	// Telephone Num
						GetSeatAvailable(),			// Seat Num
						Autofill_List_MealChoice());// Preferred Meal
			break;
		case 16:
			CreateNewNode(head,						// primary list
						"Tai Yang",					// First Name
						"Taipa",					// Last Name
						Autofill_List_Numbers(0),	// Passenger ID
						Autofill_List_Numbers(1),	// Reservation Num
						Autofill_List_Numbers(2),	// Telephone Num
						GetSeatAvailable(),			// Seat Num
						Autofill_List_MealChoice());// Preferred Meal
			break;
		case 17:
			CreateNewNode(head,						// primary list
						"Achava",					// First Name
						"Nili",						// Last Name
						Autofill_List_Numbers(0),	// Passenger ID
						Autofill_List_Numbers(1),	// Reservation Num
						Autofill_List_Numbers(2),	// Telephone Num
						GetSeatAvailable(),			// Seat Num
						Autofill_List_MealChoice());// Preferred Meal
			break;
		case 18:
			CreateNewNode(head,						// primary list
						"John",						// First Name
						"Hancock",					// Last Name
						Autofill_List_Numbers(0),	// Passenger ID
						Autofill_List_Numbers(1),	// Reservation Num
						Autofill_List_Numbers(2),	// Telephone Num
						GetSeatAvailable(),			// Seat Num
						Autofill_List_MealChoice());// Preferred Meal
			break;
		case 19:
			CreateNewNode(head,						// primary list
						"Theodore",					// First Name
						"Roosevelt",				// Last Name
						Autofill_List_Numbers(0),	// Passenger ID
						Autofill_List_Numbers(1),	// Reservation Num
						Autofill_List_Numbers(2),	// Telephone Num
						GetSeatAvailable(),			// Seat Num
						Autofill_List_MealChoice());// Preferred Meal
			break;
		default: // Easter Egg!
			CreateNewNode(head,						// primary list
						"Jenny",					// First Name
						"Tommy Tutone",				// Last Name
						-919,						// Passenger ID [919 area code ;)]
						-919,						// Reservation Num
						8675309,					// Telephone Num [reference: https://youtu.be/8ou6DDG5e7I ]
						919,						// Seat Num
						"MRE");						// Preferred Meal -  Military acronym for 'Meal Ready to Eat', its horrible.
			break;
		} // switch
	} // for
} // Autofill_List()



// User Input [String]
// ===============================================
// Documentation:
//	This function will allow the user to input a specific string into the program.
// -----------------------------------------------
// Parameters:
//	UsePrompt [bool]
//		If true, this will provide the python'ish prompt.
// -----------------------------------------------
// Output:
//	string
//		Returns a string captured from STDIN.
// ===============================================
inline std::string UserInput_String(bool UsePrompt = true)
{
	std::string userInput;		// Use this to capture the STDIN

	if (UsePrompt)
		std::cout << ">>>>> ";	// The python'ish prompt

	std::cin >> userInput;		// Capture the input

	return userInput;			// Return the value.
} // UserInput_String()



// User Input [Number]
// ===============================================
// Documentation:
//	This function will allow the user to input a specific number into the program.
// -----------------------------------------------
// Parameters:
//	UsePrompt [bool]
//		If true, this will provide the python'ish prompt.
// -----------------------------------------------
// Output:
//	int
//		Returns an int captured from STDIN.
// ===============================================
inline int UserInput_Number(bool UsePrompt = true)
{
	int userInput;				// Use this to capture the STDIN

	if (UsePrompt)
		std::cout << ">>>>> ";	// The python'ish prompt

	std::cin >> userInput;		// Capture the input

	return userInput;			// Return the value.
} // UserInput_Number()



// User Input [Bool]
// ===============================================
// Documentation:
//	This function will allow the user to input a yes or no into the program.
// -----------------------------------------------
// Parameters:
//	UsePrompt [bool]
//		If true, this will provide the python'ish prompt.
// -----------------------------------------------
// Output:
//	bool
//		Returns a bool captured from STDIN.
// ===============================================
inline bool UserInput_Bool(bool UsePrompt = true)
{
	char userInput;				// Use this to capture the STDIN

	if (UsePrompt)
		std::cout << ">>>>> ";	// The python'ish prompt

	std::cin >> userInput;		// Capture the input


	if (tolower(userInput) == 'y') // See if 'Yes' was selected
		return true;		// Yes
	else
		return false;		// No
} // UserInput_Bool()



// Manual Customer Add [Meal Choice]
// ===============================================
// Documentation:
//	I have decided to separate this chunk of code into its own function
//	this way its a bit easier and the parent function is not so bloated.
// -----------------------------------------------
// Output:
//	string
//		Returns the preferred meal choice
// ===============================================
inline std::string ManualCustomerAdd_MealChoice()
{
	// We will use this to store the user's choice and then process it later.
	int userChoice;

	// Provide the inflight meal list:
	std::cout << "Select a number: " << std::endl
		<< " 1) Monkey Brains" << std::endl
		<< " 2) Tuna Eyeballs" << std::endl
		<< " 3) Raw Octopus" << std::endl
		<< " 4) Fish" << std::endl
		<< " 5) Expired Peanuts" << std::endl << std::endl;

	// Prevent bad input; run away protection
	bool badInputCatch;
	do
	{
		// Get the customer's request
		userChoice = UserInput_Number();

		// Process the user's request
		switch (userChoice)
		{
		case 1:					// Monkey Brains
			return "Monkey Brains";
			break;
		case 2:					// Tuna Eyeballs
			return "Tuna Eyeballs";
			break;
		case 3:					// Raw Octopus
			return "Raw Octopus";
			break;
		case 4:					// Fish [Seriously, don't go for the fish! https://youtu.be/rQbj9uvYL8I ]
			return "Fish";
			break;
		case 5:					// Expired Peanuts
			return "Expired Peanuts";
			break;
		default:				// Bad Input
			std::cout << "Incorrect option!" << std::endl;
			badInputCatch = true;
			break;
		} // switch
	} while (badInputCatch);
} // ManualCustomerAdd_MealChoice()



// Manual Customer add
// ===============================================
// Documentation:
//	This will allow the end-user to manually create a new entry within the list.
//	 Capture all fields possible and then run through the importing algorithm.
// -----------------------------------------------
// Parameters:
//	head [Node**]
//		The list in which is to be appended
// ===============================================
inline void ManualCustomerAdd(Node** head)
{
	// Declarations
	// ------------------
	std::string stdinNameFirst;
	std::string stdinNameLast;
	int stdinPhone;
	std::string stdinMealChoice;
	int stdinSeat;
	// ----
	// working variables
	bool cacheBit;
	// ------------------


	// Provide instructions to the user
	std::cout << "Please provide the following information:" << std::endl << std::endl;

	// ----

	// Capture first name:
	std::cout << "First name: ";
	stdinNameFirst = UserInput_String(false);
	std::cout << std::endl;

	// Capture last name:
	std::cout << "Last name: ";
	stdinNameLast = UserInput_String(false);
	std::cout << std::endl;

	// Capture telephone number:
	std::cout << "Telephone number: ";
	stdinPhone = UserInput_Number(false);
	std::cout << std::endl;

	// Capture preferred meal:
	std::cout << "Inflight meal choice: " << std::endl;
	stdinMealChoice = ManualCustomerAdd_MealChoice();
	
	// [optional] Seat
	std::cout << "Preferred seating arrangement? [Y] = Yes | [N] = No" << std::endl;

	// Capture user input for seating preference
	cacheBit = UserInput_Bool();

	if (cacheBit)
	{					// The customer has seating arrangements
		std::cout << "Preferred seating: ";
		stdinSeat = UserInput_Number(false);
	} // if
	else				// Automatically find the next available seat
		stdinSeat = GetSeatAvailable();

	std::cout << std::endl;

	// ----

	// Now that we have the information we need, now lets try to add this new entry into the list!
	CreateNewNode(head,				// primary list
		stdinNameFirst,				// First Name
		stdinNameLast,				// Last Name
		Autofill_List_Numbers(0),	// Passenger ID [919 area code ;)]
		Autofill_List_Numbers(1),	// Reservation Num
		stdinPhone,					// Telephone Num [reference: https://youtu.be/8ou6DDG5e7I ]
		stdinSeat,					// Seat Num
		stdinMealChoice);			// Preferred Meal -  Military acronym for 'Meal Ready to Eat', its horrible.
} // ManualCustomerAdd()



// Search Node Entries
// ===============================================
// Documentation:
//	This is a very important function that will promptly scan the entire list
//	 for a specific key.
//  This function will scan all nodes available, but it will stop at the
//	 first available hit from the scan.  With that, once the scan finds the
//	 key in one of the nodes, this function will NOT continue scanning afterwards.
// -----------------------------------------------
// Methodology:
//	Using both Node types, cur and pre, we will perform the scan as follows:
// | ====== |     | ====== |     | ====== |     | ====== |     | ====== |
// | NODE 1 |     | NODE 2 |     | NODE 3 |     | NODE N |     | NODE N+1
// | ~~~~~~ |     | ~~~~~~ |     | ~~~~~~ |     | ~~~~~~ |     | ~~~~~~ |
// |  DATA  |     |  DATA  |     |  DATA  |     |  DATA  |     |  DATA  |
// | ------ |     | ------ |     | ------ |     | ------ |     | ------ |
// |  NEXT  ----> |  NEXT  ----> |  NEXT  ----> |  NEXT  ----> |  NEXT  ---->
// | ====== |     | ====== |     | ====== |     | ====== |     | ====== |
//    ---            pre             cur             <NOT YET SCANNED>
// Simple Logic:
// Fist scan:
// cur = node 1 || pre = NULL
// Second scan:
// cur = node 2 || pre = node 1
// Third scan:
// cur = node 3 || pre = node 2
// N scan: <general form>
// cur = node N || pre = node N-1
// -----------------------------------------------
// Parameters:
//	cur [Node** - Alterable]
//		Used for processing; holds the search point
//	pre [Node** - Alterable]
//		Used for processing before 'cur'; holds the node right before 'cur' pointer.
//	searchMode [int]
//		Determines how the lists will be scanned within this function.
//		0 = Scan Last name [string]
//		1 = Scan first name [string]
//		2 = Scan passenger ID [int]
//		3 = Scan reservation number [int]
//		4 = Scan telephone number [int]
//		5 = Scan seat number [int]
//	searchKeyString [string]
//		A specific key in a string form used for scanning each node.
//	searchKeyInt [int]
//		A specific key in an int form used for scanning each node.
// -----------------------------------------------
// Output:
//	bool
//		Reports the status if the operation was successful or failed.
//		true = an error occurred
//		false = operation successful
// ===============================================
inline bool Search(Node** cur, Node** pre, int searchMode, std::string searchKeyString = "NA", int searchKeyInt = -255)
{
	// If the cur pointer points to NULL, then there is nothing to scan.
	if (*cur == NULL)
		return false;

	// Scan the node
	while (*cur != NULL)
	{
		// Besides using a nesting conditional statement, we are going to use
		//  a switch statement for simplicity.
		switch (searchMode)
		{
		case 0:		// Scan last name
			if (searchKeyString.compare((*cur)->nameLast) == 0)
									// Equality between the two strings
									// [ http://www.cplusplus.com/reference/string/string/compare/ ]
				return true;
			break;
		case 1:		// Scan first name
			if (searchKeyString.compare((*cur)->nameFirst) == 0)
									// Equality between the two strings
									// [ http://www.cplusplus.com/reference/string/string/compare/ ]
				return true;
			break;
		case 2:		// Scan passenger ID
			if ((*cur)->passengerID == searchKeyInt)
				return true;
			break;
		case 3:		// Scan reservation number
			if ((*cur)->reservationNum == searchKeyInt)
				return true;
			break;
		case 4:		// Scan telephone number
			if ((*cur)->telephoneNum == searchKeyInt)
				return true;
			break;
		case 5:		// Scan seat number
			if ((*cur)->seatNum == searchKeyInt)
				return true;
			break;
		} // switch
		
		// Update the node positions
		*pre = (*cur);				// Update pre to cur's current position.
		*cur = (*cur)->next;		// Shift cur to next position.
	} // while

	// Unable to find a node with that specific key and data.
	return false;
} // Search()



// Find and Print Passenger
// ===============================================
// Documentation:
//  This function will allow the end-user to search for a specific passenger
//  and output the passenger's information on the terminal.
// 
//  This function will depend on several functions:
//	 Search() && Print_Passenger_List() && UserInput_String()
//   UserInput_Number()
// ===============================================
inline void FindPrintPassenger(Node* head)
{
	// Present the user with a menu in which to search by
	std::cout << "Search for Passenger:" << std::endl
		<< "-----------------------" << std::endl
		<< " 1) Last name" << std::endl
		<< " 2) Telephone" << std::endl
		<< " 3) Reservation ID" << std::endl
		<< " 4) Passenger ID" << std::endl
		<< " 5) Seat Number" << std::endl
		<< " 0) Exit" << std::endl
		<< std::endl;
	
	bool badInput;	// Make sure that the input provided from the end-user
					// is valid; run-away protection.
	std::string captureString;
	int captureInt;

	Node* nodeIndex = head;
	Node* nullityNode = NULL;

	do {
		// Capture the user's request and process the request
		switch (UserInput_Number())
		{
		case 1:						// Last name
			// Capture the last name from the end-user
			std::cout << "Enter passenger's last name: ";
			captureString = UserInput_String(false);
			std::cout << std::endl;

			if (Search(&nodeIndex,	// Our list to be scanned and processed.
				&nullityNode,		// Required for the function, but not used.
				0,					// Search by last name
				captureString))		// String to search
			{
				nodeIndex->next = NULL;			// Ignore all nodes after the current node.
				Print_Passenger_List(nodeIndex);// Output the results
			} // if
			else
				std::cout << "Unable to find passenger: " << captureString
				<< std::endl;

			badInput = false;
			break;
		case 2:						// Telephone
			std::cout << "Enter passenger's telephone number: ";
			captureInt >> UserInput_Number(false);
			std::cout << std::endl;

			if (Search(&nodeIndex,	// Our list to be scanned and processed.
				&nullityNode,		// Required for the function, but not used.
				4,					// Search by telephone number
				"NA",				// Default to 'NA' due to standard; unused.
				captureInt))		// integer to search
			{
				nodeIndex->next = NULL;			// Ignore all nodes after the current node.
				Print_Passenger_List(nodeIndex);// Output the results
			} // if
			else
				std::cout << "Unable to find passenger with the telephone number: " << captureInt
				<< std::endl;

			badInput = false;
			break;
		case 3:						// Reservation ID
			std::cout << "Enter passenger's Reservation number: ";
			captureInt = UserInput_Number(false);
			std::cout << std::endl;

			if (Search(&nodeIndex,	// Our list to be scanned and processed.
				&nullityNode,		// Required for the function, but not used.
				3,					// Search by reservation number
				"NA",				// Default to 'NA' due to standard; unused.
				captureInt))		// integer to search
			{
				nodeIndex->next = NULL;			// Ignore all nodes after the current node.
				Print_Passenger_List(nodeIndex);// Output the results
			} // if
			else
				std::cout << "Unable to find passenger with the reservation number: " << captureInt
				<< std::endl;

			badInput = false;
			break;
		case 4:						// Passenger ID
			std::cout << "Enter passenger's Passenger number: ";
			captureInt = UserInput_Number(false);
			std::cout << std::endl;

			if (Search(&nodeIndex,	// Our list to be scanned and processed.
				&nullityNode,		// Required for the function, but not used.
				2,					// Search by passenger number
				"NA",				// Default to 'NA' due to standard; unused.
				captureInt))		// integer to search
			{
				nodeIndex->next = NULL;			// Ignore all nodes after the current node.
				Print_Passenger_List(nodeIndex);// Output the results
			} // if
			else
				std::cout << "Unable to find passenger with the passenger number: " << captureInt
				<< std::endl;

			badInput = false;
			break;
		case 5:						// Seat Number [Occupied]
			std::cout << "Enter passenger's Seat number: ";
			captureInt = UserInput_Number(false);
			std::cout << std::endl;

			if (Search(&nodeIndex,	// Our list to be scanned and processed.
				&nullityNode,		// Required for the function, but not used.
				5,					// Search by seat number
				"NA",				// Default to 'NA' due to standard; unused.
				captureInt))		// integer to search
			{
				nodeIndex->next = NULL;			// Ignore all nodes after the current node.
				Print_Passenger_List(nodeIndex);// Output the results
			} // if
			else
				std::cout << "Unable to a find a passenger in seat number: " << captureInt
				<< std::endl;

			badInput = false;
			break;
		case 0:						// Exit; silently leave this function
			badInput = false;
			break;
		default:					// Bad input
			std::cout << "Incorrect option!" << std::endl;
			badInput = true;
			break;
		} // switch
	} while (badInput);
} // FindPrintPassenger()




// Cancel Reservation
// =====================================================================================================
// Documentation:
// This code allows the user to search for a passenger in the list then remove them from said list.
// Logic:
// This code is a modified version of the Search function that only searches for passenger IDs.
// When it finds the ID it will delete the Node the ID is connected to.
// ========================================================================================================


inline bool delete_node(Node** head, Node** pre, int passengerIDKey)
{       
	if (*head == NULL){   //makes sure there is something in head
                return false;

	}
        while(*head != NULL){
                if((*head)->passengerID = passengerIDKey){ // searches the passenger IDs
                        (*pre)->next = (*head)->next; // moves to the next ID
                        delete head; // deletes the node if the node is the node that needs to be deleted
                        return true;
		}
	}

                return false; // If the ID typed in does not exist
}



// Update Passenger Information
// ===============================================
// Documentation:
//	This function will provide a front-end to the end-user to identify what
//	passenger's information is to be updated.
//  This function will first ask the end-user to input the current information
//   about the passenger, then with this information - we scan the list for the node.
//   IIF if the node exists with the passenger's information, then will provide the
//   end-user with update options for that passenger.
//
// NOTES: This function was coded badly and this should be better optimized, but
//			as we work at a coding sweat shop, there is no better way!
//			The pay grade at this code sweat shop only offers 27 cents per hour :(
//			Please help us!
//
//  This function depends on the Search() and the input (number\int) function.
// ===============================================
inline void UpdatePassengerInformation(Node** head)
{
	// Present the user with a menu in which to search by
	std::cout << "Search for Passenger:" << std::endl
		<< "-----------------------" << std::endl
		<< " 1) Last name" << std::endl
		<< " 2) Telephone" << std::endl
		<< " 3) Reservation number" << std::endl
		<< " 4) Passenger number" << std::endl
		<< " 5) Seat Number" << std::endl
		<< " 0) Exit" << std::endl
		<< std::endl;

	bool badInput;	// Make sure that the input provided from the end-user
					// is valid; run-away protection.
	std::string captureString;
	int captureInt;

	Node* nullityNode = NULL;	// Create a list placeholder; we will not need it in this function, but
								// it is required when calling the Search() function.

	bool targetFound = false;	// We will use this to determine if the passenger was
								// detect during the search.  This will become true
								// IIF the passenger was found, otherwise - its false.
								// IIF this is true, then we will allow the user to update
								//  that node index.
	do {
		// Capture the user's request and process the request
		switch (UserInput_Number())
		{
		case 1:						// Last name
									// Capture the last name from the end-user
			std::cout << "Enter passenger's last name: ";
			captureString = UserInput_String(false);
			std::cout << std::endl;

			if (Search(head,		// Our list to be scanned and processed.
				&nullityNode,		// Required for the function, but not used.
				0,					// Search by last name
				captureString))		// String to search
				targetFound = true;
			else
				std::cout << "Unable to find passenger: " << captureString
				<< std::endl;

			badInput = false;
			break;
		case 2:						// Telephone
			std::cout << "Enter passenger's telephone number: ";
			captureInt >> UserInput_Number(false);
			std::cout << std::endl;

			if (Search(head,		// Our list to be scanned and processed.
				&nullityNode,		// Required for the function, but not used.
				4,					// Search by telephone number
				"NA",				// Default to 'NA' due to standard; unused.
				captureInt))		// integer to search
				targetFound = true;
			else
				std::cout << "Unable to find passenger with the telephone number: " << captureInt
				<< std::endl;

			badInput = false;
			break;
		case 3:						// Reservation ID
			std::cout << "Enter passenger's Reservation number: ";
			captureInt = UserInput_Number(false);
			std::cout << std::endl;

			if (Search(head,		// Our list to be scanned and processed.
				&nullityNode,		// Required for the function, but not used.
				3,					// Search by reservation number
				"NA",				// Default to 'NA' due to standard; unused.
				captureInt))		// integer to search
				targetFound = true;
			else
				std::cout << "Unable to find passenger with the reservation number: " << captureInt
				<< std::endl;

			badInput = false;
			break;
		case 4:						// Passenger ID
			std::cout << "Enter passenger's Passenger number: ";
			captureInt = UserInput_Number(false);
			std::cout << std::endl;

			if (Search(head,		// Our list to be scanned and processed.
				&nullityNode,		// Required for the function, but not used.
				2,					// Search by passenger number
				"NA",				// Default to 'NA' due to standard; unused.
				captureInt))		// integer to search
				targetFound = true;
			else
				std::cout << "Unable to find passenger with the passenger number: " << captureInt
				<< std::endl;

			badInput = false;
			break;
		case 5:						// Seat Number [Occupied]
			std::cout << "Enter passenger's Seat number: ";
			captureInt = UserInput_Number(false);
			std::cout << std::endl;

			if (Search(head,		// Our list to be scanned and processed.
				&nullityNode,		// Required for the function, but not used.
				5,					// Search by seat number
				"NA",				// Default to 'NA' due to standard; unused.
				captureInt))		// integer to search
				targetFound = true;
			else
				std::cout << "Unable to a find a passenger in seat number: " << captureInt
				<< std::endl;

			badInput = false;
			break;
		case 0:						// Exit; silently leave this function
			badInput = false;
			break;
		default:					// Bad input
			std::cout << "Incorrect option!" << std::endl;
			badInput = true;
			break;
		} // switch
	} while (badInput);

	// If the passenger was not found, leave this function.
	if (!targetFound)
	{
		system("PAUSE");		// Allow the end-user to view the message that the pasenger
								// was not found during the scan.
								// WARNING: __WINDOWS_ONLY__
								// ANYONE USING ADA OR LINUX, PLEASE COMMENT THIS STATEMENT!
								// With this statement, I am using an extCMD in Windows
								// via the Command Shell.
		return;
	}
	

	// =========================================================================
	// -------------------------------------------------------------------------
	// =========================================================================
	// TARGET FOUND


	// What does the end-user want to update?
	std::cout << "Information to Update:" << std::endl
		<< "-----------------------" << std::endl
		<< " 1) Telephone" << std::endl
		<< " 2) Reservation number" << std::endl
		<< " 3) Passenger number" << std::endl
		<< " 4) Seat Number" << std::endl
		<< " 0) Exit" << std::endl
		<< std::endl;

	// Get the user's input and evaluate it
	do
	{
		switch (UserInput_Number())
		{
		case 1:				// Update telephone
			// Let the user know of the current value
			std::cout << "Current telephone number: " << (*head)->telephoneNum << std::endl;
			// Allow the user to update that specific field:
			std::cout << "Enter a new value: ";
			(*head)->telephoneNum = UserInput_Number(false);

			badInput = false;
			break;
		case 2:				// Update reservation ID
			// Let the user know of the current value
			std::cout << "Current reservation number: " << (*head)->reservationNum << std::endl;
			// Allow the user to update that specific field:
			std::cout << "Enter a new value: ";
			(*head)->reservationNum = UserInput_Number(false);

			badInput = false;
			break;
		case 3:				// Update passenger ID
			// Let the user know of the current value
			std::cout << "Current passenger number: " << (*head)->passengerID << std::endl;
			// Allow the user to update that specific field:
			std::cout << "Enter a new value: ";
			(*head)->passengerID = UserInput_Number(false);

			badInput = false;
			break;
		case 4:				// Seat Number
			// Let the user know of the current value
			std::cout << "Current seat number: " << (*head)->seatNum << std::endl;
			// Allow the user to update that specific field:
			std::cout << "Enter a new value: ";
			(*head)->seatNum = UserInput_Number(false);

			badInput = false;
			break;
		case 0:				// Exit; silently leave this function
			badInput = false;
			break;
		default:			// Bad input
			std::cout << "Incorrect option!" << std::endl;
			badInput = true;
			break;
		}
	} while (badInput);
} // UpdatePassengerInformation()
#endif // !__LinkList__Implementation__