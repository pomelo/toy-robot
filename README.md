This is a small demo using Plain C++, and the first taste of Google Test. This console program can read in commands of the following form:

    PLACE X,Y,F - Place a toy on a 5x5 table, 0 <= x, y <=4
    MOVE        - Move the toy towards its facing direction
    LEFT        - Turn the toy to left by 90 degrees
    RIGHT       - Turn the toy to right by 90 degrees
    REPORT      - Describe the position and direction of the toy

1. It's my first time to learn Google Test, which seems to be a handy test framework. To setup Google Test, follow these steps:

    1. make sure cmake is installed.
    2. Clone the repo
        ```
        git clone https://github.com/google/googletest.git
        ```
    3. make install directory 
        ```
        mkdir -p googletest/install 
        cd install 
        ```
    4. create make file
        ```
        cmake ../
        ```
    5. compiles Google Test & install
        ```
        make 
        make install
        ```

2. To compile this project, simply use the Makefile
    ```
    make
    ```

3. To run the tests, use the executable under the output folder
    ```
    ./output/tests
    ```

4. To run this project, use the executable under the output folder
    ```
    ./output/toy
    ```
