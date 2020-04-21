#include <iostream>

#include "Core.h"

int main() {
    char a[] = "pesho", b[] = "p@abv.bg", _a[101] = "gosho pesho tosho";
    /*User u(a, 10, b), c(a, 80, b), v(a, 10, b), n(a, 10, b), q(a, 10, b), m(a, b);
    u.print();
    c.print();
    v.print();
    n.print();
    q.print();
    m.print(); */
    Core core;
    std::cout << "To end the program, please write 'end'. Thank you!\n\tYou can use info to learn what commands you can use.\n";
    std::cin.getline(_a, 101);
    while (strcmp(_a, "end") != 0)
    {
        if (strcmp(_a, "info") == 0) {
            core.print_info_for_core();
            std::cin.getline(_a, 101);
            continue;
        }
        Tokens t;
        core.parse_input(_a, t);
        //to-do add console responses;
        //ready
        if (strcmp(t.tokens[0], "register") == 0) {
            core.register_user(t);
        }//ready to-do change appearance 
        else if (strcmp(t.tokens[0], "profile_info") == 0) {
            core.get_profile_info(t);
        }//ready //to-do change appearance 
        else if (strcmp(t.tokens[0], "print_all_users") == 0) {
            core.print_all_users();
        }//ready
        else if (strcmp(t.tokens[0], "finish") == 0) {
            core.finish_challenge(t);
        }//to-do
        else if (strcmp(t.tokens[0], "list_by") == 0) {
            core.list_challenge(t);
        }
        else if (strcmp(t.tokens[0], "load") == 0) {
            core.load_file(t);
        }//ready
        else if (strcmp(t.tokens[0], "challenge") == 0) {
            core.challenge(t);
        }
        t.delete_memory(); 
        std::cin.getline(_a, 101);
    }
    std::cout << "Thank you for using the CORE\n";
    return 0;
}