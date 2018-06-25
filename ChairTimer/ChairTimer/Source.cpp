#include "Header.h"


int main()
{	
	string inputRun = "y";
	
	while (inputRun == "y")
	{
		TimerIO();

		cout << "Would you like to create another timer? (y/n)" << endl;
		cin >> inputRun;
		system("Color 0F");
		system("cls");

	}
	cout << "Ok, thanks for using my program :)" << endl;

	system("pause");
	return 0;
}