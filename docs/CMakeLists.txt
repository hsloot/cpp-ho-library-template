set(DOXYGEN_EXTRACT_ALL YES)
set(DOXYGEN_BUILTIN_STL_SUPPORT YES)

set(DOXYGEN_IN ${CMAKE_CURRENT_SOURCE_DIR}/../docs/Doxyfile.in)
set(DOXYGEN_OUT ${CMAKE_CURRENT_BINARY_DIR}/Doxyfile)
set(DOXYGEN_GENERATE_HTML YES)
set(DOXYGEN_GENERATE_LATEX NO)
set(DOXYGEN_HTML_HEADER ${PROJECT_SOURCE_DIR}/docs/doxystyle/header.html)
set(DOXYGEN_HTML_FOOTER ${PROJECT_SOURCE_DIR}/docs/doxystyle/footer.html)
set(DOXYGEN_HTML_EXTRA_STYLESHEET ${PROJECT_SOURCE_DIR}/docs/customdoxygen.css)
set(DOXYGEN_HTML_EXTRA_FILES
  ${PROJECT_SOURCE_DIR}/docs/doxy-boot.js)

configure_file(${DOXYGEN_IN} ${DOXYGEN_OUT} @ONLY)
message("Doxygen build started")


doxygen_add_docs(docs ${PROJECT_SOURCE_DIR}/include ${PROJECT_SOURCE_DIR}/docs/mainpage.md
  WORKING_DIRECTORY ${PROJECT_SOURCE_DIR}/docs
  COMMENT "Generate documentation")
