---
title: "Funções &lt;forward_list&gt; | Microsoft Docs"
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.tgt_pltfrm: 
ms.topic: article
ms.assetid: 0d6bc656-7049-4651-a4bd-c9a805e47756
caps.latest.revision: 11
manager: ghogen
translationtype: Machine Translation
ms.sourcegitcommit: 3168772cbb7e8127523bc2fc2da5cc9b4f59beb8
ms.openlocfilehash: b1c8cbb3a8dbbf7f6c14400f531e7ab40a2c84f6
ms.lasthandoff: 02/25/2017

---
# <a name="ltforwardlistgt-functions"></a>Funções &lt;forward_list&gt;
||  
|-|  
|[swap](#swap)|  
  
##  <a name="a-nameswapa--swap"></a><a name="swap"></a>  swap  
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




