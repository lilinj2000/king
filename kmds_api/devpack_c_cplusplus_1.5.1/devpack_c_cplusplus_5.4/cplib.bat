set basepath=%cd%\
set win64libpath=%basepath%lib_win64\
set win32libpath=%basepath%lib_win32\
set win64binpath=%basepath%kmdsdemo\bin_win64\
set win32binpath=%basepath%kmdsdemo\bin_win32\
set includepath=%basepath%include\

set kmdsapipath=%basepath%..\..\lib\prj\kmdsapi\userapi\
set quickfastpath=%basepath%..\..\lib\third-party\quickfast\
set commpath=%basepath%..\..\lib\comm\lcomm\
set srcincludepath=%basepath%..\..\include\
set filterdllpath=%basepath%..\..\..\bin\KMDS_Test_V1.0\kdhqtrans_win\

echo  copy to lib
copy   %kmdsapipath%kmdsapi_x64.lib   %win64libpath%
rem copy   %kmdsapipath%kmdsapi_x64.dll   %win64libpath% 
copy   %kmdsapipath%kmdsapi.lib       %win32libpath%
rem copy   %kmdsapipath%kmdsapi.dll       %win32libpath% 

copy   %kmdsapipath%libckmdsapi_x64.lib   %win64libpath%
rem copy   %kmdsapipath%libckmdsapi_x64.dll   %win64libpath% 
copy   %kmdsapipath%libckmdsapi.lib       %win32libpath%
rem copy   %kmdsapipath%libckmdsapi.dll       %win32libpath% 

copy   %commpath%lcomm_x64.lib   %win64libpath% 
copy   %commpath%lcomm.lib       %win32libpath%

echo   copy to bin

copy   %kmdsapipath%kmdsapi_x64.dll   %win64binpath% 
copy   %kmdsapipath%kmdsapi.dll       %win32binpath% 

copy   %quickfastpath%QuickFAST_x64.dll   %win64binpath% 
copy   %quickfastpath%QuickFAST.dll       %win32binpath% 

copy   %kmdsapipath%libckmdsapi_x64.dll   %win64binpath% 
copy   %kmdsapipath%libckmdsapi.dll       %win32binpath% 

copy   %filterdllpath%plugins_32\lplugin_hq_filterverfity.dll      %win32binpath% 
copy   %filterdllpath%plugins_64\lplugin_hq_filterverfity.dll      %win64binpath% 


echo   copy to include
copy   %srcincludepath%prj\kmdsapi\kmdsapidef.h   %includepath% 
copy   %srcincludepath%prj\kmdsapi\kmdsuserapi.h   %includepath% 
copy   %srcincludepath%prj\kmdsapi\kdhqplayback_define.h   %includepath% 
copy   %srcincludepath%prj\kmdsapi\libckmdsapi\ckmdsdef.h   %includepath%libckmdsapi\ 
copy   %srcincludepath%prj\kmdsapi\libckmdsapi\ckmdsuserapi.h   %includepath%libckmdsapi\ 
copy   %srcincludepath%prj\kmdsapi\libckmdsapi\cmsgdata.h   %includepath%libckmdsapi\ 
copy   %srcincludepath%prj\kmdsapi\libckmdsapi\ctabledata.h   %includepath%libckmdsapi\ 
copy   %srcincludepath%comm\lcomm\msgdata.h   %includepath% 

pause
 
