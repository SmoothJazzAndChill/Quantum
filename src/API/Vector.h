#pragma once
#ifndef VECTOR_H
#define VECTOR_H

#include "../Engine/PCH.h"

namespace Quantum
{
	class Quaternion;

	class Vector
	{
	public:
		///
		/// Operators
		///

		void operator =(Vector v);

		Vector operator +(Vector v);
		void operator +=(Vector v);

		Vector operator -(Vector v);
		void operator -=(Vector v);

		template<typename T>
		Vector operator *(T rhs);
		Vector operator *(Vector v);

		template<typename T>
		void operator *=(T rhs);
		void operator *=(Vector v);

		template<typename T>
		Vector operator /(T rhs);
		Vector operator /(Vector v);

		template<typename T>
		void operator /=(T rhs);
		void operator /=(Vector v);

		///
		///	 Vector Maths
		///

		//Returns the Square Magnitude of the Vector
		double SqrMagnitude();
		//Returns the Magnitude of the Vector
		double Magnitude();
		//Normalises this Vector to have a Magnitude of 1
		void Normalise();
		//Returns a Normalised version of this Vector, which will have a Magnitude of 1
		Vector Normalised() const;
		//Returns the Dot product of two Vectors
		static double Dot(Vector v1, Vector v2);
		//Returns the Distance between two Vectors
		static double Distance(Vector v1, Vector v2);
		//Returns the Direction from one Vector to another
		static Vector Direction(Vector Start, Vector End);
		//Returns the Direction from this Vector to another
		Vector DirectionTo(Vector Target);
		//Returns the Distance from this Vector to another
		double DistanceTo(Vector Target);
		//Returns a point between two Vectors at time T (0.0-1.0)
		static Vector Lerp(Vector Start, Vector End, float T);
		//Returns a Vector rotated by a given Quaternion
		static Vector Rotate(Vector v, Quaternion q);
		//Rotates this Vector by a given Quaternion
		void Rotate(Quaternion q);
		//Returns a Vector that is rotated between two Quaternions at time T (0.0-1.0)
		static Vector Slerp(Vector V, Quaternion Start, Quaternion End, float T);

		///
		/// Constants
		///
		//Returns {0,1,0,0}
		static const Vector Up();
		//Returns {1,0,0,0}
		static const Vector Forward();
		//Returns {0,0,1,0}
		static const Vector Right();
		//Returns {0,0,0,0}
		static const Vector Zero();

	protected:
		Vector();

		void SetValues(double x, double y, double z, double w);
		void SetValues(Vector v);

		double Values[4] = { 0,0,0,0 };
	};

	class Vector2 : public Vector
	{
	public:
		Vector2();
		//Initialise with values
		Vector2(double x, double y);

		//Set the values of the Vector2
		void Set(double x, double y);
		//Return the X value
		double x() const;
		//Set the X value
		void SetX(double d);
		//Return the Y value
		double y() const;
		//Set the Y value
		void SetY(double d);
	};

	class Vector3 : public Vector
	{
	public:
		Vector3();
		//Initialise with a Vector2 and a Z value
		Vector3(Vector2 v, double z);
		//Initialise with values
		Vector3(double x, double y, double z);

		//Set the values of the Vector3
		void Set(double x, double y, double z);
		//Return the X value
		double x() const;
		//Set the X value
		void SetX(double d);
		//Return the Y value
		double y() const;
		//Set the Y value
		void SetY(double d);
		//Return the Z value
		double z() const;
		//Set the Z value
		void SetZ(double d);

		//Returns the Cross product of two Vectors
		static Vector3 Cross(Vector3 v1, Vector3 v2);
	};

	class Vector4 : public Vector
	{
	public:
		Vector4();
		//Initialise with two Vector2s
		Vector4(Vector2 v1, Vector2 v2);
		//Initialise with a Vector3 and a W value
		Vector4(Vector3 v, double _w);
		//Initialise with values
		Vector4(double x, double y, double z, double w);

		//Set the values of the Vector4
		void Set(double x, double y, double z, double w);
		//Return the X value
		double x() const;
		//Set the X value
		void SetX(double d);
		//Return the Y value
		double y() const;
		//Set the Y value
		void SetY(double d);
		//Return the Z value
		double z() const;
		//Set the Z value
		void SetZ(double d);
		//Return the W value
		double w() const;
		//Set the W value
		void SetW(double d);
	};
}

#endif //!VECTOR_H