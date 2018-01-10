---
title: _CrtDbgBreak | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology: cpp-standard-libraries
ms.tgt_pltfrm: 
ms.topic: article
apiname: _CrtDbgBreak
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
- _CrtDbgBreak
- CrtDbgBreak
dev_langs: C++
helpviewer_keywords:
- CrtDbgBreak function
- _CrtDbgBreak function
ms.assetid: 01f8b4a2-a2c7-4e1f-9f39-e573b4a7871f
caps.latest.revision: "12"
author: corob-msft
ms.author: corob
manager: ghogen
ms.workload: cplusplus
ms.openlocfilehash: dafc1b743af2b11c83f7dc6d932844c6aa9da609
ms.sourcegitcommit: 8fa8fdf0fbb4f57950f1e8f4f9b81b4d39ec7d7a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/21/2017
---
# <a name="crtdbgbreak"></a>_CrtDbgBreak
Define um ponto de interrupção em uma linha de código específica. (Usado somente no modo de depuração.)  
  
## <a name="syntax"></a>Sintaxe  
  
```  
void _CrtDbgBreak( void );  
```  
  
## <a name="return-value"></a>Valor de retorno  
 Nenhum valor de retorno.  
  
## <a name="remarks"></a>Comentários  
 A função `_CrtDbgBreak` define um ponto de interrupção de depuração na linha de código específica em que a função reside. Essa função é usada somente no modo de depuração e depende de `_DEBUG` ter sido previamente definido.  
  
 Para obter mais informações sobre como usar outras funções em tempo de execução compatíveis com gancho e escrever suas próprias funções de gancho definidas pelo cliente, consulte [Writing Your Own Debug Hook Functions](/visualstudio/debugger/debug-hook-function-writing) (Escrevendo suas próprias funções de gancho de depuração).  
  
## <a name="requirements"></a>Requisitos  
  
|Rotina|Cabeçalho necessário|  
|-------------|---------------------|  
|`_CrtDbgBreak`|\<CRTDBG.h>|  
  
## <a name="libraries"></a>Libraries  
 Somente versões de depuração de [bibliotecas de tempo de execução C](../../c-runtime-library/crt-library-features.md).  
  
## <a name="see-also"></a>Consulte também  
 [Rotinas de depuração](../../c-runtime-library/debug-routines.md)   
 [__debugbreak](../../intrinsics/debugbreak.md)