idf_component_register(
    SRCS 
    	"RAM_LITE_DB_MAIN.c"
    	"Main_Shell.c"
    PRIV_REQUIRES spi_flash
    INCLUDE_DIRS ""
)

# Add this to define the flag for C code
target_compile_definitions(${COMPONENT_LIB} PRIVATE RAM_LITE_CONSOLE=1)
