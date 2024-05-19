#include <map>
#include <chrono>
#include <thread>
#include <limits>
#include <fcntl.h>
#include <io.h>
#include <vector>
#include <string>
#include <iostream>
#include "defines.hpp"
// Basit bir banka uygulaması

int main() {
	_setmode(_fileno(stdout), _O_U16TEXT);
	_setmode(_fileno(stdin), _O_U16TEXT);
	bool main_loop_condition = true;
	std::wstring entry_choice = L"";
	Bank::UserInfo user_info;
	user_info.user_account_name = L"Test1234";
	user_info.user_name = L"Test1234";
	user_info.user_surname = L"Test1234";
	user_info.user_pwd = L"Test1234";
	user_info.user_balance = 99999;
	std::vector<Bank::UserInfo> database { user_info };
	std::wcout << L"Hoşgeldiniz lütfen hesap adınızı giriniz eğer hesap adınız yoksa 2 yazarak yeni bir hesap oluşturunuz çıkmak içinde 3'e yazınız" << std::endl;

	do {
		std::wcout << L"Banka:Ana menü giriş : > ";
		std::getline(std::wcin,entry_choice);
		if (entry_choice.size() > 7)
			if (Bank::is_exist_user(entry_choice,database)) {
				bool is_logged_in = false;
				std::wstring temp_pwd = L"";
				Bank::UserInfo user_inf = Bank::extract_personal_credentias(database,entry_choice);
				for (int i = 0;i<3;++i) {
					std::wcout << L"Şifreyi giriniz:" << i << " ";
					std::getline(std::wcin,temp_pwd);
					if (temp_pwd == Bank::extract_personal_credentials(database,entry_choice).user_pwd) {
						is_logged_in = true;
						break;
					}
				}
				if (is_logged_in) {
					std::wcout << L"Başarılı giriş !! " << std::endl;
					Bank::bank_main_menu(user_inf);
				} else {
					std::wcout << L"Hatalı giriş !! " << std::endl;
				}
				continue;
			} else if (entry_choice.size() < 7) {
				std::wcout << L"Yetersiz hesap adı uzunluğu en az 7 ve en fazla 10 uzunlukta olmalıdır !!" << std::endl;
			}
			
		if (!Bank::is_digit(entry_choice) && Bank::convert_to_int(entry_choice) < 1 || Bank::convert_to_int(entry_choice) > 6) {
			std::wcout << L"Lütfen geçerli bir seçenek giriniz" << std::endl;
		} else { 
			switch (Bank::convert_to_int(entry_choice)) {
				case 1:
					break;
				default:
					break;
			}
		}
	} while(main_loop_condition);
}