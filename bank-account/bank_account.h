#pragma once

#include <stdexcept>
#include <mutex>

namespace Bankaccount {

    inline std::mutex mtx;

    // class Bankaccount
    class Bankaccount {
    private:
        int _balance{};
        bool _is_open{};
        void ensure_open(){ if(!_is_open) throw std::runtime_error("Account is closed"); }
        void ensure_closed(){ if(_is_open) throw std::runtime_error("Account already opened"); }

    public:
        Bankaccount(){
            _balance = 0;
            _is_open = false;
        }

        void open(){
            ensure_closed();
            _balance = 0;
            _is_open = true;
        }

        void close() {
            ensure_open();
            _is_open = false;
        }

        void deposit(int amt){
            ensure_open();
            if(amt < 0) throw std::runtime_error("Cannot deposite negative");
            mtx.lock();
            _balance += amt;
            mtx.unlock();
        }

        void withdraw(int amt){
            ensure_open();
            if(amt > _balance) throw std::runtime_error("Cannot withdraw more than deposited");
            if(amt < 0) throw std::runtime_error("Cannot withdraw negative");
            mtx.lock();
            _balance -= amt;
            mtx.unlock();
        }

        int balance() {
            ensure_open();
            return _balance;
        }
    };

}  // namespace Bankaccount
