---
title: _set_new_mode | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- cpp-standard-libraries
ms.tgt_pltfrm: 
ms.topic: reference
apiname:
- _set_new_mode
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
- set_new_mode
- _set_new_mode
dev_langs:
- C++
helpviewer_keywords:
- handler modes
- _set_new_mode function
- set_new_mode function
ms.assetid: 4d14039a-e54e-4689-8c70-74a4b9834768
caps.latest.revision: 
author: corob-msft
ms.author: corob
manager: ghogen
ms.workload:
- cplusplus
ms.openlocfilehash: e0c49e60201374f2c9cc916d65077c2800ed48ab
ms.sourcegitcommit: 6002df0ac79bde5d5cab7bbeb9d8e0ef9920da4a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 02/14/2018
---
# <a name="setnewmode"></a>_set_new_mode
Define um novo modo do manipulador para `malloc`.  
  
## <a name="syntax"></a>Sintaxe  
  
```  
int _set_new_mode(  
   int newhandlermode   
);  
```  
  
#### <a name="parameters"></a>Parâmetros  
 `newhandlermode`  
 Novo modo do manipulador para `malloc`; o valor válido é 0 ou 1.  
  
## <a name="return-value"></a>Valor de retorno  
 Retorna o modo do manipulador anterior definido para `malloc`. Um valor retornado de 1 indica que, em caso de falha ao alocar memória, `malloc` chamou anteriormente a nova rotina de manipulador; um valor retornado de 0 indica que não chamou. Se o `newhandlermode` argumento não é igual a 0 ou 1, retornará -1.  
  
## <a name="remarks"></a>Comentários  
 A função `_set_new_mode` C++ define o novo modo do manipulador para [malloc](../../c-runtime-library/reference/malloc.md). O novo modo do manipulador indica se, em caso de falha, `malloc` deverá chamar a nova rotina do manipulador conforme definido por [_set_new_handler](../../c-runtime-library/reference/set-new-handler.md). Por padrão, `malloc` não chama a nova rotina do manipulador em caso de falha ao alocar memória. Você pode substituir esse comportamento padrão para que, quando `malloc` falhar ao alocar memória, `malloc` chame a nova rotina do manipulador da mesma forma que o operador `new` fará quando ele falhar pelo mesmo motivo. Para obter mais informações, consulte os operadores [new](../../cpp/new-operator-cpp.md) e [delete](../../cpp/delete-operator-cpp.md) na *Referência da Linguagem C++*. Para substituir o padrão, chame:  
  
```  
_set_new_mode(1)  
```  
  
 no início do seu programa ou vincule com Newmode.obj (consulte [Opções de link](../../c-runtime-library/link-options.md)).  
  
 Esta função valida seu parâmetro. Se `newhandlermode` tiver qualquer valor diferente de 0 ou 1, a função invocará o manipulador de parâmetro inválido, conforme descrito em [Validação de parâmetro](../../c-runtime-library/parameter-validation.md). Se a execução puder continuar, **_**`set_new_mode` retornará -1 e definirá `errno` para `EINVAL`.  
  
## <a name="requirements"></a>Requisitos  
  
|Rotina|Cabeçalho necessário|  
|-------------|---------------------|  
|`_set_new_mode`|\<new.h>|  
  
 Para obter mais informações sobre compatibilidade, consulte [Compatibilidade](../../c-runtime-library/compatibility.md) na Introdução.  
  
## <a name="see-also"></a>Consulte também  
 [Alocação de Memória](../../c-runtime-library/memory-allocation.md)   
 [calloc](../../c-runtime-library/reference/calloc.md)   
 [free](../../c-runtime-library/reference/free.md)   
 [realloc](../../c-runtime-library/reference/realloc.md)   
 [_query_new_handler](../../c-runtime-library/reference/query-new-handler.md)   
 [_query_new_mode](../../c-runtime-library/reference/query-new-mode.md)