#include "Header.h"

class Timer
{
public:

	//Figured I'd use the numbers in milliseconds for the sleep function at some point, but ended up not needing to
	void setSeconds(unsigned int);
	unsigned int getSeconds(bool);

	void setMinutes(unsigned int);
	unsigned int getMinutes(bool);

	void setHours(unsigned int);
	unsigned int getHours(bool);

private:
	unsigned int timeSeconds = 0;
	unsigned int timeMinutes = 0;
	unsigned int timeHours = 0;


};

//Since Sleep() uses values in milliseconds these convert from milliseconds to the actual times entered by the user 

void Timer::setSeconds(unsigned int seconds)
{
	timeSeconds = seconds * 1000;
}

unsigned int Timer::getSeconds(bool inMilliseconds)
{
	if (inMilliseconds == true)
		return timeSeconds; 
	else 
		return timeSeconds / 1000; 
}

void Timer::setMinutes(unsigned int minutes)
{
	timeMinutes = minutes * 60000;
}

unsigned int Timer::getMinutes(bool inMilliseconds)
{
	if (inMilliseconds == true)
		return timeMinutes;
	else
		return timeMinutes / 60000;
}

void Timer::setHours(unsigned int hours)
{
	timeHours = hours * 3600000;
}

unsigned int Timer::getHours(bool inMilliseconds)
{
	if (inMilliseconds == true)
		return timeHours;
	else
		return timeHours / 3600000;
}

//Program calls user by the name they input
void TakeName()
{
	string userName;
	cout << "Enter your name: ";
	getline(cin, userName);
	if (userName == "") { userName = "User"; }
	cout << "Hello there, " << userName << "." << endl;
}	

void TimerIO()
{
	Timer timer;
	unsigned int userInput;
	string Messages[] =
	{
		"Get out of your chair, theres a bomb under it!!", "Your chair is actually shortening your lifespan, leave it.",
		"Your feet miss being used, you should go walk around",
		"I know you're focused on solving them bugs and completing them logics, but get up and do something else for a byte."
	};

	timer.setHours(0);
	timer.setMinutes(0);
	timer.setSeconds(0);

	//Make this function dynamically update itself with the correct values and words
	//instead of manually making three code blocks that are nearly identical
	for (int timeLocation = 0; timeLocation < 4; timeLocation++)
	{
		system("cls");
		//Program calls user by the name they input
		TakeName();

		//Once the user sets a time, update the display with the value they set
		cout << "This is a timer to remind you to get out of your chair." << endl;
		cout << "Enter the amount of time you'd like to set.\n" << endl;
		cout << "Hours[" << timer.getHours(false) << "] ";
		cout << "Minutes[" << timer.getMinutes(false) << "] ";
		cout << "Seconds[" << timer.getSeconds(false) << "]" << endl;

		//Display the correct words in the order that the user sets values
		if (timeLocation == 0) { cout << "Hours: "; }
		if (timeLocation == 1) { cout << "Minutes: "; }
		if (timeLocation == 2) { cout << "Seconds: "; }

		//Fourth loop is just to update the seconds displayed
		if (timeLocation < 3) { cin >> userInput; }

		//If the user doesnt enter an integer, make them
		//ERROR Catch
		while (cin.fail() || userInput < 0)
		{
			cout << "Please enter the amount of time as a number, not a word or letter." << endl;
			if (timeLocation == 0) { cout << "Hours: "; }
			if (timeLocation == 1) { cout << "Minutes: "; }
			if (timeLocation == 2) { cout << "Secondss: "; }
			cin.clear();
			//Ignore all previous characters from cin until it reaches a newline

			cin.ignore((numeric_limits<unsigned int>::max)(), '\n');
			cin >> userInput;
			system("cls");
		}

		if (timeLocation == 0)
		{
			cout << "Hours: ";
			timer.setHours(userInput);
		}
		if (timeLocation == 1)
		{
			cout << "Minutes: ";
			timer.setMinutes(userInput);
		}
		if (timeLocation == 2)
		{
			cout << "Seconds: ";
			timer.setSeconds(userInput);
		}
	}

	//The actual timer that runs behind the scenes
	unsigned int totalTime;
	do
	{
		totalTime = timer.getHours(false) + timer.getMinutes(false) + timer.getSeconds(false);
		system("cls");
		cout << "==Time until you should get out of your chair==" << endl;
		cout << "Hours[" << timer.getHours(false) << "] ";
		cout << "Minutes[" << timer.getMinutes(false) << "] ";
		cout << "Seconds[" << timer.getSeconds(false) << "]" << endl;
		Sleep(1000);
		timer.setSeconds(timer.getSeconds(false) - 1);
		//Since 1000 milliseconds have gone by, remove 1000 milliseconds from the total time the user 

		//My brain was fried here due to trying to find and fix a bud that was driving me crazy. 
		//I realized I never needed 2 return states after I wrote this
		if (timer.getSeconds(false) == 0 && timer.getMinutes(false) != 0)
		{
			timer.setMinutes(timer.getMinutes(false) - 1);
			timer.setSeconds(timer.getSeconds(false) + 60);
		}
		if (timer.getMinutes(false) == 0 && timer.getHours(false) != 0)
		{
			timer.setHours(timer.getHours(false) - 1);
			timer.setMinutes(timer.getMinutes(false) + 60);
		}


	} while (totalTime != 0);

	cout << Messages[rand() % 3] << endl;
	system("color F0");
}
	
//Wanted to put the actual time part in here, but I'm getting close to the deadline and I don't want to run out of time
void Update(unsigned int Hours, unsigned int Minutes, int unsigned Seconds )
{
	

}