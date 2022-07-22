#include <graphics.h>
#include <conio.h>

#define GRAPH_WIDTH 1280		// �������
#define GRAPH_HEIGHT 800		// �����߶�
#define UNIT_PIXEL 10			// ��Ԫ����

// �����ߵĽṹ�壨�ࣩ
struct Snake {
	int x, y, right, bottom, length, width, toward;
};

// ��ʼ���߲���
void initsnake(Snake* s, int x, int y, int length, int width, int toward = 1) {
	s->x = x;
	s->y = y;
	s->right = x + length * UNIT_PIXEL;
	s->bottom = y + width * UNIT_PIXEL;
	s->length = length;
	s->width = width;
}

void movesnake(Snake* s, int frame = 10) {
	int index = 0;
	while (true) {
		if (index == frame) {
			s->x += UNIT_PIXEL;
			index = 0;
		}
		else
			index++;
	}
}

void get_key_code() {
	char in = '0';
	while (in = _getch())
		outtext(in);
}

int main() {
	initgraph(GRAPH_WIDTH, GRAPH_HEIGHT);		// ������ͼ����
	Snake* s = (Snake *)malloc(sizeof(Snake));		// ʵ������
	initsnake(s, 200, 200, 3, 1, 1);				// ��ʼ���ߵĲ���
	fillrectangle(s->x, s->y, s->right, s->bottom);
	//movesnake(s);
	get_key_code();
	return 0;
}