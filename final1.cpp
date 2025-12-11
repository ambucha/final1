#include <iostream>
#include <fstream>
#include <map>
#include <string>
using namespace std;

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
    cout << "All airport traffic coutns:" << endl;

    // go through the map and print out the data
    for(auto const& a : airports){
        cout << a.first << " " << a.second << endl;
        // this print outs the airport name followed by the traffic count
    }

    // alright off to milestone 2 now

    return 0;
}