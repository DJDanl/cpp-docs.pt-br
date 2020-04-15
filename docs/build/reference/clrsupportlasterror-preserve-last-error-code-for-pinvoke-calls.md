---
title: /CLRSUPPORTLASTERROR (preservar último código de erro para chamadas PInvoke)
ms.date: 11/04/2016
f1_keywords:
- /CLRSUPPORTLASTERROR
helpviewer_keywords:
- /CLRSUPPORTLASTERROR linker option
- -CLRSUPPORTLASTERROR linker option
ms.assetid: b7057990-4154-4b1d-9fc9-6236f7be7575
ms.openlocfilehash: 19930591c2d0406c68b1a408622a49c9e8b1d551
ms.sourcegitcommit: c123cc76bb2b6c5cde6f4c425ece420ac733bf70
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/14/2020
ms.locfileid: "81322268"
---
# <a name="clrsupportlasterror-preserve-last-error-code-for-pinvoke-calls"></a>/CLRSUPPORTLASTERROR (preservar último código de erro para chamadas PInvoke)

**/CLRSUPPORTLASTERROR**, que está ligado por padrão, preserva o último código de erro das funções chamadas através do mecanismo P/Invoke, que permite chamar funções nativas em DLLS, a partir de código compilado com **/clr**.

## <a name="syntax"></a>Sintaxe

```
/CLRSUPPORTLASTERROR{:NO | SYSTEMDLL}
```

## <a name="remarks"></a>Comentários

Preservar o último código de erro implica uma diminuição no desempenho.  Se você não quiser incorrer no impacto de desempenho da preservação do último código de erro, vincule-se com **/CLRSUPPORTLASTERROR:NO**.

Você pode minimizar o impacto de desempenho vinculando-se com **/CLRSUPPORTLASTERROR:SYSTEMDLL**, que só preserva o último código de erro para funções em DLLs do sistema.  Um sistema DLL é definido como um dos seguintes:

|||||
|-|-|-|-|
|A ACLUI. Dll|Activeds. Dll|ADPTIF. Dll|ADVAPI32. Dll|
|Asycfilt. Dll|O AUTHZ. Dll|AVICAP32. Dll|O AVIFIL32. Dll|
|Armário. Dll|A CLUSAPI. Dll|COMCTL32. Dll|COMDLG32. Dll|
|COMSVCS. Dll|Credui. Dll|CRYPT32. Dll|CRYPTNET. Dll|
|Cryptui. Dll|D3D8THK. Dll|O DBGENG. Dll|DBGHELP. Dll|
|O DCIMAN32. Dll|DNSAPI. Dll|DSPROP. Dll|DSUiEXT. Dll|
|GDI32. Dll|O GLU32. Dll|O HLINK. Dll|O ICM32. Dll|
|IMAGEHLP. Dll|O IMM32. Dll|IPHLPAPI. Dll|IPROP. Dll|
|KERNEL32. Dll|O KSUSER. Dll|LOADPERF. Dll|O LZ32. Dll|
|MAPI32. Dll|MGMTAPI. Dll|O MOBSYNC. Dll|Mpr. Dll|
|O MPRAPI. Dll|O MQRT. Dll|MSACM32. Dll|MSCMS. Dll|
|Msi. Dll|MSIMG32. Dll|MSRATING. Dll|MSTASK. Dll|
|MSVFW32. Dll|MSWSOCK. Dll|O MTXEX. Dll|A NDDEAPI. Dll|
|NETAPI32. Dll|NPPTOOLS. Dll|A NTDSAPI. Dll|NTDSBCLI. Dll|
|A NTMSAPI. Dll|ODBC32. Dll|ODBCBCP. Dll|Ole32. Dll|
|OLEACC, o que está. Dll|OLEAUT32. Dll|OLEDLG. Dll|O OPENGL32. Dll|
|Pdh. Dll|PowrPROF. Dll|QOSNAME. Dll|Consulta. Dll|
|RASAPI32. Dll|O RASDLG. Dll|A RASSAPI. Dll|RESUTILS. Dll|
|RICHED20. Dll|RPCNS4. Dll|RPCRT4. Dll|Rtm. Dll|
|RTUTILS. Dll|SCARDDLG. Dll|SECUR32. Dll|A SENSAPI. Dll|
|SetuPAPI. Dll|Sfc. Dll|O SHELL32. Dll|SHFOLDER. Dll|
|A SHLWAPI. Dll|O SISBKUP. Dll|O SNMPAPI. Dll|SRCLIENT. Dll|
|Sti. Dll|O TAPI32. Dll|Tráfego. Dll|Url. Dll|
|Urlmon. Dll|USUÁRIO32. Dll|Userenv. Dll|USP10. Dll|
|Uxtheme. Dll|VDMDBG. Dll|Versão. Dll|Winfax. Dll|
|WINHTTP. Dll|Wininet. Dll|O WINMM. Dll|O WINSCARD. Dll|
|A WINTRUST. Dll|WLDAP32. Dll|UAU32. Dll|WS2_32.DLL|
|WSNMP32. Dll|WSOCK32.DLL|WTSAPI32. Dll|O XOLEHLP. Dll|

> [!NOTE]
> A preservação do último erro não é suportada para funções não gerenciadas que são consumidas pelo código CLR, no mesmo módulo.

- Para obter mais informações, consulte [/clr (Common Language Runtime Compilation)](clr-common-language-runtime-compilation.md).

### <a name="to-set-this-linker-option-in-the-visual-studio-development-environment"></a>Para definir esta opção do vinculador no ambiente de desenvolvimento do Visual Studio

1. Abra a caixa de diálogo **Páginas de Propriedades** do projeto. Para obter detalhes, confira [Definir as propriedades de build e do compilador do C++ no Visual Studio](../working-with-project-properties.md).

1. Clique na pasta **Vinculador**.

1. Clique na página de propriedade Linha de **Comando.**

1. Digite a opção na **caixa Opções Adicionais.**

### <a name="to-set-this-linker-option-programmatically"></a>Para definir esta opção do vinculador por meio de programação

- Consulte <xref:Microsoft.VisualStudio.VCProjectEngine.VCLinkerTool.AdditionalOptions%2A>.

## <a name="example"></a>Exemplo

A amostra a seguir define uma DLL nativa com uma função exportada que modifica o último erro.

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

A amostra a seguir consome o DLL, demonstrando como usar **/CLRSUPPORTLASTERROR**.

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

## <a name="see-also"></a>Confira também

[Referência de vinculador MSVC](linking.md)<br/>
[Opções de vinculador MSVC](linker-options.md)
