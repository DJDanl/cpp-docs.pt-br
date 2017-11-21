---
title: omp_get_dynamic | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology: cpp-windows
ms.tgt_pltfrm: 
ms.topic: article
f1_keywords: omp_get_dynamic
dev_langs: C++
helpviewer_keywords: omp_get_dynamic OpenMP function
ms.assetid: efa843c5-7266-4a75-8db3-22992663d9db
caps.latest.revision: "8"
author: mikeblome
ms.author: mblome
manager: ghogen
ms.openlocfilehash: 3f74f9d8f4f4bcff90c1b8204851814adfe84a4f
ms.sourcegitcommit: ebec1d449f2bd98aa851667c2bfeb7e27ce657b2
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/24/2017
---
# <a name="ompgetdynamic"></a>omp_get_dynamic
Retorna um valor que indica se o número de threads disponíveis na região parallel subsequente pode ser ajustado por tempo de execução.  
  
## <a name="syntax"></a>Sintaxe  
  
```  
int omp_get_dynamic();  
```  
  
## <a name="return-value"></a>Valor de retorno  
 Se for diferente de zero, o ajuste dinâmico de threads está habilitado.  
  
## <a name="remarks"></a>Comentários  
 Ajuste dinâmico de threads é especificado com [omp_set_dynamic](../../../parallel/openmp/reference/omp-set-dynamic.md) e [OMP_DYNAMIC](../../../parallel/openmp/reference/omp-dynamic.md).  
  
 Para obter mais informações, consulte [3.1.7 função omp_set_dynamic](../../../parallel/openmp/3-1-7-omp-set-dynamic-function.md).  
  
## <a name="example"></a>Exemplo  
 Consulte [omp_set_dynamic](../../../parallel/openmp/reference/omp-set-dynamic.md) para obter um exemplo de como usar `omp_get_dynamic`.  
  
## <a name="see-also"></a>Consulte também  
 [Funções](../../../parallel/openmp/reference/openmp-functions.md)