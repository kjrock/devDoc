cls

@echo [101mg++ %* -std=c++23 -o gout.exe [0m
@g++ %* -std=c++23 -o gout.exe

@IF %ERRORLEVEL% EQU 0 (
	echo [37;4m[ g++ compiling success !! run gout.exe ][0m
  	gout.exe
) ELSE (
	echo [37;4m[ Error !!, g++ fail to compile. ][0m
)

@REM @echo.

@REM @echo [101mcl %* /permissive- /std:c++latest /utf-8 /nologo /EHsc /link /out:vout.exe [0m
@REM @cl  %* /permissive- /std:c++latest /utf-8 /nologo /EHsc /link /out:vout.exe

@REM @IF %ERRORLEVEL%  EQU 0 (
@REM 	echo [37;4m[ cl compiling success !! run vout.exe ][0m
@REM 	vout.exe
@REM )ELSE (
@REM 	echo [37;4m[ Error !!, cl fail to compile. ][0m
@REM )
