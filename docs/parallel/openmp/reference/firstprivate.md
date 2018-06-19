---
title: firstprivate | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-parallel
ms.topic: reference
f1_keywords:
- firstprivate
dev_langs:
- C++
helpviewer_keywords:
- firstprivate OpenMP clause
ms.assetid: db479766-6d3b-4bbd-b28e-b192d826788c
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
ms.openlocfilehash: 10b5a270feb638a98c060b58e90af8146ff97325
ms.sourcegitcommit: 7019081488f68abdd5b2935a3b36e2a5e8c571f8
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/07/2018
ms.locfileid: "33691697"
---
# <a name="firstprivate"></a>firstprivate
Especifica que cada thread deve ter sua própria instância de uma variável, e que a variável deve ser inicializada com o valor da variável, porque ele existe antes da construção paralela.  
  
## <a name="syntax"></a>Sintaxe  
  
```  
firstprivate(var)  
```  
  
#### <a name="parameters"></a>Parâmetros  
  
|Parâmetro|Descrição|  
|---------------|-----------------|  
|`var`|A variável para ter instâncias em cada thread e que será inicializada com o valor da variável, porque ele existe antes da construção paralela. Se mais de uma variável for especificada, separe os nomes de variável com uma vírgula.|  
  
## <a name="remarks"></a>Comentários  
  
## <a name="remarks"></a>Comentários  
 `firstprivate` aplica-se para as seguintes diretivas:  
  
-   [for](../../../parallel/openmp/reference/for-openmp.md)  
  
-   [parallel](../../../parallel/openmp/reference/parallel.md)  
  
-   [Seções](../../../parallel/openmp/reference/sections-openmp.md)  
  
-   [single](../../../parallel/openmp/reference/single.md)  
  
 Para obter mais informações, consulte [2.7.2.2 firstprivate](../../../parallel/openmp/2-7-2-2-firstprivate.md).  
  
## <a name="example"></a>Exemplo  
 Para obter um exemplo do uso de `firstprivate`, consulte o exemplo [particular](../../../parallel/openmp/reference/private-openmp.md).  
  
## <a name="see-also"></a>Consulte também  
 [Cláusulas](../../../parallel/openmp/reference/openmp-clauses.md)