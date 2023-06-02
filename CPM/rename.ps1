# Script to recursively rename all files to upper case on Windows

Get-ChildItem -Recurse | ForEach-Object {
    if (-not $_.PSIsContainer) {
        $fileName = $_.Name
        if (($fileName.ToUpper() -ne "RENAME.SH") -and ($fileName.ToUpper() -ne "RENAME.PS1") -and ($fileName.ToUpper() -ne "RUNCPM")) {
            $newFileName = $fileName.ToUpper()
            if ($fileName -ceq $newFileName) {
#                Write-Host "File is already in uppercase:" $_.FullName
            }
            else {
                Write-Host -NoNewLine "Renaming:" $fileName
                $tempName = $_.FullName + ".tmp"
                Rename-Item $_.FullName $tempName
                while (Test-Path $_.FullName) {
                    Start-Sleep -Milliseconds 100
                }
                Rename-Item $tempName $newFileName
                while (Test-Path $tempName) {
                    Start-Sleep -Milliseconds 100
                }
                Write-Host "  to:" $newFileName
            }
        }
    }
}
