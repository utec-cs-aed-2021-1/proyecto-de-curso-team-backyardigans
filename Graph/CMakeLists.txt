SET(TARGET_NAME graph)

add_library(${TARGET_NAME}
        DirectedGraph.h
        Structs.h
        UndirectedGraph.h
        graph.h)

SET_TARGET_PROPERTIES(graph PROPERTIES LINKER_LANGUAGE CXX)

target_include_directories(${TARGET_NAME}
  INTERFACE ./)

install(TARGETS ${TARGET_NAME}
  ARCHIVE DESTINATION lib/)
