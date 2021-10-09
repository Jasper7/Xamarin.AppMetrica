using System;
using ObjCRuntime;

namespace YandexMetricaIOS
{
	[Native]
	public enum YMMErrorReportingOptions : ulong
	{
		YMMErrorReportingOptionsNoBacktrace = 1 << 0
	}

	[Native]
	public enum YMMYandexMetricaEventErrorCode : ulong
	{
		InitializationError = 1000,
		InvalidName = 1001,
		JsonSerializationError = 1002,
		InvalidRevenueInfo = 1003,
		EmptyUserProfile = 1004,
		NoCrashLibrary = 1005,
		InternalInconsistency = 1006
	}

	[Native]
	public enum YMMGenderType : ulong
	{
		Male,
		Female,
		Other
	}
}
