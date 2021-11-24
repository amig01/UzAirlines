#include <iostream>
#include <iomanip>
#include <string>
#include <cctype>
#include <ctime>

using namespace std;

string name, destination, date, flight, gate, seat;

string table_info[10][3];
const int const_flight = 0;
const int const_dest = 1;
const int const_gate = 2;

string destinations[] =
{
	"abidjan", "alexandria", "almaty", "amman", "ankara",
	"baghdad", "baku", "barcelona", "bangkok", "beijing", "berlin", "birmingham", "bogota", "bombei", "brasilia", "brisbane", "bucharest", "budapest",
	"cairo", "canberra", "capetown", "chicago", "copenhagen", "cordoba",
	"dakar", "dehli", "dhaka",
	"giza", "guatamala",
	"hamburg", "hanoi", "havana", "hiroshima", "houston",
	"istanbul",
	"kabul", "kawasaki", "kazan", "kiev", "kyoto",
	"leon", "london",
	"madrid", "mecca", "medina", "mexico", "milan", "minsk", "montreal", "moscow", "mumbai", "munich",
	"napoli",
	"odessa", "osaka",
	"paris", "perm", "prague",
	"rabat", "rome",
	"salvador", "samarkand", "santiago", "seoul", "shanghai", "singapore", "sofia", "stockholm", "sydney",
	"tbilisi", "tehran", "tokyo", "toronto", "tunis",
	"valencia", "vienna",
	"warsaw", "wuhan",
	"yerevan", "yokohama",
};

void Greeting();
void FillFlightTable(int);
void ShowFlightTable();
void ShowDestinations();
void InputDestination();
void InputDate();
void InputName();
void ShowProgress();
bool BookTicket();
void ShowTicket();

int main()
{
	//Linking rand() function's return values to time
	srand(time(0));

	//Setting text's color in command line to the light-yellow
	system("color e");

	bool booked = false;
	while (booked == false)
	{
		//Clearing all data about the flight
		name = destination = date = flight = gate = seat = "";

		Greeting();

		cout << "Enter the number of option: ";
		string option;
		cin >> option;

		if (option == "1")
		{
			system("cls");

			booked = BookTicket();
			if (booked)
				ShowTicket();
		}
		else if (option == "2")
		{
			system("cls");

			date = to_string(rand() % 31 + 1) + ".12.2021";

			ShowFlightTable();
			
			cin >> option;

			system("cls");

			if (option == "1" || option == "2" || option == "3" || option == "4" || option == "5" || option == "6" || option == "7")
			{
				//Extracting chosen flight's additional data from the table and copying it to the data about the flight 
				flight = table_info[stoi(option) - 1][const_flight];
				destination = table_info[stoi(option) - 1][const_dest];
				gate = table_info[stoi(option) - 1][const_gate];

				booked = BookTicket();
				if (booked)
					ShowTicket();
			}
		}
		else if (option == "3")
		{
			system("cls");

			ShowDestinations();

			booked = BookTicket();
			if (booked)
				ShowTicket();
		}
	}

	system("pause");
	return 0;
}

void Greeting()
{
	system("cls");
	cout << setfill('_') << setw(121) << '\n' << endl;
	cout << setfill(' ') << setw(70) << "Welcome to UzAirlines!" << endl;
	cout << setfill('_') << setw(121) << '\n' << endl;
	cout << "1. Book a ticket" << endl;
	cout << "2. Look at today's flight table." << endl;
	cout << "3. Look at list of avialable destinations." << endl;
	cout << endl;
}

void FillFlightTable(int num)
{
	for (int i = 0; i < num; i++)
	{
		cout << setfill(' ');
		cout << setw(22) << char(179);
		cout << left;
		cout << ' ' << setw(3) << i + 1 << char(179);

		//Assigning proper random values to temporary variables
		int h = rand() % 10 + 10;
		int m = rand() % 10 + 10;

		string temp;
		temp = destinations[rand() % 80];

		for (int j = 0; j < temp.length(); j++)
			temp[j] = toupper(temp[j]);

		//Filling flights table by assigning temporary variables to array elements
		table_info[i][const_dest] = temp;

		table_info[i][const_flight] = temp.substr(0, 3) + to_string(rand() % 900 + 100);

		table_info[i][const_gate] = "";
		table_info[i][const_gate] += char(rand() % 10 + 65) + to_string(rand() % 9 + 1);

		//Printing table information
		cout << ' ' << setw(8) << table_info[i][const_flight] << char(179);
		cout << ' ' << setw(23) << table_info[i][const_dest] << char(179);
		cout << ' ' << setw(8) << to_string(h) + ":" + to_string(m) << char(179);
		cout << ' ' << setw(8) << table_info[i][const_gate] << char(179);
		cout << ' ' << setw(13); rand() % 3 == 0 ? cout << "BOARDING" : cout << "CHECK-IN"; cout << char(179);
		cout << endl;

		if (i == num - 1)
			break;

		//Printing middle border to separate body information
		cout << right << setfill(' ') << setw(22) << char(195) << setfill(char(196)) << setw(5) << char(197) << setw(10) << char(197) << setw(25) << char(197) << setw(10) << char(197) << setw(10) << char(197) << setw(15) << char(180) << endl;
	}
}

void ShowFlightTable()
{
	cout << setfill('_') << setw(121) << '\n' << endl;
	cout << setfill(' ') << setw(67) << "Departures." << endl;
	cout << setfill('_') << setw(121) << '\n' << endl;

	cout << setfill(' ') << setw(36) << "Current date: " << date << endl;

	//Printing top border of the table's heading
	cout << setw(22) << char(201) << setfill(char(205)) << setw(5) << char(203) << setw(10) << char(203) << setw(25) << char(203) << setw(10) << char(203) << setw(10) << char(203) << setw(15) << char(187) << endl;

	//Filling header with categories
	cout << setfill(' ') << setw(22) << char(186) << left;
	cout << ' ' << setw(3) << 'N' << char(186);
	cout << ' ' << setw(8) << "Flight" << char(186);
	cout << ' ' << setw(23) << "Destination" << char(186);
	cout << ' ' << setw(8) << "Time" << char(186);
	cout << ' ' << setw(8) << "Gate" << char(186);
	cout << ' ' << setw(13) << "Remark" << char(186);
	cout << endl;

	//Printing bottom border of the table's heading
	cout << right << setfill(' ') << setw(22) << char(200) << setfill(char(205)) << setw(5) << char(202) << setw(10) << char(202) << setw(25) << char(202) << setw(10) << char(202) << setw(10) << char(202) << setw(15) << char(188) << endl;

	//Printing top border of the table's body part
	cout << setfill(' ') << setw(22) << char(218) << setfill(char(196)) << setw(5) << char(194) << setw(10) << char(194) << setw(25) << char(194) << setw(10) << char(194) << setw(10) << char(194) << setw(15) << char(191) << endl;

	FillFlightTable(7);

	//Printing bottom border of the table's body part
	cout << right << setfill(' ') << setw(22) << char(192) << setfill(char(196)) << setw(5) << char(193) << setw(10) << char(193) << setw(25) << char(193) << setw(10) << char(193) << setw(10) << char(193) << setw(15) << char(217) << endl;

	cout << endl << setfill(' ') << setw(22) << ' ' << "Enter 0 to go to home page." << endl;
	cout << setw(22) << ' ' << "Choose the number of flight: ";
}

void ShowDestinations()
{
	cout << right << setfill('_') << setw(121) << '\n' << endl;
	cout << setfill(' ') << setw(72) << "Available destinations." << endl;
	cout << setfill('_') << setw(121) << '\n' << endl;

	for (int i = 0; i < 80; i++)
	{
		if (i % 5 == 0)
			cout << endl << setfill(' ') << setw(25) << ' ';
		cout << left << setw(15) << destinations[i];
	}
	cout << endl;
}

void InputDestination()
{
	bool correct = false;
	while (correct == false && destination == "")
	{
		cout << "\nEnter the destination: ";
		string input;
		cin >> input;

		//Checking entered destination for typos
		correct = true;
		for (int i = 0; i < input.length(); i++)
		{
			if (isalpha(input[i]) == false || input.length() < 4)
			{
				correct = false;
				break;
			}
		}

		if (correct == false)
		{
			cout << "Please, enter distinct place." << endl;
			continue;
		}

		//Checking entered destination for avalability
		bool available = false;

		for (int i = 0; i < input.length(); i++)
			input[i] = tolower(input[i]);

		for (int i = 0; i < 100; i++)
		{
			if (input == destinations[i])
			{
				available = true;

				for (int j = 0; j < input.length(); j++)
					destination += toupper(input[j]);
			}
		}

		if (available == false)
		{
			cout << "Unfortunately we don't fly to this destination." << endl;
			cout << "Choose another one." << endl;

			cout << "\nWould you like to look at available destinations?" << endl;
			cout << "0. No" << endl << "1. Yes" << endl;

			cout << "\nChoose only given option: ";
			cin >> input;
			cout << endl;

			if (input == "1")
				ShowDestinations();

			correct = false;
		}
	}
}

void InputDate()
{
	bool correct = false;
	while (correct == false && date == "")
	{
		cout << "\nEnter the day of departure in this month: ";
		string input;
		cin >> input;

		//Checking date for typo or for existence
		if (input.length() == 1)
		{
			input += input[0];
			input[0] = '0';
		}

		int date = 0;

		if (isdigit(input[0]) && isdigit(input[1]) && (input.length() < 3))
			date = stoi(input);

		if (date < 1 || date > 31)
			correct = false;
		else
			correct = true;


		if (correct == false)
			cout << "Please, enter valid date." << endl;
		else
			::date = input + ".12.2021";
	}
}

void InputName()
{
	bool correct = false;
	while (correct == false)
	{
		cout << "\nEnter your first name: ";
		string input;
		cin >> input;

		//Checking first name for typos
		correct = true;
		for (int i = 0; i < input.length(); i++)
		{
			if ((isalpha(input[i]) == 0) || (input.length() < 4))
			{
				correct = false;
				break;
			}
		}

		if (correct == false)
			cout << "Please, enter your name correctly." << endl;
		else
		{
			input[0] = toupper(input[0]);
			for (int i = 1; i < input.length(); i++)
				input[i] = tolower(input[i]);

			name += input;
		}
	}

	correct = false;
	while (correct == false)
	{
		cout << "\nEnter your last name: ";
		string input;
		cin >> input;

		//Checking last name for typos
		correct = true;
		for (int i = 0; i < input.length(); i++)
		{
			if ((isalpha(input[i]) == 0) || (input.length() < 4))
			{
				correct = false;
				break;
			}
		}

		if (correct == false)
			cout << "Please, enter your name correctly." << endl;
		else
		{
			input[0] = toupper(input[0]);
			for (int i = 1; i < input.length(); i++)
				input[i] = tolower(input[i]);

			name += ' ' + input;
		}
	}
}

void ShowProgress()
{
	system("cls");
	cout << right << setfill('_') << setw(121) << '\n' << endl;
	cout << setfill(' ') << setw(75) << "Where do you want to explore?" << endl;
	cout << setfill('_') << setw(121) << '\n' << endl;

	//The function ShowProgres() was implemented in order to make the process of booking neat and tidy as it clears previous inputs and prints only given information
	if (destination != "")
		cout << "Destination: " << destination << endl;

	if (date != "")
		cout << "Date: " << date << endl;

	if (name != "")
		cout << "Name: " << name << endl;
}

bool BookTicket()
{
	cout << right << setfill('_') << setw(121) << '\n' << endl;
	cout << setfill(' ') << setw(75) << "Where do you want to explore?" << endl;
	cout << setfill('_') << setw(121) << '\n' << endl;

	InputDestination();
	ShowProgress();

	InputDate();
	ShowProgress();

	InputName();
	ShowProgress();

	//If the flight was not chosen from today's flight table all these 3 if statements will be ran to fill the necessary information
	if (flight == "")
		flight = destination.substr(0, 3) + to_string(rand() % 900 + 100);

	if (gate == "")
		gate += char(rand() % 10 + 65) + to_string(rand() % 9 + 1);

	if (seat == "")
		seat += char(rand() % 8 + 65) + to_string(rand() % 99 + 1);

	string verification;
	cout << endl << name + ", is this your last choice?" << endl;
	cout << "0. No\n1. Yes\n" << endl;
	cout << "Choose only given option: ";
	cin >> verification;

	return verification == "1";
}

void ShowTicket()
{
	system("cls");

	cout << right << setfill('_') << setw(121) << '\n' << endl;
	cout << setfill(' ') << setw(65) << "Your ticket." << endl;
	cout << setfill('_') << setw(121) << '\n' << endl;

	cout << endl;
	cout << setfill(' ') << setw(10) << char(218) << setfill(char(196)) << setw(70) << char(210) << setw(30) << char(191) << endl;
	cout << setfill(' ') << setw(10) << char(179) << setw(40) << "UzAirlines" << setw(30) << char(186) << setw(20) << "UzAirlines" << setw(10) << char(179) << endl;
	cout << setfill(' ') << setw(10) << char(195) << setfill(char(196)) << setw(70) << char(215) << setw(30) << char(180) << endl;

	//Every single "cout" in line is printing only one line 
	cout << setfill(' ') << right << setw(10) << char(179) << setw(70) << char(186) << setw(30) << char(179) << endl;
	cout << right << setw(10) << char(179) << setw(20) << "Passenger name: " << left << setw(49) << name << char(186) << right << setw(10) << "Date: " << left << setw(19) << date << char(179) << endl;
	cout << right << setw(10) << char(179) << setw(20) << "Flight: " << left << setw(49) << flight << char(186) << right << setw(30) << char(179) << endl;
	cout << right << setw(10) << char(179) << setw(70) << char(186) << right << setw(10) << "Gate: " << left << setw(19) << gate << char(179) << endl;
	cout << right << setw(10) << char(179) << setw(20) << "From: " << left << setw(10) << "TASHKENT" << right << setw(10) << "To: " << left << setw(10) << destination << right << setw(20) << char(186) << setw(30) << char(179) << endl;
	cout << right << setw(10) << char(179) << setw(70) << char(186) << right << setw(10) << "Seat: " << left << setw(19) << seat << char(179) << endl;
	cout << right << setw(10) << char(179) << setw(20) << "Date: " << setw(20) << "Gate: " << setw(20) << "Seat: " << setw(10) << char(186) << setw(30) << char(179) << endl;
	cout << right << setw(10) << char(179) << setw(25) << date << setw(15) << gate << setw(20) << seat << setw(10) << char(186) << right << setw(10) << "To: " << left << setw(19) << destination << char(179) << endl;
	cout << right << setw(10) << char(179) << setw(70) << char(186) << setw(30) << char(179) << endl;
	cout << setfill(' ') << setw(10) << char(192) << setfill(char(196)) << setw(70) << char(208) << setw(30) << char(217) << endl;
}
