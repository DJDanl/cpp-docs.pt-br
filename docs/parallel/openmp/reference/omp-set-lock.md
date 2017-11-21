---
title: omp_set_lock | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology: cpp-windows
ms.tgt_pltfrm: 
ms.topic: article
f1_keywords: omp_set_lock
dev_langs: C++
helpviewer_keywords: omp_set_lock OpenMP function
ms.assetid: ded839cb-ca19-403f-8622-eb52ce512d31
caps.latest.revision: "7"
author: mikeblome
ms.author: mblome
manager: ghogen
ms.openlocfilehash: f2d63074ce989aa4bc96c829639386e3477ff523
ms.sourcegitcommit: ebec1d449f2bd98aa851667c2bfeb7e27ce657b2
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/24/2017
---
# <a name="ompsetlock"></a>omp_set_lock
Blocos de thread de execução até que um bloqueio esteja disponível.  
  
## <a name="syntax"></a>Sintaxe  
  
```  
void omp_set_lock(  
   omp_lock_t *lock  
);  
```  
  
## <a name="remarks"></a>Comentários  
 onde,  
  
 `lock`  
 Uma variável do tipo [omp_lock_t](../../../parallel/openmp/reference/omp-lock-t.md) que foi inicializado com [omp_init_lock](../../../parallel/openmp/reference/omp-init-lock.md).  
  
## <a name="remarks"></a>Comentários  
 Para obter mais informações, consulte [3.2.3 funções omp_set_lock e omp_set_nest_lock](../../../parallel/openmp/3-2-3-omp-set-lock-and-omp-set-nest-lock-functions.md).  
  
## <a name="examples"></a>Exemplos  
 Consulte [omp_init_lock](../../../parallel/openmp/reference/omp-init-lock.md) para obter um exemplo de como usar `omp_set_lock`.  
  
## <a name="see-also"></a>Consulte também  
 [Funções](../../../parallel/openmp/reference/openmp-functions.md)