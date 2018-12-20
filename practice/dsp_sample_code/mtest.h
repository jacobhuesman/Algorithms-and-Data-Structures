/*******************************************************************************
 * @file    mtest.h
 * @author  Jacob Huesman
 *  ******************************************************************************/

#ifndef MTEST_H
#define MTEST_H

#if defined(MTEST_ENABLE) && (MTEST_ENABLE == 1)
#define MPRINT_ENABLE 1
#else
#define MT_ASSERT(FNCALL) { FNCALL; }
#endif

#define PASS(...) PRINT("[" ANSI_GREEN "PASS" ANSI_RESET "] ", __VA_ARGS__);
#define FAIL(...) PRINT("[" ANSI_RED   "FAIL" ANSI_RESET "] ", __VA_ARGS__);

#ifndef MT_ASSERT
#define MT_ASSERT(ASSERTION)  \
{                             \
    if (ASSERTION)            \
    {                         \
        PASS(#ASSERTION);     \
    }                         \
    else                      \
    {                         \
        FAIL(#ASSERTION);     \
    }                         \
}
#endif

#ifndef MT_ASSERT_EQ
#define MT_ASSERT_EQ(STATEMENT, VALUE)                                  \
{                                                                       \
	if (STATEMENT == VALUE)                                             \
	{                                                                   \
		PASS(#STATEMENT " equals " #VALUE);                             \
	}                                                                   \
	else                                                                \
	{                                                                   \
		FAIL("%i not equal to " #VALUE ", actual value: ", STATEMENT);  \
	}                                                                   \
}
#endif

#endif // MTEST_H