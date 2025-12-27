/*

Вам предоставлен журнал посещений магазина, представленный в виде строки с индексацией от 0customers, состоящей только из символов 'N' и 'Y':

если ith символ равен 'Y', это означает, что клиенты приходят в ith час
тогда как 'N' указывает на то, что клиенты не приходят в ith час.
Если магазин закрывается в jth час (0 <= j <= n), то штраф рассчитывается следующим образом:

За каждый час, когда магазин открыт, но покупателей нет, штраф увеличивается на 1.
За каждый час, когда магазин закрыт, но приходят покупатели, штраф увеличивается на 1.
Вернитесь к самому раннему часу, в который магазин должен быть закрыт, чтобы получить минимальный штраф.

Обратите внимание, что если магазин закрывается в jth час, это означает, что магазин закрыт в j час.

*/





#include <iostream>
#include <string>

class Solution {
public:
    int bestClosingTime(std::string customers) {
        bool closed {false};
        int closedHours{0};
        int penalty {0};
        int index {0};
        int penaltyMin {static_cast<int>(customers.size())};

        for(int i=0; i<=customers.size(); ++i, closed = false) {
            for(int j=0; j<=customers.size(); ++j) {
                if (closedHours <= j) {
                    closed = true;
                }
                if ((customers[j] == 'Y' and closed) or (customers[j] == 'N' and !closed)) {
                    penalty+=1;
                }
            }
            closedHours++;
            if(penaltyMin > penalty) {
                penaltyMin = penalty;
                index = i;

            }
            penalty = 0;
        }
        return index;    
    }
};



// YYNY



int main() {

    Solution test;
    std::cout << "Test1: " << test.bestClosingTime("YYNY") << '\n'; // 2
    std::cout << "Test2: " << test.bestClosingTime("NNNNN") << '\n'; // 0
    std::cout << "Test3: " << test.bestClosingTime("YYYY") << '\n'; // 4
    std::cout << "Test4: " << test.bestClosingTime("YNNN") << '\n'; // 1
    std::cout << "Test5: " << test.bestClosingTime("NNYNYNY") << '\n'; // 0
    std::cout << "Test6: " << test.bestClosingTime("NNNNNNNNNNNNNNNNNNNN") << '\n'; // 0
    std::cout << "Test7: " << test.bestClosingTime("YYYYYYYYYYYYYYYYYYYYYYYYY") << '\n'; // 25
    std::cout << "Test8: " << test.bestClosingTime("YNYNYNYNYNYNYNYNYNYNYNYNYNYNYNYNYNYNYNYN") << '\n'; // 1


    return 0;
}