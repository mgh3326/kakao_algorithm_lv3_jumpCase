#include<iostream>
#include<vector>
using namespace std;
unsigned nChoosek(unsigned n, unsigned k)//�޺�׼� �Լ�
{
	if (k > n) return 0;
	if (k * 2 > n) k = n - k;
	if (k == 0) return 1;

	int result = n;
	for (int i = 2; i <= k; ++i) {
		result *= (n - i + 1);
		result /= i;
	}
	return result;
}
int count_num(const vector<int>& v, const int num)
{
	int res=0;
	for (unsigned int i = 0; i<v.size(); i++)
	{
		if (v[i] == num)
			res++;
	}
	return res;
}
int jumpCase(int n)
{
	int answer = 0;
	vector<int> v;
	for(int i=0;i<n;i++)
	{
		v.push_back(1);
	}
	for (int i : v)
	{
		cout << "("<<i<<")";
	}
	cout << endl;
	//answer++;
	cout << count_num(v, 1) << endl;
	int index = 0;
	while (true)
	{
		
		cout <<(answer+= nChoosek(v.size(), count_num(v, 1))) << endl;
		if (v.back() == 2)
			break;
		else if (v.back() == 1)
		{
			v.pop_back();
			if (index == v.size())
				break;
			v[index++]++;
		}
		
	}
	return answer;
}
int main()//1�̸� 1, 2�� 1,1 2 2�� 3�̸�, 1,1,1 1,2 2,1 3��
//4���� 1,1,1,1 2,1,1 1,2,1 1,1,2 2,2 5��
//5���� 1,1,1,1,1 2,1,1,1 1,
//1+ (n-1) + 
{
	int test = 4;

	//�Ʒ��� �׽�Ʈ�� ����� ���� ���� �ڵ��Դϴ�.
	cout << jumpCase(test);
}

//
//ȿ���̴� �ָ� �ٱ⸦ �����ϰ� �ֽ��ϴ�.ȿ���̴� �ѹ��� 1ĭ, �Ǵ� 2ĭ�� �� �� �ֽ��ϴ�.
//ĭ�� �� 4�� ���� ��, ȿ���̴�
//(1ĭ, 1ĭ, 1ĭ, 1ĭ)
//(1ĭ, 2ĭ, 1ĭ)
//(1ĭ, 1ĭ, 2ĭ)
//(2ĭ, 1ĭ, 1ĭ)
//(2ĭ, 2ĭ)
//�� 5���� ������� �� �� ĭ�� ������ �� �ֽ��ϴ�.�ָ��ٱ⿡ ���� ĭ�� �� n�� �־��� ��,
// ȿ���̰� ���� �����ϴ� ����� �� �������� ����ϴ� jumpCase �Լ��� �ϼ��ϼ���.
//���� ��� 4�� �Էµȴٸ�, 5�� ��ȯ�� �ָ� �˴ϴ�.