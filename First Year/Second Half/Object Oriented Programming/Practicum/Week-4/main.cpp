#include <iostream>
#include "Dictionary.h"

int main() {

    Pair r1{ "computer", "Similar to air conditioners. Works fine until you open up windows." },
        r2{ "programmer", "A person who is paid to professionally scream at a computer." },
        r3{ "cofveve", "It literally means covfefe." },
        r4{ "server", "Person who takes your order and brings you food at a restaurant." },
        r5{ "Ubuntu", "Ubuntu is an ancient african word, meaning \"I can't configure Debian\"" },
        r6{ "chick", "The nicest way to refer to any female" };

    Pair recs[]{ r1, r2, r3, r4, r5 };

    Dictionary d(recs, sizeof(recs) / sizeof(Pair));

    d.print();

    d.remove("cofveve");

    d.print();

    d.add(r6);

    d.print();

    d.print_all_words_alphabetically();

    return 0;
}