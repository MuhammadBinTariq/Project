#include <iostream>
#include <iomanip>

using namespace std;

int main() 
{
    int symarr[9] = {1,2,9,3,4,5,6,7,8};
    int *p = symarr;
    int dim = 2;

    for (int i = 0; i <  dim; ++i) 
    {
        for (int j = 0; j <  dim; ++j) 
        {
            cout << "+-----+ ";
        }

        cout << '\n';

        for (int j = 0; j <  dim; ++j) 
        {
            cout << "|     | ";
        }

        cout << '\n';

        for (int j = 0; j <  dim; ++j) 
        {
            cout << "| " << setw(2) << *((p+i*dim)+j) << "  | ";
        }

        cout << '\n';

        for (int j = 0; j <  dim; ++j) 
        {
            cout << "|     | ";
        }

        cout << '\n';

        for (int j = 0; j <  dim; ++j) 
        {
            cout << "+-----+ ";
        }

        cout << '\n';
    }

    return 0;
}