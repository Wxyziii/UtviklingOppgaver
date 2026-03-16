#include <iostream>

class Dyr {

    public: int AntallBen;

    public: Dyr(int ben) {
        AntallBen = ben;
    }

    public: virtual void LageLyd() {
        std::cout << "Dyret lager en lyd";
    }

};

class Katt : public Dyr {
public:
    std::string Navn;

    Katt(std::string navn, int ben) : Dyr(ben) {
        Navn = navn;
    }

    void Mjau() {
        std::cout << "Dyret lager lyd!\n";
    }

    public: void LageLyd() override {
        std::cout << "Mjau!\n\n";
    }
};

class Hund : public Dyr {
public:
    std::string Navn;

    Hund(std::string navn, int ben) : Dyr(ben) {
        Navn = navn;
    }

    public: void LageLyd() override {
        std::cout << "Voff!\n";
    }
};

int main() {
    
    Katt k("Luna", 4);
    Hund h("Alex", 5);

    std::cout << k.Navn << "\n";
    std::cout << k.AntallBen << "\n";
    k.Mjau();
    k.LageLyd();

    std::cout << h.Navn << "\n";
    std::cout << h.AntallBen << "\n";
    h.LageLyd();
    
    
    
    return 0;
}