# executable : test1
# -- Version
set(test1_maj_ver 0)
set(test1_min_ver 0)
set(test1_pat_ver 1)

set(test1_lib_ver
    "${test1_maj_ver}.${test1_min_ver}.${test1_pat_ver}")

set(test1_lib_compat_ver
    "${test1_maj_ver}.${test1_min_ver}")

# -- Include dependencies
# --- LLVM
hunter_add_package(LLVM)
projmsg("Found LLVM_ROOT: ${LLVM_ROOT}")
file(GLOB llvm_libs ${LLVM_ROOT}/lib/lib*.a)
projmsg("Found LLVM libs: ${llvm_libs}")

if (APPLE)
  include (FindCurses)
  projmsg("Found needed NCurses library: ${CURSES_LIBRARIES}")
  list(APPEND llvm_libs ${CURSES_LIBRARIES})
endif()

# -- Headers
# internal
set(test1_int_hdr
    )

# -- Sources
set(test1_src
    src/test1/main.cpp)

# -- Targets
# --- executable
add_exe(test1 ${test1_src} ${test1_int_hdr})
add_inc_dir(test1 ${LLVM_ROOT}/include)
add_comp_def(test1 TEST1_MAJ=${test1_maj_ver})
add_comp_def(test1 TEST1_MIN=${test1_min_ver})
add_comp_def(test1 TEST1_PAT=${test1_pat_ver})
link_libs(test1 ${llvm_libs})
set_tgt_ver(test1 ${test1_lib_ver} ${test1_lib_compat_ver})

# -- Install!
install_tgt(test1)

add_dependencies(check test1)