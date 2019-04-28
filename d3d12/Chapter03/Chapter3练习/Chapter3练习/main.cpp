#include <Windows.h>
#include <DirectXMath.h>
#include <DirectXPackedVector.h>
#include <iostream>
using namespace std;
using namespace DirectX;
using namespace DirectX::PackedVector;

ostream& XM_CALLCONV operator<<(ostream& os, XMVECTOR v)
{
	XMFLOAT4 dest;
	XMStoreFloat4(&dest, v);

	cout << "(" << dest.x << ", " << dest.y << ", " << dest.z << ", " << dest.w << ")";
	return os;
}

int main()
{
	//第27题
	XMVECTOR p = XMVectorZero();
	XMVECTOR q = XMVectorSet(0.0f, 0.0f, 1.0f, 0.0f);
	XMVECTOR _p = XMVectorSet(3.0f, 1.0f, 2.0f, 0.0f);
	XMVECTOR d = XMVectorSet(1.0f, 1.0f, 1.0f, 0.0f);
	//缩放矩阵
	XMMATRIX s = XMMatrixScaling(1.0f, 1.0f, 2.0f);
	//旋转矩阵
	//旋转角
	XMVECTOR angleVec = XMVector3AngleBetweenVectors(q, d);
	float angleRadians = XMVectorGetX(angleVec);
	float angleDegrees = XMConvertToDegrees(angleRadians);
	//旋转轴
	XMVECTOR axis = XMVector3Cross(q, d);
	axis = XMVector3Normalize(axis);
	
	XMMATRIX r = XMMatrixRotationAxis(axis, angleDegrees);
	//平移矩阵
	XMMATRIX t = XMMatrixTranslationFromVector(_p);

	XMMATRIX A = s * r * t;

	XMVECTOR result = XMVector3TransformNormal(q, A);
	cout << "变换后的向量：" << result << endl << endl;
	cout << "变换矩阵 = " << endl;
	cout << A.r[0] << endl;
	cout << A.r[1] << endl;
	cout << A.r[2] << endl;
	cout << A.r[3] << endl << endl;

	system("pause");
	return 0;
}