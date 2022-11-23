#include <iostream>
#include <cstdlib>
#include <ctime>
#include <limits>
using namespace std;

int Komnata, Trodnosc, loch;
int ZycieWroga, AtakWroga, ObronaWroga, WrogaRasa, WrogaKlasa;
float ZycieMnoznik, AtakMnoznik, ObronaMnoznik;
int k, T;
void WybieranieRasy();
void WybieranieKlasy();
void PoziomTrudnosci();
struct Gracz
{
    int atak;
    int obrona;
    int obrazenia;
    int moc;
    int szczescie;
    int zycie;
    int rany;
    int mana;
    int rasa;
    int klasa;
};
Gracz gracz;

bool CzyKoniecGry() {
    if (gracz.zycie - gracz.rany <= 0) {
        cout << "Przegrales :(";
        return true;
    }
    return false;
}
bool CzyPokonalesWroga() {
    if (ZycieWroga <= 0) {
        return true;
    }
    return false;
}

int JakiCzarRzucasz() {
    cout << "Jaki czar rzucasz (masz "<<gracz.mana <<" many) " << endl << "0. Nic" << endl << "1. Magiczny Pocisk (30 many)";
    cin >>k;
    return k;
}



void PoziomTrudnosciMech() {
    if (k >= 1 && k <= 5)
    {
        switch (k) {
        case 1: Trodnosc = 0; break;
        case 2: Trodnosc = 25; break;
        case 3: Trodnosc = 50; break;
        case 4: Trodnosc = 75; break;
        case 5: Trodnosc = 100; break;
        }
    }
    else
    {
        PoziomTrudnosci();
    }

}
void PoziomTrudnosciCom() {
    cout << "Wybierz poziom trudnosci(1, 2, 3, 4 lub 5): ";
    cin >> k;
}
void PoziomTrudnosci() {

    PoziomTrudnosciCom();
    PoziomTrudnosciMech();
}

void WybieranieRasyCom() {
    cout << "Wybierz rasę! " << endl << endl;

    cout << "1. Czlowiek:   Atak=4, Obrona=4, Obrażenia= 4, Moc = 4, Szczęście=4, Zycie = 25" << endl;
    cout << "2. Krasnolud:  Atak=5, Obrona=5, Obrażenia= 2, Moc = 3, Szczęście=4, Zycie = 30" << endl;
    cout << "3. Elf:        Atak=3, Obrona=2, Obrażenia= 4, Moc = 5, Szczęście=6, Zycie = 25" << endl;
    cout << "4. Ork:        Atak=6, Obrona=4, Obrażenia= 5, Moc = 2, Szczęście=3, Zycie = 25" << endl;
    cout << "Wybierz rasę! " << endl;
    cin >> k;
}
void WybieranieRasyMech(){
    if (k <= 4 && k>=1)
    {
        switch (k) {
        case 1: gracz.atak = 4; gracz.obrona = 4;  gracz.obrazenia = 4; gracz.moc = 4; gracz.szczescie = 4; gracz.klasa = 1; gracz.zycie = 25;  break;
        case 2: gracz.atak = 5; gracz.obrona = 5;  gracz.obrazenia = 2; gracz.moc = 3; gracz.szczescie = 4; gracz.klasa = 2; gracz.zycie = 30;  break;
        case 3: gracz.atak = 3; gracz.obrona = 2;  gracz.obrazenia = 4; gracz.moc = 5; gracz.szczescie = 6; gracz.klasa = 3; gracz.zycie = 25;  break;
        case 4: gracz.atak = 6; gracz.obrona = 4;  gracz.obrazenia = 5; gracz.moc = 2; gracz.szczescie = 3; gracz.klasa = 4; gracz.zycie = 25;  break;
        }
    }
    else
    {
        WybieranieRasy();
    }
}
void WybieranieRasy() {
    WybieranieRasyCom();
    WybieranieRasyMech();
}

void WybieranieKlasyCom() {
    cout << "Wybierz Klase! " << endl << endl;


    cout << "1. Wojownik:   Atak +5, Obrona +3, Obrażenia +3, Moc + 0, Szczęście +0, Życie  +15" << endl;
    cout << "2. Kaplan:     Atak +0, Obrona +3, Obrażenia +0, Moc + 3, Szczęście +5, Życie  +10" << endl;
    cout << "3. Mag:        Atak +3, Obrona +0, Obrażenia +3, Moc + 5, Szczęście +3, Życie  +0" << endl;//+20 do many
    cout << "Wybierz Klase! " << endl;
    cin >> k;
}
void WybieranieKlasyMech() {
    if (k < 4 && k>0)
    {
        switch (k) {
        case 1: gracz.atak += 5; gracz.obrona += 3; gracz.obrazenia += 3;  gracz.moc += 0; gracz.szczescie += 0;  gracz.zycie += 15;     gracz.klasa = 1;  break;
        case 2: gracz.atak += 0; gracz.obrona += 3; gracz.obrazenia += 0;  gracz.moc += 3; gracz.szczescie += 5;  gracz.zycie += 10;     gracz.klasa = 2;  break;
        case 3: gracz.atak += 3; gracz.obrona += 0; gracz.obrazenia += 3;  gracz.moc += 5; gracz.szczescie += 3;  gracz.zycie += 0;      gracz.klasa = 3;  break;

        }
    }
    else
    {
        WybieranieKlasy();
    }
}
void WybieranieKlasy() {
    WybieranieKlasyCom();
    WybieranieKlasyMech();
}

void Mana() {
    gracz.mana = 100;
    if (gracz.klasa == 3) {
        gracz.mana += 20;
    }
}
void TworzeniePostaci() {
    PoziomTrudnosci();
    WybieranieRasy();
    WybieranieKlasy();
    Mana();
}
void Statystyki() {
    cout << endl;
    cout << "Twoje statystyki to:" << endl << "Atak = " << gracz.atak << endl << "Obrona = " << gracz.obrona << endl;
    cout << "Sila czarow = " << gracz.moc << endl << "Obrazerzenia = " << gracz.obrazenia << endl;
    cout << "Szczesczie = " << gracz.szczescie << endl << "Zycie = " << gracz.zycie << endl << "Rany = " << gracz.rany << endl << endl;

}

void RasaWroga() {
    WrogaRasa = rand() % 3 + 1;
    switch (WrogaRasa) {
    case 1: AtakMnoznik = 1 + T;            ObronaMnoznik = T + 2;              ZycieMnoznik = T * 2 + 4;  break;
    case 2: AtakMnoznik = T;               ObronaMnoznik = T + 2;              ZycieMnoznik = T * 2 + 4;  break;
    case 3: AtakMnoznik = T + 2;             ObronaMnoznik = T;                  ZycieMnoznik = T * 2 + 5; break;
    }

}
void KlasaWroga() {
    WrogaKlasa = rand() % 3 + 1;

    switch (WrogaKlasa) {
    case 1: AtakWroga = 2 * AtakMnoznik;            ObronaWroga = 2 * ObronaMnoznik;              ZycieWroga = ZycieMnoznik * 2;    break;
    case 2: AtakWroga = 1.5 * AtakMnoznik;          ObronaWroga = 2.5 * ObronaMnoznik;              ZycieWroga = ZycieMnoznik * 2;    break;
    case 3: AtakWroga = 3 * AtakMnoznik;            ObronaWroga = 1.5 * ObronaMnoznik;              ZycieWroga = ZycieMnoznik * 2;    break;
    }

}
void Wrog() {
    RasaWroga();
    KlasaWroga();

}
void WrogNazwa() {
    switch (WrogaKlasa) {
    case 1: cout << "Przecietny "; break;
    case 2: cout << "Opancerzony "; break;
    case 3: cout << "Waleczny "; break;
    }
    switch (WrogaRasa) {
    case 1: cout << "goblin"; break;
    case 2: cout << "nocny goblin"; break;
    case 3: cout << "snotling"; break;
    }

}

void Czar1() {

}

int Czar() {
    JakiCzarRzucasz();
    switch (k) {
    case 1: if (gracz.mana >= 30) { Czar1(); } return 1; break;
    }
    return 0;
}

void PoziomTrudnosciRundy() {
    T = rand() % 50;
    T += Trodnosc + 49;
    T = T / 50;
}

int IloscObrarzen(int Atak2, int Obrona2) {
    int X = 1.5 * Atak2 - Obrona2 + 5;
    if (X <= 0) {
        return 2;//zmienić na skalowalne
    }
    else if (X < 6) {
        return 3;//zmienić na skalowalne
    }
    return 1 + X / 2;
}

void WrogAtakuje() {
    cout << "Wrog atakuje cie. Otrzymujesz " << IloscObrarzen(AtakWroga, gracz.obrona) << "ran" << endl;
    gracz.rany += IloscObrarzen(AtakWroga, gracz.obrona);
}
void GraczAtakuje() {
    cout << "Atakujesz wroga. Zadajesz " << IloscObrarzen(gracz.atak, ObronaWroga) << "ran" << endl;
    ZycieWroga -= IloscObrarzen(gracz.atak, ObronaWroga);
}
void AtakNaPoczatkuTury() {
    ZycieWroga -= gracz.obrazenia;
    cout << "Atakujesz Wroga!!! Zadajesz " << gracz.obrazenia << " obrazen" << endl;
}

int Walka() {
    AtakNaPoczatkuTury();
    if (CzyPokonalesWroga()) {
        cout << "Pokonales wroga!" << endl;
        return 1;
    }

    while (ZycieWroga > 0) {
        Czar();
        if (CzyPokonalesWroga()) {
            cout << "pokonales wroga!" << endl;
            return 1;
        }
        WrogAtakuje();
        if (CzyKoniecGry()) {
            return 0;
        }
        GraczAtakuje();
        if (CzyPokonalesWroga()) {
            cout << "pokonales wroga!" << endl;
            return 1;
        }
    }
    return 1;

}



void Nagroda() {
    if (gracz.rany < gracz.szczescie / 2) {
        gracz.rany = 0;
    }
    else {
        gracz.rany -= gracz.szczescie / 2;
    }
    if (
        gracz.mana < 10 + 9 * gracz.moc - gracz.szczescie) {
        gracz.mana += gracz.moc + gracz.szczescie;
    }
    else {
        gracz.mana = 10 + 10 * gracz.moc;
    }
    for (int i = T; i > 0; i--) {
        int x = 1 + rand() % 6;
        switch (x) {
        case 1: gracz.atak++; break;
        case 2: gracz.obrona++; break;
        case 3: gracz.moc++; break;
        case 4: gracz.obrazenia++; break;
        case 5: gracz.szczescie++; break;
        case 6: gracz.zycie += 3; break;
        }
    }
}



int main() {
    srand(time(NULL));
    
    TworzeniePostaci();
    for (int runda = 1; runda < 30; runda++) {
        cout << "Runda " << runda << endl;
        PoziomTrudnosciRundy();
        Statystyki();
        Wrog();
        WrogNazwa();
        cout << " ma Atak: " << AtakWroga << ". Obrone: " << ObronaWroga << ". Zycie: " << ZycieWroga << endl;

        cout << "Walcz z nim!!!" << endl;
        if (Walka() == 0) {
            exit(0);
        }

        Nagroda();

        cout << endl << endl;

        cout << "Czy jesteś gotow na kolejna walke???" << endl << "0. Nie 1. Tak" << endl;
        cin >> k;
        if (k == 1) {
            cout << "to dobrze !!!" << endl;
        }
        else {
            cout << "Trodno." << endl;
        }
        cout << endl << endl << endl;
        Trodnosc += 20;
    }




}