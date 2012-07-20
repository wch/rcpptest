
rcpp_hello_world <- function(){
	.Call( "rcpp_hello_world", PACKAGE = "anRpackage" )
}

rcpp_test <- function(){
  .Call( "rcpp_test", PACKAGE = "anRpackage" )
}
