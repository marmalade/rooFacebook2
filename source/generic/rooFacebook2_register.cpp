/*
The rooFacebook2 Copyright

All of the documentation and software included in the rooFacebook2 is copyrighted by Artem Babenko http://www.roolez.com/

Copyright 2011-2012 Artem Babenko http://www.roolez.com/. All rights reserved.

Redistribution and use in source and binary forms, with or without modification, are permitted provided that the following conditions are met:

Redistributions of source code must retain the above copyright notice, this list of conditions and the following disclaimer.
Redistributions in binary form must reproduce the above copyright notice, this list of conditions and the following disclaimer in the documentation and/or other materials provided with the distribution.
All advertising materials mentioning features or use of this software must display the following acknowledgement:
This product includes software developed by Artem Babenko http://www.roolez.com/ and its contributors.
Neither the name of the Artem Babenko http://www.roolez.com/ nor the names of its contributors may be used to endorse or promote products derived from this software without specific prior written permission.

THIS SOFTWARE IS PROVIDED BY THE Artem Babenko http://www.roolez.com/ AND CONTRIBUTORS ``AS IS''
AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES
OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE
Artem Babenko http://www.roolez.com/ OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT,
INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO,
PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS
INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT
LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
*/

/*
 * WARNING: this is an autogenerated file and will be overwritten by
 * the extension interface script.
 */
/*
 * This file contains the automatically generated loader-side
 * functions that form part of the extension.
 *
 * This file is awlays compiled into all loaders but compiles
 * to nothing if this extension is not enabled in the loader
 * at build time.
 */
#include "IwDebug.h"
#include "rooFacebook2_autodefs.h"
#include "s3eEdk.h"
#include "rooFacebook2.h"
//Declarations of Init and Term functions
extern s3eResult rooFacebook2Init();
extern void rooFacebook2Terminate();


// On platforms that use a seperate UI/OS thread we can autowrap functions
// here.   Note that we can't use the S3E_USE_OS_THREAD define since this
// code is oftern build standalone, outside the main loader build.
#if defined I3D_OS_IPHONE || defined I3D_OS_OSX || defined I3D_OS_LINUX || defined I3D_OS_WINDOWS

static rooFacebook_Session * rooFacebook_init_wrap(const char* appId, rooFacebook_CallbackSpecific callback, void * userData)
{
    IwTrace(ROOFACEBOOK2_VERBOSE, ("calling rooFacebook2 func on main thread: rooFacebook_init"));
    return (rooFacebook_Session *)(intptr_t)s3eEdkThreadRunOnOS((s3eEdkThreadFunc)rooFacebook_init, 3, appId, callback, userData);
}

static rooFacebook_Session * rooFacebook_initWithUrlSchemeSuffix_wrap(const char* appId, const char * urlSchemeSuffix, rooFacebook_CallbackSpecific callback, void * userData)
{
    IwTrace(ROOFACEBOOK2_VERBOSE, ("calling rooFacebook2 func on main thread: rooFacebook_initWithUrlSchemeSuffix"));
    return (rooFacebook_Session *)(intptr_t)s3eEdkThreadRunOnOS((s3eEdkThreadFunc)rooFacebook_initWithUrlSchemeSuffix, 4, appId, urlSchemeSuffix, callback, userData);
}

static void rooFacebook_authorize_wrap(rooFacebook_Session * facebook, const char * permissions)
{
    IwTrace(ROOFACEBOOK2_VERBOSE, ("calling rooFacebook2 func on main thread: rooFacebook_authorize"));
    s3eEdkThreadRunOnOS((s3eEdkThreadFunc)rooFacebook_authorize, 2, facebook, permissions);
}

static const char * rooFacebook_getAccessToken_wrap(rooFacebook_Session * facebook)
{
    IwTrace(ROOFACEBOOK2_VERBOSE, ("calling rooFacebook2 func on main thread: rooFacebook_getAccessToken"));
    return (const char *)(intptr_t)s3eEdkThreadRunOnOS((s3eEdkThreadFunc)rooFacebook_getAccessToken, 1, facebook);
}

static int rooFacebook_getAccessExpires_wrap(rooFacebook_Session * facebook)
{
    IwTrace(ROOFACEBOOK2_VERBOSE, ("calling rooFacebook2 func on main thread: rooFacebook_getAccessExpires"));
    return (int)(intptr_t)s3eEdkThreadRunOnOS((s3eEdkThreadFunc)rooFacebook_getAccessExpires, 1, facebook);
}

static void rooFacebook_setAccessToken_wrap(rooFacebook_Session * facebook, const char * access_token)
{
    IwTrace(ROOFACEBOOK2_VERBOSE, ("calling rooFacebook2 func on main thread: rooFacebook_setAccessToken"));
    s3eEdkThreadRunOnOS((s3eEdkThreadFunc)rooFacebook_setAccessToken, 2, facebook, access_token);
}

static void rooFacebook_setAccessExpires_wrap(rooFacebook_Session * facebook, int access_expires)
{
    IwTrace(ROOFACEBOOK2_VERBOSE, ("calling rooFacebook2 func on main thread: rooFacebook_setAccessExpires"));
    s3eEdkThreadRunOnOS((s3eEdkThreadFunc)rooFacebook_setAccessExpires, 2, facebook, access_expires);
}

static void rooFacebook_extendAccessToken_wrap(rooFacebook_Session * facebook)
{
    IwTrace(ROOFACEBOOK2_VERBOSE, ("calling rooFacebook2 func on main thread: rooFacebook_extendAccessToken"));
    s3eEdkThreadRunOnOS((s3eEdkThreadFunc)rooFacebook_extendAccessToken, 1, facebook);
}

static void rooFacebook_extendAccessTokenIfNeeded_wrap(rooFacebook_Session * facebook)
{
    IwTrace(ROOFACEBOOK2_VERBOSE, ("calling rooFacebook2 func on main thread: rooFacebook_extendAccessTokenIfNeeded"));
    s3eEdkThreadRunOnOS((s3eEdkThreadFunc)rooFacebook_extendAccessTokenIfNeeded, 1, facebook);
}

static void rooFacebook_logout_wrap(rooFacebook_Session * facebook)
{
    IwTrace(ROOFACEBOOK2_VERBOSE, ("calling rooFacebook2 func on main thread: rooFacebook_logout"));
    s3eEdkThreadRunOnOS((s3eEdkThreadFunc)rooFacebook_logout, 1, facebook);
}

static void rooFacebook_deleteSession_wrap(rooFacebook_Session * facebook)
{
    IwTrace(ROOFACEBOOK2_VERBOSE, ("calling rooFacebook2 func on main thread: rooFacebook_deleteSession"));
    s3eEdkThreadRunOnOS((s3eEdkThreadFunc)rooFacebook_deleteSession, 1, facebook);
}

static int rooFacebook_isSessionValid_wrap(rooFacebook_Session * facebook)
{
    IwTrace(ROOFACEBOOK2_VERBOSE, ("calling rooFacebook2 func on main thread: rooFacebook_isSessionValid"));
    return (int)(intptr_t)s3eEdkThreadRunOnOS((s3eEdkThreadFunc)rooFacebook_isSessionValid, 1, facebook);
}

static rooFacebook_Dialog * rooFacebook_dialog_wrap(rooFacebook_Session * facebook, const char * action, rooFacebook_CallbackSpecific callback, void * userData)
{
    IwTrace(ROOFACEBOOK2_VERBOSE, ("calling rooFacebook2 func on main thread: rooFacebook_dialog"));
    return (rooFacebook_Dialog *)(intptr_t)s3eEdkThreadRunOnOS((s3eEdkThreadFunc)rooFacebook_dialog, 4, facebook, action, callback, userData);
}

static rooFacebook_Dialog * rooFacebook_dialogAndParams_wrap(rooFacebook_Session * facebook, const char * action, const char * params, rooFacebook_CallbackSpecific callback, void * userData)
{
    IwTrace(ROOFACEBOOK2_VERBOSE, ("calling rooFacebook2 func on main thread: rooFacebook_dialogAndParams"));
    return (rooFacebook_Dialog *)(intptr_t)s3eEdkThreadRunOnOS((s3eEdkThreadFunc)rooFacebook_dialogAndParams, 5, facebook, action, params, callback, userData);
}

static void rooFacebook_deleteDialog_wrap(rooFacebook_Dialog * dialog)
{
    IwTrace(ROOFACEBOOK2_VERBOSE, ("calling rooFacebook2 func on main thread: rooFacebook_deleteDialog"));
    s3eEdkThreadRunOnOS((s3eEdkThreadFunc)rooFacebook_deleteDialog, 1, dialog);
}

static rooFacebook_Request * rooFacebook_requestWithParams_wrap(rooFacebook_Session * facebook, const char * params, rooFacebook_CallbackSpecific callback, void * userData)
{
    IwTrace(ROOFACEBOOK2_VERBOSE, ("calling rooFacebook2 func on main thread: rooFacebook_requestWithParams"));
    return (rooFacebook_Request *)(intptr_t)s3eEdkThreadRunOnOS((s3eEdkThreadFunc)rooFacebook_requestWithParams, 4, facebook, params, callback, userData);
}

static rooFacebook_Request * rooFacebook_requestWithMethodName_wrap(rooFacebook_Session * facebook, const char * methodName, const char * params, const char * httpMethod, rooFacebook_CallbackSpecific callback, void * userData)
{
    IwTrace(ROOFACEBOOK2_VERBOSE, ("calling rooFacebook2 func on main thread: rooFacebook_requestWithMethodName"));
    return (rooFacebook_Request *)(intptr_t)s3eEdkThreadRunOnOS((s3eEdkThreadFunc)rooFacebook_requestWithMethodName, 6, facebook, methodName, params, httpMethod, callback, userData);
}

static rooFacebook_Request * rooFacebook_requestWithGraphPath_wrap(rooFacebook_Session * facebook, const char * graphPath, rooFacebook_CallbackSpecific callback, void * userData)
{
    IwTrace(ROOFACEBOOK2_VERBOSE, ("calling rooFacebook2 func on main thread: rooFacebook_requestWithGraphPath"));
    return (rooFacebook_Request *)(intptr_t)s3eEdkThreadRunOnOS((s3eEdkThreadFunc)rooFacebook_requestWithGraphPath, 4, facebook, graphPath, callback, userData);
}

static rooFacebook_Request * rooFacebook_requestWithGraphPathAndParams_wrap(rooFacebook_Session * facebook, const char * graphPath, const char * params, rooFacebook_CallbackSpecific callback, void * userData)
{
    IwTrace(ROOFACEBOOK2_VERBOSE, ("calling rooFacebook2 func on main thread: rooFacebook_requestWithGraphPathAndParams"));
    return (rooFacebook_Request *)(intptr_t)s3eEdkThreadRunOnOS((s3eEdkThreadFunc)rooFacebook_requestWithGraphPathAndParams, 5, facebook, graphPath, params, callback, userData);
}

static rooFacebook_Request * rooFacebook_requestWithGraphPathAndParamsAndHttpMethod_wrap(rooFacebook_Session * facebook, const char * graphPath, const char * params, const char * httpMethod, rooFacebook_CallbackSpecific callback, void * userData)
{
    IwTrace(ROOFACEBOOK2_VERBOSE, ("calling rooFacebook2 func on main thread: rooFacebook_requestWithGraphPathAndParamsAndHttpMethod"));
    return (rooFacebook_Request *)(intptr_t)s3eEdkThreadRunOnOS((s3eEdkThreadFunc)rooFacebook_requestWithGraphPathAndParamsAndHttpMethod, 6, facebook, graphPath, params, httpMethod, callback, userData);
}

static void rooFacebook_deleteRequest_wrap(rooFacebook_Request * request)
{
    IwTrace(ROOFACEBOOK2_VERBOSE, ("calling rooFacebook2 func on main thread: rooFacebook_deleteRequest"));
    s3eEdkThreadRunOnOS((s3eEdkThreadFunc)rooFacebook_deleteRequest, 1, request);
}

#define rooFacebook_init rooFacebook_init_wrap
#define rooFacebook_initWithUrlSchemeSuffix rooFacebook_initWithUrlSchemeSuffix_wrap
#define rooFacebook_authorize rooFacebook_authorize_wrap
#define rooFacebook_getAccessToken rooFacebook_getAccessToken_wrap
#define rooFacebook_getAccessExpires rooFacebook_getAccessExpires_wrap
#define rooFacebook_setAccessToken rooFacebook_setAccessToken_wrap
#define rooFacebook_setAccessExpires rooFacebook_setAccessExpires_wrap
#define rooFacebook_extendAccessToken rooFacebook_extendAccessToken_wrap
#define rooFacebook_extendAccessTokenIfNeeded rooFacebook_extendAccessTokenIfNeeded_wrap
#define rooFacebook_logout rooFacebook_logout_wrap
#define rooFacebook_deleteSession rooFacebook_deleteSession_wrap
#define rooFacebook_isSessionValid rooFacebook_isSessionValid_wrap
#define rooFacebook_dialog rooFacebook_dialog_wrap
#define rooFacebook_dialogAndParams rooFacebook_dialogAndParams_wrap
#define rooFacebook_deleteDialog rooFacebook_deleteDialog_wrap
#define rooFacebook_requestWithParams rooFacebook_requestWithParams_wrap
#define rooFacebook_requestWithMethodName rooFacebook_requestWithMethodName_wrap
#define rooFacebook_requestWithGraphPath rooFacebook_requestWithGraphPath_wrap
#define rooFacebook_requestWithGraphPathAndParams rooFacebook_requestWithGraphPathAndParams_wrap
#define rooFacebook_requestWithGraphPathAndParamsAndHttpMethod rooFacebook_requestWithGraphPathAndParamsAndHttpMethod_wrap
#define rooFacebook_deleteRequest rooFacebook_deleteRequest_wrap

#endif

void rooFacebook2RegisterExt()
{
    /* fill in the function pointer struct for this extension */
    void* funcPtrs[21];
    funcPtrs[0] = (void*)rooFacebook_init;
    funcPtrs[1] = (void*)rooFacebook_initWithUrlSchemeSuffix;
    funcPtrs[2] = (void*)rooFacebook_authorize;
    funcPtrs[3] = (void*)rooFacebook_getAccessToken;
    funcPtrs[4] = (void*)rooFacebook_getAccessExpires;
    funcPtrs[5] = (void*)rooFacebook_setAccessToken;
    funcPtrs[6] = (void*)rooFacebook_setAccessExpires;
    funcPtrs[7] = (void*)rooFacebook_extendAccessToken;
    funcPtrs[8] = (void*)rooFacebook_extendAccessTokenIfNeeded;
    funcPtrs[9] = (void*)rooFacebook_logout;
    funcPtrs[10] = (void*)rooFacebook_deleteSession;
    funcPtrs[11] = (void*)rooFacebook_isSessionValid;
    funcPtrs[12] = (void*)rooFacebook_dialog;
    funcPtrs[13] = (void*)rooFacebook_dialogAndParams;
    funcPtrs[14] = (void*)rooFacebook_deleteDialog;
    funcPtrs[15] = (void*)rooFacebook_requestWithParams;
    funcPtrs[16] = (void*)rooFacebook_requestWithMethodName;
    funcPtrs[17] = (void*)rooFacebook_requestWithGraphPath;
    funcPtrs[18] = (void*)rooFacebook_requestWithGraphPathAndParams;
    funcPtrs[19] = (void*)rooFacebook_requestWithGraphPathAndParamsAndHttpMethod;
    funcPtrs[20] = (void*)rooFacebook_deleteRequest;

    /*
     * Flags that specify the extension's use of locking and stackswitching
     */
    int flags[21] = { 0 };

    /*
     * Register the extension
     */
    s3eEdkRegister("rooFacebook2", funcPtrs, sizeof(funcPtrs), flags, rooFacebook2Init, rooFacebook2Terminate, 0);
}

#if !defined S3E_BUILD_S3ELOADER

#if defined S3E_EDK_USE_STATIC_INIT_ARRAY
int rooFacebook2StaticInit()
{
    void** p = g_StaticInitArray;
    void* end = p + g_StaticArrayLen;
    while (*p) p++;
    if (p < end)
        *p = (void*)&rooFacebook2RegisterExt;
    return 0;
}

int g_rooFacebook2Val = rooFacebook2StaticInit();

#elif defined S3E_EDK_USE_DLLS
S3E_EXTERN_C S3E_DLL_EXPORT void RegisterExt()
{
    rooFacebook2RegisterExt();
}
#endif

#endif
