
class BankAccount {
private:
	int balance; //帳號存款
	static int total; //銀行內總存款
public:
	BankAccount(); //建立帳號(無初始金額)
	BankAccount(int input); //建立帳號(有初始金額)
	void withdraw(int output); //取出現金
	void save(int input); //存入現金
	int getBalance(); //取得帳號存款
	static int getAllMoneyInBank(); //取得銀行內總存款
};