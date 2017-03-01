---
title: _callnewh | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- devlang-cpp
ms.tgt_pltfrm: 
ms.topic: article
apiname:
- _callnewh
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
- _callnewh
dev_langs:
- C++
helpviewer_keywords:
- _callnewh
ms.assetid: 4dcb73e9-6384-4d12-a973-a8807d4de7a8
caps.latest.revision: 3
author: corob-msft
ms.author: corob
manager: ghogen
translation.priority.ht:
- de-de
- es-es
- fr-fr
- it-it
- ja-jp
- ko-kr
- ru-ru
- zh-cn
- zh-tw
translation.priority.mt:
- cs-cz
- pl-pl
- pt-br
- tr-tr
translationtype: Machine Translation
ms.sourcegitcommit: 3168772cbb7e8127523bc2fc2da5cc9b4f59beb8
ms.openlocfilehash: 37b95f22528690b1e9b37c38e2b63792906b5459
ms.lasthandoff: 02/25/2017

---
# <a name="callnewh"></a>_callnewh
Chama o *novo manipulador* atualmente instalado.  
  
## <a name="syntax"></a>Sintaxe  
  
```cpp  
int _callnewh(  
   size_t size  
   )  
```  
  
#### <a name="parameters"></a>Parâmetros  
 `size`  
 A quantidade de memória que o [novo operador](../../cpp/new-operator-cpp.md) tentou alocar.  
  
## <a name="return-value"></a>Valor retornado  
  
|Valor|Descrição|  
|-----------|-----------------|  
|0|Falha: nenhum novo manipulador está instalado ou nenhum novo manipulador está ativo.|  
|1|Sucesso: o novo manipulador está instalado e ativo. A alocação de memória pode ser repetida.|  
  
## <a name="exceptions"></a>Exceções  
 Essa função gerará [bad_alloc](../../standard-library/bad-alloc-class.md) se o *novo manipulador* não puder ser localizado.  
  
## <a name="remarks"></a>Comentários  
 O *novo manipulador* será chamado se o [novo operador](../../cpp/new-operator-cpp.md) falhar em alocar memória com sucesso. O novo manipulador pode então iniciar alguma ação apropriada, como liberar a memória, para que as alocações subsequentes tenham sucesso.  
  
## <a name="requirements"></a>Requisitos  
  
|Rotina|Cabeçalho necessário|  
|-------------|---------------------|  
|_callnewh|internal.h|  
  
## <a name="see-also"></a>Consulte também  
 [_set_new_handler](../../c-runtime-library/reference/set-new-handler.md)   
 [_set_new_mode](../../c-runtime-library/reference/set-new-mode.md)
