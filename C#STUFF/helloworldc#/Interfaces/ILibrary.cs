namespace webowkaWejscie.Interfaces
{
    using webowkaWejscie.Models;

    public interface ILibrary
    {
        Book AddBook(int a, Book previous);
        void FindBook(Book head);
        void showlistofbooks(Book head);
    }
}