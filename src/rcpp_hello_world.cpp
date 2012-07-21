#include "rcpp_hello_world.h"


// This is taken from http://tolstoy.newcastle.edu.au/R/e2/devel/06/11/1242.html
// A hack to undefine the Realloc macro, which is defined by R and by Windows stuff
#undef Realloc
// Another hack to undefine the Free macro
#undef Free

// Needed for Windows stuff
// http://stackoverflow.com/questions/10062113/shgetfolderpath
#include <shlobj.h>

// Uncomment if you want to use cout
//#include <iostream>


SEXP rcpp_hello_world(){
    using namespace Rcpp ;
    
    CharacterVector x = CharacterVector::create( "foo", "bar" )  ;
    NumericVector y   = NumericVector::create( 0.0, 1.0 ) ;
    List z            = List::create( x, y ) ;
    return z ;
}

SEXP rcpp_test(){
    using namespace std;

    // I think this should be wchar_t, but that won't compile for me
    char startupFolder[MAX_PATH];
    HRESULT hr = SHGetFolderPath(0, CSIDL_STARTUP, 0, 0, startupFolder);

    if (SUCCEEDED(hr)) {
        //wcout << L"Startup folder = " << startupFolder << endl;

        // Get short path
        char shortPath[MAX_PATH];
        GetShortPathName(startupFolder, shortPath, MAX_PATH);

        // Convert to a string object so wrap() can process it
        std::string sfString(shortPath);

        return Rcpp::wrap(sfString);
    }
    else {
        //cout << "Error when getting startup folder";

        // Return NULL if failed
        return R_NilValue;
    }
}

