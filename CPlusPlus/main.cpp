#include <iostream>
#include <string>
#include "picosha2.h"


// ���ü�� ä�� �����ϰ� �ùķ��̼�.
// �����ϰ� �����ż� ���� ���ü�ΰ� Ʋ�� �κ��� ����.
// �ؽ� �˰����� PicoSHA2 SHA256 ���.

using namespace std;

int main() {
	int difficulty = 1; // ä���� ���̵�. 3�̸� Hash�� 000���� �����ؾ� ��.
	int tried_count = 0; // ä���� �õ��� Ƚ��. 12���� �ߴٸ� 12�� ��.
	int nonce = 0; // Nonce�� Data�� �����Ͽ� Hash ����.
	string data; // Nonce�� �����Ͽ� hash ����.
	string hash; // Hash ��.

	cin >> data; // hash �Է�
	cin >> difficulty; // ���̵� �Է�

	for ( ; ;) {
		hash = picosha2::hash256_hex_string(to_string(nonce) + data); // Nonce�� Data�� �����Ͽ� Hash ����
		nonce += 1;
		tried_count += 1;
		if (hash.substr(0, difficulty) == string(difficulty, '0')) { // Hash���� �� ���̵� ��ŭ�� �ڸ��� 0�϶�
			cout << "ä�� �Ϸ�\n";
			cout << "Nonce: " << nonce << "\n";
			cout << "�õ� Ƚ��: " << tried_count << "\n";
			break;
		}
	}
	
	return 0;
}