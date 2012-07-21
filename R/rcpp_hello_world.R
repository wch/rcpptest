
rcpp_hello_world <- function(){
	.Call( "rcpp_hello_world", PACKAGE = "rcpptest" )
}

rcpp_test <- function(){
  .Call( "rcpp_test", PACKAGE = "rcpptest" )
}
