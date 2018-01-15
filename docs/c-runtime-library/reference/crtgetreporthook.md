---
title: _CrtGetReportHook | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology: cpp-standard-libraries
ms.tgt_pltfrm: 
ms.topic: article
apiname: _CrtGetReportHook
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
- CrtGetReportHook
- _CrtGetReportHook
dev_langs: C++
helpviewer_keywords:
- CrtGetReportHook function
- _CrtGetReportHook function
ms.assetid: 922758ed-7edd-4359-9c92-0535192dc11a
caps.latest.revision: "12"
author: corob-msft
ms.author: corob
manager: ghogen
ms.workload: cplusplus
ms.openlocfilehash: 69c49895f50f18e96a1d673df3e80e6bb7d88824
ms.sourcegitcommit: 8fa8fdf0fbb4f57950f1e8f4f9b81b4d39ec7d7a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/21/2017
---
# <a name="crtgetreporthook"></a>_CrtGetReportHook
Recupera a função de relatório definida pelo cliente para vinculá-lo ao tempo de execução C do processo de relatório de depuração (somente versão de depuração).  
  
## <a name="syntax"></a>Sintaxe  
  
```  
_CRT_REPORT_HOOK _CrtGetReportHook( void );  
```  
  
## <a name="return-value"></a>Valor de retorno  
 Retorna a função de relatório atual definida pelo cliente.  
  
## <a name="remarks"></a>Comentários  
 `_CrtGetReportHook` permite que um aplicativo recupere a função de relatório atual do processo de relatório da biblioteca de depuração em tempo de execução C.  
  
 Para obter mais informações sobre como usar outras funções em tempo de execução compatíveis com gancho e escrever suas próprias funções de gancho definidas pelo cliente, consulte [Gravação da função de gancho de depuração](/visualstudio/debugger/debug-hook-function-writing).  
  
## <a name="requirements"></a>Requisitos  
  
|Rotina|Cabeçalho necessário|  
|-------------|---------------------|  
|`_CrtGetReportHook`|\<crtdbg.h>|  
  
 Para obter mais informações sobre compatibilidade, consulte [Compatibilidade](../../c-runtime-library/compatibility.md) na Introdução.  
  
## <a name="libraries"></a>Libraries  
 Somente versões de depuração de [bibliotecas de tempo de execução C](../../c-runtime-library/crt-library-features.md).  
  
## <a name="example"></a>Exemplo  
 Para obter uma amostra de como usar `_CrtSetReportHook`, consulte [report](http://msdn.microsoft.com/en-us/f6e08c30-6bd9-459a-830a-56deec0d2051).  
  
## <a name="see-also"></a>Consulte também  
 [Rotinas de depuração](../../c-runtime-library/debug-routines.md)   
 [_CrtSetReportHook](../../c-runtime-library/reference/crtsetreporthook.md)