---
title: Typedefs &lt;new&gt; | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.tgt_pltfrm: 
ms.topic: article
f1_keywords:
- new/std::new_handler
ms.assetid: aef01de1-06b5-4b6c-aebc-2c9f423d7e47
caps.latest.revision: 7
manager: ghogen
ms.translationtype: MT
ms.sourcegitcommit: 65f4e356ad0d46333b0d443d0fd6ac0b9f2b6f58
ms.openlocfilehash: e23ea06002dc840997a0e7202f581cd81ef407c5
ms.contentlocale: pt-br
ms.lasthandoff: 10/03/2017

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




