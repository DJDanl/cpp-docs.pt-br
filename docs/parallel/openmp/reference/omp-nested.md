---
title: OMP_NESTED | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-parallel
ms.topic: reference
f1_keywords:
- OMP_NESTED
dev_langs:
- C++
helpviewer_keywords:
- OMP_NESTED OpenMP environment variable
ms.assetid: c43f5287-a548-40d0-bd54-0c6b2b9f9a53
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
ms.openlocfilehash: c6b51df88ae700f81cf84250cc06ae24c9131fec
ms.sourcegitcommit: 7019081488f68abdd5b2935a3b36e2a5e8c571f8
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/07/2018
---
# <a name="ompnested"></a>OMP_NESTED
Especifica se o paralelismo aninhado está habilitado, a menos que o paralelismo aninhado está habilitado ou desabilitado com `omp_set_nested`.  
  
## <a name="syntax"></a>Sintaxe  
  
```  
set OMP_NESTED[=TRUE | =FALSE]  
```  
  
## <a name="remarks"></a>Comentários  
 O `OMP_NESTED` variável de ambiente pode ser substituída pelo [omp_set_nested](../../../parallel/openmp/reference/omp-set-nested.md) função.  
  
 O valor padrão na implementação do padrão OpenMP Visual C++ é `OMP_DYNAMIC=FALSE`.  
  
 Para obter mais informações, consulte [OMP_NESTED 4,4](../../../parallel/openmp/4-4-omp-nested.md).  
  
## <a name="example"></a>Exemplo  
 O comando a seguir define o `OMP_NESTED` variável de ambiente para TRUE:  
  
```  
set OMP_NESTED=TRUE  
```  
  
 O comando a seguir exibe a configuração atual de `OMP_NESTED` variável de ambiente:  
  
```  
set OMP_NESTED  
```  
  
## <a name="see-also"></a>Consulte também  
 [Variáveis de ambiente](../../../parallel/openmp/reference/openmp-environment-variables.md)