#include <iostream>
#include <cstring>
#include <cstdio>
#include <ctime>
#include <Windows.h>
using namespace std;
char map[20][20],ch;
int scoremap[20][20],order;
int a, b, a1, b1, a2, b2;
                              //判断输赢
bool winorlose(int x, int y,char t) {
	int count;
	count = 1;                         //竖直方向
	for (int i = x, j = y + 1; i >= 0 && j >= 0 && i < 20 && j < 20 && j <= y + 5; j++) {
		if (map[i][j] == t) count++;
		else break;
	}
	for (int i = x, j = y - 1; i >= 0 && j >= 0 && i < 20 && j < 20 && j >= y - 5; j--) {
		if (map[i][j] == t) count++;
		else break;
	}
	if (count >= 6) return true;
	count = 1;                    //水平方向
	for (int i = x + 1, j = y; i >= 0 && j >= 0 && i < 20 && j < 20 && i <= x + 5; i++) {
		if (map[i][j] == t) count++;
		else break;
	}
	for (int i = x - 1, j = y; i >= 0 && j >= 0 && i < 20 && j < 20 && i >= x - 5; i--) {
		if (map[i][j] == t) count++;
		else break;
	}
	if (count >= 6) return true;
	count = 1;          //从左下斜向右上
	for (int i = x + 1, j = y + 1; i >= 0 && j >= 0 && i < 20 && j < 20 && i <= x + 5 && j <= y + 5; i++, j++) {
		if (map[i][j] == t) count++;
		else break;
	}
	for (int i = x - 1, j = y - 1; i >= 0 && j >= 0 && i < 20 && j < 20 && i >= x - 5 && j >= y - 5; i--, j--) {
		if (map[i][j] == t) count++;
		else break;
	}
	if (count >= 6) return true;
	count = 1;    //左上斜向右下
	for (int i = x - 1, j = y + 1; i >= 0 && j >= 0 && i < 20 && j < 20 && i >= x - 5 && j <= y + 5; i--, j++) {
		if (map[i][j] == t) count++;
		else break;
	}
	for (int i = x + 1, j = y - 1; i >= 0 && j >= 0 && i < 20 && j < 20 && i <= x + 5 && j >= y - 5; i++, j--) {
		if (map[i][j] == t) count++;
		else break;
	}
	if (count >= 6) return true;
	return false;
} 
                          //判断合法性
bool legal(int x, int y) {
	if (x > 19 || x < 0 || y>19 || y < 0 || map[x][y] != '*')
		return false;
	else return true;
}
                   //判断是否悔棋， 输入-1和20时悔棋
bool huiqi(int x, int y) {
	if (x == -1 && y == 20)
		return true;
	else return false;
} 
                  //判断是否和棋
bool heqi( ) {
	for (int i = 0; i < 20; i++) {
		for (int j = 0; j < 20; j++) {
			if (map[i][j] == '*') return false;
		}
	}
	return true;
}
                 //判断是否禁手
bool jinshou(int x, int y, char t, char s) {     //t为自己棋子，s为敌方棋子
	int num4 = 0, num5 = 0, i, j;
	int count;
	char temp1, temp2;
	count = 1;          //竖直方向判断禁手
	for (i = x, j = y + 1; i >= 0 && j >= 0 && i < 20 && j < 20 && j <= y + 4; j++) {
		if (map[i][j] == t) count++;
		else break;
	}
	temp1 = map[i][j];
	for (i = x, j = y - 1; i >= 0 && j >= 0 && i < 20 && j < 20 && j >= y - 4; j--) {
		if (map[i][j] == t) count++;
		else break;
	}
	temp2 = map[i][j];
	if (count == 4) {
		num4++;
		if (temp1 == s && temp2 == s) num4--;
	}
	if (count == 5) {
		num5++;
		if (temp1 == s && temp2 == s) num5--;
	}
	count = 1;          //水平方向判断禁手
	for (i = x + 1, j = y; i >= 0 && j >= 0 && i < 20 && j < 20 && i <= x + 4; i++) {
		if (map[i][j] == t) count++;
		else break;
	}
	temp1 = map[i][j];
	for (i = x - 1, j = y; i >= 0 && j >= 0 && i < 20 && j < 20 && i >= x - 4; i--) {
		if (map[i][j] == t) count++;
		else break;
	}
	temp2 = map[i][j];
	if (count == 4) {
		num4++;
		if (temp1 == s && temp2 == s) num4--;
	}
	if (count == 5) {
		num5++;
		if (temp1 == s && temp2 == s) num5--;
	}
	count = 1;    //从左下斜向右上
	for (i = x + 1, j = y + 1; i >= 0 && j >= 0 && i < 20 && j < 20 && i <= x + 4 && j <= y + 4; i++, j++) {
		if (map[i][j] == t) count++;
		else break;
	}
	temp1 = map[i][j];
	for (i = x - 1, j = y - 1; i >= 0 && j >= 0 && i < 20 && j < 20 && i >= x - 4 && j >= y - 4; i--, j--) {
		if (map[i][j] == t) count++;
		else break;
	}
	temp2 = map[i][j];
	if (count == 4) {
		num4++;
		if (temp1 == s && temp2 == s) num4--;
	}
	if (count == 5) {
		num5++;
		if (temp1 == s && temp2 == s) num5--;
	}
	count = 1;    //左上斜向右下
	for (i = x - 1, j = y + 1; i >= 0 && j >= 0 && i < 20 && j < 20 && i >= x - 4 && j <= y + 4; i--, j++) {
		if (map[i][j] == t) count++;
		else break;
	}
	temp1 = map[i][j];
	for (i = x + 1, j = y - 1; i >= 0 && j >= 0 && i < 20 && j < 20 && i <= x + 4 && j >= y - 4; i++, j--) {
		if (map[i][j] == t) count++;
		else break;
	}
	temp2 = map[i][j];
	if (count == 4) {
		num4++;
		if (temp1 == s && temp2 == s) num4--;
	}
	if (count == 5) {
		num5++;
		if (temp1 == s && temp2 == s) num5--;
	}
	if (num4 >= 2) return true;
	else if (num5 >= 2) return true;
	else return false;
}
                  //地图初始化
void initializemap() {
	for (int i = 0; i < 20; i++)                 
		for (int j = 0; j < 20; j++)
			map[i][j] = '*';
}
                   //进入游戏的界面
void gamestart() {
		cout << "开始游玩" << endl;
		cout << "请选择游戏模式" << endl;
		cout << "1.人人对战" << endl;
		cout << "2.人机对战" << endl;
		cout << "3.机机对战" << endl;
		cout << "4.Quit" << endl;
}
                  //玩家落子，B为黑棋，W为白棋
void playchess(int x, int y, int player) {
	if (player == 1) map[x][y] = 'B';
	else map[x][y] = 'W';
}
                   //打印棋盘
void printmap() {
	cout << "     0  1  2  3  4  5  6  7  8  9 10 11 12 13 14 15 16 17 18 19" << endl;
	for (int i = 0; i < 20; i++) {
		if (i < 10) cout << "  " << i;
		else cout << " " << i;
		for (int j = 0; j < 20; j++)
			cout << "  " << map[i][j];
		cout << endl;
	}
}
        //AI所走每一步的得分分数图
void AIgetscore(char ch) {    //ch为敌方棋子的种类
	int oppnum = 0, AInum = 0,blanknum= 0;
	char dh;
	if (ch == 'B') dh = 'W';
	else if (ch == 'W') dh = 'B';
	for (int i = 0; i < 20; i++)             //对AI得分地图初始化
		for (int j = 0; j < 20; j++)
			scoremap[i][j] = 0;
	for (int i = 0; i < 20; i++) {       //计算得分
		for (int j = 0; j < 20; j++) {
			if (i >= 0 && j >= 0 && i <= 19 && j <= 19 && map[i][j] == '*') {  //保证此处可以下棋
				for(int k=-1;k<=1;k++)
					for (int z = -1; z <= 1; z++) {   //寻遍周围八个方向的棋子
						oppnum = 0; AInum = 0; blanknum = 0;  //先将每个方向的各种棋子数量记为零
						if (!(k == 0 && z == 0)) {  //k z为0时不为八个方向之一
						 //根据对手落子情况评定分数:
							for (int s = 1; s <= 5; s++) {   //此方向查询五颗棋子
								if (i + k * s >= 0 && i + k * s <= 19 &&    //查询此方向满足条件的敌方棋子个数
									j + z * s >= 0 && j + z * s <= 19 &&
									map[i + k * s][j + z * s] == ch) oppnum++;   //计算此方向满足条件的敌方棋子个数
								else if (i + k * s >= 0 && i + k * s <= 19 &&  //查询此方向满足条件的暂无棋子位置
									j + z * s >= 0 && j + z * s <= 19 &&
									map[i + k * s][j + z * s] == '*') {
									blanknum++;  //此方向无棋子位置加一
									break;   //跳出循环
								}
								else break;   //检测到自己的棋子或者达到边界则退出循环
							}
							for (int s = 1; s <= 5; s++) {   //此方向的反方向查询五颗棋子
								if (i - k * s >= 0 && i - k * s <= 19 &&    //查询此方向反方向满足条件的敌方棋子个数
									j - z * s >= 0 && j - z * s <= 19 &&
									map[i - k * s][j - z * s] == ch) oppnum++;   //计算此方向反方向满足条件的敌方棋子个数
								else if (i - k * s >= 0 && i - k * s <= 19 &&  //查询此方向反方向满足条件的暂无棋子位置
									j - z * s >= 0 && j - z * s <= 19 &&
									map[i - k * s][j - z * s] == '*') {
									blanknum++;  //此方向反方向无棋子位置加一
									break;   //跳出循环
								}
								else break;   //检测到自己的棋子或者到达边界则退出循环
							}
							if (oppnum == 1) scoremap[i][j] += 10;   //抵挡敌方棋子一颗时分数+10
							else if (oppnum == 2) {
								if (blanknum == 1) scoremap[i][j] += 20;  //抵挡敌方眠2时分数+20
								else scoremap[i][j] += 25;        //抵挡敌方活2时分数+25
							}
							else if (oppnum == 3) {
								if (blanknum == 1) scoremap[i][j] += 30;
								else scoremap[i][j] += 35;
							}
							else if (oppnum == 4) {
								if (blanknum == 1) scoremap[i][j] += 40;
								else scoremap[i][j] += 45;
							}
							else if (oppnum == 5) scoremap[i][j] += 100;
							blanknum = 0;
						//根据自己落子情况评定分数：
							for (int s = 1; s <= 5; s++) {   //此方向查询五颗棋子
								if (i + k * s >= 0 && i + k * s <= 19 &&    //查询此方向满足条件的我方棋子个数
									j + z * s >= 0 && j + z * s <= 19 &&
									map[i + k * s][j + z * s] == dh) AInum++;   //计算此方向满足条件的我方棋子个数
								else if (i + k * s >= 0 && i + k * s <= 19 &&  //查询此方向满足条件的暂无棋子位置
									j + z * s >= 0 && j + z * s <= 19 &&
									map[i + k * s][j + z * s] == '*') {
									blanknum++;  //此方向无棋子位置加一
									break;   //跳出循环
								}
								else break;   //检测到敌方的棋子或者达到边界则退出循环
							}
							for (int s = 1; s <= 5; s++) {   //此方向的反方向查询五颗棋子
								if (i - k * s >= 0 && i - k * s <= 19 &&    //查询此方向反方向满足条件的我方棋子个数
									j - z * s >= 0 && j - z * s <= 19 &&
									map[i - k * s][j - z * s] == dh) AInum++;   //计算此方向反方向满足条件的我方棋子个数
								else if (i - k * s >= 0 && i - k * s <= 19 &&  //查询此方向反方向满足条件的暂无棋子位置
									j - z * s >= 0 && j - z * s <= 19 &&
									map[i - k * s][j - z * s] == '*') {
									blanknum++;  //此方向反方向无棋子位置加一
									break;   //跳出循环
								}
								else break;   //检测到敌方的棋子或者到达边界则退出循环
							}
							if (AInum == 1) scoremap[i][j] += 10;   //
							else if (AInum == 2) {
								if (blanknum == 1) scoremap[i][j] += 20;  //
								else scoremap[i][j] += 25;        //
							}
							else if (AInum == 3) {
								if (blanknum == 1) scoremap[i][j] += 30;
								else scoremap[i][j] += 35;
							}
							else if (AInum == 4) {
								if (blanknum == 1) scoremap[i][j] += 40;
								else scoremap[i][j] += 45;
							}
							else if (AInum >= 5) scoremap[i][j] += 100;
							blanknum = 0;
						}
					}
			}
		}
	}
}
               //AI下棋（有禁手规则）
void AIplayyou() {
	AIgetscore(ch);
	char dh;
	if (ch == 'B') dh = 'W';
	else dh = 'B';
	int maxscore = 0;
	for (int i = 0; i < 20; i++)
		for (int j = 0; j < 20; j++)
			if (scoremap[i][j] > maxscore) maxscore = scoremap[i][j];     //得到最大分数值
	int num = 0;             //最大值个数
	int p[400], q[400];            //存放可放最大值位置的数组
	for (int i = 0; i < 20; i++)
		for (int j = 0; j < 20; j++)
			if (scoremap[i][j] == maxscore) {
				if (!jinshou(i, j, dh, ch)) {
					p[num] = i;
					q[num] = j;
					num++;
				}
			}
	int n;
	srand((unsigned)time(0));
	n = rand() % num;	                 //n为0到num-1的随机数，随机取一个最大数值
	if (ch == 'B') map[p[n]][q[n]] = 'W';
	else map[p[n]][q[n]] = 'B';
	a2 = p[n];
	b2 = q[n];
	a = p[n];
	b = q[n];
	Sleep(2000);
	printmap();
}
           //AI下棋（无禁手规则）
void AIplaywu() {
	AIgetscore(ch);
	int maxscore = 0;
	for (int i = 0; i < 20; i++)
		for (int j = 0; j < 20; j++)
			if (scoremap[i][j] > maxscore) maxscore = scoremap[i][j];     //得到最大分数值
	int num = 0;             //最大值个数
	int p[400], q[400];            //存放最大值位置的数组
	for (int i = 0; i < 20; i++)
		for (int j = 0; j < 20; j++)
			if (scoremap[i][j] == maxscore) {
				p[num] = i;
				q[num] = j;
				num++;
			}
	int n;
	srand((unsigned)time(0));
	n = rand() % num;	                 //n为0到num-1的随机数，随机取一个最大数值
	if (ch == 'B') map[p[n]][q[n]] = 'W';
	else map[p[n]][q[n]] = 'B';
	a2 = p[n];
	b2 = q[n];
	a = p[n];
	b = q[n];
	Sleep(2000);
	printmap();
}
//AI1下棋（有禁手规则）
void AI1play() {
	AIgetscore(ch);
	char dh;
	if (ch == 'B') dh = 'W';
	else dh = 'B';
	int maxscore = 0;
	for (int i = 0; i < 20; i++)
		for (int j = 0; j < 20; j++)
			if (scoremap[i][j] > maxscore) maxscore = scoremap[i][j];     //得到最大分数值
	int num = 0;             //最大值个数
	int p[400], q[400];            //存放可放最大值位置的数组
	for (int i = 0; i < 20; i++)
		for (int j = 0; j < 20; j++)
			if (scoremap[i][j] == maxscore) {
				if (!jinshou(i, j, dh, ch)) {
					p[num] = i;
					q[num] = j;
					num++;
				}
			}
	int n;
	srand((unsigned)time(0));
	n = rand() % num;	                 //n为0到num-1的随机数，随机取一个最大数值
	if (ch == 'B') map[p[n]][q[n]] = 'W';
	else map[p[n]][q[n]] = 'B';
	a = p[n];
	b = q[n];
	Sleep(2000);
	printmap();
}
//AI2下棋（无禁手规则）
void AI2play() {
	AIgetscore(ch);
	int maxscore = 0;
	for (int i = 0; i < 20; i++)
		for (int j = 0; j < 20; j++)
			if (scoremap[i][j] > maxscore) maxscore = scoremap[i][j];     //得到最大分数值
	int num = 0;             //最大值个数
	int p[400], q[400];            //存放最大值位置的数组
	for (int i = 0; i < 20; i++)
		for (int j = 0; j < 20; j++)
			if (scoremap[i][j] == maxscore) {
				p[num] = i;
				q[num] = j;
				num++;
			}
	int n;
	srand((unsigned)time(0));
	n = rand() % num;	                 //n为0到num-1的随机数，随机取一个最大数值
	if (ch == 'B') map[p[n]][q[n]] = 'W';
	else map[p[n]][q[n]] = 'B';
	a = p[n];
	b = q[n];
	Sleep(2000);
	printmap();
}
   //人人对战模式
void gamemodeone() {
	int count = 1;
	bool flag1 = true, flag2 = true;
	while (1) {
		cout << "第" << count++ << "回合：" << endl<< "玩家1请下棋:" << endl;
		cin >> a>> b;
		if (huiqi(a, b) && flag1 && (count > 2)) {
			flag1 = false;
			map[a1][b1] = '*';
			map[a2][b2] = '*';
			printmap();
			cout << "玩家1悔棋成功，请重新输入：" << endl;
			cin >> a >> b;
			while (!legal(a, b)) {
				cout << "此步棋不合法，请重新输入：" << endl;
				cin >> a >> b;
			}
			a1= a; b1 = b;
		}
		else {
			while (!legal(a, b)) {
				cout << "此步棋不合法，请重新输入：" << endl;
				cin >> a >> b;
			}
			a1 = a; b1 = b;
		}
		playchess(a, b, 1);
		printmap();
		if (jinshou(a, b, 'B', 'W')) {
			cout << "玩家2胜利" << endl << "Game Over!" << endl;
			initializemap();                            //地图初始化
			break;
		}
		if (winorlose(a, b,'B')) {
			cout << "玩家1胜利" << endl<<"Game Over!" << endl;
			initializemap();                            //地图初始化
			break;
		}
		cout << "玩家2请下棋：" << endl;
		cin >> a >> b;
		if (huiqi(a, b)&&flag2&&(count>2)) {
			flag2 = false;
			map[a1][b1] = '*';
			map[a2][b2] = '*';
			printmap();
			cout << "玩家2悔棋成功，请重新输入：" << endl;
			cin >> a >> b;
			while (!legal(a, b)) {
				cout << "此步棋不合法，请重新输入：" << endl;
				cin >> a >> b;
			}
			a2 = a; b2 = b;
		}
		else {
			while (!legal(a, b)) {
				cout << "此步棋不合法，请重新输入：" << endl;
				cin >> a >> b;
			}
			a2 =a; b2 = b;
		}
		playchess(a, b, 2);
		printmap();
		if (winorlose(a, b,'W')) {
			cout << "玩家2胜利" << endl << "Game Over!" << endl;
			initializemap();                            //地图初始化
			break;
		}
		if (heqi()) {
			cout << "和棋" << endl;
			initializemap();                            //地图初始化
			break;
		}
	}
}
     //人机对战模式
void gamemodetwo() {
	int count,c;
	bool flag = true;
	cout << "1.先手" << endl << "2.后手" << endl;
	cin >> c;
	if (c == 1) {
		count = 1;
		while (1) {
			cout << "第" << count++ << "回合：" << endl << "玩家请下棋:" << endl;
			cin >> a >> b;
			if (huiqi(a, b) && flag && (count > 2)) {
				flag = false;
				map[a1][b1] = '*';
				map[a2][b2] = '*';
				printmap();
				cout << "玩家悔棋成功，请重新输入：" << endl;
				cin >> a >> b;
				while (!legal(a, b)) {
					cout << "此步棋不合法，请重新输入：" << endl;
					cin >> a >> b;
				}
				a1 = a; b1 = b;
			}
			else {
				while (!legal(a, b)) {
					cout << "此步棋不合法，请重新输入：" << endl;
					cin >> a >> b;
				}
				a1 = a; b1 = b;
			}
			playchess(a, b, 1);
			ch = 'B';
			printmap();
			if (jinshou(a, b, 'B', 'W')) {
				cout << "电脑胜利" << endl << "Game Over!" << endl;
				initializemap();                            //地图初始化
				break;
			}
			if (winorlose(a, b,'B')) {
				cout << "玩家胜利" << endl << "Game Over!" << endl;
				initializemap();                            //地图初始化
				break;
			}
			cout << "电脑下棋：" << endl;
			AIplaywu();
			if (winorlose(a, b,'W')) {
				cout << "电脑胜利" << endl << "Game Over!" << endl;
				initializemap();                            //地图初始化
				break;
			}
			if (heqi()) {
				cout << "和棋" << endl;
				initializemap();                            //地图初始化
				break;
			}
		}
	}
	if (c == 2) {
		count = 1;
		while (1) {
			cout << "第" << count++ << "回合：" << endl << "电脑下棋:" << endl;
			ch = 'W';
			AIplayyou();
			if (winorlose(a, b,'B')) {
				cout << "电脑胜利" << endl << "Game Over!" << endl;
				initializemap();                            //地图初始化
				break;
			}
			cout << "玩家请下棋：" << endl;
			cin >> a >> b;
			if (huiqi(a, b) && flag && (count > 2)) {
				flag = false;
				map[a1][b1] = '*';
				map[a2][b2] = '*';
				printmap();
				cout << "玩家悔棋成功，请重新输入：" << endl;
				cin >> a >> b;
				while (!legal(a, b)) {
					cout << "此步棋不合法，请重新输入：" << endl;
					cin >> a >> b;
				}
				a1 = a; b1 = b;
			}
			else {
				while (!legal(a, b)) {
					cout << "此步棋不合法，请重新输入：" << endl;
					cin >> a >> b;
				}
				a1 = a; b1 = b;
			}
			playchess(a, b, 2);
			printmap();
			if (winorlose(a, b,'W')) {
				cout << "玩家胜利" << endl << "Game Over!" << endl;
				initializemap();                            //地图初始化
				break;
			}
			if (heqi()) {
				cout << "和棋" << endl;
				initializemap();                            //地图初始化
				break;
			}
		}
	}
}
        //机机对战模式
void gamemodethree() {
	int count = 1;
	while (1) {
		cout << "第" << count++ << "回合:" << endl << "电脑1下棋：" << endl;
		ch = 'W';
		AI1play();
		if (winorlose(a, b,'B')) {
			cout << "电脑1胜利" << endl << "Game Over!" << endl;
			initializemap();                            //地图初始化
			break;
		}
		cout << "电脑2下棋：" << endl;
		ch = 'B';
		AI2play();
		if (winorlose(a, b,'W')) {
			cout << "电脑2胜利" << endl << "Game Over!" << endl;
			initializemap();                            //地图初始化
			break;
		}
		if (heqi()) {
			cout << "和棋" << endl;
			initializemap();                            //地图初始化
			break;
		}
	}
}
int main() {
	initializemap();                            //地图初始化
	gamestart();                                //进入游戏
	while (cin >> order) {
		if (order == 1) gamemodeone();
		if (order == 2) gamemodetwo();
		if (order == 3) gamemodethree();
		if (order == 4) {
			cout << "感谢您的参与，请再接再厉提高竞技水平！" << endl;
				break;
		}
		return 0;
	}
}