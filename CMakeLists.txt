set(CMAKE_C_STANDARD 99)

set(CURRENT_EXE_NAME Time_Second)
set(SOURCE_FILES main.c second.c clock.c utc.c wristband.c alarm.c rtc.c week.c)
include_directories(${CMAKE_CURRENT_SOURCE_DIR}/alarm_test)
add_executable(${CURRENT_EXE_NAME} ${SOURCE_FILES})

# link against math library.
target_link_libraries(${CURRENT_EXE_NAME} m)
#install(TARGETS ${CURRENT_EXE_NAME} DESTINATION bin)

