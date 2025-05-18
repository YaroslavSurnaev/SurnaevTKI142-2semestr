#include "CppUnitTest.h"
#include "../Solver/Book.h"
#include "../Solver/City.h"
#include "../Solver/Person.h"
#include "../Solver/Publisher.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace SolverTests
{
    TEST_CLASS(CityTests)
    {
    public:
        TEST_METHOD(TestCityInitialization)
        {
            City city("Москва");
            Assert::AreEqual(std::string("Москва"), city.getName());
        }
    };

    TEST_CLASS(PersonTests)
    {
    public:
        TEST_METHOD(TestPersonFullName)
        {
            Person person("Иван", "Иванов");
            Assert::AreEqual(std::string("Иван Иванов"), person.getFullName());
        }
    };

    TEST_CLASS(PublisherTests)
    {
    public:
        TEST_METHOD(TestPublisherToString)
        {
            Publisher publisher("Эксмо", City("Москва"));
            std::string expected = "Издательство: Эксмо, Город: Москва";
            Assert::AreEqual(expected, publisher.ToString());
        }
    };

    TEST_CLASS(BookTests)
    {
    public:
        TEST_METHOD(TestBookToString)
        {
            std::vector<Person> authors = { Person("Лев", "Толстой") };
            Publisher publisher("АСТ", City("Москва"));
            Person editor("Иван", "Иванов");

            Book book(authors, "Война и мир", 1869, publisher, editor);

            std::string result = book.ToString();
            Assert::IsTrue(result.find("Книга: Война и мир") != std::string::npos);
            Assert::IsTrue(result.find("Год издания: 1869") != std::string::npos);
            Assert::IsTrue(result.find("Лев Толстой") != std::string::npos);
            Assert::IsTrue(result.find("Издательство: АСТ") != std::string::npos);
            Assert::IsTrue(result.find("Редактор: Иван Иванов") != std::string::npos);
        }

        TEST_METHOD(TestBookReadFromStream)
        {
            std::istringstream input(
                "1\n"      // Количество авторов
                "Федор\n"  // Имя автора
                "Достоевский\n" // Фамилия автора
                "Преступление и наказание\n" // Название книги
                "1866\n"   // Год издания
                "Азбука\n" // Издательство
                "Москва\n" // Город
                "Петр\n"   // Имя редактора
                "Петров\n" // Фамилия редактора
            );

            Book book = Book::ReadFromStream(input);

            std::string result = book.ToString();
            Assert::IsTrue(result.find("Федор Достоевский") != std::string::npos);
            Assert::IsTrue(result.find("Преступление и наказание") != std::string::npos);
        }
    };
}