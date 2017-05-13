---
title: _query_new_handler | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- devlang-cpp
ms.tgt_pltfrm: 
ms.topic: article
apiname:
- _query_new_handler
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
- api-ms-win-crt-heap-l1-1-0.dll
apitype: DLLExport
f1_keywords:
- _query_new_handler
- query_new_handler
dev_langs:
- C++
helpviewer_keywords:
- query_new_handler function
- handler routines
- error handling
- _query_new_handler function
ms.assetid: 9a84b5c3-fe33-4c01-83a0-be87dc3ec518
caps.latest.revision: 10
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
ms.openlocfilehash: 63d43e80009b0d6c8f2d827f6ea5b239d7a39663
ms.contentlocale: pt-br
ms.lasthandoff: 03/30/2017

---
# <a name="querynewhandler"></a>_query_new_handler
Retorna o endereço da rotina atual do novo manipulador.  
  
## <a name="syntax"></a>Sintaxe  
  
```  
_PNH _query_new_handler(  
   void   
);  
```  
  
## <a name="return-value"></a>Valor de retorno  
 Retorna o endereço da rotina atual do novo manipulador conforme definido por `_set_new_handler`.  
  
## <a name="remarks"></a>Comentários  
 A função `_query_new_handler` C++ retorna o endereço da função de manipulação de exceção atual definida pela função C++ [_set_new_handler](../../c-runtime-library/reference/set-new-handler.md). `_set_new_handler` é usado para especificar uma função de manipulação de exceção que assumirá o controle se o operador **new** falhar ao alocar memória. Para obter mais informações, consulte a discussão sobre os [operadores new e delete](../../cpp/new-and-delete-operators.md) na Referência da Linguagem C++.  
  
## <a name="requirements"></a>Requisitos  
  
|Rotina|Cabeçalho necessário|  
|-------------|---------------------|  
|`_query_new_handler`|\<new.h>|  
  
 Para obter mais informações sobre compatibilidade, consulte [Compatibilidade](../../c-runtime-library/compatibility.md) na Introdução.  
  
## <a name="libraries"></a>Libraries  
 Todas as versões das [bibliotecas em tempo de execução C](../../c-runtime-library/crt-library-features.md).  
  
## <a name="see-also"></a>Consulte também  
 [Alocação de Memória](../../c-runtime-library/memory-allocation.md)   
 [free](../../c-runtime-library/reference/free.md)
