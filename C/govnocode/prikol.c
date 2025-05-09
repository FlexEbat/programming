#include <stdio.h>
#include <math.h>

void imt() 
{
	double weight, height, imt;
	printf("Пару но при подсчёте IMT:\n");
	printf("1. Рост меряй без Обуви.\n");
	printf("2. Вес утром, натощак, после туалета.\n");
	printf("3. Рост укажи в метрах(не 182, а 1.82).\n");
	printf("4. Если ты накаченный кабан, то ИМТ только покажет ожирение.\n");
	printf("Введи свой вес: ");
	if(scanf("%lf", &weight) != 1) {
		printf("Ошибка ввода. Пожалуйста, введите число.\n");
		return; // Возвращаем ошибку
	}
	if (weight <= 0) {
		printf("Вес не может быть отрицательным.\n");
		return; // Возвращаем ошибку
	}
	printf("Введи свой рост: ");
	if(scanf("%lf", &height) != 1) {
		printf("Ошибка ввода. Пожалуйста, введите число.\n");
		return; // Возвращаем ошибку
	}
	if (height <= 0) {
		printf("Рост не может быть отрицательным.\n");
		return; // Возвращаем ошибку
	}
	imt = weight / (pow(height,2));
	printf("Твой ИМТ: %.2lf\n", imt);
	if (imt < 18.5) printf("Дрищ ты, братец.\n");
	else if (imt < 25) printf("Нормуль, живи спокойно.\n");
	else if (imt < 30) printf("Уже на подходе к свиноферме.\n");
	else printf("Поздравляю, ты шаурма ходячая.\n");
}

void kgToPounds()
 {
	double kg, pounds;
	
	printf("Введите ваш вес в КГ: ");
	if(scanf("%lf", &kg) != 1) {
		printf("Ошибка ввода. Пожалуйста, введите число.\n");
		return; // Возвращаем ошибку
	}
	if (kg < 0) {
		printf("Вес не может быть <0.\n");
		return;
	} 
	pounds = kg * 2.20462;
	printf("Ваш вес в Фунтах: %.2lf\n", pounds);
}

void rubToUsd()
{
	double rub, dollar;
	printf("КУРС АКТУАЛЕН НА 17.04.2025\n");
	printf("Введите сумму в рублях(БЕЗ ПРОБЕЛОВ): ");
	if(scanf("%lf", &rub) != 1) {
		printf("Ошибка ввода. Пожалуйста, введите число.\n");
		return; // Возвращаем ошибку
	}
	if (rub <= 0) {
		printf("Как?**???\n");
		return;
	}
	dollar = rub / 82.5892;
	printf("Твои %.2lf рублей - это %.2lf долларов США.\n", rub, dollar);
}

void bmr() {
    int choice, activityChoice;
    double weight, height, age, bmr, tdee, deficit, surplus, protein, fat, carbs;
    
    printf("Используем формулу Харриса-Бенедикта\n");
    printf("Баба чи мужик????\n");
    printf("1. Баба\n2. Мужик\n");
    printf("А: ");
    if (scanf("%d", &choice) != 1) {
        printf("Ошибка ввода. Пожалуйста, введите число.\n");
        return; // Выход из функции
    }

    if (choice == 1 || choice == 2) {
        printf("Введите свой вес в КГ: ");
        if (scanf("%lf", &weight) != 1) {
            printf("Ошибка ввода. Пожалуйста, введите число.\n");
            return; // Выход из функции
        }
        if (weight <= 0) {
            printf("Вес не может быть отрицательным или нулевым.\n");
            return; // Выход из функции
        }

        printf("Введите свой рост в см(в см): ");
        if (scanf("%lf", &height) != 1) {
            printf("Ошибка ввода. Пожалуйста, введите число.\n");
            return; // Выход из функции
        }
        if (height <= 0) {
            printf("Рост не может быть отрицательным или нулевым.\n");
            return; // Выход из функции
        }

        printf("Введите свой возраст в годах: ");
        if (scanf("%lf", &age) != 1) {
            printf("Ошибка ввода. Введите число.\n");
            return; // Выход из функции
        }
        if (age <= 0) {
            printf("Возраст не может быть отрицательным или нулевым.\n");
            return; // Выход из функции
        }

        // Расчёт BMR
        if (choice == 1) {
            bmr = 447.593 + (9.247 * weight) + (3.098 * height) - (4.330 * age);
        } 
        else if (choice == 2) {
            bmr = 88.362 + (13.397 * weight) + (4.799 * height) - (5.677 * age);
        }

        printf("Ваш BMR: %.2lf ккал/день\n", bmr);  // Теперь выводим BMR после его вычисления

        // Ввод уровня активности
        printf("Выберите уровень активности:\n");
        printf("1. Маленькая активность (сидячий образ жизни)\n");
        printf("2. Умеренная активность (легкие упражнения или работа)\n");
        printf("3. Высокая активность (тренировки 3-5 раз в неделю)\n");
        printf("4. Очень высокая активность (тренировки каждый день или физическая работа)\n");
        printf("Введите номер: ");
        if (scanf("%d", &activityChoice) != 1) {
            printf("Ошибка ввода.\n");
            return;
        }

        // Рассчитаем TDEE на основе выбранной активности
        if (activityChoice == 1) {
            tdee = bmr * 1.2;
        } else if (activityChoice == 2) {
            tdee = bmr * 1.55;
        } else if (activityChoice == 3) {
            tdee = bmr * 1.725;
        } else if (activityChoice == 4) {
            tdee = bmr * 1.9;
        } else {
            printf("Ошибка ввода.\n");
            return;
        }

        printf("Ваш TDEE: %.2lf ккал/день\n", tdee);

        // Ввод дефицита или профицита
        printf("Выберите цель:\n");
        printf("1. Похудение (дефицит калорий)\n");
        printf("2. Набор массы (профицит калорий)\n");
        printf("3. Поддержание веса (без изменений)\n");
        printf("Введите номер: ");
        int goalChoice;
        if (scanf("%d", &goalChoice) != 1) {
            printf("Ошибка ввода.\n");
            return;
        }

        // Рассчитаем калории в зависимости от цели
        if (goalChoice == 1) { // Похудение
            deficit = tdee * 0.8; // 20% дефицит
            printf("Для похудения вам нужно: %.2lf ккал/день\n", deficit);
        } else if (goalChoice == 2) { // Набор массы
            surplus = tdee * 1.1; // 10% профицит
            printf("Для набора массы вам нужно: %.2lf ккал/день\n", surplus);
        } else { // Поддержание веса
            printf("Для поддержания веса вам нужно: %.2lf ккал/день\n", tdee);
        }

        // Расчёт макроэлементов для похудения или набора массы
        protein = weight * 2;
        fat = weight * 1;
        double caloriesFromProtein = protein * 4;
        double caloriesFromFat = fat * 9;
        double remainingCalories = (goalChoice == 1) ? deficit : (goalChoice == 2) ? surplus : tdee;
        carbs = (remainingCalories - caloriesFromProtein - caloriesFromFat) / 4;

        printf("Для вашей цели:\n");
        printf("Белки: %.2lf г\n", protein);
        printf("Жиры: %.2lf г\n", fat);
        printf("Углеводы: %.2lf г\n", carbs);

    } else {
        printf("Ошибка: выбран неверный вариант.\n");
    }
}

int main()
{
	int choice;
	do {
	printf("Небольшой пак тул\n");
	printf("1. Поможем посчитать индекс массы тела(ИМТ);\n2. Перевести ваш вес из КГ в футы;\n3. Перевести доллары в руб.\n4. Расчёт BMR+TDEE\n");
	printf("!!! ВЫЙТИ ИЗ МЕНЮ - 0 !!!\n");
	printf("Выберите одно из меню: ");
	scanf("%d", &choice);
	
	switch (choice)
	{
	case 0:
		printf("Давай пока:)");
		break;
	case 1:
		imt();
		break;
	case 2:
		kgToPounds();
		break;
	case 3:
		rubToUsd();
		break;
	case 4:
		bmr();
		break;
	default:
		printf("Ты выбрал не правильный вариант. Попробуй ещё раз.\n");
		break;
	} 
		} while (choice != 0);
	return 0;
}