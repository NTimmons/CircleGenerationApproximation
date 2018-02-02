#pragma once

#include <type_traits>
#include <iostream>
#include <string>
#include <vector>

struct OperationDef
{
	OperationDef(std::string _op, long double _added, long double _current)
	:_operation(_op), _addedError(_added), _currentError(_current)
	{}

	std::string _operation;
	long double _addedError;
	long double _currentError;
};

class FloatError
{
public:
	FloatError(float _x)
	{
		static int floatIDCounter = 0;

		m_name = "FloatID_";
		m_name.append(std::to_string(floatIDCounter));

		m_value = _x;
		m_accurateValue = _x;
		m_error = 0.0;
	}

	FloatError(float _x, long double _error)
	{
		static int floatIDCounter = 0;

		m_name = "FloatID_";
		m_name.append(std::to_string(floatIDCounter));

		m_value = _x;
		m_accurateValue = _x;
		m_error = _error;
	}

	FloatError(float _x, long double _error, long double _accurateVal)
	{
		static int floatIDCounter = 0;

		m_name = "FloatID_";
		m_name.append(std::to_string(floatIDCounter));

		m_value = _x;
		m_accurateValue = _accurateVal;
		m_error = _error;
	}

	FloatError()
	{
		static int floatIDCounter = 0;

		m_name = "FloatID_";
		m_name.append(std::to_string(floatIDCounter));

		m_value = 0.f;
		m_accurateValue = 0.f;
		m_error = 0.0;
	}

	~FloatError()
	{
		//std::cout << m_name.c_str() << " error was: " << m_error << "\n";
	}

	long double GetCumulativeError()
	{
		return ( (long double)m_value - m_accurateValue);
	}

	//Operators overload
	FloatError operator+(const FloatError& _in)
	{
		float val = m_value + _in.m_value;
		long double accurateVal = m_accurateValue + _in.m_accurateValue;
		
		long double error = ((long double)m_value + (long double)_in.m_value);

		error = abs((long double)val - error);
		m_error += error + _in.m_error;
		return FloatError(val, m_error, accurateVal);
	}

	FloatError operator-(const FloatError& _in)
	{
		float val = m_value - _in.m_value;
		long double accurateVal = m_accurateValue - _in.m_accurateValue;

		long double error = ((long double)m_value - (long double)_in.m_value);

		error = abs((long double)val - error);
		m_error += error + _in.m_error;
		return FloatError(val, m_error, accurateVal);
	}

	FloatError operator*(const FloatError& _in)
	{
		float val = m_value * _in.m_value;
		long double accurateVal = m_accurateValue * _in.m_accurateValue;

		long double error = ((long double)m_value * (long double)_in.m_value);

		error = abs((long double)val - error);
		m_error += error + _in.m_error;
		return FloatError(val, m_error, accurateVal);
	}

	FloatError operator/(const FloatError& _in)
	{
		float val = m_value / _in.m_value;
		long double accurateVal = m_accurateValue / _in.m_accurateValue;

		long double error = ((long double)m_value / (long double)_in.m_value);

		error = abs((long double)val - error);
		m_error += error + _in.m_error;

		return FloatError(val, m_error, accurateVal);
	}

	FloatError operator=(const FloatError& _in)
	{
		m_value = _in.m_value;
		m_error = _in.m_error;
		m_accurateValue = _in.m_accurateValue;
		return FloatError(m_value, m_error, m_accurateValue);
	}

	float m_value;
	long double m_accurateValue;
	long double m_error;
	
	// Additional output information.
	std::string m_name;
	std::vector<OperationDef> m_operationList;
};