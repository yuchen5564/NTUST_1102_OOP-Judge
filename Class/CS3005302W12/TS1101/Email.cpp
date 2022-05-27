#include "Email.h"

Email::Email(string _text, string _sender, string _recipient, string _title):Document(_text)
{
	this->sender = _sender;
	this->recipient = _recipient;
	this->title = _title;
}

string Email::getSender()
{
	return this->sender;
}

string Email::getRecipient()
{
	return this->recipient;
}

string Email::getTitle()
{
	return this->title;
}
