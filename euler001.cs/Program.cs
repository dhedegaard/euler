using System;
using System.Linq;

class Program
{
    static void Main(string[] args)
    {
        Console.WriteLine(Enumerable.Range(1, 999).Where(e => e % 3 == 0 || e % 5 == 0).Sum());
    }
}
