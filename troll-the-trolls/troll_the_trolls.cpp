namespace hellmath {

    enum class AccountStatus {
        troll,
        guest,
        user,
        mod
    };

    enum class Action {
        read,
        write,
        remove
    };

    bool display_post(AccountStatus poster, AccountStatus viewer){
        if (poster != AccountStatus::troll) return true;
        if (poster == AccountStatus::troll && viewer == AccountStatus::troll) return true;
        return false;
    }


    // TODO: Task 3 - Implement the `permission_check` function, that takes an
    // `Action` as a first argument and an `AccountStatus` to check against. It
    // should return a `bool`.
    //
    // guest: read
    // troll: read, write
    // user:  read, write
    // mod:   read, write, remove
    //
    //permission_check(Action::remove, AccountStatus::guest) => false
    // permission_check(Action::write, AccountStatus::mod) => true

    bool permission_check(Action action, AccountStatus account) {
        switch (action) {
            case Action::read:
                return true;
            case Action::write:
                if (account != AccountStatus::guest) return true;
                return false;
            default:
                if (account == AccountStatus::mod) return true;
                return false;
        }
        // if (action == Action::read) return true;
        // if (account == AccountStatus::mod) return true;
        // if (action == Action::remove) return false;
        // if (account == AccountStatus::guest) return false;
        // return true;
    }

    // TODO: Task 4 - Implement the `valid_player_combination` function that
    // checks if two players can join the same game. The function has two parameters
    // of type `AccountStatus` and returns a `bool`.
    //         guest  troll  user   mod
    // guest:    0      0     0      0
    // troll:    0      1     0      0
    // user:     0      0     1      1
    // mod:      0      0     1      1
    bool valid_player_combination(AccountStatus player1, AccountStatus player2) {
        switch (player1) {
            case AccountStatus::guest:
                return false;
            case AccountStatus::troll:
                if (player2 == AccountStatus::troll) return true;
                return false;
            default:
                if (player2 == AccountStatus::user || player2 == AccountStatus::mod) return true;
                return false;
        }

        // if (player1 == AccountStatus::guest || player2 == AccountStatus::guest) return false;
        // if (player1 == player2) return true;
        // if (player1 == AccountStatus::troll || player2 == AccountStatus::troll) return false;
        // return true;
    }


    // TODO: Task 5 - Implement the `has_priority` function that takes two
    // `AccountStatus` arguments and returns `true`, if and only if the first
    // account has a strictly higher priority than the second.
    bool has_priority(AccountStatus player1, AccountStatus player2) {
        return player1 > player2;
    }
}  // namespace hellmath