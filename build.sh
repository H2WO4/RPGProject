# Generate build folder
mkdir build
cd build

# Clear existing data
rm -rf sources
rm -rf objects
rm -rf resources

# Create new folders
mkdir sources
mkdir objects
mkdir resources

# Copy files to sources folder
for i in `find ../RPGProject -iname '*.hpp'`; do cp $i sources; done
for i in `find ../RPGProject -iname '*.cpp'`; do cp $i sources; done
for i in `find ../RPGProject/Resources -iname '*'`; do cp $i resources; done

# Build objects
cd objects
g++ -std=c++11 -g -fgnu-runtime -O -c ../sources/*.cpp

# Link objects to a binary
cd ..
g++ -o rpgproject objects/*.o -lsfml-graphics -lsfml-audio -lsfml-window -lsfml-network -lsfml-system

# Go back to home folder
cd ..

