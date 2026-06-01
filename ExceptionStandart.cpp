#include <iostream>
#include <exception>
#include <array>
using namespace std;

int main()
{
    cout << "Awal program" << endl;//penanda 1
    try
    {
        //deklarasi array data dg panjang index 3
        array <int, 3> data = { 1, 2, 3 };
        //memanggial array element ke 5 bararti akan error
        cout << data.at(5) << endl;
    }
    //codisi jika eorr dlm try
    catch(exception& e)
    {
        cout << e.what() << endl;
    }
    cout << "baris program terakir" << endl; //penanda 2
    return 0;
}