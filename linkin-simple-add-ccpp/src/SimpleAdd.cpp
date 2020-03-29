#include <fstream>
#include <iostream>
#include <string.h>
#include <stdlib.h>
#include <vector>
using namespace std;


vector<string> split(const string& str, const string& delim) {
    vector<string> res;
    if("" == str) return res;
    //�Ƚ�Ҫ�и���ַ�����string����ת��Ϊchar*����
    char * strs = new char[str.length() + 1];
    strcpy(strs, str.c_str());

    char * d = new char[delim.length() + 1];
    strcpy(d, delim.c_str());

    char *p = strtok(strs, d);
    while(p) {
        //�ָ�õ����ַ���ת��Ϊstring����
        string s = p;
        res.push_back(s);
        //����������
        p = strtok(NULL, d);
    }

    return res;
}

int main(int argc, char *argv[]) {

	char* input, * output;
	for (int i = 0; i < argc; i++) {
		if (strcmp(argv[i], "-input") == 0) {
			input = argv[++i];
		} else if (strcmp(argv[i], "-output") == 0) {
			output = argv[++i];
		}
	}
//	cout << input << '\n' << output << endl;
    ifstream fin;
    fin.open(input);
    string line, number;
    vector<int> sums;
    while(getline(fin, line)) {
        vector<string> numbers = split(line, "+");
        int sum = 0;
        for (vector<string>::iterator it = numbers.begin(); it != numbers.end(); it++) {
            sum += atoi((*it).c_str());
        }
        sums.push_back(sum);
    }
    fin.close();
    ofstream fout(output);
    for (vector<int>::iterator it = sums.begin(); it != sums.end(); it++) {
        cout << *it << '\n';
        fout << *it << '\n';
    }
    cout << endl;
    fout.close();
    cin.get();
}
