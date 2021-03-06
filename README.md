# C Sandbox

## Setup for VSCode

### Extension

#### Required Extension

1. [C/C++ by Microsoft](https://marketplace.visualstudio.com/items?itemName=ms-vscode.cpptools)
2. [Code Runner by Jun Han](https://marketplace.visualstudio.com/items?itemName=formulahendry.code-runner)  

#### Setup

1. View > Command Palette...
2. Set `Compiler Path` to path of gcc.exe. Default: `C:/MinGW/bin/gcc.exe`
3. Edit `"externalConsole": true,` from **.vscode\launch.json**  to allow printf message to show during step debug.  

## C/C++ Compiler

1. Mingw-w64 from <https://jmeubank.github.io/tdm-gcc/download/>  

## Ceedling Setup

1. Download and install Ruby 3.0.2-1 (x64) without Devkit at <https://rubyinstaller.org/downloads/>.
2. Install ceedling by `gem install ceedling`.
3. Update `project.yml`
   - Change the executable from .out to .exe as .out (default) is for unix system.
   - Added `xml_tests_report` to enable [ceedling extension](https://marketplace.visualstudio.com/items?itemName=numaru.vscode-ceedling-test-adapter).

    ```yml
    :extension:
      :executable: .exe
    
    :plugins:
    :load_paths:
      - "#{Ceedling.load_path}"
    :enabled:
      - stdout_pretty_tests_report
      - module_generator
      - xml_tests_report  # To enable Vscode ceedlinge extension else will report 
                          # The required Ceedling plugin 'xml_tests_report' is not enabled. 
                          # You have to edit your 'project.xml' file to enable the plugin.
                          # see https://github.com/ThrowTheSwitch/Ceedling/blob/master/docs/CeedlingPacket.md#tool-element-runtime-substitution-notational-substitution
    ```

4. Ceedling plugin
   `Ceedling Explorer: Debug Configuration` will be using the debug config name at `launch.json`.
   For my case it's `gcc.exe - Build and debug active file`.

> [How to create ceedling project](https://github.com/jxwleong/HowToCreateCeedlingProject)  
  
## .vscode

### launch.json

Comment will cause github actions superlinter to fail, so put here as workaround.????

```json
{
    // Use IntelliSense to learn about possible attributes.
    // Hover to view descriptions of existing attributes.
    // For more information, visit: https://go.microsoft.com/fwlink/?linkid=830387
    "version": "0.2.0",
    "configurations": [
    
        {
            "name": "gcc.exe - Build and debug active file",
            "type": "cppdbg",
            "request": "launch",
            "program": "${workspaceFolder}\\build\\test\\out\\${command:ceedlingExplorer.debugTestExecutable}",
            "args": [],
            "stopAtEntry": false,
            "cwd": "C:/MinGW/bin",
            "environment": [],
            "externalConsole": true,
            "MIMode": "gdb",
            //"miDebuggerPath": "C:\\MinGW\\bin\\gdb.exe",
            // Using 64 bit gdb else will report error saying
            // executable format not recogzie bla2 ????
            "miDebuggerPath": "C:\\TDM-GCC-64\\bin\\gdb.exe",
            "setupCommands": [
                {
                    "description": "Enable pretty-printing for gdb",
                    "text": "-enable-pretty-printing",
                    "ignoreFailures": true
                }
            ],
            // use ceedling to link and compile the test file executable
            "preLaunchTask": "ceedling"
        }
    ]
}
```