#!/usr/bin/env python

import methods

executable_name = 'hello_vulkan'
executable_dir = '#bin'

available_platforms = methods.detect_platoforms()

# -----------

""" Get Arguments """
platform = ARGUMENTS.get('platform', 0)
target = ARGUMENTS.get('target', "debug")
vulkan_SDK_path = ARGUMENTS.get('vulkan_lib_path', "")

""" Arguments check """
if platform in available_platforms:
    string_platforms = ""
    for p in available_platforms:
        string_platforms += p + ", "
    print "The argument platform should be " + string_platforms
    Exit(9553) #Invalid property

debug = target == 'debug'

# TODO improve compilation by removing this requirment
if vulkan_SDK_path == "":
    print "Please set vulkan_lib_path. EG: C:\VulkanSDK\1.1.73.0"
    Exit(9553) #Invalid property

""" Create directories """
Execute(Mkdir('bin'))
Execute(Mkdir('shaders/bin'))

""" Compile shaders """
# TODO please move this inside the SCsub of directory shaders
vulkan_glslangValidator_path = ""
if platform == 'windows':
    vulkan_glslangValidator_path = vulkan_SDK_path + r"\bin\glslangValidator"
elif platform == 'linux':
    vulkan_glslangValidator_path = vulkan_SDK_path + r"/bin/glslangValidator"

Execute(vulkan_glslangValidator_path + " -V ./shaders/shader.vert -o ./shaders/bin/vert.spv")
Execute(vulkan_glslangValidator_path + " -V ./shaders/shader.frag -o ./shaders/bin/frag.spv")
""" ~Compile shaders """

""" Project building """
env = Environment()

env.executable_name = executable_name
env.executable_dir = executable_dir
env.platform = platform
env.debug = debug
env.vulkan_SDK_path = vulkan_SDK_path

env.__class__.add_source_files = methods.add_source_files
env.__class__.add_library = methods.add_library
env.__class__.add_program = methods.add_program
env.__class__.disable_warnings = methods.disable_warnings

# Load module list of engine
env.module_list = methods.detect_modules()

# default include path
env.Append(CPPPATH=[ '#libs', '#' ])

if debug:
    env.Append(CPPDEFINES=['DEBUG_ENABLED'])

env.Prepend(LIBS=[vulkan_library_name])
env.Prepend(LIBPATH=[vulkan_lib_path])

Export('env')

""" Script executions """
SConscript("servers/SCsub")
SConscript("modules/SCsub")

# build platform
SConscript("platforms/" + platform + "/SCsub")

