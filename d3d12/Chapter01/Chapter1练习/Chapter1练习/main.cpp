#include <Windows.h>
#include <DirectXMath.h>
#include <DirectXPackedVector.h>
#include <iostream>
using namespace std;
using namespace DirectX;
using namespace DirectX::PackedVector;

ostream& XM_CALLCONV operator<<(ostream& os, FXMVECTOR v)
{
	XMFLOAT3 dest;
	XMStoreFloat3(&dest, v);
	cout << "(" << dest.x << ", " << dest.y << ", " << dest.z << ")";
	return os;
}

void p1()
{
	XMVECTOR u = XMVectorSet(1.0f, 2.0f, 0.0f, 0.0f);
	XMVECTOR v = XMVectorSet(3.0f, -4.0f, 0.0f, 0.0f);
	XMVECTOR a = u + v;
	XMVECTOR b = u - v;
	XMVECTOR c = 2 * u + 1.0f / 2 * v;
	XMVECTOR d = -2 * u + v;
	cout << "u = " << u << endl;
	cout << "v = " << v << endl;
	cout << "a = " << a << endl;
	cout << "b = " << b << endl;
	cout << "c = " << c << endl;
	cout << "d = " << d << endl;
}

void p2()
{
	XMVECTOR u = XMVectorSet(-1.0f, 3.0f, 2.0f, 0.0f);
	XMVECTOR v = XMVectorSet(3.0f, -4.0f, 1.0f, 0.0f);
	XMVECTOR a = u + v;
	XMVECTOR b = u - v;
	XMVECTOR c = 3 * u + 2 * v;
	XMVECTOR d = -2 * u + v;
	cout << "u = " << u << endl;
	cout << "v = " << v << endl;
	cout << "a = " << a << endl;
	cout << "b = " << b << endl;
	cout << "c = " << c << endl;
	cout << "d = " << d << endl;
}

void p4()
{
	//2(a - x) - b = -2a, x = a - [(b - 2a) / 2]
	XMVECTOR a = XMVectorSet(1.0f, 2.0f, 3.0f, 0.0f);
	XMVECTOR b = XMVectorSet(-2.0f, 0.0f, 4.0f, 0.0f);
	XMVECTOR c, x;
	c = 1 / 2.0 * (b - 2 * a);
	x = a - c;
	cout << "x = " << x << endl;
}

void p5()
{
	XMVECTOR u = XMVectorSet(-1.0f, 3.0f, 2.0f, 0.0f);
	XMVECTOR v = XMVectorSet(3.0f, -4.0f, 1.0f, 0.0f);
	XMVECTOR u_ = XMVector3Normalize(u);
	XMVECTOR v_ = XMVector3Normalize(v);
	cout << "u^ = " << u_ << endl;
	cout << "v^ = " << v_ << endl;
}

void p7()
{
	XMVECTOR a_u = XMVectorSet(1.0f, 1.0f, 1.0f, 0.0f);
	XMVECTOR a_v = XMVectorSet(2.0f, 3.0f, 4.0f, 0.0f);
	XMVECTOR b_u = XMVectorSet(1.0f, 1.0f, 0.0f, 0.0f);
	XMVECTOR b_v = XMVectorSet(-2.0f, 2.0f, 0.0f, 0.0f);
	XMVECTOR c_u = XMVectorSet(-1.0f, -1.0f, -1.0f, 0.0f);
	XMVECTOR c_v = XMVectorSet(3.0f, 1.0f, 0.0f, 0.0f);

	XMVECTOR angleA = XMVector3AngleBetweenVectors(a_u, a_v);
	float angleDegreesA = XMConvertToDegrees(XMVectorGetX(angleA));
	XMVECTOR angleB = XMVector3AngleBetweenVectors(b_u, b_v);
	float angleDegreesB = XMConvertToDegrees(XMVectorGetX(angleB));
	XMVECTOR angleC = XMVector3AngleBetweenVectors(c_u, c_v);
	float angleDegreesC = XMConvertToDegrees(XMVectorGetX(angleC));

	cout << "degreeA = " << angleDegreesA << endl;
	cout << "degreeB = " << angleDegreesB << endl;
	cout << "degreeC = " << angleDegreesC << endl;
}

void p8()
{
	XMVECTOR u = XMVectorSet(-1.0f, 3.0f, 2.0f, 0.0f);
	XMVECTOR v = XMVectorSet(3.0f, -4.0f, 1.0f, 0.0f);
	XMVECTOR angle = XMVector3AngleBetweenVectors(u, v);
	float degrees = XMConvertToDegrees(XMVectorGetX(angle));
	cout << "degrees = " << degrees << endl;
}

void p11()
{
	XMVECTOR n = XMVectorSet(-2.0f, 1.0f, 0.0f, 0.0f);
	XMVECTOR g = XMVectorSet(0.0f, -9.8f, 0.0f, 0.0f);
	XMVECTOR n_ = XMVector3Normalize(n);
	XMVECTOR projG, perpG;
	XMVector3ComponentsFromNormal(&projG, &perpG, g, n_);
	cout << "projG = " << projG << endl;
	cout << "perpG = " << perpG << endl;
}

void p12()
{
	XMVECTOR u = XMVectorSet(-2.0f, 1.0f, 4.0f, 0.0f);
	XMVECTOR v = XMVectorSet(3.0f, -4.0f, 1.0f, 0.0f);
	XMVECTOR w = XMVector3Cross(u, v);
	XMVECTOR w_u = XMVector3Dot(w, u);
	XMVECTOR w_v = XMVector3Dot(w, v);
	//XMVECTOR w_u = w * u;
	//XMVECTOR w_v = w * v;
	cout << "w = " << w << endl;
	cout << "w . u = " << w_u << endl;
	cout << "w . v = " << w_v << endl;
}

void p13()
{
	XMVECTOR b = XMVectorSet(0.0f, 1.0f, 3.0f, 0.0f);
	XMVECTOR c = XMVectorSet(5.0f, 1.0f, 0.0f, 0.0f);
	XMVECTOR x = XMVector3Cross(b, c);
	XMVECTOR xb = XMVector3Dot(x, b);
	XMVECTOR xc = XMVector3Dot(x, c);
	cout << "x = " << x << endl;
	cout << "x . b = " << xb << endl;
	cout << "x . c = " << xc << endl;
}

void p18()
{
	XMVECTOR v0 = XMVectorSet(1.0f, 0.0f, 0.0f, 0.0f);
	XMVECTOR v1 = XMVectorSet(1.0f, 5.0f, 0.0f, 0.0f);
	XMVECTOR v2 = XMVectorSet(2.0f, 1.0f, -4.0f, 0.0f);
	XMVECTOR w0 = XMVector3Normalize(v0);
	XMVECTOR d = XMVector3Cross(w0, v1);
	XMVECTOR w2 = XMVector3Normalize(d);
	XMVECTOR w1 = XMVector3Cross(w2, w0);
	cout << "{ " << w0 << ", " << w1 << ", " << w2 << " }" << endl;
}

int main()
{
	cout.setf(ios_base::boolalpha);
	if (!XMVerifyCPUSupport) {
		cout << "directx math not supported" << endl;
		return 0;
	}
	//p1();
	//p2();
	//p4();
	//p5();
	//p7();
	//p8();
	//p11();
	//p12();
	//p13();
	p18();

	system("pause");
	return 0;
}