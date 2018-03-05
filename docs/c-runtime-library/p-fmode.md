---
title: __p__fmode | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- cpp-standard-libraries
ms.tgt_pltfrm: 
ms.topic: article
apiname:
- __p__fmode
apilocation:
- msvcr80.dll
- msvcr120.dll
- msvcr90.dll
- msvcrt.dll
- msvcr110.dll
- msvcr110_clr0400.dll
- msvcr100.dll
apitype: DLLExport
f1_keywords:
- __p__fmode
dev_langs:
- C++
helpviewer_keywords:
- __p__fmode
ms.assetid: 1daa1394-81eb-43aa-a71b-4cc6acf3207b
caps.latest.revision: 
author: corob-msft
ms.author: corob
manager: ghogen
ms.workload:
- cplusplus
ms.openlocfilehash: 341eab038db17b39e5b2a408db7c61c69d432fe9
ms.sourcegitcommit: 8fa8fdf0fbb4f57950f1e8f4f9b81b4d39ec7d7a
ms.translationtype: HT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/21/2017
---
# <a name="pfmode"></a>__p__fmode
Aponta para a variável global `_fmode`, que especifica o *modo de translação de arquivos* padrão para operações de E/S de arquivo.  
  
## <a name="syntax"></a>Sintaxe  
  
```cpp  
int* __p__fmode(  
   );  
```  
  
## <a name="return-value"></a>Valor retornado  
 Ponteiro para a variável global `_fmode`.  
  
## <a name="remarks"></a>Comentários  
 A função `__p__fmode` destina-se apenas ao uso interno e não deve ser chamada do código do usuário.  
  
 O modo de translação de arquivo especifica uma translação `binary` ou `text` para operações E/S [_open](../c-runtime-library/reference/open-wopen.md) e [_pipe](../c-runtime-library/reference/pipe.md). Para obter mais informações, consulte [_fmode](../c-runtime-library/fmode.md).  
  
## <a name="requirements"></a>Requisitos  
  
|Rotina|Cabeçalho necessário|  
|-------------|---------------------|  
|__p\__fmode|stdlib.h|