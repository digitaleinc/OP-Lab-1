#include "file_pointer.h"
#include "file_stream.h"

int main(int argc, char* argv[]) {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    if(argc >= 2, strcmp(argv[2], "FilePointer") == 0) {
        char file_name[LENGTH];
        char new_file[LENGTH];
        char substr[LENGTH];

        name_a_file(file_name);
        input_to_file(file_name);
        show_content_of_file(file_name);
        name_a_file(new_file);
        restruct_file_and_write_to_new(file_name,new_file,substr);
        show_content_of_file(new_file);
        count_substrings_in_file(new_file,substr);
        show_content_of_file(new_file);

    } else if(argc >= 2, strcmp(argv[2], "FileStream") == 0) {
        // Config
        string input_filename, output_filename, word, modified_word;
        string temp_filename = "temp_file.txt";

        // Input
        input_filename = get_input("Set name for input file: ");
        file_input(input_filename);
        show_file(input_filename);
        file_copy(input_filename, temp_filename);

        // Word
        word = get_input("\nPlease, write a subword: ");
        modified_word = word_change(word);

        // Text Refactor and TempFile output
        text_refactor(input_filename, temp_filename, word, modified_word);
        show_file(temp_filename);

        // Output File and Output Results
        output_filename = get_input("Set name for output file: ");
        file_copy(temp_filename, output_filename);
        show_file(output_filename);

    }
    system("pause");
    return 0;
}