#include <stdio.h>
#include <stdbool.h>
#include <string.h>

int main () {
    char fullname[100];
    char mssv[100];
    char chu_cai_so2[2] = {0}; // initialize chu_cai_dau to null character
    char chu_cai_dau[2] = {0};
    char last_name[100] = {0};

    printf("Nhap ten cua ban: ");
    fgets(fullname, sizeof(fullname), stdin);
    printf("Nhap ma so sinh vien cua ban: ");
    scanf("%s", &mssv);

    //lay ten
    int start_index = 0;
    for (int i = strlen(fullname); i >= 0; i--) {
        if (fullname[i] == ' ') {
            start_index = i + 1;
            break;
        }
    }
    strncpy(last_name, fullname + start_index, strlen(fullname) - start_index - 1);

    //lay chu cai dau cua ho
    chu_cai_dau[0] = fullname[0];

    //lay chu cai dau ten dem
    for (int i = 0; i < strlen(fullname); i++) {
        if(fullname[i] == ' ') {
            if (i < strlen(fullname) - 1) {
                chu_cai_so2[0] = fullname[i+1]; 
            }
            break; 
        }
    }
    strcat(chu_cai_dau, chu_cai_so2);
    strcat(last_name, chu_cai_dau);
    printf("Email FPT cua ban la: ");
    printf("%s%s@fpt.edu.vn", last_name, mssv);
}