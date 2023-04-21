#include <iostream>
#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <windows.h>
using namespace std;

/*
Створити базовий клас саг (машина), що характеризується торговою
маркою (рядок), числом циліндрів, потужністю. Визначити методи перепризначення і
зміни потужності. Створити похідний клас Lorry (вантажівка), характеризує також
вантажопідйомністю кузова. Визначити функції перепризначення марки і зміни
вантажопідйомності.
*/

struct Car1 {
    string mark;

    Car1() {
        mark = "No Mark";
        cout << "Default constructor Car \n";
    }

    Car1(string fn) {
        mark = fn;
        cout << "Constructor Car(string fn) \n";
    }

    Car1(const Car1& s) {
        mark = s.mark;
        cout << "Constructor Copy Car(const Car &) \n";
    }

    Car1(Car1&& s) {
        mark = s.mark;
        cout << " Constructor Move Car(Car &&) \n";
        s.mark = "BMW";
    }
    Car1(const char* fn, const int n, const double ln) {
        mark = fn;
        cout << " Constructor Car(const char * ... ) \n";
    }
    ~Car1() {
        cout << "Destructor ~Car() \n";
    }
    Car1& operator=(const Car1& s)
    {
        mark = s.mark;
        cout << " Car operator=(Car &) \n";
        return *this;
    }
    string toString() {
        string ts = "\n     Car: " + mark + " ";
        return ts;
    }
    bool operator==(Car1& b) {
        return mark == b.mark ? true : false;
    }

    void Input() {
        cout << "Input mark: "; cin >> mark;
    }
    friend ostream& operator<<(ostream& os, Car1& a);
    friend istream& operator>>(istream& os, Car1& a);
};


ostream& operator<<(ostream& os, Car1& a) {
    os << a.mark << endl;
    return os;
}
istream& operator>>(istream& is, Car1& a) {
    is >> a.mark;
    return is;
}


class Car
{
protected:
    int cyl, pow;
    Car1 mark;
public:
    Car() {
        cyl = 0;
        pow = 0;
        cout << " Default constructor Car1() \n";
    }
    Car(int a, int w, string n) {
        cyl = a;
        pow = w;
        mark = n;
        cout << " Constructor Person(int a, int w, string n) \n";
    }
    Car(int a, int w, Car1& n) {
           cyl = a;
           pow = w;
           mark = n;
           cout << " Constructor Person(int a, int w, Car n) \n";
    }
    
    ~Car()
    {
        cout << "\tDestructor Car\n";
    }

    void setCyl(int a) {
        if (a >= 0 && a <= 10)
            cyl = a;
        else
            cout << "Cyl " << a << " not allow, cyl is " << cyl << endl;;
    }

    void setPow(int w) {
        if (w >= 0 && w <= 100)
            pow = w;
        else
            cout << "Pow " << w << " not exist, pow is " << pow << endl;;
    }

    string toString() {
        string r, a, w;
        a = to_string(cyl);
        w = to_string(pow);
        r = mark.toString() + " \n     Cyl: " + a + " \n     Pow: " + w;
        return r;
    }

    void Input() {
        mark.Input();
        cout << "Input cyl "; while (!(cin >> cyl) || (cyl < 0 || cyl > 10)) {
            cin.clear();
            cin.ignore(MAXSHORT, '\n');
            fflush(stdin);
            cout << "bad input cyl is 1 to 10 \n";
        };

        cout << "Input pow "; while (!(cin >> pow) || (pow < 0 || pow > 100)
            ) {
            cin.clear();
            cin.ignore(MAXSHORT, '\n');
            fflush(stdin);
            cout << "bad input pow is 1 to 100 \n";
        };
    }

    friend ostream& operator<<(ostream& os, Car& a);
    friend istream& operator>>(istream& os, Car& a);
};

ostream& operator<<(ostream& os, Car& a) {
    os << a.mark;
    os << a.cyl << endl;
    os << a.pow << endl;
    return os;
}
istream& operator>>(istream& is, Car& a) {
    is >> a.mark;
    is >> a.cyl;
    is >> a.pow;
    return is;
}


class Lorry : public Car {
    long long K;
public:
    Lorry() {
        K = 0;
        cout << " Default constructor Lorry() \n";
    }
    Lorry(int a, int w, string n, long long i) :
        Car(a, w, n) {
        K = i;
        cout << " Constructor Lorry(int a, int w, string n, long long i) \n";
    }
    
    Lorry(int a, int w, Car1& pi, long long i) :
        Car(a, w, pi) {
        K = i;
        cout << " Constructor Car(int a, int w, PIB& pib, long long i) \n";
    }
    ~Lorry() {
        cout << "\tDestructor Lorry\n";
    }
    void setK(long long i) {
        if (i > 0) K = i;
        else K = 0;
    }
    string toString() {
        string sK;
        sK = to_string(K);
        string s = Car::toString() + " \n     K: " + sK + "\n ";
        return s;
    }
    void Input() {
        Car::Input();
        cout << "Input K ";
        while (!(cin >> K) || K < 0) {
            cin.clear();
            cin.ignore(MAXSHORT, '\n');
            fflush(stdin);
            cout << "bad input K \n";
        };
    }
    void Output() {
        cout << toString() << endl;
    }
    friend ostream& operator<<(ostream& os, Lorry& a);
    friend istream& operator>>(istream& os, Lorry& a);
};
ostream& operator<<(ostream& os, Lorry& a) {
    os << a.mark;
    os << a.cyl << endl;
    os << a.pow << endl;
    os << a.K << endl;
    return os;
}
istream& operator>>(istream& is, Lorry& a) {
    is >> a.mark;
    is >> a.cyl;
    is >> a.pow;
    is >> a.K;
    return is;
}

int main1() {

    char Choice = 'n';
    do {
        cout << "\n\n\n Main menu \n";
        cout << "1 - Default constructor Lorry \n";
        cout << "2 - Default constructor Lorry input \n";
        cout << "3 - Constructor Lorry Lorry(int a, int w, Car1 pi, long long i) \n";
        cout << "4 - Set Cyl \n";
        cout << "5 - Set Pow \n";
        cout << "6 - Set K \n";
        cout << "7 - Input from file \n";
        cout << "8 - Input array of Lorry and save file \n";
        cout << "q - Quit \n";
        cout << "Your choice: ";
        cin >> Choice;
        switch (Choice)
        {
        case '1': {
            Car1 test;
            cout << test.toString() << " \n";
        }
                break;
        case '2': {
            Lorry test;
            cout << " Input mark: \n";
            test.Input();
            cout << " Input " << test.toString() << " \n";
        }
                break;
        case '3': {
            Car1 mark("Tesla");
            Lorry t(5, 100, mark, 2323190);
            string rez = t.toString();
            cout << rez;
        }
                break;
        case '4': {
            Car1 mark("Ferrari");
            Lorry t(10, 78, mark, 2323191);
            t.toString();
            cout << t.toString() << endl;
            cout << " Input new cyl: ";
            int newC;
            while (!(cin >> newC)) {
                cin.clear();
                cin.ignore(MAXSHORT, '\n');
                fflush(stdin);
                cout << "bad input \n";
            };
            t.setCyl(newC);
            cout << " New recoeds " << t.toString() << endl;
        }
                break;
        case '5': {
            Car1 pi("Ford");
            Lorry t(10, 49, pi, 2323192);
            t.toString();
            cout << t.toString() << endl;
            cout << " Input new Pow: ";
            long long newP;
            while (!(cin >> newP)) {
                cin.clear();
                cin.ignore(MAXSHORT, '\n');
                fflush(stdin);

                cout << "bad input \n";
            };
            t.setPow(newP);
            cout << " New recoeds " << t.toString() << endl;
        }
                break;


        case '6': {
            Car1 pi("Porche");
            Lorry t(10, 50, pi, 2323193);
            t.toString();
            cout << t.toString() << endl;
            cout << " Input new K: ";
            long long newK;
            while (!(cin >> newK)) {
                cin.clear();
                cin.ignore(MAXSHORT, '\n');
                fflush(stdin);

                cout << "bad input \n";
            };
            t.setK(newK);
            cout << " New recoeds " << t.toString() << endl;
        }
                break;


        case '7': {
            ifstream fileLorry("fileLorry1.txt");
            int n, i;
            fileLorry >> n;
            if (n > 0)
            {
                Lorry* pMas;
                pMas = new Lorry[n];
                for (i = 0; i < n; i++)
                    fileLorry >> pMas[i];
                cout << "Lorry in file \n";
                for (i = 0; i < n; i++)
                    cout << pMas[i].toString() << endl;
                cout << " delete \n";
                delete[] pMas;
            }
        }
                break;
        case '8': {
            ofstream fileLorry("fileLorry1.txt");
            int n, i;
            cout << " Input num Lorry ";
            while (!(cin >> n) || n < 0) {
                cin.clear();
                cin.ignore(MAXSHORT, '\n');
                fflush(stdin);
                cout << "bad input num \n";
            };
            Lorry* pMas;
            pMas = new Lorry[n];
            for (i = 0; i < n; i++)
                pMas[i].Input();
            cout << "Lorry in input e \n";
            for (i = 0; i < n; i++)
                cout << pMas[i].toString() << endl;
            fileLorry << n << endl;
            for (i = 0; i < n; i++)
                fileLorry << pMas[i];
            cout << "Lorry save in file \n";
            cout << " delete \n";
            delete[] pMas;
        }
        case 'q': break;
        default:
            cout << " ??? Choice {1,2, ..., 7 or q} \n";
        }
    } while (Choice != 'q');
    cout << " Exit from test! Bye! \n";
    return 0;

}





/*
Створити клас кнопка, що має розмір. Визначити конструктори й метод
доступу. Створити клас вікно, що містить клас кнопка. Додатково є координати
вікна. Визначити конструктори й деструктор. Визначити public- похідний клас вікно
із кнопкою меню, що й має (вказівник на рядок). Визначити конструктори,
деструктори й функцію друку
*/



struct Button {
    string size;

    Button() {
        size = "No Size";
        cout << "Default constructor Button \n";
    }

    Button(string fn) {
        size = fn;
        cout << "Constructor Button(string fn) \n";
    }

    Button(const Button& s) {
        size = s.size;
        cout << "Constructor Copy Button(const Button &) \n";
    }

    Button(Button&& s) {
        size = s.size;
        cout << " Constructor Move Button(Button &&) \n";
        s.size = "BMW";
    }
    Button(const char* fn, const int n, const double ln) {
        size = fn;
        cout << " Constructor Button(const char * ... ) \n";
    }
    ~Button() {
        cout << "Destructor ~Button() \n";
    }
    Button& operator=(const Button& s)
    {
        size = s.size;
        cout << " Button operator=(Button &) \n";
        return *this;
    }
    string toString() {
        string ts = "\n     Size: " + size + " ";
        return ts;
    }
    bool operator==(Button& b) {
        return size == b.size ? true : false;
    }

    void Input() {
        cout << "Input size: "; cin >> size;
    }
    friend ostream& operator<<(ostream& os, Button& a);
    friend istream& operator>>(istream& os, Button& a);
};


ostream& operator<<(ostream& os, Button& a) {
    os << a.size << endl;
    return os;
}
istream& operator>>(istream& is, Button& a) {
    is >> a.size;
    return is;
}


class Wind
{
protected:
    int x, y;
    Button size;
public:
    Wind() {
        x = 0;
        y = 0;
        cout << " Default constructor Wind() \n";
    }
    Wind(int a, int w, string n) {
        x = a;
        y = w;
        size = n;
        cout << " Constructor Person(int a, int w, string n) \n";
    }
    Wind(int a, int w, Button& n) {
        x = a;
        y = w;
        size = n;
        cout << " Constructor Person(int a, int w, Wind n) \n";
    }

    ~Wind()
    {
        cout << "\tDestructor Wind\n";
    }

    void setCyl(int a) {
        if (a >= 0 && a <= 10)
            x = a;
        else
            cout << "X " << a << " not allow, X is " << x << endl;
    }

    void setPow(int w) {
        if (w >= 0 && w <= 10)
            y = w;
        else
            cout << "Y " << w << " not exist, Y is " << y << endl;;
    }

    string toString() {
        string r, a, w;
        a = to_string(x);
        w = to_string(y);
        r = size.toString() + " \n     X: " + a + " \n     Y: " + w;
        return r;
    }

    void Input() {
        size.Input();
        cout << "Input X "; while (!(cin >> x) || (x < 0 || x > 10)) {
            cin.clear();
            cin.ignore(MAXSHORT, '\n');
            fflush(stdin);
            cout << "bad input X is 1 to 10 \n";
        };

        cout << "Input Y "; while (!(cin >> y) || (y < 0 || y > 10)
            ) {
            cin.clear();
            cin.ignore(MAXSHORT, '\n');
            fflush(stdin);
            cout << "bad input Y is 1 to 10 \n";
        };
    }

    friend ostream& operator<<(ostream& os, Wind& a);
    friend istream& operator>>(istream& os, Wind& a);
};

ostream& operator<<(ostream& os, Wind& a) {
    os << a.size;
    os << a.x << endl;
    os << a.y << endl;
    return os;
}
istream& operator>>(istream& is, Wind& a) {
    is >> a.size;
    is >> a.x;
    is >> a.y;
    return is;
}


class Public : public Wind {
    long long K;
public:
    Public() {
        K = 0;
        cout << " Default constructor Public() \n";
    }
    Public(int a, int w, string n, long long i) :
        Wind(a, w, n) {
        K = i;
        cout << " Constructor Public(int a, int w, string n, long long i) \n";
    }

    Public(int a, int w, Button& pi, long long i) :
        Wind(a, w, pi) {
        K = i;
        cout << " Constructor Wind(int a, int w, PIB& pib, long long i) \n";
    }
    ~Public() {
        cout << "\tDestructor Public\n";
    }
    void setK(long long i) {
        if (i > 0) K = i;
        else K = 0;
    }
    string toString() {
        string sK;
        sK = to_string(K);
        string s = Wind::toString() + " \n     K: " + sK + "\n ";
        return s;
    }
    void Input() {
        Wind::Input();
        cout << "Input K (Model code) ";
        while (!(cin >> K) || K < 0) {
            cin.clear();
            cin.ignore(MAXSHORT, '\n');
            fflush(stdin);
            cout << "bad input K \n";
        };
    }
    void Output() {
        cout << toString() << endl;
    }
    friend ostream& operator<<(ostream& os, Public& a);
    friend istream& operator>>(istream& os, Public& a);
};
ostream& operator<<(ostream& os, Public& a) {
    os << a.size;
    os << a.x << endl;
    os << a.y << endl;
    os << a.K << endl;
    return os;
}
istream& operator>>(istream& is, Public& a) {
    is >> a.size;
    is >> a.x;
    is >> a.y;
    is >> a.K;
    return is;
}

int main2() {

    char Choice = 'n';
    do {
        cout << "\n\n\n Main menu \n";
        cout << "1 - Default constructor Public \n";
        cout << "2 - Default constructor Public input \n";
        cout << "3 - Constructor Public Public(int a, int w, Car1 pi, long long i) \n";
        cout << "4 - Set X \n";
        cout << "5 - Set Y \n";
        cout << "6 - Set K \n";
        cout << "7 - Input from file \n";
        cout << "8 - Input array of Public and save file \n";
        cout << "q - Quit \n";
        cout << "Your choice: ";
        cin >> Choice;
        switch (Choice)
        {
        case '1': {
            Button test;
            cout << test.toString() << " \n";
        }
                break;
        case '2': {
            Public test;
            cout << " Input size: \n";
            test.Input();
            cout << " Input " << test.toString() << " \n";
        }
                break;
        case '3': {
            Button size("10");
            Public t(5.15, 10.1, size, 24856);
            string rez = t.toString();
            cout << rez;
        }
                break;
        case '4': {
            Button size("1");
            Public t(4.98, 4.6, size, 2534);
            t.toString();
            cout << t.toString() << endl;
            cout << " Input new X: ";
            int newC;
            while (!(cin >> newC)) {
                cin.clear();
                cin.ignore(MAXSHORT, '\n');
                fflush(stdin);
                cout << "bad input \n";
            };
            t.setCyl(newC);
            cout << " New recoeds " << t.toString() << endl;
        }
                break;
        case '5': {
            Button pi("52");
            Public t(8.56, 4.96, pi, 752);
            t.toString();
            cout << t.toString() << endl;
            cout << " Input new Y: ";
            long long newP;
            while (!(cin >> newP)) {
                cin.clear();
                cin.ignore(MAXSHORT, '\n');
                fflush(stdin);

                cout << "bad input \n";
            };
            t.setPow(newP);
            cout << " New recoeds " << t.toString() << endl;
        }
                break;


        case '6': {
            Button pi("4");
            Public t(1.2, 7.41, pi, 956);
            t.toString();
            cout << t.toString() << endl;
            cout << " Input new K: ";
            long long newK;
            while (!(cin >> newK)) {
                cin.clear();
                cin.ignore(MAXSHORT, '\n');
                fflush(stdin);

                cout << "bad input \n";
            };
            t.setK(newK);
            cout << " New recoeds " << t.toString() << endl;
        }
                break;


        case '7': {
            ifstream filePublic("filePublic1.txt");
            int n, i;
            filePublic >> n;
            if (n > 0)
            {
                Public* pMas;
                pMas = new Public[n];
                for (i = 0; i < n; i++)
                    filePublic >> pMas[i];
                cout << "Public in file \n";
                for (i = 0; i < n; i++)
                    cout << pMas[i].toString() << endl;
                cout << " delete \n";
                delete[] pMas;
            }
        }
                break;
        case '8': {
            ofstream filePublic("filePublic1.txt");
            int n, i;
            cout << " Input num Public ";
            while (!(cin >> n) || n < 0) {
                cin.clear();
                cin.ignore(MAXSHORT, '\n');
                fflush(stdin);
                cout << "bad input num \n";
            };
            Public* pMas;
            pMas = new Public[n];
            for (i = 0; i < n; i++)
                pMas[i].Input();
            cout << "Public in input e \n";
            for (i = 0; i < n; i++)
                cout << pMas[i].toString() << endl;
            filePublic << n << endl;
            for (i = 0; i < n; i++)
                filePublic << pMas[i];
            cout << "Public save in file \n";
            cout << " delete \n";
            delete[] pMas;
        }
        case 'q': break;
        default:
            cout << " ??? Choice {1,2, ..., 7 or q} \n";
        }
    } while (Choice != 'q');
    cout << " Exit from test! Bye! \n";
    return 0;

}



int main()
{
    int n;
    cout << "N: ";
e: cin >> n;

    switch (n) {
    case 1: main1(); break;
    case 2: main2(); break;
    default: cout << "Error\n"; goto e;
    }

    return 0;
}