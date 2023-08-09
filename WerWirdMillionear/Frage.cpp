#include "Frage.h"
#include <QSqlQuery>
#include <QString>

Frage::Frage(int frageID, const std::string& frage, const std::string& antwort1,
             const std::string& antwort2, const std::string& antwort3, const std::string& antwort4,
             char richtigeAntwort, const std::string& kategorie)
    : frageID(frageID), frage(frage), antwort1(antwort1), antwort2(antwort2),
    antwort3(antwort3), antwort4(antwort4), richtigeAntwort(richtigeAntwort), kategorie(kategorie) {}

Frage Frage::erstelleZufaelligeFrage(const std::string& kategorie, const std::string& schwierigkeit) {
    QSqlQuery query;
    QString tableName;

    int randomId = 0;

    if (schwierigkeit == "einfach") {
        if (kategorie == "Sport") {
            randomId = rand() % 25 + 1; // Zufällige Zahl zwischen 1 und 25
        } else if (kategorie == "Wissenschaft") {
            randomId = rand() % 29 + 26; // Zufällige Zahl zwischen 26 und 54
        } else if (kategorie == "Kunst und Kultur") {
            randomId = rand() % 28 + 55; // Zufällige Zahl zwischen 55 und 82
        } else if (kategorie == "Geschichte") {
            randomId = rand() % 30 + 83; // Zufällige Zahl zwischen 83 und 112
        }else if (kategorie == "allgemein") {
            randomId = rand() % 112 + 1; // Zufällige Zahl zwischen 1 und 112
        }
        tableName = "fragenkatalog_einfach";
    } else if (schwierigkeit == "mittelschwer") {
        if (kategorie == "Sport") {
            randomId = rand() % 30 + 1; // Zufällige Zahl zwischen 1 und 30
        } else if (kategorie == "Wissenschaft") {
            randomId = rand() % 30 + 31; // Zufällige Zahl zwischen 31 und 60
        } else if (kategorie == "Kunst und Kultur") {
            randomId = rand() % 30 + 61; // Zufällige Zahl zwischen 61 und 90
        } else if (kategorie == "Geschichte") {
            randomId = rand() % 23 + 91; // Zufällige Zahl zwischen 91 und 113
        }else if (kategorie == "allgemein") {
            randomId = rand() % 113 + 1; // Zufällige Zahl zwischen 1 und 113
        }
        tableName = "fragenkatalog_mittelschwer";
    } else if (schwierigkeit == "schwer") {
        if (kategorie == "Sport") {
            randomId = rand() % 30 + 91; // Zufällige Zahl zwischen 91 und 120
        } else if (kategorie == "Wissenschaft") {
            randomId = rand() % 30 + 31; // Zufällige Zahl zwischen 31 und 60
        } else if (kategorie == "Kunst und Kultur") {
            randomId = rand() % 30 + 61; // Zufällige Zahl zwischen 61 und 90
        } else if (kategorie == "Geschichte") {
            randomId = rand() % 30 + 1; // Zufällige Zahl zwischen 1 und 30
        }else if (kategorie == "allgemein") {
            randomId = rand() % 120 + 1; // Zufällige Zahl zwischen 1 und 120
        }
        tableName="fragenkatalog_schwer";
    }

    if (randomId == 0) {
        // Fehlerfall: Leeres Frage-Objekt zurückgeben
        return Frage(0, "", "", "", "", "", ' ', "");
    }
    query.prepare("SELECT frage, antwort1, antwort2, antwort3, antwort4, richtigeAntwort FROM " + tableName + " WHERE FrageID = :id AND kategorie = :kategorie");
    query.bindValue(":id", randomId);
    query.bindValue(":kategorie", QString::fromStdString(kategorie));

    if (query.exec() && query.next()) {
        std::string frageText = query.value(0).toString().toStdString();
        std::string antwort1 = query.value(1).toString().toStdString();
        std::string antwort2 = query.value(2).toString().toStdString();
        std::string antwort3 = query.value(3).toString().toStdString();
        std::string antwort4 = query.value(4).toString().toStdString();
        char richtigeAntwort = query.value(5).toString().toStdString()[0];

        return Frage(randomId, frageText, antwort1, antwort2, antwort3, antwort4, richtigeAntwort, kategorie);
    }

    // Fehlerfall: Leeres Frage-Objekt zurückgeben
    return Frage(0, "", "", "", "", "", ' ', "");
}

std::string Frage::getFrage() const {
    return frage;
}

std::vector<std::string> Frage::getAntworten() const {
    std::vector<std::string> antworten = {antwort1, antwort2, antwort3, antwort4};
    return antworten;
}

char Frage::getRichtigeAntwort() const {
    return richtigeAntwort;
}

std::string Frage::getKategorie() const {
    return kategorie;
}

bool Frage::istAntwortKorrekt(char benutzerAntwort) const {
    return benutzerAntwort == richtigeAntwort;
}
bool operator==(const Frage& frage1, const Frage& frage2) {
    // Hier vergleichen Sie die Attribute, die für die Frageeinzigartigkeit relevant sind.
    // Wenn diese gleich sind, geben Sie true zurück, sonst false.
    // Beispiel:
    return frage1.getFrage() == frage2.getFrage() &&
           frage1.getAntworten() == frage2.getAntworten() &&
           frage1.getRichtigeAntwort() == frage2.getRichtigeAntwort();
}
