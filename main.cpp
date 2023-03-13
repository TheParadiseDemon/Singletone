#include <bits/stdc++.h>

struct Transaction{
private:
    std::pair<std::chrono::year_month_day, std::chrono::hh_mm_ss<std::chrono::seconds>> date_time;
    float amount;
    float reminder;
public:
    void SetTime(std::pair<std::chrono::year_month_day, std::chrono::hh_mm_ss<std::chrono::seconds>> newtime){
        date_time = newtime;
    }

    std::pair<std::chrono::year_month_day, std::chrono::hh_mm_ss<std::chrono::seconds>> GetTime(){
        return date_time;
    }
};

struct User{
private:
    std::vector<Transaction> transactions;
    float total_reminder;
    int code;
public:
    std::vector<Transaction> GetTransactions(){
        return transactions;
    }

    int GetCode(){
        return code;
    }
};

class Singleton
{
private:
    Singleton() = default;
    Singleton( const Singleton&);
    Singleton& operator=( Singleton&);
    std::vector<User> users;
public:
    static Singleton& getInstance() {
        static Singleton  instance;
        return instance;
    }

    std::vector<User> GetUsers(){
        return users;
    }

    void AddFromFile(const std::string& filename){
        std::ifstream input (filename);
        if (!input.is_open()){
            std::cout << "File couldn't be opened!\n";
            return;
        }

        unsigned int number;
        input >> number;

        for (auto i = 0; i < number; ++i){
            unsigned int year, month, day, hours, minutes, seconds;
            int user_code;
            float amount;
            input >> year >> month >> day >> hours >> minutes >> seconds >> user_code >> amount;
           //date_time = std::make_pair(std::chrono::year_month_day(year, month, day), )

        }

        input.close();
    }

    User FindUserInfo(int code){
        auto it = std::find_if(users.begin(), users.end(),
                               [code](User a){
            return a.GetCode() == code;
        });
        if (it == users.end()) {
            std::cout << "No user with this code was found";
            return {};
        }
        else
            return users[it - users.begin()];
    }
};

int main() {

    Singleton& s = Singleton::getInstance();

    return 0;
}
