import time
import os

def clear_screen():
    os.system('cls' if os.name == 'nt' else 'clear')

def display_welcome():
    clear_screen()
    print("*" * 50)
    print("\n🍔 Welcome to QuickBite Delivery! 🍕")
    print("\nWhere Every Bite is a Quick Delight!")
    print("\n🚀 Fast • Fresh • Fantastic 🚀")
    print("\nLoading", end="")
    for _ in range(3):
        time.sleep(0.5)
        print(".", end="", flush=True)
    print("\n")
    print("*" * 50)
    time.sleep(2)

def Order(): #регистрация аккаунта
    print("\nРегистрация")
    login = str(input("Введите логин:"))
    while(True):
        password = input("Введит ваш пароль: ")
        has_isupper = any(char.isupper() for char in password)
        has_lower = any(char.islower() for char in password)
        has_isalnum = any(char.isalnum() for char in password)
        if len(password) < 8:
            print("Пароль должен содержать хотя бы 8 символов.")
        elif not has_isalnum:
            print("Пароль должен иметь хотя бы одну букву и цифру")
        elif not has_isupper:
            print("Пароль должен иметь одну заглавную букву")
        elif not has_lower:
            print("Пароль должен иметь одну маленькую букву")
        else:
            break
        
    profile = {
        "login": login,
        "Name": input("Введи ваше имя: "),
        "Surname": input("Введи вашу фамилию: "),
        "Address": input("Введи ваш адрес: ")
    } 
    print("\n Регистрация завершена")
    return profile

def dish(): #блюдо, которые есть
    menu = {
        "1": {"name": "Пицца пепперони", "price": 400},
        "2": {"name": "Пицца гавайская", "price": 385 },
        "3": {"name": "Спрайт 0.5л", "price": 88},
        "4": {"name": "Добрый кола 0.5л", "price": 85 }
    }

    print("\n Меню:")
    for num, item in menu.items():
        print(f"{num}. {item["name"]} - {item["price"]} рублей")

# тут с курьером надо пошаманить, чтобы в меню его тоже добавить и потом чтобы курьера можно было выбрать в меню, который будет доставлять
# def courier():
#     print("Курьеры")
#     courier = {
#         "Name": name,
#         "Surname": surname,
#         "Rating": rating
#     }
#     name = "Bogdan"
#     surname = "WibeKoder"
#     rating = "8"

def enter(): #чтобы не было путаницы в главном меню маратикс
    input("\nНажмите любую кнопку, чтобы продолжить")
    clear_screen()
    
def main(): #главное меню 
    user = None

    while True:
        print("\n Главное меню")
        print("1. Регистрация")
        print("2. Меню")
        # print("3. Заказать")                         здесь на будущие что ещё можно добавить
        # print("4. инфо курьерах")
        # print("5. инфо заказа")
        # print("6. инфо клиентов")
        print("3. Выход")

        choise = input("Выберите действие:\n")

        if choise == "1":
            user = Order()
        elif choise == "2":
              if user:
                  dish()
                  enter()
              else:
                  print("Пройди регистрацию о гай дэм")
                  enter() 
        elif choise == "3":
            print("До скорых встреч")
            break
        else:
            print("Ошибка")
            enter()
display_welcome()
main()  





