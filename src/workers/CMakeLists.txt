set (CURRENT_DIR "src/workers")

set (farm_QT_HEADERS ${farm_QT_HEADERS}
        PARENT_SCOPE
        )

set (farm_SRCS ${farm_SRCS}
        ${CURRENT_DIR}/Populator.cpp
        PARENT_SCOPE
        )