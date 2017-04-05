#ifndef __LinkList__Implementation__		// For those using Visual Studio, lets try to avoid LNK2004 errors...
#define __LinkList__Implementation__

#pragma region Inclusions
#include <iostream>			// Input and Output
#include <cstring>			// Used for the 'NULL' keyword, despite that it is '0' or 'OL', but keep this for convention sakes.
#include "LinkedList.h"		// Implementation for Link List.
#pragma endregion



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
	// Cache all of the items from the parent and store it to a cache var.
	Node* cache = head;

	// Output the available list with the information required.
	while (cache != NULL)
	{
		std::cout << "Passenger ID: " << cache->passangerID << std::endl
			<< "Passenger Name: " << cache->nameLast << ", " << cache->nameFirst << std::endl
			<< "Telephone Number: " << cache->telephoneNum << std::endl
			<< "Reservation Number: " << cache->reservationNum << std::endl
			<< "Seat on the plane: " << cache->seatNum << std::endl
			<< "Preferred Meal Plan: " << cache->mealType << std::endl;
	} // while
} // Print_List()
#endif // !__LinkList__Implementation__