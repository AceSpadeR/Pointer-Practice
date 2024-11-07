#include <iostream>
#include <string>
#include <chrono>
#include <cstdlib>
#include <ctime>
#include "list.h"
using namespace std;

int main() {
    cout << "Pointer Practice" << endl;
    bool getData = true;
    string input;
    int number;
    list<long> List;
    srand(static_cast<unsigned int>(time(0)));
    // Get input for List
    while(getData){
        cout << "Enter number for List size:" << endl;
        cin >> input;
         try{
            number = stoi(input);
            for (int i = 0; i < number; i++)
            {
                int random = rand() % 100;
                 List.push(random);
            }
            break;
        }
        catch(invalid_argument &e)
        {
           cout << "Invalid input." << endl;
        }
        
    }
        
          
    list<long> InsertList = List.createTempList();
    list<long> MergeList = List.createTempList();
    list<long> SelectionList = List.createTempList();
    cout << "-----------------------------------------"<< endl;
    cout << "Total elements:" << List << endl;
    
    
    

    auto startBubble = chrono::high_resolution_clock::now();
    List.bubbleSort();
    auto endBubble = chrono::high_resolution_clock::now(); // End timer
    chrono::duration<double> durationBubble = endBubble - startBubble;
    cout << "Bubble Sort took " << durationBubble.count() << " seconds."<< endl;

    cout << "After:" << List << endl;
    cout << "-----------------------------------------"<< endl;
    cout << "Before:" << InsertList << endl;
    


    auto startInsertion = chrono::high_resolution_clock::now();
    InsertList.insertionSort();
    auto endInsertion = chrono::high_resolution_clock::now(); // End timer
    chrono::duration<double> durationInsertion = endInsertion - startInsertion;
    cout << "Insertion Sort took " << durationInsertion.count() << " seconds."<< endl;


    cout << "After:" << InsertList << endl;
    cout << "-----------------------------------------"<< endl;
    cout << "Before:" << SelectionList << endl;
    



    auto startSelection = chrono::high_resolution_clock::now();
    SelectionList.selectionSort();
    auto endSelection = chrono::high_resolution_clock::now(); // End timer
    chrono::duration<double> durationSelection = endSelection - startSelection;
    cout << "Selection Sort took " << durationSelection.count() << " seconds."<< endl;

    cout << "After:" << SelectionList << endl;
    cout << "-----------------------------------------"<< endl;
    cout << "Before:" << MergeList << endl;
    

    auto startMerge = chrono::high_resolution_clock::now();
    MergeList.mergeSort();
    auto endMerge = chrono::high_resolution_clock::now(); // End timer
    chrono::duration<double> durationMerge = endMerge - startMerge;
    cout << "Merge Sort took " << durationMerge.count() << " seconds."<< endl;

    cout << "After:" << MergeList << endl;
    
    return 0;
}