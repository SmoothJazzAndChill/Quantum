#pragma once
#ifndef MATHS_H
#define MATHS_H

#define MATHSCONST_E 2.71828
#define MATHSCONST_PI 3.1415926
#define MATHSCONST_ROOT2 1.41421

namespace Quantum
{
	///
	/// Types
	///
	typedef double Radian;
	typedef double Degrees;

	namespace Maths
	{
		///
		/// Value Adjustment Functions
		///

		//Returns a value clamped between a minimum and a maximum
		template<typename T>
		T Clamp(T min, T max, T value);
		//Returns the square root of a value
		template<typename T>
		T Sqrt(T value);
		//Returns a value squared
		template<typename T>
		T Sqr(T value);
		//Returns the absolute value of a value
		template<typename T>
		T Abs(T value);
		//Returns a value rounded to the nearest whole number
		template<typename T>
		T Round(T value);
		//Returns a value rounded to the nearest whole number and casts it to an int
		template<typename T>
		int RoundToInt(T value);
		//Returns a value roundede down to the nearest whole number
		template<typename T>
		T Floor(T value);
		//Returns a value rounded down to the nearest whole number and casts it to an int
		template<typename T>
		int FloorToInt(T value);
		//Returns a value rounded up to the nearest whole number
		template<typename T>
		T Ceil(T value);
		//Returns a value rounded up to the nearest whole number and casts it to an int
		template<typename T>
		int CeilToInt(T value);

		///
		///	Standard Maths Functions
		///

		//Returns the log of a number given a base
		template<typename T>
		double Log(T value, T base);
		//Returns the natural log of a value
		template<typename T>
		double Ln(T value);
		//Returns the difference between two values
		template<typename T>
		T Diff(T value1, T value2);
		//Returns a value raised to a power
		template<typename T>
		T Pow(T value, double exponent);
		//Returns the sum of all values provided
		template<typename T>
		T Sum(T values...);
		//Returns the sum of all values in an array
		template<typename T>
		T Sum(int count, T* values);
		//Returns the sum of all values in a std::vector
		template<typename T>
		T Sum(std::vector<T> values);
		//Returns the factorial of a value
		template<typename T>
		T Fact(T value);
		//Returns the volume of a sphere with a given radius
		template<typename T>
		T SphericalVolume(T radius);
		//Returns the greatest value of the values given
		template<typename T>
		T Max(int count, T values...);
		//Returns the greatest value of the values given in an array
		template<typename T>
		T Max(int count, T* values);
		//Returns the greatest value of the values given in a std::vector
		template<typename T>
		T Max(std::vector<T> values);
		//Returns the smallest value of the values given
		template<typename T>
		T Min(T values...);
		//Returns the smallest value of the values given in an array
		template<typename T>
		T Min(int count, T* values);
		//Returns the smallest value of the values given in a std::vector
		template<typename T>
		T Min(std::vector<T> values);

		///
		/// Trigonometric Functions
		///

		//Returns the sine of a value
		template<typename T>
		T Sin(T value);
		//Returns the cosine of a value
		template<typename T>
		T Cos(T value);
		//Returns the tangent of a value
		template<typename T>
		T Tan(T value);
		//Returns the cotangent of a value
		template<typename T>
		T Cot(T value);
		//Returns the secant of a value
		template<typename T>
		T Sec(T value);
		//Returns the cosecant of a value
		template<typename T>
		T Csc(T value);
		//Returns the arcsine of a value
		template<typename T>
		T ASin(T value);
		//Returns the arccosine of a value
		template<typename T>
		T ACos(T value);
		//Returns the arctangent of a value
		template<typename T>
		T ATan(T value);
		//Returns the arccotangent of a value
		template<typename T>
		T ACot(T value);
		//Returns the arcsecant of a value
		template<typename T>
		T ASec(T value);
		//Returns the arccosecant of a value
		template<typename T>
		T ACsc(T value);
		
		///
		/// Conversion Functions
		///

		Radian DegToRad(Degrees value);
		Degrees RadToDeg(Radian value);

		///
		/// Constants
		///

		const double e = MATHSCONST_E;
		const double Pi = MATHSCONST_PI;
		const double Root2 = MATHSCONST_ROOT2;
	}
}

#endif //!MATHS_H