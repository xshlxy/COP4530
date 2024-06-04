//libraries
#include <iostream>
#include <fstream>
#include <sstream>
#include <list>
#include <string>
using namespace std;

//struct definition
struct Cities
{
    int population;
    string names,countries;
};

//prototypes
void displayAnswer(const list<Cities>& l, const string& s, int n);

int main()
{
    //getting input to see how many matches
    int n;
    cout << "How many top matches do you want to look for?" << endl;
    cin >> n;
    cin.ignore();

    //list
    list<Cities> citiesList;
    ifstream inputFile("cities2.txt");
    if (inputFile.is_open())
    {
        string line;
        while(getline(inputFile, line))
        {
            // Parse the line to extract city data
            stringstream ss(line);
            int population;
            string name,country;
            ss >> population;
            ss.ignore();
            getline(ss, name,',');
            getline(ss, country);

            // define the city list and push data into it
            Cities city = {population, name, country};
            citiesList.push_back(city);
        }
        inputFile.close();
    }
    else
    {
        cerr << "Error opening file!" << endl;
        return 1;
    }

    //definition
    string choice;

    //menu and making it work
    cout << "Enter the initial letters of a city to find its similarly "
            "named cities, ranked by population (this is case-"
            "sensitive)." << endl;
    do
    {
        if (!getline(cin, choice))
            break; // Exit loop if input fails

        displayAnswer(citiesList, choice, n);
        cout << "Another city? (CTRL-D to exit)\n";
    } while (true);
    return 0;
}


// display data function

void displayAnswer(const list<Cities>& l, const string& s, int n)
{
    cout << "TOP MATCHES FOR '" << s << "' ARE:" << endl;
    int rank = 1;
        for (const Cities& city : l)
        {

            // Extract a substring of the desired length
            // Adjust length as needed
            string cityBeginning = city.names.substr(0, s.length());

            //check if the beginning of the city is the same as input
            if (cityBeginning == s)
            {
                cout << "\t" << rank << ") " << city.names << "," << city.countries
                << " has a population of " << city.population << endl;
                rank++;
            }
            //if counter reaches the amount n then it stops
            if(rank > n)
                break;
    }


    //if there's no city then it says so
    if (rank == 1)
    {
        cout << "City not found." << endl;
    }
}