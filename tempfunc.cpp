#include "tempfunc.h"

string* splitString(string temp,int* len)
{
    string separator = " ";
    int start = 0;
    int end = temp.find(separator);
    int n = 0;
    string* arr = new string[MAX_STRING];
    while (end != -1) {
        arr[n] = temp.substr(start, end - start);
        start = end + separator.size();
        end = temp.find(separator, start);
        n++;
    }
    arr[n++] = temp.substr(start, end - start);
    string* tempStr = new string[n];
    for (int i = 0; i < n; i++) { tempStr[i] = arr[i]; }
    delete[] arr;
    arr = tempStr;
    *len = n;
    return arr;
}

void printMenu() {

    cout << "------------------\n";
    cout << "1. Dodaj studenta\n"
        "2. Obrisi studenta\n"
        "3. Ispis hash tabele\n"
        "4. Pronanji studenta\n"
        "5. Isprazni tabelu\n"
        "6. Broj kljuceva u tabeli\n"
        "7. Stepen popunjenosti\n"
        "8. Dodaj ispit studentu\n"
        "9. Obrisi ispit studentu\n"
        "10. Izlaz\n";

}

int* highBits(int num, int n, int limit) {
    int* bits = new int[n];
    int len = 0;
    int numsBits = sizeof(int)* 8;
    if (limit) numsBits = limit;
    int temp = pow(2, numsBits - 1);
    for (int i = 0; i < n; i++) {
        bits[i] = (num & temp) ? 1 : 0;
        temp >>= 1;
    }
    return bits;
}

bool compareBits(int* a, int* b, int len) {
    for (int i = 0; i < len; i++) {
        if (a[i] != b[i]) return false;
    }
    return true;
}