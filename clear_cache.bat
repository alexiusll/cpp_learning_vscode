@echo off
echo 清理临时文件中...
del %~dp0*.exe /q /s
del %~dp0tempCodeRunnerFile.c /q /s
del %~dp0a.out /q /s
del %~dp0*.o /q /s
echo 清理文件结束...按任意键退出
pause >nul
exit