#include <iostream>
#include <istream>
#include <fstream>
#include <string>

using namespace std;

void print_menu() {
    system("cls");
    system("color 0F");
    cout << "Laboratorium 9" << endl
        << "Menu" << endl
        << "1) Task 1" << endl
        << "2) Task 2" << endl
        << "3) Exit" << endl;
}

void printPattern() {
    for (int i = 1; i <= 20; i++) {
        for (int j = 1; j <= 20; j++) {
            if (j == i || j == (21 - i))
                cout << "# # # #";
            else
                cout << "  ";
        }
        cout << endl;
    }
}

/*
Napisz program, który wyświetli kod programu w języku C++ usuwając komentarze, które
są poprzedzone // wraz z tymi znakami. Aby usunąć komentarze można użyć metody ignore.
Należy skorzystać z pliku kod.txt. W programie należy obsłużyć sytuację, kiedy plik nie będzie
istniał poprzez złapanie odpowiedniego wyjątku.
Podpowiedź: Metoda peek umożliwia podgląd kolejnego znaku. Można ją użyć aby
sprawdzić czy występują po sobie dwa znaki //.
*/

istream& deleteComments(istream& stm, string& line)
{
	if (getline(stm, line)) {
		auto pos = line.find("//");
		if (pos == 0) 
			return deleteComments(stm, line);
		else if (pos != string::npos) 
			line.erase(pos);
	}
	return stm;
}

void zad1() {
	ifstream fileIf;
	fileIf.open("kod.txt");
	if (!fileIf) {
		cerr << "ERROR: this file doesn't exist!" << endl;
	}
	else {
		cout << "Opening file...\n\n";
		string line;

		cout << "kod.txt file with comments: \n\n";
		while (getline(fileIf, line)) {
			cout << line << endl;
		}
		fileIf.close();

		fileIf.open("kod.txt");
		cout << "\n\kod.txt file without comments: \n\n";
		while (deleteComments(fileIf, line)) {
			cout << line << endl;
		}
		cout << "\nClosing file..." << endl;
	}
	fileIf.close();
}

/*
Napisz program, w którym użytkownik będzie podawał dodatnią liczbę całkowitą do momentu aż suma podanych przez 
użytkownika liczb będzie mniejsza niż oczko (21). Jeśli suma będzie równa 21 wtedy należy wyświetlić 
odpowiedni komunikat i zakończyć program. Jeśli suma przekroczy 21 należy rzucić wyjątek informujący, 
że suma została przekroczona. Wyjątek należy obsłużyć umożliwiając ponowne podanie ostatniej liczby. 
W programie powinna zostać obsłużona sytuacja, kiedy użytkownik zamiast liczby podaje inny typ danych.
Wtedy użytkownik powinien zostać poproszony o ponowne podanie liczby. 
Program powinien wyświetlić po ilu próbach (udanych i nieudanych) udało się osiągnąć oczko.
*/

void zad2() {
    int sum = 0;
    int attempts = 0;
    int num;

    while (sum < 21)
    {
        cout << "Enter a number: ";
        cin >> num;
        attempts++;

        try
        {
            if (cin.fail())
            {
                throw invalid_argument("The given number is incorrect!");
            }
            sum += num;
            if (sum > 21)
            {
                throw runtime_error("The sum exceeded 21");
            }
        }
        catch (invalid_argument& e)
        {
            cout << e.what() << endl;
            cin.clear();
            cin.ignore(INT_MAX, '\n');
            attempts--;
        }
        catch (runtime_error& e)
        {
            cout << e.what() << endl;
            cout << "Re-enter the last number: ";
            cin >> num;
            sum -= num;
        }
    }
    if (attempts == 1)
        cout << "But you just typed 21! Of course it worked after the " << attempts << " try." << endl;
    else if (attempts > 1)
        cout << "The sum of the numbers is 21! It succeeded after " << attempts << " attempts." << endl;
}

int main() {
    int variant;
    bool isTrue = true;
    while (isTrue) {
        print_menu();
        cin >> variant;
        switch (variant) {
        case 1:
            system("cls");
            zad1();
            system("pause");
            break;
        case 2:
            system("cls");
            zad2();
            system("pause");
            break;
        case 3:
            system("cls");
            cout << "Have a nice day! Goodbye..." << endl;
            isTrue = false;
            break;
        default:
            system("cls");
            system("color 40");
            printPattern();
            cout << "Incorrect symbol!" << endl;
            system("timeout /t 3 /nobreak");
            break;
        }
    }
	return 0;
}
