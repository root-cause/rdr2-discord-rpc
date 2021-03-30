#pragma once
#include "pch.h"

namespace presencemod::honor
{
	// Source: https://alloc8or.re/rdr3/nativedb/?n=0xC48FE1971C9743FF
	struct StatId
	{
		alignas(8) Hash BaseId = 0;
		alignas(8) Hash PermutationId = 0;
	};

	int getCurrentHonor();
	int getHonorLevel(int);
}