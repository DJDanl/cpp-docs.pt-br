---
title: ___setlc_active_func, ___unguarded_readlc_active_add_func | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- cpp-standard-libraries
ms.tgt_pltfrm: 
ms.topic: article
apiname:
- ___setlc_active_func
- ___unguarded_readlc_active_add_func
apilocation:
- msvcr90.dll
- msvcr110_clr0400.dll
- msvcrt.dll
- msvcr110.dll
- msvcr80.dll
- msvcr120.dll
- msvcr100.dll
apitype: DLLExport
f1_keywords:
- ___unguarded_readlc_active_add_func
- ___setlc_active_func
dev_langs:
- C++
helpviewer_keywords:
- ___setlc_active_func
- ___unguarded_readlc_active_add_func
ms.assetid: 605ec4e3-81e5-4ece-935a-f434768cc702
caps.latest.revision: 
author: corob-msft
ms.author: corob
manager: ghogen
ms.workload:
- cplusplus
ms.openlocfilehash: 0a1ecc14403a7a08fed73fb10f15dd25051b0a28
ms.sourcegitcommit: 8fa8fdf0fbb4f57950f1e8f4f9b81b4d39ec7d7a
ms.translationtype: HT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/21/2017
---
# <a name="setlcactivefunc-unguardedreadlcactiveaddfunc"></a>___setlc_active_func, ___unguarded_readlc_active_add_func
OBSOLETO. O CRT exporta essas funções internas somente para preservar a compatibilidade binária.  
  
## <a name="syntax"></a>Sintaxe  
  
```cpp  
int ___setlc_active_func(void);  
int * ___unguarded_readlc_active_add_func(void);  
```  
  
## <a name="return-value"></a>Valor retornado  
 O valor retornado não é significativo.  
  
## <a name="remarks"></a>Comentários  
 Embora as funções CRT internas `___setlc_active_func` e `___unguarded_readlc_active_add_func` sejam obsoletas e não sejam mais utilizadas, elas são exportadas pela biblioteca do CRT para preservar a compatibilidade binária. O propósito original de `___setlc_active_func` era retornar o número de chamadas ativas no momento para a função `setlocale`. O propósito original de `___unguarded_readlc_active_add_func` era retornar o número de funções que faziam referência ao código de idioma sem bloqueá-lo.  
  
## <a name="requirements"></a>Requisitos  
  
|Rotina|Cabeçalho necessário|  
|-------------|---------------------|  
|`___setlc_active_func`, `___unguarded_readlc_active_add_func`|nenhum|  
  
## <a name="see-also"></a>Consulte também  
 [setlocale, _wsetlocale](../c-runtime-library/reference/setlocale-wsetlocale.md)