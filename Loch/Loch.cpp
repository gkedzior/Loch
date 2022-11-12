#include <iostream>
#include <cstdlib>
#include <ctime>
#include <limits>
using namespace std;

int Komnata, Trodnosc, loch;
int Atak, Obrona, SC, Obrazenia, Szczescie, Zycie;
int ZycieWroga, AtakWroga, ObronaWroga, WrogaRasa, WrogaKlasa;
float ZycieMnoznik, AtakMnoznik, ObronaMnoznik;
int Rasa, Klasa, Rany, Mana;
int k, T;

bool CzyKoniecGry() {
    if (Zycie - Rany <= 0) {
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


void PoziomTrudnosci() {
    cout << "Wybierz poziom trudnosci(1, 2, 3, 4 lub 5): ";
    cin >> k;

    if (k < 6 && k>0)
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
        cout << "blond" << endl;
        PoziomTrudnosci();
    }

}
void WybieranieRasy() {
    cout << "Wybierz rasę! " << endl << endl;

    int k;
    cout << "1. Czlowiek:   Atak=4, Obrona=4, Obrażenia= 4, Siła czarow = 4, Szczęście=4, Życie = 20" << endl;
    cout << "2. Krasnolud:  Atak=5, Obrona=5, Obrażenia= 2, Siła czarow = 3, Szczęście=4, Życie = 25" << endl;
    cout << "3. Elf:        Atak=3, Obrona=2, Obrażenia= 4, Siła czarow = 5, Szczęście=6, Życie = 20" << endl;
    cout << "4. Ork:        Atak=6, Obrona=4, Obrażenia= 5, Siła czarow = 2, Szczęście=3, Życie = 20" << endl;
    cout << "Wybierz rasę! " << endl;
    cin >> k;
    if (k < 5 && k>0)
    {
        switch (k) {
        case 1: Atak = 4; Obrona = 4;  Obrazenia = 4; SC = 4; Szczescie = 4; Rasa = 1; Zycie = 20;  break;
        case 2: Atak = 5; Obrona = 5;  Obrazenia = 2; SC = 3; Szczescie = 4; Rasa = 2; Zycie = 25;  break;
        case 3: Atak = 3; Obrona = 2;  Obrazenia = 4; SC = 5; Szczescie = 6; Rasa = 3; Zycie = 20;   break;
        case 4: Atak = 6; Obrona = 4;  Obrazenia = 5; SC = 2; Szczescie = 3; Rasa = 4; Zycie = 30;  break;
        }
    }
    else
    {
        cout << "blond" << endl;
        WybieranieRasy();
    }
}
void WybieranieKlasy() {
    cout << "Wybierz Klase! " << endl << endl;


    cout << "1. Wojownik:   Atak +5, Obrona +3, Obrażenia +3, Siła czarow + 0, Szczęście +0, Życie  +10" << endl;
    cout << "2. Kaplan:     Atak +3, Obrona +3, Obrażenia +3, Siła czarow + 3, Szczęście +5, Życie  +0" << endl;
    cout << "3. Mag:        Atak +3, Obrona +0, Obrażenia +3, Siła czarow + 5, Szczęście +3, Życie  +5" << endl;
    cout << "Wybierz Klase! " << endl;
    cin >> k;
    if (k < 4 && k>0)
    {
        switch (k) {
        case 1: Atak += 5; Obrona += 5; Obrazenia += 3;  SC += 0; Szczescie += 0;  Zycie += 10;     Klasa = 1;  break;
        case 2: Atak += 3; Obrona += 3; Obrazenia += 3;  SC += 3; Szczescie += 5;  Zycie += 0;      Klasa = 2;  break;
        case 3: Atak += 3; Obrona += 0; Obrazenia += 3;  SC += 5; Szczescie += 3;  Zycie += 5;      Klasa = 3;  break;

        }
    }
    else
    {
        cout << "blond" << endl;
        WybieranieKlasy();
    }
}
void TworzeniePostaci() {
    PoziomTrudnosci();
    WybieranieRasy();
    WybieranieKlasy();
    Mana = 10 + 10 * SC;
}
void Statystyki() {
    cout << endl;
    cout << "Twoje statystyki to:" << endl << "Atak = " << Atak << endl << "Obrona = " << Obrona << endl;
    cout << "Sila czarow = " << SC << endl << "Obrazerzenia = " << Obrazenia << endl;
    cout << "Szczesczie = " << Szczescie << endl << "Zycie = " << Zycie << endl << "Rany = " << Rany << endl << endl;

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
    AtakWroga -= 1;
    ObronaWroga -= 2;

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


void Czar() {
    if (Mana >= 3 * SC) {
        cout << "Czy chcesz rzucic czar? Koszt: " << 3 * SC << " / " << Mana << " Many ." << endl << "0 NIE 1 TAK" << endl;
        cin >> k;
        if (k == 1) {
            int IloscObrazen = 1.5 * SC;
            cout << "Rzucies czar, zada on: " << IloscObrazen << "obrazen!!!" << endl;
            ZycieWroga -= IloscObrazen;
            Mana -= 3 * SC;
        }
        else if (k == 0) {
            cout << "Nie rzuciles czaru" << endl;
        }
        else {
            cout << "!!!bond!!! Nie mozesz rzucic czaru!!!!" << endl;
        }

    }
    else {
        cout << "Nie mozesz rzucic czaru." << endl;
    }
}

void PoziomTrudnosciRundy() {
    T = rand() % 50;
    T += Trodnosc + 49;
    T = T / 50;
}


int IloscObrarzen(int Atak2, int Obrona2) {
    int X = Atak2 - Obrona2 + 6;
    X = X / 2;
    if (X > 0) {
        return X;
    }
    return 1;
}
void WrogAtakuje() {
    cout << "Wrog atakuje cie. Otrzymujesz " << IloscObrarzen(AtakWroga, Obrona) << "ran" << endl;
    Rany += IloscObrarzen(AtakWroga, Obrona);

}
void GraczAtakuje() {
    cout << "Atakujesz wroga. Zadajesz " << IloscObrarzen(Atak, ObronaWroga) << "ran" << endl;
    ZycieWroga -= IloscObrarzen(Atak, ObronaWroga);



}
void AtakNaPoczatkuTury() {
    ZycieWroga -= Obrazenia;
    cout << "Atakujesz Wroga!!! Zadajesz " << Obrazenia << " obrazen" << endl;
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
    if (Rany < Szczescie / 2) {
        Rany = 0;
    }
    else {
        Rany -= Szczescie / 2;
    }
    if (
        Mana < 10 + 9 * SC - Szczescie) {
        Mana += SC + Szczescie;
    }
    else {
        Mana = 10 + 10 * SC;
    }
    for (int i = T; i > 0; i--) {
        int x = 1 + rand() % 6;
        switch (x) {
        case 1: Atak++; break;
        case 2: Obrona++; break;
        case 3: SC++; break;
        case 4: Obrazenia++; break;
        case 5: Szczescie += 2; break;
        case 6: Zycie += 3; break;
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

        Trodnosc += 25;
        cout << "Czy jesteś gotow na kolejna walke???" << endl << "0. Nie 1. Tak" << endl;
        cin >> k;
        if (k == 1) {
            cout << "to dobrze !!!" << endl;
        }
        else {
            cout << "Trodno." << endl;
        }
        cout << endl << endl << endl;
        Trodnosc += 10;
    }




}