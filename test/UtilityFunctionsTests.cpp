#include "catch.hpp"
#include "UtilityFunctions.hpp"
#include "RandomNumberGenerator.hpp"

SCENARIO("check createGenerator() function")
{
    GIVEN("Generator type RANDOM")
    {
        auto type = GeneratorType::RANDOM;

        WHEN("Generator is created with provided type")
        {
            auto generator = createGenerator(type);

            THEN("It should not be a null pointer")
            {
                CHECK(generator);
            }
        }
    }

    GIVEN("Not existing generator type")
    {
        auto type = static_cast<GeneratorType>(-1);

        WHEN("Generator is created with provided type")
        {
            THEN("It should throw logic_error")
            {
                CHECK_THROWS_AS(createGenerator(type), std::logic_error);
            }
        }
    }
}

SCENARIO("check sumGeneratedNumbers() function")
{
    GIVEN("RandomNumberGenerator and numberOfValues = 10")
    {
        auto generator = std::make_unique<RandomNumberGenerator>();
        auto numberOfValues = 10;

        WHEN("sumGeneratedNumbers is called")
        {
            auto result = sumGeneratedNumbers(std::move(generator), numberOfValues);

            THEN("It should return 420")
            {
                CHECK(result == 420);
            }
        }
    }
}

SCENARIO("check sumNumbersFromGenerators() function")
{
    GIVEN("Empty generators collection and numberOfValues = 1")
    {
        std::vector<GeneratorType> collection = {};
        auto numberOfValues = 1;

        WHEN("sumNumbersFromGenerators is called")
        {
            auto result = sumNumbersFromGenerators(collection, numberOfValues);

            THEN("It should return 0")
            {
                CHECK(result == 0);
            }
        }
    }
}