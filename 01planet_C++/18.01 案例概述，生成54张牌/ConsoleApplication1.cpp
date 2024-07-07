/*

*/

#include <iostream>
#include <cstring>
#include <stdlib.h>
#include <time.h>
using namespace std;

struct CARD
{
	char suit[9];		// 花色
	char rank[6];			// 点数
};

// 四种花色
char suits[4][9] = { "Hearts","Spades", "Diamonds", "Clubs" };
//const char* suits[] = { "Hearts","Spades", "Diamonds", "Clubs" };

// 十三种点数
char ranks[13][5] = { "A","2","3","4","5","6","7","8","9","10","J","Q","K" };

// 生成54张牌
void createCards(CARD card[]);
// 洗牌
void shuffleCards(CARD card[]);
// 发牌
void dealCards(CARD card[]);
// 横向显示的发牌
void dealCards2(CARD card[]);

int main()
{
	CARD card[54];
	createCards(card);
	shuffleCards(card);
	dealCards2(card);
}

void createCards(CARD card[]) {
	int i = 0;
	for (; i < 52; i++) {
		strcpy_s(card[i].suit, suits[i / 13]);	// 每13张更换花色
		strcpy_s(card[i].rank, ranks[i % 13]);
	}
	// 生成大小王
	strcpy_s(card[i].suit, "Black");
	strcpy_s(card[i++].rank, "Joker");
	strcpy_s(card[i].suit, "Red");
	strcpy_s(card[i].rank, "Joker");
}

void shuffleCards(CARD card[]) {
	// 循环54次，每次随机一个 0-53 的数字来和下标 i 对应的牌交换
	int i = 0, j;
	CARD temp;
	srand(time(0));		// srand设置了种子，此后每一次rand()都有对应的固定值
	for (; i < 54; i++) {
		// srand(time(0));	// 不能写在循环里边，执行太快，以至于种子没有变化！
		j = rand() % 54;
		if (i != j) {
			temp = card[i];
			card[i] = card[j];
			card[j] = temp;
		}
	}
}

void dealCards(CARD card[]) {
	CARD player[3][17], finalCards[3];
	int p1 = 0, p2 = 0, p3 = 0;
	for (int i = 0; i < 51; i++) {
		if (i % 3 == 0) {
			player[0][p1++] = card[i];
		}
		else if (i % 3 == 1) {
			player[1][p2++] = card[i];
		}
		else {
			player[2][p3++] = card[i];
		}
	}
	for (int i = 0; i < 3; i++) {
		finalCards[i] = card[i + 51];
	}

	for (int i = 0; i < 3; i++) {
		cout << "玩家" << i + 1 << endl;
		for (int j = 0; j < 17; j++) {
			cout << player[i][j].suit << "     \t" << player[i][j].rank << endl;
		}
	}
	cout << "底牌" << endl;
	for (int i = 0; i < 3; i++) {
		cout << finalCards[i].suit << "     \t" << finalCards[i].rank << endl;
	}
}

void dealCards2(CARD card[]) {
	CARD player[3][17], finalCards[3];
	int p1 = 0, p2 = 0, p3 = 0;
	cout << "玩家1\t\t\t玩家2\t\t\t玩家3" << endl;
	for (int i = 0; i < 51; i++) {
		if (i % 3 == 0) {
			player[0][p1++] = card[i];
			cout << card[i].suit << "     \t" << card[i].rank;
		}
		else if (i % 3 == 1) {
			player[1][p2++] = card[i];
			cout << "\t" << card[i].suit << "     \t" << card[i].rank;
		}
		else {
			player[2][p3++] = card[i];
			cout << "\t" << card[i].suit << "     \t" << card[i].rank << endl;
		}
	}

	cout << "\n底牌" << endl;
	for (int i = 0; i < 3; i++) {
		finalCards[i] = card[i + 51];
		cout << finalCards[i].suit << "     \t" << finalCards[i].rank << endl;
	}
}