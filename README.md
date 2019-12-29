# Lightweight Templated Vector Library

This simple vector/matrix library is designed to be simple to include, with all code simply being in the .h file.

**This was written with the goals of brevity and ease of use, there is no error checking, this was not optimized for execution speed or mimimizing RAM usage. this was not written to handle every possible requirement. this is not documented, or written for ease of comprehension, nor are there many comments.**

the goal was to keep each under 100 lines of code.

## compiling
most applications will not need to compile anything here, as all code is in header files. Simply #include the header, and compile your project.
The vectors library in tvec3.h do not require the other headers, this may be the only file you need.
the matrix3 and matrix4 headers require the the vector3 header, but neither requires the other matrix header.

The repository includes a simple test app, which can be compiled using cmake.

```
mkdir build
cd build
cmake ../src/
make
./tester >../testerOutput.txt
```
read tester.C for details.


## origin
On pages 534 to 557 of the book "Graphics Gems IV", Jean-François Doué provided a useful library of most of the matrix and vector functions that are used everyday in 3d graphics.
(http://www.realtimerendering.com/resources/GraphicsGems/gems.html#gemsiv)
(http://www.realtimerendering.com/resources/GraphicsGems/gemsiv/vec_mat/)

this was very brief and useful, but I needeed a version that was templated and had a determinant function, and I could not quickly find one, so I wrote this one.

I hope it is useful to you.
