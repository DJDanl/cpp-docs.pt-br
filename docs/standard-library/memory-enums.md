---
title: "Enumerações &lt;memory&gt; | Microsoft Docs"
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.tgt_pltfrm: 
ms.topic: article
ms.assetid: b9be0a7b-0beb-40b2-8183-911de371c6b9
caps.latest.revision: 11
manager: ghogen
translationtype: Machine Translation
ms.sourcegitcommit: 3168772cbb7e8127523bc2fc2da5cc9b4f59beb8
ms.openlocfilehash: 9c3440495d77b788658cffefc917d9960ca1f833
ms.lasthandoff: 02/25/2017

---
# <a name="ltmemorygt-enums"></a>Enumerações &lt;memory&gt;
||  
|-|  
|[Enumeração pointer_safety](#pointer_safety_enumeration)|  
  
##  <a name="a-namepointersafetyenumerationa--pointersafety-enumeration"></a><a name="pointer_safety_enumeration"></a> Enumeração pointer_safety  
 A enumeração dos possíveis valores retornados por `get_pointer_safety`.  
  
class pointer_safety { relaxed, preferred, strict };  
  
### <a name="remarks"></a>Comentários  
 O `enum` de escopo define os valores que podem ser retornados por `get_pointer_safety``()`:  
  
 `relaxed` – ponteiros não derivados de forma segura (obviamente ponteiros para objetos declarados ou alocados) são tratados da mesma maneira que os derivados de forma segura.  
  
 `preferred` – como antes, mas os ponteiros não derivados de forma segura não devem ser desreferenciados.  
  
 `strict` – os ponteiros não derivados de forma segura devem ser tratados de maneira diferente dos derivados de forma segura.  
  
## <a name="see-also"></a>Consulte também  
 [\<memory>](../standard-library/memory.md)




