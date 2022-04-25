add_library(cls "")

target_sources(cls
    PRIVATE
        Element.cpp
        UMLAttribute.cpp
        UMLOperation.cpp
        UMLClassInterfaceTemplate.cpp
        UMLInterface.cpp
        UMLRelation.cpp
        UMLClass.cpp
        ClassDiagram.cpp
        Mess.cpp
        SequenceDiagram.cpp
        
  PUBLIC
    ${CMAKE_CURRENT_LIST_DIR}/Element.hpp
    ${CMAKE_CURRENT_LIST_DIR}/UMLAttribute.hpp
    ${CMAKE_CURRENT_LIST_DIR}/UMLOperation.hpp
    ${CMAKE_CURRENT_LIST_DIR}/UMLClassInterfaceTemplate.hpp
    ${CMAKE_CURRENT_LIST_DIR}/UMLInterface.hpp
    ${CMAKE_CURRENT_LIST_DIR}/UMLRelation.hpp
    ${CMAKE_CURRENT_LIST_DIR}/UMLClass.hpp
    ${CMAKE_CURRENT_LIST_DIR}/ClassDiagram.hpp
    ${CMAKE_CURRENT_LIST_DIR}/Mess.hpp
    ${CMAKE_CURRENT_LIST_DIR}/SequenceDiagram.hpp
  )
target_include_directories(cls
  PUBLIC
    ${CMAKE_CURRENT_LIST_DIR}
  )