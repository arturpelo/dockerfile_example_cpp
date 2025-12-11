#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Przedmiot {
    int waga;
    int wartosc;
    double ratio;
};

int main() {
    string name = "Plecakowy_zachlanny";
    cout << "Napisz program \"" << name 
         << "\", który realizuje problem plecakowy metoda zachlanna!" << endl;
    cout << "----------------------------------------------------------" << endl;

    int n, capacity;
    cout << "Podaj liczbe przedmiotow: ";
    cin >> n;

    cout << "Podaj pojemnosc plecaka: ";
    cin >> capacity;

    vector<Przedmiot> items(n);

    cout << "Podaj wagi przedmiotow:" << endl;
    for(int i = 0; i < n; i++) cin >> items[i].waga;

    cout << "Podaj wartosci przedmiotow:" << endl;
    for(int i = 0; i < n; i++) cin >> items[i].wartosc;

    // wyliczamy stosunek wartosc/waga
    for(int i = 0; i < n; i++)
        items[i].ratio = (double)items[i].wartosc / items[i].waga;

    // sortowanie malejąco po ratio
    sort(items.begin(), items.end(), [](const Przedmiot &a, const Przedmiot &b){
        return a.ratio > b.ratio;
    });

    int currentWeight = 0;
    int totalValue = 0;

    cout << "----------------------------------------------------------" << endl;
    cout << "Wybrane przedmioty:" << endl;

    for(int i = 0; i < n; i++) {
        if(currentWeight + items[i].waga <= capacity) {
            currentWeight += items[i].waga;
            totalValue += items[i].wartosc;

            cout << " - Waga: " << items[i].waga 
                 << ", Wartosc: " << items[i].wartosc 
                 << ", Stosunek: " << items[i].ratio << endl;
        }
    }

    cout << "----------------------------------------------------------" << endl;
    cout << "Calkowita wartosc: " << totalValue << endl;
    cout << "Calkowita waga: " << currentWeight << endl;
    cout << "Pojemnosc plecaka: " << capacity << endl;

    return 0;
}
