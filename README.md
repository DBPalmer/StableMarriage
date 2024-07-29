
# Palmer, Deuce CS2353 Project

cd Palmer,Deuce-Project

cd Palmer,Deuce-Implementation

cd DataGenerator

g++ main.cpp -o a.out

./a.out 100 SetA.txt SetB.txt

mv SetA.txt ../

mv SetB.txt ../

cd -

mv SetA.txt  CS2353FinalProject/

mv SetB.txt  CS2353FinalProject/

cd CS2353FinalProject

g++ Element.cpp SetOfElements.cpp StableMatchSet.cpp main.cpp -o a.out

./a.out SetA.txt SetB.txt

