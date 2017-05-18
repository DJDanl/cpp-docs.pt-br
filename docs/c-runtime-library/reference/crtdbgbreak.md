---
title: _CrtDbgBreak | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- cpp-standard-libraries
ms.tgt_pltfrm: 
ms.topic: article
apiname:
- _CrtDbgBreak
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
dev_langs:
- C++
helpviewer_keywords:
- CrtDbgBreak function
- _CrtDbgBreak function
ms.assetid: 01f8b4a2-a2c7-4e1f-9f39-e573b4a7871f
caps.latest.revision: 12
author: corob-msft
ms.author: corob
manager: ghogen
translation.priority.ht:
- cs-cz
- de-de
- es-es
- fr-fr
- it-it
- ja-jp
- ko-kr
- pl-pl
- pt-br
- ru-ru
- tr-tr
- zh-cn
- zh-tw
ms.translationtype: Machine Translation
ms.sourcegitcommit: e257f037a05c45f5b98e64ea55bd125af443b0be
ms.openlocfilehash: fd68d614e0c676d63bc8b5227eab95c3eae76258
ms.contentlocale: pt-br
ms.lasthandoff: 03/30/2017

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
