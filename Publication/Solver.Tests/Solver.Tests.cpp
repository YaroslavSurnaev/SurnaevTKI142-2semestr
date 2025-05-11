#include "CppUnitTest.h"
#include "../Solver/Book.h"
#include "../Solver/City.h"
#include "../Solver/Person.h"
#include "../Solver/Publisher.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace SolverTests
{
    TEST_CLASS(BookTests)
    {
    public:
        TEST_METHOD(BookCreationTest)
        {
            City::initCities();
            std::vector<Person> authors = { Person("����", "������") };
            Publisher publisher("������������", City("������"));
            Person editor("����", "������");

            Book book(authors, "�������� �����", 2023, publisher, editor);

            Assert::IsTrue(book.ToString().find("�������� �����") != std::string::npos);
        }
    };
}