
namespace webowkaWejscie.Models
{
    public class Book
    {
 
        public string Title {get;set;}
        public string Author { get;set;}
        public Book next {get;set;}
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