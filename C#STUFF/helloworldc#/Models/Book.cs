
namespace webowkaWejscie.Models
{
    public class Book
    {
 
        public string Title;
        public string Author;
        public Book next;
        public Book(string author, string title)
        {
            Title = title;
            Author = author;
        }   
        public void setnext(Book tmp)
        {
            next = tmp;
        }
    }
}