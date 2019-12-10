---
title: /CLRSUPPORTLASTERROR (preservar último código de erro para chamadas PInvoke)
ms.date: 11/04/2016
f1_keywords:
- /CLRSUPPORTLASTERROR
helpviewer_keywords:
- /CLRSUPPORTLASTERROR linker option
- -CLRSUPPORTLASTERROR linker option
ms.assetid: b7057990-4154-4b1d-9fc9-6236f7be7575
ms.openlocfilehash: 64948d81759d415245e741bc6152d56bb35480d2
ms.sourcegitcommit: 573b36b52b0de7be5cae309d45b68ac7ecf9a6d8
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/10/2019
ms.locfileid: "74988343"
---
# <a name="clrsupportlasterror-preserve-last-error-code-for-pinvoke-calls"></a>/CLRSUPPORTLASTERROR (preservar último código de erro para chamadas PInvoke)

**/CLRSUPPORTLASTERROR**, que é ativado por padrão, preserva o último código de erro das funções chamadas por meio do mecanismo P/Invoke, que permite chamar funções nativas em DLLs, do código compilado com **/CLR**.

## <a name="syntax"></a>Sintaxe

```
/CLRSUPPORTLASTERROR{:NO | SYSTEMDLL}
```

## <a name="remarks"></a>Comentários

A preservação do último código de erro implica uma diminuição no desempenho.  Se você não quiser incorrer no impacto no desempenho de preservar o último código de erro, vincule com **/CLRSUPPORTLASTERROR: no**.

Você pode minimizar o impacto no desempenho vinculando-se com **/CLRSUPPORTLASTERROR: SYSTEMDLL**, que preserva apenas o último código de erro para funções em DLLs do sistema.  Uma DLL do sistema é definida como uma das seguintes opções:

|||||
|-|-|-|-|
|ACLUI.DLL|ACTIVEDS. DLL|ADPTIF. DLL|ADVAPI32.DLL|
|ASYCFILT. DLL|Autorização. DLL|AVICAP32. DLL|AVIFIL32.DLL|
|Gabinete. DLL|CLUSAPI.DLL|COMCTL32.DLL|COMDLG32.DLL|
|COMSVCS.DLL|CREDUI. DLL|CRYPT32.DLL|CRYPTNET.DLL|
|CRYPTUI. DLL|D3D8THK.DLL|DBGENG. DLL|DBGHELP. DLL|
|DCIMAN32.DLL|DNSAPI.DLL|DSPROP. DLL|DSUIEXT.DLL|
|GDI32.DLL|GLU32.DLL|Hlink. DLL|ICM32.DLL|
|IMAGEHLP.DLL|IMM32.DLL|IPHLPAPI.DLL|IPROP. DLL|
|KERNEL32.DLL|KSUSER.DLL|LOADPERF. DLL|LZ32.DLL|
|Mapi32. DLL|MGMTAPI. DLL|MOBSYNC.DLL|MPR. DLL|
|MPRAPI. DLL|MQRT.DLL|MSACM32.DLL|MSCMS. DLL|
|MSI.DLL|MSIMG32.DLL|MSRATING. DLL|Mstask. DLL|
|MSVFW32.DLL|MSWSOCK.DLL|MTXEX. DLL|NDDEAPI.DLL|
|Netapi32. DLL|NPPTOOLS. DLL|NTDSAPI.DLL|NTDSBCLI.DLL|
|NTMSAPI.DLL|ODBC32.DLL|ODBCBCP.DLL|OLE32.DLL|
|OLEACC. DLL|OLEAUT32.DLL|OLEDLG. DLL|OPENGL32.DLL|
|PDH. DLL|POWRPROF. DLL|QOSNAME.DLL|Consultá. DLL|
|RASAPI32.DLL|RASDLG.DLL|RASSAPI.DLL|RESUTILS. DLL|
|Riched20. DLL|RPCNS4.DLL|RPCRT4.DLL|RTM. DLL|
|RTUTILS. DLL|SCARDDLG. DLL|SECUR32.DLL|SENSAPI. DLL|
|Setupapi. DLL|SFC.DLL|SHELL32.DLL|SHFOLDER.DLL|
|SHLWAPI.DLL|SISBKUP.DLL|SNMPAPI. DLL|SRCLIENT. DLL|
|STI. DLL|TAPI32. DLL|Tráfico. DLL|URL.DLL|
|Urlmon. DLL|USER32.DLL|USERENV. DLL|USP10.DLL|
|UXTHEME. DLL|VDMDBG.DLL|Versão. DLL|WINFAX.DLL|
|WINHTTP.DLL|WININET.DLL|WINMM.DLL|WINSCARD. DLL|
|WINTRUST.DLL|WLDAP32.DLL|WOW32.DLL|WS2_32.DLL|
|WSNMP32.DLL|WSOCK32.DLL|WTSAPI32.DLL|XOLEHLP.DLL|

> [!NOTE]
>  Não há suporte para a preservação do último erro em funções não gerenciadas que são consumidas pelo código CLR, no mesmo módulo.

- Para obter mais informações, consulte [/clr (compilação de Common Language Runtime)](clr-common-language-runtime-compilation.md).

### <a name="to-set-this-linker-option-in-the-visual-studio-development-environment"></a>Para definir esta opção do vinculador no ambiente de desenvolvimento do Visual Studio

1. Abra a caixa de diálogo **Páginas de Propriedades** do projeto. Para obter detalhes, confira [Definir as propriedades de build e do compilador do C++ no Visual Studio](../working-with-project-properties.md).

1. Clique na pasta **Vinculador**.

1. Clique na página de propriedades de **linha de comando** .

1. Digite a opção na caixa **Opções adicionais** .

### <a name="to-set-this-linker-option-programmatically"></a>Para definir esta opção do vinculador por meio de programação

- Consulte <xref:Microsoft.VisualStudio.VCProjectEngine.VCLinkerTool.AdditionalOptions%2A>.

## <a name="example"></a>Exemplo

O exemplo a seguir define uma DLL nativa com uma função exportada que modifica o último erro.

```cpp
// CLRSUPPORTLASTERROR_dll.cpp
// compile with: /LD
#include <windows.h>
#include <math.h>

#pragma unmanaged
__declspec(dllexport) double MySqrt(__int64 n) {
   SetLastError(DWORD(-1));
   return sqrt(double(n));
}
```

## <a name="example"></a>Exemplo

O exemplo a seguir consome a DLL, demonstrando como usar **/CLRSUPPORTLASTERROR**.

```cpp
// CLRSUPPORTLASTERROR_client.cpp
// compile with: /clr CLRSUPPORTLASTERROR_dll.lib /link /clrsupportlasterror:systemdll
// processor: x86
#include <windows.h>
#include <wininet.h>
#include <stdio.h>
#include <math.h>

#pragma comment(lib, "wininet.lib")

double MySqrt(__int64 n);

#pragma managed
int main() {
   double   d = 0.0;
   __int64 n = 65;
   HANDLE  hGroup = NULL;
   GROUPID groupID;
   DWORD   dwSet = 127, dwGet = 37;

   SetLastError(dwSet);
   d = MySqrt(n);
   dwGet = GetLastError();

   if (dwGet == DWORD(-1))
      printf_s("GetLastError for application call succeeded (%d).\n",
             dwGet);
   else
      printf_s("GetLastError for application call failed (%d).\n",
             dwGet);

   hGroup = FindFirstUrlCacheGroup(0, CACHEGROUP_SEARCH_ALL,
                           0, 0, &groupID, 0);
   dwGet = GetLastError();
   if (dwGet == 183)
      printf_s("GetLastError for system call succeeded (%d).\n",
             dwGet);
   else
      printf_s("GetLastError for system call failed (%d).\n",
             dwGet);
}
```

```Output
GetLastError for application call failed (127).
GetLastError for system call succeeded (183).
```

## <a name="see-also"></a>Consulte também

[Referência de vinculador MSVC](linking.md)<br/>
[Opções de vinculador MSVC](linker-options.md)
