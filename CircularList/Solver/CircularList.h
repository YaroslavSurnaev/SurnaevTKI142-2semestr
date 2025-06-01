#pragma once
#include <initializer_list>
#include <string>

/**
 * @brief Реализация циклического односвязного списка целых чисел
 *
 * Класс предоставляет стандартные операции работы со списком:
 * - Добавление/удаление элементов
 * - Проверка состояния списка
 * - Поддержка семантики копирования и перемещения
 * - Перегруженные операторы для удобной работы
 */
class CircularList {
private:
    /**
     * @brief Узел списка
     */
    struct Node {
        int data;       ///< Хранимое значение
        Node* next;     ///< Указатель на следующий узел

        /**
         * @brief Конструктор узла
         * @param val Значение для хранения в узле
         */
        Node(int val) : data(val), next(nullptr) {}
    };

    Node* head; ///< Указатель на первый узел
    Node* tail; ///< Указатель на последний узел
    size_t size; ///< Количество элементов в списке

public:
     /**
      * @brief Конструктор по умолчанию
      *
      * Создает пустой список:
      * - head = nullptr
      * - tail = nullptr
      * - size = 0
      */
    CircularList();

    /**
     * @brief Конструктор с инициализацией из списка
     * @param init Список инициализации в формате {1, 2, 3}
     */
    CircularList(std::initializer_list<int> init);

    /**
     * @brief Деструктор
     *
     * Автоматически освобождает всю занятую память
     * через вызов метода clear()
     */
    ~CircularList();

    /**
     * @brief Конструктор копирования
     * @param other Ссылка на копируемый объект
     *
     * Создает глубокую копию списка:
     * - Последовательно копирует все элементы
     * - Сохраняет циклическую структуру
     */
    CircularList(const CircularList& other);

    /**
     * @brief Конструктор перемещения
     * @param other R-value ссылка на объект-источник
     */
    CircularList(CircularList&& other) noexcept;

     /**
      * @brief Копирующее присваивание
      * @param other Ссылка на копируемый объект
      * @return Ссылка на текущий объект
      */
    CircularList& operator=(const CircularList& other);

    /**
     * @brief Перемещающее присваивание
     * @param other R-value ссылка на объект-источник
     * @return Ссылка на текущий объект
     */
    CircularList& operator=(CircularList&& other) noexcept;

     /**
      * @brief Добавляет элемент в конец списка
      * @param value Значение для добавления
      */
    void add(int value);

    /**
     * @brief Удаляет первое вхождение элемента
     * @param value Значение для удаления
     * @return true если элемент найден и удален, иначе false
     */
    bool remove(int value);

    /**
     * @brief Очищает список
     *
     * Освобождает память всех узлов и сбрасывает состояние:
     * - head = nullptr
     * - tail = nullptr
     * - size = 0
     */
    void clear();

    /**
     * @brief Проверяет список на пустоту
     * @return true если список пуст (size == 0)
     */
    bool isEmpty() const { return size == 0; }

    /**
     * @brief Возвращает количество элементов
     * @return Текущий размер списка
     */
    size_t getSize() const { return size; }

    /**
     * @brief Генерирует строковое представление
     * @return Строка в формате [1, 2, 3] или "Empty list"
     */
    std::string toString() const;
    /// @}

    /**
     * @brief Оператор добавления элемента
     * @param value Значение для добавления
     * @return Ссылка на текущий объект (для цепочки операций)
     */
    CircularList& operator<<(int value);

    /**
     * @brief Оператор извлечения элемента
     * @param value Ссылка для сохранения извлеченного значения
     * @return Ссылка на текущий объект

     */
    CircularList& operator>>(int& value);
};