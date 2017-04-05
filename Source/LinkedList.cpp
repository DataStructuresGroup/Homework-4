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
		std::cout << "Passenger ID: " << cache->passengerID << std::endl
			<< "Passenger Name: " << cache->nameLast << ", " << cache->nameFirst << std::endl
			<< "Telephone Number: " << cache->telephoneNum << std::endl
			<< "Reservation Number: " << cache->reservationNum << std::endl
			<< "Seat on the plane: " << cache->seatNum << std::endl
			<< "Preferred Meal Plan: " << cache->mealType << std::endl;
	} // while
} // Print_Passenger_List()



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
inline bool Update_Passenger_Information(Node** head, int passengerID, int updateKey, int reservation = -255, int contactPhone = -255, std::string seatNumber = "NA", std::string mealType = "NA")
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
#endif // !__LinkList__Implementation__