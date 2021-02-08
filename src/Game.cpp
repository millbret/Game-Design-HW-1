// COMPETE ME
#include "Game.hpp"

Game::Game(){
}

std::string Game::getName() {
	return this->title;
}

void Game::setName(std::string title){
    this->title = title;
}

bool Game::getOnline() {
	return this->online;
}

void Game::setOnline(bool online) {
	this->online = online;
}

double Game::getSales() {
	return this->sales;
}

void Game::setSales(double sales) {
	this->sales = sales;
}

std::string Game::getConsole() {
	return this->console;
}

void Game::setConsole(std::string console) {
	this->console = console;
}

char Game::getRating() {
	return this->rating;
}

void Game::setRating(char rating) {
	this->rating = rating;
}

int Game::getReleaseYear() {
	return this->release_year;
}

void Game::setReleaseYear(int release_year) {
	this->release_year = release_year;
}
