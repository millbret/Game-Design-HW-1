//COMPLETE ME
#ifndef     __HPP__Game__
#define     __HPP__Game__

#include <string>

class Game{

    public:
        Game();
        ~Game();

        std::string getName();
        bool getOnline();
        double getSales();
        std::string getConsole();
        char getRating();
        int getReleaseYear();
        
        void setName(std::string name);
        void setOnline(bool online);
        void setSales(double sales);
        void setConsole(std::string console);
        void setRating(char rating);
        void setReleaseYear(int release_year);


    private:
        std::string title;
        bool online;
        double sales;
        std::string console;
        char rating;
        int release_year;

};
#endif