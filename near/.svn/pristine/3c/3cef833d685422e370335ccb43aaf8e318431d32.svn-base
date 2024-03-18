@start /MIN /WAIT powershell "Get-ChildItem %1 -Filter *.p -Recurse | foreach {$_.LastWriteTime = [System.DateTime]::Now};exit"
