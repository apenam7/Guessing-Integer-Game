/***********************************************
Author: Ariel Pena-Martinez
Date: 09/16/2019
Purpose: <In this program you can set your own conditions in guessing a number. Using the rand() function,
it generates a random number between the conditions entered by the player. You can set your own attempts 
to guess the number and the program will allow you to play as many time as the player said.>
Sources of Help: <Lectures, overflow, book, geekforgeeks>
Time Spent: 2h
***********************************************/

/*
Computing III -- COMP.2017 Honor Statement
The practice of	good	 ethical	 behavior	 is	 essential	 for	 maintaining
good	 order	 in	 the	 classroom,	 providing	 an	 enriching	 learning
experience	 for	 students,	 and	 as	 training	 as	 a	 practicing	 computing
professional	 upon	 graduation.	 	 This	 practice	 is	 manifested	 in	 the
University’s	 Academic	 Integrity	 policy.	 Students	 are	 expected	 to
strictly	 avoid	 academic	 dishonesty	 and	 adhere	 to	 the	 Academic
Integrity	 policy	 as	 outlined	 in	 the	 course	 catalog.	 	 Violations	 will
be	dealt	with	as	outlined	therein.
All	 programming	 assignments	 in	 this	 class	 are	 to	 be	 done	 by	 the
student	alone.		No	outside	help	is	permitted	except	the	instructor	and
approved	tutors.
I	certify	that	the	work	submitted	with	this	assignment	is	mine	and	was
generated	 in	 a	 manner	 consistent	 with	 this	 document,	 the	 course
academic	 policy	 on	 the	 course	 website	 on	 Blackboard,	 and	 the	 UMass
Lowell	academic	code.
Date: 09/16/2019
Name: Ariel Pena-Martinez
*/

#include <iostream>
#include <cstdlib>

using namespace std;

const int MIN_LIMIT = 0; //minimum limit constant.
const int MAX_LIMIT = 1000; //maximum limit constant.
const int MAX_GUESS_LIMIT = 10; //maximum guess limit constant.

int get_random(int min, int max); /*The parameters min and max are used to stablish the limites in wich 
								  the random value gets generated between*/

int main() {
	bool playing;
	cout << "******* Welcome to the Game *******\nFirst, let's set up the game." << endl;
	do { //do while the player wants to play, otherwise break out of the loop.
		int min;
		int max;
		int guesses;

		while (true) { //Continue the loop, until user enter the correct min number greater than 0 in this case.
			cout << "	Please enter the minimum number, a positive integer greater than " << MIN_LIMIT << ": ";
			cin >> min;
			if (min > MIN_LIMIT) {
				break;
			}
			cout << "Invalid input, try again\n "; //Show this message in case of invalid input and ask again.
		}
		
		while (true) { //Continue the loop until user enter the correct maximum number between the min and 1000.
			cout << "	Please enter the maximum number, which is greater than " << min << " and less than " << MAX_LIMIT << ": ";
			cin >> max;
			if (max > min && max < MAX_LIMIT) {
				break;
			}
			cout << "Invalid input, try again\n "; //Show this message in case of invalid input and ask again.
		}

		
		while (true) { //Continue the loop until user enter the correct amount of guesses less than 10.
			cout << "	Please enter the number of guesses allowed (less than 10): ";
			cin >> guesses;
			if (guesses < MAX_GUESS_LIMIT) {
				break;
			}
			cout << "Invalid input, try again \n"; //Show this message in case of invalid input and ask again.
		}

		int number_guessed = get_random(min, max); //Get random value for game by passing min and max limit.
		bool win = false; //variable whose make decision for winning or loosing initially in false.
		int guess;
		//After player enters the correct values, the game begins!!!!!
		cout << "Now, I have a number between " << min << " and " << max <<". Can you guess my number? Please type your first guess.\n?";
		cin >> guess;
		for (int i = 0; i < guesses; ++i) { //loop for the amount of guesses. 

			if (guess > number_guessed) { //conditions for messages to show and orientations of the game. Check if guess is greater than the number.
				if (i == guesses - 1)
				{
					cout << "Too high!" << endl;
					break;
				}
				cout << "Too high! Try again.\n?";
				cin >> guess;
			}

			else if (guess < number_guessed) { //check if guess is less than the number.
				if (i == guesses - 1)
				{
					cout << "Too low!" << endl;
					break;
				}
				cout << "Too low! Try again.\n?";
				cin >> guess;
			}
			else { //when the correct number is guessed.
				win = true; 
				break;
			}
		}
		/* the end of the for loop, meaning that eother the player got to the maximum amount of
		guesses or the player won*/

		if (win) { //check if the player won the match or loose it.
			cout << "Excellent! You guessed the number. " << number_guessed << endl;
		}
		else {
			cout << "Sorry, you can't guess any more. The number is: " << number_guessed << endl;
		}

		//Ask player if play a new game or exit.
		cout << "Would you like to play again[y or n]: ";
		string choice;
		cin >> choice;  //gets the player choice in a string variable.

		/*If choice is "y" or "Y" or "yes" or "Yes" or "YES" then make "playing" true,
		otherwise false.*/
		playing = (choice == "y" || choice == "Y" || choice == "yes" || choice == "Yes" || choice == "YES");

	}
	while (playing); //Loop will continue or break according to player's choice.

	cout << "Thanks for playing" << endl;
	return 0;
}

int get_random(int min, int max) { /*Generating a random number. For example rand%10 = to the numbers
								   between 0-9. In case I want the number 0-10 I have to add 1. 
								   Example : rand%(10+1)
								   We need the value which is more or equal to min and less or equal 
								   to max. */
	int temp = max - min + 1;
	int random = rand() % temp + min; // We add the min since we want the numbers greater or equal to min
	return random; //returns the random value.
}
