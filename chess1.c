#include <stdio.h>
#include <stdlib.h>

char** arr1;
char arrB[8][8];
char arrW[8][8];
int M;
int N;

int ch(int x, int y) {
    int B = 0, W = 0;
    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            if (arr1[y + i][x + j] != arrB[i][j]) {
                B++;
            }
            if (arr1[y + i][x + j] != arrW[i][j]) {
                W++;
            }
        }
    }

    if (B > W) {
    return W;
    }
    else if (B == W) {
        return B;
    }
    else if (W > B) {
    return B;
    }
}

int main() {
    int min = 64; 
    char n;
    scanf("%d %d", &N, &M);

    // 메모리 할당 수정
    arr1 = (char**)malloc(sizeof(char*) * N);
    for (int i = 0; i < N; i++) {
        arr1[i] = (char*)malloc(sizeof(char) * (M + 1)); // 각 행에 문자열의 끝을 표시하는 null 문자('\0')를 저장하기 위해 크기를 M+1로 수정
    }

    for (int i = 0; i < N; i++) {
        scanf(" %s", arr1[i]); // 개행 문자 제거

        // 입력 문자열을 8x8 체스판으로 확장
        for (int j = M; j < 8; j++) {
            arr1[i][j] = ' ';
        }
    }

    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            if ((i + j) % 2 == 0) {
                arrB[i][j] = 'B';
                arrW[i][j] = 'W';
            }
            else {
                arrB[i][j] = 'W';
                arrW[i][j] = 'B';
            }
        }
    }

    for (int i = 0; i <= N - 8; i++) {
        for (int j = 0; j <= M - 8; j++) {
            int result = ch(j, i);
            if (min > result) {
                min = result;
            }
        }
    }

    printf("%d", min);

    // 메모리 해제 추가
    for (int i = 0; i < N; i++) {
        free(arr1[i]);
    }
    free(arr1);

    return 0;
}
