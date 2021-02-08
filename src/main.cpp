#define CATCH_CONFIG_MAIN
#include "catch.hpp"
#include "Game.hpp"
#include <iostream>
#include <vector>

std::vector<Game*>* getGames(){
    std::vector<Game*> *games = new std::vector<Game*>;
    std::ifstream input ("./data/video_games.csv");

    if(!input.is_open()) throw std::runtime_error("File failed to open.");
    std::string line;
    std::string piece;
    if(input.good()){
        std::getline(input,line);
        while(std::getline(input,line,'\n')){
            std::stringstream ss(line);
            Game* temp = new Game();
            getline(ss, piece, ','); //name (title)
            temp->setName(piece); 
            getline(ss,piece,','); //handheld
            getline(ss,piece,','); //max players
            getline(ss,piece,','); //multiplatform
            getline(ss,piece,','); //online
            if(piece.find("True")){
                temp->setOnline(true);
            }else{
                temp->setOnline(false);
            }
            getline(ss,piece,','); //genre
            getline(ss,piece,','); //licensed
            getline(ss,piece,','); //publishers
            getline(ss,piece,','); //sequel
            getline(ss,piece,','); //review score
            getline(ss,piece,','); //sales
            temp->setSales(std::stod(piece)); //stod set string to double
            getline(ss,piece,','); //used price
            getline(ss,piece,','); //console
            temp->setConsole(piece);
            getline(ss,piece,','); //rating
            temp->setRating(piece[0]);
            getline(ss,piece,','); //rerelease
            getline(ss,piece,','); //release year
            temp->setReleaseYear(std::stoi(piece)); //stoi set string to int
            games->push_back(temp); //add temp to games
        }
    }
    return games;
}

TEST_CASE( "Testing...", "[all]" ) {
    std::vector<Game*> *games = getGames();
    REQUIRE( games->size() == 1114);
    Game* g = games->at(222);
    REQUIRE( g->getName() == "WWE SmackDown vs. Raw 2007" );
    g = games->at(235);
    REQUIRE( g->getName() == "Rockstar Games presents Table Tennis");
    REQUIRE( !g->getOnline());
    g = games->at(254);
    REQUIRE( g->getSales() == 0.23 );
    g = games->at(541);
    REQUIRE( g->getConsole() == "PlayStation 3");
    g = games->at(978);
    REQUIRE( g->getRating() == 'M');
    g = games->at(1113);
    REQUIRE( g->getName() == "Chicken Hunter");
    REQUIRE( g->getReleaseYear() == 2008);
    double value = 0;
    for(auto it=games->begin(); it!=games->end(); ++it){
        value += (*it)->getSales();
    }
    REQUIRE( value > 574.3);
    REQUIRE( value < 574.4);
}
