---
title: omp_get_nested | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-parallel
ms.topic: reference
f1_keywords:
- omp_get_nested
dev_langs:
- C++
helpviewer_keywords:
- omp_get_nested OpenMP function
ms.assetid: e9784847-516e-40d3-89f7-b8b6898d8667
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
ms.openlocfilehash: 59900f0a1aba1cbc3bacc5cd1d8832e60aebe30b
ms.sourcegitcommit: 7019081488f68abdd5b2935a3b36e2a5e8c571f8
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/07/2018
ms.locfileid: "33686874"
---
# <a name="ompgetnested"></a>omp_get_nested
Retorna um valor que indica se o paralelismo aninhado está habilitado.  
  
## <a name="syntax"></a>Sintaxe  
  
```  
int omp_get_nested( );  
```  
  
## <a name="return-value"></a>Valor de retorno  
 Se for diferente de zero, paralelismo aninhado está habilitado.  
  
## <a name="remarks"></a>Comentários  
 Paralelismo aninhado é especificado com [omp_set_nested](../../../parallel/openmp/reference/omp-set-nested.md) e [OMP_NESTED](../../../parallel/openmp/reference/omp-nested.md).  
  
 Para obter mais informações, consulte [3.1.10 função omp_get_nested](../../../parallel/openmp/3-1-10-omp-get-nested-function.md).  
  
## <a name="example"></a>Exemplo  
 Consulte [omp_set_nested](../../../parallel/openmp/reference/omp-set-nested.md) para obter um exemplo de como usar `omp_get_nested`.  
  
## <a name="see-also"></a>Consulte também  
 [Funções](../../../parallel/openmp/reference/openmp-functions.md)