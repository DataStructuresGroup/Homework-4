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
	// Create a new list to generate
	Node* autoList;

	// __HARD_CODED__
	// Update this algorithm with caution!
	//---
	// To auto-generate, we are going to throw hard-coded values
	// to the link list.  This will greatly allow us to debug or
	// generally work with the list.
	for (int i = 0; i < 20; ++i)
	{
		switch (i)
		{
		case 0:
			autoList->nameFirst = "Fabian";
			autoList->nameLast = "Nadie";
			autoList->passengerID = Autofill_List_Numbers(0);
			autoList->reservationNum = Autofill_List_Numbers(1);
			autoList->telephoneNum = Autofill_List_Numbers(2);
			autoList->seatNum = "";
			autoList->mealType = Autofill_List_MealChoice();
			break;
		case 1:
			autoList->nameFirst = "Ganit";
			autoList->nameLast = "Ume";
			autoList->passengerID = Autofill_List_Numbers(0);
			autoList->reservationNum = Autofill_List_Numbers(1);
			autoList->telephoneNum = Autofill_List_Numbers(2);

			autoList->mealType = Autofill_List_MealChoice();
			break;
		case 2:
			autoList->nameFirst = "Dan";
			autoList->nameLast = "Randi";
			autoList->passengerID = Autofill_List_Numbers(0);
			autoList->reservationNum = Autofill_List_Numbers(1);
			autoList->telephoneNum = Autofill_List_Numbers(2);

			autoList->mealType = Autofill_List_MealChoice();
			break;
		case 3:
			autoList->nameFirst = "Reese";
			autoList->nameLast = "Nafisa";
			autoList->passengerID = Autofill_List_Numbers(0);
			autoList->reservationNum = Autofill_List_Numbers(1);
			autoList->telephoneNum = Autofill_List_Numbers(2);

			autoList->mealType = Autofill_List_MealChoice();
			break;
		case 4:
			autoList->nameFirst = "Nina";
			autoList->nameLast = "Albany";
			autoList->passengerID = Autofill_List_Numbers(0);
			autoList->reservationNum = Autofill_List_Numbers(1);
			autoList->telephoneNum = Autofill_List_Numbers(2);

			autoList->mealType = Autofill_List_MealChoice();
			break;
		case 5:
			autoList->nameFirst = "Alexis";
			autoList->nameLast = "Wayne";
			autoList->passengerID = Autofill_List_Numbers(0);
			autoList->reservationNum = Autofill_List_Numbers(1);
			autoList->telephoneNum = Autofill_List_Numbers(2);

			autoList->mealType = Autofill_List_MealChoice();
			break;
		case 6:
			autoList->nameFirst = "Rani";
			autoList->nameLast = "Falcon";
			autoList->passengerID = Autofill_List_Numbers(0);
			autoList->reservationNum = Autofill_List_Numbers(1);
			autoList->telephoneNum = Autofill_List_Numbers(2);

			autoList->mealType = Autofill_List_MealChoice();
			break;
		case 7:
			autoList->nameFirst = "Yasmine";
			autoList->nameLast = "Benicia";
			autoList->passengerID = Autofill_List_Numbers(0);
			autoList->reservationNum = Autofill_List_Numbers(1);
			autoList->telephoneNum = Autofill_List_Numbers(2);

			autoList->mealType = Autofill_List_MealChoice();
			break;
		case 8:
			autoList->nameFirst = "Al";
			autoList->nameLast = "Bundy";
			autoList->passengerID = Autofill_List_Numbers(0);
			autoList->reservationNum = Autofill_List_Numbers(1);
			autoList->telephoneNum = Autofill_List_Numbers(2);

			autoList->mealType = Autofill_List_MealChoice();
			break;
		case 9:
			autoList->nameFirst = "Janeeva";
			autoList->nameLast = "Zaina";
			autoList->passengerID = Autofill_List_Numbers(0);
			autoList->reservationNum = Autofill_List_Numbers(1);
			autoList->telephoneNum = Autofill_List_Numbers(2);

			autoList->mealType = Autofill_List_MealChoice();
			break;
		case 10:
			autoList->nameFirst = "Ofra";
			autoList->nameLast = "Sable";
			autoList->passengerID = Autofill_List_Numbers(0);
			autoList->reservationNum = Autofill_List_Numbers(1);
			autoList->telephoneNum = Autofill_List_Numbers(2);

			autoList->mealType = Autofill_List_MealChoice();
			break;
		case 11:
			autoList->nameFirst = "Nadalia";
			autoList->nameLast = "Hao";
			autoList->passengerID = Autofill_List_Numbers(0);
			autoList->reservationNum = Autofill_List_Numbers(1);
			autoList->telephoneNum = Autofill_List_Numbers(2);

			autoList->mealType = Autofill_List_MealChoice();
			break;
		case 12:
			autoList->nameFirst = "Hana";
			autoList->nameLast = "Starr";
			autoList->passengerID = Autofill_List_Numbers(0);
			autoList->reservationNum = Autofill_List_Numbers(1);
			autoList->telephoneNum = Autofill_List_Numbers(2);

			autoList->mealType = Autofill_List_MealChoice();
			break;
		case 13:
			autoList->nameFirst = "Ashia";
			autoList->nameLast = "Bäddan";
			autoList->passengerID = Autofill_List_Numbers(0);
			autoList->reservationNum = Autofill_List_Numbers(1);
			autoList->telephoneNum = Autofill_List_Numbers(2);

			autoList->mealType = Autofill_List_MealChoice();
			break;
		case 14:
			autoList->nameFirst = "Qi";
			autoList->nameLast = "Wahponjea";
			autoList->passengerID = Autofill_List_Numbers(0);
			autoList->reservationNum = Autofill_List_Numbers(1);
			autoList->telephoneNum = Autofill_List_Numbers(2);

			autoList->mealType = Autofill_List_MealChoice();
			break;
		case 15:
			autoList->nameFirst = "Hali";
			autoList->nameLast = "Eamon";
			autoList->passengerID = Autofill_List_Numbers(0);
			autoList->reservationNum = Autofill_List_Numbers(1);
			autoList->telephoneNum = Autofill_List_Numbers(2);

			autoList->mealType = Autofill_List_MealChoice();
			break;
		case 16:
			autoList->nameFirst = "Tai Yang";
			autoList->nameLast = "Taipa";
			autoList->passengerID = Autofill_List_Numbers(0);
			autoList->reservationNum = Autofill_List_Numbers(1);
			autoList->telephoneNum = Autofill_List_Numbers(2);

			autoList->mealType = Autofill_List_MealChoice();
			break;
		case 17:
			autoList->nameFirst = "Achava";
			autoList->nameLast = "Nili";
			autoList->passengerID = Autofill_List_Numbers(0);
			autoList->reservationNum = Autofill_List_Numbers(1);
			autoList->telephoneNum = Autofill_List_Numbers(2);

			autoList->mealType = Autofill_List_MealChoice();
			break;
		case 18:
			autoList->nameFirst = "John";
			autoList->nameLast = "Hancock";
			autoList->passengerID = Autofill_List_Numbers(0);
			autoList->reservationNum = Autofill_List_Numbers(1);
			autoList->telephoneNum = Autofill_List_Numbers(2);

			autoList->mealType = Autofill_List_MealChoice();
			break;
		case 19:
			// Deal with it
			autoList->nameFirst = "Theodore";
			autoList->nameLast = "Roosevelt";
			autoList->passengerID = Autofill_List_Numbers(0);
			autoList->reservationNum = Autofill_List_Numbers(1);
			autoList->telephoneNum = Autofill_List_Numbers(2);

			autoList->mealType = Autofill_List_MealChoice();
			break;
		default:
			autoList->nameFirst = "Jenny";
			autoList->nameLast = "Tommy Tutone";
			autoList->passengerID = -919;
			autoList->reservationNum = -919;
			autoList->telephoneNum = 8675309; // https://youtu.be/8ou6DDG5e7I
			autoList->mealType = "MRE"; // Military acronym for 'Meal Ready to Eat', its horrible.
			break;
		} // switch
	} // for

	// Append the list to the primary link list
	*head = autoList;
} // Autofill_List()



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
	int choice = rand() % 4;
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
#endif // !__LinkList__Implementation__