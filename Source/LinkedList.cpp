#ifndef __LinkList__Implementation__		// For those using Visual Studio, lets try to avoid LNK2004 errors...
#define __LinkList__Implementation__

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

		head = head->next;
	} // while
} // Print_Passenger_List()



// Update Passenger Information
// ===============================================
// Documentation:
//	Update the passenger's information respectively
//	This will only allow one change per-invoktion.  If
//	 the passenger needs two or more fields to be updated,
//	 then this function MUST be invoked two or more times.
// -----------------------------------------------
// Parameters:
//	head [Node*]
//		This will take any valid link list.
//	passengerID [int]
//		Select the passenger to update
//	updateKey [int]
//		Updates the requested field.  (ONLY ONE UPDATE PER-CALL!)
//		<WARNING>
//		Please read the list to update the correct field!
//		Use the following key to update:
//			0 = Reservation
//			1 = Phone number
//			2 = Flight Seat
//			3 = InFlight Meal
//	reservation [int]
//		[DEFAULT = -255]
//		When requested, update the reservation.
//	contactPhone [int]
//		[DEFAULT = -255]
//		When requested, update the telephone number.
//	seatNumber [string]
//		[DEFAULT = NA]
//		When requested, update the flight seat.
//	mealType [string]
//		[DEFAULT = NA]
//		When requested, update the inflight meal.
//		Fun Fact: Skip the fish!
//			Please consider watching Airplane!
//			https://youtu.be/rQbj9uvYL8I
// -----------------------------------------------
// Output:
//	False:
//		Success, no failures.
//	True:
//		Failure; possibly the passenger does not exist.
// ===============================================
inline bool Update_Passenger_Information(Node** head, int passengerID, int updateKey, int reservation = -255, int contactPhone = -255, int seatNumber = -255, std::string mealType = "NA")
{
	// Check to see if at least node exists, if not - leave this function.
	if (*head == NULL)
		return false;

	// Mirror list for alterations
	Node* mirrorList = *head;

	// Find the passenger....
	while (mirrorList->passengerID != passengerID && mirrorList->next != NULL)
		mirrorList->next;

	// Make sure that we actually found the passenger
	if (mirrorList->passengerID != passengerID || mirrorList == NULL)
		// Failed to find the passenger, terminate
		return 0;

	// Evaluate what needs to be updated and alter as needed
	switch (updateKey)
	{
		case 0:
			// Reservation
			mirrorList->reservationNum = reservation;
			break;
		case 1:
			// Phone number
			mirrorList->telephoneNum = contactPhone;
			break;
		case 2:
			// Flight Seat
			mirrorList->seatNum = seatNumber;
			break;
		case 3:
			// InFlight Meal
			mirrorList->mealType = mealType;
			break;
	} // switch

	// Success!
	return true;
} // Update_Passenger_Information()



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



/*
bool search_node(int key)

{ node*temp=head;
pre = NULL;

cur = temp;

while(cur != NULL)
{

if (cur-> key ==key)
 {return true;
}
else{
pre = cur;
cur = cur->next;

}
return false;



bool delete_node(int key){
cout << "Enter what you want to delete:";
cin >> key;

if (search_node(key))
{
 pre->next = cur->next;
 delete cur;
 return true;
}
else{
cout "ERRROR this is not in the list!" << endl;
return false;
}
*/
#endif // !__LinkList__Implementation__