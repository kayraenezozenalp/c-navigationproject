#include <iostream>
#include <cstdlib>
#include <ctime>
#include <Math.h>

using namespace std;

int main()
{
    srand(time(NULL));
    int size;
    char name[5] = { '#','H','K','O','U' };
    cout << "Please enter the number of buildings = ";
    cin >> size;
    int* x = new int[size];
    int* y = new int[size];
    int b, a, r, z = 0;
    int Userx = 10;
    int Usery = 10;
    for (int i = 0; i < size; i++) {
        x[i] = rand() % 20;
        y[i] = rand() % 20;
    }
    int p;
    p = (1, 2, 3, 4, 5);
    do {
        cout << "CMP1001 Navigation System v1.0" << endl;
        cout << "1 - Print Map" << endl;
        cout << "2 - Find Nearest Building " << endl;
        cout << "3 - Go" << endl;
        cout << "4 - Info " << endl;
        cout << "5 - Close Navigation System" << endl;
        cout << "0 - Exit " << endl;
        cin >> p;
        int ac;
        int ce;
        int s;
        int so;
        int* sonuc = new int[size];
        int Bx;
        int By;
        int t[20][20];
        for (int i = 0; i < 20; i++) {
            for (int j = 0; j < 20; j++) {
                t[i][j] = 0;
            }
        }
        int i;
        int j;
        bool aynivarmi = 0;

        do {
            aynivarmi = 0;
            for (i = 0; i < size; i++) {
                for (j = 0; j < size; j++) {
                    if (i != j && x[i] == x[j] && y[i] == y[j]) {
                        x[i] = rand() % 20;
                        y[i] = rand() % 20;
                        aynivarmi = 1;
                    }

                }
            }
        } while (aynivarmi == 1);
        for (int i = 0; i < size; i++) {
            t[x[i]][y[i]] = rand() % 3 + 1;
        }

        if (p == 1)
        {
            cout << "X|Y";
            for (a = 0; a < 20; a++) {

                if (a < 10) {
                    cout << a << "  ";
                }
                else {
                    cout << a << " ";
                }

            }
            cout << endl;

            for (int i = 0; i < 20; i++) {
                if (i < 10) {
                    cout << i << "  ";
                }
                else {
                    cout << i << " ";
                }
                for (int j = 0; j < 20; j++) {
                    if ((j + 1) == Userx && (i + 1) == Usery) {
                        cout << name[4] << "  ";
                    }
                    else {
                        cout << name[t[i][j]] << "  ";
                    }
                }
                cout << endl;
            }

        }
        if (p == 2)
        {
            int enyakin = 40;
            int ans = 0;
            for (int i = 0; i < size; i++) {
                int mesafe = (x[i] - Userx) * (x[i] - Userx) + (y[i] - Usery) * (y[i] - Usery);
                if (mesafe < enyakin) {
                    ans = i;
                    enyakin = mesafe;
                }

            }
            cout << "--------------------------------------------" << "\nOption2 ------------------------------------" << endl;
            cout << "Nearest Building = " << name[t[x[ans]][y[ans]]] << endl;
            cout << "Location X = " << x[ans] << ' ' << "\nLocation Y = " << y[ans] << endl;
            cout << "--------------------------------------------" << endl;
        }
        if (p == 3)
        {
            int sn;
            int X;
            int Y;
            cout << "--------------------------------------------" << "\nOption3-------------------------------------" << endl;
            cout << "Current Coordinate" << endl;
            cout << "X=10";
            cout << "Y=10";
            int control;
            control = (1, 2, 3, 4);
            int step;
            int q = 0;
            cout << "\nWhich way you want to go UP(1)/RIGHT(2)/DOWN(3)/LEFT(4)" << endl;
            cin >> control;
            if (control > 4 || control < 1) {
                cout << "Please enter again : ";
                cin >> control;
            }
            cout << "Please enter number of step" << endl;
            cin >> step;
            switch (control) {
            case 1:
            {
                for (q = 0; q < 1;) {
                    sn = Usery - step;
                    if (sn < 0) {
                        cout << "The Value you entered goes of the map,Please enter another number between 1-10 : ";
                        cin >> step;
                    }
                    else {
                        Usery = sn;
                        cout << Usery << endl;
                        q = 1;
                    }
                }
                break;
            }
            case 2:
            {
                for (q = 0; q < 1;) {
                    sn = Userx + step;
                    if (sn > 20) {
                        cout << "The Value you entered goes of the map,Please enter another number between 1-10 : ";
                        cin >> step;
                    }
                    else {
                        Userx = sn;
                        cout << Userx;
                        q++;
                    }
                }
                break;
            }
            case 3: {
                for (q = 0; q < 1;) {
                    sn = Usery + step;
                    if (sn > 0) {
                        cout << "The Value you entered goes of the map,Please enter another number between 1-10 : ";
                        cin >> step;
                    }
                    else {
                        Usery = sn;
                        cout << Usery << endl;
                        q++;
                    }
                }
                break;
            }
            case 4:
                for (q = 0; q < 1;) {
                    sn = Userx - step;
                    if (sn < 0) {
                        cout << "The Value you entered goes of the map,Please enter another number between 1-10 : ";
                        cin >> step;
                    }
                    else {
                        Userx = sn;
                        cout << Userx << endl;
                        q++;
                    }
                }
                break;
            }
            cout << endl;
            cout << "X|Y";
            for (a = 0; a < 20; a++) {

                if (a < 10) {
                    cout << a << "  ";
                }
                else {
                    cout << a << " ";
                }

            }
            cout << endl;

            for (int i = 0; i < 20; i++) {
                if (i < 10) {
                    cout << i << "  ";
                }
                else {
                    cout << i << " ";
                }
                for (int j = 0; j < 20; j++) {
                    if ((j + 1) == Userx && (i + 1) == Usery) {
                        cout << name[4] << "  ";
                    }
                    else {
                        cout << name[t[i][j]] << "  ";
                    }
                }
                cout << endl;
            }

        }

        if (p == 4)
        {
            cout << "--------------------------------------------" << "\nOption4-------------------------------------" << endl;
            cout << "U = User Current Location" << "\nH = Hospital" << "\nP = Police Station" << "\nS = School" << endl;
            cout << "--------------------------------------------" << endl;


        }

        if (p == 5)
        {
            cout << "--------------------------------------------" << "\nOption5-------------------------------------" << endl;
            cout << "Goodbye" << "\n--------------------------------------------" << endl;
            break;
        }
    } while (p != 5);




}