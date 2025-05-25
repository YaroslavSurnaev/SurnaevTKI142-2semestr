#pragma once
#include <initializer_list>
#include <string>

/**
 * @brief Класс, реализующий циклический односвязный список целых чисел
 *
 * Список поддерживает основные операции: добавление, удаление, проверку на пустоту,
 * а также перегруженные операторы для удобной работы.
 */
class CircularList {
private:
    /**
     * @brief Структура узла списка
     */
    struct Node {
        int data;       ///< Значение узла
        Node* next;     ///< Указатель на следующий узел

        /**
         * @brief Конструктор узла
         * @param val Значение для хранения в узле
         */
        Node(int val) : data(val), next(nullptr) {}
    };

    Node* head; ///< Указатель на первый узел списка
    Node* tail; ///< Указатель на последний узел списка
    size_t size; ///< Текущий размер списка

public:
    /**
     * @brief Конструктор по умолчанию
     */
    CircularList();

    /**
     * @brief Конструктор с инициализацией из списка
     * @param init Список инициализации
     */
    CircularList(std::initializer_list<int> init);

    /**
     * @brief Деструктор
     *
     * Освобождает всю занятую списком память
     */
    ~CircularList();

    /**
     * @brief Добавляет элемент в конец списка
     * @param value Значение для добавления
     */
    void add(int value);

    /**
     * @brief Удаляет первое вхождение элемента
     * @param value Значение для удаления
     * @return true если элемент был найден и удален, false в противном случае
     */
    bool remove(int value);

    /**
     * @brief Очищает список
     *
     * Удаляет все элементы и освобождает память
     */
    void clear();

    /**
     * @brief Проверяет список на пустоту
     * @return true если список пуст, false в противном случае
     */
    bool isEmpty() const { return size == 0; }

    /**
     * @brief Возвращает текущий размер списка
     * @return Количество элементов в списке
     */
    size_t getSize() const { return size; }

    /**
     * @brief Генерирует строковое представление списка
     * @return Строка в формате [x1, x2, ..., xn] или "Empty list" если пуст
     */
    std::string toString() const;

    /**
     * @brief Оператор добавления элемента в список
     * @param value Значение для добавления
     * @return Ссылка на текущий список (позволяет цепочки операций)
     */
    CircularList& operator<<(int value);

    /**
     * @brief Оператор извлечения элемента из списка
     * @param value Ссылка для сохранения извлеченного значения
     * @return Ссылка на текущий список (позволяет цепочки операций)
     *
     * Извлекает первый элемент списка и сохраняет его в value
     */
    CircularList& operator>>(int& value);
};