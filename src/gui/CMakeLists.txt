set (CURRENT_DIR "src/gui")

set (farm_QT_HEADERS ${farm_QT_HEADERS}
        ${CURRENT_DIR}/farm.h
        PARENT_SCOPE
        )

set(farm_SRCS ${farm_SRCS}
        ${CURRENT_DIR}/FarmMain.cpp
        ${CURRENT_DIR}/farm.cpp
        PARENT_SCOPE
        )