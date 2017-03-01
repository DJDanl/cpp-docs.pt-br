---
title: omp_get_dynamic | Documentos do Microsoft
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- devlang-cpp
ms.tgt_pltfrm: 
ms.topic: article
f1_keywords:
- omp_get_dynamic
dev_langs:
- C++
helpviewer_keywords:
- omp_get_dynamic OpenMP function
ms.assetid: efa843c5-7266-4a75-8db3-22992663d9db
caps.latest.revision: 8
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
ms.openlocfilehash: bd026e3370d7f71626d63f285deba132c7a27987
ms.lasthandoff: 02/25/2017

---
# <a name="ompgetdynamic"></a>omp_get_dynamic
Retorna um valor que indica se o número de threads disponíveis na região paralela subsequente pode ser ajustado pelo tempo de execução.  
  
## <a name="syntax"></a>Sintaxe  
  
```  
int omp_get_dynamic();  
```  
  
## <a name="return-value"></a>Valor de retorno  
 Se for diferente de zero, o ajuste dinâmico de threads está habilitado.  
  
## <a name="remarks"></a>Comentários  
 Ajuste dinâmico de segmentos é especificado com [omp_set_dynamic](../../../parallel/openmp/reference/omp-set-dynamic.md) e [OMP_DYNAMIC](../../../parallel/openmp/reference/omp-dynamic.md).  
  
 Para obter mais informações, consulte [3.1.7 função omp_set_dynamic](../../../parallel/openmp/3-1-7-omp-set-dynamic-function.md).  
  
## <a name="example"></a>Exemplo  
 Consulte [omp_set_dynamic](../../../parallel/openmp/reference/omp-set-dynamic.md) para obter um exemplo de como usar `omp_get_dynamic`.  
  
## <a name="see-also"></a>Consulte também  
 [Funções](../../../parallel/openmp/reference/openmp-functions.md)
