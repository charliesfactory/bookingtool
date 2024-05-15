Beschreibung, Informationen und Zielsetzung

Dieses Tool dient der Buchung eines Raumes für die Mitarbeitenden einer Firma. 
Das Endziel des Programms soll sein, dass anhand seiner Anforderungen an den Arbeitsplatz ein Mitarbeiter einen freien Platz nach 
dessen Ausstattungs-, Zugangswünschen und Zeiten buchen kann.
Zum Schluss soll er eine Dokument ausgestellt bekommen, wo seine gebuchte Raumnummer draufsteht. Mit dieser erhält er an der Rezeption den Schlüssel zum Raum.
Weitere Todos und Ideen: Interaktion, alle Räume einpflegen,  Usermanagement anschließen, wobei verschiedene Rollen (zB. Hausmeister, Admin, Teamlead, Mitarbeiter, Werkstudent) Zugriffsoptionen auf Räume haben (zB. nur Teamlead kann
Koferenzraum buchen).

Zunächst wurden alle Räume, Zuordnungen und Ausstattungen festgehalten und ein UML-Diagram wurde erstellt.

Eine erste vereinfachte Version stellt "Plain" dar.

Es hat eine Klasse Raum.
Raum hat die Attribute Raumnummer, Typ (z.B. "Büroraum", "Konferenzraum"), Barrierefreiheit und eine Liste von Ausrüstungsgegenständen. Zusätzlich gibt es verfuegbarkeit, was das Datum mit einem Booleschen Wert verbindet, um die Verfügbarkeit des Raums an diesem Tag zu kennzeichnen.
Wir haben folgende drei Methoden:
Zunächst gibt zeigeDetails() Informationen über den Raum aus, einschließlich Raumnummer, Typ, Barrierefreiheit und Ausrüstung.
pruefeVerfuegbarkeit(std::string datum) überprüft, ob der Raum am gegebenen Datum verfügbar ist.
bucheRaum(std::string datum) setzt die Verfügbarkeit des Raums auf false für das angegebene Datum, um den Raum zu buchen.

Buchungssystem ist auch eine Klasse.
Es hat als Attribute eine Liste von Räumen.
Dessen Methoden sind hinzufuegenRaum(const Raum&). Es fügt einen Raum zur Liste hinzu.
Dann gibt es findeFreienRaum(std::string typ, bool barrierefrei, std::string datum). Diese Methode durchsucht die verfügbaren Räume und gibt den ersten Raum zurück, der den spezifizierten Kriterien entspricht (Raumtyp, Barrierefreiheit, Verfügbarkeit am angegebenen Datum).

Die main-Funktion erstellt für ein erstes Beispiel zwei Raumobjekte raum1 und raum2 mit spezifischen Eigenschaften.
Dann wird Buchungssystem und fügt die erstellten Räume hinzu.
Es versucht, einen Raum zu finden, der den gegebenen Kriterien entspricht, und bucht ihn, falls verfügbar. Zum Schluss wird eine Meldung ausgegeben, ob der Raum gebucht wurde oder nicht.


Draft von "alle Räume":

Gebäude A

im Erdgeschoss 

Raum 0000 - Büroraum - barrierefrei - 1 Sitzplatz, 1 Tisch, 2 Monitore, 1 Locker

Raum 0001 - Büroraum - barrierefrei - 2 Sitzplätze, 2 Tische, 4 Monitore, 2 Locker

Raum 0002 - Büroraum - barrierefrei - 3 Sitzplätze, 3 Tische, 6 Monitore, 3 Locker

Raum 0003 - Büroraum - barrierefei - 4 Sitzplätze, 4 Stühle, 8 Monitore, 4 Locker

Raum 0004 - Konferenzraum - barrierefei - 20 Sitzplätze, 20 Tische, 1 Beamer, 2 Lautsprecher

Raum 0005 - Küche - Kaffeemaschine, Wasserkocher, Waschbecken, Herd

Raum 0006 - Toilette mit Pissoir

Raum 0007 - Toilette ohne Pissoir und Wickeltisch

im ersten Obergeschoss mit Fahstuhl

Raum 1000 - Büroraum - barrierefrei - 1 Sitzplatz, 1 Tisch, 2 Monitore, 1 Locker

Raum 1001 - Büroraum - barrierefrei - 2 Sitzplätze, 2 Tische, 4 Monitore, 2 Locker

Raum 1002 - Büroraum - barrierefrei - 3 Sitzplätze, 3 Tische, 6 Monitore, 3 Locker

Raum 1003 - Büroraum - barrierefei - 4 Sitzplätze, 4 Stühle, 8 Monitore, 4 Locker

Raum 1004 - Konferenzraum - barrierefei - 20 Sitzplätze, 20 Tische, 1 Beamer, 2 Lautsprecher

Raum 1005 - Küche - Kaffeemaschine, Wasserkocher, Waschbecken, Herd

Raum 1006 - Toilette mit Pissoir

Raum 1007 - Toilette ohne Pissoir und Wickeltisch

im dritten Obergeschoss nur Treppe

Raum 3000 - Büroraum - nicht barrierefrei - 1 Sitzplatz, 1 Tisch, 2 Monitore, 1 Locker

Raum 3001 - Büroraum - nicht barrierefrei - 2 Sitzplätze, 2 Tische, 4 Monitore, 2 Locker

Raum 3002 - Büroraum - nicht barrierefrei - 3 Sitzplätze, 3 Tische, 6 Monitore, 3 Locker

Raum 3003 - Büroraum - nicht barrierefei - 4 Sitzplätze, 4 Stühle, 8 Monitore, 4 Locker

Raum 3004 - Konferenzraum - nicht barrierefei - 20 Sitzplätze, 20 Tische, 1 Beamer, 2 Lautsprecher

Raum 3005 - Küche - nicht barrierefrei - Kaffeemaschine, Wasserkocher, Waschbecken, Herd

Raum 3006 - Toilette nicht barrierefrei - mit Pissoir

