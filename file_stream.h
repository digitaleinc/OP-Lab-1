#include <iostream>
#include <fstream>
#include <cstring>
#include <Windows.h>

using namespace std;

string get_input(string);
void file_input(const string &);
void show_file(const string &);
void file_copy(const string &file, const string &tempfile_name);
string word_change(string);
void text_refactor(const string &, const string &, const string &, const string &);