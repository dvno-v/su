#ifndef CHALLENGE_H

#define CHALLENGE_H

class Challenge
{
private:
    double rating;
    unsigned times_called;
    char* name;
    char* status;
    
    void update_rating(double);
    void del_memory(char const *);
    char* copy_memory(char const *);
public:
    Challenge();
    ~Challenge();
    void finish_challenge();
};





#endif //! CHALLENGE_H