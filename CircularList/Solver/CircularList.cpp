#include "CircularList.h"
#include <sstream>

/**
 * @brief Конструктор по умолчанию
 *
 * Инициализирует пустой список
 */
CircularList::CircularList() : head(nullptr), tail(nullptr), size(0) {}

/**
 * @brief Конструктор с инициализацией из списка
 * @param init Список инициализации
 */
CircularList::CircularList(std::initializer_list<int> init) : CircularList() {
    for (int value : init) {
        add(value);
    }
}

/**
 * @brief Деструктор
 *
 * Освобождает всю занятую списком память через вызов clear()
 */
CircularList::~CircularList() {
    clear();
}

// Конструктор копирования
CircularList::CircularList(const CircularList& other) : head(nullptr), tail(nullptr), size(0) {
    if (other.head) {
        Node* current = other.head;
        do {
            add(current->data);
            current = current->next;
        } while (current != other.head);
    }
}

// Конструктор перемещения
CircularList::CircularList(CircularList&& other) noexcept
    : head(other.head), tail(other.tail), size(other.size) {
    // Обнуляем исходный объект
    other.head = nullptr;
    other.tail = nullptr;
    other.size = 0;
}

// Копирующее присваивание
CircularList& CircularList::operator=(const CircularList& other) {
    if (this != &other) {
        // Очищаем текущее содержимое
        clear();

        // Копируем данные из other
        if (other.head) {
            Node* current = other.head;
            do {
                add(current->data);
                current = current->next;
            } while (current != other.head);
        }
    }
    return *this;
}

// Перемещающее присваивание
CircularList& CircularList::operator=(CircularList&& other) noexcept {
    if (this != &other) {
        // Освобождаем текущие ресурсы
        clear();

        // Перехватываем ресурсы
        head = other.head;
        tail = other.tail;
        size = other.size;

        // Обнуляем исходный объект
        other.head = nullptr;
        other.tail = nullptr;
        other.size = 0;
    }
    return *this;
}

/**
 * @brief Добавляет элемент в конец списка
 * @param value Значение для добавления
 */
void CircularList::add(int value) {
    Node* newNode = new Node(value);

    if (!head) {
        head = tail = newNode;
        newNode->next = head;
    }
    else {
        tail->next = newNode;
        tail = newNode;
        tail->next = head;
    }
    size++;
}

/**
 * @brief Удаляет первое вхождение элемента
 * @param value Значение для удаления
 * @return true если элемент был найден и удален, false в противном случае
 */
bool CircularList::remove(int value) {
    if (!head) return false;

    Node* current = head;
    Node* prev = tail;

    do {
        if (current->data == value) {
            if (current == head && current == tail) {
                head = tail = nullptr;
            }
            else if (current == head) {
                head = head->next;
                tail->next = head;
            }
            else if (current == tail) {
                tail = prev;
                tail->next = head;
            }
            else {
                prev->next = current->next;
            }

            delete current;
            size--;
            return true;
        }
        prev = current;
        current = current->next;
    } while (current != head);

    return false;
}

/**
 * @brief Очищает список
 *
 * Удаляет все элементы и освобождает память
 */
void CircularList::clear() {
    if (!head) return;

    Node* current = head;
    do {
        Node* next = current->next;
        delete current;
        current = next;
    } while (current != head);

    head = tail = nullptr;
    size = 0;
}

/**
 * @brief Генерирует строковое представление списка
 * @return Строка в формате [x1, x2, ..., xn] или "Empty list" если пуст
 */
std::string CircularList::toString() const {
    std::ostringstream oss;
    if (!head) {
        oss << "Empty list";
    }
    else {
        Node* current = head;
        oss << "[";
        do {
            oss << current->data;
            if (current->next != head) oss << ", ";
            current = current->next;
        } while (current != head);
        oss << "]";
    }
    return oss.str();
}

/**
 * @brief Оператор добавления элемента в список
 * @param value Значение для добавления
 * @return Ссылка на текущий список (позволяет цепочки операций)
 */
CircularList& CircularList::operator<<(int value) {
    add(value);
    return *this;
}

/**
 * @brief Оператор извлечения элемента из списка
 * @param value Ссылка для сохранения извлеченного значения
 * @return Ссылка на текущий список (позволяет цепочки операций)
 *
 * Извлекает первый элемент списка и сохраняет его в value
 */
CircularList& CircularList::operator>>(int& value) {
    if (head) {
        value = head->data;
        remove(value);
    }
    return *this;
}