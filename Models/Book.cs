
namespace webowkaWejscie.Models
{
    public class Book
    {
        private int id;
        public int Id
        {
            get
            {
                if(id == 0)
                {
                    return int.MaxValue;
                }
                else
                {
                    return Id;
                }
            }
            set
            {
                id = value;
            }
        }
        public string Title { get; private set; }   

        public Book(int id, string title)
        {
            Id = id;
            title = Title;
        }   
    }
}