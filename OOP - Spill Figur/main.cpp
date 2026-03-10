#include <iostream>
#include <string>

using namespace std;

class Fiende; // forward declaration

class Spiller {
private:
    string navn;
    int helse;
    int skade;

public:
    Spiller(string n, int h, int s) {
        navn = n;
        helse = h;
        skade = s;
    }

    void angripe(Fiende &fiende);

    void taSkade(int s) {
        helse -= s;
        cout << navn << " fikk " << s << " skade. Helse igjen: " << helse << endl;
    }

    int getSkade() {
        return skade;
    }

    string getNavn() {
        return navn;
    }
};

class Fiende {
private:
    string navn;
    int helse;
    int skade;

public:
    Fiende(string n, int h, int s) {
        navn = n;
        helse = h;
        skade = s;
    }

    void angripe(Spiller &spiller) {
        cout << navn << " angriper spilleren!" << endl;
        spiller.taSkade(skade);
    }

    void taSkade(int s) {
        helse -= s;
        cout << navn << " fikk " << s << " skade. Helse igjen: " << helse << endl;
    }
};

void Spiller::angripe(Fiende &fiende) {
    cout << navn << " angriper fienden!" << endl;
    fiende.taSkade(skade);
}

int main() {

    Spiller spiller("Hero", 100, 20);
    Fiende fiende("Goblin", 50, 10);

    spiller.angripe(fiende);
    fiende.angripe(spiller);

    return 0;
}