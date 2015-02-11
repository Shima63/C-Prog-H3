/* 
 * Prime Numbers Program
 * To Understand C++ Iteration Statements,
 * And How to Read Input from and Write Output to Text Files
 * By Shima Azizzadeh-Roodpish
 * 29 Jan 2015
 * No Copyright
 */
 
// External Libraries
 
#include <iostream>
#include <string>
#include <fstream>
using namespace std;
 
// Main Program.
// Return Zero on Success.
// Return One If the Input and Two If the Output Is Not Right.

int main () {
     
    // Defining Variables' Type

    string inputfilename, outputfilename;
    int i, x, factor, num = 0, p_num = 0, non_p_num = 0;
    int max_num, min_num, max_p_num, min_p_num, max_non_p_num, min_non_p_num;
    double sum_num, sum_p_num, sum_non_p_num, avg_num, avg_p_num, avg_non_p_num;
    
    // Prompt User for Input File Name.

    cout << "Enter input file name: ";
    cin >> inputfilename;

    // ifstream Is an INPUT File Stream
    
    ifstream inputfile;
    
    // c_str Is a Function to Convert inputfilename to a C String

    inputfile.open(inputfilename.c_str());

    // Check to Make Sure the File Is Opened Properly

    if ( !inputfile.is_open() ) {
        cout << "File does not exist!" << endl;
        return 1;
    }   
    
    // Prompt User for Output File Name.

    cout << "Enter output file name: ";
    cin >> outputfilename;
    
    // ofstream is an OUTPUT File Stream
    
    ofstream outputfile;
    
    // c_str Is a Function to Convert outputfilename to a C String

    outputfile.open(outputfilename.c_str());
    
    // Check That the Output File Is Opened Properly 
    
    if ( !outputfile.is_open() ) {
        cout << "Cannot open output file!" << endl;
        return 2;
    } 
                
    // Finding Prime and Non_prime Numbers, Max, Min and Sum

    while ( inputfile >> i ) {
        factor = 0;
        sum_num = sum_num + i;
        num = num + 1;
        if ( num == 1 ) {
            max_num = i;
            min_num = i;
        }
        else {
            if ( max_num < i ) {
                max_num = i;
            }    
            if ( min_num > i ) {
                min_num = i;
            }
        }          
        
        // Putting Negative Ones as Non-Prime.
        
        if ( i <= 0 ) { 
            sum_non_p_num = sum_non_p_num + i;
            non_p_num = non_p_num + 1;
            if ( non_p_num == 1 ) { 
                max_non_p_num = i;
                min_non_p_num = i;
            }
            else {
                if ( max_non_p_num < i ) {
                    max_non_p_num = i;
                }    
                if ( min_non_p_num > i ) {
                    min_non_p_num = i;
                }
            }    
        }
        else {
            for( x = 2; x <= i; x++ ) {
                if ( i % x == 0 ) {
                    factor++;    // Counting Number of Factors
                }
            }
                                      
            if ( factor != 1 ) {
                sum_non_p_num = sum_non_p_num + i;
                non_p_num = non_p_num + 1;
                if ( non_p_num == 1 ) { 
                    max_non_p_num = i;
                    min_non_p_num = i;
                }
                else {
                    if ( max_non_p_num < i ) {
                        max_non_p_num = i;
                    }
                    if ( min_non_p_num > i ) {
                        min_non_p_num = i;
                    }
                }    
            }
            else {
                sum_p_num = sum_p_num + i;
                p_num = p_num + 1;
                if ( p_num == 1 ) { 
                    max_p_num = i;
                    min_p_num = i;
                }
                else {
                    if ( max_p_num < i ) {
                        max_p_num = i;
                    }
                    if ( min_p_num > i ) {
                        min_p_num = i;
                    }
                }    
                     
                // File Outputs

                outputfile << i << "\n" ;
                outputfile << endl;
                     
            }             
        }   
    }
       
    // Finding Average, We Can Also Do It Directly in Output.

    avg_num = sum_num / num;
    avg_p_num = sum_p_num / p_num;
    avg_non_p_num = sum_non_p_num / non_p_num;
    
    // Terminal Outputs

    cout << "Number of all is: " << num << endl;
    cout << "Number of primes is: " << p_num << endl;
    cout << "Number of non_primes is: " << non_p_num << endl;
    cout << "Maximum of (all, prime, non-prime) is: " << max_num << ", " << max_p_num << ", " << max_non_p_num << endl;
    cout << "Minimum of (all, prime, non-prime) is: " << min_num << ", " << min_p_num << ", " << min_non_p_num << endl;    
    cout << "Average of (all, prime, non-prime) is: " << avg_num << ", " << avg_p_num << ", " << avg_non_p_num << endl;
    cout << "The End." << endl;

    inputfile.close ();
    outputfile.close ();
    
    return 0;
}
 
 
