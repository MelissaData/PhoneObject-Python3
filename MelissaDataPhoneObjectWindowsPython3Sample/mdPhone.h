/*
 * Melissa Data Phone Object for Windows/Linux/Solaris
 * Copyright 1993-2005 Melissa Data Corporation.
 *
 * Public interface
 */
#ifndef MDPHONE_H
#define MDPHONE_H

#ifndef MDAPI
#if defined(_WIN32) || defined(_WIN64)
#define MDAPI __declspec(dllimport)
#else
#define MDAPI
#endif
#endif

/*
 * C++ version of interface
 */
#if defined(__cplusplus) && !defined(MDCFORCE)

/*********************************
     Phone Check Interface
*********************************/

class MDAPI mdPhone
{
protected:
	struct mdPhone_ *I;
private:	/* disable implicit constructor and assignment */
	mdPhone(mdPhone &x);
	mdPhone& operator=(mdPhone &x);
public:
	#undef MDENUMS_H
	#include "mdEnums.h"
	mdPhone();
	~mdPhone();

	/* Setup methods */
	enum ProgramStatus Initialize(const char*);
	const char* GetInitializeErrorString();
	bool        SetLicenseString(const char*);
	const char* GetLicenseExpirationDate();
	const char* GetBuildNumber();
	const char* GetDatabaseDate();

	/* Processing methods */
	bool        Lookup(const char* phone, const char* zip=0);
	bool        CorrectAreaCode(const char* phone, const char* zip);
	double      ComputeDistance(double, double, double, double);
	double      ComputeBearing(double, double, double, double);

	/* Output methods */
	const char* GetAreaCode();
	const char* GetNewAreaCode();
	const char* GetPrefix();
	const char* GetSuffix();
	const char* GetExtension();
	const char* GetCity();
	const char* GetState();
	const char* GetCountyFips();
	const char* GetCountyName();
	const char* GetMsa();
	const char* GetPmsa();
	const char* GetTimeZone();
	const char* GetTimeZoneCode();
	const char* GetCountryCode();
	const char* GetLatitude();
	const char* GetLongitude();
	const char* GetDistance();	
	const char* GetResults();	
	const char* GetResultCodeDescription(const char* resultCode, enum ResultCdDescOpt opt=ResultCodeDescriptionLong);

	/* Deprecated Functions */
	const char* GetStatusCode();
	const char* GetErrorCode();
};

/*********************************
    Global Phone Check Interface
*********************************/
class MDAPI mdGlobalPhone
{
protected:
	struct mdGlobalPhone_ *I;
private:	/* disable implicit constructor and assignment */
	mdGlobalPhone(mdGlobalPhone &x);
	mdGlobalPhone& operator=(mdGlobalPhone &x);

public:
	#undef MDENUMS_H
	#include "mdEnums.h"
	mdGlobalPhone();
	~mdGlobalPhone();

	/* Setup methods */
	enum ProgramStatus Initialize(const char*);
	const char* GetInitializeErrorString();
	bool        SetLicenseString(const char*);
	const char* GetLicenseExpirationDate();
	const char* GetBuildNumber();	
	const char* GetDatabaseDate();

	/* Processing methods */
	bool        Lookup(const char* phone, const char* country=0, const char* origcountry=0);
	bool        LookupNext();

	/* Output methods */
	const char* GetPhoneNumber();
	const char* GetSubscriberNumber();
	const char* GetCountry();
	const char* GetCountryCode();
	const char* GetInternationalPrefix();
	const char* GetNationPrefix();
	const char* GetNationalDestinationCode();
	const char* GetLanguage();
	const char* GetAdministrativeArea();
	const char* GetLocality();	
	const char* GetUTC();
	const char* GetDST();
	const char* GetLatitude();
	const char* GetLongitude();

	const char* GetResults();		
	const char* GetResultCodeDescription(const char* resultCode, enum ResultCdDescOpt opt=ResultCodeDescriptionLong);
};

#else

/*
 * C version of interface
 */
#include "mdEnums.h"

typedef struct  mdPhone_ *mdPhone;

MDAPI mdPhone	mdPhoneCreate(void);
MDAPI void	mdPhoneDestroy(mdPhone);
MDAPI void	mdPhonePlsCompat(int n_mode);

/* Setup methods */
MDAPI enum mdProgramStatus mdPhoneInitialize(mdPhone, const char*);
MDAPI const char* mdPhoneGetInitializeErrorString(mdPhone);
MDAPI int         mdPhoneSetLicenseString(mdPhone, const char*);
MDAPI const char* mdPhoneGetLicenseExpirationDate(mdPhone);
MDAPI const char* mdPhoneGetBuildNumber(mdPhone);
MDAPI const char* mdPhoneGetDatabaseDate(mdPhone);

/* Processing methods */
MDAPI int         mdPhoneLookup(mdPhone, const char*, const char*);
MDAPI int         mdPhoneCorrectAreaCode(mdPhone, const char*, const char*);
MDAPI double      mdPhoneComputeDistance(mdPhone, double, double, double, double);
MDAPI double      mdPhoneComputeBearing(mdPhone, double, double, double, double);

/* Output methods */
MDAPI const char* mdPhoneGetAreaCode(mdPhone);
MDAPI const char* mdPhoneGetNewAreaCode(mdPhone);
MDAPI const char* mdPhoneGetPrefix(mdPhone);
MDAPI const char* mdPhoneGetSuffix(mdPhone);
MDAPI const char* mdPhoneGetExtension(mdPhone);
MDAPI const char* mdPhoneGetCity(mdPhone);
MDAPI const char* mdPhoneGetState(mdPhone);
MDAPI const char* mdPhoneGetCountyFips(mdPhone);
MDAPI const char* mdPhoneGetCountyName(mdPhone);
MDAPI const char* mdPhoneGetMsa(mdPhone);
MDAPI const char* mdPhoneGetPmsa(mdPhone);
MDAPI const char* mdPhoneGetTimeZone(mdPhone);
MDAPI const char* mdPhoneGetTimeZoneCode(mdPhone);
MDAPI const char* mdPhoneGetCountryCode(mdPhone);
MDAPI const char* mdPhoneGetLatitude(mdPhone);
MDAPI const char* mdPhoneGetLongitude(mdPhone);
MDAPI const char* mdPhoneGetDistance(mdPhone);
MDAPI const char* mdPhoneGetStatusCode(mdPhone);
MDAPI const char* mdPhoneGetErrorCode(mdPhone);
MDAPI const char* mdPhoneGetResults(mdPhone);
MDAPI const char* mdPhoneGetResultCodeDescription(mdPhone, const char* resultCode, enum mdResultCdDescOpt opt);


/*
 * Global Phone Check Interface
 */

#include "mdEnums.h"
typedef struct  mdGlobalPhone_ *mdGlobalPhone;

MDAPI mdGlobalPhone	mdGlobalPhoneCreate(void);
MDAPI void			mdGlobalPhoneDestroy(mdGlobalPhone);

/* Setup methods */
MDAPI enum mdProgramStatus mdGlobalPhoneInitialize(mdGlobalPhone, const char*);
MDAPI const char*	mdGlobalPhoneGetInitializeErrorString(mdGlobalPhone);
MDAPI int			mdGlobalPhoneSetLicenseString(mdGlobalPhone, const char*);
MDAPI const char*	mdGlobalPhoneGetLicenseExpirationDate(mdGlobalPhone);
MDAPI const char*	mdGlobalPhoneGetBuildNumber(mdGlobalPhone);
MDAPI const char*	mdGlobalPhoneGetDatabaseDate(mdGlobalPhone);

/* Processing methods */
MDAPI int			mdGlobalPhoneLookup(mdGlobalPhone, const char*, const char*, const char*);
MDAPI int			mdGlobalPhoneLookupNext(mdGlobalPhone);

/* Output methods */
MDAPI const char*	mdGlobalPhoneGetPhoneNumber(mdGlobalPhone);
MDAPI const char*	mdGlobalPhoneGetSubscriberNumber(mdGlobalPhone);
MDAPI const char*	mdGlobalPhoneGetCountry(mdGlobalPhone);
MDAPI const char*	mdGlobalPhoneGetCountryCode(mdGlobalPhone);
MDAPI const char*	mdGlobalPhoneGetInternationalPrefix(mdGlobalPhone);
MDAPI const char*	mdGlobalPhoneGetNationPrefix(mdGlobalPhone);
MDAPI const char*	mdGlobalPhoneGetNationalDestinationCode(mdGlobalPhone);
MDAPI const char*	mdGlobalPhoneGetLanguage(mdGlobalPhone);
MDAPI const char*	mdGlobalPhoneGetAdministrativeArea(mdGlobalPhone);
MDAPI const char*	mdGlobalPhoneGetLocality(mdGlobalPhone);
MDAPI const char*	mdGlobalPhoneGetUTC(mdGlobalPhone);
MDAPI const char*	mdGlobalPhoneGetDST(mdGlobalPhone);
MDAPI const char*	mdGlobalPhoneGetLatitude(mdGlobalPhone);
MDAPI const char*	mdGlobalPhoneGetLongitude(mdGlobalPhone);

MDAPI const char*	mdGlobalPhoneGetResults(mdGlobalPhone);
MDAPI const char*	mdGlobalPhoneGetResultCodeDescription(mdGlobalPhone, const char* resultCode, enum mdResultCdDescOpt opt);

#endif /* __cplusplus */

#endif /* MDPHONE_H */
