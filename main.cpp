#include <iostream>
#include <fstream>
#include <cmath>

using namespace std;
int a, b, c, x1, x2, D;
ifstream file;
ofstream fout;

int count(int a, int b, int c) {
    D = 0;
    D = (b * b - 4 * a * c);
    if (D < 0) {
        fout << "D меньше нуля" << endl;
        fout << "-----------------------" << endl;
    } else if (D == 0) {
        x1 = -b / 2 * a;
        fout << x1 << endl;
        fout << "-------------------" << endl;
    } else if (D > 0) {
        x1 = -b + sqrt(D) / 2 * a;
        x2 = -b - sqrt(D) / 2 * a;
        fout << x1 << endl;
        fout << x2 << endl;
        fout << "-------------------" << endl;
    }
    return 0;
}

int main(int argc, char **argv) {
    if (argc == 1) {
        cout << "Calculator" << endl;
        cout << "Input: kvadrat_with_file inputfile" << endl;
        cout << "or kvadrat_with_file a b c" << endl;
        return 0;
    }
    file.open(argv[1]);
    if (file.is_open() != 1) {
        a = atoi(argv[1]);
        b = atoi(argv[2]);
        c = atoi(argv[3]);
        fout.open(argv[4]);
        count(a, b, c);
    } else {
        fout.open(argv[2]);
        while(file.eof() != 1) {
            file >> a;
            file >> b;
            file >> c;
            count(a,b,c);
        }
    }
    file.close();
    return 0;
}
