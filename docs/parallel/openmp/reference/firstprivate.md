---
title: firstprivate | Documentos do Microsoft
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- devlang-cpp
ms.tgt_pltfrm: 
ms.topic: article
f1_keywords:
- firstprivate
dev_langs:
- C++
helpviewer_keywords:
- firstprivate OpenMP clause
ms.assetid: db479766-6d3b-4bbd-b28e-b192d826788c
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
ms.openlocfilehash: 03bea93209428a0edbd4c87779d46c633bbe6259
ms.lasthandoff: 02/25/2017

---
# <a name="firstprivate"></a>firstprivate
Especifica que cada thread deve ter sua própria instância de uma variável, e que a variável deve ser inicializada com o valor da variável, pois ela existe antes da construção parallel.  
  
## <a name="syntax"></a>Sintaxe  
  
```  
firstprivate(var)  
```  
  
#### <a name="parameters"></a>Parâmetros  
  
|Parâmetro|Descrição|  
|---------------|-----------------|  
|`var`|A variável ter instâncias de cada thread e que será inicializada com o valor da variável, porque ele existe antes da construção parallel. Se mais de uma variável for especificada, separe os nomes de variáveis com uma vírgula.|  
  
## <a name="remarks"></a>Comentários  
  
## <a name="remarks"></a>Comentários  
 `firstprivate`aplica-se para as seguintes diretivas:  
  
-   [for](../../../parallel/openmp/reference/for-openmp.md)  
  
-   [paralelo](../../../parallel/openmp/reference/parallel.md)  
  
-   [seções](../../../parallel/openmp/reference/sections-openmp.md)  
  
-   [único](../../../parallel/openmp/reference/single.md)  
  
 Para obter mais informações, consulte [2.7.2.2 firstprivate](../../../parallel/openmp/2-7-2-2-firstprivate.md).  
  
## <a name="example"></a>Exemplo  
 Para obter um exemplo de uso `firstprivate`, consulte o exemplo na [particular](../../../parallel/openmp/reference/private-openmp.md).  
  
## <a name="see-also"></a>Consulte também  
 [Cláusulas](../../../parallel/openmp/reference/openmp-clauses.md)
