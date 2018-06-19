---
title: __CxxFrameHandler | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-standard-libraries
ms.topic: conceptual
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
author: corob-msft
ms.author: corob
ms.workload:
- cplusplus
ms.openlocfilehash: 53659b462f811bca79209dd141d90527401cbc95
ms.sourcegitcommit: be2a7679c2bd80968204dee03d13ca961eaa31ff
ms.translationtype: HT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/03/2018
ms.locfileid: "32388274"
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
  
## <a name="return-value"></a>Valor retornado  
 Um dos valores da *expressão de filtro* usados pela [instrução try-except](../cpp/try-except-statement.md).  
  
## <a name="remarks"></a>Comentários  
  
## <a name="requirements"></a>Requisitos  
  
|Rotina|Cabeçalho necessário|  
|-------------|---------------------|  
|__CxxFrameHandler|excpt.h, ehdata.h|