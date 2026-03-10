using System.Diagnostics;

class Spillfigur
{
    public string Navn;
    public int Liv;
    public int Niva;

    public Spillfigur(string name)
    {
        this.Navn = "Aria";
        Liv = 100;
        Niva = 1;
    }
}

class program
{
   static void Main(string[] args)
    {
        Spillfigur Spiller = new Spillfigur("Aria");
        Console.WriteLine($"Navn: {Spiller.Navn}");
        Console.WriteLine($"Liv: {Spiller.Liv}");
        Console.WriteLine($"Nivå: {Spiller.Niva}");
    }
}
   
