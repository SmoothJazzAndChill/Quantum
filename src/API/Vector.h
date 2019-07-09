#pragma once
#ifndef VECTOR_H
#define VECTOR_H

#include "../Engine/PCH.h"
#include "QuantumAPI.h"

class Vector
{
public:
	// Operators
	void operator =(Vector v)
	{
		SetValues(v);
	}

	Vector operator +(Vector v)
	{
		Vector Result;
		for (int i = 0; i < 4; i++)
		{
			Result.Values[i] = this->Values[i] + v.Values[i];
		}
		return Result;
	}
	void operator +=(Vector v)
	{
		Values[0] += v.Values[0];
		Values[1] += v.Values[1];
		Values[2] += v.Values[2];
		Values[3] += v.Values[3];
	}

	Vector operator -(Vector v)
	{
		Vector Result;
		for (int i = 0; i < 4; i++)
		{
			Result.Values[i] = this->Values[i] - v.Values[i];
		}
		return Result;
	}
	void operator -=(Vector v)
	{
		Values[0] -= v.Values[0];
		Values[1] -= v.Values[1];
		Values[2] -= v.Values[2];
		Values[3] -= v.Values[3];
	}

	Vector operator *(Vector v)
	{
		Vector Result;
		for (int i = 0; i < 4; i++)
		{
			Result.Values[i] = this->Values[i] * v.Values[i];
		}
		return Result;
	}
	template<typename T>
	Vector operator *(T rhs)
	{
		Vector o;
		for (int i = 0; i < 4; i++)
		{
			o.Values[i] *= rhs;
		}
		return o;
	}
	template<typename T>
	void operator *=(T rhs)
	{
		for (int i = 0; i < 4; i++)
		{
			Values[i] *= rhs;
		}
	}
	void operator *=(Vector v)
	{
		for (int i = 0; i < 4; i++)
		{
			Values[i] *= v.Values[i];
		}
	}

	Vector operator /(Vector v)
	{
		Vector Result;
		for (int i = 0; i < 4; i++)
		{
			Result.Values[i] = this->Values[i] / v.Values[i];
		}
		return Result;
	}
	template<typename T>
	Vector operator /(T rhs)
	{
		Vector o;
		for (int i = 0; i < 4; i++)
		{
			o.Values[i] /= rhs;
		}
		return o;
	}
	template<typename T>
	void operator /=(T rhs)
	{
		for (int i = 0; i < 4; i++)
		{
			Values[i] /= rhs;
		}
	}
	void operator /=(Vector v)
	{
		for (int i = 0; i < 4; i++)
		{
			Values[i] /= v.Values[i];
		}
	}

	// Vector Math
	double SqrMagnitude()
	{
		double output = 0;
		for (int i = 0; i < 4; i++)
		{
			output += Values[i] * Values[i];
		}
		return output;
	}
	double Magnitude()
	{
		return sqrt(SqrMagnitude());
	}
	void Normalise()
	{
		for (int i = 0; i < 4; i++)
		{
			Values[i] /= Magnitude();
		}
	}
	Vector Normalised() const
	{
		Vector v = *this;
		v.Normalise();
		return v;
	}
	static double Dot(Vector v1, Vector v2)
	{
		double Result;

		for (int i = 0; i < 4; i++)
		{
			Result += v1.Values[i] * v2.Values[i];
		}

		return Result;
	}
	static double Distance(Vector v1, Vector v2)
	{
		Vector v = Direction(v1, v2);
		return v.Magnitude();
	}
	static Vector Direction(Vector start, Vector end)
	{
		Vector v = end;
		v -= start;
		return v;
	}
	Vector DirectionTo(Vector Target)
	{
		return Vector::Direction(*this, Target);
	}
	double DistanceTo(Vector Target)
	{
		return Vector::Distance(*this, Target);
	}
	static Vector Lerp(Vector Start, Vector End, float T)
	{
		Vector V = Direction(Start, End);
		float Distance = V.Magnitude();
		return (V / Distance) * T;
	}
	static Vector Rotate(Vector v, Quaternion q)
	{

	}
	void Rotate(Quaternion q)
	{

	}
	static Vector Slerp(Vector V, Quaternion Start, Quaternion End, float T)
	{

	}

	// Constants
	static Vector Up()
	{
		Vector v;
		v.SetValues(0, 1, 0, 0);
		return v;
	}
	static Vector Forward()
	{
		Vector v;
		v.SetValues(0, 0, 1, 0);
		return v;
	}
	static Vector Right()
	{
		Vector v;
		v.SetValues(1, 0, 0, 0);
		return v;
	}

protected:
	Vector() {}

	void SetValues(double x, double y, double z, double w)
	{
		Values[0] = x;
		Values[1] = y;
		Values[2] = z;
		Values[3] = w;
	}
	void SetValues(Vector v)
	{
		for (int i = 0; i < 4; i++)
		{
			Values[i] = v.Values[i];
		}
	}

	double Values[4] = { 0,0,0,0 };
};

class Vector2 : public Vector
{
public:
	Vector2() {}
	Vector2(double x, double y)
	{
		SetValues(x, y, 0, 0);
	}

	void Set(double x, double y) { Values[0] = x; Values[1] = y; }
	double x() const { return Values[0]; }
	void SetX(double d) { Values[0] = d; }
	double y() const { return Values[1]; }
	void SetY(double d) { Values[1] = d; }
};

class Vector3 : public Vector
{
public:
	Vector3() {}
	Vector3(Vector2 v, double z)
	{
		SetValues(v.x(), v.y(), z, 0);
	}
	Vector3(double x, double y, double z)
	{
		SetValues(x, y, z, 0);
	}

	void Set(double x, double y, double z) { Values[0] = x; Values[1] = y; Values[2] = z; }
	double x() const { return Values[0]; }
	void SetX(double d) { Values[0] = d; }
	double y() const { return Values[1]; }
	void SetY(double d) { Values[1] = d; }
	double z() const { return Values[2]; }
	void SetZ(double d) { Values[2] = d; }

	static Vector3 Cross(Vector3 v1, Vector3 v2)
	{
		Vector3 Result;

		Result.Values[0] = (v1.y() * v2.z()) - (v1.z() * v2.y());
		Result.Values[1] = (v1.z() * v2.x()) - (v1.x() * v2.z());
		Result.Values[2] = (v1.x() * v2.y()) - (v1.y() * v2.x());

		return Result;
	}
};

class Vector4 : public Vector
{
public:
	Vector4() {}
	Vector4(Vector2 v1, Vector2 v2)
	{
		SetValues(v1.x(), v1.y(), v2.x(), v2.y());
	}
	Vector4(Vector3 v, double _w)
	{
		SetValues(v.x(), v.y(), v.z(), 0);
	}
	Vector4(double x, double y, double z, double w)
	{
		SetValues(x, y, z, w);
	}

	void Set(double x, double y, double z, double w) { Values[0] = x; Values[1] = y; Values[2] = z; Values[3] = w; }
	double x() const { return Values[0]; }
	void SetX(double d) { Values[0] = d; }
	double y() const { return Values[1]; }
	void SetY(double d) { Values[1] = d; }
	double z() const { return Values[2]; }
	void SetZ(double d) { Values[2] = d; }
	double w() const { return Values[3]; }
	void SetW(double d) { Values[3] = d; }
};

#endif //!VECTOR_H