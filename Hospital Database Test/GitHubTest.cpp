#include "class.h"
#include <iostream>
#include <vector>

using namespace std;

int main()
{
    Hospital Hospital1;
    Hospital Hospital2;
    Hospital1.fillDatabase();
    Hospital2.fillDatabase();


    Hospital1.displayDatabase();
    
    cout << endl << endl << "Next database..." << endl;

    Hospital2.displayDatabase();

   


   
    return 0;
}
