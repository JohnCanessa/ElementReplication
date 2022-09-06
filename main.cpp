#include <iostream>
#include <exception>

using namespace std;


/// <summary>
/// It is clear that the person describing the problem 
/// in the video does not understand C++.
/// </summary>
void elementReplication()
{

    // **** initialization ****
    int n{0};
    int pos{0};

    // **** prompt for and read n ****
    cout << ">>> size of array: ";
    cin >> n;

    // ???? ????
    cout << "elementReplication <<< n: " << n << endl;

    // **** allocate memory for array ****
    //int arr[n];             // !!! does NOT COMPILE !!!
    int* ar = (int*)calloc(n + 1, sizeof(int));

    // ???? test memory allocation failure ????
    //ar = NULL;

    // **** check if malloc failed ****
    if (ar == NULL)
    {
        throw bad_alloc();
    }

    // **** prompt for values and populate array ****
    cout << ">>> array elements: ";
    int* p = ar;
    for (int i = 0; i < n; i++, p++)
    {
        cin >> *p;
    }

    // ???? ????
    cout << "elementReplication <<< ar: ";
    for (int i = 0; i < n; i++)
        cout << ar[i] << ' ';
    cout << endl;
 
    // **** request and accept position of element to replicate ****
    cout << ">>> position of element to replicate: ";
    cin >> pos;

    // **** verify position to replicate ****
    if (pos >= 0 && pos < n)            // REPLACE n with n - 1
    {

        // **** for the looks ****
        cout << "<<< ar: ";

        // **** replicate this element
        //      may be OUT OF BOUNDS (like in the demo code) ****
        ar[n] = ar[pos];

        // **** display contents of array ****
        for (int i = 0; i <= n; i++)
        {
            cout << ar[i] << " ";
        }
    
        // **** for the looks ****
        cout << endl;
    }

    // **** need to throw an exception ****
    else
    {
        throw runtime_error("elementReplication - array index out of range");
    }
}


/// <summary>
/// Test scaffold
/// </summary>
/// <returns></returns>
int main()
{

    // **** initialization ****
    int retVal{0};

    // **** try-catch block ****
    try
    {
        elementReplication();
    }
    catch (bad_alloc &e)
    {
        // **** memory allocation exception ****
        cerr << "main <<< " << e.what() << endl;

        // **** flag the issue ****
        retVal = -1;
    }
    catch (runtime_error &e)
    {
        // **** runtime exception ****
        cerr << "main <<< " << e.what() << endl;

        // **** flag the issue ****
        retVal = -2;
    }
    catch (exception& e)
    {

        // **** other exception ****
        cerr << "main <<< EXCEPTION - " << e.what() << endl;

        // **** flag the issue ****
        retVal = -3;
    }

    // **** assume all went well ****
    return retVal;
}