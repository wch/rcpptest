#include <R.h>
#include <Rdefines.h>

#ifdef WIN32

#include <shlobj.h>
// SHGetFolderPath documentation:
// http://msdn.microsoft.com/en-us/library/windows/desktop/bb762181.aspx

SEXP get_folder_path() {
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

#else

SEXP get_folder_path() {
    return R_NilValue;
}

#endif