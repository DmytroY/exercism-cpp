// INFO: Headers from the standard library should be inserted at the top via
// #include <LIBRARY_NAME>
#include <cmath>

// daily_rate calculates the daily rate given an hourly rate
double daily_rate(double hourly_rate) {
    return hourly_rate * 8.0;
}

// apply_discount calculates the price after a discount
double apply_discount(double before_discount, double discount) {
    return before_discount* (1 - discount/100);
}

// monthly_rate calculates the monthly rate, given an hourly rate and a discount
// The returned monthly rate is rounded up to the nearest integer.
int monthly_rate(double hourly_rate, double discount) {
    return static_cast<int>(std::ceil(22 * apply_discount(daily_rate(hourly_rate), discount)));
}

// days_in_budget calculates the number of workdays given a budget, hourly rate,
// and discount The returned number of days is rounded down (take the floor) to
// the next integer.
// days_in_budget(20'000, 80, 11.0) => 35
int days_in_budget(int budget, double hourly_rate, double discount) {
    double workday_rate = 8 * apply_discount(hourly_rate, discount);
    return static_cast<int>(floor(budget / workday_rate));
}