#include <iostream>
#include <fstream>
#include <map>
#include <string>
using namespace std;

// Milestone 3
void printRange(const map<string,int>& airports, int low, int high);

int main() {

    // Milestone 1
    map<string,int> airports;
    string file = "210-final-1-FA25.txt";
    ifstream input(file);

    if(!input){
        cout << "ERROR: Couldn't open the file" << endl;
        return 1;
    }

    string origin;
    string destination;

    while(input >> origin >> destination){
        airports[origin]++;
        airports[destination]++;
    }

    cout << "All airport traffic counts:" << endl; 

    for(auto const& a : airports){
        cout << a.first << " " << a.second << endl;
    }

    int max = 0;
    for(const auto& a : airports){
        if(a.second > max){
            max = a.second;
        }
    }

    // Milestone 2
    cout << endl << "Busiest airport(s) with count " << max << ":" << endl;
    for(const auto &a : airports){
        if(a.second == max){
            cout << a.first << " " << a.second << endl;
        }
    }
    cout << endl;

    // Milestone 3
    printRange(airports,8,18);
    printRange(airports,3,6);

    return 0;
}

// Milestone 3
void printRange(const map<string,int>& airports, int low, int high){
    cout << "Airports with traffic in range [" << low << ", " << high << "]:" << endl;
    for(const auto &a : airports){
        if(a.second >= low && a.second <= high){
            cout << a.first << " " << a.second << endl;
        }
    }

    cout << endl;
}