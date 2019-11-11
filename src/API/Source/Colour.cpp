#include "../QuantumAPI.h"

using namespace Quantum;

HSV::HSV(){}
HSV::HSV(double _h, double _s, double _v)
{
	h = _h;
	s = _s;
	v = _v;
}
void HSV::operator =(HSV hsv)
{
	h = hsv.h;
	s = hsv.s;
	v = hsv.v;
}

RGB::RGB(){}
RGB::RGB(double _r, double _g, double _b)
{
	r = _r;
	g = _g;
	b = _b;
}
void RGB::operator =(RGB rgb)
{
	r = rgb.r;
	g = rgb.g;
	b = rgb.b;
}

Colour::Colour(){}
Colour::Colour(RGB rgb, double alpha)
{
	_rgb = rgb;
	_hsv = RGBToHSV(rgb);
	_a = alpha;
}
Colour::Colour(HSV hsv, double alpha)
{
	_rgb = HSVToRGB(hsv);
	_hsv = hsv;
	_a = alpha;
}

void Colour::operator =(Colour c)
{
	_rgb = c._rgb;
	_hsv = c._hsv;
	_a = c._a;
}

Colour Colour::operator +(Colour c) { return c; }
void Colour::operator +=(Colour c) { return; }

Colour Colour::operator -(Colour c) { return c; }
void Colour::operator -=(Colour c) { return; }

template<typename T>
Colour Colour::operator *(T rhs) { return this; }
Colour Colour::operator *(Colour v) { return v; }

template<typename T>
void Colour::operator *=(T rhs) { return; }
void Colour::operator *=(Colour v) { return; }

template<typename T>
Colour Colour::operator /(T rhs) { return this; }
Colour Colour::operator /(Colour v) { return v; }

template<typename T>
void Colour::operator /=(T rhs) { return; }
void Colour::operator /=(Colour v) { return; }

RGB Colour::rgb() const { return _rgb; }
HSV Colour::hsv() const { return _hsv; }

void Colour::Set(RGB rgb)
{
	Set(rgb, _a);
}
void Colour::Set(RGB rgb, double a)
{
	_rgb = rgb;
	_hsv = RGBToHSV(rgb);
	_a = a;
}
void Colour::Set(HSV hsv)
{
	Set(hsv, _a);
}
void Colour::Set(HSV hsv, double a)
{
	_rgb = HSVToRGB(hsv);
	_hsv = hsv;
	_a = a;
}

double Colour::a() const { return _a; }
void Colour::SetA(double a)
{
	_a = a;
}

template<> Vector4 Colour::ToVector4<RGB>()
{
	Vector4 v = Vector4(_rgb.r, _rgb.g, _rgb.b, _a);
	return v;
}
template<> Vector4 Colour::ToVector4<HSV>()
{
	Vector4 v = Vector4(_hsv.h, _hsv.s, _hsv.v, _a);
	return v;
}

Colour Colour::White()
{
	RGB rgb = RGB(255, 255, 255);
	Colour c = Colour(rgb, 255);
	return c;
}
Colour Colour::Grey()
{
	RGB rgb = RGB(127.5, 127.5, 127.5);
	Colour c = Colour(rgb, 255);
	return c;
}
Colour Colour::Black()
{
	RGB rgb = RGB(0, 0, 0);
	Colour c = Colour(rgb, 255);
	return c;
}
Colour Colour::Clear()
{
	RGB rgb = RGB(0, 0, 0);
	Colour c = Colour(rgb, 0);
	return c;
}

Colour Colour::Red()
{
	RGB rgb = RGB(255, 0, 0);
	Colour c = Colour(rgb, 255);
	return c;
}
Colour Colour::Yellow() 
{
	RGB rgb = RGB(255, 255, 0);
	Colour c = Colour(rgb, 255);
	return c;
}
Colour Colour::Green() 
{
	RGB rgb = RGB(0, 255, 0);
	Colour c = Colour(rgb, 255);
	return c;
}
Colour Colour::Cyan() 
{
	RGB rgb = RGB(0, 255, 255);
	Colour c = Colour(rgb, 255);
	return c;
}
Colour Colour::Blue() 
{
	RGB rgb = RGB(0, 0, 255);
	Colour c = Colour(rgb, 255);
	return c;
}
Colour Colour::Magenta() 
{
	RGB rgb = RGB(255, 0, 255);
	Colour c = Colour(rgb, 255);
	return c;
}

Colour Colour::Orange()
{
	RGB rgb = RGB(255, 127.5, 0);
	Colour c = Colour(rgb, 255);
	return c;
}
Colour Colour::Violet()
{
	RGB rgb = RGB(127.5, 0, 255);
	Colour c = Colour(rgb, 255);
	return c;
}
Colour Colour::Brown()
{
	RGB rgb = RGB(150, 75, 0);
	Colour c = Colour(rgb, 255);
	return c;
}

Colour Colour::Lerp(Colour c1, Colour c2, double T) { return c1; }

HSV Colour::RGBToHSV(RGB rgb)
{
	HSV result = HSV(0,0,0);

	double r = rgb.r / 255;
	double g = rgb.g / 255;
	double b = rgb.b / 255;

	double cMax = Maths::Max(3, r, g, b);
	double cMin = Maths::Min(3, r, g, b);
	double diff = cMax - cMin;

	if (cMax == cMin) result.h = 0;
	else if (cMax == r) result.h = (double)((int)(60 * ((g - b) / diff) + 360) % 360);
	else if (cMax == g) result.h = (double)((int)(60 * ((b - r) / diff) + 120) % 360);
	else if (cMax == b) result.h = (double)((int)(60 * ((r - g) / diff) + 240) % 360);

	if (cMax == 0) result.s = 0;
	else result.s = (diff / cMax) * 100;

	result.v = cMax * 100;

	return result;
}

RGB Colour::HSVToRGB(HSV hsv)
{
	RGB result;
	double h = hsv.h;
	double s = hsv.s;
	double v = hsv.v;
	int i;
	double f, p, q, t;

	if (s = 0)
	{
		result = RGB(v, v, v);
		return result;
	}

	h /= 60;
	i = Maths::FloorToInt(h);
	f = h - i;
	p = v * (1 - s);
	q = v * (1 - s * f);
	t = v * (1 - s * (1 - f));

	switch (i)
	{
	case 0:
		result = RGB(v, t, p);
		break;
	case 1:
		result = RGB(q, v, p);
		break;
	case 2:
		result = RGB(p, v, t);
		break;
	case 3:
		result = RGB(p, q, v);
		break;
	case 4:
		result = RGB(t, p, v);
		break;
	default:
		result = RGB(v, p, q);
		break;
	}

	return result;
}