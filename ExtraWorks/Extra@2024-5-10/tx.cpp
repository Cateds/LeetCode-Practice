#include "stdio.h"
#include "string.h"

int check(FILE *fp, char *temp_for_check) {
    // int i;
    int find = 0;
    char buf[21]; //= {0};
    // char check_temp[20];
    fseek(fp, 0, SEEK_SET); // 指针到文件的记开始
    // while (fgets(buf, sizeof(buf), fp) != NULL && find == 0) {
    //     for (i = 0; buf[i] != '#'; i++) {
    //         check_temp[i] = buf[i];
    //     }
    //     check_temp[i] = '\0';
    //     if (strcmp(check_temp, temp_for_check) == 0) { // 找到
    //         find = 1;
    //         printf("The book has already in the document! Enter again!");
    //     }
    // }
    while (!feof(fp) && fscanf(fp,"%s #",buf)) {
        if (!strcmp(temp_for_check,buf)) {
            find = 1;
            printf("The book has already in the document! Enter again!");
            break;
        }
        while (!feof(fp) && fgetc(fp)!='\n') continue;
    }
    return find;
}