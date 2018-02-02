#pragma once
#include <array>
#include "helper.h"



template<typename T>
static constexpr T cos_approx(const T _x) noexcept
{
	return ((1.00000000922939569214520361128961667*(1.0)) + (-0.00000040038351959167077379411758820*(_x)) + (-0.49999581902513079434413612034404650*(_x* _x)) + (-0.00001868808381795402666814172321086*(_x* _x * _x)) + (0.04171125229782790544419412981369533*(_x* _x * _x * _x)) + (-0.00006331374243904154216523727516375*(_x* _x * _x * _x * _x)) + (-0.00133230596002621454881920115553839*(_x* _x * _x * _x * _x * _x)) + (-0.00003250491185282628451994405005543*(_x* _x * _x * _x * _x * _x * _x)) + (0.00003666795841889910768365487547804*(_x* _x * _x * _x * _x * _x * _x * _x)) + (-0.00000258872188337465851184506469840*(_x* _x * _x * _x * _x * _x * _x * _x * _x)) + (-0.00000000060839243653413992793179150*(_x* _x * _x * _x * _x * _x * _x * _x * _x * _x)));
}

template<typename T>
static constexpr T sin_approx(const T _x) noexcept
{
	return ((-0.00000000064690956972212391391747053*(1.0)) + (1.00000003320329367006991105881752446*(_x)) + (-0.00000040994246018193569577601803773*(_x* _x)) + (-0.16666448961862406763501098794222344*(_x* _x * _x)) + (-0.00000622424996446996101848734075923*(_x* _x * _x * _x)) + (0.00834406368773692695695043397563495*(_x* _x * _x * _x * _x)) + (-0.00001186714484661257391245100384358*(_x* _x * _x * _x * _x * _x)) + (-0.00018972798584677026114894693442636*(_x* _x * _x * _x * _x * _x * _x)) + (-0.00000423366245181830420089190772370*(_x* _x * _x * _x * _x * _x * _x * _x)) + (0.00000410233980333327290143099683184*(_x* _x * _x * _x * _x * _x * _x * _x * _x)) + (-0.00000026116504773674288632879852620*(_x* _x * _x * _x * _x * _x * _x * _x * _x * _x)));
}


template<typename T>
static constexpr T sin_approx_1(const T _x) noexcept
{
	return ((0.63411206370122119579946229350753129*(1.0)) + (0.00180362810570462196724239589684657*(_x)));
}

template<typename T>
static constexpr T sin_approx_2(const T _x) noexcept
{
	return ((-0.05039318423411790620614070235205872*(1.0)) + (1.31233507117186665169583648093976080*(_x)) + (-0.41777468470396011968048810558684636*(_x* _x)));
}

template<typename T>
static constexpr T sin_approx_3(const T _x) noexcept
{
	return ((-0.04987307487343569517568298010701255*(1.0)) + (1.31034057575871787371113441622583196*(_x)) + (-0.41618438160939502656887611919955816*(_x* _x)) + (-0.00033797402187770022663829139197844*(_x* _x * _x)));
}

template<typename T>
static constexpr T sin_approx_4(const T _x) noexcept
{
	return ((0.00130389241324155389506467273008639*(1.0)) + (0.98261292522179788377911791030783206*(_x)) + (0.05448418424418018796151486071721592*(_x* _x)) + (-0.23381099243266778575645048476872034*(_x* _x * _x)) + (0.03721357361149765091701269170698652*(_x* _x * _x * _x)));
}

template<typename T>
static constexpr T sin_approx_5(const T _x) noexcept
{
	return ((0.00128282919100716524991867562022207*(1.0)) + (0.98281574985627895291173672376316972*(_x)) + (0.05403070072958710001742588246997911*(_x* _x)) + (-0.23342520989237894313284016334364424*(_x* _x * _x)) + (0.03707518651419114408263055793213425*(_x* _x * _x * _x)) + (0.00001764616217344582523355277225985*(_x* _x * _x * _x * _x)));
}

template<typename T>
static constexpr T sin_approx_6(const T _x) noexcept
{
	return ((-0.00001671184082613849528281893541681*(1.0)) + (1.00038672717918486476662565110018477*(_x)) + (-0.00214675820606848380411868504324957*(_x* _x)) + (-0.16170432508544826943897021465090802*(_x* _x * _x)) + (-0.00581659841563121095264765614274438*(_x* _x * _x * _x)) + (0.01205236625089425687995525748874570*(_x* _x * _x * _x * _x)) + (-0.00127881998232273123676516757285526*(_x* _x * _x * _x * _x * _x)));
}

template<typename T>
static constexpr T sin_approx_7(const T _x) noexcept
{
	return ((-0.00001634516043208604610436143755869*(1.0)) + (1.00038009384751802599566872231662273*(_x)) + (-0.00211809497841153283534398887866246*(_x* _x)) + (-0.16175517872218753145929781567247119*(_x* _x * _x)) + (-0.00577197844097547280856064233489633*(_x* _x * _x * _x)) + (0.01203187496000217640568230592634791*(_x* _x * _x * _x * _x)) + (-0.00127410146949291950765892345032171*(_x* _x * _x * _x * _x * _x)) + (-0.00000042976571944038545060087753123*(_x* _x * _x * _x * _x * _x * _x)));
}

template<typename T>
static constexpr T sin_approx_8(const T _x) noexcept
{
	return ((0.00000012768551856449798190865877346*(1.0)) + (0.99999543512162458736014514215639792*(_x)) + (0.00003933375911739343415212885601839*(_x* _x)) + (-0.16681095181124358517443795335566392*(_x* _x * _x)) + (0.00027949814854613848347231197521978*(_x* _x * _x * _x)) + (0.00801661063662397095630485210904226*(_x* _x * _x * _x * _x)) + (0.00021974489802353147508209851856975*(_x* _x * _x * _x * _x * _x)) + (-0.00029202868006305058136765073761865*(_x* _x * _x * _x * _x * _x * _x)) + (0.00002323916857247873890882604308583*(_x* _x * _x * _x * _x * _x * _x * _x)));
}

template<typename T>
static constexpr T sin_approx_9(const T _x) noexcept
{
	return ((0.00000012415075926461402946845752251*(1.0)) + (0.99999553875897861932031673859455623*(_x)) + (0.00003860195560336173207453130951095*(_x* _x)) + (-0.16680876759666335429344030671927612*(_x* _x * _x)) + (0.00027609797856187085363793842773816*(_x* _x * _x * _x)) + (0.00801964853694500309777559721169382*(_x* _x * _x * _x * _x)) + (0.00021812995607926077596024072580150*(_x* _x * _x * _x * _x * _x)) + (-0.00029152422302223992677666641881729*(_x* _x * _x * _x * _x * _x * _x)) + (0.00002315372679552261321361990298318*(_x* _x * _x * _x * _x * _x * _x * _x)) + (0.00000000605274579728484965536875311*(_x* _x * _x * _x * _x * _x * _x * _x * _x)));
}

template<typename T>
static constexpr T sin_approx_10(const T _x) noexcept
{
	return ((-0.00000000064690956972212391391747053*(1.0)) + (1.00000003320329367006991105881752446*(_x)) + (-0.00000040994246018193569577601803773*(_x* _x)) + (-0.16666448961862406763501098794222344*(_x* _x * _x)) + (-0.00000622424996446996101848734075923*(_x* _x * _x * _x)) + (0.00834406368773692695695043397563495*(_x* _x * _x * _x * _x)) + (-0.00001186714484661257391245100384358*(_x* _x * _x * _x * _x * _x)) + (-0.00018972798584677026114894693442636*(_x* _x * _x * _x * _x * _x * _x)) + (-0.00000423366245181830420089190772370*(_x* _x * _x * _x * _x * _x * _x * _x)) + (0.00000410233980333327290143099683184*(_x* _x * _x * _x * _x * _x * _x * _x * _x)) + (-0.00000026116504773674288632879852620*(_x* _x * _x * _x * _x * _x * _x * _x * _x * _x)));
}

template<typename T>
static constexpr T cos_approx_1(const T _x) noexcept
{
	return ((1.21585997086344566042726000887341797*(1.0)) + (-0.77424412011466126060099668393377215*(_x)));
}

template<typename T>
static constexpr T cos_approx_2(const T _x) noexcept
{
	return ((1.21426539252361087584120014071231708*(1.0)) + (-0.77119119238461297793918447496253066*(_x)) + (-0.00097322038825760185960095371981993*(_x* _x)));
}

template<typename T>
static constexpr T cos_approx_3(const T _x) noexcept
{
	return ((0.99099785025660080961529274645727128*(1.0)) + (0.08498660909236299687563587212935090*(_x)) + (-0.68364323216711120334565521261538379*(_x* _x)) + (0.14508223638927780774210418712755200*(_x* _x * _x)));
}

template<typename T>
static constexpr T cos_approx_4(const T _x) noexcept
{
	return ((0.99111706874875937778313073067693040*(1.0)) + (0.08422315634384701377168624958358123*(_x)) + (-0.68254679367724746530399215771467425*(_x* _x)) + (0.14453835302356762837483472594612977*(_x* _x * _x)) + (0.00008669028996885503734071837245168*(_x* _x * _x * _x)));
}

template<typename T>
static constexpr T cos_approx_5(const T _x) noexcept
{
	return ((1.00015888613588210809268730372423306*(1.0)) + (-0.00284345132615635614106719408766821*(_x)) + (-0.48787975359694302213142691471148282*(_x* _x)) + (-0.02106666417319153980503010359370819*(_x* _x * _x)) + (0.05949217196906651100585250446783903*(_x* _x * _x * _x)) + (-0.00757497472021174522022191055725671*(_x* _x * _x * _x * _x)));
}

template<typename T>
static constexpr T cos_approx_6(const T _x) noexcept
{
	return ((1.00015585881069157814238224091241136*(1.0)) + (-0.00280251913472447881231497390785989*(_x)) + (-0.48801062090507602020394983810547274*(_x* _x)) + (-0.02089958792393016226429658388497046*(_x* _x * _x)) + (0.05939225409201191047126044963988534*(_x* _x * _x * _x)) + (-0.00754693942897357271382130505799068*(_x* _x * _x * _x * _x)) + (-0.00000297905479992673411743600055124*(_x* _x * _x * _x * _x * _x)));
}

template<typename T>
static constexpr T cos_approx_7(const T _x) noexcept
{
	return ((0.99999845377881002583819736173609272*(1.0)) + (0.00004497366503313687450095817443874*(_x)) + (-0.50031489550474261829293709524790756*(_x* _x)) + (0.00093037198914509594994265428979929*(_x* _x * _x)) + (0.04023822066463358243515457957073522*(_x* _x * _x * _x)) + (0.00124936477660389077398717105893411*(_x* _x * _x * _x * _x)) + (-0.00202849684518903363578123943966602*(_x* _x * _x * _x * _x * _x)) + (0.00018448569323736529177761023223781*(_x* _x * _x * _x * _x * _x * _x)));
}

template<typename T>
static constexpr T cos_approx_8(const T _x) noexcept
{
	return ((0.99999849215286629178223165581584908*(1.0)) + (0.00004407758940387754330661462809360*(_x)) + (-0.50030986970085089549087342675193213*(_x* _x)) + (0.00091859439312594174699422300278684*(_x* _x * _x)) + (0.04025231778596616988297185457668093*(_x* _x * _x * _x)) + (0.00124001108126038260201506879809585*(_x* _x * _x * _x * _x)) + (-0.00202501687906547159917503009296524*(_x* _x * _x * _x * _x * _x)) + (0.00018380640360864835582133114399994*(_x* _x * _x * _x * _x * _x * _x)) + (0.00000005413643682108236825995450578*(_x* _x * _x * _x * _x * _x * _x * _x)));
}

template<typename T>
static constexpr T cos_approx_9(const T _x) noexcept
{
	return ((1.00000000952011558474907815252663568*(1.0)) + (-0.00000041085347359975989113705405024*(_x)) + (-0.49999572814559800626454943994758651*(_x* _x)) + (-0.00001902418427297241629086652081604*(_x* _x * _x)) + (0.04171190997703201619462021199069568*(_x* _x * _x * _x)) + (-0.00006406947846304747440620425136260*(_x* _x * _x * _x * _x)) + (-0.00133177017408985529436926675828090*(_x* _x * _x * _x * _x * _x)) + (-0.00003274204956340421554571509799025*(_x* _x * _x * _x * _x * _x * _x)) + (0.00003673175824313024807150560024915*(_x* _x * _x * _x * _x * _x * _x * _x)) + (-0.00000259826431776509967871199163758*(_x* _x * _x * _x * _x * _x * _x * _x * _x)));
}

template<typename T>
static constexpr T cos_approx_10(const T _x) noexcept
{
	return ((1.00000000922939569214520361128961667*(1.0)) + (-0.00000040038351959167077379411758820*(_x)) + (-0.49999581902513079434413612034404650*(_x* _x)) + (-0.00001868808381795402666814172321086*(_x* _x * _x)) + (0.04171125229782790544419412981369533*(_x* _x * _x * _x)) + (-0.00006331374243904154216523727516375*(_x* _x * _x * _x * _x)) + (-0.00133230596002621454881920115553839*(_x* _x * _x * _x * _x * _x)) + (-0.00003250491185282628451994405005543*(_x* _x * _x * _x * _x * _x * _x)) + (0.00003666795841889910768365487547804*(_x* _x * _x * _x * _x * _x * _x * _x)) + (-0.00000258872188337465851184506469840*(_x* _x * _x * _x * _x * _x * _x * _x * _x)) + (-0.00000000060839243653413992793179150*(_x* _x * _x * _x * _x * _x * _x * _x * _x * _x)));
}



namespace ApproxImpl
{
	//Compile time factorials to save some time and make sure everything as accurate as possible at compile time.
	template<typename T>
	constexpr T factorial(int n)
	{
		return (T)(n <= 1 ? 1 : (n * factorial<T>((int)n - 1)));
	}

	template<typename T>
	constexpr T float_recp(T n)
	{
		return T(1.0) / n;
	}
	//////////////////////////////////////////////////////////////////////////////////////////////

	// so here is a manually constexpr friendly version.
	template<typename T>
	constexpr T approxSin_4nTaylor_NoPow(T x)
	{
		return x - ((x*x*x)						* float_recp(factorial<T>(3))) +
			((x*x*x*x*x)					* float_recp(factorial<T>(5))) -
			((x*x*x*x*x*x*x)				* float_recp(factorial<T>(7))) +
			((x*x*x*x*x*x*x*x*x)			* float_recp(factorial<T>(9))) -
			((x*x*x*x*x*x*x*x*x*x*x)		* float_recp(factorial<T>(11))) +
			((x*x*x*x*x*x*x*x*x*x*x*x*x)	* float_recp(factorial<T>(13)));
	}

	// so here is a manually constexpr friendly version.
	template<typename T>
	constexpr T approxCos_4nTaylor_NoPow(T x)
	{
		return x - ((x*x)						* float_recp(factorial<T>(2))) +
			((x*x*x*x)					* float_recp(factorial<T>(4))) -
			((x*x*x*x*x*x)				* float_recp(factorial<T>(6))) +
			((x*x*x*x*x*x*x*x)			* float_recp(factorial<T>(8))) -
			((x*x*x*x*x*x*x*x*x*x)		* float_recp(factorial<T>(10))) +
			((x*x*x*x*x*x*x*x*x*x*x*x)	* float_recp(factorial<T>(12)));
	}

	template <typename T, int numVerts, T(*approxSin)(T), T(*approxCos)(T)>
	std::array<std::pair<T, T>, numVerts> GenerateCircleVertices_A(T _radius, std::pair<T, T> _offset)
	{
		std::array<std::pair<T, T>, numVerts> points;

		T theta = 0.f;
		T thetaStep = (T)(PI) / (T)numVerts;
		for (int i = 0; i < numVerts; i++)
		{
			T x = (_radius * approxCos(theta)) + _offset.first;
			T y = (_radius * approxSin(theta)) + _offset.second;

			points[i] = std::make_pair(x, y);

			theta += thetaStep;
		}
		return points;
	}

	template <typename T, int numVerts, T(*approxSin)(T), T(*approxCos)(T)>
	std::array<std::pair<T, T>, numVerts> GenerateCircleVertices_B(T _radius, std::pair<T, T> _offset)
	{
		std::array<std::pair<T, T>, numVerts> points;

		T thetaStep = (T)(PI) / (T)numVerts;
		std::pair<T, T> movingPos = std::make_pair((T)_radius + _offset.first, (T)_radius + +_offset.second);
		for (int i = 0; i < numVerts; i++)
		{
			movingPos = rotate2d<T, approxSin, approxCos>(thetaStep, movingPos.first, movingPos.second);
			points[i] = movingPos;
		}

		return points;
	}

	template<typename T, T(*approxSin)(T), T(*approxCos)(T) >
	std::pair<T, T> rotate2d(T _rads, T _xpos, T _ypos)
	{
		T Mat2D[2][2];
		T newX, newY;

		Mat2D[0][0] = approxCos(_rads);
		Mat2D[0][1] = -approxSin(_rads);
		Mat2D[1][0] = approxSin(_rads);
		Mat2D[1][1] = approxCos(_rads);

		newX = (Mat2D[0][0] * _xpos) + (Mat2D[0][1] * _ypos);
		newY = (Mat2D[1][0] * _xpos) + (Mat2D[1][1] * _ypos);

		return std::make_pair(newX, newY);
	}



}