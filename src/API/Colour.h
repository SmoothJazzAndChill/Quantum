#pragma once
#ifndef COLOUR_H
#define COLOUR_H

#include "../Engine/PCH.h"
#include "Vector.h"

namespace Quantum
{
	struct HSV
	{
		HSV();
		HSV(double h, double s, double v);
		double h;
		double s;
		double v;

		void operator =(HSV hsv);
	};

	struct RGB
	{
		RGB();
		RGB(double r, double g, double b);
		double r;
		double g;
		double b;

		void operator =(RGB rgb);
	};
	
	class Colour
	{
	public:
		Colour();
		Colour(RGB rgb, double alpha);
		Colour(HSV hsv, double alpha);

		void operator =(Colour c);

		Colour operator +(Colour c);
		void operator +=(Colour c);

		Colour operator -(Colour c);
		void operator -=(Colour c);

		template<typename T>
		Colour operator *(T rhs);
		Colour operator *(Colour v);

		template<typename T>
		void operator *=(T rhs);
		void operator *=(Colour v);

		template<typename T>
		Colour operator /(T rhs);
		Colour operator /(Colour v);

		template<typename T>
		void operator /=(T rhs);
		void operator /=(Colour v);

		RGB rgb() const;
		HSV hsv() const;

		void Set(RGB rgb);
		void Set(RGB rgb, double a);
		void Set(HSV hsv);
		void Set(HSV hsv, double a);

		double a() const;
		void SetA(double a);

		template<typename T>
		Vector4 ToVector4();

		//255,255,255,255
		static Colour White();
		//127,127,127,255
		static Colour Grey();
		//0,0,0,255
		static Colour Black();
		//0,0,0,0
		static Colour Clear();

		//255,0,0
		static Colour Red();
		//255,255,0
		static Colour Yellow();
		//0,255,0
		static Colour Green();
		//0,255,255
		static Colour Cyan();
		//0,0,255
		static Colour Blue();
		//255,0,255
		static Colour Magenta();

		//255,127,0
		static Colour Orange();
		//127,0,255
		static Colour Violet();
		static Colour Brown();

		static Colour Lerp(Colour c1, Colour c2, double T);

		static HSV RGBToHSV(RGB rgb);
		static RGB HSVToRGB(HSV hsv);

	private:
		RGB _rgb;
		HSV _hsv;
		double _a;
	};	
}

#endif //!COLOUR_H