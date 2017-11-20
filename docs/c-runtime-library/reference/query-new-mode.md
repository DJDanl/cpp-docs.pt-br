---
title: _query_new_mode | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology: cpp-standard-libraries
ms.tgt_pltfrm: 
ms.topic: article
apiname: _query_new_mode
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
- query_new_mode
- _query_new_mode
dev_langs: C++
helpviewer_keywords:
- query_new_mode function
- handler modes
- _query_new_mode function
ms.assetid: e185c5f9-b73b-4257-8eff-b47648374768
caps.latest.revision: "10"
author: corob-msft
ms.author: corob
manager: ghogen
ms.openlocfilehash: 4f5cc42ee9aaeccfacf7088f5cc80a3d305169b6
ms.sourcegitcommit: ebec1d449f2bd98aa851667c2bfeb7e27ce657b2
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/24/2017
---
# <a name="querynewmode"></a>_query_new_mode
Retorna um inteiro que indica o novo modo de manipulador definido por `_set_new_mode` para `malloc`.  
  
## <a name="syntax"></a>Sintaxe  
  
```  
  
      int _query_new_mode(  
   void   
);  
```  
  
## <a name="return-value"></a>Valor de retorno  
 Retorna o modo atual do novo manipulador, ou seja 0 ou 1, para `malloc`. Um valor retornado de 1 indica que, em caso de falha ao alocar memória, `malloc` chama a nova rotina de manipulador; um valor retornado de 0 indica que não chama.  
  
## <a name="remarks"></a>Comentários  
 A função C++ `_query_new_mode` retorna um inteiro que indica o novo modo de manipulador definido pela função C++ [_set_new_mode](../../c-runtime-library/reference/set-new-mode.md) para [malloc](../../c-runtime-library/reference/malloc.md). O novo modo do manipulador indica se, em caso de falha de alocação de memória, `malloc` deverá chamar a nova rotina do manipulador conforme definido por [_set_new_handler](../../c-runtime-library/reference/set-new-handler.md). Por padrão, `malloc` não chama a nova rotina do manipulador em caso de falha. Você pode usar `_set_new_mode` para substituir esse comportamento para que, em caso de falha, `malloc` chame a nova rotina do manipulador da mesma forma que o operador **new** faz quando ele falha ao alocar memória. Para obter mais informações, consulte a discussão sobre os [operadores new e delete](../../cpp/new-and-delete-operators.md) na Referência da Linguagem C++.  
  
## <a name="requirements"></a>Requisitos  
  
|Rotina|Cabeçalho necessário|  
|-------------|---------------------|  
|`_query_new_mode`|\<new.h>|  
  
 Para obter mais informações sobre compatibilidade, consulte [Compatibilidade](../../c-runtime-library/compatibility.md) na Introdução.  
  
## <a name="libraries"></a>Libraries  
 Todas as versões das [bibliotecas em tempo de execução C](../../c-runtime-library/crt-library-features.md).  
  
## <a name="see-also"></a>Consulte também  
 [Alocação de Memória](../../c-runtime-library/memory-allocation.md)   
 [calloc](../../c-runtime-library/reference/calloc.md)   
 [free](../../c-runtime-library/reference/free.md)   
 [realloc](../../c-runtime-library/reference/realloc.md)   
 [_query_new_handler](../../c-runtime-library/reference/query-new-handler.md)