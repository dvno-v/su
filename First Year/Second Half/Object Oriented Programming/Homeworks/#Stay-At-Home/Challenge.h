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
    Challenge(/* args */);
    ~Challenge();
};





#endif //! CHALLENGE_H