set(TARGET_NAME tests)

set(UNIT_TEST_LIST
  main
  UndirectedGraph
  DirectedGraph
  AStar
  BFS
  DFS
  Dijkstra
  Kruskal
  Prim
  )

foreach(NAME IN LISTS UNIT_TEST_LIST)
  list(APPEND UNIT_TEST_SOURCE_LIST ${NAME}.cpp)
endforeach()


add_executable(${TARGET_NAME}
  ${UNIT_TEST_SOURCE_LIST})

target_compile_options(${TARGET_NAME}
  PRIVATE -fmax-errors=1)

target_link_libraries(${TARGET_NAME}
  PUBLIC graph)

target_include_directories(${TARGET_NAME}
  PUBLIC ../externals/catch2)
