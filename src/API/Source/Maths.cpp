#include "../QuantumAPI.h"

using namespace Quantum;

template<typename T>
T Maths::Clamp(T min, T max, T value)
{
	T Output = 0;

	if (value < min) return min;
	if (value > max) return max;
	return value;
}

template char Maths::Clamp<char>(char, char, char);
template short Maths::Clamp<short>(short, short, short);
template int Maths::Clamp<int>(int, int, int);
template long Maths::Clamp<long>(long, long, long);
template float Maths::Clamp<float>(float, float, float);
template double Maths::Clamp<double>(double, double, double);

template<typename T>
T Maths::Sqrt(T value)
{
	return (T)sqrt(value);
}

template char Maths::Sqrt<char>(char);
template short Maths::Sqrt<short>(short);
template int Maths::Sqrt<int>(int);
template long Maths::Sqrt<long>(long);
template float Maths::Sqrt<float>(float);
template double Maths::Sqrt<double>(double);

template<typename T>
T Maths::Sqr(T value)
{
	return value * value;
}

template char Maths::Sqr<char>(char);
template short Maths::Sqr<short>(short);
template int Maths::Sqr<int>(int);
template long Maths::Sqr<long>(long);
template float Maths::Sqr<float>(float);
template double Maths::Sqr<double>(double);

template<typename T>
T Maths::Abs(T value)
{
	return (T)abs(value);
}

template char Maths::Abs<char>(char);
template short Maths::Abs<short>(short);
template int Maths::Abs<int>(int);
template long Maths::Abs<long>(long);
template float Maths::Abs<float>(float);
template double Maths::Abs<double>(double);

template<typename T>
T Maths::Round(T value)
{
	return (T)round(value);
}

template char Maths::Round<char>(char);
template short Maths::Round<short>(short);
template int Maths::Round<int>(int);
template long Maths::Round<long>(long);
template float Maths::Round<float>(float);
template double Maths::Round<double>(double);

template<typename T>
int Maths::RoundToInt(T value)
{
	return (int)round(value);
}

template int Maths::RoundToInt<char>(char);
template int Maths::RoundToInt<short>(short);
template int Maths::RoundToInt<int>(int);
template int Maths::RoundToInt<long>(long);
template int Maths::RoundToInt<float>(float);
template int Maths::RoundToInt<double>(double);

template<typename T>
T Maths::Floor(T value)
{
	return (T)trunc(value);
}

template char Maths::Floor<char>(char);
template short Maths::Floor<short>(short);
template int Maths::Floor<int>(int);
template long Maths::Floor<long>(long);
template float Maths::Floor<float>(float);
template double Maths::Floor<double>(double);

template<typename T>
int Maths::FloorToInt(T value)
{
	return (int)trunc(value);
}

template int Maths::FloorToInt<char>(char);
template int Maths::FloorToInt<short>(short);
template int Maths::FloorToInt<int>(int);
template int Maths::FloorToInt<long>(long);
template int Maths::FloorToInt<float>(float);
template int Maths::FloorToInt<double>(double);

template<typename T>
T Maths::Ceil(T value)
{
	return (T)trunc(value) + 1;
}

template char Maths::Ceil<char>(char);
template short Maths::Ceil<short>(short);
template int Maths::Ceil<int>(int);
template long Maths::Ceil<long>(long);
template float Maths::Ceil<float>(float);
template double Maths::Ceil<double>(double);

template<typename T>
int Maths::CeilToInt(T value)
{
	return (int)trunc(value) + 1;
}

template int Maths::CeilToInt<char>(char);
template int Maths::CeilToInt<short>(short);
template int Maths::CeilToInt<int>(int);
template int Maths::CeilToInt<long>(long);
template int Maths::CeilToInt<float>(float);
template int Maths::CeilToInt<double>(double);

template<typename T>
double Maths::Log(T value, T base)
{
	return log(value) / log(base);
}

template double Maths::Log<char>(char, char);
template double Maths::Log<short>(short, short);
template double Maths::Log<int>(int, int);
template double Maths::Log<long>(long, long);
template double Maths::Log<float>(float, float);
template double Maths::Log<double>(double, double);

template<typename T>
double Maths::Ln(T value) 
{
	return log(value);
}

template double Maths::Ln<char>(char);
template double Maths::Ln<short>(short);
template double Maths::Ln<int>(int);
template double Maths::Ln<long>(long);
template double Maths::Ln<float>(float);
template double Maths::Ln<double>(double);

template<typename T>
T Maths::Diff(T value1, T value2)
{
	return (T)Abs(value1 - value2);
}

template char Maths::Diff<char>(char, char);
template short Maths::Diff<short>(short, short);
template int Maths::Diff<int>(int, int);
template long Maths::Diff<long>(long, long);
template float Maths::Diff<float>(float, float);
template double Maths::Diff<double>(double, double);

template<typename T>
T Maths::Pow(T value, double exponent)
{
	return (T)pow(value, exponent);
}

template char Maths::Pow<char>(char, double);
template short Maths::Pow<short>(short, double);
template int Maths::Pow<int>(int, double);
template long Maths::Pow<long>(long, double);
template float Maths::Pow<float>(float, double);
template double Maths::Pow<double>(double, double);

template<typename T>
T Maths::Sum(T values...){}

template<typename T>
T Maths::Sum(int count, T* values){}

template<typename T>
T Maths::Sum(std::vector<T> values)
{
	T result = 0;
	for (int i = 0; i < values.size(); i++)
	{
		result += values[i];
	}
	return result;
}

template char Maths::Sum<char>(std::vector<char>);
template short Maths::Sum<short>(std::vector<short>);
template int Maths::Sum<int>(std::vector<int>);
template long Maths::Sum<long>(std::vector<long>);
template float Maths::Sum<float>(std::vector<float>);
template double Maths::Sum<double>(std::vector<double>);

template<typename T>
T Maths::Fact(T value)
{
	T result = 1;
	for (int i = 1; i <= value; i++)
	{
		result *= i;
	}
	return result;
}

template char Maths::Fact<char>(char);
template short Maths::Fact<short>(short);
template int Maths::Fact<int>(int);
template long Maths::Fact<long>(long);

template<typename T>
T Maths::SphericalVolume(T radius)
{
	return (T)((4 / 3) * Pi * Pow(radius, 3));
}

template char Maths::SphericalVolume<char>(char);
template short Maths::SphericalVolume<short>(short);
template int Maths::SphericalVolume<int>(int);
template long Maths::SphericalVolume<long>(long);
template float Maths::SphericalVolume<float>(float);
template double Maths::SphericalVolume<double>(double);

template<typename T>
T Maths::Max(int count, T values...)
{
	va_list Values;
	va_start(Values, values);

	T highest = va_arg(Values, T);
	T next;

	for (int i = 1; i < count; i++);
	{
		next = va_arg(Values, T);
		if (next > highest) highest = next;
	}

	va_end(Values);

	return highest;
}

template char Maths::Max<char>(int, char...);
template short Maths::Max<short>(int, short...);
template int Maths::Max<int>(int, int...);
template long Maths::Max<long>(int, long...);
template float Maths::Max<float>(int, float...);
template double Maths::Max<double>(int, double...);

template<typename T>
T Max(int count, T* values){}

template<typename T>
T Max(std::vector<T> values){}

template<typename T>
T Maths::Min(T values...)
{
	va_list Values;
	va_start(Values, values);

	T lowest = va_arg(Values, T);

	while (values--)
	{
		T next = va_arg(Values, T);
		if (next < lowest) lowest = next;
	}

	va_end(Values);

	return lowest;
}

template char Maths::Min<char>(char...);
template short Maths::Min<short>(short...);
template int Maths::Min<int>(int...);
template long Maths::Min<long>(long...);
template float Maths::Min<float>(float...);
template double Maths::Min<double>(double...);

template<typename T>
T Min(int count, T* values){}

template<typename T>
T Min(std::vector<T> values){}

template<typename T>
T Maths::Sin(T value)
{
	return (T)sin(value);
}

template char Maths::Sin<char>(char);
template short Maths::Sin<short>(short);
template int Maths::Sin<int>(int);
template long Maths::Sin<long>(long);
template float Maths::Sin<float>(float);
template double Maths::Sin<double>(double);

template<typename T>
T Maths::Cos(T value)
{
	return (T)cos(value);
}

template char Maths::Cos<char>(char);
template short Maths::Cos<short>(short);
template int Maths::Cos<int>(int);
template long Maths::Cos<long>(long);
template float Maths::Cos<float>(float);
template double Maths::Cos<double>(double);

template<typename T>
T Maths::Tan(T value)
{
	return (T)tan(value);
}

template char Maths::Tan<char>(char);
template short Maths::Tan<short>(short);
template int Maths::Tan<int>(int);
template long Maths::Tan<long>(long);
template float Maths::Tan<float>(float);
template double Maths::Tan<double>(double);

template<typename T>
T Maths::Cot(T value)
{
	return (T)(1 / tan(value));
}

template char Maths::Cot<char>(char);
template short Maths::Cot<short>(short);
template int Maths::Cot<int>(int);
template long Maths::Cot<long>(long);
template float Maths::Cot<float>(float);
template double Maths::Cot<double>(double);

template<typename T>
T Maths::Sec(T value)
{
	return (T)(1 / cos(value));
}

template char Maths::Sec<char>(char);
template short Maths::Sec<short>(short);
template int Maths::Sec<int>(int);
template long Maths::Sec<long>(long);
template float Maths::Sec<float>(float);
template double Maths::Sec<double>(double);

template<typename T>
T Maths::Csc(T value)
{
	return (T)(1 / sin(value));
}

template char Maths::Csc<char>(char);
template short Maths::Csc<short>(short);
template int Maths::Csc<int>(int);
template long Maths::Csc<long>(long);
template float Maths::Csc<float>(float);
template double Maths::Csc<double>(double);

template<typename T>
T Maths::ASin(T value)
{
	return (T)asin(value);
}

template char Maths::ASin<char>(char);
template short Maths::ASin<short>(short);
template int Maths::ASin<int>(int);
template long Maths::ASin<long>(long);
template float Maths::ASin<float>(float);
template double Maths::ASin<double>(double);

template<typename T>
T Maths::ACos(T value)
{
	return (T)acos(value);
}

template char Maths::ACos<char>(char);
template short Maths::ACos<short>(short);
template int Maths::ACos<int>(int);
template long Maths::ACos<long>(long);
template float Maths::ACos<float>(float);
template double Maths::ACos<double>(double);

template<typename T>
T Maths::ATan(T value)
{
	return (T)atan(value);
}

template char Maths::ATan<char>(char);
template short Maths::ATan<short>(short);
template int Maths::ATan<int>(int);
template long Maths::ATan<long>(long);
template float Maths::ATan<float>(float);
template double Maths::ATan<double>(double);

template<typename T>
T Maths::ACot(T value) { return 0; }

template char Maths::ACot<char>(char);
template short Maths::ACot<short>(short);
template int Maths::ACot<int>(int);
template long Maths::ACot<long>(long);
template float Maths::ACot<float>(float);
template double Maths::ACot<double>(double);

template<typename T>
T Maths::ASec(T value) { return 0; }

template char Maths::ASec<char>(char);
template short Maths::ASec<short>(short);
template int Maths::ASec<int>(int);
template long Maths::ASec<long>(long);
template float Maths::ASec<float>(float);
template double Maths::ASec<double>(double);

template<typename T>
T Maths::ACsc(T value) { return 0; }

template char Maths::ACsc<char>(char);
template short Maths::ACsc<short>(short);
template int Maths::ACsc<int>(int);
template long Maths::ACsc<long>(long);
template float Maths::ACsc<float>(float);
template double Maths::ACsc<double>(double);

Radian Maths::DegToRad(Degrees value)
{
	return (value * Pi) / 180;
}

Degrees Maths::RadToDeg(Radian value)
{
	return (value * 180) / Pi;
}