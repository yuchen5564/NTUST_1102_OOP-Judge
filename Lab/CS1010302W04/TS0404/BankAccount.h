
class BankAccount {
private:
	int balance; //�b���s��
	static int total; //�Ȧ椺�`�s��
public:
	BankAccount(); //�إ߱b��(�L��l���B)
	BankAccount(int input); //�إ߱b��(����l���B)
	void withdraw(int output); //���X�{��
	void save(int input); //�s�J�{��
	int getBalance(); //���o�b���s��
	static int getAllMoneyInBank(); //���o�Ȧ椺�`�s��
};