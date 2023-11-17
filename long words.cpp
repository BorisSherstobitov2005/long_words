#include <iostream>
#include <math.h>
#include <string>

using namespace std;
template <typename T>
void print(T text) {
    cout << text << endl;
}
int main()
{
    print("Отправьте текст: ");
    string text;
    getline(cin, text);
    text += " ";
    string words[1000];
    string new_word = "";
    for (int i = 0; i < text.length(); i++) {
        if (text[i] == ' ' or text[i] == '.' or text[i] == ',' or text[i] == '?' or text[i] == '!') {
            if (new_word != "") {
                words[i] = new_word;
            }
            new_word = "";
        }
        else {
            new_word += text[i];
        }
    }
    int count = 0;
    int min_length = 1000000;
    int max_length = 0;
    for (int i = 0; i < 1000; i++) {
        if (words[i].length() > 0) {
            count += 1;
            if (words[i].length() < min_length) min_length = words[i].length();
            if (words[i].length() > max_length) max_length = words[i].length();
        }
    }
    print("Всего слов: "+to_string(count));
    print("Самые длинные слова (" + to_string(max_length)+"): ");
    for (int i = 0; i < 1000; i++) {
        if (words[i].length() == max_length) print(words[i]);
    }
    print("Самые короткие слова (" + to_string(min_length) + "): ");
    for (int i = 0; i < 1000; i++) {
        if (words[i].length() == min_length) print(words[i]);
    }
    return 0;
}