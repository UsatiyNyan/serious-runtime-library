cpmaddpackage(
        NAME serious-meta-library
        GIT_REPOSITORY "git@github.com:UsatiyNyan/serious-meta-library.git"
        GIT_TAG main)
cpmaddpackage(
        NAME spdlog
        GIT_REPOSITORY "git@github.com:gabime/spdlog.git"
        GIT_TAG v1.17.0
        OPTIONS
        "SPDLOG_FMT_EXTERNAL ON"
        )

sl_target_link_system_libraries(${PROJECT_NAME}
        INTERFACE
        serious-meta-library
        spdlog::spdlog
)
