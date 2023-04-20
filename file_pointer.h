#include <iostream>
#include <cstring>
#include <Windows.h>
#define LENGTH 256

using namespace std;

void name_a_file(char* file);
void input_to_file(const char* file);
void show_content_of_file(const char* file);
void restruct_file_and_write_to_new(const char* file, const char* new_file, char* substr);
void count_substrings_in_file(const char* file, char* substr);
