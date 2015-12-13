set (CURRENT_DIR "src/utils")

set (farm_QT_HEADERS ${farm_QT_HEADERS}
        PARENT_SCOPE
        )

set(farm_SRCS ${farm_SRCS}
        ${CURRENT_DIR}/Datparser.cpp
        PARENT_SCOPE
        )