#include <iostream>
using namespace std;

int main()
{
    try
    {
        cout << "selamat belajar di prodi ti umy" << endl;
        //throw 0,5; //melemparkan sebuah int maka
        cout << "pernyataan tidak dapat di atampilkan " << endl;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    
}