---
title: "-CLRSUPPORTLASTERROR (preservar último código de erro para chamadas PInvoke) | Microsoft Docs"
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology: cpp-tools
ms.tgt_pltfrm: 
ms.topic: article
f1_keywords: /CLRSUPPORTLASTERROR
dev_langs: C++
helpviewer_keywords:
- /CLRSUPPORTLASTERROR linker option
- -CLRSUPPORTLASTERROR linker option
ms.assetid: b7057990-4154-4b1d-9fc9-6236f7be7575
caps.latest.revision: "16"
author: corob-msft
ms.author: corob
manager: ghogen
ms.workload: cplusplus
ms.openlocfilehash: e082637e25832c5c5036910f7b67aff53d867bdb
ms.sourcegitcommit: 8fa8fdf0fbb4f57950f1e8f4f9b81b4d39ec7d7a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/21/2017
---
# <a name="clrsupportlasterror-preserve-last-error-code-for-pinvoke-calls"></a>/CLRSUPPORTLASTERROR (preservar último código de erro para chamadas PInvoke)
**/CLRSUPPORTLASTERROR**, que é ativado por padrão, preserva o último código de erro de funções chamado por meio do mecanismo P/Invoke, que permite que você chamar funções nativas em DLLS, do código compilado com **/clr**.  
  
## <a name="syntax"></a>Sintaxe  
  
```  
/CLRSUPPORTLASTERROR{:NO | SYSTEMDLL}  
```  
  
## <a name="remarks"></a>Comentários  
 Preservar o último código de erro indica uma queda no desempenho.  Se você não deseja gerar o impacto no desempenho de preservar último código de erro, vincular com **/CLRSUPPORTLASTERROR:NO**.  
  
 Você pode minimizar o impacto de desempenho por meio da vinculação com **/CLRSUPPORTLASTERROR:SYSTEMDLL**, que preserva apenas o último código de erro para as funções em DLLs de sistema.  Uma DLL do sistema é definido como um dos seguintes:  
  
|||||  
|-|-|-|-|  
|PARA ACLUI. DLL|ACTIVEDS. DLL|ADPTIF. DLL|ADVAPI32. DLL|  
|ASYCFILT. DLL|AUTORIZAÇÃO. DLL|AVICAP32. DLL|AVIFIL32. DLL|  
|GABINETE. DLL|CLUSAPI. DLL|COMCTL32. DLL|COMDLG32. DLL|  
|COMSVCS. DLL|CREDUI. DLL|CRYPT32. DLL|CRYPTNET. DLL|  
|CRYPTUI. DLL|D3D8THK. DLL|DBGENG. DLL|DBGHELP. DLL|  
|ARQUIVO DCIMAN32. DLL|DNSAPI. DLL|DSPROP. DLL|DSUIEXT. DLL|  
|GDI32. DLL|GLU32. DLL|HLINK. DLL|ICM32. DLL|  
|IMAGEHLP. DLL|IMM32. DLL|IPHLPAPI. DLL|IPROP. DLL|  
|KERNEL32. DLL|KSUSER. DLL|LOADPERF. DLL|LZ32. DLL|  
|MAPI32. DLL|BIBLIOTECA MGMTAPI. DLL|MOBSYNC. DLL|MPR. DLL|  
|MPRAPI. DLL|MQRT. DLL|MSACM32. DLL|MSCMS. DLL|  
|MSI. DLL|MSIMG32. DLL|MSRATING. DLL|MSTASK. DLL|  
|MSVFW32. DLL|MSWSOCK. DLL|MTXEX. DLL|NDDEAPI. DLL|  
|NETAPI32. DLL|NPPTOOLS. DLL|NTDSAPI. DLL|NTDSBCLI. DLL|  
|NTMSAPI. DLL|ODBC32. DLL|ODBCBCP. DLL|OLE32. DLL|  
|OLEACC. DLL|OLEAUT32. DLL|OLEDLG. DLL|OPENGL32. DLL|  
|PDH. DLL|POWRPROF. DLL|QOSNAME. DLL|CONSULTA. DLL|  
|RASAPI32. DLL|RASDLG. DLL|RASSAPI. DLL|RESUTILS. DLL|  
|RICHED20. DLL|RPCNS4. DLL|RPCRT4. DLL|RTM. DLL|  
|RTUTILS. DLL|SCARDDLG. DLL|SECUR32. DLL|SENSAPI. DLL|  
|SETUPAPI. DLL|SFC. DLL|SHELL32. DLL|SHFOLDER. DLL|  
|SHLWAPI. DLL|SISBKUP. DLL|SNMPAPI. DLL|SRCLIENT. DLL|  
|STI. DLL|TAPI32. DLL|TRÁFEGO. DLL|URL. DLL|  
|URLMON. DLL|USER32. DLL|USERENV. DLL|USP10. DLL|  
|UXTHEME. DLL|VDMDBG. DLL|VERSÃO. DLL|WINFAX. DLL|  
|WINHTTP. DLL|WININET. DLL|WINMM. DLL|WINSCARD. DLL|  
|WINTRUST. DLL|WLDAP32. DLL|WOW32. DLL|WS2_32|  
|WSNMP32. DLL|WSOCK32.DLL|WTSAPI32. DLL|XOLEHLP. DLL|  
  
> [!NOTE]
>  Não há suporte para funções não gerenciadas que são consumidas por código CLR, no mesmo módulo preserva o último erro.  
  
-   Para obter mais informações, consulte [/clr (compilação de Common Language Runtime)](../../build/reference/clr-common-language-runtime-compilation.md).  
  
### <a name="to-set-this-linker-option-in-the-visual-studio-development-environment"></a>Para definir esta opção do vinculador no ambiente de desenvolvimento do Visual Studio  
  
1.  Abra a caixa de diálogo **Páginas de Propriedades** do projeto. Para obter detalhes, consulte [configuração Visual C++ Project Properties](../../ide/working-with-project-properties.md).  
  
2.  Clique o **vinculador** pasta.  
  
3.  Clique o **linha de comando** página de propriedades.  
  
4.  Digite a opção para o **opções adicionais** caixa.  
  
### <a name="to-set-this-linker-option-programmatically"></a>Para definir esta opção do vinculador por meio de programação  
  
-   Consulte <xref:Microsoft.VisualStudio.VCProjectEngine.VCLinkerTool.AdditionalOptions%2A>.  
  
## <a name="example"></a>Exemplo  
 O exemplo a seguir define uma DLL nativa com uma função exportada que modifica o último erro.  
  
```  
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
  
```  
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
 [Definindo opções de vinculador](../../build/reference/setting-linker-options.md)   
 [Opções do vinculador](../../build/reference/linker-options.md)