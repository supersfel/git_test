#include<stdio.h>
#include<stdlib.h>
char** arr1;
char arrB[8][8];
char arrW[8][8];
int M;
int N;

int ch(int x,int y) {
int B=0, W=0;
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
int* r;
int a=0;
int min=1000000;
char n;
scanf_s("%d %d", &N, &M);
arr1 = (char**)malloc(sizeof(char*) * N);
for (int i = 0; i < M; i++) {
arr1[i] = (char*)malloc(sizeof(char) * M);
}

scanf_s("%c", &n);
for (int i = 0; i < N; i++) {
for (int j = 0; j < M; j++) {
scanf_s("%c", &arr1[i][j]);
}
scanf_s("%c", &n);
}
for (int i = 0; i < 8; i++) {
for (int j = 0; j < 8; j++) {
if ((i + j) % 2 == 0) {
arrB[i][j] = 'B';
arrW[i][j] = 'W';
}
else if ((i + j) % 2 == 1) {
arrB[i][j] = 'W';
arrW[i][j] = 'B';
}
}
}
for (int i = 0; i <= N - 8; i++) {
for (int j = 0; j <= (M - 8); j++) {
if (min > ch(j, i)) {
min = ch(j, i);
}
}
}
printf("%d", min);
return 0;
}