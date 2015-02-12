/* 
 * H3 Program
 * To Understand How to Declare and Manipulate Multi Dimensional Arrays in C++,
 * And How to Design and Use Functions
 * By Shima Azizzadeh-Roodpish
 * 12 Feb 2015
 * No Copyright
 */
 
// External Libraries
 
#include <iostream>
#include <string>
#include <fstream>
using namespace std;
 
// Main Program.
// Return Zero on Success, Non-Zero in case of Failure.

int main () {
     
    // Defining Variables' Type

    string inputfilename, outputfilename = "shima.out", errorfilename = "shima.err", i, first, second;
    int num_of_stations = 0, num_of_instruments = 0, x, y, third = 0, m, n, row=-1, col=-1, num = 0, correct=0, failed=0;
    int sm = 0, sl = 0, nsm = 0, nlm = 0, im = 0, il = 0; nim = 0, nil = 0;
    // Prompt User for Input File Name.

    cout << "Enter input file name: ";
    cin >> inputfilename;
    ifstream inputfile;
    inputfile.open(inputfilename.c_str());

    // Check to Make Sure the File Is Opened Properly

    if ( !inputfile.is_open() ) {
        cout << "Input file does not exist!" << endl;
        return 1;
    }   
    
    // Preparing output file and error file
    
    ofstream outputfile;
    ofstream errorfile;
    outputfile.open(outputfilename.c_str());
    errorfile.open(errorfilename.c_str());
    
    // Reading Number of Stations of the Top as Integer

    inputfile >> num_of_stations;
    cout << "Number of Stations: " << num_of_stations << endl;
    
    // Checking for the Valid Number of Stations

    if ( ( num_of_stations <= 0 ) || ( num_of_stations > 100 ) ) {
        cout << "Number of Stations is not Valid!" << endl;
        return 2;
    }    
    
    // Reading Number of Instruments of the Top as Integer

    inputfile >> num_of_instruments;
    cout << "Number of Instrument: " << num_of_instruments << endl;   
    
    // Checking for the Valid Number of Instrument
    
    if ( ( num_of_instruments <= 0 ) || ( num_of_instruments > 10 ) ) {
        cout << "Number of Instrument is not Valid!" << endl;
        return 3;
    }

    // Defining Array and Reading the Stations' Name

    string station_name [100];
    for( x = 0; x <= ( num_of_stations - 1 ) ; x++ ) {
        inputfile >> station_name[x];
    }    
    cout << "Stations read." << endl;
    cout << station_name[0]<< endl;
    cout << station_name[1]<<endl;
    cout << station_name[2]<<endl;
    cout << station_name[3]<<endl;
    cout << station_name[5]<<endl;

    // Defining Array and Reading the Instruments' Name
    
    string instrument_name [10];
    for( y = 0; y <= ( num_of_instruments - 1 ); y++ ) {
        inputfile >> instrument_name[y];
    }  
    cout << "Instruments read." << endl;

    // Defining Array for Table
    
    int table [num_of_stations] [num_of_instruments];
       
    // Reading Other Information and Putting Them in Table
    
    cout << "Reading entries ... " << endl;
    while ( inputfile >> i ) { 
        num = 1 + num;
        inputfile >> first;
        inputfile >> second;
        inputfile >> third;
        for ( m = 0; m <= ( num_of_stations - 1 ); m++ ) {
            if ( station_name[m] == first ) { 
            row = m;
            }
        }
        for ( n = 0; n <= ( num_of_instruments - 1 ); n++ ) {
            if ( instrument_name[n] == second ) {
            col = n;
            }
        }
        if ( row == -1 ) {
            cout << "Warning: There is a problem with the name of the station in entry " << num << " . " << first << " is not valid and is ignored" << endl;
            errorfile << "Warning: There is a problem with the name of the station in entry " << num << " . " << first << " is not valid and is ignored" << "\n" ;
            errorfile << endl;
            failed = failed + 1;
        }
        else {
            if ( col == -1 ) {
                cout << "Warning: There is a problem with the name of the instrument in entry " << num << " . " << second << " is not valid and is ignored" << endl;
                errorfile << "Warning: There is a problem with the name of the instrument in entry " << num << " . " << second << " is not valid and is ignored" << "\n" ;
                errorfile << endl;
                failed = failed + 1;
            }
            else {
                if ( third < 0 ) {
                    cout << "Warning: There is a problem with number of events in entry " << num << " . " << third << " is negative and is ignored" << endl;
                    errorfile << "Warning: There is a problem with number of events in entry " << num << " . " << third << " is negative and is ignored" << "\n" ;
                    errorfile << endl;
                    failed = failed + 1;
                }
                else {    
                    table [row][col] = table [row][col] + third;
                    correct = correct + 1;
                }    
            }
        }
    }            
              
    cout << "Total of " << correct << " entries processed correctly and total of " << failed << " entries ignored." << endl;
    errorfile << "Total of " << correct << " entries processed correctly and total of " << failed << " entries ignored." << endl;
    
    cout << "Generating report ... " << endl;
    cout << "Completed." << endl;
    
    // Output file
    
    outputfile << "Seismic Events Summary Report" << endl;
    outputfile << "Station   " << instrument_name[] << endl;
    for ( k = 0; k <= ( num_of_stations - 1 ); k++) {
        outputfile << station_name [k] << table [k][] << endl;
    }
    
    outputfile << "Total number of events per station" << endl;

    outputfile << "Total number of events per instrument" << endl;
    
    outputfile << "Station with the most record is " << sm << " with " << nsm << " events" << endl;
    outputfile << "Station with the least record is " << sl << " with " << nsl << " events" << endl;
    outputfile << "Instrument with the most record is " << im << " with " << nim << " events" << endl;
    outputfile << "Instrument with the least record is " << il << " with " << nil << " events" << endl;

    inputfile.close ();
    outputfile.close ();
    errorfile.close ();
    
    return 0;
}
 
 
