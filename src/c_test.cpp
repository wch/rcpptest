#include <R.h>
#include <Rdefines.h>

// This is taken from http://tolstoy.newcastle.edu.au/R/e2/devel/06/11/1242.html
// A hack to undefine the Realloc macro, which is defined by R and by Windows stuff
#undef Realloc
// Another hack to undefine the Free macro
#undef Free

// Needed for Windows stuff
// http://stackoverflow.com/questions/10062113/shgetfolderpath
#include <shlobj.h>

extern "C" SEXP c_test(){
    // I think this should be wchar_t, but that won't compile for me
    char startupFolder[MAX_PATH];
    HRESULT hr = SHGetFolderPath(0, CSIDL_STARTUP, 0, 0, startupFolder);

    if (SUCCEEDED(hr)) {
        // Get short path
        char shortPath[MAX_PATH];
        GetShortPathName(startupFolder, shortPath, MAX_PATH);

        return mkString(shortPath);
    }
    else {
        // Return NULL if failed
        return R_NilValue;
    }
}
