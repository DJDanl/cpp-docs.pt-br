---
title: omp_destroy_lock | Documentos do Microsoft
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- devlang-cpp
ms.tgt_pltfrm: 
ms.topic: article
f1_keywords:
- omp_destroy_lock
dev_langs:
- C++
helpviewer_keywords:
- omp_destroy_lock OpenMP function
ms.assetid: b73ab036-b76f-4e42-82ff-c89db2edf7c0
caps.latest.revision: 7
author: mikeblome
ms.author: mblome
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
translationtype: Machine Translation
ms.sourcegitcommit: 3168772cbb7e8127523bc2fc2da5cc9b4f59beb8
ms.openlocfilehash: de0aef447ccea48fc6cf045bca67413e51241231
ms.lasthandoff: 02/25/2017

---
# <a name="ompdestroylock"></a>omp_destroy_lock
Cancela a inicialização de um bloqueio.  
  
## <a name="syntax"></a>Sintaxe  
  
```  
void omp_destroy_lock(  
   omp_lock_t *lock  
);  
```  
  
## <a name="remarks"></a>Comentários  
 onde,  
  
 `lock`  
 Uma variável do tipo [omp_lock_t ()](../../../parallel/openmp/reference/omp-lock-t.md) que foi inicializado com [omp_init_lock](../../../parallel/openmp/reference/omp-init-lock.md).  
  
## <a name="remarks"></a>Comentários  
 Para obter mais informações, consulte [3.2.2 funções omp_destroy_lock e omp_destroy_nest_lock](../../../parallel/openmp/3-2-2-omp-destroy-lock-and-omp-destroy-nest-lock-functions.md).  
  
## <a name="example"></a>Exemplo  
 Consulte [omp_init_lock](../../../parallel/openmp/reference/omp-init-lock.md) para obter um exemplo de como usar `omp_destroy_lock`.  
  
## <a name="see-also"></a>Consulte também  
 [Funções](../../../parallel/openmp/reference/openmp-functions.md)
