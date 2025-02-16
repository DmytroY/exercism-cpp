// interest_rate returns the interest rate for the provided balance.
double interest_rate(double balance) {
    // 3.213% for a balance less than `0`
    // 0.5% equal to `0` and less than `1000`
    // 1.621% greater than or equal to `1000`  and less than `5000`
    // 2.475% greater than or equal to `5000`
    //interest_rate(200.75) => 0.5
    if (balance < 0) return 3.213;
    if (balance >= 0 && balance < 1000) return 0.5;
    if (balance >= 1000 && balance < 5000) return 1.621;
    return 2.475;
}

// yearly_interest calculates the yearly interest for the provided balance.
double yearly_interest(double balance) {
    // yearly_interest(200.75) => 1.003750
    return balance*interest_rate(balance)/100;
}

// annual_balance_update calculates the annual balance update, taking into
// account the interest rate.
double annual_balance_update(double balance) {
    // annual_balance_update(200.75) => 201.75375
    return balance + yearly_interest(balance);
}

// years_until_desired_balance calculates the minimum number of years required
// to reach the desired balance.
int years_until_desired_balance(double balance, double target_balance) {
    int years = 0;
    while(balance < target_balance){
        balance = annual_balance_update(balance);
        years++;
    }
    return years;
}