#include <stdio.h>
#define MAX_SIZE 50

void printStock(int stock[], int n) {
    printf("Mang hien tai: [");
    for (int i = 0; i < n; i++) {
        printf("%d", stock[i]);
        if (i < n - 1) {
            printf(", ");
        }
    }
    printf("]\n");
}

void clearInputBuffer() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}

int main() {
    int stock[MAX_SIZE] = {12, 7, 20, 5, 16};
    int n = 5;
    int choice;

    do {
        printf("------------------------------------------------------\n");
        printf(" |   CHUONG TRINH QUAN LY LUOT MUON SACH BOOKHUB    | \n");
        printf("------------------------------------------------------\n");
        printf(" | 1. Them so luot muon sach                        |\n");
        printf(" | 2. Sua so luot muon sach                         |\n");
        printf(" | 3. Xoa so luot muon sach                         |\n");
        printf(" | 4. Tim kiem so luot muon sach                    |\n");
        printf(" | 0. Thoat chuong trinh                            |\n");
        printf("-----------------------------------------------------\n");
        printf("Vui long nhap lua chon cua ban (0 - 4): ");


        if (scanf("%d", &choice) != 1) {
            printf("\n Lua chon khong hop le!\n");
            clearInputBuffer();
            continue;
        }

        switch (choice) {
            case 1: {
                int value, pos;
                printf("THEM SO LUOT MUON SACH \n");
                
                printf("Nhap gia tri can them: ");
                if (scanf("%d", &value) != 1) {
                    printf("Gia tri khong hop le!\n");
                    clearInputBuffer();
                    break;
                }

                printf("Nhap vi tri can chen: ");
                if (scanf("%d", &pos) != 1) {
                    printf("Vi tri khong hop le!\n");
                    clearInputBuffer();
                    break;
                }

                if (n >= MAX_SIZE) {
                    printf("Mang da day, khong the them!\n");
                } else if (pos < 1 || pos > n + 1) {
                    printf("Vi tri chen khong hop le!\n");
                } else {
                    for (int i = n; i >= pos; i--) {
                        stock[i] = stock[i - 1];
                    }
                    stock[pos - 1] = value;
                    n++;
                    printStock(stock, n);
                }
                break;
            }

            case 2: {
                int pos, newValue;
                printf("SUA SO LUOT MUON SACH \n");
                
                printf("Nhap vi tri can sua: ");
                if (scanf("%d", &pos) != 1) {
                    printf("Vi tri khong hop le!\n");
                    clearInputBuffer();
                    break;
                }

                printf("Nhap gia tri moi: ");
                if (scanf("%d", &newValue) != 1) {
                    printf("Gia tri khong hop le!\n");
                    clearInputBuffer();
                    break;
                }

                if (pos < 1 || pos > n) {
                    printf("Vi tri sua khong hop le!\n");
                } else if (newValue < 0) {
                    printf("So luong ton kho khong hop le!\n");
                } else {
                    stock[pos - 1] = newValue;
                    printStock(stock, n);
                }
                break;
            }

            case 3: {
                int pos;
                printf("XOA SO LUOT MUON SACH \n");

                printf("Nhap vi tri can xoa: ");
                if (scanf("%d", &pos) != 1) {
                    printf("Vi tri khong hop le!\n");
                    clearInputBuffer();
                    break;
                }

                if (n == 0) {
                    printf("Mang rong, khong the xoa!\n");
                } else if (pos < 1 || pos > n) {
                    printf("Vi tri xoa khong hop le!\n");
                } else {

                    for (int i = pos - 1; i < n - 1; i++) {
                        stock[i] = stock[i + 1];
                    }
                    n--;
                    printStock(stock, n);
                }
                break;
            }

            case 4: {
                int target;
                printf("TIM KIEM SO LUOT MUON SACH \n");

                printf("Nhap gia tri can tim : ");
                if (scanf("%d", &target) != 1) {
                    printf("Gia tri khong hop le!\n");
                    clearInputBuffer();
                    break;
                }

                int count = 0;
                int positions[MAX_SIZE];

                for (int i = 0; i < n; i++) {
                    if (stock[i] == target) {
                        positions[count++] = i + 1;
                    }
                }

                if (count == 0) {
                    printf("Khong tim thay gia tri trong mang!\n");
                } else {
                    printf("----------------------------------------\n");
                    printf("            KET QUA TIM KIEM            \n");
                    printf("----------------------------------------\n");
                    printf("Gia tri can tim : %d\n", target);
                    printf("Vi tri          : ");
                    for (int i = 0; i < count; i++) {
                        printf("%d", positions[i]);
                        if (i < count - 1) {
                            printf(", ");
                        }
                    }
                    printf("So lan xuat hien: %d\n", count);
                    printf("-----------------------------------------\n");
                }
                break;
            }

            case 0:
                printf("Cam on ban da su dung chuong trinh Quan ly luot muon sach BOOKHUB!\n");
                break;

            default:
                printf("Lua chon khong hop le!\n");
                break;
        }

    } while (choice != 0);

    return 0;
}
