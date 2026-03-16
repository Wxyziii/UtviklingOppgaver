#include <iostream>

class Figur {
private:
    std::string Navn;
    int Liv;

public:
    Figur(std::string navn, int liv) {
        Navn = navn;
        Liv = liv;
    }

    void TaSkade(int skade) {
        Liv -= skade;
    }

    int HentLiv() {
        return Liv;
    }

    void VisInfo() {
        std::cout << "Navn " << Navn << ", Liv " << Liv << "\n"; 
    }
};

class Spiller : public Figur {
public:
    Spiller(std::string navn) : Figur(navn, 100) {}

    void Angrip() {
        std::cout << "Spiller angriper!\n";

    }
    
};

class Magiker : public Spiller {
public:
    Magiker(std::string navn) : Spiller(navn) {}

    void KastTrylleformel() {
        std::cout << "Magiker kaster Trylle formel!\n";
    }
};

class Fiende : public Figur {
public:
    Fiende(std::string navn, int liv = 50) : Figur(navn, liv) {}

    void Angrip() {
        std::cout << "Fiende angriper!\n";
    }
};

class Boss : public Fiende {
public:
    Boss(std::string navn) : Fiende(navn, 150) {}

    void SuperAngrip() {
        std::cout << "Bossen bruker et Super Angrep!\n";
    }

};



int main() {
    Spiller spiller("Hero");
    Magiker magiker("Gandalf");
    Fiende fiende("Zombie");
    Boss boss("Mega Zombie");

    spiller.Angrip();
    magiker.KastTrylleformel();
    fiende.Angrip();
    boss.SuperAngrip();

    fiende.TaSkade(20);
    boss.TaSkade(30);

    std::cout << "Fiende har " << fiende.HentLiv() << " liv igjen.\n";
    std::cout << "Boss har " << boss.HentLiv() << " liv igjen.\n";

    spiller.VisInfo();
    magiker.VisInfo();
    fiende.VisInfo();
    boss.VisInfo();

    return 0;
}
