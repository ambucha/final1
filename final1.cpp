#include <iostream>
#include <fstream>
#include <map>
#include <string>
using namespace std;

// lets make a functino to print inside a given range, tbh this is super similar to the last mielstone, just the if conditions inside the loop are gonna be different
// returns nothing and takes the map as an argument
void printRange(const map<string,int>& airports);

int main() {
    // lets start with the first part, getting the data
    // start by opening the file (as well as making the map
    map<string,int> airports;
    string file = "210-final-1-FA25.txt";
    ifstream input(file);

    // now make sure the file opens properly
    if(!input){
        cout << "ERROR: Couldn't open the file" << endl;
        return 1;
    }

    // next up lets set up the strings to collect the inputs
    string origin;
    string destination;

    // now lets insert into the map if they are missing, as well as incrementing them
    // so set up a while loop that goes as long is there are lines, we can set it up so the lines themselves are read in the while statement itself to be efficient
    while(input >> origin >> destination){
        // now that we have the data collected now we gotta start putting it into the map
        // we just care about traffic, not where the flight comes from etc, so we just need to increment each time we see teh airport
        airports[origin]++;
        airports[destination]++;
        // increments each time an airport, wether it be the origin or destination, is seen
    }

    // ok now we want to display it to the user
    cout << "All airport traffic counts:" << endl; 

    // go through the map and print out the data
    for(auto const& a : airports){
        cout << a.first << " " << a.second << endl;
        // this print outs the airport name followed by the traffic count
    }

    // alright off to milestone 2 now
    // set up a for loop to find the max count, then set up a for loop to find the airports with that max count
    // this way ties will be allowed
    int max = 0;
    for(const auto& a : airports){
        if(a.second > max){
            max = a.second;
            // this sets it up so that we go through the airports and find what the maximum traffic is
        }
    }

    // now we use this in order to fin dhte airports with the most traffic, since we will be searching through every airport with the given traffic, the airports with the same triffic will all be displayed
    // was outputting ugly needs an extra space
    cout << endl << "Busiest airport(s) with count " << max << ":" << endl;
    for(const auto &a : airports){
        if(a.second == max){
            cout << a.first << " " << a.second << endl;
            // display the data for the busiest airports
        }
    }

    // milestone 3 time
    printRange(airports);

    return 0;
}

void printRange(const map<string,int>& airports){
    int high;
    int low;


    // prompt for rnages
    cout << "Enter min of the range: ";
    cin >> low;
    cout << "Enter max of the range: ";
    cin >> high;

    // output airports in that range
    cout << "Airports with traffic in range [" << low << ", " << high << "]:" << endl;
    for(const auto &a : airports){
        if(a.second >= low && a.second <= high){
            cout << a.first << " " << a.second << endl;
            // display the data for the airports within the given range
        }
    }

    cout << endl;
}