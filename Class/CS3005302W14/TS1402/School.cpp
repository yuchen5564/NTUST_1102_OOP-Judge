#include "School.h"

//constructors
School::School(string _name, int _amount)
{
	name = _name;
	studentAmount = _amount;
	studentAmountNextYear = _amount;
}

//�W�[�ǥ�
void School::admissions(int amount)
{
	if (amount > 0) studentAmount += amount; //�L�o��J�p��0
}

//��־ǥ�
void School::dropouts(int amount)
{
	if (studentAmount >= amount && amount > 0) studentAmount -= amount; //�L�o��J�p��0 && ��J�j��ثe�`��
}

//���
void School::transfer(int amount, School& toSchool)
{
	dropouts(amount); //�ثe�մ��
	toSchool.admissions(amount); //�ؼЮռW�[
}

//formate output
ostream& operator<<(ostream& output, const School& s)
{
	output << s.name << "\t" << s.studentAmount << "\t" << s.studentAmountNextYear;
	return output;
}

//constructors
PrivateSchool::PrivateSchool(string _name, int _amount)
{
	name = _name;
	studentAmount = _amount;
	studentAmountNextYear = _amount;
	dropoutsCounter = 0;
}

//������־ǥ�
void PrivateSchool::dropouts(int amount)
{
	if (studentAmount >= amount && amount > 0) {	//�L�o��J�p��0 && ��J�j��ثe�`��
		if (dropoutsCounter == 0) dropoutsCounter = 1; //�W�L�@������־ǥ�-->�խ����~�W�B
		else studentAmountNextYear -= 100;
		studentAmount -= amount;
	}
}

//constructors
PublicSchool::PublicSchool(string _name, int _amount)
{
	name = _name;
	studentAmount = _amount;
	studentAmountNextYear = _amount;
	growth_rate = 0.05;
}

//�P�N�W�[�ۦ�
void PublicSchool::apply_growth()
{
	studentAmountNextYear += growth_rate * studentAmountNextYear;
}

//������־ǥ�
void PublicSchool::dropouts(int amount)
{
	if (studentAmount >= amount && amount > 0) { //�L�o��J�p��0 && ��J�j��ثe�`��
		if (amount > 100) studentAmountNextYear = studentAmountNextYear * 0.95; //�@����ֶW�L100�H-->�խ����~�ۦ��ǥ�
		studentAmount -= amount;
	}
}
