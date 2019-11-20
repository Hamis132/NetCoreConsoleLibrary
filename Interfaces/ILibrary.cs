namespace webowkaWejscie.Interfaces
{
    using webowkaWejscie.Models;

    public interface ILibrary
    {
        Book FindBook(int id);
        Book FindBook(string title);
        Book FindBook(string title, string author);
        void AddBook(Book book);
        void AddBook(string author);
    }
}