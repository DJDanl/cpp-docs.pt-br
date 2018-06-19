---
title: omp_get_dynamic | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-parallel
ms.topic: reference
f1_keywords:
- omp_get_dynamic
dev_langs:
- C++
helpviewer_keywords:
- omp_get_dynamic OpenMP function
ms.assetid: efa843c5-7266-4a75-8db3-22992663d9db
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
ms.openlocfilehash: d97cae8091f88c283412b36ef757b03c72f7580d
ms.sourcegitcommit: 7019081488f68abdd5b2935a3b36e2a5e8c571f8
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/07/2018
ms.locfileid: "33691255"
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