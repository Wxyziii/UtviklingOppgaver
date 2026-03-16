#include <iostream>
#include <vector>

using namespace std;

// Valgt datastruktur: vector<Bil>
// Hvorfor: vector er enkel å bruke, lagrer elementer i rekkefolge,
// og passer godt nar vi vil vise, legge til, slette og skyte inn biler.

struct Bil {
    string modell;
    int aar;
};

void visBiler(const vector<Bil>& biler, const string& overskrift) {
    cout << "\n" << overskrift << "\n";
    if (biler.empty()) {
        cout << "Ingen biler registrert." << endl;
        return;
    }
    for (size_t i = 0; i < biler.size(); ++i) {
        cout << i << ": " << biler[i].modell << " (" << biler[i].aar << ")" << endl;
    }
}

Bil lesBilFraBruker() {
    Bil nyBil;
    cout << "Skriv inn bilmodell: ";
    getline(cin >> ws, nyBil.modell);
    cout << "Skriv inn arsmodell: ";
    cin >> nyBil.aar;
    return nyBil;
}

void leggTilBil(vector<Bil>& biler) {
    // Innsetting: push_back legger ny bil bakerst i vectoren.
    visBiler(biler, "For innsetting:");
    Bil nyBil = lesBilFraBruker();
    biler.push_back(nyBil);
    visBiler(biler, "Etter innsetting:");
}

void skytInnBil(vector<Bil>& biler) {
    // Innskyting: insert legger inn ny bil pa valgt indeks og flytter resten.
    visBiler(biler, "For innskyting:");

    size_t indeks;
    cout << "Velg posisjon for innskyting (0 til " << biler.size() << "): ";
    cin >> indeks;

    if (indeks > biler.size()) {
        cout << "Ugyldig posisjon." << endl;
        return;
    }

    Bil nyBil = lesBilFraBruker();
    biler.insert(biler.begin() + static_cast<long long>(indeks), nyBil);
    visBiler(biler, "Etter innskyting:");
}

void slettBil(vector<Bil>& biler) {
    // Sletting: erase fjerner elementet fra vectoren og flytter resten mot venstre.
    visBiler(biler, "For sletting:");

    string modellTilSletting;
    cout << "Skriv inn bilmodell som skal slettes: ";
    getline(cin >> ws, modellTilSletting);

    for (auto it = biler.begin(); it != biler.end(); ++it) {
        if (it->modell == modellTilSletting) {
            biler.erase(it);
            cout << "Bil slettet!" << endl;
            visBiler(biler, "Etter sletting:");
            return;
        }
    }

    cout << "Fant ikke bil med den modellen." << endl;
    visBiler(biler, "Etter sletting (ingen endring):");
}

int main() {
    vector<Bil> biler {
        {"Audi", 2025},
        {"BMW", 2026},
        {"Mercedes", 2024},
        {"Mazda", 2023}
    };
    
    char menyValg;
    do {
        cout << "\nMeny:\n";
        cout << "1. Legg til bil\n";
        cout << "2. Skyt inn bil pa posisjon\n";
        cout << "3. Slett bil\n";
        cout << "4. Vis biler\n";
        cout << "5. Avslutt\n";
        cout << "Velg et alternativ (1-5): ";
        cin >> menyValg;

        switch (menyValg) {
            case '1':
                leggTilBil(biler);
                break;
            case '2':
                skytInnBil(biler);
                break;
            case '3':
                slettBil(biler);
                break;
            case '4':
                visBiler(biler, "Innhold i datastrukturen:");
                break;
            case '5':
                cout << "Avslutter programmet..." << endl;
                break;
            default:
                cout << "Ugyldig valg, prøv igjen." << endl;
        }
    } while (menyValg != '5');
    return 0;
}