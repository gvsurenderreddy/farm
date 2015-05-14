
set (CURRENT_DIR "src/data")

set (farm_QT_HEADERS ${farm_QT_HEADERS}
#     ${CURRENT_DIR}/DBGameSets.h
#     ${CURRENT_DIR}/DatabaseHelper.h
#     ${CURRENT_DIR}/setcontainers.h
#     ${CURRENT_DIR}/setobjects.h
    PARENT_SCOPE
)


set(farm_SRCS ${farm_SRCS}
    ${CURRENT_DIR}/DBGameSets.cpp
    ${CURRENT_DIR}/DatabaseHelper.cpp
    ${CURRENT_DIR}/setcontainers.cpp
    ${CURRENT_DIR}/setobjects.cpp
    PARENT_SCOPE
)
