#include <iostream>
#include <cctype>
using namespace std;

struct rycerz {
    int hitpoints;
    int damage;
    int gold;
};

struct smok {
    int hitpoints;
    int damage;
};

struct stanGry {
    rycerz Knight1{};
    smok Witek{};
    smok Jerzyk{};
    smok Adam{};
    smok Olek{};
    stanGry() {
        Knight1.gold = 100;
        Knight1.hitpoints = 100;
        Knight1.damage = 10;
        Witek.hitpoints = 50;
        Witek.damage = 10;
        Jerzyk.hitpoints = 200;
        Jerzyk.damage = 25;
        Adam.damage = 50;
        Adam.hitpoints = 490;
        Olek.hitpoints = 900;
        Olek.damage = 75;
    }
};
bool czyLiczba(char znak) {
    return isdigit(znak) != 0; // isdigit zwraca wartość różną od zera, jeśli znak jest cyfrą
}
int wczytajWybor() {
    char x;
    cout << "Wybierz opcje: ";
    cin >> x;
    while (!czyLiczba(x)) { // Dopóki wprowadzony znak nie jest liczbą
        cout << "Niepoprawny wybor. Wprowadz liczbe: ";
        cin >> x;
    }
    return x - '0'; // Konwersja znaku na cyfrę (char na int)
}

void sklep(stanGry& stan) {
    rycerz& Knight1 = stan.Knight1;

    int y;
    do {
        cout << "Witaj w sklepie, wpisz odpowiedni numer by kupic dany przedmiot" << endl;
        cout << "Liczba dostepnego zlota: " << Knight1.gold << endl;
        cout << "Liczba punktow hp: " << Knight1.hitpoints << endl;
        cout << "[1] aby kupic 10hp (-10g)" << endl;
        cout << "[2] aby kupic +5dmg (-10g)" << endl;
        cout << "[3] aby kupic 50hp (-50g)" << endl;
        cout << "[4] aby kupic +25dmg (-50g)" << endl;
        cout << "[9] Dev mode " << endl;
        cout << "[0] aby opuscic sklep" << endl;
        y = wczytajWybor();
        switch (y) {
            case 1: {
                if (Knight1.gold >= 10) {
                    cout << "Kupiles 10hp" << endl;
                    Knight1.gold -= 10;
                    Knight1.hitpoints += 10;
                    cout << "Stan zlota: " << Knight1.gold << endl;
                    cout << "Stan obrazen: " << Knight1.damage << endl;
                    cout << "Stan zdrowia: " << Knight1.hitpoints << endl;
                } else {
                    cout << "Nie masz wystarczającej ilości zlota!" << endl;
                }
                break;
            }
            case 2: {
                if (Knight1.gold >= 10) {
                    cout << "Kupiles +5 dmg" << endl;
                    Knight1.gold -= 10;
                    Knight1.damage += 5;
                    cout << "Stan zlota: " << Knight1.gold << endl;
                    cout << "Stan obrazen: " << Knight1.damage << endl;
                    cout << "Stan zdrowia: " << Knight1.hitpoints << endl;
                } else {
                    cout << "Nie masz wystarczajacej ilosci zlota!" << endl;
                }
                break;
            }
            case 3: {
                if (Knight1.gold >= 50) {
                    cout << "Kupiles 50hp" << endl;
                    Knight1.gold -= 50;
                    Knight1.hitpoints += 50;
                    cout << "Stan zlota: " << Knight1.gold << endl;
                    cout << "Stan obrazen: " << Knight1.damage << endl;
                    cout << "Stan zdrowia: " << Knight1.hitpoints << endl;
                } else {
                    cout << "Nie masz wystarczającej ilości zlota!" << endl;
                }
                break;
            }
            case 4: {
                if (Knight1.gold >= 50) {
                    cout << "Kupiles +25 dmg" << endl;
                    Knight1.gold -= 50;
                    Knight1.damage += 25;
                    cout << "Stan zlota: " << Knight1.gold << endl;
                    cout << "Stan obrazen: " << Knight1.damage << endl;
                    cout << "Stan zdrowia: " << Knight1.hitpoints << endl;
                } else {
                    cout << "Nie masz wystarczajacej ilosci zlota!" << endl;
                }
                break;
            }
            case 9: {
                    cout << "Obdarowano cie kox statami" << endl;
                    Knight1.gold = 2147483;
                    Knight1.damage = 2147483;
                    Knight1.hitpoints = 2147483;
                    cout << "Stan zlota: " << Knight1.gold << endl;
                    cout << "Stan obrazen: " << Knight1.damage << endl;
                    cout << "Stan zdrowia: " << Knight1.hitpoints << endl;
                    break;
            }
            case 0: {
                    cout << "Opuszczasz sklep" << endl;
                    break;
            }
            default:
                    cout << "Wybierz poprawna opcje!" << endl;
                    break;
        }
    } while (y != 0);
}

void walka(stanGry& stan) {
    rycerz& Knight1 = stan.Knight1;
    smok& Witek = stan.Witek;

    cout << "witaj w walce z Witkiem\n";
    int Hp_przed_walka = Knight1.hitpoints;
    do {
        int x;
        cout << "twoje hp = " << Knight1.hitpoints << endl;
        cout << "twoje obrazenia " << Knight1.damage << endl;
        cout << "hp smoka " << Witek.hitpoints << endl;
        cout << "aby zadac obrazenia wpisz 1\n";
        cout << "aby sie poddac wpisz 2\n";
        x = wczytajWybor();
        switch (x) {
            case 1: {
                cout << "zabrales Witkowi "<< Knight1.damage << " ale sam straciles "<< Witek.damage << " hp" << endl;
                Witek.hitpoints -= Knight1.damage;
                Knight1.hitpoints -= Witek.damage;
                break;
            }
            case 2:
                cout << "poddales sie\n";
                break;
            default:
                break;
        }
    } while (Knight1.hitpoints > 0 && Witek.hitpoints > 0);

    if (Witek.hitpoints <= 0) {
        cout << "wygrales z smokiem witkiem\n pora na kogos mocniejszego\n";
        cout << "w nagrode otrzymujesz 50 zlota\n";
        Knight1.gold += 50;
        cout << "masz teraz " << Knight1.gold << " zlota\n";
        Knight1.hitpoints = Hp_przed_walka;
        cout<< "odzyskales swoje hp"<<endl;
        sklep(stan);
    } else
        cout << "niestety musisz podejsc do gry jeszcze raz\n";
}

void walka2(stanGry& stan) {
    rycerz& Knight1 = stan.Knight1;
    smok& Jerzyk = stan.Jerzyk;

    cout << "witaj w walce 2 z Jerzykiem\n";
    int Hp_przed_walka = Knight1.hitpoints;
    do {
        int x;
        cout << "twoje hp = " << Knight1.hitpoints << endl;
        cout << "twoje obrazenia " << Knight1.damage << endl;
        cout << "hp smoka " << Jerzyk.hitpoints << endl;
        cout << "aby zadac obrazenia wpisz 1\n";
        cout << "aby sie poddac wpisz 2\n";
        x = wczytajWybor();
        switch (x) {
            case 1: {
                cout << "zabrales Jerzykowi " << Knight1.damage << " hp ale sam straciles " << Jerzyk.damage << " hp" << endl;
                Jerzyk.hitpoints -= Knight1.damage;
                Knight1.hitpoints -= Jerzyk.damage;
                break;
            }
            case 2:
                cout << "poddales sie\n";
                break;
            default:
                break;
        }
    } while (Knight1.hitpoints > 0 && Jerzyk.hitpoints > 0);

    if (Jerzyk.hitpoints <= 0) {
        cout << "wygrales z smokiem Jerzykiem\n pora na kogos mocniejszego\n";
        cout << "w nagrode otrzymujesz ";
        Knight1.gold += 200;
        cout << Knight1.gold << " zlota\n";
        Knight1.hitpoints = Hp_przed_walka;
        cout<<"odzyskales swoje hp"<<endl;
        sklep(stan);
    } else
        cout << "niestety musisz podejsc do gry jeszcze raz\n";

}
void walka3(stanGry& stan) {
    rycerz &Knight1 = stan.Knight1;
    smok &Adam = stan.Adam;
    cout << "witaj w walce 3 z Adamem\n";
    int Hp_przed_walka = Knight1.hitpoints;
    do {
        int x;
        cout << "twoje hp = " << Knight1.hitpoints << endl;
        cout << "twoje obrazenia " << Knight1.damage << endl;
        cout << "hp smoka " << Adam.hitpoints << endl;
        cout << "aby zadac obrazenia wpisz 1\n";
        cout << "aby sie poddac wpisz 2\n";
        x = wczytajWybor();
        switch (x) {
            case 1: {
                cout << "zabrales Adamowi " << Knight1.damage << " hp ale sam straciles " << Adam.damage << " hp"
                     << endl;
                Adam.hitpoints -= Knight1.damage;
                Knight1.hitpoints -= Adam.damage;
                break;
            }
            case 2:
                cout << "poddales sie\n";
                break;
            default:
                break;
        }
    } while (Knight1.hitpoints > 0 && Adam.hitpoints > 0);

    if (Adam.hitpoints <= 0) {
        cout << "wygrales z smokiem Adamem\n pora na kogos mocniejszego\n";
        cout << "w nagrode otrzymujesz ";
        Knight1.gold += 250;
        cout << Knight1.gold << " zlota\n";
        Knight1.hitpoints = Hp_przed_walka;
        cout << "odzyskales swoje hp" << endl;
        sklep(stan);
    } else

        cout << "niestety smok Adam jest zbyt potezny\n";

}
void walka4(stanGry& stan) {
    rycerz &Knight1 = stan.Knight1;
    smok &Olek = stan.Olek;

    cout << "witaj w walce 4 walce z Olkiem\n";
    int Hp_przed_walka = Knight1.hitpoints;
    do {
        int x;
        cout << "twoje hp = " << Knight1.hitpoints << endl;
        cout << "twoje obrazenia " << Knight1.damage << endl;
        cout << "hp smoka " << Olek.hitpoints << endl;
        cout << "aby zadac obrazenia wpisz 1\n";
        cout << "aby sie poddac wpisz 2\n";
        x = wczytajWybor();
        switch (x) {
            case 1: {
                cout << "zabrales Olkowi " << Knight1.damage << " hp ale sam straciles " << Olek.damage << " hp"
                     << endl;
                Olek.hitpoints -= Knight1.damage;
                Knight1.hitpoints -= Olek.damage;
                break;
            }
            case 2:
                cout << "poddales sie\n";
                break;
            default:
                break;
        }
    } while (Knight1.hitpoints > 0 && Olek.hitpoints > 0);
    if (Olek.hitpoints <= 0) {
        cout << "wygrales z smokiem Olkiem\n jestes pro\n";
        cout << "w nagrode otrzymujesz ";
        Knight1.gold += 350;
        cout << Knight1.gold << " zlota\n";
        Knight1.hitpoints = Hp_przed_walka;
        cout << "odzyskales swoje hp" << endl;
        sklep(stan);
    } else

        cout << "niestety Olek jest zbyt potezny\n";

}
int main() {
    stanGry aktualnyStanGry;
    sklep(aktualnyStanGry);
    walka(aktualnyStanGry);
    walka2(aktualnyStanGry);
    walka3(aktualnyStanGry);
    walka4(aktualnyStanGry);
    return 0;
}