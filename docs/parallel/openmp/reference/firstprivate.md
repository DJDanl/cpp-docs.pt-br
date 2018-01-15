---
title: firstprivate | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology: cpp-windows
ms.tgt_pltfrm: 
ms.topic: article
f1_keywords: firstprivate
dev_langs: C++
helpviewer_keywords: firstprivate OpenMP clause
ms.assetid: db479766-6d3b-4bbd-b28e-b192d826788c
caps.latest.revision: "8"
author: mikeblome
ms.author: mblome
manager: ghogen
ms.workload: cplusplus
ms.openlocfilehash: 8c7d4a5ba23e343f7858bf3320ed05ebce84f1c2
ms.sourcegitcommit: 8fa8fdf0fbb4f57950f1e8f4f9b81b4d39ec7d7a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/21/2017
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
 `firstprivate`aplica-se para as seguintes diretivas:  
  
-   [for](../../../parallel/openmp/reference/for-openmp.md)  
  
-   [parallel](../../../parallel/openmp/reference/parallel.md)  
  
-   [seções](../../../parallel/openmp/reference/sections-openmp.md)  
  
-   [single](../../../parallel/openmp/reference/single.md)  
  
 Para obter mais informações, consulte [2.7.2.2 firstprivate](../../../parallel/openmp/2-7-2-2-firstprivate.md).  
  
## <a name="example"></a>Exemplo  
 Para obter um exemplo do uso de `firstprivate`, consulte o exemplo [particular](../../../parallel/openmp/reference/private-openmp.md).  
  
## <a name="see-also"></a>Consulte também  
 [Cláusulas](../../../parallel/openmp/reference/openmp-clauses.md)