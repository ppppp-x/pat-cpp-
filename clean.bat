@echo off
if not exist "bin" (
    echo 创建 bin 文件夹...
    mkdir "bin"
)

echo 正在移动 .exe 文件到 bin 文件夹...
move *.exe bin\

echo.
echo 整理完毕！
pause