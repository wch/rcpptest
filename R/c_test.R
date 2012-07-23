
get_folder_path <- function(){
  .Call( "get_folder_path", PACKAGE = "rcpptest" )
}
