typedef struct order {
    char name[20];
    char quantity[10];
} order;

void add_order_info(FILE *fp);
int check_order(FILE *fp, char *temp_for_check);
void show_order_info(FILE *fp);
void look_up_order_info(FILE *fp);
int linenumber_order(FILE *fp);
void delete_order_info(FILE *fp);
void revise_order_info(FILE *fp);

void order_menu() // 图书目录
{
    printf("\n          Orders          \n");
    printf("----------------------------\n");
    printf("|1. Add Orders' Info     |\n");    // 添加图书信息
    printf("|2. Show All Info           |\n"); // 显示图书信息
    printf("|3. Look Up Info            |\n"); // 查询图书信息
    printf("|4. Delete Info             |\n"); // 删除图书信息
    printf("|5. Revise Info             |\n"); // 修改图书信息
    printf("|0. exit                    |\n"); // 退出
    printf("----------------------------\n");
    printf("Please enter the number to choose==>      \n");
}

int order_main(FILE *fp1) // 主菜单函数
{
    while (1) // 无限循环
    {
        system("clear"); // 使用Windows系统使改为system("cls");
        int choose, judge = 1;
        do {
            order_menu();
            scanf("%d", &choose);
            if (choose != 0 && choose != 1 && choose != 2 && choose != 3 && choose != 4 && choose != 5) {
                printf("\nInvalid Number! Please enter again!");
            } else {
                judge = 0;
            }
        } while (judge == 1);

        switch (choose) {
        case 1:
            add_order_info(fp1);
            break;
        case 2:
            show_order_info(fp1);
            break;
        case 3:
            look_up_order_info(fp1);
            break;
        case 4:
            delete_order_info(fp1);
            break;
        case 5:
            revise_order_info(fp1);
            break;
        case 0:
            return 0;
        }
    }
}

void add_order_info(FILE *fp) {
    int count = 0, judge = 0;
    order ordertemp;
    char *temp_for_check = ordertemp.name;
    system("clear");
    do {
        printf("\nPlease enter the order's information");
        printf("\nBook's Name # Order's Quantity");
        do {
            printf("\nPlease enter the book's name: ");
            fflush(stdin);
            scanf("%[^\n]", ordertemp.name);
        } while (check_order(fp, temp_for_check) == 1);
        printf("\nPlease enter the quantity: ");
        fflush(stdin);
        scanf("%[^\n]", ordertemp.quantity);
        fprintf(fp, "%s # %s\n", ordertemp.name, ordertemp.quantity);
        count = count + 1;
        printf("\nYou have entered %d datas. Do you want to continue?(0 for continue/1 for stop)", count);
        fflush(stdin);
        scanf("%d", &judge);
    } while (judge == 0);
    printf("Information input successfully!");
}

int check_order(FILE *fp, char *temp_for_check) {
    int find = 0;
    char buf[21];
    fseek(fp, 0, SEEK_SET); // 指针到文件的记开始
    while (!feof(fp) && fgetc(fp) != '\n')
        continue; // 忽略标题行
    while (!feof(fp) && fscanf(fp, "%s #", buf)) {
        if (!strcmp(temp_for_check, buf)) {
            find = 1;
            printf("The order has already in the document! Enter again!");
            break;
        }
        while (!feof(fp) && fgetc(fp) != '\n')
            continue; // 忽略该行后面的内容
    }
    return find;
}

void show_order_info(FILE *fp) {
    char str[100];
    fseek(fp, 0, SEEK_SET); // 指针到文件的记开始
    while (fgets(str, 100, fp) != NULL) {
        printf("%s", str);
        if (feof(fp)) {
            break;
        }
    }
    printf("Press Enter to continue==>"); // 按下回车键以继续
    getchar();
    getchar();
    return;
}

void look_up_order_info(FILE *fp) {
    system("clear");
    int judge = 0;
    do {
        char input_name[21], buf[21];
        printf("Please enter the book's name you want to look up: ");
        fflush(stdin);
        scanf("%[^\n]", input_name);
        strcat(input_name, " "); // 与文件匹配，保证后面有一个空格
        int count = 1;
        fseek(fp, 0, SEEK_SET); // 指针到文件的记开始
        while (!feof(fp) && fgetc(fp) != '\n')
            continue;
        while (!feof(fp) && fscanf(fp, "%[^#]", buf)) {
            if (!strcmp(input_name, buf)) {
                printf("\nThe order has been found!");
                break;
            }
            while (!feof(fp) && fgetc(fp) != '\n')
                continue;
            count = count + 1;
        }
        int a = linenumber_order(fp);
        if (count == a + 2) {
            printf("\nThe order doesn't exist!");
        } else {
            fseek(fp, 0, SEEK_SET); // 指针到文件的记开始
            while (!feof(fp) && fgetc(fp) != '\n')
                continue;
            int i, j;
            char get[100] = {0};
            for (i = 1; i <= count; i++) {
                fflush(fp);
                fgets(get, 100, fp);
            }

            order show;
            for (i = 0; get[i] != '#'; i++) {
                show.name[i] = get[i];
            }
            for (j = 0; get[j + i + 2] != '0'; j++) {
                show.quantity[j] = get[j + i + 2];
            }
            printf("\nThe book's name is %s. The order's quantity is: %s.", show.name, show.quantity);
        }
        printf("\nDo you want to continue?(0 for continue/1 for stop)");
        fflush(stdin);
        scanf("%d", &judge);
    } while (judge == 0);
    return;
}

int linenumber_order(FILE *fp) {
    char str[100];
    int linenumber = 0;
    fseek(fp, 0, SEEK_SET); // 指针到文件的记开始
    while (!feof(fp) && fgetc(fp) != '\n')
        continue;
    while (fgets(str, 100, fp) != NULL) {
        linenumber = linenumber + 1;
        if (feof(fp)) {
            break;
        }
    }
    return linenumber;
}

void delete_order_info(FILE *fp) {
    system("clear");
    char delete_order[21], judge[21] = {"exit\0"};
    printf("\nPlease enter the name of the book you want to delete: (Enter 'exit' to exit)");
    fflush(stdin);
    scanf("%[^\n]", delete_order);
    if (strcmp(delete_order, judge) == 0) {
        return;
    } else {
        FILE *fp_temp;
        fp_temp = fopen("order_temp.txt", "w");
        char copy[100], buf[21];
        int success = 0, i;
        fseek(fp, 0, SEEK_SET);
        while (fgets(copy, 100, fp) != NULL && !feof(fp)) {
            for (i = 0; copy[i] != '#'; i++) {
                buf[i] = copy[i];
            }
            buf[i - 1] = '\0';
            if (strcmp(delete_order, buf) == 0) {
                printf("\nThe order has been found and it will be deleted!");
                success = success + 1;
            } else {
                fprintf(fp_temp, "%s", copy);
            }
        }
        fclose(fp);
        remove("orders.txt");
        rename("order_temp.txt", "orders.txt");
        fp = fopen("orders.txt", "a+");
        if (success == 0) {
            printf("\nThe order hasn't been found.");
        }
        printf("\nPress enter to continue==> ");
        fflush(stdin);
        getchar();
    }
    return;
}

void revise_order_info(FILE *fp) {
    system("clear");
    char revise_order[21], judge[21] = {"exit\0"};
    printf("\nPlease enter the name of the book you want to revise: (Enter 'exit' to exit)");
    fflush(stdin);
    scanf("%[^\n]", revise_order);
    if (strcmp(revise_order, judge) == 0) {
        return;
    } else {
        FILE *fp_temp;
        fp_temp = fopen("order_temp.txt", "w");
        char copy[100], buf[21];
        int success = 0, i;
        fseek(fp, 0, SEEK_SET);
        while (fgets(copy, 100, fp) != NULL && !feof(fp)) {
            for (i = 0; copy[i] != '#'; i++) {
                buf[i] = copy[i];
            }
            buf[i - 1] = '\0';
            if (strcmp(revise_order, buf) == 0) {
                printf("\nThe order has been found!");
                printf("\nThe oringinal information is: %s", copy);
                order new_info;
                char *temp_for_check = new_info.name;
                printf("\nPlease enter the order's new information");
                printf("\nBook's Name # Order's Quantity");
                printf("\nPlease enter the book's name: ");
                fflush(stdin);
                scanf("%[^\n]", new_info.name);
                printf("\nPlease enter the order's quantity: ");
                fflush(stdin);
                scanf("%[^\n]", new_info.quantity);
                fprintf(fp_temp, "%s # %s\n", new_info.name, new_info.quantity);
                printf("Information revised successfully!");
                success = success + 1;
            } else {
                fprintf(fp_temp, "%s", copy);
            }
        }
        fclose(fp);
        remove("orders.txt");
        rename("order_temp.txt", "orders.txt");
        fp = fopen("orders.txt", "a+");
        if (success == 0) {
            printf("\nThe order hasn't been found.");
        }
        printf("\nPress enter to continue==> ");
        fflush(stdin);
        getchar();
    }
    return;
}