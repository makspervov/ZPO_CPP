#include <iostream>
#include <string>
#include <regex>
#include <istream>
#include <fstream>

using namespace std;

void print_menu() {
    system("cls");
    system("color 0F");
    cout << "Laboratorium 10" << endl
        << "Menu" << endl
        << "1) Task 1" << endl
        << "2) Task 2" << endl
        << "3) Task 3" << endl
        << "4) Task 4" << endl
        << "5) Task 5" << endl
        << "e) Exit" << endl;
}

void printPattern() {
    cout << R"(   _                   _
 _( )                 ( )_
(_, |      __ __      | ,_)
   \'\    /  ^  \    /'/
    '\'\,/\      \,/'/'
      '\| []   [] |/'
        (_  /^\  _)
          \  ~  /
          /HHHHH\
        /'/{^^^}\'\
    _,/'/'  ^^^  '\'\,_
   (_, |           | ,_)
     (_)           (_)
    )" << endl;
}

void zad1() {
    string liczba;
    cout << "Wprowadz liczbe: ";
    cin >> liczba;

    if (regex_match(liczba, regex("[+-][0-9]+\\.[0-9]+")))
        cout << "Wprowadzono liczbe zmiennoprzecinkowa ze znakiem" << endl;
    else if (regex_match(liczba, regex("[+-]?[0-9]+\\.?[0-9]+")))
        cout << "Wprowadzono liczbe zmiennoprzecinkowa bez znaku" << endl;
    else
        cout << "To nie jest liczba" << endl;
}

void zad2() {
    string time;
    cout << "Podaj czas w formacie hh:mm lub hh:mm:ss: ";
    cin >> time;

    regex pattern("([01][0-9]|2[0-3]):[0-5][0-9](:[0-5][0-9])?");
    //regex pattern("([01][0-9]|2[0-3])(:[0-5][0-9]){1,2}");

    if (regex_match(time, pattern))
        cout << "Czas wpisany poprawnie" << endl;
    else
        cout << "Czzas nie jest wpisany poprawnie" << endl;
}

void zad3() {
    string kod_pocztowy;
    string ulica;
    string dom;
    string mieszkanie;

    cout << "Wprowadz dane (kod, ulica, nr. domu, nr. mieszkania): ";
    cin >> kod_pocztowy;
    cin >> ulica;
    cin >> dom;
    cin >> mieszkanie;

    cout << "\n\nKod pocztowy: ";
    if (regex_match(kod_pocztowy, regex("[0-9]{2}-[0-9]{3}")))
        cout << "poprawnie wpisana" << endl;
    else
        cout << "niepoprawnie wpisana" << endl;

    cout << "Ulica: ";
    if (regex_match(ulica, regex("[A-Z][a-z ]+")))
        cout << "poprawnie wpisana" << endl;
    else
        cout << "niepoprawnie wpisana" << endl;

    cout << "Numer domu: ";
    if (regex_match(dom, regex("[1-9][0-9]+[A-Z]?")))
        cout << "poprawnie wpisana" << endl;
    else
        cout << "niepoprawnie wpisana" << endl;

    cout << "Numer mieszkania: ";
    if (regex_match(mieszkanie, regex("[1-9][0-9]*")))
        cout << "poprawnie wpisana" << endl;
    else
        cout << "niepoprawnie wpisana" << endl;

    /*string input;

    input = "01-001";
    cout << endl << "Kod pocztowy: " << input << endl;

    if (regex_match(input, regex("[0-9]{2}-[0-9]{3}")))
        cout << "Poprawny kod pocztowy" << endl;
    else
        cout << "Niepoprawny kod pocztowy" << endl;

    input = "Velyka Zhytomyrska";
    cout << endl << "Ulica: " << input << endl;
    if (regex_match(input, regex("[A-Za-z0-9 ]+")))
        cout << "Poprawna ulica" << endl;
    else
        cout << "Niepoprawna nazwa ulicy" << endl;

    input = "27";
    cout << endl << "Numer domu: " << input << endl;
    if (regex_match(input, regex("[0-9]+[A-Z]?")))
        cout << "Poprawny numer domu" << endl;
    else
        cout << "Niepoprawny numer domu" << endl;

    input = "15";
    cout << endl << "Numer mieszkania: " << input << endl;
    if (regex_match(input, regex("[0-9]+")))
        cout << "Poprawny numer mieszkania" << endl;
    else
        cout << "Niepoprawny numer mieszkania" << endl;*/
}

void zad4() {
    string imie;
    string nazwisko;
    string wiek;
    string numer_telefonu;
    string email;

    cout << "Wprowadz dane: ";
    cin >> imie;
    cin >> nazwisko;
    cin >> wiek;
    cin >> numer_telefonu;
    cin >> email;

    if (regex_match(imie, regex("^[A-Za-z]+$"))) {
        if (regex_match(nazwisko, regex("^[A-Za-z]+(-[A-Za-z]+)*$"))) {
            if (regex_match(wiek, regex("^[0-9]{1,2}$"))) {
                if (regex_match(numer_telefonu, regex("^[1-9][0-9]{8}$"))) {
                    if (regex_match(email, regex("^([a-z0-9._-]+)@([a-z0-9.-]+)\.([a-z]{2,})$"))) {    //[a-z][a-z0-9-.]+@[a-z]+\\.[a-z]+
                        cout << "Wpisane dane sa poprawne!" << endl
                            << "Zapisywanie do pliku dane.txt..." << endl;

                        string dane = imie + ";" + nazwisko + ";" + wiek + ";" + numer_telefonu + ";" + email + ";";
                        ofstream file("dane.txt", ios::app);
                        if (!file) {
                            cerr << "ERROR: ten plik nie istnieje!" << endl;
                        }
                        else if (file.is_open())
                            file << dane << endl;
                        file.close();
                    }
                    else
                        cout << "Niepoprawny email" << endl;
                }
                else
                    cout << "Niepoprawny numer telefonu" << endl;
            }
            else
                cout << "Niepoprawny wiek" << endl;
        }
        else
            cout << "Niepoprawne nazwisko" << endl;
    }
    else
        cout << "Niepoprawne imie" << endl;

}

int main()
{
    char variant;
    bool isTrue = true;
    while (isTrue) {
        print_menu();
        cin >> variant;
        switch (variant) {
        case '1':
            system("cls");
            zad1();
            system("pause");
            break;
        case '2':
            system("cls");
            zad2();
            system("pause");
            break;
        case '3':
            system("cls");
            zad3();
            system("pause");
            break;
        case '4':
            system("cls");
            zad4();
            system("pause");
            break;
        case 'e':
            system("cls");
            system("color 02");
            cout << "Have a nice day! Goodbye..." << endl;
            system("timeout /t 3 /nobreak");
            isTrue = false;
            break;
        default:
            system("cls");
            system("color 40");
            printPattern();
            cout << "\tIncorrect symbol!" << endl;
            system("timeout /t 3 /nobreak");
            break;
        }
    }
    return 0;
}