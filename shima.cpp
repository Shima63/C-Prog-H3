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
#include <iomanip>
using namespace std;
 
// Main Program.
// Return Zero on Success, Non-Zero in case of Failure.

int main () {
     
    // Defining Variables' Type

    string inputfilename, outputfilename = "shima.out", errorfilename = "shima.err", i;
    string first, second, sm, sl, im, il;
    int num_of_stations = 0, num_of_instruments = 0, third = 0, num = 0, x, y, m, n, k, row, col;
    int tem = 0, temp = 0, factor = 0, nsm = 0, nsl = 0, nim = 0, nil = 0, correct = 0, failed = 0;
    
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
    errorfile << "Number of Stations: " << num_of_stations << endl;

    // Checking for the Valid Number of Stations

    if ( ( num_of_stations <= 0 ) || ( num_of_stations > 100 ) ) {
        cout << "Number of Stations is not Valid!" << endl;
        return 2;
    }    
    
    // Reading Number of Instruments of the Top as Integer

    inputfile >> num_of_instruments;
    cout << "Number of Instrument: " << num_of_instruments << endl;   
    errorfile << "Number of Instrument: " << num_of_instruments << endl;   

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
    errorfile << "Stations read." << endl;

    // Defining Array and Reading the Instruments' Name
    
    string instrument_name [10];
    for( y = 0; y <= ( num_of_instruments - 1 ); y++ ) {
        inputfile >> instrument_name[y];
    }  

    // Defining Array for Table
    
    int table [100][10] = {0};

    // Reading Other Information and Putting Them in Table
    
    cout << "Reading entries ... " << endl;
    errorfile << "Reading entries ... " << endl;
    
    while ( inputfile >> i ) { 
        
        // Finding Total Number of Entries
        
        num = 1 + num;

        // Reading the Three Entries
        
        first = i;
        inputfile >> second;
        inputfile >> third;

        // Initializing Row and Col Elements of Table
        
        row = -1;
        col = -1;
        
        // Searching in Stations' Name
         
        for ( m = 0; m <= ( num_of_stations - 1 ); m++ ) {
            if ( station_name[m] == first ) { 
            row = m;
            }
        }
        
        // Searching in Instrument' Name

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
    errorfile << "Generating report ... " << endl;

    // Output file
    
    outputfile << "Seismic Events Summary Report" << endl;
    
    // Writing the First Row
    
    outputfile << setw (12) << left << "Station"; // Assumed 10 Char for the Name of Station +2 Additional Space for Enough Distance
    for ( n = 0; n <= ( num_of_instruments - 1 ); n++ ) {
        outputfile << setw (17) << left << instrument_name[n]; // Assumed 15 Char for the Name of Instrument +2 Additional Space for Enough Distance
    }
    
    // Writing Other Rows
    
    for ( m = 0; m <= ( num_of_stations - 1 ); m++ ) {
        outputfile << endl;
        outputfile << setw (12) << left << station_name[m];
        for ( n = 0; n <= ( num_of_instruments - 1 ); n++ ) {
            outputfile << setw (17) << left << table[m][n];
        }       
    }
    
    // Total Number of Events per Station
    
    outputfile << endl << "Total number of events per station " << endl;
    outputfile << setw (12) << left << "Station" << "Total" << endl;
    factor = 0;
    for ( m = 0; m <= ( num_of_stations - 1 ); m++ ) {
        outputfile << setw (12) << left << station_name[m];
        tem = 0;
        factor = factor + 1;
        for ( n = 0; n <= ( num_of_instruments - 1 ); n++ ) {
            tem = tem + table[m][n];
        }
        if ( factor == 1 ) {
            nsm = tem;
            nsl = tem;
            sm = station_name[m];
            sl = station_name[m];
        }
        else {
            if ( nsm < tem ) {
                nsm = tem;
                sm = station_name[m];
            } 
            else { 
                if ( nsm == tem ) {
                    sm.append ( " , " );
                    sm.append ( station_name[m] );
                }  
            }    
            if ( nsl > tem ) {
                nsl = tem;
                sl = station_name[m];
            }
            else {
                if ( nsl == tem ) {
                    sl.append ( " , " );
                    sl.append ( station_name[m] );
                }    
            }
        }
        outputfile << tem << endl;
    }

    // Total Number of Events per Instrument
 
    outputfile << endl << "Total number of events per Instrument " << endl;
    outputfile << setw (17) << left << "Instrument" << "Total" << endl;
    factor = 0;
    for ( n = 0; n <= ( num_of_instruments - 1 ); n++ ) {
        outputfile << setw (17) << left << instrument_name[n];
        tem = 0;
        factor = factor + 1;
        for ( m = 0; m <= ( num_of_stations - 1 ); m++ ) {
            tem = tem + table[m][n];
        }
        if ( factor == 1 ) {
            nim = tem;
            nil = tem;
            im = instrument_name[n];
            il = instrument_name[n];
        }
        else {
            if ( nim < tem ) {
                nim = tem;
                im = instrument_name[n];
            }
            else {
                if ( nim == tem ) {
                    im.append ( " , " );
                    im.append ( instrument_name[n] );
                }
            }            
            if ( nil > tem ) {
                nil = tem;
                il = instrument_name[n];
            }
            else {
                if ( nil == tem ) {
                    il.append ( " , " );
                    il.append ( instrument_name[n] );
                }
            }
        }
        outputfile << tem << endl;
        temp = temp + tem;
    }

    outputfile << endl << "Total number of entries is " << num << endl;
    outputfile << "Total number of events is " << temp << endl;
    outputfile << "Station with the most record is " << sm << " with " << nsm << " events" << endl;
    outputfile << "Station with the least record is " << sl << " with " << nsl << " events" << endl;
    outputfile << "Instrument with the most record is " << im << " with " << nim << " events" << endl;
    outputfile << "Instrument with the least record is " << il << " with " << nil << " events" << endl;

    cout << "Completed." << endl;
    errorfile << "Completed." << endl;

    inputfile.close ();
    outputfile.close ();
    errorfile.close ();
    
    return 0;
}
 
 
