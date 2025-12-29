$imagePath = "main.png"

Write-Host "程序已启动，将在1分钟后切换壁纸..."
Write-Host "壁纸文件: $imagePath"
Write-Host "等待中..."

Start-Sleep -Seconds 60

Write-Host "时间到！正在切换壁纸..."

Add-Type -TypeDefinition @"
using System;
using System.Runtime.InteropServices;
public class Wallpaper {
    [DllImport("user32.dll", CharSet = CharSet.Auto)]
    public static extern int SystemParametersInfo(int uAction, int uParam, string lpvParam, int fuWinIni);
}
"@

$result = [Wallpaper]::SystemParametersInfo(0x0014, 0, $imagePath, 0x0001 -bor 0x0002)

if ($result) {
    Write-Host "壁纸切换成功！" -ForegroundColor Green
    Write-Host "当前壁纸: $imagePath" -ForegroundColor Green
} else {
    Write-Host "壁纸切换失败" -ForegroundColor Red
}

Start-Sleep -Seconds 3
