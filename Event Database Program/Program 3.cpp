// Alexander Bowman
// 28MAR19
// Program 3
// Program defines a structure for event details loads and reads
// a txt file with event details and inputs it into the struct.
// Program allows you to add an event, search events by the name
// and date struct members and allows you to display all events.
// Program also prompts you to save updated database to another file.

#include <iostream>
#include <fstream>
#include <ostream>
#include <iomanip>

using namespace std;
    // Enum declaration for seasom
enum EventSeason {Winter, Spring, Summer, Fall};
    // Time structure declaration
struct EventTime
{
    int date; // Data variable YYMMDD
    int startTime; // Event start time integer
    int endTime; // Event end time integer
    int totHours; // Event total time integer
};
    // Main event structure declaration
struct EventStruct
{
    string eventName; // Event name variable
    string eventDesc; // Event description string
    int totGuests;  // Event total guests
    EventTime timeStruc; // Time structure variable declaration
    EventSeason season; // Season enum declaration
};

    // Precondition: int variable and Structure Array is passed.
    // Postcondition: A Date or Name is ran against Event Name or Event Date
    // Function takes the number of Arrays (int) and takes Event structure array
    // than either takes a name or date from cin and runs it against all structure
    // Event names or Event Dates and displays full struct if two are equal. And loops
    // until user quits.
void searchNameDate(int num, EventStruct EventData[100]);
    // Precondition: int variable by ref and Structure Array is passed to function.
    // Postcondition: Structure is incremented by 1 and all fields are filled
    // Function takes number of Arrays (int) by reference and Structure Array and
    // increments Array up by 1 and fills all members of structure and loops until
    // user quits.
void addNewEvent(int& num, EventStruct EventData[100]);
    // Precondition: inData of ifstream is passed by ref, int variable by ref and
    // Structure Array is passed.
    // Postcondition: Structure Array Members are filled until ifstream has no more data
    // Function takes file name as string opens file and loads all data into Structure
    // Array and counts Arrays
void getFileLoad(ifstream& inData, int& num, EventStruct EventData[100]);
    // Precondition: outData of ofstream is passed by ref, int var by ref, Structure
    // Array is passed.
    // Postcondition: Structure Array has been written to a file.
    // Function increments through Structure Array and writes all members to
    // offstream.
void saveDatabase(ofstream& outData, int num, EventStruct EventData[100]);
    // Precondition: outData of ofstream is passed by ref, int var passed, Structure
    // Array is passed.
    // Postcondition: All members of Structure Array has been written to screen.
    // Function takes the number of Arrays and loops through each member of Structure
    // Array and prints to each member to screen.
void displayAllEvents (int num, EventStruct EventData[100]);
    // Precondition: int variable by ref and Structure Array is passed to function.
    // Postcondition: Array element is deleted and all elements are shifted down arrayCount
    // is incremented down 1
    // Function takes arrayCount and struct array searches by Event Name than deletes entire element
    // shifts all elements down and increments array count down 1.
void deleteEvent (int &num, EventStruct EventData[100]);

int main() // Main Func
{
        cout << "***********************************************************************************" << endl;
        cout << "                            EVENT DATABASE MANAGER V1                              " << endl;
        cout << "***********************************************************************************" << endl;

        char menu; // Char for switch condition
        char yesOrNo; // Char Y or N
        ifstream inData; // Opens in data stream
        ofstream outData; // Opens out data stream
        int arrayCount = 0; // int var for array increment
        EventStruct EventData[100]; // Declaring EventData Structure Array

        cout << endl << "Load an existing database file? Enter 'Y' for Yes or 'N' for No. ";
        cin >> yesOrNo;

            // While loop when yesOrNo != 'Y' or 'N'
        while (yesOrNo != 'Y' && yesOrNo != 'N')
        {
            cout << endl << "Invalid Entry. Enter 'Y' to save or 'N' to quit. ";
            cin >> yesOrNo;
        }

        if (yesOrNo == 'Y')
        {
            getFileLoad(inData, arrayCount, EventData);
        }
        cout << endl << endl;
        yesOrNo = 'Y'; // While loop priming read

            // While to loop Main Menu when yesOrNo = 'Y'
        while (yesOrNo == 'Y')
        {
            cout << "************************************************************************************" << endl;
            cout << "                                   MAIN MENU                                        " << endl;
            cout << "************************************************************************************" << endl << endl << endl;
            cout << "Event Count: " << arrayCount << endl;
            cout << "Choose from the Following Menu:" << endl << endl;
            cout << "Enter 'V' To View All Events." << endl;
            cout << "Enter 'F' To Search Database By Name Or Date." << endl;
            cout << "Enter 'A' To Add New Event." << endl;
            cout << "Enter 'D' To Delete an Event." << endl;
            cout << "Enter 'Q' To Quit." << endl;
            cin >> menu;

                // While to loop when char is not 'F', 'D', 'A' or 'Q'
            while (menu != 'F' && menu != 'D' && menu != 'A' && menu != 'Q' && menu != 'V')
            {
                cout << endl << "Incorrect Selection!" << endl;
                cout << "Enter 'V' To View All Events." << endl;
                cout << "Enter 'F' To Search Database By Name Or Date" << endl;
                cout << "Enter 'A' To Add New Event" << endl;
                cout << "Enter 'D' To Delete An Event" << endl;
                cout << "Enter 'Q' To Quit." << endl;
                cin >> menu;
                cout << endl;
            }

                // Main Menu Switch Statement
            switch (menu)
            {
                case 'V': displayAllEvents(arrayCount, EventData); // Case D: displayAllEvents Function Call
                            break;
                case 'F': searchNameDate(arrayCount, EventData); // Case F: searchNameDate Function Call
                            break;
                case 'A': addNewEvent(arrayCount, EventData); // Case A: addNewEvent Function Call
                            break;
                case 'D': deleteEvent(arrayCount, EventData); // Case D: deleteEvent Function Call
                            break;
                case 'Q':
                {
                    cout << endl << "Save a copy of your database? Enter 'Y' for Yes 'N' for No. ";
                    cin >> yesOrNo;
                    while (yesOrNo != 'Y' && yesOrNo != 'N')
                    {
                        cout << "Invalid Entry. Enter 'Y' to save or 'N' to quit. ";
                        cin >> yesOrNo;
                    }
                    if (yesOrNo == 'Y')
                    {
                        saveDatabase(outData, arrayCount, EventData); // saveDatabase Function Call
                        return 0;
                    }
                    else return 0;
                }
            }

            cout << "Enter 'Y' for Main Menu or 'N' to Quit. ";
            cin >> yesOrNo; // Return to Main Menu variable

                // While loop when yesOrNo is not 'Y' or 'N'
            while (yesOrNo != 'Y' && yesOrNo != 'N')
            {
                cout << "Invalid Entry. Enter 'Y' for Main Menu or 'N' to Quit. ";
                cin >> yesOrNo;
            }

            cout << endl;
        }

        cout << endl << "Save a copy of your database? Enter 'Y' for Yes 'N' for No. ";
        cin >> yesOrNo;

            // While loop if yesOrNo does not equal 'Y' or 'N'
        while (yesOrNo != 'Y' && yesOrNo != 'N')
        {
            cout << "Invalid Entry. Enter 'Y' to save or 'N' to quit. ";
            cin >> yesOrNo;
        }

            // If yesOrNo equals Y
        if (yesOrNo == 'Y')
                saveDatabase(outData, arrayCount, EventData); // saveDatabase Function Call
        else // else return 0;

        return 0;
}
    // Precondition: inData of ifstream is passed by ref, int variable by ref and
    // Structure Array is passed.
    // Postcondition: Structure Array Members are filled until ifstream has no more data
    // Function takes file name as string opens file and loads all data into Structure
    // Array and counts Arrays
void getFileLoad(ifstream& inData, int& num, EventStruct EventData[100])
{
    string fileName; // string for filename
    string tempSeason; // string for assigning season enum

        // do-while loop until valid file
    do
    {
        cout << "Enter valid filename for database: ";
        cin >> fileName; // Enters filename into variable
        inData.open (fileName.c_str()); // Converts to c string and opens file
        if(!inData) // If invalid file name prompt
        cout << "Invalid file!" << endl;
    }
    while (!inData); // Loop test until valid file

    cout << endl << "Database successfully loaded!" << endl;

        // while loop until eof
        // Assigns data from instream to struct members and
        // increments Structure Array until inData reaches eof
    while (!inData.eof())
    {
        getline(inData, EventData[num].eventName, ',');
        inData.ignore(100, ' ');
        inData >> EventData[num].timeStruc.date;
        inData.ignore(100, ',');
        inData >> EventData[num].timeStruc.startTime;
        inData.ignore(100, '-');
        inData >> EventData[num].timeStruc.endTime;
        inData.ignore(100, ',');
        inData >> EventData[num].timeStruc.totHours;
        inData.ignore(100, ',');
        inData >> EventData[num].totGuests;
        inData.ignore(100, ',');
        inData.ignore(100, ' ');
        getline(inData, tempSeason, '\n');

            // if statements for correct assignment to season enum
        if (tempSeason == "Winter")
                EventData[num].season = Winter;
        if (tempSeason == "Spring")
                EventData[num].season = Spring;
        if (tempSeason == "Summer")
                EventData[num].season = Summer;
        if (tempSeason == "Fall")
                EventData[num].season = Fall;

        getline(inData, EventData[num].eventDesc);
        inData.ignore(100, '\n');
        num++; // Array increment
    }

    cout << num << " Events successfully loaded into memory!" << endl; // Prompt for amt of events loaded into structure
}

    // Precondition: outData of ofstream is passed by ref, int var passed, Structure
    // Array is passed.
    // Postcondition: All members of Structure Array has been written to screen.
    // Function takes the number of Arrays and loops through each member of Structure
    // Array and prints to each member to screen.
void displayAllEvents (int num, EventStruct EventData[100])
{
    int x = 0; // Increment for Structure Array
    cout << endl << endl;
    cout << "***********************************************************************************" << endl;
    cout << "                                    ALL EVENTS                                     " << endl;
    cout << "***********************************************************************************" << endl << endl;

        // While x is less than amt of arrays
    while (x < num)
    {
        cout << "Event # " << x+1 << "." << endl;
        cout << "Event Title: " << EventData[x].eventName << endl;
        cout << "Event Date: " << EventData[x].timeStruc.date << endl;
        cout << "Event Description: " << EventData[x].eventDesc << endl;
        cout << "Event Total Guests: " << EventData[x].totGuests << endl;
        cout << "Event Start Time: " << setw(4) << setfill('0') << EventData[x].timeStruc.startTime << endl;
        cout << "Event End Time: " << setw(4) << setfill('0') << EventData[x].timeStruc.endTime << endl;
        cout << "Event Title: " << EventData[x].timeStruc.totHours << " Hrs." << endl;

        if (EventData[x].season == 0)
            cout << "Event Season: Winter." << endl;
        if (EventData[x].season == 1)
            cout << "Event Season: Spring." << endl;
        if (EventData[x].season == 2)
            cout << "Event Season: Summer." << endl;
        if (EventData[x].season == 3)
            cout << "Event Season: Fall." << endl;

        cout << endl << "***********************************************************************************" << endl;
        x++; // increment for Array
    }

}
    // Precondition: int variable by ref and Structure Array is passed to function.
    // Postcondition: Structure is incremented by 1 and all fields are filled
    // Function takes number of Arrays (int) by reference and Structure Array and
    // increments Array up by 1 and fills all members of structure and loops until
    // user quits.
void addNewEvent(int& num, EventStruct EventData[100])
{
    cout << endl;
    cout << "***********************************************************************************" << endl;
    cout << "                                   ADD FUNCTION                                    " << endl;
    cout << "***********************************************************************************" << endl << endl;
    char contExit;
    contExit = 'Y'; // While priming read

        // While loops when contExit = 'Y'
    while (contExit == 'Y')
    {
        string tempSeason;
        cout << "Enter event title: ";
        cin.ignore();
        getline(cin, EventData[num].eventName);
        cout << "Enter event date in YYMMDD format: ";
        cin >> EventData[num].timeStruc.date;
        cout << "Enter event description: ";
        cin.ignore();
        cin.clear();
        getline(cin, EventData[num].eventDesc, '\n');
        cout << "Enter event start time 0000-2400 format: ";
        cin >> EventData[num].timeStruc.startTime;

            // while loop when time is invalid
        while (EventData[num].timeStruc.startTime < 0 || EventData[num].timeStruc.startTime > 2400)
        {
            cout << "Invalid Entry! Enter start time 0000-2400 format: ";
            cin >> EventData[num].timeStruc.startTime;
        }

        cout << "Enter event end time 0000-2400 format: ";
        cin >> EventData[num].timeStruc.endTime;

            // while loop when time is invalid
        while (EventData[num].timeStruc.endTime < 0 || EventData[num].timeStruc.endTime > 2400)
        {
            cout << "Invalid Entry! Enter end time 0000-2400 format: ";
            cin >> EventData[num].timeStruc.endTime;
        }

        cout << "Enter length of event in hours: ";
        cin >> EventData[num].timeStruc.totHours;
        cout << "Enter total number of guests: ";
        cin >> EventData[num].totGuests;
        cout << "Enter Season (Winter, Spring, Summer, Fall): ";
        cin.ignore();
        cin >> tempSeason;
        cin.ignore();

            // while loop when tempSeason does not equal a season
        while (tempSeason != "Winter" && tempSeason != "Spring" && tempSeason != "Summer" && tempSeason != "Fall")
        {
            cout << "Incorrect Input! Enter Winter, Spring, Summer or Fall: ";
            cin >> tempSeason;
        }

            // if statements assign correct season to enum season
        if (tempSeason == "Winter")
            EventData[num].season = Winter;
        if (tempSeason == "Spring")
            EventData[num].season = Spring;
        if (tempSeason == "Summer")
            EventData[num].season = Summer;
        if (tempSeason == "Fall")
            EventData[num].season = Fall;

        num++; // Increment for structure array
        cout << endl << "Event successfully added!" << endl << endl;
        cout << "Add Another Event? Enter 'Y' for Yes or 'N' to Exit: ";
        cin >> contExit;

            // While loop when contExit does not equal Y or N
        while (contExit != 'Y' && contExit != 'N')
        {
            cout << "Incorrect Entry! Enter 'Y' to continue or 'N' to exit: ";
            cin >> contExit;
        }
    }
}

    // Precondition: int variable and Structure Array is passed.
    // Postcondition: A Date or Name is ran against Event Name or Event Date
    // Function takes the number of Arrays (int) and takes Event structure array
    // than either takes a name or date from cin and runs it against all structure
    // Event names or Event Dates and displays full struct if two are equal. And loops
    // until user quits.
void searchNameDate(int num, EventStruct EventData[100])
{
    cout << endl;
    cout << "***********************************************************************************" << endl;
    cout << "                                    SEARCH FUNCTION                                " << endl;
    cout << "***********************************************************************************" << endl << endl;
    char contExit;

    contExit = 'Y'; // While priming read

        // While loops when contExit = 'Y'
    while (contExit == 'Y')
    {
        bool match = true; // No match flag set to false
        int x = 0; // Array Increment
        string nameDate; // Search by name or date variable
        string nameSearch; // name search term
        int dateSearch; // date search term
        cout << "Search by Event Name or Date? Enter 'N' for Name or 'D' for Date: ";
        cin >> nameDate;

            // While loops when nameDate !+ equal 'N' or 'D'
        while (nameDate != "N" && nameDate != "D")
        {
            cout << "Incorrect Entry! Enter name to search by name or date to search by date: ";
            cin >> nameDate;
        }

            // If nameDate = 'N', search by name
        if (nameDate == "N")
        {
            cout << "Enter Event Name: ";
            cin >> nameSearch; // event name search variable

                // While loops x <= num
            while (x <= num)
            {
                    // if Event Name member equals search term
                    // structure is displayed
                if (EventData[x].eventName == nameSearch)
                {
                    match = false;
                    cout << "***********************************************************************************" << endl;
                    cout << "                                    EVENT FOUND                                    " << endl;
                    cout << "***********************************************************************************" << endl << endl;
                    cout << "Event # " << x+1 << "." << endl;
                    cout << "Event Title: " << EventData[x].eventName << endl;
                    cout << "Event Date: " << EventData[x].timeStruc.date << endl;
                    cout << "Event Description: " << EventData[x].eventDesc << endl;
                    cout << "Event Total Guests: " << EventData[x].totGuests << endl;
                    cout << "Event Start Time: " << setw(4) << setfill('0') << EventData[x].timeStruc.startTime << endl;
                    cout << "Event End Time: " << setw(4) << setfill('0') << EventData[x].timeStruc.endTime << endl;
                    cout << "Event Title: " << EventData[x].timeStruc.totHours << " Hrs." << endl;

                    if (EventData[x].season == 0)
                        cout << "Event Season: Winter." << endl;
                    if (EventData[x].season == 1)
                        cout << "Event Season: Spring." << endl;
                    if (EventData[x].season == 2)
                        cout << "Event Season: Summer." << endl;
                    if (EventData[x].season == 3)
                        cout << "Event Season: Fall." << endl;
                    }
                    x++; //x increment
            }

        }

            // Ff statement to search by date
        if (nameDate == "D")
        {
            cout << "Enter Date YYMMDD: ";
            cin >> dateSearch; // date variable search term

                // while loop to increment through structure array
            while (x <= num)
            {
                    // if event date member equals search term
                    // structure is displayed
                if (EventData[x].timeStruc.date == dateSearch)
                {
                    match = false;
                    cout << "***********************************************************************************" << endl;
                    cout << "                                    EVENT FOUND                                    " << endl;
                    cout << "***********************************************************************************" << endl << endl;
                    cout << "Event # " << x+1 << "." << endl;
                    cout << "Event Title: " << EventData[x].eventName << endl;
                    cout << "Event Date: " << EventData[x].timeStruc.date << endl;
                    cout << "Event Description: " << EventData[x].eventDesc << endl;
                    cout << "Event Total Guests: " << EventData[x].totGuests << endl;
                    cout << "Event Start Time: " << setw(4) << setfill('0') << EventData[x].timeStruc.startTime << endl;
                    cout << "Event End Time: " << setw(4) << setfill('0') << EventData[x].timeStruc.endTime << endl;
                    cout << "Event Title: " << EventData[x].timeStruc.totHours << " Hrs." << endl;

                    if (EventData[x].season == 0)
                        cout << "Event Season: Winter." << endl;
                    if (EventData[x].season == 1)
                        cout << "Event Season: Spring." << endl;
                    if (EventData[x].season == 2)
                        cout << "Event Season: Summer." << endl;
                    if (EventData[x].season == 3)
                        cout << "Event Season: Fall." << endl;
                    }

                    x++; // increment for array variable
            }
        }
        if (match)
            cout << endl << "NO MATCHES FOUND!" << endl << endl;
        cout << "Search Again? Enter 'Y' for yes or 'N' to exit: ";
        cin >> contExit; // continue or exit variable

            // While loop when contExit variable doesn't equal Y or N
        while (contExit != 'Y' && contExit != 'N')
        {
            cout << "Incorrect Entry! Enter 'Y' for yes or 'N' to exit: ";
            cin >> contExit;
        }
    }

}
    // Precondition: outData of ofstream is passed by ref, int var by ref, Structure
    // Array is passed.
    // Postcondition: Structure Array has been written to a file.
    // Function increments through Structure Array and writes all members to
    // offstream.
void saveDatabase(ofstream& outData, int num, EventStruct EventData[100])
{
    string fileName; // filename string
    int x = 0; // array increment variable

        // do-while outData is invalid
    do
        {
            cout << "Enter valid filename: ";
            cin >> fileName; // Enters filename into variable
            outData.open (fileName.c_str()); // Converts to c string and opens file
            if(!outData) // If invalid file name prompt
            cout << "Invalid file!" << endl;
        }
    while (!outData); // Loop test until valid file

        // while loop to increment through arrays
        // Outputs all members in each array to txt
    while (x < num)
    {
        outData << EventData[x].eventName << ", ";
        outData << EventData[x].timeStruc.date << ", ";
        outData << EventData[x].timeStruc.startTime << "-";
        outData << EventData[x].timeStruc.endTime << ", ";
        outData << EventData[x].timeStruc.totHours << ", ";
        outData << EventData[x].totGuests << ", ";

        if (EventData[x].season == 0)
            outData << "Winter" << endl;
        if (EventData[x].season == 1)
            outData << "Spring" << endl;
        if (EventData[x].season == 2)
            outData << "Summer" << endl;
        if (EventData[x].season == 3)
            outData << "Fall" << endl;

        outData << EventData[x].eventDesc << endl << endl;
        x++; // array increment variable
    }

    cout << "Database has been saved as: '" << fileName << "'." << endl;
}

    // Precondition: int variable by ref and Structure Array is passed to function.
    // Postcondition: Array element is deleted and all elements are shifted down arrayCount
    // is incremented down 1
    // Function takes arrayCount and struct array searches by Event Name than deletes entire element
    // shifts all elements down and increments array count down 1.
void deleteEvent (int &num, EventStruct EventData[100])
{
    bool match = true; // No match flag set to false
    string nameSearch; // name search term
    char yesNo; // yes no variable to delete
    char contExit; // continue/exit variable
    int delArray = 0; // variable num to delete
    contExit = 'Y'; // While priming read

    cout << "***********************************************************************************" << endl;
    cout << "                                DELETE FUNCTION                                    " << endl;
    cout << "***********************************************************************************" << endl << endl;

        // While loops when contExit = 'Y'
    while (contExit == 'Y')
    {
        cout << "Enter Event Name: ";
        cin >> nameSearch; // event name search variable

            // While loops x <= num
        while (delArray <= num)
        {
            // if Event Name member equals search term
            // structure is displayed
            if (EventData[delArray].eventName == nameSearch)
            {
                match = false;
                cout << "***********************************************************************************" << endl;
                cout << "                                    EVENT FOUND                                    " << endl;
                cout << "***********************************************************************************" << endl;
                cout << "Event # " << delArray+1 << "." << endl;
                cout << "Event Title: " << EventData[delArray].eventName << endl;
                cout << "Event Date: " << EventData[delArray].timeStruc.date << endl;
                cout << "Event Description: " << EventData[delArray].eventDesc << endl;
                cout << "Event Total Guests: " << EventData[delArray].totGuests << endl;
                cout << "Event Start Time: " << setw(4) << setfill('0') << EventData[delArray].timeStruc.startTime << endl;
                cout << "Event End Time: " << setw(4) << setfill('0') << EventData[delArray].timeStruc.endTime << endl;
                cout << "Event Title: " << EventData[delArray].timeStruc.totHours << " Hrs." << endl;

                if (EventData[delArray].season == 0)
                    cout << "Event Season: Winter." << endl;
                if (EventData[delArray].season == 1)
                    cout << "Event Season: Spring." << endl;
                if (EventData[delArray].season == 2)
                    cout << "Event Season: Summer." << endl;
                if (EventData[delArray].season == 3)
                    cout << "Event Season: Fall." << endl;

                cout << endl << "Delete Event? Enter 'Y' for yes or 'N' for no: ";
                cin >> yesNo;
                cout << endl;

                while (yesNo != 'Y' && yesNo != 'N')
                {
                    cout << "Incorrect Entry! Enter 'Y' for yes or 'N' for no. ";
                    cin >> yesNo;
                }

                if (yesNo == 'Y')
                {
                    for (delArray; delArray < num; delArray++)
                        EventData[delArray] = EventData[delArray+1];
                    num--;
                }

            }

            delArray++;
        }

        if (match)
            cout << endl << "NO MATCHES FOUND!" << endl << endl;
        delArray = 0;
        cout << "Search Again? Enter 'Y' for Yes or 'N' to Exit: ";
        cin >> contExit; // continue or exit variable
        cout << endl;

            // While loop when contExit variable doesn't equal Y or N
        while (contExit != 'Y' && contExit != 'N')
        {
            cout << "Incorrect Entry! Enter 'Y' for Yes or 'N' to Exit: ";
            cin >> contExit;
            cout << endl;
        }
    }
}

