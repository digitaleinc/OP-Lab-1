#include "file_stream.h"

string get_input(string input_text) {
    fflush(stdin);
    string input_res;
    cout << input_text;
    cin >> input_res;
    fflush(stdin);
    return input_res;
}

void file_input(const string& file) {
    ofstream f_stream;
    string text;

    f_stream.open(file, ios::app);
    if (f_stream.is_open()) {
        cout << "\nPlease, write a text into file (if you want to stop, press DOUBLE ENTER):" << endl;
        while(getline(cin, text)&&!text.empty()) {
            if(!text.empty())
                f_stream << text << "\n";
        }
        cout << "\nText was successfully saved in file: " << file << endl;
        f_stream.close();
    } else
        cout << "Opening file ("<< file <<") was failed" << endl;
}

void show_file(const string& file) {
    ifstream f_stream;
    f_stream.open(file, ios::out);

    string line;

    if (f_stream.is_open()) {
        cout << "\n------------------------------------------" << endl;
        cout << "\n  The content of file (" << file << ")" << endl;
        cout << "\n------------------------------------------" << endl;

        while (getline(f_stream, line)) {
            cout << line << endl;
        }
    } else
        cout << "Opening file ("<< file <<") was failed" << endl;

    f_stream.close();
}

void file_copy(const string& from, const string& to) {
    ifstream file_input{from}; // Файл для читання
    ofstream file_output{to}; // Файл для запису

    string line;

    if (file_input.is_open() && file_output.is_open()) {
        while (getline(file_input, line)) {
            file_output << line << "\n";
        }
    } else
        cout << "Error with opening files.\n";

    file_input.close();
    file_output.close();

    if (from == "temp_file.txt")
        remove(from.c_str());
}

string word_change(string old_word) {
    string new_word;
    new_word = "(" + old_word + ")";
    cout << "\nModified word is:\n" << new_word << endl;
    return new_word;
}

void text_refactor(const string& file, const string& temp, const string& from, const string& to) {
    ifstream f_stream(file);
    fstream temp_stream(temp);

    if (f_stream.is_open()) {
        int line_count;
        string line;

        while (getline(f_stream, line)&&!line.empty()) {
            if (!line.empty()) {
                size_t start_pos = 0;
                line_count = 0;
                while ((start_pos = line.find(from, start_pos)) != string::npos) {
                    line_count++;
                    line.replace(start_pos, from.length(), to);
                    start_pos += to.length();
                }
                temp_stream  << line << ", " << line_count << endl;
            }
        }
        f_stream.close();
    } else
        cout << "Opening file ("<< file <<") was failed" << endl;
}