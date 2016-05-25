# Build example
add_executable(tests
  tests.cpp
  )
  
target_link_libraries(tests
  glfw
  ${GLFW_LIBRARIES}
  m)
add_dependencies(tests glfw ${COPY_BINARY})


