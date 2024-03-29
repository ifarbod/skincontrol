:: Premake5 Invoker util
:: Author(s):       iFarbod <ifarbod@outlook.com>
::
:: Copyright (c) 2015-2017 CTNorth Team
::
:: Distributed under the MIT license (See accompanying file LICENSE or copy at
:: https://opensource.org/licenses/MIT)

@echo off

if "%1" == "clean" (
    :: Invoke premake5's clean action
    echo Performing clean action...
    buildtools\win\premake5 clean
) else (
    :: Invoke premake5 with specified args and VS2019 action
    buildtools\win\premake5 %* vs2019
)

:: Pause for 5 seconds and auto-close the command window
:end
timeout /t 5 /nobreak
