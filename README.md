# Клеточные Автоматы

## Начальное меню
![image](https://user-images.githubusercontent.com/52111046/140954448-9d1647b4-acad-4b0a-96e7-6c3f995c0346.png)

## B3/S23 (Игра жизнь)
Двумерный клеточный автомат основаный на следующих правилах:

-В пустой клетке, рядом с которой ровно три живые клетки, зарождается жизнь.

-Если у живой клетки есть две или три живые соседки, то эта клетка продолжает жить в противном случае, если соседей меньше двух или больше трёх, клетка умирает.

```C++
void Game::checkRules_1()
{
	
	for (int y = 0; y < Game_h; y++) {
		for (int x = 0; x < Game_w; x++) {

			int cellsCount = this->GetCellsCount(x, y);

			if (OldGeneration[x][y] == false) {

				if (cellsCount == 3) {

					Generation[x][y] = true;

				}
			}
			else {

				if ((cellsCount < 2) || (cellsCount > 3)) {

					Generation[x][y] = false;

				}
			}
		}
	}
	
}
```

(Функция GetCellsCount(x, y) возвращяет количество живых клеток вокруг проверяемой клетки).

![ezgif com-gif-maker](https://user-images.githubusercontent.com/52111046/142083479-c6acc23b-900f-47c5-9567-6f0c46b1137f.gif)

## B1/S12345678
Двумерный клеточный автомат основаный на следующих правилах:
-В пустой клетке, рядом с которой есть хотя бы одна живая клетка зарождается жизнь.
-Клетка продолжает жить не зависимо от количества соседей.

![image](https://user-images.githubusercontent.com/52111046/142526475-a68efc0c-6c66-4a8e-b2e3-41a3dface0f6.png)

(Функция GetCellsCount(x, y) возвращяет количество живых клеток вокруг проверяемой клетки).

![bandicam 2021-11-09 20-06-38-852 (online-video-cutter com)](https://user-images.githubusercontent.com/52111046/140975793-e1558fa6-8e9d-4783-bc56-0d2a868638b5.gif)

## Правило 30
Элементарный клеточный автомат, то есть одномерный клеточный автомат с двумя состояниями, основанный на операции left XOR (central OR right).

![image](https://user-images.githubusercontent.com/52111046/142520673-206e6551-6d99-409f-b891-b753e39b497a.png)

(y - использкется для переноса на следущую строку и в логике правила 30 не участвует).

![bandicam 2021-11-09 20-07-18-875 (online-video-cutter com)](https://user-images.githubusercontent.com/52111046/142082209-ac0bc9d6-ebc0-4e24-b2d4-f283a08a6a8a.gif)

## Правило 90 (треугольник Серпинского)
Элементарный клеточный автомат, с двумя состояниями, основанный на функции XOR.

![image](https://user-images.githubusercontent.com/52111046/142520048-69959ae6-82e5-451f-9732-7418ecf143e8.png)

(y - использкется для переноса на следущую строку и в логике правила 90 не участвует).

![bandicam 2021-11-09 20-04-18-758 (online-video-cutter com)](https://user-images.githubusercontent.com/52111046/140975116-1d2afdb3-9367-4716-ab51-9adb12a4c39e.gif)


