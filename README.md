# Features  
Supports conversion of a non negative base 10 integer to any target base between 2 and 10 (inclusively).  
![IntegerConversion](https://user-images.githubusercontent.com/26939775/190873526-155b9e58-ed11-449a-b5d0-bca194035224.png)

# How to use  
1. Clone the repo : `git clone https://github.com/AlexandreBrown/IntegerBaseConversion.git`
1. Navigate to the repo folder you just cloned : `cd IntegerBaseConversion/`
1. Create a `lib` folder : `mkdir lib/`
1. Navigate to the lib folder : `cd lib/`
1. Clone GoogleTest repo : `git clone https://github.com/google/googletest`
1. Navigate back to the root of the repo : `cd ..`
1. Create a `build` folder : `mkdir build/`
1. Navigate to the `build` folder : `cd build/`
1. Generate Makefile using cmake : `cmake ..`
1. Generate executable : `make`
1. Give execute permission to the executable : `chmod +x IntegerBaseConversion`
1. Run the executable : `./IntegerBaseConversion <NUMBER_IN_BASE_10> <TARGET_BASE>` eg: `./IntegerBaseConversion 123 2`
