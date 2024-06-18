#include "menuitem.h"
#include "order.h"
#include "guest.h"
#include "chef.h"
#include "waiter.h"
#include "admin.h"
#include "employee.h"
#include "restic.h"
#include <iostream>
#include <vector>
#include <locale>


using namespace std;

bool removeMenuItem(vector<MenuItem>& menu, const string& itemName) {
    for (auto it = menu.begin(); it != menu.end(); ++it) {
        if (it->getName() == itemName) {
            menu.erase(it);
            return true;
        }
    }
    return false;
}

void displayMainMenu();
void displaySubMenu(const vector<MenuItem>& items, Order& order);
void addItemsToMenu(vector<MenuItem>& items, const vector<pair<string, double>>& data);
void handleGuestRole(vector<MenuItem>& fries, vector<MenuItem>& burgers, vector<MenuItem>& hotDrinks,
    vector<MenuItem>& drinks, vector<MenuItem>& desserts, vector<MenuItem>& iceCreams,
    vector<Order>& allOrders);
void handleChefRole(Chef& chef, vector<Order>& allOrders);
void handleWaiterRole(Waiter& waiter, vector<Order>& allOrders);
void handleAdminRole(Admin& admin, vector<MenuItem>& fries, vector<MenuItem>& burgers,
    vector<MenuItem>& hotDrinks, vector<MenuItem>& drinks,
    vector<MenuItem>& desserts, vector<MenuItem>& iceCreams,
    vector<Employee>& employees);

bool authenticate(const string& role);

int main() {

    setlocale(LC_ALL, "Rus");
    Chef chef("Chef1");
    Waiter waiter("Waiter1", "password");
    Admin admin("Admin", "admin");
    vector<Order> allOrders;
    vector<Employee> employees;

    vector<MenuItem> fries;
    addItemsToMenu(fries, { {"Картошка фри: картошка, обжаренная до золотистой корочки", 120.0},
                            {"Картошка по-деревенски: картофельные дольки, приготовленные по старинному рецепту", 150.0} });

    vector<MenuItem> burgers;
    addItemsToMenu(burgers, { {"Мясной бургер: сочный бифштекс с овощами на пшеничной булочке", 280.0},
                              {"Куриный бургер: нежное куриное филе с листьями салата и помидором", 250.0},
                              {"Бургер с рыбой: свежая рыба с лимоном и соусом тар-тар", 320.0} });

    vector<MenuItem> hotDrinks;
    addItemsToMenu(hotDrinks, { {"Кофе: ароматный напиток с молоком или без", 80.0},
                                {"Горячий шоколад: нежный шоколадный вкус с маршмеллоу", 120.0} });

    vector<MenuItem> drinks;
    addItemsToMenu(drinks, { {"Кола: прохладительный газированный напиток", 60.0},
                             {"Фанта: освежающий фруктовый напиток", 60.0},
                             {"Вода: чистая питьевая вода", 50.0} });

    vector<MenuItem> desserts;
    addItemsToMenu(desserts, { {"Пирожок с вишней: нежное тесто с сочной начинкой из вишни", 130.0},
                               {"Пирожок с яблоком: ароматное яблочное начинка в хрустящем тесте", 130.0} });

    vector<MenuItem> iceCreams;
    addItemsToMenu(iceCreams, { {"Шоколадное мороженое: настоящий шоколадный вкус в каждой ложке", 150.0},
                                {"Карамельное мороженое: нежное мороженое с ароматом карамели", 150.0} });



    while (true) {
        cout << "\n--- Главное меню ---\n";
        cout << "1. Войти как Гость\n";
        cout << "2. Войти как Повар\n";
        cout << "3. Войти как Официант\n";
        cout << "4. Войти как Системный администратор\n";
        cout << "0. Выйти\n";
        cout << "Выберите роль: ";

        int choice;
        cin >> choice;

        switch (choice) {
        case 1:
            handleGuestRole(fries, burgers, hotDrinks, drinks, desserts, iceCreams, allOrders);
            break;
        case 2:
            if (authenticate("chef")) {
                handleChefRole(chef, allOrders);
            }
            break;
        case 3:
            if (authenticate("ofic")) {
                handleWaiterRole(waiter, allOrders);
            }
            break;
        case 4:
            if (authenticate("admin")) {
                handleAdminRole(admin, fries, burgers, hotDrinks, drinks, desserts, iceCreams, employees);
            }
            break;
        case 0:
            return 0;
        default:
            cout << "Неверный выбор. Попробуйте снова.\n";
        }
    }
}

void displayMainMenu() {
    cout << "\n--- Меню ---\n";
    cout << "1. Картошка\n";
    cout << "2. Бургеры\n";
    cout << "3. Горячие напитки\n";
    cout << "4. Напитки\n";
    cout << "5. Десерты\n";
    cout << "6. Мороженое\n";
    cout << "0. Назад\n";
}

void displaySubMenu(const vector<MenuItem>& items, Order& order) {
    for (size_t i = 0; i < items.size(); ++i) {
        cout << i + 1 << ". " << items[i].getName() << " (" << items[i].getPrice() << " руб.)" << endl;
    }
    cout << "Выберите пункт для добавления в заказ (0 для возврата в главное меню): ";
    int choice;
    cin >> choice;

    if (choice > 0 && choice <= items.size()) {
        order.addItem(items[choice - 1]);
        cout << items[choice - 1].getName() << " добавлен в заказ." << endl;
        cout << "Текущая итоговая цена заказа: " << order.getTotalPrice() << " руб." << endl;
    }
    else if (choice != 0) {
        cout << "Неверный выбор. Попробуйте снова." << endl;
    }
}

void addItemsToMenu(vector<MenuItem>& items, const vector<pair<string, double>>& data) {
    for (const auto& item : data) {
        items.emplace_back(item.first, item.second);
    }
}

void handleGuestRole(vector<MenuItem>& fries, vector<MenuItem>& burgers, vector<MenuItem>& hotDrinks,
    vector<MenuItem>& drinks, vector<MenuItem>& desserts, vector<MenuItem>& iceCreams,
    vector<Order>& allOrders) {
    Guest guest("Guest", "password");
    Order order;

    while (true) {
        cout << "Меню:\n";
        cout << "1. Показать картофель фри\n";
        cout << "2. Показать бургеры\n";
        cout << "3. Показать горячие напитки\n";
        cout << "4. Показать напитки\n";
        cout << "5. Показать десерты\n";
        cout << "6. Показать мороженое\n";
        cout << "7. Показать содержимое корзины\n";
        cout << "0. Завершить заказ\n";
        cout << "Выберите опцию: ";
        int choice;
        cin >> choice;

        switch (choice) {
        case 1:
            displaySubMenu(fries, order);
            break;
        case 2:
            displaySubMenu(burgers, order);
            break;
        case 3:
            displaySubMenu(hotDrinks, order);
            break;
        case 4:
            displaySubMenu(drinks, order);
            break;
        case 5:
            displaySubMenu(desserts, order);
            break;
        case 6:
            displaySubMenu(iceCreams, order);
            break;
        case 7:
            if (!order.isEmpty()) {
                cout << "Содержимое корзины:\n";
                order.display();
            }
            else {
                cout << "Корзина пуста.\n";
            }
            break;
        case 0:
            order.setStatus("Оплачен");
            guest.addToOrder(order);
            guest.confirmOrder();
            allOrders.push_back(order);
            return;
        default:
            cout << "Неверный выбор. Попробуйте снова.\n";
        }
    }
}

void handleChefRole(Chef& chef, vector<Order>& allOrders) {
    while (true) {
        cout << "\n--- Меню повара ---\n";
        cout << "1. Просмотреть заказы\n";
        cout << "2. Начать приготовление заказа\n";
        cout << "0. Назад\n";
        cout << "Выберите действие: ";

        int choice;
        cin >> choice;

        switch (choice) {
        case 1:
            chef.viewOrders(allOrders);
            break;
        case 2:
            int orderId;
            cout << "Введите номер заказа для приготовления: ";
            cin >> orderId;
            for (auto& order : allOrders) {
                if (order.getId() == orderId) {
                    chef.startPreparingOrder(order);
                    break;
                }
            }
            break;
        case 0:
            return;
        default:
            cout << "Неверный выбор. Попробуйте снова.\n";
        }
    }
}

void handleWaiterRole(Waiter& waiter, vector<Order>& orders) {
    int choice;
    do {
        cout << "1. Посмотреть заказы\n";
        cout << "2. Получить заказ\n";
        cout << "3. Доставить заказ\n";
        cout << "0. Выйти\n";
        cout << "Выберите действие: ";
        cin >> choice;

        switch (choice) {
        case 1:
            waiter.viewOrders(orders);
            break;
        case 2: {
            int orderId;
            cout << "Введите ID заказа: ";
            cin >> orderId;
            for (auto& order : orders) {
                if (order.getId() == orderId) {
                    waiter.receiveOrder(order);
                    break;
                }
            }
            break;
        }
        case 3: {
            int orderId;
            cout << "Введите ID заказа: ";
            cin >> orderId;
            for (auto& order : orders) {
                if (order.getId() == orderId) {
                    waiter.deliverOrder(order);
                    break;
                }
            }
            break;
        }
        case 0:
            cout << "Выход.\n";
            break;
        default:
            cout << "Неверный выбор. Попробуйте снова.\n";
        }
    } while (choice != 0);
}

void handleAdminRole(Admin& admin, vector<MenuItem>& fries, vector<MenuItem>& burgers,
    vector<MenuItem>& hotDrinks, vector<MenuItem>& drinks,
    vector<MenuItem>& desserts, vector<MenuItem>& iceCreams,
    vector<Employee>& employees) {
    while (true) {
        cout << "\n--- Меню администратора ---\n";
        cout << "1. Просмотреть меню\n";
        cout << "2. Добавить пункт в меню\n";
        cout << "3. Удалить пункт из меню\n";
        cout << "4. Просмотреть сотрудников\n";
        cout << "5. Добавить нового сотрудника\n";
        cout << "6. Удалить сотрудника\n";
        cout << "7. Изменить данные сотруднику\n";
        cout << "0. Назад\n";
        cout << "Выберите действие: ";

        int choice;
        cin >> choice;

        switch (choice) {
        case 1:
            cout << "--- Меню ---\n";
            for (const auto& item : fries) cout << item.getName() << " " << item.getPrice() << "  Руб" << "\n";
            for (const auto& item : burgers) cout << item.getName() << " " << item.getPrice() << "  Руб" << "\n";
            for (const auto& item : hotDrinks) cout << item.getName() << " " << item.getPrice() << "  Руб" << "\n";
            for (const auto& item : drinks) cout << item.getName() << " " << item.getPrice() << "  Руб" << "\n";
            for (const auto& item : desserts) cout << item.getName() << " " << item.getPrice() << "  Руб" << "\n";
            for (const auto& item : iceCreams) cout << item.getName() << " " << item.getPrice() << "  Руб" << "\n";
            break;
        case 2:
        {
            string newItemName;
            double newItemPrice;
            cout << "Введите название нового товара: ";
            cin >> newItemName;
            cout << "Введите цену нового товара: ";
            cin >> newItemPrice;
            MenuItem newItem(newItemName, newItemPrice);
            fries.push_back(newItem);
            cout << "Пункт успешно добавлен в меню.\n";

            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            break;
        }

        case 3:
        {
            string itemToRemove;
            cout << "Введите название пункта, который нужно удалить: ";
            cin >> itemToRemove;
            if (!removeMenuItem(fries, itemToRemove) &&
                !removeMenuItem(burgers, itemToRemove) &&
                !removeMenuItem(hotDrinks, itemToRemove) &&
                !removeMenuItem(drinks, itemToRemove) &&
                !removeMenuItem(desserts, itemToRemove) &&
                !removeMenuItem(iceCreams, itemToRemove)) {
                cout << "Пункт не найден в меню.\n";
            }
            else {
                cout << "Пункт успешно удален из меню.\n";
            }
            break;
        }
        case 4:
            cout << "\n--- Сотрудники ---\n";
            for (const auto& employee : employees) {
                cout << "Имя: " << employee.getFirstName() << " Фамилия: " << employee.getLastName() << " Отчество: " << employee.getMiddleName()
                    << ", Логин: " << employee.getLogin() << ", Пароль: " << employee.getPassword() << ", Роль: " << employee.getRole() << "\n";
            }
            break;
        case 5:
        {
            string name, lastName, middleName, login, password, role;
            cout << "Введите имя нового сотрудника: ";
            cin >> name;
            cout << "Введите фамилию нового сотрудника: ";
            cin >> lastName;
            cout << "Введите отчество нового сотрудника: ";
            cin >> middleName;
            cout << "Введите логин нового сотрудника: ";
            cin >> login;
            cout << "Введите пароль нового сотрудника: ";
            cin >> password;
            cout << "Введите роль нового сотрудника: ";
            cin >> role;
            Employee newEmployee(role, lastName, name, middleName, login, password);
            employees.push_back(newEmployee);
            cout << "Сотрудник успешно добавлен.\n";
            break;
        }
        case 6:
        {
            string lastNameToRemove;
            cout << "Введите фамилию сотрудника, которого нужно удалить: ";
            cin >> lastNameToRemove;
            auto it = find_if(employees.begin(), employees.end(), [&](const Employee& e) { return e.getLastName() == lastNameToRemove; });
            if (it != employees.end()) {
                employees.erase(it);
                cout << "Сотрудник успешно удален.\n";
            }
            else {
                cout << "Сотрудник с такой фамилией не найден.\n";
            }
            break;
        }

        case 7:
        {
            string lastNameToEdit;
            cout << "Введите фамилию сотрудника, данные которого нужно изменить: ";
            cin >> lastNameToEdit;
            auto it = find_if(employees.begin(), employees.end(), [&](const Employee& e) { return e.getLastName() == lastNameToEdit; });
            if (it != employees.end()) {
                string newLastName, newFirstName, newMiddleName, newRole, newLogin, newPassword;
                cout << "Введите новую фамилию: ";
                cin >> newLastName;
                cout << "Введите новое имя: ";
                cin >> newFirstName;
                cout << "Введите новое отчество: ";
                cin >> newMiddleName;
                cout << "Введите новую роль: ";
                cin >> newRole;
                cout << "Введите новый логин: ";
                cin >> newLogin;
                cout << "Введите новый пароль: ";
                cin >> newPassword;
                it->setLastName(newLastName);
                it->setFirstName(newFirstName);
                it->setMiddleName(newMiddleName);
                it->setRole(newRole);
                it->setLogin(newLogin);
                it->setPassword(newPassword);
                cout << "Данные сотрудника успешно изменены.\n";
            }
            else {
                cout << "Сотрудник с такой фамилией не найден.\n";
            }
            break;
        }

        case 0:
            return;
        default:
            cout << "Неверный выбор. Попробуйте снова.\n";
        }
    }
}

bool authenticate(const string& role) {
    string password;
    cout << "Введите пароль для " << role << ": ";
    cin >> password;
    if (role == "chef" && password == "password") return true;
    if (role == "ofic" && password == "password") return true;
    if (role == "admin" && password == "admin") return true;
    cout << "Неверный пароль.\n";
    return false;
}

