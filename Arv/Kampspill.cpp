#include <algorithm>
#include <iostream>
#include <string>
#include <utility>

class Figur {
private:
    std::string Navn;
    int Liv;

public:
    Figur(std::string navn, int liv) : Navn(std::move(navn)), Liv(std::max(0, liv)) {}

    void TaSkade(int skade) {
        Liv = std::max(0, Liv - std::max(0, skade));
    }

    int HentLiv() const {
        return Liv;
    }

    void VisInfo() const {
        std::cout << "Navn " << Navn << ", Liv " << Liv << "\n";
    }
};

class Spiller : public Figur {
public:
    explicit Spiller(std::string navn) : Figur(std::move(navn), 100) {}

    void Angrip() {
        std::cout << "Spiller angriper!\n";

    }
    
};

class Magiker : public Spiller {
public:
    explicit Magiker(std::string navn) : Spiller(std::move(navn)) {}

    void KastTrylleformel() {
        std::cout << "Magiker kaster Trylle formel!\n";
    }
};

class Fiende : public Figur {
public:
    Fiende(std::string navn, int liv = 50) : Figur(std::move(navn), liv) {}

    void Angrip() {
        std::cout << "Fiende angriper!\n";
    }
};

class Boss : public Fiende {
public:
    explicit Boss(std::string navn) : Fiende(std::move(navn), 150) {}

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
