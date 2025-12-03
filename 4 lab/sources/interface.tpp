template <class T>
void Interface<T>::menu() 
{
    int choice;

    do
    {
        std::cout << "=========================================" << std::endl;
        std::cout << "1. Работа с самолетами" << std::endl;
        std::cout << "2. Работа с поездами" << std::endl;
        std::cout << "3. Работа с автомобилями" << std::endl;
        std::cout << "0. Выход" << std::endl;
        std::cout << "=========================================" << std::endl;
        std::cin >> choice;
        
        switch (choice)
        {
        case 0:
            break;
        case 1:
        {
            Interface<AirPlane> obj1;
            obj1.fun();
            break;
        }
        case 2:
        {
            Interface<Train> obj2;
            obj2.fun();
            break;
        }
        case 3:
        {
            Interface<Car> obj3;
            obj3.fun();
            break;
        }
        default:
            std::cout << "Неверный выбор! Попробуйте снова." << std::endl;
            break;
        }
    } while (choice != 0);
}

template<class T>
void Interface<T>::editElement(T &element)
{
    element.setMenu();
}

template<class T>
void Interface<T>::sortBySpeed()
{
    if (ochered.getSize() == 0)
    {
        std::cout << "Нет элементов для сортировки!" << std::endl;
        return;
    }

    ochered.sort([](const T& a, const T& b) {
        return a.getSpeed() > b.getSpeed();
    });
    std::cout << "Отсортировано по скорости!" << std::endl;
}

template<class T>
void Interface<T>::searchByName()
{
    if (ochered.getSize() == 0)
    {
        std::cout << "Очередь пуста!" << std::endl;
        return;
    }

    std::string name;
    std::cout << "Введите имя для поиска: ";
    std::cin.ignore();
    std::getline(std::cin, name);

    auto result = ochered.search([&](const T& obj) {
        return obj.getName() == name;
    });

    if (result != nullptr)
    {
        std::cout << "Найден элемент:" << std::endl;
        result->getData().shapka();
        result->getData().print();
        std::cout << std::endl;
    }
    else
    {
        std::cout << "Элемент не найден!" << std::endl;
    }
}

template <class T>
void Interface<T>::fun()
{
    system("cls");
    int choice;
    do
    {
        std::cout << "1. Добавить элемент" << std::endl;
        std::cout << "2. Показать очередь" << std::endl;
        std::cout << "3. Редактировать первый элемент" << std::endl;
        std::cout << "4. Удалить первый элемент" << std::endl;
        std::cout << "5. Поиск по имени" << std::endl;
        std::cout << "6. Сортировка по скорости" << std::endl;
        std::cout << "0. Назад" << std::endl;
        std::cout << "=========================================" << std::endl;
        std::cin >> choice;
        std::cin.ignore(1000, '\n');

        switch (choice)
        {
        case 1:
        {
            T obj;
            std::cin >> obj;
            ochered.push(obj);
            std::cout << "Элемент добавлен!" << std::endl;
            break;
        }
        case 2:
        {
            if (ochered.getSize() == 0)
            {
                std::cout << "Очередь пуста!" << std::endl;
            }
            else
            {
                ochered.print();
            }
            break;
        }
        case 3:
        {
            if (ochered.getSize() == 0)
            {
                std::cout << "Очередь пуста!" << std::endl;
            }
            else
            {
                editElement(ochered.getFront());
                std::cout << "Элемент отредактирован!" << std::endl;
            }
            break;
        }
        case 4:
        {
            if (ochered.pop())
            {
                std::cout << "Элемент удален!" << std::endl;
            }
            else
            {
                std::cout << "Очередь пуста!" << std::endl;
            }
            break;
        }
        case 5:
            searchByName();
            break;
        case 6:
            sortBySpeed();
            break;
        case 0:
            break;
        default:
            std::cout << "Неверный выбор!" << std::endl;
        }
        
        if (choice != 0)
        {
            std::cout << "Нажмите Enter для продолжения...";
            std::cin.get();
            system("cls");
        }
    } while (choice != 0);
}