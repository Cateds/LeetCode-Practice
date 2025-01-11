#include <stdio.h>

int main(void) {
    // char text[] = "This is a sentence that would be processed by this program.";
    char text[] = "aaaaaaabbbbcccd";
    
    int char_nums[26] = {0};
    int char_count = 0;

    for (int i=0; text[i]!='\0'; i++) {
        if (text[i]>='A' && text[i] <='Z') {
            char_nums[text[i]-'A']++;
            char_count++;
        }
        else if (text[i]>='a' && text[i]<='z') {
            char_nums[text[i]-'a']++;
            char_count++;
        }
    }
    int char_max_index[3] = {0,1,2};
    for (int i=0; i<3-1; i++) {
        for (int j=i+1; j<3; j++) {
            if (char_nums[char_max_index[i]]<char_nums[char_max_index[j]]) {
                int temp = char_max_index[i];
                char_max_index[i] = char_max_index[j];
                char_max_index[j] = temp;
            }
        }
    }
    for (int i=3; i<26; i++) {
        for (int j=2; j>=0; j--) {
            if (char_nums[i]>char_nums[char_max_index[j]]) {
                if (j!=2)
                    char_max_index[j+1] = char_max_index[j];
                char_max_index[j] = i;
            }
            else break;
        }
    }
    printf("> The Content:\n\t%s\n",text);
    printf("> Character Num:%d\n",char_count);
    printf("> Most Frequent Characters:\n\t%c\t%d\n\t%c\t%d\n\t%c\t%d\n",
            char_max_index[0]+'a', char_nums[char_max_index[0]],
            char_max_index[1]+'a', char_nums[char_max_index[1]],
            char_max_index[2]+'a', char_nums[char_max_index[2]] );
}