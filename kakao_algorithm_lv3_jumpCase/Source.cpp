#include<iostream>
#include<vector>
using namespace std;
unsigned nChoosek(unsigned n, unsigned k)//콤비네션 함수
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
int main()//1이면 1, 2면 1,1 2 2개 3이면, 1,1,1 1,2 2,1 3개
//4개면 1,1,1,1 2,1,1 1,2,1 1,1,2 2,2 5개
//5개면 1,1,1,1,1 2,1,1,1 1,
//1+ (n-1) + 
{
	int test = 4;

	//아래는 테스트로 출력해 보기 위한 코드입니다.
	cout << jumpCase(test);
}

//
//효진이는 멀리 뛰기를 연습하고 있습니다.효진이는 한번에 1칸, 또는 2칸을 뛸 수 있습니다.
//칸이 총 4개 있을 때, 효진이는
//(1칸, 1칸, 1칸, 1칸)
//(1칸, 2칸, 1칸)
//(1칸, 1칸, 2칸)
//(2칸, 1칸, 1칸)
//(2칸, 2칸)
//의 5가지 방법으로 맨 끝 칸에 도달할 수 있습니다.멀리뛰기에 사용될 칸의 수 n이 주어질 때,
// 효진이가 끝에 도달하는 방법이 몇 가지인지 출력하는 jumpCase 함수를 완성하세요.
//예를 들어 4가 입력된다면, 5를 반환해 주면 됩니다.