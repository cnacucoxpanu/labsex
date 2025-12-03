// Конструктор очереди - инициализация пустой очереди
template <typename T>
Ochered<T>::Ochered() : head(nullptr), tail(nullptr), size(0) {}

// Деструктор очереди - освобождение всей памяти
template <typename T>
Ochered<T>::~Ochered() {
    while (head != nullptr) {
        Ochered_node<T>* temp = head;
        head = head->next;
        delete temp;
    }
}

// Добавление элемента в КОНЕЦ очереди (через tail)
template <typename T>
void Ochered<T>::push(const T& value) {
    Ochered_node<T>* newNode = new Ochered_node<T>(value);
    
    if (head == nullptr) {
        // Если очередь пуста, новый элемент становится и головой и хвостом
        head = tail = newNode;
    } else {
        // Если очередь не пуста, добавляем в конец через tail
        newNode->prev = tail;   // новый узел ссылается на старый хвост
        tail->next = newNode;   // старый хвост ссылается на новый узел
        tail = newNode;         // обновляем хвост на новый узел
    }
    size++;
}

// Удаление элемента из НАЧАЛА очереди (через head)
template <typename T>
bool Ochered<T>::pop() {
    if (head == nullptr) return false;  // очередь пуста

    Ochered_node<T>* temp = head;
    head = head->next;          // двигаем голову на следующий элемент
    
    if (head != nullptr) {
        head->prev = nullptr;   // убираем ссылку на старую голову
    } else {
        tail = nullptr;         // если очередь стала пустой, обнуляем хвост
    }
    
    delete temp;
    size--;
    return true;
}

// Вывод очереди в формате: "Очередь (3 элементов): A -> B -> C"
template <typename T>
void Ochered<T>::print() const {
    Ochered_node<T>* curr = head;
    std::cout << "Очередь (" << size << " элементов): ";
    bool first = true;
    while (curr != nullptr) {
        if (!first) {
            std::cout << " -> ";
        }
        std::cout << curr->getData().getName();
        first = false;
        curr = curr->next;
    }
    std::cout << std::endl;
}

// Поиск элемента по условию (предикату)
template <typename T>
template <typename Predicate>
Ochered_node<T>* Ochered<T>::search(Predicate pred) const {
    Ochered_node<T>* curr = head;
    while (curr != nullptr) {
        if (pred(curr->getData())) return curr;
        curr = curr->next;
    }
    return nullptr;
}

// Сортировка очереди пузырьком
template <typename T>
template <typename Compare>
void Ochered<T>::sort(Compare comp) {
    if (size < 2) return;  // нечего сортировать

    // Внешний цикл - проходы по очереди
    for (Ochered_node<T>* i = head; i != nullptr; i = i->next) {
        // Внутренний цикл - сравнение соседних элементов
        for (Ochered_node<T>* j = i->next; j != nullptr; j = j->next) {
            if (comp(i->getData(), j->getData())) {
                // Обмен данными между узлами
                T temp = i->getData();
                i->getData() = j->getData();
                j->getData() = temp;
            }
        }
    }
}

// Проверка на пустоту очереди
template <typename T>
bool Ochered<T>::isEmpty() const { 
    return head == nullptr; 
}

// Получение ПЕРВОГО элемента очереди (без удаления)
template <typename T>
T& Ochered<T>::getFront() { 
    return head->getData(); 
}

template <typename T>
const T& Ochered<T>::getFront() const { 
    return head->getData(); 
}

// Получение размера очереди
template <typename T>
int Ochered<T>::getSize() const { 
    return size; 
}