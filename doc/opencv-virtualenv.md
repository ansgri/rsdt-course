Based on the following materials:
* https://medium.com/p/bf4d82220313
* http://stackoverflow.com/questions/17931726/ascii-codec-cant-decode-error-when-use-pip-to-install-uwsgi

Instal virtualenv

    sudo pip install virtualenv

Create and activate your virtualenv named «venv»

    mkdir venv
    virtualenv --copy venv
    cd venv
    source bin/activate

Install scipy (required by opencv python bindings)

    sudo apt-get install libatlas-base-dev gfortran
    LC_ALL=C pip install numpy scipy

Assuming you have unpacked opencv source to OPENCV_DIR, build opencv (from within virtualenv!):

    cd OPENCV_DIR
    mkdir build.user
    cd build.user
    cmake -D CMAKE_BUILD_TYPE=RELEASE -D CMAKE_INSTALL_PREFIX=$VIRTUAL_ENV/local/ -D PYTHON_EXECUTABLE=$VIRTUAL_ENV/bin/python -D PYTHON_PACKAGES_PATH=$VIRTUAL_ENV/lib/python2.7/site-packages -D INSTALL_PYTHON_EXAMPLES=ON ..
    make -j3 install

Now run python and enter following code to check version:

    import cv2
    print cv2.__version__
