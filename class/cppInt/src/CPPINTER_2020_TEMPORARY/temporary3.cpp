void draw_line(int x1, int y1, int x2, int y2)
{
	
}

int main()
{
	// #1. 변수를 생성해서 함수 인자로 사용
	int x1 = 0,  y1 = 0;
	int x2 = 30, y2 = 30;

	draw_line(x1, y1, x2, y2);


	// #2. literal 을 인자로 사용
	draw_line(0, 0, 30, 30);
}