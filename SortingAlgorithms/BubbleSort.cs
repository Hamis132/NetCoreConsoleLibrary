namespace webowkaWejscie.SortingAlgorithms
{
    using System;
    using System.Collections.Generic;
    using webowkaWejscie.Models;
    public static class BubbleSort
    {
        public static List<Book> Sort(List<Book> books)
        {
            for(int i=0; i < books.Count; i++)
            {
                for(int j = 0; j < books.Count - 1; j++)
                {
                    if(String.Compare(books[j].Author, books[j+1].Author) > 0)
                    {
                        var tmp = books[j];
                        books[j] = books[j+1];
                        books[j+1] = tmp;
                    }
                }
            }

            return books;
        }
        public static void Swap<T>(ref T lhs, ref T rhs)
        {
            T temp;
            temp = lhs;
            lhs = rhs;
            rhs = temp;
        }
    }
}