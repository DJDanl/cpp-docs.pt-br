---
title: ___setlc_active_func, ___unguarded_readlc_active_add_func | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-standard-libraries
ms.topic: conceptual
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
author: corob-msft
ms.author: corob
ms.workload:
- cplusplus
ms.openlocfilehash: 532aac2e47a402ae04ba4d4bf4fcb133c997bd31
ms.sourcegitcommit: be2a7679c2bd80968204dee03d13ca961eaa31ff
ms.translationtype: HT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/03/2018
ms.locfileid: "32409729"
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