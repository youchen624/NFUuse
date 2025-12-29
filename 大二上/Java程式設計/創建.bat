@echo off
setlocal enabledelayedexpansion

echo --------------------------------------------------
echo Java課程檔案結構創建精靈
echo --------------------------------------------------

REM 日期
set /p date="請輸入日期(MMDD): "

REM 題號
set /p num="請輸入題號(i): "

echo.

REM 檢查
if "!date!"=="" (
    echo 錯誤 請輸入日期
    goto end
)
if "!num!"=="" (
    echo 錯誤 請輸入題號
    goto end
)

REM 資料夾名稱
set "rootFolder=%~dp0!date!/CSIE_41343131_!date!_!num!"
set "fileName=CSIE_41343131_!date!_!num!.java"

echo 正在創建... %rootFolder%
echo.

REM 創建主要資料夾
md "%rootFolder%"
@REM md "%rootFolder%\程式碼\Source"
@REM md "%rootFolder%\程式碼\測試"
@REM md "%rootFolder%\資源"

REM 創建空檔案 (使用 copy NUL 或 type NUL >)
@REM copy NUL "%rootFolder%\文件\README.txt" > NUL
type NUL > "%rootFolder%\%fileName%"

echo.
echo 專案已成功創建!
REM echo 根資料夾: %rootFolder%
echo.

:end
endlocal
pause