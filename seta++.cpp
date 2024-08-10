
#include <iostream>
#include <map>
#include <string>
using namespace std;

int main() {
    map<char, int> frequency;
    string paragraph;

    cout << "Enter a paragraph: ";
    getline(cin, paragraph);

    for (char ch : paragraph) {
            frequency[ch]++;
    }

   cout << "Character frequencies:" << endl;
    for (const auto& pair : frequency) {
        cout << pair.first << ": " << pair.second << endl;
    }

    return 0;
}
