#include <iostream>
#include <string>
#include "picosha2.h"


// 블록체인 채굴 간단하게 시뮬레이션.
// 간단하게 구현돼서 실제 블록체인과 틀린 부분이 많음.
// 해시 알고리즘은 PicoSHA2 SHA256 사용.

using namespace std;

int main() {
	int difficulty = 1; // 채굴의 난이도. 3이면 Hash가 000으로 시작해야 함.
	int tried_count = 0; // 채굴을 시도한 횟수. 12번을 했다면 12가 됨.
	int nonce = 0; // Nonce와 Data를 조합하여 Hash 생성.
	string data; // Nonce와 조합하여 hash 생성.
	string hash; // Hash 값.

	cin >> data; // hash 입력
	cin >> difficulty; // 난이도 입력

	for ( ; ;) {
		hash = picosha2::hash256_hex_string(to_string(nonce) + data); // Nonce와 Data를 조합하여 Hash 생성
		nonce += 1;
		tried_count += 1;
		if (hash.substr(0, difficulty) == string(difficulty, '0')) { // Hash값의 앞 난이도 만큼의 자리가 0일때
			cout << "채굴 완료\n";
			cout << "Nonce: " << nonce << "\n";
			cout << "시도 횟수: " << tried_count << "\n";
			break;
		}
	}
	
	return 0;
}