#include <R.h>
#include <Rdefines.h>

// Needed for Windows stuff
// http://stackoverflow.com/questions/10062113/shgetfolderpath
#include <shlobj.h>

SEXP c_test(){
    // I think this should be wchar_t, but that won't compile for me
    TCHAR startupFolder[MAX_PATH];
    HRESULT hr = SHGetFolderPath(0, CSIDL_STARTUP, 0, 0, startupFolder);

    if (SUCCEEDED(hr)) {
        // Get short path
        TCHAR shortPath[MAX_PATH];
        GetShortPathName(startupFolder, shortPath, MAX_PATH);

        return mkString(shortPath);
    }
    else {
        // Return NULL if failed
        return R_NilValue;
    }
}
