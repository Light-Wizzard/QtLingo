# Get-Command -syntax 'testPS.ps1'
# if(Test-Syntax build_script.ps1){ Write-Host 'Build Script looks good!' }
# if(Test-Syntax install.ps1){ Write-Host 'Install Script looks good!' }
function Test-Syntax
{
    [CmdletBinding(DefaultParameterSetName='File')]
    param(
        [Parameter(Mandatory=$true, ParameterSetName='File', Position = 0)]
        [string]$Path, 

        [Parameter(Mandatory=$true, ParameterSetName='String', Position = 0)]
        [string]$Code
    )

    $Errors = @()
    if($PSCmdlet.ParameterSetName -eq 'String'){
        [void][System.Management.Automation.Language.Parser]::ParseInput($Code,[ref]$null,[ref]$Errors)
    } else {
        [void][System.Management.Automation.Language.Parser]::ParseFile($Path,[ref]$null,[ref]$Errors)
    }

    return [bool]($Errors.Count -lt 1)
}
