/**
 * ��ϰ������������Ƚ��ң������Ͱ��˼·��û�м����ԣ�
 * ��Ҳ�����������⣬���˺ܳ�ʱ�䡣
 **/

#include <Windows.h>
#include <DirectXMath.h>
#include <DirectXPackedVector.h>
#include <iostream>
#include <vector>
using namespace std;
using namespace DirectX;
using namespace DirectX::PackedVector;

ostream& XM_CALLCONV operator<<(ostream& os, FXMVECTOR v)
{
	XMFLOAT4 dest;
	XMStoreFloat4(&dest, v);

	cout << "(" << dest.x << ", " << dest.y << ", "
		<< dest.z << ", " << dest.w << ")";
	return os;
}

ostream& XM_CALLCONV operator<<(ostream& os, FXMMATRIX m)
{
	for (int i = 0; i < 4; ++i) {
		os << XMVectorGetX(m.r[i]) << "\t";
		os << XMVectorGetY(m.r[i]) << "\t";
		os << XMVectorGetZ(m.r[i]) << "\t";
		os << XMVectorGetW(m.r[i]) << endl;
	}
	return os;
}

void p1()
{
	XMMATRIX A(-2.0f, 0.0f, 0.0f, 0.0f,
			   1.0f, 3.0f, 0.0f, 0.0f,
			   0.0f, 0.0f, 0.0f, 0.0f,
			   0.0f, 0.0f, 0.0f, 0.0f);
	XMMATRIX X = 1 / 2.0 * (A - 2 / 3.0 * A);
	cout << "X = " << endl << X << endl;
}

void p2()
{
	XMMATRIX aA(-2.0f, 0.0f, 3.0f, 0.0f,
			   4.0f, 1.0f, -1.0f, 0.0f,
			   0.0f, 0.0f, 0.0f, 0.0f,
			   0.0f, 0.0f, 0.0f, 0.0f);
	XMMATRIX aB(2.0f, -1.0f, 0.0f, 0.0f,
			   0.0f, 6.0f, 0.0f, 0.0f,
			   2.0f, -3.0f, 0.0f, 0.0f,
			   0.0f, 0.0f, 0.0f, 0.0f);
	cout << "a. A * B = " << endl << aA * aB << endl;

	XMMATRIX bA(1.0f, 2.0f, 0.0f, 0.0f,
				3.0f, 4.0f, 0.0f, 0.0f,
				0.0f, 0.0f, 0.0f, 0.0f,
				0.0f, 0.0f, 0.0f, 0.0f);
	XMMATRIX bB(-2.0f, 0.0f, 0.0f, 0.0f,
				1.0f, 1.0f, 0.0f, 0.0f,
				0.0f, 0.0f, 0.0f, 0.0f,
				0.0f, 0.0f, 0.0f, 0.0f);
	cout << "b. A * B = " << endl << bA * bB << endl;

	XMMATRIX cA(2.0f, 0.0f, 2.0f, 0.0f,
				0.0f, -1.0f, -3.0f, 0.0f,
				0.0f, 0.0f, 1.0f, 0.0f,
				0.0f, 0.0f, 0.0f, 0.0f);
	XMMATRIX cB(1.0f, 0.0f, 0.0f, 0.0f,
				2.0f, 0.0f, 0.0f, 0.0f,
				1.0f, 0.0f, 0.0f, 0.0f,
				0.0f, 0.0f, 0.0f, 0.0f);
	cout << "c. A * B = " << endl << cA * cB << endl;
}

void p8()
{
	XMMATRIX A(2.0f, 0.0f, 1.0f, 0.0f,
				0.0f, -1.0f, -3.0f, 0.0f,
				0.0f, 0.0f, 1.0f, 0.0f,
				0.0f, 0.0f, 0.0f, 0.0f);
	XMMATRIX B(0.5f, 0.0f, -0.5f, 0.0f,
			   0.0f, -1.0f, -3.0f, 0.0f,
			   0.0f, 0.0f, 1.0f, 0.0f,
			   0.0f, 0.0f, 0.0f, .0f);
	XMMATRIX C = A * B;
	cout << "C = A * B = " << endl << C << endl;
	//C��3�׾��󣬹�B��A�������
}
//18.��ת�þ���
void transpose(vector<vector<double>> source, vector<vector<double>> &dest)
{
	dest = source;
	for (int i = 0; i < dest.size(); ++i) {
		for (int j = i + 1; j < dest.size(); ++j) {
			double temp = dest[i][j];
			dest[i][j] = dest[j][i];
			dest[j][i] = temp;
		}
	}
}
//19.����������ʽ
double determinant(vector<vector<double>> a)
{
	//�������n�׾���
	if (a.size() != a[0].size()) {
		cout << "error" << endl;
		return -1;
	}
	//1�׾���ֱ�ӷ�����Ԫ��
	if (a[0].size() == 1) return a[0][0];
	else {
		int n = a[0].size();

		double det = 0;
		//��һ�е�i+1�г���������ʽ
		for (int i = 0; i < n; ++i) {
			//����n-1�׾���,��ʼ������ʽ
			vector<vector<double>> temp;
			for (int i = 0; i < n - 1; ++i)
				temp.push_back(vector<double>());
			int row = 0;
			//���ڵ�һ���Ҳ��ڵ�c+1�е�Ԫ�ط���temp��
			for (int r = 1; r < n; ++r) {
				for (int c = 0; c < n; ++c) {
					if (c != i) {
						temp[row].push_back(a[r][c]);
						//�����ǰ��Ԫ������
						if (temp[row].size() == n - 1)
							++row;
					}
				}
			}
			//��������ʽ��i��ż��Ϊ�ӣ�����Ϊ��
			if (i % 2 == 0) 
				det += a[0][i] * determinant(temp);
			else det -= a[0][i] * determinant(temp);
		}
		return det;
	}
}
//19.�������
void inverse(vector<vector<double>> a, vector<vector<double>> &dest)
{
	double det = determinant(a);
	vector<vector<double>> b;
	for (int i = 0; i < a.size(); ++i)
		b.push_back(vector<double>());
	//���ÿһ��ÿһ�е�����ʽ
	for (int i = 0; i < a.size(); ++i) {
		for (int j = 0; j < a[0].size(); ++j) {
			vector<vector<double>> temp;
			for (int n = 0; n < a.size() - 1; ++n)
				temp.push_back(vector<double>());
			int row = 0;
			for (int r = 0; r < a.size(); ++r) {
				for (int c = 0; c < a[0].size(); ++c) {
					//ȥ����ǰ�к���
					if (r != i && c != j) {
						temp[row].push_back(a[r][c]);
						if (temp[row].size() == a.size() - 1)
							++row;
					}
				}
			}
			//����������ʽ����
			double m = determinant(temp);
			if ((i + j) % 2 == 1 && m != 0)
				m *= -1;
			b[i].push_back(m / det);
		}
	}
	//ת��
	transpose(b, dest);
}

int main()
{
	cout.setf(ios::boolalpha);
	//p1();
	//p2();
	//p8();
	vector<vector<double>> a = { {1, 0, 0, 0}, {0, 2, 0, 0}, {0, 0, 4, 0}, {1, 2, 3, 1} };
	vector<vector<double>> b;
	transpose(a, b);
	cout << "ת�þ���transposeA = " << endl;
	for (int i = 0; i < b.size(); ++i) {
		for (int j = 0; j < b[0].size(); ++j)
			cout << b[i][j] << "\t";
		cout << endl;
	}
	cout << endl;

	double det = determinant(a);
	cout << "����ʽdetA = " << det << endl << endl;

	vector<vector<double>> c;
	inverse(a, c);
	cout << "�����inverseA = " << endl;
	for (int i = 0; i < c.size(); ++i) {
		for (int j = 0; j < c[0].size(); ++j)
			cout << c[i][j] << "\t";
		cout << endl;
	}
	cout << endl;

	system("pause");
	return 0;
}