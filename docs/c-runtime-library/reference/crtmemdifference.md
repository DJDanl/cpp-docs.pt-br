---
title: _CrtMemDifference | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- cpp-standard-libraries
ms.tgt_pltfrm: 
ms.topic: reference
apiname:
- _CrtMemDifference
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
- _CrtMemDifference
- CrtMemDifference
dev_langs:
- C++
helpviewer_keywords:
- CrtMemDifference function
- _CrtMemDifference function
ms.assetid: 0f327278-b551-482f-958b-76941f796ba4
caps.latest.revision: 
author: corob-msft
ms.author: corob
manager: ghogen
ms.workload:
- cplusplus
ms.openlocfilehash: 68d0aa43167e9c4641851927bd56819e384fed4d
ms.sourcegitcommit: 6002df0ac79bde5d5cab7bbeb9d8e0ef9920da4a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 02/14/2018
---
# <a name="crtmemdifference"></a>_CrtMemDifference
Compara dois estados de memória e retorna suas diferenças (somente versão de depuração).  
  
## <a name="syntax"></a>Sintaxe  
  
```  
int _CrtMemDifference(   
   _CrtMemState *stateDiff,  
   const _CrtMemState *oldState,  
   const _CrtMemState *newState   
);  
```  
  
#### <a name="parameters"></a>Parâmetros  
 `stateDiff`  
 Ponteiro para uma estrutura `_CrtMemState` que é usada para armazenar as diferenças entre os dois estados de memória (retornados).  
  
 `oldState`  
 Ponteiro para um estado de memória anterior (estrutura `_CrtMemState`).  
  
 `newState`  
 Ponteiro para um estado de memória posterior (estrutura `_CrtMemState`).  
  
## <a name="return-value"></a>Valor de retorno  
 Se os estados de memória forem significativamente diferentes, `_CrtMemDifference` retornará TRUE. Caso contrário, a função retorna FALSE.  
  
## <a name="remarks"></a>Comentários  
 A função `_CrtMemDifference` compara `oldState` e `newState` e armazena suas diferenças em `stateDiff`, que pode então ser usado pelo aplicativo para detectar perdas de memória e outros problemas de memória. Quando [_DEBUG](../../c-runtime-library/debug.md) não está definido, as chamadas a `_CrtMemDifference` são removidas durante o pré-processamento.  
  
 `newState` e `oldState` devem ser um ponteiro válido para uma estrutura `_CrtMemState`, definida em Crtdbg.h, que tenha sido preenchida por [_CrtMemCheckpoint](../../c-runtime-library/reference/crtmemcheckpoint.md) antes da chamada a `_CrtMemDifference`. `stateDiff` deve ser um ponteiro para uma instância previamente alocada da estrutura `_CrtMemState`. Se `stateDiff`, `newState` ou `oldState` for `NULL`, o manipulador de parâmetro inválido será invocado, conforme descrito em [Validação de parâmetro](../../c-runtime-library/parameter-validation.md). Se a execução tiver permissão para continuar, [errno, _doserrno, _sys_errlist e _sys_nerr](../../c-runtime-library/errno-doserrno-sys-errlist-and-sys-nerr.md) serão definidos como `EINVAL` e a função retornará FALSE.  
  
 `_CrtMemDifference` compara os valores do campo `_CrtMemState` dos blocos em `oldState` com aqueles em `newState` e armazena o resultado em `stateDiff`. Quando o número de tipos de bloco alocados ou o número total de blocos alocados para cada tipo diferir entre os dois estados de memória, os estados serão considerados significativamente diferentes. A diferença entre a maior quantidade alocada ao mesmo tempo para os dois estados e a diferença entre o total de alocações para os dois estados também são armazenadas em `stateDiff`.  
  
 Por padrão, os blocos internos em tempo de execução C (`_CRT_BLOCK`) não são incluídos em operações de estado de memória. A função [_CrtSetDbgFlag](../../c-runtime-library/reference/crtsetdbgflag.md) pode ser usada para ativar o bit `_CRTDBG_CHECK_CRT_DF` de `_crtDbgFlag` para incluir esses blocos na detecção de perda e em outras operações de estado de memória. Blocos de memória liberados (`_FREE_BLOCK`) não fazem com que `_CrtMemDifference` retorne TRUE.  
  
 Para obter mais informações sobre as funções de estado de heap e a estrutura `_CrtMemState`, consulte [Funções de relatório de estado de heap](/visualstudio/debugger/crt-debug-heap-details). Para obter informações sobre como os blocos de memória são alocados, inicializados e gerenciados na versão de depuração do heap de base, consulte [Detalhes do heap de depuração CRT](/visualstudio/debugger/crt-debug-heap-details).  
  
## <a name="requirements"></a>Requisitos  
  
|Rotina|Cabeçalho necessário|Cabeçalho opcional|  
|-------------|---------------------|---------------------|  
|`_CrtMemDifference`|\<crtdbg.h>|\<errno.h>|  
  
 Para obter mais informações sobre compatibilidade, consulte [Compatibilidade](../../c-runtime-library/compatibility.md) na Introdução.  
  
 **Bibliotecas:** somente versões de depuração dos [Recursos da biblioteca CRT](../../c-runtime-library/crt-library-features.md).  
  
## <a name="see-also"></a>Consulte também  
 [Rotinas de depuração](../../c-runtime-library/debug-routines.md)   
 [_crtDbgFlag](../../c-runtime-library/crtdbgflag.md)