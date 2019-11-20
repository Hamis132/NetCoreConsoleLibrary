using System;
using webowkaWejscie.Interfaces;
using webowkaWejscie.Library;
using webowkaWejscie.Models;

namespace webowkaWejscie
{
    class Program
    {
        static void Main(string[] args)
        {
            int a;
            Book book = null;
            ILibrary biblioteka = new Library.Library();

            Console.WriteLine(args[0]);
        }
    }
}
