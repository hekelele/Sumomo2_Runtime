::echo %1
::echo %2
::echo %3
::echo %4
set include_path=%4\includes\
set x64_path=%4\lib\x64\
set x86_path=%4\lib\x86\

If not exist %4\includes\ mkdir %include_path%
if %2 == Win32 If not exist %x86_path% mkdir %x86_path%
if %2 == x64 If not exist %x64_path% mkdir %x64_path%

xcopy %3\Runtime\*.h %include_path% /D /Y

if  %1 == Release set file_name=Sumomo2.lib
if  %1 == Debug set file_name=Sumomo2_d.lib
if %2 == Win32 set out_path=%x86_path%
if %2 == x64 set out_path=%x64_path%
if %2 == Win32 set in_path=%3Build\x86\%file_name%
if %2 == x64 set in_path=%3Build\x64\%file_name%

xcopy %in_path% %out_path% /D /Y

::.\cpy.bat Debug x64 .\ C:\Includes\sumomo