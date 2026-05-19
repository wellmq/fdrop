add_rules("mode.debug", "mode.release")

target("fdrop")
    set_kind("binary")
    add_files("src/*.cpp")
    set_targetdir("$(projectdir)")

