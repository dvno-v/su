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
    std::cout << "To end the program, please write 'end'. Thank you!\n You can use info to learn what commands you can use.\n";
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
        if (strcmp(t.tokens[0], "register") == 0) {
            core.register_user(t);
        }
        //else if (strcmp(t.tokens[0], "profile_info") == 0) {
        //    core.get_profile_info(t);
        //}
        //else if (strcmp(t.tokens[0], "finish") == 0) {
        //    core.finish_challenge(t);
        //}
        //else if (strcmp(t.tokens[0], "list_by") == 0) {
        //    core.list_challenge(t);
        //}
        //else if (strcmp(t.tokens[0], "load") == 0) {
        //    core.load_file(t);
        //}
        //else if (strcmp(t.tokens[0], "challenge") == 0) {
        //    core.challenge(t);
        //}
        t.delete_memory(); 
        std::cin.getline(_a, 101);
    }

    return 0;
}