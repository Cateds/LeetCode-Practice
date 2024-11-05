#include "stdio.h"

void main_menu() {
    {
        printf("      Library Manager     \n");
        printf("--------------------------\n");
        printf("|1��Directory             |\n"); // ͼ��Ŀ¼
        printf("|2��Customers' Info       |\n"); // �ͻ���Ϣ
        printf("|3��Orders                |\n"); // �ͻ�����
        printf("|0��exit                  |\n"); // �˳�
        printf("-------------------------\n");
        printf("Please enter the number to choose==>      ");
    }
}

void make_files(char filename1[], char filename2[], char filename3[]) {
    FILE *fp;

    if (access(filename1, F_OK) != 0) {
        fp = fopen(filename1, "w+");
        fprintf(fp, "Book's Name # ISBN Code # Book's Author\n");
        fclose(fp);
    }

    if (access(filename2, F_OK) != 0) {
        fp = fopen(filename2, "w+");
        fprintf(fp, "Customer's Name # Customer's City\n");
        fclose(fp);
    }

    if (access(filename3, F_OK) != 0) {
        fp = fopen(filename3, "w+");
        fprintf(fp, "Book's Name # Order's Quantity\n");
        fclose(fp);
    }
}