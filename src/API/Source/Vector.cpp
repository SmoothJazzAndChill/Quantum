#include "../QuantumAPI.h"

///
///	Vector Functions
///

using namespace Quantum;

Vector::Vector() 
{
	SetValues(0, 0, 0, 0);
}

void Vector::operator =(Vector v)
{
	SetValues(v);
}

Vector Vector::operator +(Vector v)
{
	Vector Result;
	for (int i = 0; i < 4; i++)
	{
		Result.Values[i] = this->Values[i] + v.Values[i];
	}
	return Result;
}
void Vector::operator +=(Vector v)
{
	Values[0] += v.Values[0];
	Values[1] += v.Values[1];
	Values[2] += v.Values[2];
	Values[3] += v.Values[3];
}

Vector Vector::operator -(Vector v)
{
	Vector Result;
	for (int i = 0; i < 4; i++)
	{
		Result.Values[i] = this->Values[i] - v.Values[i];
	}
	return Result;
}
void Vector::operator -=(Vector v)
{
	Values[0] -= v.Values[0];
	Values[1] -= v.Values[1];
	Values[2] -= v.Values[2];
	Values[3] -= v.Values[3];
}

template<typename T>
Vector Vector::operator *(T rhs)
{
	Vector o;
	for (int i = 0; i < 4; i++)
	{
		o.Values[i] *= rhs;
	}
	return o;
}
Vector Vector::operator *(Vector v)
{
	Vector Result;
	for (int i = 0; i < 4; i++)
	{
		Result.Values[i] = this->Values[i] * v.Values[i];
	}
	return Result;
}

template Vector Vector::operator*<char>(char);
template Vector Vector::operator*<short>(short);
template Vector Vector::operator*<int>(int);
template Vector Vector::operator*<long>(long);
template Vector Vector::operator*<float>(float);
template Vector Vector::operator*<double>(double);

template<typename T>
void Vector::operator *=(T rhs)
{
	for (int i = 0; i < 4; i++)
	{
		Values[i] *= rhs;
	}
}
void Vector::operator *=(Vector v)
{
	for (int i = 0; i < 4; i++)
	{
		Values[i] *= v.Values[i];
	}
}

template void Vector::operator*=<char>(char);
template void Vector::operator*=<short>(short);
template void Vector::operator*=<int>(int);
template void Vector::operator*=<long>(long);
template void Vector::operator*=<float>(float);
template void Vector::operator*=<double>(double);

template<typename T>
Vector Vector::operator /(T rhs)
{
	Vector o;
	for (int i = 0; i < 4; i++)
	{
		o.Values[i] /= rhs;
	}
	return o;
}
Vector Vector::operator /(Vector v)
{
	Vector Result;
	for (int i = 0; i < 4; i++)
	{
		Result.Values[i] = this->Values[i] / v.Values[i];
	}
	return Result;
}

template Vector Vector::operator/<char>(char);
template Vector Vector::operator/<short>(short);
template Vector Vector::operator/<int>(int);
template Vector Vector::operator/<long>(long);
template Vector Vector::operator/<float>(float);
template Vector Vector::operator/<double>(double);

template<typename T>
void Vector::operator /=(T rhs)
{
	for (int i = 0; i < 4; i++)
	{
		Values[i] /= rhs;
	}
}
void Vector::operator /=(Vector v)
{
	for (int i = 0; i < 4; i++)
	{
		Values[i] /= v.Values[i];
	}
}

template void Vector::operator/=<char>(char);
template void Vector::operator/=<short>(short);
template void Vector::operator/=<int>(int);
template void Vector::operator/=<long>(long);
template void Vector::operator/=<float>(float);
template void Vector::operator/=<double>(double);

double Vector::SqrMagnitude()
{
	double output = 0;
	for (int i = 0; i < 4; i++)
	{
		output += Values[i] * Values[i];
	}
	return output;
}

double Vector::Magnitude()
{
	return sqrt(SqrMagnitude());
}

void Vector::Normalise()
{
	for (int i = 0; i < 4; i++)
	{
		Values[i] /= Magnitude();
	}
}

Vector Vector::Normalised() const
{
	Vector v = *this;
	v.Normalise();
	return v;
}

double Vector::Dot(Vector v1, Vector v2)
{
	{
		double Result = 0;

		for (int i = 0; i < 4; i++)
		{
			Result += v1.Values[i] * v2.Values[i];
		}

		return Result;
	}
}

double Vector::Distance(Vector v1, Vector v2)
{
	Vector v = Direction(v1, v2);
	return v.Magnitude();
}

Vector Vector::Direction(Vector v1, Vector v2)
{
	Vector v = v2;
	v -= v1;
	return v;
}

Vector Vector::DirectionTo(Vector Target)
{
	return Vector::Direction(*this, Target);
}

double Vector::DistanceTo(Vector Target)
{
	return Vector::Distance(*this, Target);
}

Vector Vector::Lerp(Vector v1, Vector v2, float T)
{
	Vector V = Direction(v1, v2);
	double Distance = V.Magnitude();
	return (V / Distance) * T;
}

Vector Vector::Rotate(Vector v, Quaternion q)
{
	return Zero();
}

void Vector::Rotate(Quaternion q)
{

}

Vector Vector::Slerp(Vector V, Quaternion Start, Quaternion End, float T)
{
	return Zero();
}

const Vector Vector::Up()
{
	Vector v;
	v.SetValues(0, 1, 0, 0);
	return v;
}

const Vector Vector::Right()
{
	Vector v;
	v.SetValues(1, 0, 0, 0);
	return v;
}

const Vector Vector::Forward()
{
	Vector v;
	v.SetValues(0, 0, 1, 0);
	return v;
}

const Vector Vector::Zero()
{
	Vector v;
	v.SetValues(0, 0, 0, 0);
	return v;
}

void Vector::SetValues(double x, double y, double z, double w)
{
	Values[0] = x;
	Values[1] = y;
	Values[2] = z;
	Values[3] = w;
}

void Vector::SetValues(Vector v)
{
	for (int i = 0; i < 4; i++)
	{
		Values[i] = v.Values[i];
	}
}

///
/// Vector2 Functions
///

Vector2::Vector2() {}
Vector2::Vector2(double x, double y)
{
	SetValues(x, y, 0, 0);
}

void Vector2::Set(double x, double y) { Values[0] = x; Values[1] = y; }
double Vector2::x() const { return Values[0]; }
void Vector2::SetX(double d) { Values[0] = d; }
double Vector2::y() const { return Values[1]; }
void Vector2::SetY(double d) { Values[1] = d; }

///
/// Vector3 Functions
///

Vector3::Vector3() {}
Vector3::Vector3(Vector2 v, double z)
{
	SetValues(v.x(), v.y(), z, 0);
}
Vector3::Vector3(double x, double y, double z)
{
	SetValues(x, y, z, 0);
}

void Vector3::Set(double x, double y, double z) { Values[0] = x; Values[1] = y; Values[2] = z; }
double Vector3::x() const { return Values[0]; }
void Vector3::SetX(double d) { Values[0] = d; }
double Vector3::y() const { return Values[1]; }
void Vector3::SetY(double d) { Values[1] = d; }
double Vector3::z() const { return Values[2]; }
void Vector3::SetZ(double d) { Values[2] = d; }

Vector3 Vector3::Cross(Vector3 v1, Vector3 v2)
{
	Vector3 Result;

	Result.Values[0] = (v1.y() * v2.z()) - (v1.z() * v2.y());
	Result.Values[1] = (v1.z() * v2.x()) - (v1.x() * v2.z());
	Result.Values[2] = (v1.x() * v2.y()) - (v1.y() * v2.x());

	return Result;
}

///
/// Vector4 Functions
///

Vector4::Vector4() {}
Vector4::Vector4(Vector2 v1, Vector2 v2)
{
	SetValues(v1.x(), v1.y(), v2.x(), v2.y());
}
Vector4::Vector4(Vector3 v, double _w)
{
	SetValues(v.x(), v.y(), v.z(), 0);
}
Vector4::Vector4(double x, double y, double z, double w)
{
	SetValues(x, y, z, w);
}

void Vector4::Set(double x, double y, double z, double w) { Values[0] = x; Values[1] = y; Values[2] = z; Values[3] = w; }
double Vector4::x() const { return Values[0]; }
void Vector4::SetX(double d) { Values[0] = d; }
double Vector4::y() const { return Values[1]; }
void Vector4::SetY(double d) { Values[1] = d; }
double Vector4::z() const { return Values[2]; }
void Vector4::SetZ(double d) { Values[2] = d; }
double Vector4::w() const { return Values[3]; }
void Vector4::SetW(double d) { Values[3] = d; }