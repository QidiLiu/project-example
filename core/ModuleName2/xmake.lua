target("ModuleName2")
    add_rules("mode.debug", "mode.release")
    set_kind("binary")
    set_optimize("fastest")
    set_warnings("all", "error")

    add_includedirs("$(scriptdir)/../..")
    modules = {
        "ModuleName1"
    }

    for i, v in ipairs(modules) do
        add_headerfiles(string.format("./../%s/**.h", v))
        add_files(string.format("./../%s/**.cpp", v))
    end

    add_headerfiles("**.h")
    add_files("**.cpp")
    add_files("test.cc")
