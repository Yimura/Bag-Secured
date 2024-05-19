#include <algorithm>
#include <cstring>
#include <cstdint>
#include <format>
#include <fstream>
#include <functional>
#include <iostream>
#include <string_view>
#include <tuple>
#include <vector>

static std::fstream log;

struct product
{
    product()
    {
        {
            std::string _weight, _value;
            std::cin >> _weight;
            std::cin >> _value;

            weight = std::stoll(_weight);
            value = std::stoll(_value);
        }

        ratio = float(value) / float(weight);
    }

    int64_t weight;
    int64_t value;
    float ratio;

    bool operator<(const product &other)
    {
        return std::tie(value, other.weight, ratio) > std::tie(other.value, weight, other.ratio);
    }

    friend std::ostream &operator<<(std::ostream &os, const product &prod)
    {
        os << std::format("Weight: {}, Value: {}, Ratio: {}", prod.weight, prod.value, prod.ratio) << std::endl;

        return os;
    }
};

int64_t max(int64_t a, int64_t b) { return (a > b) ? a : b; }
int64_t knap_sack(int capacity, std::vector<product> &products, int n)
{
    int64_t dp[capacity + 1];
    memset(dp, 0, sizeof(dp));

    for (int i = 1; i < n + 1; i++)
    {
        for (int w = capacity; w >= 0; w--)
        {

            if (products[i - 1].weight <= w)

                // Finding the maximum value
                dp[w] = max(dp[w],
                            dp[w - products[i - 1].weight] + products[i - 1].value);
        }
    }
    // Returning the maximum value of knapsack
    return dp[capacity];
};

struct question
{
    question() : products_count(0),
                 our_capacity(0),
                 products()
    {
        {
            std::string _product, _capacity;
            std::cin >> _product;
            std::cin >> _capacity;

            products_count = std::stoll(_product);
            our_capacity = std::stoll(_capacity);
        }

        products.resize(products_count);
        std::sort(products.begin(), products.end());

        auto max_value = knap_sack(our_capacity, products, products.size());

        std::cout
            << max_value << '\n';
        log << "Max possible value: " << max_value << std::flush;
    }

    int64_t products_count;
    int64_t our_capacity;
    std::vector<product> products;
};

int main()
{
    log.open("cout.log", std::ios::out | std::ios::trunc);

    std::string waste;
    for (int i = 0;; ++i)
    {
        // do nothing until we find "Test "
        while (std::getline(std::cin, waste, '\n') && waste.rfind("Test ") != 0)
        {
            if (waste.rfind("Chief you got scammed") == 0)
            {
                log << "We got scammed, last test = " << i << std::flush;

                return 1;
            }
            log << waste << std::endl;
        }

        log << "Current test: " << i << std::endl;
        auto q = question();
    }

    return 0;
}
