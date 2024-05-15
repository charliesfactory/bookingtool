#include <iostream>
#include <vector>
#include <string>
#include <map>

class Raum {
public:
    std::string raumnummer;
    std::string typ;
    bool barrierefrei;
    std::vector<std::string> ausruestung;
    std::map<std::string, bool> verfuegbarkeit;  // Datum als Schlüssel, Verfügbarkeit als Wert

    Raum(std::string nummer, std::string t, bool barrierefrei, std::vector<std::string> ausr) 
        : raumnummer(nummer), typ(t), barrierefrei(barrierefrei), ausruestung(ausr) {}

    void zeigeDetails() {
        std::cout << "Raumnummer: " << raumnummer << ", Typ: " << typ << ", Barrierefrei: " << (barrierefrei ? "Ja" : "Nein")   << std::endl;
        std::cout << "Ausstattung: ";
        for (size_t i = 0; i < ausruestung.size(); ++i) {
            std::cout << ausruestung[i];
            if (i < ausruestung.size() - 1) {
                std::cout << ", ";
            }
        }
        std::cout << std::endl;
    }

    bool pruefeVerfuegbarkeit(std::string datum) {
        return verfuegbarkeit[datum];
    }

    void bucheRaum(std::string datum) {
        verfuegbarkeit[datum] = false;  // Setzt die Verfügbarkeit auf false für das gegebene Datum
    }
};

class Buchungssystem {
public:
    std::vector<Raum> raeume;

    void hinzufuegenRaum(const Raum& raum) {
        raeume.push_back(raum);
    }

    Raum* findeFreienRaum(std::string typ, bool barrierefrei, std::string datum) {
        for (auto& raum : raeume) {
            if (raum.typ == typ && raum.barrierefrei == barrierefrei && raum.pruefeVerfuegbarkeit(datum)) {
                return &raum;
            }
        }
        return nullptr;
    }
};

int main() {
    // Beispielräume erstellen
    Raum raum1("0000", "Büroraum", true, {"1 Sitzplatz", "1 Tisch", "2 Monitore", "1 Locker"});
    Raum raum2("0001", "Konferenzraum", true, {"20 Sitzplätze", "20 Tische", "1 Beamer", "2 Lautsprecher"});

    // Buchungssystem initialisieren und Räume hinzufügen
    Buchungssystem system;
    system.hinzufuegenRaum(raum1);
    system.hinzufuegenRaum(raum2);

    // Suche nach einem freien Raum und buche ihn
    Raum* gebuchterRaum = system.findeFreienRaum("Büroraum", true, "2024-05-20");
    if (gebuchterRaum != nullptr) {
        gebuchterRaum->bucheRaum("2024-05-20");
        std::cout << "Raum gebucht: " << gebuchterRaum->raumnummer << std::endl;
    } else {
        std::cout << "Kein Raum verfügbar." << std::endl;
