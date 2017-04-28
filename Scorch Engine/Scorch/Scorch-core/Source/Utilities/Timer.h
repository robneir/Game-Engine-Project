#ifndef _TIMER_
#define _TIMER_

#include <Windows.h>

namespace Scorch 
{
namespace Utilities
{
	class Timer
	{
	private:
		LARGE_INTEGER m_Start;
		double m_Frequency;
	public:
		Timer()
		{
			LARGE_INTEGER frequency;
			QueryPerformanceFrequency(&frequency);
			m_Frequency = 1.0 / frequency.QuadPart;
			QueryPerformanceCounter(&m_Start);
		}

		void Reset()
		{
			QueryPerformanceCounter(&m_Start);
		}

		double GetElapsedTime()
		{
			LARGE_INTEGER current;
			QueryPerformanceCounter(&current);
			unsigned __int64 cycles = current.QuadPart - m_Start.QuadPart;
			return (float)(cycles * m_Frequency);
		}


	};
}
}

#endif