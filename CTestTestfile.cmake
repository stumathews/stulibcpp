# CMake generated Testfile for 
# Source directory: /home/stuart/cmake
# Build directory: /home/stuart/cmake
# 
# This file includes the relevant testing commands required for 
# testing this directory and lists subdirectories to be tested as well.
add_test(TutorialRuns "Tutorial" "")
add_test(TutorialConstructor "Tutorial" "")
set_tests_properties(TutorialConstructor PROPERTIES  PASS_REGULAR_EXPRESSION "Default constructor called")
subdirs("MathLib")
