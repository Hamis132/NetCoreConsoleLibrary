namespace webowkaWejscie.Interfaces
{
    using webowkaWejscie.Models;

    public interface ILibrary
    {
        void AddBook();
        void SortBooks();
        void FindBook();
        void showlistofbooks();
    }
}