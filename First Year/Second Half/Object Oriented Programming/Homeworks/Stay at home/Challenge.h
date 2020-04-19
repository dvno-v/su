#ifndef CHALLENGE_H

#define CHALLENGE_H

class Challenge
{
private:
    double rating;
    char* name;
    char* status;
    unsigned times_called;

    void del_challenge_memory(char const*);
    char* copy_challenge_memory(char const*);

public:
    Challenge();
    Challenge(const char*);
    Challenge(const Challenge&);
    Challenge(const char*, unsigned, double);
    ~Challenge();

    const char* get_challenge_name() const;

    void update_rating(double);
    void update_status();
};





#endif //! CHALLENGE_H