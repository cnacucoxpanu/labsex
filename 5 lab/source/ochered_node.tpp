#ifndef OCHERED_NODE_TPP
#define OCHERED_NODE_TPP

#include <algorithm>

// Конструктор по умолчанию - инициализирует пустую очередь
template <typename T>
Ochered<T>::Ochered() : head(nullptr), tail(nullptr), size(0) {}

// Деструктор - освобождает всю память, занятую узлами очереди
template <typename T>
Ochered<T>::~Ochered() {
    while (head != nullptr) {
        Ochered_node<T>* temp = head;
        head = head->next;
        delete temp;
    }
}

// Добавление элемента в конец очереди
template <typename T>
void Ochered<T>::push(const T& value) {
    Ochered_node<T>* newNode = new Ochered_node<T>(value);
    
    // Если очередь пуста, новый элемент становится и головой и хвостом
    if (head == nullptr) {
        head = tail = newNode;
    } else {
        // Иначе добавляем новый элемент после текущего хвоста
        newNode->prev = tail;
        tail->next = newNode;
        tail = newNode;
    }
    size++;
}

// Удаление элемента из начала очереди
template <typename T>
bool Ochered<T>::pop() {
    if (head == nullptr) return false; // Очередь пуста

    Ochered_node<T>* temp = head;
    head = head->next;
    
    // Обновляем указатель prev у новой головы (если она существует)
    if (head != nullptr) {
        head->prev = nullptr;
    } else {
        // Если очередь стала пустой, обнуляем и хвост
        tail = nullptr;
    }
    
    delete temp;
    size--;
    return true;
}

// Вывод содержимого очереди в консоль
template <typename T>
void Ochered<T>::print() const {
    Ochered_node<T>* curr = head;
    std::cout << "Очередь (" << size << " элементов): ";
    bool first = true;
    while (curr != nullptr) {
        if (!first) {
            std::cout << " -> ";
        }
        std::cout << curr->getData().getName(); // Предполагается, что T имеет метод getName()
        first = false;
        curr = curr->next;
    }
    std::cout << std::endl;
}

// Поиск элемента в очереди по предикату
template <typename T>
template <typename Predicate>
Ochered_node<T>* Ochered<T>::search(Predicate pred) const {
    Ochered_node<T>* curr = head;
    while (curr != nullptr) {
        if (pred(curr->getData())) return curr; // Возвращаем первый элемент, удовлетворяющий условию
        curr = curr->next;
    }
    return nullptr; // Элемент не найден
}

// Сортировка очереди методом пузырька
template <typename T>
template <typename Compare>
void Ochered<T>::sort(Compare comp) {
    if (size < 2) return; // Нечего сортировать

    // Внешний цикл - проход по всем элементам
    for (Ochered_node<T>* i = head; i != nullptr; i = i->next) {
        // Внутренний цикл - сравнение текущего элемента с последующими
        for (Ochered_node<T>* j = i->next; j != nullptr; j = j->next) {
            if (comp(i->getData(), j->getData())) {
                // Если элементы находятся в неправильном порядке, меняем их местами
                using std::swap;
                swap(i->getData(), j->getData());
            }
        }
    }
}

// Проверка, пуста ли очередь
template <typename T>
bool Ochered<T>::isEmpty() const { 
    return head == nullptr; 
}

// Получение ссылки на элемент в начале очереди (неконстантная версия)
template <typename T>
T& Ochered<T>::getFront() { 
    return head->getData(); 
}

// Получение константной ссылки на элемент в начале очереди
template <typename T>
const T& Ochered<T>::getFront() const { 
    return head->getData(); 
}

// Получение текущего размера очереди
template <typename T>
int Ochered<T>::getSize() const { 
    return size; 
}

#endif