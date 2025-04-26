#define _CRT_SECURE_NO_WARNINGS
#define _CRT_SECURE_NO_DEPRECATE
#pragma warning(disable : 4996)

// ²ìïîðò ïîòð³áíèõ á³áë³îòåê òà ôàéë³â

#include "Results.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

// Ôóíêö³ÿ äëÿ âèêëèêó ìåíþ
void menu()
{
    printf("====================================================\n");
    printf("||                  Course Work                   ||\n");
    printf("||                                                ||\n");
    printf("||    The study of the effectiveness of different ||\n");
    printf("||        methods for sorting algorithms on       ||\n");
    printf("||             multidimensional arrays            ||\n");
    printf("||                                                ||\n");
    printf("||  Variant:                                      ||\n");
    printf("||  Made by: Pryimak Yulianna                     ||\n");
    printf("||  Group:                                        ||\n");
    printf("||                                                ||\n");
    printf("||        Press any button to continue...         ||\n");
    printf("====================================================\n");
    getch();
    system("cls");
    int mode;
    while (1)
    {
        // Ìîæëèâ³ñòü âèáîðó ðåæèìó ðîáîòè ïðîãðàìè:
        // äåìîíñòðàö³¿ ñîðòóâàííÿ àáî ÷àñó.

        printf("\nChoose the mode:\n");
        printf("\n1) Sorting\n");
        printf("\n2) Time of sorting\n");
        printf("\nPress '0' to exit...\n");
        scanf(" %d", &mode);

        // Ïåðåìèêà÷ ðåæèì³â

        switch (mode)
        {
        case(1):

            // Ìîæëèâ³ñòü âèáîðó ðåæèìó ðîáîòè ïðîãðàìè:
            // âèá³ð ìåòîäó ñîðòóâàííÿ àáî ñîðòóâàííÿ âåêòîðó.

            system("cls");
            printf("\nChoose mode:\n");
            printf("\n1. Select4Exchange | 1 method (#21 | 1)\n");
            printf("\n2. Select4Exchange | 2 method (#21 | 2)\n");
            printf("\n3. Select4Exchange | 3 method (#21 | 3)\n");
            printf("\n4. Select4Exchange | Vector (#21 | vector)\n");
            printf("\nPress '0' to exit...\n\n");
            scanf(" %d", &mode);

            // Ïåðåìèêà÷ ðåæèì³â

            switch (mode)
            {
            case(1):
                Sorting(1, 1);
                break;
            case(2):
                Sorting(2, 1);
                break;
            case(3):
                Sorting(3, 1);
                break;
            case(4):
                Sorting(1, 2);
                break;
            case(0):
                exit(1);
            default:
                printf("Incorrect value!");
            }
            break;
        case(2):

            // Ìîæëèâ³ñòü âèáîðó ðåæèìó ðîáîòè ïðîãðàìè:
            // âèá³ð ìåòîäó ñîðòóâàííÿ, âèâ³ä òàáëèö³ ç óñ³ìè ðåçóëüòàòàìè ÷àñó
            // àáî ñîðòóâàííÿ âåêòîðó.

            system("cls");
            printf("\nChoose the mode:\n");
            printf("\n1. Select4Exchange | 1 method (#21 | 1)\n");
            printf("\n2. Select4Exchange | 2 method (#21 | 2)\n");
            printf("\n3. Select4Exchange | 3 method (#21 | 3)\n");
            printf("\n4. All methods time for array \n");
            printf("\n5. Select4Exchange | Vector (#21 | vector)\n");
            printf("\nPress '0' to exit...\n\n");
            scanf(" %d", &mode);

            // Ïåðåìèêà÷ ðåæèì³â

            switch (mode)
            {
            case(1):
                S_Time(1, 1);
                break;
            case(2):
                S_Time(2, 1);
                break;
            case(3):
                S_Time(3, 1);
                break;
            case(4):
                S_Time(4, 1);
                break;
            case(5):
                S_Time(1, 2);
                break;
            case(0):
                exit(1);
            default:
                printf("Incorrect value!");
            }
            break;
        case(0):
            exit(1);
        default:
            printf("Incorrect value!");
        }
        printf("\n\n\n Press any key to continue...");
        getch();
        system("cls");
    }
}

void main()
{
    // Âèêëèê ôóíêö³¿

    menu();
}
