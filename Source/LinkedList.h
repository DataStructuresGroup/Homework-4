
// This merely holds the LinkedList struct.  The related functions can be located at:
//  LinkedList.cpp.
#ifndef __LinkedList__
#define __LinkedList__

#pragma region Inclusions
// This is a temporary solution for now, this inclusion must be resolved before final submission!
//TODO Fix inclusion at header; std::string.  LinkList.h >> LinkList.cpp
	#include <string>
#pragma endregion


// Node Methodology:
// ======================
// |     DATA FIELDS    |
// | ------------------ |
// |     Next Node -->  |
// ======================


struct Node
{
	// Data within the node
	std::string nameFirst;		// Holds the passenger's first name
	std::string nameLast;		// Holds the passenger's last name
	int passengerID;			// Retains the passenger's ID
	int reservationNum;			// Retains the passenger's reservation number
	int telephoneNum;			// Holds the passenger's preferred phone number.
	int seatNum;				// Holds the passenger's seat number
	std::string mealType;		// What meal does the passenger want during the flight?

	//----

	// Next node
	Node* next;					// Point to the next node
};
#endif // !__LinkedList__