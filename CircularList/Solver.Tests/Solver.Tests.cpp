#pragma once
#include "CppUnitTest.h"
#include "../Solver/CircularList.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace CircularListTests
{
    /**
    * @brief Тестирование базовой функциональности CircularList
    */
    TEST_CLASS(BasicFunctionalityTests)
    {
    public:
        /**
        * @brief Проверка создания пустого списка
        */
        TEST_METHOD(TestEmptyListCreation)
        {
            CircularList list;
            Assert::IsTrue(list.isEmpty());
            Assert::AreEqual(0ull, list.getSize());
            Assert::AreEqual(std::string("Empty list"), list.toString());
        }

        /**
        * @brief Проверка добавления элементов
        */
        TEST_METHOD(TestAddElements)
        {
            CircularList list;
            list.add(10);
            list.add(20);

            Assert::AreEqual(2ull, list.getSize());
            Assert::AreEqual(std::string("[10, 20]"), list.toString());
        }
    };

    /**
    * @brief Тестирование операций удаления
    */
    TEST_CLASS(RemovalTests)
    {
    public:
        /**
        * @brief Проверка удаления элементов
        */
        TEST_METHOD(TestRemoveElements)
        {
            CircularList list = { 1, 2, 3, 4 };

            Assert::IsTrue(list.remove(3));
            Assert::AreEqual(3ull, list.getSize());
            Assert::AreEqual(std::string("[1, 2, 4]"), list.toString());

            Assert::IsFalse(list.remove(99)); // Несуществующий элемент
        }
    };

    /**
    * @brief Тестирование операторов
    */
    TEST_CLASS(OperatorTests)
    {
    public:
        /**
        * @brief Проверка оператора добавления <<
        */
        TEST_METHOD(TestShiftLeftOperator)
        {
            CircularList list;
            list << 5 << 10 << 15;

            Assert::AreEqual(std::string("[5, 10, 15]"), list.toString());
        }

        /**
        * @brief Проверка оператора извлечения >>
        */
        TEST_METHOD(TestShiftRightOperator)
        {
            CircularList list = { 100, 200 };
            int value;
            list >> value;

            Assert::AreEqual(100, value);
            Assert::AreEqual(std::string("[200]"), list.toString());
        }
    };

    /**
    * @brief Тестирование особых случаев
    */
    TEST_CLASS(EdgeCasesTests)
    {
    public:
        /**
        * @brief Проверка циклической природы списка
        */
        TEST_METHOD(TestCircularNature)
        {
            CircularList list = { 1, 2, 3 };
            // Удаляем все элементы по кругу
            Assert::IsTrue(list.remove(1));
            Assert::IsTrue(list.remove(2));
            Assert::IsTrue(list.remove(3));
            Assert::IsTrue(list.isEmpty());
        }

        /**
        * @brief Проверка работы с одним элементом
        */
        TEST_METHOD(TestSingleElementList)
        {
            CircularList list = { 42 };

            Assert::AreEqual(1ull, list.getSize());
            Assert::AreEqual(std::string("[42]"), list.toString());

            int value;
            list >> value;
            Assert::AreEqual(42, value);
            Assert::IsTrue(list.isEmpty());
        }
    };
}