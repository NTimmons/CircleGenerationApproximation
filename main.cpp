#include "floatcomp.h"
#include <random>
#include <array>
#include <sstream>
#include <iomanip>
#include "helper.h"

#include "CircleGen_Approx.h"
#include "CircleGen_Real.h"

void clearfile(std::string _name)
{
	std::ofstream ofs;
	ofs.open(_name.c_str(), std::ofstream::out | std::ofstream::trunc);
	ofs.close();
}

float getRandom(float min, float max)
{
	float x = min + ((float)rand() / ((float)RAND_MAX / max));
	return x;
}

#define float FloatError
float Sum(std::array<float, 200>& _in)
{
	float err(0.0);
	for (auto i : _in)
	{
		err = err + i;
	}
	return err;
}
float MulDiv(std::array<float, 200>& _in)
{
	float err(1.f);
	for (auto i : _in)
	{
		err = err * i;
		err = err / i;
	}
	return err;
}
#define float float

ErrorDetails TestFloatErrorMulDiv(const float _min = 0.f, const float _max = 1000.f, const int _sampleCount = 1000)
{
	std::array<FloatError, 200> numbers;
	float lo = _min;
	float hi = _max;
	long double minRoundingErr = 1000000.f;
	long double maxRoundingErr = 0.f;

	long double minCumulativeErr = 1000000.f;
	long double maxCumulativeErr = 0.f;

	for (int j = 0; j < _sampleCount; j++)
	{
		for (int i = 0; i < 200; i++)
		{
			numbers[i] = getRandom(lo, hi);
		}

		FloatError errRes = MulDiv(numbers);
		long double cumulativeError = errRes.GetCumulativeError();
		minCumulativeErr = std::min(minCumulativeErr, cumulativeError);
		maxCumulativeErr = std::max(maxCumulativeErr, cumulativeError);
		minRoundingErr = std::min(minRoundingErr, errRes.m_error);
		maxRoundingErr = std::max(maxRoundingErr, errRes.m_error);
	}

	return ErrorDetails(_min, _max, minRoundingErr, maxRoundingErr, minCumulativeErr, maxCumulativeErr);
}

ErrorDetails TestFloatErrorSum(const float _min = 0.f, const float _max = 1000.f, const int _sampleCount = 1000)
{
	std::array<FloatError, 200> numbers;
	float lo = _min;
	float hi = _max;
	long double minRoundingErr = 1000000.f;
	long double maxRoundingErr = 0.f;

	long double minCumulativeErr = 1000000.f;
	long double maxCumulativeErr = 0.f;

	for (int j = 0; j < _sampleCount; j++)
	{
		for (int i = 0; i < 200; i++)
		{
			numbers[i] = getRandom(lo, hi);
		}

		FloatError errRes = Sum(numbers);
		long double cumulativeError = errRes.GetCumulativeError();
		minCumulativeErr	= std::min(minCumulativeErr, cumulativeError);
		maxCumulativeErr	= std::max(maxCumulativeErr, cumulativeError);
		minRoundingErr		= std::min(minRoundingErr, errRes.m_error);
		maxRoundingErr		= std::max(maxRoundingErr, errRes.m_error);
	}

	return ErrorDetails(_min, _max, minRoundingErr, maxRoundingErr, minCumulativeErr, maxCumulativeErr);
}


std::vector<long double> GetRadii(long double _min, long double _max)
{
	std::vector<long double> rads;
	long double counter = _min;
	while (counter < _max)
	{
		rads.push_back(counter);
		counter *=2.0;
	}

	return rads;

}

#define vertexCount 3600
void TestCircleReal()
{
	std::vector<long double> radii = GetRadii(0.25, 10000000.0);
	//std::array<long double, 8> radii = { 1.0, 10.0, 100.0, 1000.0, 10000.0, 100000.0, 1000000.0, 10000000.0 };
	std::vector<std::string> errorResults;
	for (auto off : radii)
	{
		for (auto i : radii)
		{
			auto absolute	= RealImpl::GenerateCircleVertices_B<long double, vertexCount>( i, std::make_pair(off, off)				);
			auto comparison = RealImpl::GenerateCircleVertices_B<float, vertexCount>		((float)i, std::make_pair(float(off), float(off)) );
			VertexComparison vc = VertexComparison::Compare(absolute, comparison);
			vc.offset = off;
			vc.radius = i;
			errorResults.push_back(vc.ToString());
		}
	}
	clearfile("Results/FloatRoundingCumulativeError_CircleGeometry_B.txt");
	WriteLog(VertexComparison::GetTitles(), "Results/FloatRoundingCumulativeError_CircleGeometry_B.txt");
	for (auto a : errorResults)
	{
		WriteLog(a, "Results/FloatRoundingCumulativeError_CircleGeometry_B.txt");
	}

	errorResults.clear();
	for (auto off : radii)
	{
		for (auto i : radii)
		{
			auto absolute   = RealImpl::GenerateCircleVertices_A<long double, vertexCount>(i, std::make_pair(off, off));
			auto comparison = RealImpl::GenerateCircleVertices_A<float, vertexCount>((float)i, std::make_pair((float)off, (float)off));
			VertexComparison vc = VertexComparison::Compare(absolute, comparison);
			vc.offset = off;
			vc.radius = i;
			errorResults.push_back(vc.ToString());
		}
	}
	clearfile("Results/FloatRoundingCumulativeError_CircleGeometry_A.txt");
	WriteLog(VertexComparison::GetTitles(), "Results/FloatRoundingCumulativeError_CircleGeometry_A.txt");
	for (auto a : errorResults)
	{
		WriteLog(a, "Results/FloatRoundingCumulativeError_CircleGeometry_A.txt");
	}

	//Verification Test
	errorResults.clear();
	for (auto off : radii)
	{
		for (auto i : radii)
		{
			auto absolute	= RealImpl::GenerateCircleVertices_A<long double, vertexCount>(i, std::make_pair(off, off));
			auto comparison = RealImpl::GenerateCircleVertices_A<double, vertexCount>(i, std::make_pair((double)off, (double)off));
			VertexComparison vc = VertexComparison::Compare(absolute, comparison);
			vc.offset = off;
			vc.radius = i;
			errorResults.push_back(vc.ToString());
		}
	}
	clearfile("Results/FloatRoundingCumulativeError_CircleGeometry_A_VERIFICATION.txt");
	WriteLog(VertexComparison::GetTitles(), "Results/FloatRoundingCumulativeError_CircleGeometry_A_VERIFICATION.txt");
	for (auto a : errorResults)
	{
		WriteLog(a, "Results/FloatRoundingCumulativeError_CircleGeometry_A_VERIFICATION.txt");
	}
}

template<typename T, T(*approxSin)(T), T(*approxCos)(T), int order_name>
void TestCircleApprox()
{
	std::vector<long double> radii = GetRadii(0.25, 10000000.0);
	std::vector<std::string> errorResults;
	for (auto off : radii)
	{
		for (auto i : radii)
		{
			auto comparison = ApproxImpl::GenerateCircleVertices_B<long double, vertexCount, approxSin, approxCos>(i, std::make_pair(off, off));
			auto absolute   = RealImpl::GenerateCircleVertices_B<long double, vertexCount>(i, std::make_pair(off, off));
			VertexComparison vc = VertexComparison::Compare(absolute, comparison);
			vc.offset = off;
			vc.radius = i;
			errorResults.push_back(vc.ToString());
		}
	}

	std::string filename = "Results/FloatRoundingCumulativeError_CircleGeometry_B_Approx";
	filename.append(std::to_string(order_name));
	filename.append(".txt");
	clearfile(filename);
	WriteLog(VertexComparison::GetTitles(), filename);
	for (auto a : errorResults)
	{
		WriteLog(a, filename);
	}
	errorResults.clear();

	for (auto off : radii)
	{
		for (auto i : radii)
		{
			auto comparison  = ApproxImpl::GenerateCircleVertices_A<long double, vertexCount, approxSin, approxCos>(i, std::make_pair(off, off));
			auto absolute    = RealImpl::GenerateCircleVertices_A<long double, vertexCount>(i, std::make_pair(off, off));
			VertexComparison vc = VertexComparison::Compare(absolute, comparison);
			vc.offset = off;
			vc.radius = i;
			errorResults.push_back(vc.ToString());
		}
	}

	filename = "Results/FloatRoundingCumulativeError_CircleGeometry_A_Approx";
	filename.append(std::to_string(order_name));
	filename.append(".txt");
	clearfile(filename);
	WriteLog(VertexComparison::GetTitles(), filename);
	for (auto a : errorResults)
	{
		WriteLog(a, filename);
	}
}


int main()
{
	TestCircleReal();
	TestCircleApprox<long double, sin_approx_1 , cos_approx_1 , 1>();
	TestCircleApprox<long double, sin_approx_2 , cos_approx_2 , 2>();
	TestCircleApprox<long double, sin_approx_3 , cos_approx_3 , 3>();
	TestCircleApprox<long double, sin_approx_4 , cos_approx_4 , 4>();
	TestCircleApprox<long double, sin_approx_5 , cos_approx_5 , 5>();
	TestCircleApprox<long double, sin_approx_6 , cos_approx_6 , 6>();
	TestCircleApprox<long double, sin_approx_7 , cos_approx_7 , 7>();
	TestCircleApprox<long double, sin_approx_8 , cos_approx_8 , 8>();
	TestCircleApprox<long double, sin_approx_9 , cos_approx_9 , 9>();
	TestCircleApprox<long double, sin_approx_10, cos_approx_10, 10>();
	TestCircleApprox<long double, sin_approx   , cos_approx   , 11>();

	std::array<std::pair<float, float>, 8> combined =	{
															std::make_pair(0.f, 1.f),
															std::make_pair(0.f, 10.f),
															std::make_pair(0.f, 100.f),
															std::make_pair(0.f, 1000.f),
															std::make_pair(0.f, 10000.f),
															std::make_pair(0.f, 100000.f),
															std::make_pair(0.f, 1000000.f),
															std::make_pair(0.f, 10000000.f)
														};

	//SUM TEST
	//////////////////////////////
	std::vector<std::string> data;
	for (auto a : combined)
	{
		ErrorDetails err = TestFloatErrorSum(a.first, a.second);
		data.push_back(err.ToString());
	}

	WriteLog(ErrorDetails::GetTitles(), "FloatRoundingCumulativeError_Sum.txt");
	for (auto a : data)
	{
		WriteLog(a, "FloatRoundingCumulativeError_Sum.txt");
	}

	//MULDIV TEST
	//////////////////////////////
	data.clear();
	for (auto a : combined)
	{
		ErrorDetails err = TestFloatErrorMulDiv(a.first, a.second);
		data.push_back(err.ToString());
	}

	WriteLog(ErrorDetails::GetTitles(), "FloatRoundingCumulativeError_MulDiv.txt");
	for (auto a : data)
	{
		WriteLog(a, "FloatRoundingCumulativeError_MulDiv.txt");
	}
	
	system("PAUSE");

	return 0;
}