#include "baddude.h"

int main() {
    std::srand(std::time(0));

    Person person("John", "Doe");
    Gunslinger gunslinger("Clint", "Eastwood", 0.35, 3);
    PokerPlayer pokerPlayer("James", "Bond");
    BadDude badDude("Jesse", "James", 0.28, 5);

    cout << "Person:" << endl;
    person.Show();
    cout << endl;

    cout << "Gunslinger:" << endl;
    gunslinger.Show();
    cout << endl;

    cout << "PokerPlayer:" << endl;
    pokerPlayer.Show();
    cout << endl;

    cout << "BadDude:" << endl;
    badDude.Show();
    cout << endl;

    return 0;
}
