---
title: _CrtSetDumpClient | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- devlang-cpp
ms.tgt_pltfrm: 
ms.topic: article
apiname:
- _CrtSetDumpClient
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
- _CrtSetDumpClient
- CrtSetDumpClient
dev_langs:
- C++
helpviewer_keywords:
- _CrtSetDumpClient function
- CrtSetDumpClient function
ms.assetid: f3dd06d0-c331-4a12-b68d-25378d112033
caps.latest.revision: 12
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
ms.openlocfilehash: 0fc4875a344a8d094c40436ae6d67d80707deef1
ms.contentlocale: pt-br
ms.lasthandoff: 03/30/2017

---
# <a name="crtsetdumpclient"></a>_CrtSetDumpClient
Instala uma função definida pelo aplicativo para despejar blocos de memória do tipo `_CLIENT_BLOCK` (somente versão de depuração).  
  
## <a name="syntax"></a>Sintaxe  
  
```  
  
      _CRT_DUMP_CLIENT _CrtSetDumpClient(   
   _CRT_DUMP_CLIENT dumpClient   
);  
```  
  
#### <a name="parameters"></a>Parâmetros  
 `dumpClient`  
 Nova função de despejo de memória definida pelo cliente a ser vinculada ao processo de despejo de memória de depuração em tempo de execução C.  
  
## <a name="return-value"></a>Valor de retorno  
 Retorna a função de despejo de bloco do cliente definida anteriormente.  
  
## <a name="remarks"></a>Comentários  
 A função `_CrtSetDumpClient` permite que o aplicativo vincule sua própria função aos objetos de despejo armazenados em blocos de memória `_CLIENT_BLOCK` no processo de despejo de memória de depuração em tempo de execução C. Como resultado, sempre que uma função de despejo de depuração como [_CrtMemDumpAllObjectsSince](../../c-runtime-library/reference/crtmemdumpallobjectssince.md) ou [_CrtDumpMemoryLeaks](../../c-runtime-library/reference/crtdumpmemoryleaks.md) despejar um bloco de memória `_CLIENT_BLOCK`, a função de despejo do aplicativo também será chamada. `_CrtSetDumpClient` fornece um aplicativo com um método fácil para detecção de perdas de memória e para validação ou relatório do conteúdo dos dados armazenados em blocos `_CLIENT_BLOCK`. Quando [_DEBUG](../../c-runtime-library/debug.md) não está definido, as chamadas a `_CrtSetDumpClient` são removidas durante o pré-processamento.  
  
 A função `_CrtSetDumpClient` instala a nova função de despejo definida pelo aplicativo especificada em `dumpClient` e retorna a função de despejo definida anteriormente. Este é um exemplo de uma função de despejo de bloco do cliente:  
  
```  
void DumpClientFunction( void *userPortion, size_t blockSize );  
```  
  
 O argumento `userPortion` é um ponteiro para o início da parte de dados do usuário do bloco de memória e `blockSize` especifica o tamanho do bloco de memória alocado em bytes. A função de despejo de bloqueio do cliente deve retornar `void`. O ponteiro para a função de despejo do cliente passado para `_CrtSetDumpClient` é do tipo `_CRT_DUMP_CLIENT`, conforme definido em Crtdbg.h:  
  
```  
typedef void (__cdecl *_CRT_DUMP_CLIENT)( void *, size_t );  
```  
  
 Para obter mais informações sobre as funções que operam em blocos de memória do tipo `_CLIENT_BLOCK`, consulte [Funções de gancho de bloco do cliente](/visualstudio/debugger/client-block-hook-functions). A função [_CrtReportBlockType](../../c-runtime-library/reference/crtreportblocktype.md) pode ser usada para retornar informações sobre tipos e subtipos de bloco.  
  
## <a name="requirements"></a>Requisitos  
  
|Rotina|Cabeçalho necessário|  
|-------------|---------------------|  
|`_CrtSetDumpClient`|\<crtdbg.h>|  
  
 Para obter mais informações sobre compatibilidade, consulte [Compatibilidade](../../c-runtime-library/compatibility.md) na Introdução.  
  
## <a name="libraries"></a>Libraries  
 Somente versões de depuração de [bibliotecas de tempo de execução C](../../c-runtime-library/crt-library-features.md).  
  
## <a name="see-also"></a>Consulte também  
 [Rotinas de depuração](../../c-runtime-library/debug-routines.md)   
 [_CrtReportBlockType](../../c-runtime-library/reference/crtreportblocktype.md)   
 [_CrtGetDumpClient](../../c-runtime-library/reference/crtgetdumpclient.md)
