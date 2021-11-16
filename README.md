# String Bibliothek

Implementierung einer universell verwendbare String Bibliothek. Universell bedeutet in diesem Zusammenhang, dass die
Bibliothek mit unterschiedlichen Compilern und Plattformen funktionieren muss und sich auf jeder Plattform gleich
verhält.

Erstellen Sie zum Testen Ihrer String Klasse geeignete Testfälle. Die vorgegebenen Testfälle bilden nicht alle
Möglichkeiten ab.

Achten Sie beim Implementieren auf Performance und Speichermanagement. Dies bedeutet nicht, dass Sie Ihre Klasse auf die
letzte Millisekunde optimieren müssen, sondern dass unnötige Allokationen/Kopien oder Berechnungen mit Punkteabzug
gewertet werden können.

Achten Sie auf __Const Correctness__ und schreiben Sie an geeigneten Stellen __sinnvolle Kommentare.__

## Aufgabenstellung Teil 1:

- Erstellung eines Strings mit __const char*__
- Zusammenfügen von Strings über eine __Concatenate()__ member Funktion
- Erlauben Sie den Zugriff auf die intern verwaltete Zeichenkette über die __c_str()__ member Funktion (c string
  equivalent)
- Implementieren Sie einen getter, welcher die Länge der Zeichenkette zurück liefert – __getLength()__

## Aufgabenstellung Teil 2:

- Implementieren Sie einen __copy constructor__
- Implementieren Sie einen __copy assignment operator__
- Implementieren Sie einen __move constructor__
- Implementieren Sie einen __move assignment operator__
- Implementieren Sie den __+= operator__ und den __+ operator (two overloads each)__
- Implementieren Sie eine __conversion function__ für const char*

## Aufgabenstellung Teil 3:

- Implementieren Sie einen bidirektionalen __Iterator__ zur String Klasse
    - Der FwdIterator soll mit einer __nested class__ implementiert werden
    - Stellen Sie eine __begin()__ und eine __end()__ Methode bereit
    - Überladen Sie sinnvolle Operatoren