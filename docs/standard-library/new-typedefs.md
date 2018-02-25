---
title: Typedefs &lt;new&gt; | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.tgt_pltfrm: 
ms.topic: reference
f1_keywords:
- new/std::new_handler
ms.assetid: aef01de1-06b5-4b6c-aebc-2c9f423d7e47
caps.latest.revision: 
manager: ghogen
ms.openlocfilehash: cbcc542095ad8b75bbe632f741f43206e436b5e4
ms.sourcegitcommit: d51ed21ab2b434535f5c1d553b22e432073e1478
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 02/23/2018
---
# <a name="ltnewgt-typedefs"></a>Typedefs &lt;new&gt;
||  
|-|  
|[new_handler](#new_handler)|  
  
##  <a name="new_handler"></a>  new_handler  
 O tipo aponta para uma função adequada para uso como um manipulador new.  
  
```
typedef void (*new_handler)();
```  
  
### <a name="remarks"></a>Comentários  
 Esse tipo de função do manipulador é chamado pelo **operatornew** ou `operator new[]` quando eles não podem atender uma solicitação de armazenamento adicional.  
  
### <a name="example"></a>Exemplo  
  Consulte [set_new_handler](../standard-library/new-functions.md#set_new_handler) para obter um exemplo usando `new_handler` como um valor retornado.  
  
## <a name="see-also"></a>Consulte também  
 [\<new>](../standard-library/new.md)



