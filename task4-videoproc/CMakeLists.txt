project(task4-videoproc)
find_package(OpenCV REQUIRED)
add_executable(videoproc
  src/videoproc_main.cpp
  src/visualizer.h
  src/bgfg.h
  src/bgfg.cpp
  src/optflow.h
  src/optflow.cpp
)

target_link_libraries(videoproc
  ${OpenCV_LIBS}
  jsoncpp
)
