---
title: _CrtSetReportFile | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- cpp-standard-libraries
ms.tgt_pltfrm: 
ms.topic: article
apiname:
- _CrtSetReportFile
apilocation:
- msvcrt.dll
- msvcr80.dll
- msvcr90.dll
- msvcr100.dll
- msvcr100_clr0400.dll
- msvcr110.dll
- msvcr110_clr0400.dll
- msvcr120.dll
- msvcr120_clr0400.dll
- ucrtbase.dll
apitype: DLLExport
f1_keywords:
- CrtSetReportFile
- _CrtSetReportFile
dev_langs:
- C++
helpviewer_keywords:
- CrtSetReportFile function
- _CrtSetReportFile function
ms.assetid: 3126537e-511b-44af-9c1c-0605265eabc4
caps.latest.revision: 16
author: corob-msft
ms.author: corob
manager: ghogen
translation.priority.ht:
- de-de
- es-es
- fr-fr
- it-it
- ja-jp
- ko-kr
- ru-ru
- zh-cn
- zh-tw
translation.priority.mt:
- cs-cz
- pl-pl
- pt-br
- tr-tr
ms.translationtype: Machine Translation
ms.sourcegitcommit: e257f037a05c45f5b98e64ea55bd125af443b0be
ms.openlocfilehash: 339da058334fa394aa10f2eb33707203f4f1be7b
ms.contentlocale: pt-br
ms.lasthandoff: 03/30/2017

---
# <a name="crtsetreportfile"></a>_CrtSetReportFile
Depois de usar [_CrtSetReportMode](../../c-runtime-library/reference/crtsetreportmode.md) para especificar `_CRTDBG_MODE_FILE`, é possível especificar o identificador de arquivo para receber o texto da mensagem. `_CrtSetReportFile` também é usado por [_CrtDbgReport, _CrtDbgReportW](../../c-runtime-library/reference/crtdbgreport-crtdbgreportw.md) para especificar o destino do texto (somente versão de depuração).  
  
## <a name="syntax"></a>Sintaxe  
  
```  
_HFILE _CrtSetReportFile(   
   int reportType,  
   _HFILE reportFile   
);  
```  
  
#### <a name="parameters"></a>Parâmetros  
 `reportType`  
 Tipo de relatório: `_CRT_WARN`, `_CRT_ERROR` e `_CRT_ASSERT`.  
  
 `reportFile`  
 Novo arquivo de relatório para `reportType`.  
  
## <a name="return-value"></a>Valor de retorno  
 Após a conclusão bem-sucedida, `_CrtSetReportFile` retorna o arquivo de relatório anterior definido para o tipo de relatório especificado em `reportType`. Se um valor inválido for passado para `reportType`, essa função invocará o manipulador de parâmetro inválido, conforme descrito em [Validação de parâmetro](../../c-runtime-library/parameter-validation.md). Se a execução tiver permissão para continuar, `errno` será definido como `EINVAL` e a função retornará `_CRTDBG_HFILE_ERROR`. Para obter mais informações, consulte [errno, _doserrno, _sys_errlist e _sys_nerr](../../c-runtime-library/errno-doserrno-sys-errlist-and-sys-nerr.md).  
  
## <a name="remarks"></a>Comentários  
 `_CrtSetReportFile` é usado com a função [_CrtSetReportMode](../../c-runtime-library/reference/crtsetreportmode.md) para definir os destinos de um tipo de relatório gerado por `_CrtDbgReport`. Quando `_CrtSetReportMode` tiver sido chamado para atribuir o modo de relatório `_CRTDBG_MODE_FILE` a um tipo de relatório específico, `_CrtSetReportFile` deverá ser chamado para definir o arquivo ou o fluxo específico a ser usado como o destino. Quando [_DEBUG](../../c-runtime-library/debug.md) não está definido, as chamadas a `_CrtSetReportFile` são removidas durante o pré-processamento.  
  
 A tabela a seguir mostra uma lista das opções disponíveis para `reportFile` e o comportamento resultante de `_CrtDbgReport`. Essas opções são definidas como sinalizadores de bits em Crtdbg.h.  
  
 `file handle`  
 Um identificador para o arquivo que será o destino das mensagens. Nenhuma tentativa é feita para verificar a validade do identificador. É necessário abrir e fechar o identificador do arquivo. Por exemplo:  
  
```  
HANDLE hLogFile;  
hLogFile = CreateFile("c:\\log.txt", GENERIC_WRITE,   
   FILE_SHARE_WRITE, NULL, CREATE_ALWAYS,   
   FILE_ATTRIBUTE_NORMAL, NULL);  
_CrtSetReportMode(_CRT_WARN, _CRTDBG_MODE_FILE);  
_CrtSetReportFile(_CRT_WARN, hLogFile);  
  
_RPT0(_CRT_WARN,"file message\n");  
CloseHandle(hLogFile);  
```  
  
 `_CRTDBG_FILE_STDERR`  
 Grava a mensagem em `stderr`, que pode ser redirecionada da seguinte maneira:  
  
```  
freopen( "c:\\log2.txt", "w", stderr);  
_CrtSetReportMode(_CRT_ERROR, _CRTDBG_MODE_FILE);  
_CrtSetReportFile(_CRT_ERROR, _CRTDBG_FILE_STDERR);  
  
_RPT0(_CRT_ERROR,"1st message\n");  
```  
  
 `_CRTDBG_FILE_STDOUT`  
 Grava a mensagem em `stdout`, que pode ser redirecionada.  
  
 `_CRTDBG_REPORT_FILE`  
 Retorna o modo de relatório atual.  
  
 O arquivo de relatório usado por cada tipo de relatório pode ser controlado separadamente. Por exemplo, é possível especificar que um `reportType` de `_CRT_ERROR` seja relatado para `stderr`, enquanto um `reportType` de `_CRT_ASSERT` seja relatado para um fluxo ou um identificador de arquivo definido pelo usuário.  
  
## <a name="requirements"></a>Requisitos  
  
|Rotina|Cabeçalho necessário|Cabeçalho opcional|  
|-------------|---------------------|---------------------|  
|`_CrtSetReportFile`|\<crtdbg.h>|\<errno.h>|  
  
 Não há suporte para o console em aplicativos [!INCLUDE[win8_appname_long](../../build/includes/win8_appname_long_md.md)]. Os identificadores de fluxo padrão associados ao console – `stdin`, `stdout` e `stderr` – devem ser redirecionados antes que as funções em tempo de execução C possam usá-los em aplicativos [!INCLUDE[win8_appname_long](../../build/includes/win8_appname_long_md.md)]. Para obter mais informações sobre compatibilidade, consulte [Compatibilidade](../../c-runtime-library/compatibility.md).  
  
 **Bibliotecas:** somente versões de depuração dos [Recursos da biblioteca CRT](../../c-runtime-library/crt-library-features.md).  
  
## <a name="see-also"></a>Consulte também  
 [Rotinas de depuração](../../c-runtime-library/debug-routines.md)
