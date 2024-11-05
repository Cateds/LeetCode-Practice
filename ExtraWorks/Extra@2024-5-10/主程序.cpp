#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include "library_directory.h"
#include "main menu & make files.h"

int main() {
    FILE *fp_directory, *fp_information, *fp_order;                                                                                               // ׼���ļ�ָ��
    char filename_directory[] = {"book directory.txt"}, filename_information[] = {"customer information.txt"}, filename_order[] = {"orders.txt"}; // ׼���ļ���
    make_files(filename_directory, filename_information, filename_order);                                                                         // �����ļ�
    // ��׷�ӷ�ʽ�������ļ�
    fp_directory = fopen(filename_directory, "a+");
    fp_information = fopen(filename_information, "a+");
    fp_order = fopen(filename_order, "a+");
    while (1) {
        printf("\n\n\nWelcome to the Library Manager\n\n\n"); // ��ӭ����ͼ��������
        printf("Press Enter to continue==>");                 // ���»س����Լ���
        getchar();
        system("clear"); // ʹ��Windowsϵͳʹ��Ϊsystem("cls");
        int choose, judge = 1;
        do {
            main_menu();
            scanf("%d", &choose);
            if (choose != 0 && choose != 1 && choose != 2 && choose != 3 && choose != 4 && choose != 5) {
                printf("\nInvalid Number! Please enter again!");
            } else {
                judge = 0;
            }
        } while (judge == 1);

        switch (choose) {
        case 1:
            directory_main(fp_directory);
            break;
        case 2:
            // kcml_gl();
            break;
        case 3:
            // kscj_gl();
            break;
        case 0:
            fclose(fp_directory);
            fclose(fp_directory);
            fclose(fp_order);
            return 0;
        }
    }
    return 0;
}
