#include "stdio.h"
#include "windows.h"
#include "string.h"

typedef struct book {
    char name[20];
    int isbn;
    char author[20];
} book;

void add_book_info(FILE *fp1);
int check(FILE *fp1, char *temp_for_check);

void directory_menu() // 图书目录
{
    printf("      Books Directory       \n");
    printf("----------------------------\n");
    printf("|1、Add Books' Info         |\n"); // 添加图书信息
    printf("|2、Show All Info           |\n"); // 显示图书信息
    printf("|3、Look Up Info            |\n"); // 查询图书信息
    printf("|4、Delete Info             |\n"); // 删除图书信息
    printf("|5、Revise Info             |\n"); // 修改图书信息
    printf("|0、exit                    |\n"); // 退出
    printf("----------------------------\n");
    printf("请输入相应的序号选择==>      ");
}

int directory_main(FILE *fp1) // 主菜单函数
{
    while (1) // 无限循环
    {
        // system("clear"); // 使用Windows系统使改为system("cls");
        int choose, judge = 1;
        do {
            directory_menu();
            scanf("%d", &choose);
            if (choose != 0 && choose != 1 && choose != 2 && choose != 3 && choose != 4 && choose != 5) {
                printf("\nInvalid Number! Please enter again!");
            } else {
                judge = 0;
            }
        } while (judge == 1);

        switch (choose) {
        case 1:
            add_book_info(fp1);
            break;
        case 2:
            // kcml_gl();
            break;
        case 3:
            // kscj_gl();
            break;
        case 4:
            // zhyy_gl();
            break;
        case 0:
            return 0;
        }
    }
}

void    add_book_info(FILE *fp) {
    int count = 0, judge = 0;
    book booktemp;
    char *temp_for_check = booktemp.name;
    do {
        printf("\nPlease enter the book's information");
        printf("\nBook's Name # ISBN Code # Book's Author");
        do {
            printf("\nPlease enter the book's name: ");
            fflush(stdin);
            scanf("%[^\n]", booktemp.name);
        } while (check(fp, temp_for_check) == 1);
        printf("\nPlease enter the ISBN code: ");
        fflush(stdin);
        scanf("%d", &booktemp.isbn);
        printf("\nPlease enter the author's name: ");
        fflush(stdin);
        scanf("%[^\n]", booktemp.author);
        fprintf(fp, "%s # %d # %s\n", booktemp.name, booktemp.isbn, booktemp.author);
        count = count + 1;
        printf("\nYou have entered %d datas. Do you want to continue?(0 for continue/1 for stop)", count);
        fflush(stdin);
        scanf("%d", &judge);
    } while (judge == 0);
    printf("Information input successfully!");
}

// int check(FILE *fp, char *temp_for_check) {
//     int i, find = 0, records;
//     char buf[21]; //= {0};
//     char check_temp[20];
//     fseek(fp, 0, SEEK_SET); // 指针到文件的记开始
//     while (fgets(buf, sizeof(buf), fp) != NULL && find == 0) {
//         for (i = 0; buf[i] != '#'; i++) {
//             check_temp[i] = buf[i];
//         }
//         check_temp[i] = '\0';
//         if (strcmp(check_temp, temp_for_check) == 0) { // 找到
//             find = 1;
//             printf("The book has already in the document! Enter again!");
//         }
//     }
//     return find;
// }

int check(FILE *fp, char *temp_for_check) {
    int find = 0;
    char buf[21];
    fseek(fp, 0, SEEK_SET); // 指针到文件的记开始
    while(!feof(fp) && fgetc(fp)!='\n') continue;
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