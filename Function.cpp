/**
̰���߹��ܺ���ʵ��
���ߣ�luye@nankai.edu.cn
ʱ�䣺2018��3��5��
*/
#pragma once
#include"Function.h"

Snake *head, *food;//ȫ��ָ�룬head����Զָ���һ���ڵ��ָ�룬food��ָ��ʳ���ָ��
Snake *q;//�������������õ���ָ��
int condition;//����������������Ѱ�����������ֱ�������ֵ��������������Ҳ��int ����
int end_condition = 0;//��ʾ�����������=1��ײǽ��=2��ҧ���Լ���=3���Լ�����;4 ײ���ϰ������
int score = 0, add = 1;//�÷ֺ�ÿ��ʳ��ķ���
Obstacle o[30];//����һ������ϰ���Ľṹ�������������ÿһ���ϰ����x��y����

inline void Green_color()//�����õ�һ��SetConsoleTextAttribute����API���ÿ���̨������ɫ���Եĺ���������;������
{                               // ������ɫΪ��ɫ
	HANDLE hOut;
	hOut = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hOut,
		FOREGROUND_GREEN |//������ɫ
		FOREGROUND_INTENSITY);//�������ø�������
}

inline void Red_color()//������ɫΪ��ɫ
{
	HANDLE hOut;
	hOut = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hOut,
		FOREGROUND_RED |
		FOREGROUND_INTENSITY);//intensity����������������ɫ����
}

inline void Yellow_color()//������ɫΪ��ɫ
{
	HANDLE hOut;
	hOut = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hOut,
		FOREGROUND_RED |
		FOREGROUND_GREEN |
		FOREGROUND_INTENSITY);
}

inline void White_color(){
	HANDLE hOut;
	hOut = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hOut,
		FOREGROUND_RED |
		FOREGROUND_GREEN |
		FOREGROUND_BLUE |
		FOREGROUND_INTENSITY);
}

void Set_location(int x, int y)//��λ�����������Ƕ�λ���������λ�÷����ӡ����Ҫ�Ķ���
{
	COORD cd;
	HANDLE hOut;
	cd.X = x;
	cd.Y = y;
	hOut = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleCursorPosition(hOut, cd);//��λ����
}
void Creat_obs(Obstacle o[], int n)//�����ϰ���,һ�������ϰ�������ڲ������ѭ��
{
	int a = 14, b = 24, c = 8, d = 40, e = 32, f = 10;//��Щ���������Լ��漴��ѡ�ģ��ǿ��Ը����ģ�ֻҪ��������ͼ��Χ
	for (int i = 0; i < 6; i++)
	{
		o[i].x = a;
		a += 2;//�����+2����Ϊ���ڴ�ӡ"��"������ռ����������ռһ��
		o[i].y = c;
	}
	a = 15; b = 24; c = 8; d = 40; e = 32; f = 10;
	for (int i = 6; i < 15; i++)
	{
		o[i].x = b;
		o[i].y = c++;
	}
	a = 15; b = 23; c = 8; d = 40; e = 10; f = 17;
	for (int i = 15; i < 20; i++)
	{
		o[i].x = e;
		e += 2;
		o[i].y = f;
		f++;
	}
	a = 15; b = 23; c = 8; d = 40; e = 32; f = 13;
	for (int i = 20; i < 26; i++)
	{
		o[i].x = d;
		o[i].y = f;
		f++;
	}
	a = 15; b = 23; c = 8; d = 40; e = 44; f = 4;
	for (int i = 26; i < 30; i++)
	{
		o[i].x = e;
		e -= 2;
		o[i].y = f;
	}
	a = 15; b = 23; c = 8; d = 40; e = 32; f = 10;
	for (int i = 0; i < 30; i++)//���������õ��ϰ����ӡ����ͼ��
	{
		Set_location(o[i].x, o[i].y);
		cout << "��";
	}
}


void Initial()//��ʼ���ߣ���һ��ʼ���Ľ�
{
	Snake *tail;
	int i;
	tail = new Snake;
	head = tail;
	head->s_x = 24;//����ͷ����x��y������ֵ
	head->s_y = 5;//���������ֵ�����Լ����ģ����Ը��ģ��Ӷ��ﵽ��������ʼλ�õ�Ŀ�ģ����ǲ��ܳ�Խ��ͼ��Χ�Ĵ�С
	head->next = NULL;
	for (i = 1; i <= 4; i++)//�����ĸ��ռ�����ĸ��ߵ�����
	{
		head = new Snake;
		head->next = tail;
		head->s_x = 24 + 2 * i;
		head->s_y = 5;
		tail = head;
	}
	while (tail->next != NULL)//��ͷ��β���������
	{
		Set_location(tail->s_x, tail->s_y);
		Green_color();
		cout << "��";
		tail = tail->next;
	}
}
void creat_food()//�������ʳ��ĺ���
{
	Snake *food_1;//���������ʳ��������food_1ָ��ģ��ȴ�����ʳ��֮���ٸ�ֵ��ȫ��foodָ��
	srand((unsigned)time(NULL));//��srandһ�����ӣ�����rand������������ģ�ͬѧ�ǿ��Բ�һ�������������������Լ�Ϊʲô��α���
	food_1 = new Snake;
	while ((food_1->s_x % 2) != 0)    //��֤��Ϊż����ʹ��ʳ��������ͷ����,����Ϊż������Ϊ����������ռ2��λ�ã�����ռ1��λ��
	{
		food_1->s_x = (rand() % 52) + 2;//%52��ʾ��0��51�ĺ����귶Χ�����
	}
	food_1->s_y = (rand() % 24) + 1;//ͬ��
	q = head;//q�Ƕ����һ��ȫ��ָ�룬����������������
	while (q->next != NULL)
	{
		if (q->s_x == food_1->s_x && q->s_y == food_1->s_y) //�ж������Ƿ���ʳ���غ�
		{
			delete food_1;//������������ʳ��ʹ��ڵ��ߵ������غϾ�Ҫɾ�����ʳ�����´���һ��ʳ��
			creat_food();
		}
		q = q->next;
	}
	for (int i = 0; i < 30; i++)
	{
		if (o[i].x == food_1->s_x && o[i].y == food_1->s_y)
		{
			delete food_1;//���ʳ��͵�ͼ�е��ϰ����غϣ���Ҫɾ��ʳ�����´���ʳ��
			creat_food();
		}
	}
	Set_location(food_1->s_x, food_1->s_y);//����ʳ��ɹ���Ҫ��ʳ���ӡ����
	food = food_1;
	Red_color();//��ʳ���ɺ�ɫ
	cout << "��";//���ʳ��
}
void creatMap()//������ͼ
{
	int i;
	for (i = 0; i<58; i += 2)//��ӡ���±߿�,����������ͬʱ��ӡ
	{
		Set_location(i, 0);
		cout << "��";
		Set_location(i, 26);
		cout << "��";
	}
	Set_location(10, 0);//��ӡ����Խ��
	cout << " ";
	Set_location(50, 26);
	cout << " ";
	for (i = 1; i<26; i++)//��ӡ���ұ߿�����ͬʱ��ӡ
	{
		Set_location(0, i);
		cout << "��";
		Set_location(56, i);
		cout << "��";
	}
	Set_location(0, 20);
	cout << " ";
	Set_location(56, 6);
	cout << " ";
	Creat_obs(o, 30);
}

void pause()//��ͣ�����������¿ո񣬱�ʾҪ��ͣ��Ϸ
{
	while (1)
	{
		Sleep(300);//��ʱ������1000��ʾ��ʱ1s����������ʱ0.3s
		if (GetAsyncKeyState(VK_SPACE))//VK��ʾ���̰�����Ϊ����_����ʾ����һ�������������ж��ǿո񰴼�
			break;                   //�����ж����������SPACE ��Ҫ��ֹ��Ϸ  async�첽�ģ�ͬ���첽�ĸ���ͬѧ�ǻ��ڴ��ʱѧ����
	}
}
void Start()//��ʼ��Ϸ
{
	system("mode con cols=100 lines=30");//�������п�Ĵ�С��������Լ������
	//White_color();
	int i;
	for (i = 33; i<60; i += 2)//��ӡ���±߿�,����������ͬʱ��ӡ������ͬʱ��ӡ
	{
		Set_location(i, 10);
		cout << "��";
		Set_location(i, 14);
		cout << "��";
	}
	for (i = 10; i<15; i++)//��ӡ���ұ߿�
	{
		Set_location(33, i);
		cout << "��";
		Set_location(61, i);
		cout << "��";
	}
	Set_location(40, 12);
	cout << "̰����@_@С��Ϸ" << endl;
	system("pause");//�ǻ���ͣ���ڵ�ǰ
	system("cls");//����
	Set_location(30, 12);
	cout << "�á�.��.��.���ֱ�����ߵ��ƶ�" << endl;
	Set_location(30, 13);
	cout << "��Ϸ����ʱ�������̰���߿��Դ�Խͼ���ϰ��ﲻ����ײ��"<<endl;
	system("pause");
	system("cls");
	creatMap();
	Initial();
	creat_food();
}
void Playing()//������Ϸ��
{
	Set_location(64, 15);
	Yellow_color();
	cout << "���ܴ�ǽ������ҧ���Լ�" << endl;
	Set_location(64, 16);
	Yellow_color();
	cout << "�á�.��.��.���ֱ�����ߵ��ƶ�" << endl;
	Set_location(64, 17);
	Yellow_color();
	cout << "̰���߿��Դ�Խ������ϰ��ﲻ����ײ��"<<endl;
	Set_location(64, 18);
	Yellow_color();
	cout << "ESC ���˳���Ϸ.space����ͣ��Ϸ" << endl;
	while (1)//
	{
		Set_location(64, 10);
		Yellow_color();
		cout << "Score=" << score;
		Set_location(64, 11);
		Yellow_color();
		cout << "ÿ��ʳ��  " << add << " ��";
		if (GetAsyncKeyState(VK_UP) && condition != DOWN)//�жϰ���״̬����
			condition = UP;
		else if (GetAsyncKeyState(VK_DOWN) && condition != UP)
			condition = DOWN;
		else if (GetAsyncKeyState(VK_LEFT) && condition != RIGHT)
			condition = LEFT;
		else if (GetAsyncKeyState(VK_RIGHT) && condition != LEFT)
			condition = RIGHT;
		else if (GetAsyncKeyState(VK_SPACE))
			pause();
		else if (GetAsyncKeyState(VK_ESCAPE))
		{
			end_condition = 3;
			break;
		}
		Sleep(200);
		head->Move();
	}
}

void Die()//��Ϸ����
{
	system("cls");
	Set_location(30, 12);
	if (end_condition == 1)//��ͬ����ᵼ����Ϸ����ʱ��ʵ�����ֲ�ͬ
	{
		Yellow_color();
		cout << "ײǽ��������������";
	}
	else if (end_condition == 2)
	{
		Yellow_color();
		cout << "��Ȼҧ���Լ���������";
	}

	else if (end_condition == 3)
	{
		Yellow_color();
		cout << "���Լ���������Ϸ������";
	}
	else if (end_condition == 4)
	{
		Yellow_color();
		cout << "��ײ�����ϰ��������";
	}
	Set_location(30, 13);
	Yellow_color();
	cout << "�÷֣�" << score << endl;
	system("pause");
    exit(0);
    //Start();
}