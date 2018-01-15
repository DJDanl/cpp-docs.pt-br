---
title: _CrtGetAllocHook | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology: cpp-standard-libraries
ms.tgt_pltfrm: 
ms.topic: article
apiname: _CrtGetAllocHook
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
- CrtGetAllocHook
- _CrtGetAllocHook
dev_langs: C++
helpviewer_keywords:
- _CrtGetAllocHook function
- CrtGetAllocHook function
ms.assetid: 036acf7c-547a-4b3f-a636-80451070d7ed
caps.latest.revision: "12"
author: corob-msft
ms.author: corob
manager: ghogen
ms.workload: cplusplus
ms.openlocfilehash: 53291de083b788890dcd66df50c7973a2695858a
ms.sourcegitcommit: 8fa8fdf0fbb4f57950f1e8f4f9b81b4d39ec7d7a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/21/2017
---
# <a name="crtgetallochook"></a>_CrtGetAllocHook
Recupera a função de alocação definida pelo cliente para vinculá-la ao processo de alocação de memória de depuração em tempo de execução C (somente versão de depuração).  
  
## <a name="syntax"></a>Sintaxe  
  
```  
_CRT_ALLOC_HOOK _CrtGetAllocHook( void );  
```  
  
## <a name="return-value"></a>Valor de retorno  
 Retorna a função de gancho de alocação atualmente definida.  
  
## <a name="remarks"></a>Comentários  
 `_CrtGetAllocHook` recupera a função de gancho de aplicativo atual definida pelo cliente do processo de alocação de memória da biblioteca de depuração em tempo de execução C.  
  
 Para obter mais informações sobre como usar outras funções em tempo de execução compatíveis com gancho e escrever suas próprias funções de gancho definidas pelo cliente, consulte [Gravação da função de gancho de depuração](/visualstudio/debugger/debug-hook-function-writing).  
  
## <a name="requirements"></a>Requisitos  
  
|Rotina|Cabeçalho necessário|  
|-------------|---------------------|  
|`_CrtGetAllocHook`|\<crtdbg.h>|  
  
 Para obter mais informações sobre compatibilidade, consulte [Compatibilidade](../../c-runtime-library/compatibility.md) na Introdução.  
  
## <a name="libraries"></a>Libraries  
 Somente versões de depuração de [bibliotecas de tempo de execução C](../../c-runtime-library/crt-library-features.md).  
  
## <a name="see-also"></a>Consulte também  
 [Rotinas de depuração](../../c-runtime-library/debug-routines.md)   
 [_CrtSetAllocHook](../../c-runtime-library/reference/crtsetallochook.md)