
#include "Contact.hpp"

Contact::Contact( void ) {
}

std::string Contact::formattedColumn(std::string content) const {
	char result[11];

	content.copy(result, 9, 0);
	result[9] = '.';
	result[10] = '\0';
	return result;
}

std::string Contact::getFirstName (int listing) const {
	if (listing == 1 && this->_first_name.length() > 10) {
		return this->formattedColumn(this->_first_name);
	}
	return this->_first_name;
}

std::string Contact::getLastName (int listing) const {
	if (listing == 1 && this->_last_name.length() > 10) {
		return this->formattedColumn(this->_last_name);
	}
	return this->_last_name;
}

std::string Contact::getNickName (int listing) const {
	if (listing == 1 && this->_nickname.length() > 10) {
		return this->formattedColumn(this->_nickname);
	}
	return this->_nickname;
}

std::string Contact::getLogin (void) const {
	return this->_login;
}

std::string Contact::getPostalAdress (void) const {
	return this->_postal_adress;
}

std::string Contact::getEmailAdress (void) const {
	return this->_email_adress;
}

std::string Contact::getPhoneNumber (void) const {
	return this->_phone_number;
}

std::string Contact::getBirthdayDate (void) const {
	return this->_birthday_date;
}

std::string Contact::getFavoriteMeal (void) const {
	return this->_favorite_meal;
}

std::string Contact::getUnderwearColor (void) const {
	return this->_underwear_color;
}

std::string Contact::getDarkestSecret (void) const {
	return this->_darkest_secret;
}

void Contact::setFirstName (std::string first_name) {
	this->_first_name = first_name;
}

void Contact::setLastName (std::string last_name) {
	this->_last_name = last_name;
}

void Contact::setNickName (std::string nickname) {
	this->_nickname = nickname;
}

void Contact::setLogin (std::string login) {
	this->_login = login;
}

void Contact::setPostalAdress (std::string postal_adress) {
	this->_postal_adress = postal_adress;
}

void Contact::setEmailAdress (std::string email_adress) {
	this->_email_adress = email_adress;
}

void Contact::setPhoneNumber (std::string phone_number) {
	this->_phone_number = phone_number;
}

void Contact::setBirthdayDate (std::string birthday_date) {
	this->_birthday_date = birthday_date;
}

void Contact::setFavoriteMeal (std::string favorite_meal) {
	this->_favorite_meal = favorite_meal;
}

void Contact::setUnderwearColor (std::string underwear_color) {
	this->_underwear_color = underwear_color;
}

void Contact::setDarkestSecret (std::string darkest_secret) {
	this->_darkest_secret = darkest_secret;
}
