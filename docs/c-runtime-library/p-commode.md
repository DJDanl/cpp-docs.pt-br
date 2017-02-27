---
title: __p__commode | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- devlang-cpp
ms.tgt_pltfrm: 
ms.topic: article
apiname:
- __p__commode
apilocation:
- msvcr110.dll
- msvcrt.dll
- msvcr120.dll
- msvcr90.dll
- msvcr100.dll
- msvcr80.dll
- msvcr110_clr0400.dll
- api-ms-win-crt-stdio-l1-1-0.dll
apitype: DLLExport
f1_keywords:
- __p__commode
dev_langs:
- C++
helpviewer_keywords:
- __p__commode
ms.assetid: 4380acb8-e3e4-409c-a60f-6205ac5189ce
caps.latest.revision: 2
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
translationtype: Human Translation
ms.sourcegitcommit: 3168772cbb7e8127523bc2fc2da5cc9b4f59beb8
ms.openlocfilehash: 1ae9ef3c73cb3b88eb33869fbbfac090acac1921

---
# <a name="pcommode"></a>__p__commode
Aponta para a variável global `_commode`, que especifica o *modo de confirmação de arquivos* padrão para operações de E/S de arquivo.  
  
## <a name="syntax"></a>Sintaxe  
  
```cpp  
int * __p__commode(  
   );  
```  
  
## <a name="return-value"></a>Valor de retorno  
 Ponteiro para a variável global `_commode`.  
  
## <a name="remarks"></a>Comentários  
 A função `__p__commode` destina-se apenas ao uso interno e não deve ser chamada do código do usuário.  
  
 O modo de confirmação de arquivo especifica quando os dados críticos são gravados no disco. Para obter mais informações, consulte [fflush](../c-runtime-library/reference/fflush.md).  
  
## <a name="requirements"></a>Requisitos  
  
|Rotina|Cabeçalho necessário|  
|-------------|---------------------|  
|__p\__commode|internal.h|


<!--HONumber=Feb17_HO4-->


