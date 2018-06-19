---
title: Constantes _locking | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-standard-libraries
ms.topic: conceptual
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
author: corob-msft
ms.author: corob
ms.workload:
- cplusplus
ms.openlocfilehash: 588c286cbad5e0097394a38eed34c09fc04af3ea
ms.sourcegitcommit: be2a7679c2bd80968204dee03d13ca961eaa31ff
ms.translationtype: HT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/03/2018
ms.locfileid: "32389963"
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