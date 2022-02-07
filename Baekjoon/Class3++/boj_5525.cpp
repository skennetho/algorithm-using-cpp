//https://www.acmicpc.net/problem/5525
// IOIOI
#include <iostream>
#include <string>

using namespace std;

#define INIT_COUNT 0;

void countIOIandUpdateResult(const string& s, const int& n, int& result) {
    bool begin;
    int count = INIT_COUNT;
    for (int i = 0; i < s.size() - 1; i++){
        if (s[i] == 'I') {
            if (s[i + 1] == 'I') {
                count = INIT_COUNT;
                continue;
            }
            while (s[i + 1] == 'O' && s[i + 2] == 'I') {
                i += 2;
                count++;
            } 
            if (count >= n) {
                result += count - n + 1;
            }
            count = INIT_COUNT;
        }
    }
}

int main() {
    int n, sLength; 
    string s;

    cin >> n >> sLength;
    cin >> s;

    int result = 0;
    countIOIandUpdateResult(s, n, result);

    cout << result << '\n';
}

/**
 * Ǯ��
 * P1�� P2�� 2�� ����ִ�.
 * ���� ��ġ�� Pn�� Px�� x-n+1�� ����ִ�. 
 * 
 * IOI�Ǻ���-1
 * �׷� ���ڿ��� ������ "IO"�� �������� ���ö� ��(x)�� �������� ����
 *  "II" ������ Px, "O"�� ������ Px-1�� �Ǵ��Ѵ�.
 * 
 * IOI�Ǻ���-2
 * ���ڿ����� I�� �����ϴ� ��ġ�� ã�´�.
 * I�� �����ϴ� ��ġ���� ������ �ٴ����� O,I��� count++�� �Ѵ�.
 * ���� ��ġ�� ����-2���� ũ�ٸ� count�� �׸��Ѵ�.
 * 
 * �⺻ 0���� �����ϴ� result������
 * Px (x>0)�� ���´ٸ� x-n+1�� ���Ѵ�.
 * Px (x==0)�� ���´ٸ� �Ѿ��.
 * 
 * �������� result�� ����Ѵ�.
 * 
 * 
 * 
 * I > IO, II > IOI, IOO, III, IIO
 *               ^
 * O > OI, OO > OII, OIO, OOI, OOO > OIII, OIIO, OIOI, OIOO, OOII, OOIO, OOOI, OOOO
 *                                                ^
 * 
 * I�� ������ ��ġ�� ã�� OI�� �ݺ��Ǵ� ���� ī��Ʈ �ϴ°� ���� ���?
 * �׷� ������ �Ʒ��� ����?
 * �ϳ��� ������ Ȯ���Ѵ�.
 * - I��� ����
 *   - �״����� �ٴ����� OI��� count++, 
 *      - ������ ��ġ�� OI�� �����ķ� �̵�
 *   - I��� ��ġ�� ��������
 *   - ���Ѵ� �ƴ϶�� result ������Ʈ,
 * - O��� �о�
 * 
 * 2
25
OOIOIIOIOIOIOIOIOIOIOOIOI
     ^ ^ ^ ^ ^ ^ 
=> 6
 */