#include "file_pointer.h"

void name_a_file(char* file) {
    fflush(stdin);
    printf("Name a file: ");
    gets(file);
    fflush(stdin);
}

void input_to_file(const char* file) {
    FILE *f_pointer;
    char input[LENGTH];

    f_pointer = fopen(file, "w");

    printf("\nPlease, write a text into file (if you want to stop, press DOUBLE ENTER): \n");

    while (gets(input)&&strcmp(input,"")!=0)
        if (strcmp(input,"")!=0)
            fprintf(f_pointer,"%s\n", input);

    printf("\n");
    fclose(f_pointer);
}

void show_content_of_file(const char* file) {
    FILE *f_pointer;
    char read[LENGTH];

    f_pointer = fopen(file, "r");

    printf("Content of file %s\n", file);
    while(!feof(f_pointer)&&fscanf(f_pointer, "%[^\n]%*c", read))
        if(!feof(f_pointer))
            printf("%s\n",read);

    printf("\n");

    fclose(f_pointer);
}

void restruct_file_and_write_to_new(const char* file, const char* new_file, char* substr) {
    void change_sentence(char* sentence, char* substr);

    FILE* f_pointer;
    FILE* new_file_pointer;
    char sentence[LENGTH] = "";

    f_pointer = fopen(file, "r");
    new_file_pointer = fopen(new_file, "w");

    cout << "Input substring: ";
    gets(substr);
    fflush(stdin);
    cout << endl;

    while (!feof(f_pointer)&&fscanf(f_pointer,"%[^\n]%*c", sentence)) {
        if (!feof(f_pointer)) {
            change_sentence(sentence, substr);
            fprintf(new_file_pointer,"%s\n", sentence);
        }
    }

    fclose(f_pointer);
    fclose(new_file_pointer);
}

void change_sentence(char* sentence, char* substr) {
    void change_word(char* word, char* substr, char* new_word);

    char new_sentence[LENGTH] = "";
    char* word;
    char new_word[LENGTH] = "";

    word = strtok(sentence, " ");
    change_word(word, substr, new_word);
    strcat(new_sentence, new_word);
    strcat(new_sentence, " ");
    while (word!=nullptr) {
        word = strtok(nullptr, " ");
        if (word!=nullptr) {
            change_word(word, substr, new_word);
            strcat(new_sentence, new_word);
            strcat(new_sentence, " ");
        }
    }

    strcpy(sentence, new_sentence);
}

void change_word(char* word, char* substr, char* new_word) {
    strcpy(new_word,"");

    char* pos = strstr(word, substr);
    while (pos != NULL) {
        strncat(new_word, word, pos-word);
        strcat(new_word, "(");
        strncat(new_word, pos, 2);
        strcat(new_word, ")");
        if (pos != NULL) {
            word = pos+2;
            pos = strstr(word, substr);
        }
    }
    strcat(new_word, word);
}

void count_substrings_in_file(const char* file, char* substr) {
    void count_substrings_in_str(char* str, char* sub);

    char sentence[LENGTH];
    const char tmp_file[] = "tmpfile.txt";
    FILE* f_in;
    FILE* f_out;

    f_in = fopen(file, "r");
    f_out = fopen(tmp_file, "w");

    while (!feof(f_in)&&fscanf(f_in, "%[^\n]%*c", sentence)) {
        if (!feof(f_in)) {
            count_substrings_in_str(sentence, substr);
            fprintf(f_out, "%s\n",sentence);
        }
    }

    fclose(f_in);
    fclose(f_out);

    remove(file);
    rename(tmp_file,file);
}

void count_substrings_in_str(char* str, char* sub) {
    char new_sentence[LENGTH];
    char quantity[LENGTH];

    char* pos = strstr(str, sub);
    int count = 0;

    while (pos != nullptr) {
        count++;
        pos = strstr(pos + 1, sub);
    }

    itoa(count,quantity,15);

    strcpy(new_sentence, str);
    strcat(new_sentence, ", ");
    strcat(new_sentence, quantity);

    strcpy(str, new_sentence);
}