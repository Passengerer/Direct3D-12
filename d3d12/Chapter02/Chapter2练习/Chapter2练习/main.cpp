#include <Windows.h>
#include <DirectXMath.h>
#include <DirectXPackedVector.h>
#include <iostream>
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
	//CÊÇ3½×¾ØÕó£¬¹ÊBÊÇAµÄÄæ¾ØÕó
}

int main()
{
	cout.setf(ios::boolalpha);
	//p1();
	//p2();
	p8();

	system("pause");
	return 0;
}