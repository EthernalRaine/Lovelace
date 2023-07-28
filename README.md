# Lovelace

Small, extensible and versatile base. 
<img align="right" height="128" alt="Ada Lovelace" src="https://cumslut.lol/content/cdn/IZOCGFwqxLld.png" />

Lovelace is a small, C++17, internal gamehacking project template. 
Designed to be versatile yet compact, Lovelace's design goal was to be able quickly get started with a new project, without having to write required boilerplate code.

## How to create a new Application using Lovelace

### Using the "QuickStart" Template

1. Copy the "example" project from the QuickStart folder, in the root of the repo, to Source/[ApplicationName]
2. Rename the ".vcxproj", ".vcxproj.filters" and ".vcxproj.user" files to the desired ApplicationName
3. Add the Project to the Solution, and test if it compiles.
4. Rename "ExampleApp.cpp/hpp" and "CExampleApp" to the name of your Application. <br>
   (Also changing the reference to CExampleApp in EntryPoint.cpp)
5. Build the template and inject it into any DirectX 9 Game, examples being MW3 or Portal 2 <br>
	(the template includes a DX9 EndScene hook, however this can be swapped out)

### From Scratch 

1. Create a new DLL project and put it in the Source folder
2. Under properties, set the following settings:
   1. Character set > Multi-byte Character set
   2. Include Directories > `$(SolutionDir)Source\$(ProjectName)`
   3. External Include Directories > `$(SolutionDir)Source\Shared`
   4. C++ Langugage Standard > ISO C++17 Standard
   5. Precompiled Headers > Not using Precompiled Headers
   6. (Optional) Multi-processor Complication > Yes
   7. (Optional) Enhanced Instruction Set > AVX or AVX2
   8. (Optional) Output Directory > `$(SolutionDir)Build\$(ProjectName)\$(PlatformShortName)\msvc-v$(PlatformToolsetVersion)-sdk-$(TargetPlatformVersion)\$(Configuration)\`
   9. (Optional) Intermediate Directory > `$(SolutionDir)Build\$(ProjectName)\$(PlatformShortName)\msvc-v$(PlatformToolsetVersion)-sdk-$(TargetPlatformVersion)\$(Configuration)\int\`
3. Right-click the Application, go to Add > Reference and select "Shared" <br>
   (If you get "The 'ReferenceManagerPackage' package did not load correctly", check out the troubleshooting step)
4. Remove everything from inside the DLLMain except for the return, and implement a virtual class that overrides `OnAttach` and `OnDetach` and inherits from `CLovelaceApp`
5. Using the LovelaceImplementApp macro, pass in the hModule, Dll call reason and the newly created class, and put inside of the DLLMain. 
6. Inside of OnAttach, wrap your init code inside of <br>
   `CLovelaceDefaults::Get()->InitializeApplication(m_pApplicationProperties, []() { });`
7. Inside of OnDetach, wrap your shutdown code inside of <br>
	`CLovelaceDefaults::Get()->ShutdownApplication(m_pApplicationProperties, []() { });`
8. Test if it builds, if it does: Profit!

## Adding additional libraries

### In Source-code form

If a library, contained in source code, is to be added:

1. Add the code along with a vcxproj in the Vendor folder
2. Include the project in the solution and move it to the Vendor "folder" in the solution.
3. Right-click on the project, click Add -> Reference and select the new library. <br>
   (if the library is a dependency of another library, repeat the step but right-click the library instead)

### In Compiled Library form

1. Put the library in Vendor/[libraryname]
2. Right-click the project -> Properties -> Linker -> Input and under "Additional Dependencies" add the library name
3. Under "VC++ Directories", add the location to both the header and the library

## Troubleshooting Step for References

If you run into an issue where trying to add a reference throws "The 'ReferenceManagerPackage' package did not load correctly", do the following

1. Open a "Developer Command Prompt for VS 2019" as administrator
2. Change Directory into `C:\Program Files (x86)\Microsoft Visual Studio 2019\[Community/Professional/Enterprise]\Common7\IDE\PublicAssemblies`
3. Run `gacutil -i Microsoft.VisualStudio.Shell.Interop.11.0.dll`

## Design Doc

| Type             | Convention           | Prefix/Suffix |
|------------------|----------------------|---------------|
| Macros           | PascalCase			  |               |
| Constants        | camelCase            |               |
| Statics          | camelCase            |               |
| Classes          | PascalCase           | C prefix      |
| Structs          | PascalCase           |               |
| Enums            | PascalCase           |               |
| Namespaces       | PascalCase           |               |
| Functions        | PascalCase           |               |
| Types            | PamelCase            | _t suffix     |
| Enum members     | camelCase            |               |
| Template params  | camelCase            |               |
| Parameters       | camelCase            |               |
| Local Variables  | camelCase            |               |
| Member Variables | camelCase            | m_ prefix     |
| Global Variables | camelCase            | g_ prefix     |
| File Names	   | PascalCase			  | 			  |

## Credits/Inspiration
* wxWidgets - Inspired the overall architecture and UI of Lovelace
* Dear ImGui - Used as a middleware to easily interface with OpenGL/DirectX/Vulkan
* JsonCpp - Utilalized for JSON Parsing

## License
In accordance with the BSL, if you'd like to use and publish this code for your own purposes, please link back to this repository
```
Boost Software License - Version 1.0 - August 17th, 2003

Permission is hereby granted, free of charge, to any person or organization
obtaining a copy of the software and accompanying documentation covered by
this license (the "Software") to use, reproduce, display, distribute,
execute, and transmit the Software, and to prepare derivative works of the
Software, and to permit third-parties to whom the Software is furnished to
do so, all subject to the following:

The copyright notices in the Software and this entire statement, including
the above license grant, this restriction and the following disclaimer,
must be included in all copies of the Software, in whole or in part, and
all derivative works of the Software, unless such copies or derivative
works are solely in the form of machine-executable object code generated by
a source language processor.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE, TITLE AND NON-INFRINGEMENT. IN NO EVENT
SHALL THE COPYRIGHT HOLDERS OR ANYONE DISTRIBUTING THE SOFTWARE BE LIABLE
FOR ANY DAMAGES OR OTHER LIABILITY, WHETHER IN CONTRACT, TORT OR OTHERWISE,
ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER
DEALINGS IN THE SOFTWARE.
```
