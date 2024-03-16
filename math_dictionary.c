//
//  main.c
//  vocabulary_app_ENG_POL_and_POL_ENG
//
//  Created by Karol Czołpiński on 14/07/2022.
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// language selection and invitation
void language_selection(char *language);
void print_invite_message_eng(void);
void print_invite_message_pl(void);

// the program finctionality for ENG or PL users
void program_workflow_eng(void);
void program_workflow_pl(void);

// the program workflow functions
void scan_the_input_term_eng(char *term, char *mode);
void scan_the_input_term_pl(char *term, char *mode);
void print_the_input_term_translation_and_description(char *term, char *mode, char *translation);
void ask_the_user_about_input_next_term_eng(void);
void ask_the_user_about_input_next_term_pl(void);

// closing messages
void print_closing_message_en(void);
void print_closing_message_pl(void);

void language_selection(char *language)
{
    system("clear");
    printf("To select language type (ENG or PL)...\n");
    printf("Aby wpisać język wpisz (ENG lub PL): ");
    scanf("%s", language);
    fflush(stdin);
    
    while (1)
    {
        if (strcmp(language, "ENG") == 0
        || strcmp(language, "eng") == 0
        || strcmp(language, "PL") == 0
        || strcmp(language, "pl") == 0)
            break;
        else
        {
            printf("Innorrectly inputted language / niepoprawnie wprowadzony język...\n");
            printf("Try again / spróbuj jeszcze raz: ");
            scanf("%s", language);
            fflush(stdin);
        }
    }
}

void print_invite_message_eng(void)
{
    system("clear");
    printf("Hello! :) Welcome to our English-Polish and Polish-English vocabulary app!\n");
    printf("The program contain both directions of translation\n\n");
    printf("Press ENTER to begin...");
    
    fgetc(stdin);
    fflush(stdin);
}

void print_invite_message_pl(void)
{
    system("clear");
    printf("Hej! :) Witamy w naszym Angielsko-Polskim i Polsko-Angielskim słowniku appce!\n");
    printf("Program zawiera oba kierunki tłumaczenia\n\n");
    printf("Wciśnij enter aby rozpocząć...");
    
    fgetc(stdin);
    fflush(stdin);
}

void program_workflow_eng(void)
{
    char term[50]; // to store the input string
    char mode[3];  // to store the translated term language
    char translation[50]; // to store the translation of the input word
    
    scan_the_input_term_eng(term, mode);
    print_the_input_term_translation_and_description(term, mode, translation);
    ask_the_user_about_input_next_term_eng();
}

void program_workflow_pl(void)
{
    char term[50]; // to store the input string
    char mode[3];  // to store the translated term language
    char translation[50]; // to store the translation of the input word
    
    scan_the_input_term_pl(term, mode);
    print_the_input_term_translation_and_description(term, mode, translation);
    ask_the_user_about_input_next_term_pl();
}

void scan_the_input_term_eng(char *term, char *mode)
{
    system("clear");
    printf("Please enter the translated term language (ENG or PL): ");
    scanf("%s", mode);
    fflush(stdin);
    
    printf("Please enter the term, which you want to translate: ");
    
    fgets(term, 49, stdin);//scanf("%s", term);
    fflush(stdin);
}

void scan_the_input_term_pl(char *term, char *mode)
{
    system("clear");
    printf("Proszę wprowadź język tłumaczonego zwrotu (ENG lub PL): ");
    scanf("%s", mode);
    fflush(stdin);
    
    printf("Proszę wprowadź wyrażenie, które chcesz przetłumaczyć: ");
    
    fgets(term, 49, stdin);//scanf("%s", term);
    fflush(stdin);
}

void print_the_input_term_translation_and_description(char *term, char *mode, char *translation)
{
    // char description[250];                   // to store the description of translated term
    char read[50];                           // to store the current searched word in a file
    
    FILE* fp;
    
    if ((strcmp("ENG", mode)) == 0
        || strcmp("eng", mode) == 0)
    {
        fp = fopen("ENG-PL.txt", "r");
        fseek(fp, 0, SEEK_SET);
        
//        if (fp != NULL)
//            printf("File opened successfully!\n");
        
        while (!(feof(fp)))
        {
            fgets(read, 49, fp);//fscanf(fp, "%s", read);
            read[strlen(read)-1] = '\0';
            fflush(stdin);
            
            if (strcmp(term, read) == 0)
            {
                printf("\n%s - ", term); // the coursor is set behind the translated term
                fgets(read, 49, fp);//fscanf(fp, "%s", read);  // scan the next word in the file
                fflush(stdin);
                strcpy(translation, read);
                puts(translation);//printf("%s\n\n", translation);
            }
        }
        fclose(fp);
    }
    else if ((strcmp("PL", mode)) == 0
             || strcmp("pl", mode) == 0)
    {
        fp = fopen("PL-ENG.txt", "r");
        fseek(fp, 0, SEEK_SET);
        
//        if (fp != NULL)
//            printf("File opened successfully!\n");
        
        while (!(feof(fp)))
        {
            fscanf(fp, "%s", read);
            fflush(stdin);
            
            if (strcmp(term, read) == 0)
            {
                printf("\n%s - ", term); // the coursor is set behind the translated term
                fscanf(fp, "%s", read);  // scan the next word in the file
                fflush(stdin);
                strcpy(translation, read);
                printf("%s\n\n", translation);
            }
        }
        fclose(fp);
    }
    
    // the program will search through the file, which contains all that data.
    // In this function we have to implement finding the word,
    // than this function will get the translation (and description),
    // and then it will put according 'translation' (and 'description') strings into proper arrays of characters
}

void ask_the_user_about_input_next_term_eng(void)
{
    char decision[4];
    
    printf("Would you like to check another term?\n");
    printf("Please type YES to continue (or NO to close the program): ");
    scanf("%s", decision);
    fflush(stdin);
    
    if (strcmp("YES", decision) == 0
        || strcmp("yes", decision) == 0)
        program_workflow_eng();
    else if (strcmp("NO", decision) == 0
            || strcmp("no", decision) == 0)
        print_closing_message_en();
    else
        while (strcmp("YES", decision) != 0
                || strcmp("yes", decision) != 0
                || strcmp("NO", decision) != 0
                || strcmp("no", decision) != 0)
        {
            printf("Invalid input, please enter your answer again: ");
            scanf("%s", decision);
            fflush(stdin);
        }
}

void ask_the_user_about_input_next_term_pl(void)
{
    char decision[4];
    
    printf("Czy chciałbyć sprawdzić inne wyrażenie?\n");
    printf("Proszę wpisz TAK aby kontynuować (lub NIE aby zamknąć program): ");
    scanf("%s", decision);
    fflush(stdin);

    if (strcmp("TAK", decision) == 0
        || strcmp("tak", decision) == 0)
        program_workflow_pl();
    else if (strcmp("NIE", decision) == 0
            || strcmp("nie", decision) == 0)
            print_closing_message_pl();
    else
        while (strcmp("TAK", decision) != 0
                || strcmp("tak", decision) != 0
                || strcmp("NIE", decision) != 0
                || strcmp("nie", decision) != 0)
        {
            printf("Niepoprawnie wprowadzone dane, wprowadź odpowiedź ponownie: ");
            scanf("%s", decision);
            fflush(stdin);
        }
}

void print_closing_message_en(void)
{
    system("clear");
    printf("You have entered NO, the program is ending it's work.\n");
    printf("Thank you for using our program! :)\n\n");
}

void print_closing_message_pl(void)
{
    system("clear");
    printf("Nacisnąłeś NIE, program kończy swoją pracę.\n");
    printf("Dziękujemy za skorzystanie z naszego programu! :)\n\n");
}

int main(void)
{
    char language [4];
    language_selection(language);
    
    if (strcmp("ENG", language) == 0
        || strcmp("eng", language) == 0)
    {
        print_invite_message_eng();
        program_workflow_eng();
    }
    else // if (strcmp(language, "ENG") == 0)
    {
        print_invite_message_pl();
        program_workflow_pl();
    }
    
    return 0;
}

// consider implementing new words input by the user

// (?) to have polish and english words in just one file
// we can use the approach of checking english words from the beginning of the file
// and in case of scanning the words in Polish the 'check' would be done from
// the end of the file
// ...
// they could be stored just in normal order, but it might probably slow down the program work,
// but I'm not that sure how much it would slow down the program work
