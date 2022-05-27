#include "Document.h"

Document::Document(const char* _text)
{
	this->text = _text;
}

Document::Document(string _text)
{
	this->text = _text;
}

Document& Document::operator=(Document* in)
{
	this->text = in->text;
	return *this;
}

const string Document::getText() const{
	return text;
}
