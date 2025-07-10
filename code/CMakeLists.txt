cmake_minimum_required(VERSION 3.19)
project(objetos_agora_vai LANGUAGES CXX)

# Usa C++17
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Encontra os módulos necessários do Qt6
find_package(Qt6 REQUIRED COMPONENTS Core Gui Widgets Charts Network)

qt_standard_project_setup()

# Lista de arquivos do projeto
qt_add_executable(objetos_agora_vai
    main.cpp
    mainwindow.cpp
    mainwindow.h

    ativo.cpp
    ativo.h

    periodo.cpp
    periodo.h

    fonteexcel.cpp
    fonteexcel.h
    fontededados.h

    geradorgrafico.cpp
    geradorgrafico.h

    controladorgrafico.cpp
    controladorgrafico.h
)

# Linka com os módulos Qt corretos (inclusive Charts!)
target_link_libraries(objetos_agora_vai
    PRIVATE
        Qt6::Core
        Qt6::Gui
        Qt6::Widgets
        Qt6::Charts
        Qt6::Network
)
