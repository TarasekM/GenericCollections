<h1> GenericCollections</h1>
Kolekcja struktur generycznych wzorowanych na strukturach udostępnionych w .NET 4.8 C#.

<h2>WAŻNE</h2>

Aby kolekcje działały poprawnie obiekt &#60;T&#62; musi implementować:
  
  -konstruktor bezparametrowy
  
  -metodę equals przyjmującą const T
  
  -metodę equals przyjmującą wskaźnik na obiekt T
  
  -metodę toString

<b>Implementacja klas i metod jest całkowcie napisana przeze mnie. Natomiast przy nazwach metod wzorowałem się na poniższych dokumentacjach:</b>

<h3>Iterator&#60;T&#62;:</h3>

https://docs.microsoft.com/pl-pl/dotnet/api/system.collections.generic.ienumerator-1?view=netframework-4.8

<h3>ICollection&#60;T&#62;:</h3>

https://docs.microsoft.com/pl-pl/dotnet/api/system.collections.generic.icollection-1?view=netframework-4.8

<h3>List&#60;T&#62;:</h3>

https://docs.microsoft.com/pl-pl/dotnet/api/system.collections.generic.list-1?view=netframework-4.8

<h3>Queue&#60;T&#62;:</h3>

https://docs.microsoft.com/pl-pl/dotnet/api/system.collections.generic.queue-1?view=netframework-4.8

<h3>Stack&#60;T&#62;:</h3>

https://docs.microsoft.com/pl-pl/dotnet/api/system.collections.generic.stack-1?view=netframework-4.8

<h3>LinkedList&#60;T&#62;:</h3>

https://docs.microsoft.com/pl-pl/dotnet/api/system.collections.generic.linkedlistnode-1?view=netframework-4.8

<h3>QueueNode&#60;T&#62;:</h3>

Na podstawie queue tylko, że przy użyciu węzłów (Nodes).
