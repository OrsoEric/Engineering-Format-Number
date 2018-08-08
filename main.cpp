/****************************************************************
**	OrangeBot Projects
*****************************************************************
**        /
**       /
**      /
** ______ \
**         \
**          \
*****************************************************************
**	Engineering Format
*****************************************************************
**	Problem: formatting number with std::cout and std::ostringstream can be cumbersome
**	Problem: the best format for numbers is the engineering format, which is not natively supported
**	Solution: the most readable number format is the engineering format. Make class to support it.
****************************************************************/

/****************************************************************
**	DESCRIPTION
****************************************************************
**	Show a number in engineering notation
**	four sgnificant digit, 10^n*3 suffix, optional unit of measure
**	x.xxx s
**	xx.xx s
**	xxx.x s
**	Exponents
**	index	|	-6	-5	-4	-3	-2	-1	0	+1	+2	+3	+4	+5
**	exp		|	-18	-15	-12	-9	-6	-3	0	+3	+6	+9	+12	+15	+18
**	suffix	|	a	f	p	n	u	m		K	M	G	T	P	E
****************************************************************/

/****************************************************************
**	HISTORY VERSION
****************************************************************
**
****************************************************************/

/****************************************************************
**	KNOWN BUGS
****************************************************************
**
****************************************************************/

/****************************************************************
**	TODO
****************************************************************
**
****************************************************************/

/****************************************************************
**	INCLUDES
****************************************************************/

//Standard C Libraries
#include <stdlib.h> 	//for rand()
//Standard C++ Libraries
#include <iostream>		//for std::cout, std::endl
#include <string>		//for std::string
#include <sstream>		//for std::ostringstream

/****************************************************************
**	DEFINES
****************************************************************/

//Number of trials
#define NUM_TRIAL 100

/****************************************************************
**	MACROS
****************************************************************/

/****************************************************************
**	PROTOTYPES
****************************************************************/

/****************************************************************
**	GLOBAL VARIABILE
****************************************************************/

/****************************************************************
**	USING NAMESPACES
**	NOTE: Use only specific parts of a namespace. It's bad practice to use all of std.
****************************************************************/

using std::cout;
using std::endl;
using std::string;
using std::ostringstream;

/**********************************************************************************
**	PROTOTYPE: CLASSES
**********************************************************************************/

//Assign class to a namespace
namespace User
{

/****************************************************************************
**	Class
**	\class My_utils
*****************************************************************************
**	PARAMETER:
**	RETURN:
**	DESCRIPTION:
**	\brief
**	Class where I collect utility methods
****************************************************************************/

class My_utils
{
	//Visible to all
	public:
		///--------------------------------------------------------------------------
		///	CONSTRUCTORS
		///--------------------------------------------------------------------------

		///--------------------------------------------------------------------------
		///	DESTRUCTORS
		///--------------------------------------------------------------------------

		///--------------------------------------------------------------------------
		///	SETTERS
		///--------------------------------------------------------------------------

		///--------------------------------------------------------------------------
		///	GETTERS
		///--------------------------------------------------------------------------

		///--------------------------------------------------------------------------
		///	TESTERS
		///--------------------------------------------------------------------------

		///--------------------------------------------------------------------------
		///	PUBLIC METHODS
		///--------------------------------------------------------------------------

		//From number to engineering format number
		static string eng_num( double num );

		///--------------------------------------------------------------------------
		///	PUBLIC VARS
		///--------------------------------------------------------------------------

	//Visible to derived classes
	protected:
		///--------------------------------------------------------------------------
		///	PROTECTED METHODS
		///--------------------------------------------------------------------------

		///--------------------------------------------------------------------------
		///	PROTECTED VARS
		///--------------------------------------------------------------------------

	//Visible only inside the class
	private:
		///--------------------------------------------------------------------------
		///	PRIVATE METHODS
		///--------------------------------------------------------------------------

		///--------------------------------------------------------------------------
		///	PRIVATE VARS
		///--------------------------------------------------------------------------

};	//End Class:	My_utils

}; //End Namespace

/****************************************************************
**	FUNCTIONS
****************************************************************/

/****************************************************************
**	MAIN
****************************************************************
**	INPUT:
**	OUTPUT:
**	RETURN:
**	DESCRIPTION:
****************************************************************/

int main()
{
	///----------------------------------------------------------------
	///	STATIC VARIABILE
	///----------------------------------------------------------------

	///----------------------------------------------------------------
	///	LOCAL VARIABILE
	///----------------------------------------------------------------

	//counter
	register int t;

	//temp number
	double tmp;

	///----------------------------------------------------------------
	///	CHECK AND INITIALIZATIONS
	///----------------------------------------------------------------

	///----------------------------------------------------------------
	///	BODY
	///----------------------------------------------------------------

	cout << "Engineering Format" << endl;
	cout << "Four significant digit plus 10^3X suffix" << endl;
	cout << "It's the most readable way to represent numbers" << endl;

		///Fixed trial
	cout << endl << endl << "Fixed trials" << endl << endl;
	//Starting number
	tmp = 123456789.0 / 10000000000000.0;
	//For: every trial
	for (t = 0;t < NUM_TRIAL;t++)
	{
		//Print number in engineering format and number in regular format
		cout << User::My_utils::eng_num(tmp) << " " << tmp << endl;
		tmp = tmp *1.3;
	}	//End for: every trial

		///Random trials
	cout << endl << endl << "Random trials" << endl << endl;
	//For: every trial
	for (t = 0;t < NUM_TRIAL;t++)
	{
			///Generate Number
		//generate a number from -1.0 to +1.0
		tmp = 1.0 *(rand() -(RAND_MAX/2.0))/(RAND_MAX/2.0);
		//Elevate to an high odd power to increase range
		tmp = tmp *tmp *tmp *tmp *tmp;
		//Refactor to achieve order of magnitude of spread
		tmp = tmp *100000.0;

		//Print number in engineering format and number in regular format
		cout << User::My_utils::eng_num(tmp) << " " << tmp << endl;
	}	//End for: every trial

	///----------------------------------------------------------------
	///	FINALIZATIONS
	///----------------------------------------------------------------

    return 0;
}	//end function: main

/**********************************************************************************
**	METHODS
**********************************************************************************/

//Assign class to a namespace
namespace User
{

/****************************************************************************
**	Public Method
**	\class	eng_num | double
*****************************************************************************
**	PARAMETER:
**	RETURN:
**	DESCRIPTION:
**	\brief
**	Show a number in engineering notation
**	four sgnificant digit, 10^n*3 suffix, optional unit of measure
**	x.xxx [xU]
**	xx.xx [xU]
**	xxx.x [xU]
**	Exponents
**	index	|	-6	-5	-4	-3	-2	-1	0	+1	+2	+3	+4	+5
**	exp		|	-18	-15	-12	-9	-6	-3	0	+3	+6	+9	+12	+15	+18
**	suffix	|	a	f	p	n	u	m		K	M	G	T	P	E
****************************************************************************/

std::string My_utils::eng_num( double num )
{
	///--------------------------------------------------------------------------
	///	STATIC VARIABILE
	///--------------------------------------------------------------------------

	//exponents suffix string
	static const string suffix("afpnum KMGTPE");

	///--------------------------------------------------------------------------
	///	LOCAL VARIABILE
	///--------------------------------------------------------------------------

	//Continue flag
	bool f_continue;
	//sign flag
	bool f_sign;
	//Counter
	int cnt;
	//Number of digits after the point
	int precision;
	//Create a streaming string that supports the same operators as cout
	ostringstream tmp_str_stream;

	///--------------------------------------------------------------------------
	///	CHECK AND INITIALIZATIONS
	///--------------------------------------------------------------------------

	///--------------------------------------------------------------------------
	///	BODY
	///--------------------------------------------------------------------------
	//	ALGORITHM:
	//	multiply or divide by 1000 until the number is > 1.0 && < 1000.0
	//	create a string with the '.' in the right place and with the right suffix and unit if applicable

		///STEP1: Make num between >1.0 <1000.0 and calculate 10^3X suffix

	///While Init
	//if: input is exactly 0, i don't have to scale it
	f_continue = (num != 0.0);
	//if: number is negative
	if (num < 0.0)
	{
		//remember sign
		f_sign = true;
		//make positive
		num = -num;
	}
	else
	{
		//remember sign
		f_sign = false;
	}
	//initialize exponent counter
	cnt = 0;

	///Compute multiplier
	//while: i'm not done
	while (f_continue == true)
	{
		//if: too small
		if (num < 1.0)
		{
			//inflate by 10^3
			num = num *1000.0;
			cnt--;
		}
		//if: too big
		else if (num > 1000.0)
		{
			//shrink by 10^3
			num = num /1000.0;
			cnt++;
		}
		//if: sweet spot
		else
		{
			//done
			f_continue = false;
		}
		//if: i run out of suffixes
		if ((cnt > 6) || (cnt < -6))
		{
			//done
			f_continue = false;
			//fail. return local empty string
			return string("");
		}
	}	//end While: i'm not done

		///STEP2: print sign
	//Push the right sign into the string stream
	tmp_str_stream << ((f_sign)?('-'):('+'));

		///STEP3: print number with right precision
	///Precision
	//Algorithm prevents numbers lower than 1.0 or bigger than 1000.0 to exist by this point
	//Push the number inside the string stream
	if (num < 10.0)
	{
		//X.XXX
		precision = 3;
	}
	else if (num < 100.0)
	{
		//XX.XX
		precision = 2;
	}
	else
	{
		//XXX.X
		precision = 1;
	}

	///Format Settings
	//Show right number of digits after point
	tmp_str_stream.precision( precision );
	//Show floating point in fixed point format
	tmp_str_stream.setf( tmp_str_stream.fixed );
	//This is to fix representation of non meaningful zeros after point
	//left alignment
	tmp_str_stream.setf( tmp_str_stream.left );
	//Number is always five character wide
	tmp_str_stream.width( 5 );
	//Fill all spaces with number zero
	tmp_str_stream.fill('0');

	///Print Number
	//push number inside the string
	tmp_str_stream << num;

		///STEP4: Add Unit Suffix
	//I can access string with brackets. It's an overloading of std::string
	tmp_str_stream << suffix[cnt +6];

	///--------------------------------------------------------------------------
	///	RETURN
	///--------------------------------------------------------------------------

	//Convert from string stream to string. It's a local class, it will be destroyed when it goes out of scope. No memory leak.
	return tmp_str_stream.str();
}	//end method: eng_num

}; //End Namespace
