#include "algo.h"
#include <bits/stdc++.h>

#define INF 0x3f3f3f3f

using namespace std;

inline void scanning(int &number) {
    int character;
    bool negFlag;
    negFlag = 0;

    character = getchar_unlocked();

    if (character == '-') {
        negFlag = 1;
        character = getchar_unlocked();
    }

    number = 0;

    for (; (character > 47 && character < 58); character = getchar_unlocked()) {
        number = number * 10 + character - 48;
    }

    if (negFlag == 1) {
        number *= -1;
    }
}

inline void printing(int n, ofstream &f) {
    char number[70];
    int contor = 0;

	do {
		number[contor++] = n % 10 + '0';
		n = n / 10;
	} while (n != 0);

    --contor;

    while (contor >= 0) {
        f << number[contor--];
    }

    f << ' ';
}

int main(int argc, char** argv) {
    if (argc != 2) {
        cout << "Usage: " << argv[0] << " input_file\n";
    }
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    string test_no = argv[1];
    string input_file = "./test.in";
    string output_file = "./test.out";

    FILE *fin = freopen(input_file.c_str(), "r", stdin);

    ofstream f(output_file);
    int n, m;
    // decoment in order to measure time
    // auto start = chrono::high_resolution_clock::now();

    scanning(n);
    scanning(m);

    vector< vector<edge> > neig_list(n);
    vector< vector<int> > result_matrix(n, vector<int>(n, -1));

    for (int i = 1; i <= m; ++i) {
        int source, destination, cost;
        scanning(source);
        scanning(destination);
        scanning(cost);

        neig_list[source - 1].push_back(make_pair(destination - 1, cost));
    }

    result_matrix = shortest_path_all(neig_list);

    //auto stop = chrono::high_resolution_clock::now();
    //auto duration = chrono::duration_cast<chrono::microseconds>(stop - start);
    //printing(duration.count(), f);

    if (result_matrix[0][0] == -1) {
        f << "wrong input";
    } else {
        for (int i = 0; i < n; ++i, f << '\n') {
            for (int j = 0; j < n; ++j) {
                if (result_matrix[i][j] == -1) {
                    f << "inf ";
                } else {
                    printing(result_matrix[i][j], f);
                }
            }
        }
    }
    f.close();
    fclose(fin);

    return 0;
}