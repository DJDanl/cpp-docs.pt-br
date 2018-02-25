---
title: "Funções &lt;forward_list&gt; | Microsoft Docs"
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.tgt_pltfrm: 
ms.topic: reference
f1_keywords:
- forward_list/std::swap
ms.assetid: 0d6bc656-7049-4651-a4bd-c9a805e47756
caps.latest.revision: 
manager: ghogen
ms.openlocfilehash: ce66354d2377e52043830925c3f4f880de996663
ms.sourcegitcommit: d51ed21ab2b434535f5c1d553b22e432073e1478
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 02/23/2018
---
# <a name="ltforwardlistgt-functions"></a>Funções &lt;forward_list&gt;
||  
|-|  
|[swap](#swap)|  
  
##  <a name="swap"></a>  swap  
 Troca os elementos de duas listas de encaminhamento.  
  
```
void swap(
    forward_list <Type, Allocator>& left,
    forward_list <Type, Allocator>& right);
```  
  
### <a name="parameters"></a>Parâmetros  
  
|Parâmetro|Descrição|  
|---------------|-----------------|  
|`left`|Um objeto do tipo `forward_list`.|  
|`right`|Um objeto do tipo `forward_list`.|  
  
### <a name="remarks"></a>Comentários  
 Esta função de modelo executa `left.swap(right)`.  
  
## <a name="see-also"></a>Consulte também  
 [<forward_list>](../standard-library/forward-list.md)



