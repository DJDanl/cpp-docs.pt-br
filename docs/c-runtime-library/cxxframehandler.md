---
title: __CxxFrameHandler | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- cpp-standard-libraries
ms.tgt_pltfrm: 
ms.topic: article
apiname:
- __CxxFrameHandler
apilocation:
- msvcr110.dll
- msvcrt.dll
- msvcr80.dll
- msvcr100.dll
- msvcr110_clr0400.dll
- msvcr90.dll
- msvcr120.dll
apitype: DLLExport
f1_keywords:
- __CxxFrameHandler
dev_langs:
- C++
helpviewer_keywords:
- __CxxFrameHandler
ms.assetid: b79ac97f-425a-42ae-9b91-8beaef935333
caps.latest.revision: 3
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
ms.translationtype: Human Translation
ms.sourcegitcommit: 3168772cbb7e8127523bc2fc2da5cc9b4f59beb8
ms.openlocfilehash: 3756ac523e7a90055e3f10808d7da4f68aabfa7c
ms.contentlocale: pt-br
ms.lasthandoff: 02/25/2017

---
# <a name="cxxframehandler"></a>__CxxFrameHandler
Função CRT interna. Usada pelo CRT para identificar quadros estruturados de exceção.  
  
## <a name="syntax"></a>Sintaxe  
  
```cpp  
EXCEPTION_DISPOSITION __CxxFrameHandler(  
      EHExceptionRecord  *pExcept,  
      EHRegistrationNode *pRN,  
      void               *pContext,   
      DispatcherContext  *pDC  
   )  
```  
  
#### <a name="parameters"></a>Parâmetros  
 `pExcept`  
 Registro de exceção passado para as instruções `catch` possíveis.  
  
 `pRN`  
 Informações dinâmicas sobre o registro de ativação usado para identificar a exceção. Para obter mais informações, consulte ehdata.h.  
  
 `pContext`  
 Contexto. (Não usado em processadores da Intel.)  
  
 `pDC`  
 Informações adicionais sobre a entrada da função e o registro de ativação.  
  
## <a name="return-value"></a>Valor de retorno  
 Um dos valores da *expressão de filtro* usados pela [instrução try-except](../cpp/try-except-statement.md).  
  
## <a name="remarks"></a>Comentários  
  
## <a name="requirements"></a>Requisitos  
  
|Rotina|Cabeçalho necessário|  
|-------------|---------------------|  
|__CxxFrameHandler|excpt.h, ehdata.h|
