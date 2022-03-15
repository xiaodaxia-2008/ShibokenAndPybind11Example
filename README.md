# Introduction
Qt5 uses shiboken2 to generate python bindings, if we have written a QCustomizedWidget inheriting some QWidget in c++, and we want to port it to python users, one way is to use shiboken2 to generate the binding codes. But what if we want to use pybind11 for some reasons, this example project demostrates how to solve this. It shows how to use pybind11 with shiboken2 when your project is bases on Qt5. 

# Dependencies
```shell
sudo apt install qt5-default qttools5-dev qtdeclarative5-dev
python3 -m pip install pyside2==5.15.2 shiboken2==5.15.2
```

# Build
```shell
mkdir build && cd build
cmake ..
```

# Run Example
In project root directory, run `python3 Example.py`