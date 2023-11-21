#include <stdio.h>
// Hàm nhap giá tri cho mang
void inputArray(int arr[], int n) {
    printf("Nhap gia tri cho cac phan tu cua mang:\n");
    for (int i = 0; i < n; i++) {
        printf("arr[%d]: ", i);
        scanf("%d", &arr[i]);
    }
}
// Hàm in giá tri cua mang
void printArray(int arr[], int n) {
    printf("Gia tri cua mang:\n");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}
// Hàm tính trung binh các phan tu duong trong mang
float averagePositiveElements(int arr[], int n) {
    int count = 0;
    int sum = 0;
    for (int i = 0; i < n; i++) {
        if (arr[i] > 0) {
            count++;
            sum += arr[i];
        }
    }
    if (count == 0) {
        return 0; // Tránh chia cho 0
    }
    return (float)sum / count;
}
// Hàm in ra vi trí cua phan tu có giá tri bing k trong mang
void printPositionsOfValue(int arr[], int n, int k) {
    printf("Vi tri (chi so) cua cac phan tu co gia tri bang %d trong mang: ", k);
    for (int i = 0; i < n; i++) {
        if (arr[i] == k) {
            printf("%d ", i);
        }
    }
    printf("\n");
}
// Hàm sap xep mang giam dan bang thuat toán noi bot
void bubbleSort(int arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] < arr[j + 1]) {
                // Hoán doi giá tri 
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}
// Hàm kiem tra so nguyên to 
int isPrime(int num) {
    if (num <= 1) {
        return 0; // Không phai so nguyên to 
    }
    for (int i = 2; i * i <= num; i++) {
        if (num % i == 0) {
            return 0; // Không phai so nguyên to 
        }
    }
    return 1; // Là so nguyên to 
}
// Hàm sap xep các phan tu theo yêu cau 7 
void customSort(int arr[], int n) {
    int evenDivisibleBy3Count = 0;
    int oddDivisibleBy3Count = 0;
    // Ðem so luong phan tu chan chia het cho 3 và le chia het cho 3
    for (int i = 0; i < n; i++) {
        if (arr[i] % 2 == 0 && arr[i] % 3 == 0) {
            evenDivisibleBy3Count++;
        } else if (arr[i] % 2 != 0 && arr[i] % 3 == 0) {
            oddDivisibleBy3Count++;
        }
    }
    // Sap xep mang
    bubbleSort(arr, n);
    int sortedArr[n];
    int evenDivisibleBy3Index = 0;
    int oddDivisibleBy3Index = n - oddDivisibleBy3Count;
    // Sap xep các phan tu chan chia het cho 3 o dau mang
    for (int i = 0; i < n; i++) {
        if (arr[i] % 2 == 0 && arr[i] % 3 == 0) {
            sortedArr[evenDivisibleBy3Index++] = arr[i];
        }
    }
    // Sao chép các phan tu con lai
    for (int i = 0; i < n; i++) {
        if (arr[i] % 2 != 0 || arr[i] % 3 != 0) {
            sortedArr[oddDivisibleBy3Index++] = arr[i];
        }
    }
    // Sao chép các phan tu chan không chia het cho 3
    for (int i = 0; i < n; i++) {
        if (arr[i] % 2 == 0 && arr[i] % 3 != 0) {
            sortedArr[oddDivisibleBy3Index++] = arr[i];
        }
    }
    // Copy mang da sap xep vào mang chính
    for (int i = 0; i < n; i++) {
        arr[i] = sortedArr[i];
    }
}
// Hàm chèn giá tri m vào mang sao cho mang van giu duoc thu tu giam dan
void insertValue(int arr[], int *n, int m) {
    // Tim vi trí chèn
    int insertIndex = 0;
    while (insertIndex < *n && arr[insertIndex] > m) {
        insertIndex++;
    }
    for (int i = *n - 1; i >= insertIndex; i--) {
        arr[i + 1] = arr[i];
    }
    // Chèn giá tri m vào mang
    arr[insertIndex] = m;
    (*n)++; // Tong so phan tu cua mang
}
int main() {
    int arr[100];
    int n = 0;
    int choice;
    int primeCount = 0;
    do {
        // In menu
        printf("\n************************MENU**************************\n");
        printf("1. Nhap gia tri n phan tu cua mang\n");
        printf("2. In gia tri cac phan tu trong mang\n");
        printf("3. Tinh trung binh cac phan tu duong trong mang\n");
        printf("4. In ra vi tri cac phan tu co gia tri bang k trong mang\n");
        printf("5. Sap xep mang giam dan bang thuat toan Bubble Sort\n");
        printf("6. Tinh so luong cac phan tu la so nguyen to trong mang\n");
        printf("7. Sap xep cac phan tu theo yeu cau\n");
        printf("8. Nhap gia tri m va chen vao mang (sap xep giam dan)\n");
        printf("9. Thoat\n");
        printf("Lua chon cua ban: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                // Nhap giá tri cho mang
                printf("Nhap so phan tu cua mang: ");
                scanf("%d", &n);
                inputArray(arr, n);
                break;
            case 2:
                // In giá tri cua mang
                printArray(arr, n);
                break;
            case 3:
                // Tính trung binh các phan tu duong trong mang
                printf("Trung binh cac phan tu duong trong mang: %.2f\n", averagePositiveElements(arr, n));
                break;
            case 4:
                // In ra vi trí cua các phan tu có giá tri bang k trong mang
                int k;
                printf("Nhap gia tri k can tim kiem: ");
                scanf("%d", &k);
                printPositionsOfValue(arr, n, k);
                break;
            case 5:
                // Su dung thuat toán Bubble Sort sap xep mang giam dan
                bubbleSort(arr, n);
                printf("Mang sau khi sap xep giam dan: ");
                printArray(arr, n);
                break;
            case 6:
                // Tính so luong các phan tu là so nguyên to trong mang
                for (int i = 0; i < n; i++) {
                    if (isPrime(arr[i])) {
                        primeCount++;
                    }
                }
                printf("So luong phan tu la so nguyen to trong mang: %d\n", primeCount);
                break;
            case 7:
                // Sap xep các phan tu theo yêu cau
                customSort(arr, n);
                printf("Mang sau khi sap xep theo yeu cau: ");
                printArray(arr, n);
                break;
            case 8:
                // Nhap giá tri m và chèn vào mang (sap xep giam dan)
                int m;
                printf("Nhap gia tri m can chen (luu y phai sap xep truoc bang lenh 5): ");
                scanf("%d", &m);
                insertValue(arr, &n, m);
                printf("Mang sau khi chen gia tri %d: ", m);
                printArray(arr, n);
                break;
            case 9:
                printf("Ket thuc chuong trinh.\n");
                break;
            default:
                printf("Lua chon khong hop le. Vui long nhap lai.\n");
                break;
        }
    } while (choice != 9);
    return 0;
}

