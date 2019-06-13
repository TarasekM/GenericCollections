### GenericCollections
Kolekcja struktur generycznych wzorowanych na strukturach udostępnionych w .NET 4.8 C#.

#WAŻNE:

Aby kolekcje działały poprawnie obiekt <T> musi implementować:
  -konstruktor bezparametrowy
  -metodę equals przyjmującą const T
  -metodę equals przyjmującą wskaźnik na obiekt T
  -metodę toString

Implementacja klas i metod jest całkowcie napisana przeze mnie. Natomiast przy nazwach metod wzorowałem się na poniższych dokumentacjach:

#Iterator<T>:

https://docs.microsoft.com/pl-pl/dotnet/api/system.collections.generic.ienumerator-1?view=netframework-4.8

#ICollection<T>:

https://docs.microsoft.com/pl-pl/dotnet/api/system.collections.generic.icollection-1?view=netframework-4.8

#List<T>:

https://docs.microsoft.com/pl-pl/dotnet/api/system.collections.generic.list-1?view=netframework-4.8

#Queue<T>:

https://docs.microsoft.com/pl-pl/dotnet/api/system.collections.generic.queue-1?view=netframework-4.8

#Stack<T>:

https://docs.microsoft.com/pl-pl/dotnet/api/system.collections.generic.stack-1?view=netframework-4.8

#LinkedList<T>:

https://docs.microsoft.com/pl-pl/dotnet/api/system.collections.generic.linkedlistnode-1?view=netframework-4.8

#QueueNode<T>:

Na podstawie queue tylko, że przy użyciu Node.
