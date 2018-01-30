---
title: _CrtDumpMemoryLeaks | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- cpp-standard-libraries
ms.tgt_pltfrm: 
ms.topic: article
apiname:
- _CrtDumpMemoryLeaks
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
- CRTDBG_LEAK_CHECK_DF
- CRTDBG_CHECK_CRT_DF
- _CRTDBG_LEAK_CHECK_DF
- CrtDumpMemoryLeaks
- _CrtDumpMemoryLeaks
- _CRTDBG_CHECK_CRT_DF
dev_langs:
- C++
helpviewer_keywords:
- CrtDumpMemoryLeaks function
- CRTDBG_LEAK_CHECK_DF macro
- _CRTDBG_LEAK_CHECK_DF macro
- _CrtDumpMemoryLeaks function
- CRTDBG_CHECK_CRT_DF macro
- _CRTDBG_CHECK_CRT_DF macro
ms.assetid: 71b2eab4-7f55-44e8-a55a-bfea4f32d34c
caps.latest.revision: 
author: corob-msft
ms.author: corob
manager: ghogen
ms.workload:
- cplusplus
ms.openlocfilehash: 859f1918afc69054b13cab161f2d7b4801bcbd78
ms.sourcegitcommit: 185e11ab93af56ffc650fe42fb5ccdf1683e3847
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 01/29/2018
---
# <a name="crtdumpmemoryleaks"></a>_CrtDumpMemoryLeaks
Despeja todos os blocos de memória no heap de depuração quando ocorre uma perda de memória (somente versão de depuração).  
  
## <a name="syntax"></a>Sintaxe  
  
```  
  
int _CrtDumpMemoryLeaks( void );  
```  
  
## <a name="return-value"></a>Valor de retorno  
 `_CrtDumpMemoryLeaks` retornará TRUE se for encontrada uma perda de memória. Caso contrário, a função retorna FALSE.  
  
## <a name="remarks"></a>Comentários  
 A função `_CrtDumpMemoryLeaks` determina se ocorreu uma perda de memória desde o início da execução do programa. Quando uma perda é encontrada, as informações de cabeçalho de depuração de todos os objetos no heap são despejadas em um formato legível pelo usuário. Quando [_DEBUG](../../c-runtime-library/debug.md) não está definido, as chamadas a `_CrtDumpMemoryLeaks` são removidas durante o pré-processamento.  
  
 `_CrtDumpMemoryLeaks` é chamado com frequência ao final da execução do programa para verificar se toda a memória alocada pelo aplicativo foi liberada. A função pode ser chamada automaticamente no encerramento do programa, ativando o campo de bits `_CRTDBG_LEAK_CHECK_DF` do sinalizador [_crtDbgFlag](../../c-runtime-library/crtdbgflag.md) usando a função [_CrtSetDbgFlag](../../c-runtime-library/reference/crtsetdbgflag.md).  
  
 `_CrtDumpMemoryLeaks` chama [_CrtMemCheckpoint](../../c-runtime-library/reference/crtmemcheckpoint.md) para obter o estado atual do heap e, em seguida, examina o estado em busca de blocos que não foram liberados. Quando um bloco não liberado é encontrado, `_CrtDumpMemoryLeaks` chama [_CrtMemDumpAllObjectsSince](../../c-runtime-library/reference/crtmemdumpallobjectssince.md) para despejar informações de todos os objetos alocados no heap a partir do início da execução do programa.  
  
 Por padrão, os blocos internos em tempo de execução C (`_CRT_BLOCK`) não são incluídos em operações de despejo de memória. A função [_CrtSetDbgFlag](../../c-runtime-library/reference/crtsetdbgflag.md) pode ser usada para ativar o bit `_CRTDBG_CHECK_CRT_DF` de `_crtDbgFlag` para incluir esses blocos no processo de detecção de perda.  
  
 Para obter mais informações sobre as funções de estado de heap e a estrutura `_CrtMemState`, consulte [Funções de relatório de estado de heap](/visualstudio/debugger/crt-debug-heap-details). Para obter mais informações sobre como os blocos de memória são alocados, inicializados e gerenciados na versão de depuração do heap base, consulte [Detalhes do heap de depuração do CRT](/visualstudio/debugger/crt-debug-heap-details).  
  
## <a name="requirements"></a>Requisitos  
  
|Rotina|Cabeçalho necessário|  
|-------------|---------------------|  
|`_CrtDumpMemoryLeaks`|\<crtdbg.h>|  
  
 Para obter mais informações sobre compatibilidade, consulte [Compatibilidade](../../c-runtime-library/compatibility.md) na Introdução.  
  
## <a name="libraries"></a>Libraries  
 Somente versões de depuração de [bibliotecas de tempo de execução C](../../c-runtime-library/crt-library-features.md).  
  
## <a name="example"></a>Exemplo  
 Para obter uma amostra de como usar `_CrtDumpMemoryLeaks`, consulte [crt_dbg1](https://github.com/Microsoft/VCSamples/tree/master/VC2010Samples/crt/crt_dbg1).  
  
## <a name="see-also"></a>Consulte também  
 [Rotinas de depuração](../../c-runtime-library/debug-routines.md)