#define _CRT_SECURE_NO_WARNINGS
#include <locale.h>
#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include <cstdio>

int main() {
	setlocale(LC_ALL, "Rus");
	int n, v;
	FILE* fp;
	fp = fopen("Text.txt", "r");
	printf("������� ���������� ���������: \n");
	scanf("%d", &n);
	n++;
	// ��������� ������ ��� ������� �������� ������
	int** pr = (int**)malloc(n * sizeof(int*));
	for (int i = 0; i < n; i++) {
		pr[i] = (int*)malloc(n * sizeof(int));
	}
	// ������ ���������� �� ����������� ����
	int* end = (int*)malloc(n * sizeof(int));
	for (int i = 0; i < n; ++i) {
		end[i] = 0;
	}
	// ���� ������
	printf("������� ����� ����� ������ (1 - ���� � ����������, 2 - ���� �� �����): \n");
	scanf("%d", &v);
	if (v == 1)
	{
		for (int i = 0; i < n; ++i) {
			if (i == n - 1) {
				pr[i][0] = 0;
				for (int i = 0; i < n; ++i) {
					for (int j = 2; j < pr[i][1] + 2; ++j) {
						for (int l = 0; l < n - 1; ++l) {
							if (l == pr[i][j] - 1)
								end[l] = 1;
						}
					}
				}
				int count = 0;
				for (int l = 0; l < n - 1; ++l) {
					if (end[l] == 0) {
						pr[i][count + 2] = l + 1;
						count++;
					}
				}
				pr[i][1] = count;
				for (int l = count + 2; l < n; ++l) {
					pr[i][l] = 0;
				}
			}
			else {
				printf("������� ����� ���������� %d-�� ��������: \n", i + 1);
				scanf("%d", &pr[i][0]);
				printf("������� ���-�� �������������� ��������� ��� %d-�� ��������: \n", i + 1);
				int m;
				scanf("%d", &m);
				pr[i][1] = m;
				if (m != 0) {
					printf("������� %d ���������: \n", m);
					for (int j = 2; j < m + 2; ++j) {
						scanf("%d", &pr[i][j]);
					}
					for (int l = m + 2; l < n; ++l) {
						pr[i][l] = 0;
					}

				}
			}
		}

	}
	else {
		for (int i = 0; i < n; ++i) {
			if (i == n - 1) {
				pr[i][0] = 0;
				for (int i = 0; i < n; ++i) {
					for (int j = 2; j < pr[i][1] + 2; ++j) {
						for (int l = 0; l < n - 1; ++l) {
							if (l == pr[i][j] - 1)
								end[l] = 1;
						}
					}
				}
				int count = 0;
				for (int l = 0; l < n - 1; ++l) {
					if (end[l] == 0) {
						pr[i][count + 2] = l + 1;
						count++;
					}
				}
				pr[i][1] = count;
				for (int l = count + 2; l < n; ++l) {
					pr[i][l] = 0;
				}
			}
			else {
				printf("������� ����� ���������� %d-�� ��������: ", i + 1);
				fscanf(fp, "%d", &pr[i][0]);
				printf("%d ", pr[i][0]);
				printf("\n");
				printf("������� ���-�� �������������� ��������� ��� %d-�� ��������: ", i + 1);
				int m;
				fscanf(fp, "%d", &m);
				printf("%d \n", m);
				pr[i][1] = m;
				if (m != 0) {
					printf("������� %d ���������: ", m);
					for (int j = 2; j < m + 2; ++j) {
						fscanf(fp, "%d", &pr[i][j]);
						printf("%d ", pr[i][j]);
					}
					for (int l = m + 2; l < n; ++l) {
						pr[i][l] = 0;
					}
					printf("\n");

				}
			}
		}
	}
	// ����� ��������� �������
	printf("id     | K(j)    \n");
	for (int i = 0; i < n; ++i) {
		if (i < 9) {
			printf("\nid = %d;  ", i + 1);
			for (int j = 0; j < pr[i][1] + 2; ++j) {
				printf("%d ", pr[i][j]);
			}

		}
		else {
			printf("\nid = %d; ", i + 1);
			for (int j = 0; j < pr[i][1] + 2; ++j) {
				printf("%d ", pr[i][j]);
			}
		}
	}
	// ��������� ������ ��� �������
	int** t = (int**)malloc(n * sizeof(int*));
	for (int i = 0; i < n; i++) {
		t[i] = (int*)malloc(5 * sizeof(int));
	}
	// ������� ��
	for (int i = 0; i < n; ++i) {
		if (pr[i][1] == 0)
			t[i][0] = 0;
		else {
			int max = 0;
			for (int j = 2; j < pr[i][1] + 2; ++j) {
				int tid = pr[i][j] - 1;
				if ((t[tid][0] + pr[tid][0]) > max)
					max = t[tid][0] + pr[tid][0];
			}
			t[i][0] = max;
		}
		// ������� ��
		t[i][1] = t[i][0] + pr[i][0];
	}
	// ������� ��
	for (int i = n - 1; i >= 0; i--) {
		if (i == n - 1)
			t[i][3] = t[i][1];
		if (i != n - 1) {
			int min = 999;
			for (int j = i + 1; j < n; ++j) {
				if (pr[j][1] > 0) {
					for (int l = 2; l < pr[j][1] + 2; ++l) {
						if ((pr[j][l] - 1 == i) && (t[j][2] < min))
							min = t[j][2];
					}
				}
			}
			t[i][3] = min;
		}
		// ������� ��
		t[i][2] = t[i][3] - pr[i][0];
		// ������� �������
		t[i][4] = t[i][3] - t[i][1];
	}
	int dl;
	// ����� �������
	printf("\n----------------------------------------------------\n");
	printf("\nid       | t��  | t��  | t��  | t��  | ������ \n");
	for (int i = 0; i < n; ++i) {
		printf("\nid = %3d; ", i + 1);
		for (int j = 0; j < 5; ++j) {
			printf("%5d ", t[i][j]);
		}
		// ����� ������������ ����
		if (t[i][4] == 0)
			dl = t[i][3];
		end[i] = 0;
	}
	// ���� ��� ������������ ����
	int i = n - 1;
	while (i >= 0) {
		if (t[i][4] == 0) {
			end[i] = 1;
			if (pr[i][1] == 0) {
				break;
			}
			for (int j = 2; j < pr[i][1] + 2; ++j) {
				if (t[pr[i][j] - 1][4] == 0) {
					i = pr[i][j] - 1;
					break;
				}
			}
		}
		else
			i--;
	}
	// ����� ����� ������������ ���� � ��� ����������� ����
	printf("\n----------------------------------------------------\n");
	printf("\n����� ������������ ���� = %d\n", dl);
	printf("����������� ����: ");
	int count = 0;
	for (int i = 0; i < n; ++i) {
		if (end[i] == 1) {
			if (count == 0)
				printf("%d ", i + 1);
			else
				printf("-> %d ", i + 1);
			count++;
		}
	}
	printf("\n----------------------------------------------------\n");
}
