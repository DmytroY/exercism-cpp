#pragma once

#include <stdexcept>

namespace Bankaccount {

    // class Bankaccount
    class Bankaccount {
    private:
        int _balance{};
        bool _is_open{false};
        void ensure_open(){ if(!_is_open) throw std::runtime_error("Account is closed"); }
        void ensure_closed(){ if(_is_open) throw std::runtime_error("Account already opened"); }

    public:
        // Bankaccount(){ _balance = 0;}

        void open(){
            ensure_closed();
            _balance = 0;
            _is_open = true;}

        void close() {
            ensure_open();
            _is_open = false;}

        void deposit(int amt){
            ensure_open();
            _balance += amt;}

        void withdraw(int amt){
            ensure_open();
            if(amt > _balance) throw std::runtime_error("Cannot withdraw more than deposited");
            if(amt < 0) throw std::runtime_error("Cannot withdraw negative");
            _balance -= amt;}

        int balance() {
            ensure_open();
            return _balance;
        }
    };

}  // namespace Bankaccount
