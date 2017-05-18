---
title: Constantes _locking | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- cpp-standard-libraries
ms.tgt_pltfrm: 
ms.topic: article
f1_keywords:
- _LK_RLCK
- _LK_NBLCK
- _LK_LOCK
- _LK_NBRLCK
- _LK_UNLCK
dev_langs:
- C++
helpviewer_keywords:
- LK_UNLCK constant
- LK_NBRLCK constant
- _LK_NBRLCK constant
- _LK_NBLCK constant
- _LK_LOCK constant
- LK_NBLCK constant
- _LK_UNLCK constant
- LK_RLCK constant
- _LK_RLCK constant
- LK_LOCK constant
ms.assetid: c3dc92c8-60e3-4d29-9f50-5d217627c8ad
caps.latest.revision: 7
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
ms.sourcegitcommit: a937c9d083a7e4331af63323a19fb207142604a0
ms.openlocfilehash: 883e7ea979cbc4afd83ac8bfb5fa3ec4d68491c4
ms.contentlocale: pt-br
ms.lasthandoff: 02/25/2017

---
# <a name="locking-constants"></a>Constantes (_locking)
## <a name="syntax"></a>Sintaxe  
  
```  
  
#include <sys/locking.h>  
  
```  
  
## <a name="remarks"></a>Comentários  
 O argumento *mode* na chamada para a função `_locking` especifica a ação de bloqueio que será executada.  
  
 O argumento *mode* deve ser uma das constantes de manifesto a seguir.  
  
 `_LK_LOCK`  
 Bloqueia os bytes especificados. Se os bytes não puderem ser bloqueados, a função tentará novamente após 1 segundo. Se, após 10 tentativas, os bytes não puderem ser bloqueados, a função retornará um erro.  
  
 `_LK_RLCK`  
 Mesmo que `_LK_LOCK`.  
  
 `_LK_NBLCK`  
 Bloqueia os bytes especificados. Se os bytes não puderem ser bloqueados, a função retornará um erro.  
  
 `_LK_NBRLCK`  
 Mesmo que `_LK_NBLCK`.  
  
 `_LK_UNLCK`  
 Desbloqueia os bytes especificados. (Os bytes devem ter sido protegidos anteriormente.)  
  
## <a name="see-also"></a>Consulte também  
 [_locking](../c-runtime-library/reference/locking.md)   
 [Constantes globais](../c-runtime-library/global-constants.md)
