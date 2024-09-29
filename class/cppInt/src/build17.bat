cls

@echo [101mg++ %* -std=c++17  [0m
@g++ %* -IA:\\CMC_HEADER -std=c++17 -lstdc++exp -o gout.exe

@IF %ERRORLEVEL% EQU 0 (
	echo [37;4m[ g++ compiling success !! run gout.exe ][0m
  	gout.exe
) ELSE (
	echo [37;4m[ Error !!, g++ fail to compile. ][0m
)
@echo:

@echo [101mcl %* /std:c++17 [0m
@cl  %* /IA:\\CMC_HEADER /permissive- /std:c++17 /utf-8 /nologo /EHsc /link /out:vout.exe

@IF %ERRORLEVEL%  EQU 0 (
	echo [37;4m[ cl compiling success !! run vout.exe ][0m
	vout.exe
)ELSE (
	echo [37;4m[ Error !!, cl fail to compile. ][0m
)
@echo:

