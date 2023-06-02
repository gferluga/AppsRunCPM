# Script to recursively delete all desktop.ini files on Windows

Get-ChildItem -Recurse -Attributes Hidden | Where-Object {$_.Name -eq "desktop.ini"} | ForEach-Object {
    Write-Host "Deleting:" $_.FullName
    Set-ItemProperty $_.FullName -Name Attributes -Value ([System.IO.FileAttributes]::Normal)
    Remove-Item $_.FullName
}
