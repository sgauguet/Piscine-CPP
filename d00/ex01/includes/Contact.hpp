#ifndef CONTACT_H
#define CONTACT_H

#include <string>
#include <iostream>

class Contact {

public: 

	Contact(void);

	std::string formattedColumn(std::string content) const;

	// Getters
	std::string getFirstName (int listing = 0) const;
	std::string getLastName (int listing = 0) const;
	std::string getNickName (int listing = 0) const;
	std::string getLogin (void ) const;
	std::string getPostalAdress (void ) const;
	std::string getEmailAdress (void ) const;
	std::string getPhoneNumber (void ) const;
	std::string getBirthdayDate (void ) const;
	std::string getFavoriteMeal (void ) const;
	std::string getUnderwearColor (void ) const;
	std::string getDarkestSecret (void ) const;

	//Setters
	void setFirstName (std::string first_name);
	void setLastName (std::string last_name);
	void setNickName (std::string nickname);
	void setLogin (std::string login);
	void setPostalAdress (std::string postal_adress);
	void setEmailAdress (std::string email_adress);
	void setPhoneNumber (std::string phone_number);
	void setBirthdayDate (std::string birthday_date);
	void setFavoriteMeal (std::string favorite_meal);
	void setUnderwearColor (std::string underwear_color);
	void setDarkestSecret (std::string darkest_secret);

private:

	std::string _first_name;
	std::string _last_name;
	std::string _nickname;
	std::string _login;
	std::string _postal_adress;
	std::string _email_adress;
	std::string _phone_number;
	std::string _birthday_date;
	std::string _favorite_meal;
	std::string _underwear_color;
	std::string _darkest_secret;

};
 
#endif