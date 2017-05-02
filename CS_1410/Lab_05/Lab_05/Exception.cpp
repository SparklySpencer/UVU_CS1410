#include "Exception.h"

Exception::Exception(int ex)
{
	e = ex;
}

int Exception::GetExcetion() const
{
	return e;
}
