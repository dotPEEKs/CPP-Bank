#include <string>
#include <algorithm>
// This file for helpers defines and variables

#define json_file_name "data.json"
namespace Bank {
	enum entry_choices : int {
		entry_choice_bank_add_money = 1,
		entry_choice_bank_withdraw_money = 2,
		entry_choice_bank_control_balance = 3,
		entry_choice_create_new_bank_account = 4,
		entry_choice_delete_existing_bank_account = 5,
		entry_choice_exit = 6
	};

	struct UserInfo {
		std::wstring user_account_name = L"";
		std::wstring user_name = L"";
		std::wstring user_surname = L"";
		std::wstring user_pwd = L"";
		int user_balance = 0;
	};
	template<typename T>
		bool is_digit(T& in) {
			bool isdigit = true;
			for (char ch : in) {
				if ((int) ch < 48 || (int) ch > 57) {
					isdigit = false;
				}
			}
			return isdigit;
		}

	template<typename T>
	int convert_to_int(T& in) {
		try {
			return std::stoi(in);
		} catch (...) {
			return -1;
		}
	}
	bool add_money(Bank::UserInfo& input) {
		std::wcout << "Veri giriniz: ";
		return true;
	}
	bool is_exist_user(std::wstring& account_name,std::vector<Bank::UserInfo>& db) {
		for (const auto& user_struct : db) {
			if (user_struct.user_account_name == account_name) {
				return true;
				break;
			}
		}
		return false;
	}
	UserInfo extract_personal_credentials(std::vector<UserInfo>& db ,std::wstring& user_account_name) {
		UserInfo empty_struct;
		for (const auto& personal_struct : db ) {
			if (personal_struct.user_account_name == user_account_name) {
				return personal_struct;
			}
		}
		return empty_struct;
	}
	bool bank_main_menu(UserInfo& usr_info) {
		std::wstring choice = L"";
		bool loop = true;
		do {
			std::wcout << L"> ";
			std::getline(std::wcin,choice);
			if (choice == L"exit" ) {
				loop = false;
			}
		} while(loop);
		return loop;
	}
}