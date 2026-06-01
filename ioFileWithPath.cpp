#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main()
{
    string baris, Namafile;
    cout << "Masukan nama file : ";
    cin >> Namafile;

    ofstream outfile;
    outfile.open(Namafile + ".txt", ios::out);
    cout << ">= Menulis file, \'q\' Untuk kluar" << endl;

    while(true)
    {
        cout << "- ";//mendpdt setiap karakter dlm 1 baris
        getline(cin, baris);//kondisi false jika baris hanya berisi karakter q
        if (baris == "q") break;//menulis and memasukkan nilai varialbel baris kedlm file
        outfile << baris << endl;
    }
    outfile.close();

    ifstream infile;//buka dlm mode baca
    infile.open(Namafile + ".txt", ios::in);
    cout << endl << ">= Membuka dan membaca file" << endl;

    if (infile.is_open())
    {
        while (getline(infile, baris)) {
            cout << baris << endl;
        }//perulangan untuk munculin setiap baris
        infile.close();//menutup jika selesai
    }
    else cout << "unable to open file";
    return 0;

}