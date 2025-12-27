#include <stdio.h>
int main() {
    const char *months[] = {
        "January", "February", "March", "April", "May", "June",
        "July", "August", "September", "October", "November", "December"
    };
    int n;
    printf("请输入月份值 (1-12): ");
    scanf("%d", &n);
    printf("%s\n", (n >= 1 && n <= 12) ? *(months + n - 1) : "Illegal month");
    return 0;
}