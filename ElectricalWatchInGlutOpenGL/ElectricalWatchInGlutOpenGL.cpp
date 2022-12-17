#include <glut.h>
#include <windows.h>
#include <string>
#include <iostream>

int firstHours(0), secondHours(0), firstMinutes(0), secondMinutes(0), firstSeconds(0), secondSeconds(0);

void enterTime()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	system("cls");

	std::string textforWatch;
	std::string charforWatch;

	std::cout << "Введите часы \n";
	getline(std::cin, textforWatch);

	if (textforWatch.size() == 2)
	{
		charforWatch = textforWatch[0];
		secondHours = stof(charforWatch);

		charforWatch = textforWatch[1];
		firstHours = stof(charforWatch);
	}
	else
	{
		charforWatch = textforWatch[0];
		firstHours = stof(charforWatch);

		secondHours = 0;
	}


	std::cout << "Введите минуты \n";
	getline(std::cin, textforWatch);

	if (textforWatch.size() == 2)
	{
		charforWatch = textforWatch[0];
		secondMinutes = stof(charforWatch);

		charforWatch = textforWatch[1];
		firstMinutes = stof(charforWatch);
	}
	else
	{
		charforWatch = textforWatch[0];
		firstMinutes = stof(charforWatch);

		secondMinutes = 0;
	}

	std::cout << "Введите скекунды \n";
	getline(std::cin, textforWatch);

	if (textforWatch.size() == 2)
	{
		charforWatch = textforWatch[0];
		secondSeconds = stof(charforWatch);

		charforWatch = textforWatch[1];
		firstSeconds = stof(charforWatch);
	}
	else
	{
		charforWatch = textforWatch[0];
		firstSeconds = stof(charforWatch);

		secondSeconds = 0;
	}
}

void consoleWatch()
{
	//Sleep(1000);// - 1 секунда

	if (firstSeconds >= 9)
	{
		secondSeconds++;
		firstSeconds = 0;

		if (secondSeconds >= 6)
		{
			if (firstMinutes >= 9)
			{
				secondMinutes++;
				firstMinutes = 0;
				secondSeconds = 0;

				if (secondMinutes >= 6)
				{
					firstHours++;
					secondMinutes = 0;
					secondSeconds = 0;

					if (firstHours >= 9)
					{
						secondHours++;
						secondMinutes = 0;
						secondSeconds = 0;
						firstHours = 0;

					}
					else if ((secondHours == 2) and (firstHours >= 3))
					{
						secondHours = 0;
						firstHours = 0;
						secondMinutes = 0;
						secondSeconds = 0;

					}
				}
			}
			else
			{
				firstMinutes++;
				secondSeconds = 0;
			}

		}

	}
	else
	{
		firstSeconds++;
	}
	Sleep(1000);
	system("cls");
	std::cout << secondHours << firstHours << ":" << secondMinutes << firstMinutes << ":" << secondSeconds << firstSeconds;
}

void dravSpher(float x, float y, float radius, int c, int speher, int speher2)
{
	glBegin(GL_TRIANGLE_FAN);
	glColor3ub(0, 70, 0);

	glVertex2f(x, y); // center of circle
	for (speher2; speher2 <= speher; speher2++) {
		glVertex2f(
			x + (radius * cos(speher2 * 2.0 * 3.1416 / 40)),
			y + (radius * sin(speher2 * 2.0 * 3.1416 / 40))
		);
	}

	glEnd();
}

void dravQuads(float x0, float x1, float x2, float x3, float y0, float y1, float y2, float y3, int turnOnAndOf)
{
	if (turnOnAndOf == 1)
		glColor3f(0, 50, 0);
	else if (turnOnAndOf == 0)
		glColor3f(0, 0, 0);

	glBegin(GL_QUADS);
	glVertex2f(x0, y0);
	glVertex2f(x1, y1);
	glVertex2f(x2, y2); // Врхний левый
	glVertex2f(x3, y3); // Нижний левый
	glEnd();
}

void points()
{
	dravSpher(-33, 25, 4, 0, 40, 0);// Отрисовка точки слева
	dravSpher(-33, 10, 4, 0, 40, 0);// Отрисовка точки слева

	dravSpher(33, 25, 4, 0, 40, 0); // Отрисовка точки справа
	dravSpher(33, 10, 4, 0, 40, 0); // Отрисовка точки справа
}

void pattern(
	int number,
	int* turnOnLongbottom,
	int* turnOnLongMIddle,
	int* turnOnLongHight,
	int* turnOnLeftbottom,
	int* turnOnRightbottom,
	int* turnOnLeftHight,
	int* turnOnRightHight)
{
	switch (number)
	{
	case 0:
		*turnOnLongbottom = 1;
		*turnOnLongMIddle = 0;
		*turnOnLongHight = 1;
		*turnOnLeftbottom = 1;
		*turnOnRightbottom = 1;
		*turnOnLeftHight = 1;
		*turnOnRightHight = 1;
		break;

	case 1:
		*turnOnLongbottom = 0;
		*turnOnLongMIddle = 0;
		*turnOnLongHight = 0;
		*turnOnLeftbottom = 0;
		*turnOnRightbottom = 1;
		*turnOnLeftHight = 0;
		*turnOnRightHight = 1;
		break;

	case 2:
		*turnOnLongbottom = 1;
		*turnOnLongMIddle = 1;
		*turnOnLongHight = 1;
		*turnOnLeftbottom = 1;
		*turnOnRightbottom = 0;
		*turnOnLeftHight = 0;
		*turnOnRightHight = 1;
		break;

	case 3:
		*turnOnLongbottom = 1;
		*turnOnLongMIddle = 1;
		*turnOnLongHight = 1;
		*turnOnLeftbottom = 0;
		*turnOnRightbottom = 1;
		*turnOnLeftHight = 0;
		*turnOnRightHight = 1;
		break;

	case 4:
		*turnOnLongbottom = 0;
		*turnOnLongMIddle = 1;
		*turnOnLongHight = 0;
		*turnOnLeftbottom = 0;
		*turnOnRightbottom = 1;
		*turnOnLeftHight = 1;
		*turnOnRightHight = 1;
		break;

	case 5:
		*turnOnLongbottom = 1;
		*turnOnLongMIddle = 1;
		*turnOnLongHight = 1;
		*turnOnLeftbottom = 0;
		*turnOnRightbottom = 1;
		*turnOnLeftHight = 1;
		*turnOnRightHight = 0;
		break;

	case 6:
		*turnOnLongbottom = 1;
		*turnOnLongMIddle = 1;
		*turnOnLongHight = 1;
		*turnOnLeftbottom = 1;
		*turnOnRightbottom = 1;
		*turnOnLeftHight = 1;
		*turnOnRightHight = 0;
		break;

	case 7:
		*turnOnLongbottom = 0;
		*turnOnLongMIddle = 0;
		*turnOnLongHight = 1;
		*turnOnLeftbottom = 0;
		*turnOnRightbottom = 1;
		*turnOnLeftHight = 0;
		*turnOnRightHight = 1;
		break;

	case 8:
		*turnOnLongbottom = 1;
		*turnOnLongMIddle = 1;
		*turnOnLongHight = 1;
		*turnOnLeftbottom = 1;
		*turnOnRightbottom = 1;
		*turnOnLeftHight = 1;
		*turnOnRightHight = 1;
		break;

	case 9:
		*turnOnLongbottom = 1;
		*turnOnLongMIddle = 1;
		*turnOnLongHight = 1;
		*turnOnLeftbottom = 0;
		*turnOnRightbottom = 1;
		*turnOnLeftHight = 1;
		*turnOnRightHight = 1;
		break;
	}
}

void watch(void)
{
	firstSeconds = -1;
	int firstStart(0);
	int turnOnLongbottom(0), turnOnLongMIddle(0), turnOnLongHight(0), turnOnLeftbottom(0), turnOnRightbottom(0), turnOnLeftHight(0), turnOnRightHight(0);
	while (1)
	{
		points();
		consoleWatch();
		//firstSeconds
		pattern(firstSeconds, &turnOnLongbottom, &turnOnLongMIddle, &turnOnLongHight, &turnOnLeftbottom, &turnOnRightbottom, &turnOnLeftHight, &turnOnRightHight);

		dravQuads(90, 70, 70, 90, 0, 0, -5, -5, turnOnLongbottom); // Отрисовка нижней справа
		dravQuads(90, 70, 70, 90, 20, 20, 15, 15, turnOnLongMIddle); // Отрисовка нижней справа
		dravQuads(90, 70, 70, 90, 40, 40, 35, 35, turnOnLongHight); // Отрисовка нижней справа

		dravQuads(75, 70, 70, 75, 2, 2, 12, 12, turnOnLeftbottom);
		dravQuads(90, 85, 85, 90, 2, 2, 12, 12, turnOnRightbottom);

		dravQuads(75, 70, 70, 75, 22, 22, 32, 32, turnOnLeftHight);
		dravQuads(90, 85, 85, 90, 22, 22, 32, 32, turnOnRightHight);

		//secondSeconds
		pattern(secondSeconds, &turnOnLongbottom, &turnOnLongMIddle, &turnOnLongHight, &turnOnLeftbottom, &turnOnRightbottom, &turnOnLeftHight, &turnOnRightHight);

		dravQuads(60, 40, 40, 60, 0, 0, -5, -5, turnOnLongbottom); // Отрисовка нижней справаэ
		dravQuads(60, 40, 40, 60, 20, 20, 15, 15, turnOnLongMIddle);
		dravQuads(60, 40, 40, 60, 40, 40, 35, 35, turnOnLongHight); // Отрисовка нижней справа

		dravQuads(45, 40, 40, 45, 2, 2, 12, 12, turnOnLeftbottom);
		dravQuads(55, 60, 60, 55, 2, 2, 12, 12, turnOnRightbottom);

		dravQuads(45, 40, 40, 45, 22, 22, 32, 32, turnOnLeftHight);
		dravQuads(55, 60, 60, 55, 22, 22, 32, 32, turnOnRightHight);

		//firstMinute
		pattern(firstMinutes, &turnOnLongbottom, &turnOnLongMIddle, &turnOnLongHight, &turnOnLeftbottom, &turnOnRightbottom, &turnOnLeftHight, &turnOnRightHight);

		dravQuads(5, 25, 25, 5, 0, 0, -5, -5, turnOnLongbottom);
		dravQuads(5, 25, 25, 5, 20, 20, 15, 15, turnOnLongMIddle);
		dravQuads(5, 25, 25, 5, 40, 40, 35, 35, turnOnLongHight);

		dravQuads(10, 5, 5, 10, 2, 2, 12, 12, turnOnLeftbottom);
		dravQuads(25, 20, 20, 25, 2, 2, 12, 12, turnOnRightbottom);

		dravQuads(10, 5, 5, 10, 22, 22, 32, 32, turnOnLeftHight);
		dravQuads(25, 20, 20, 25, 22, 22, 32, 32, turnOnRightHight);

		//secondMinute
		pattern(secondMinutes, &turnOnLongbottom, &turnOnLongMIddle, &turnOnLongHight, &turnOnLeftbottom, &turnOnRightbottom, &turnOnLeftHight, &turnOnRightHight);

		dravQuads(-25, -5, -5, -25, 0, 0, -5, -5, turnOnLongbottom);
		dravQuads(-25, -5, -5, -25, 20, 20, 15, 15, turnOnLongMIddle);
		dravQuads(-25, -5, -5, -25, 40, 40, 35, 35, turnOnLongHight);

		dravQuads(-25, -20, -20, -25, 2, 2, 12, 12, turnOnLeftbottom);
		dravQuads(-10, -5, -5, -10, 2, 2, 12, 12, turnOnRightbottom);

		dravQuads(-25, -20, -20, -25, 22, 22, 32, 32, turnOnLeftHight);
		dravQuads(-10, -5, -5, -10, 22, 22, 32, 32, turnOnRightHight);

		//firstHours
		pattern(firstHours, &turnOnLongbottom, &turnOnLongMIddle, &turnOnLongHight, &turnOnLeftbottom, &turnOnRightbottom, &turnOnLeftHight, &turnOnRightHight);

		dravQuads(-60, -40, -40, -60, 0, 0, -5, -5, turnOnLongbottom);
		dravQuads(-60, -40, -40, -60, 20, 20, 15, 15, turnOnLongMIddle);
		dravQuads(-60, -40, -40, -60, 40, 40, 35, 35, turnOnLongHight);

		dravQuads(-55, -60, -60, -55, 2, 2, 12, 12, turnOnLeftbottom);
		dravQuads(-45, -40, -40, -45, 2, 2, 12, 12, turnOnRightbottom);

		dravQuads(-55, -60, -60, -55, 22, 22, 32, 32, turnOnLeftHight);
		dravQuads(-45, -40, -40, -45, 22, 22, 32, 32, turnOnRightHight);

		//secondHours
		pattern(secondHours, &turnOnLongbottom, &turnOnLongMIddle, &turnOnLongHight, &turnOnLeftbottom, &turnOnRightbottom, &turnOnLeftHight, &turnOnRightHight);

		dravQuads(-90, -70, -70, -90, 0, 0, -5, -5, turnOnLongbottom);
		dravQuads(-90, -70, -70, -90, 20, 20, 15, 15, turnOnLongMIddle);
		dravQuads(-90, -70, -70, -90, 40, 40, 35, 35, turnOnLongHight);

		dravQuads(-90, -85, -85, -90, 2, 2, 12, 12, turnOnLeftbottom);
		dravQuads(-75, -70, -70, -75, 2, 2, 12, 12, turnOnRightHight);

		dravQuads(-90, -85, -85, -90, 22, 22, 32, 32, turnOnLeftHight);
		dravQuads(-75, -70, -70, -75, 22, 22, 32, 32, turnOnRightHight);


		glutSwapBuffers();

		if (firstStart == 0)
		{
			enterTime();
			firstStart++;
		}
	}


}

void init(void)
{
	consoleWatch();
	glClearColor(1.0, 1.0, 1.0, 0.0);

	glLoadIdentity();
	glOrtho(-100.0, 100.0, -100.0, 100.0, -1.0, 1.0);
}

int main(int argc, char** argv)
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE);
	glutInitWindowSize(800, 800);
	glutCreateWindow("ZZZZ");
	glutDisplayFunc(watch);
	init();
	glutMainLoop();

	return 0;
}