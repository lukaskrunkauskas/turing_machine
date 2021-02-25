#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <stdlib.h>
#include "windows.h"
#include <thread>
#include <mutex>

using namespace std;

struct programa {
    string a;
    string b, c, d;
    string e;
};

//a-dabar busena
//b-dabartinis simbolis
//c-naujas simbolis
//d- kryptis
//e- nauja busena
//-prog-tiuringo kodas
void logika();

int main() {
    cout << "iveskite kuriu failu norite: " << endl;
    thread t1(&logika);
    thread t2(&logika);
    thread t3(&logika);
    thread t4(&logika);
    t1.join();
    t2.join();
    t3.join();
    t4.join();
}

void logika() {
    int eil = 0;
    int test = 0;
    int tikr = 0;
    string juosta;
    string dabartine_busena = "0";
    int pozicija;
    string failai;
    cin >> failai;
    //nuskaitymas
    vector <programa> duom;
    ifstream fd(failai + ".txt");
    fd >> juosta;
    fd >> pozicija;
    while (!fd.eof()) {
        duom.push_back(programa());
        fd >> duom[eil].a >> duom[eil].b >> duom[eil].c >> duom[eil].d >> duom[eil].e;
        eil++;
    }
    fd.close();
    bool programarunning = true;
    int i = 0;
    while (programarunning == true) {
        if (duom[i].a == dabartine_busena) {
            if (duom[i].b == std::to_string(juosta[pozicija])) {
                std::to_string(juosta[pozicija]) = duom[i].c;
                if (duom[i].d == "R")
                    pozicija++;
                if (duom[i].d == "L")
                    pozicija--;
                dabartine_busena = duom[i].e;
                if (pozicija < 0)
                    programarunning = false;
                if (pozicija > juosta.length())
                    programarunning = false;
                if (duom[i].e == "H")
                    programarunning = false;
            }
        }
        i++;
        if (i == eil) i = 0;
        if (GetAsyncKeyState(VK_ESCAPE)) {
            programarunning = false;
        }
        mutex mtx;
        mtx.lock();
        cout << juosta << endl;
        mtx.unlock();
    }
}





