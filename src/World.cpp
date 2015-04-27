#include "World.hpp"
#include "Native.hpp"

namespace GTA
{
	void World::Weather::set(GTA::Weather value)
	{
		array<System::String ^> ^names = { "EXTRASUNNY", "CLEAR", "CLOUDS", "SMOG", "FOGGY", "OVERCAST", "RAIN", "THUNDER", "CLEARING", "NEUTRAL", "SNOW", "BLIZZARD", "SNOWLIGHT", "XMAS" };

		Native::Function::Call("SET_WEATHER_TYPE_NOW", names[static_cast<int>(value)]);
	}
	System::DateTime World::CurrentDate::get()
	{
		int year = Native::Function::Call<int>("GET_CLOCK_YEAR");
		int month = Native::Function::Call<int>("GET_CLOCK_MONTH");
		int day = Native::Function::Call<int>("GET_CLOCK_DAY_OF_MONTH");
		int hour = Native::Function::Call<int>("GET_CLOCK_HOURS");
		int minute = Native::Function::Call<int>("GET_CLOCK_MINUTES");
		int second = Native::Function::Call<int>("GET_CLOCK_SECONDS");

		return System::DateTime(year, month, day, hour, minute, second);
	}
	void World::CurrentDate::set(System::DateTime value)
	{
		Native::Function::Call("SET_CLOCK_DATE", value.Year, value.Month, value.Day);
		Native::Function::Call("SET_CLOCK_TIME", value.Hour, value.Minute, value.Second);
	}
	System::TimeSpan World::CurrentDayTime::get()
	{
		int hour = Native::Function::Call<int>("GET_CLOCK_HOURS");
		int minute = Native::Function::Call<int>("GET_CLOCK_MINUTES");
		int second = Native::Function::Call<int>("GET_CLOCK_SECONDS");

		return System::TimeSpan(hour, minute, second);
	}
	void World::CurrentDayTime::set(System::TimeSpan value)
	{
		Native::Function::Call("SET_CLOCK_TIME", value.Hours, value.Minutes, value.Seconds);
	}
	void World::GravityLevel::set(int value)
	{
		Native::Function::Call("SET_GRAVITY_LEVEL", value);
	}
}