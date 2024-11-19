#include <iostream>
#include <fstream>
#include <cctype>
#include <string>

using namespace std;

int main() {
    const string inputFilePath = "vstup.txt"; // D:\\vstup.txt
    const string outputFilePath = "vysledky.txt"; // D:\\vysledky.txt

    ifstream inputFile(inputFilePath);
    if (!inputFile.is_open()) {
        cerr << "Nepodařilo se otevřít vstupní soubor: " << inputFilePath << endl;
        return 1;
    }

    int letterCount = 0;
    int digitCount = 0;
    char ch;

    while (inputFile.get(ch)) {
        if (isalpha(static_cast<unsigned char>(ch))) {
            letterCount++;
        } else if (isdigit(static_cast<unsigned char>(ch))) {
            digitCount++;
        }
    }

    inputFile.close();

    cout << "Pocet pismen: " << letterCount << endl;
    cout << "Pocet cislic: " << digitCount << endl;

    ofstream outputFile(outputFilePath);
    if (!outputFile.is_open()) {
        cerr << "Nepodařilo se otevřít výstupní soubor: " << outputFilePath << endl;
        return 1;
    }

    outputFile << "Pocet pismen: " << letterCount << "\n";
    outputFile << "Pocet cislic: " << digitCount << "\n";

    outputFile.close();
    return 0;
}
