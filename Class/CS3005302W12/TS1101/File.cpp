#include "File.h"

File::File(string _text, string _path):Document(_text)
{
	this->path = _path;
}

//File& File::operator=(File f1)
//{
//	this->path = f1.path;
//	this->text = f1.text;
//	return *this;
//}

void File::setPathname(string _path)
{
	this->path = _path;
}

string File::getPathname()
{
	return this->path;
}
