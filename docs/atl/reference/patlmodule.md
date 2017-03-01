---
title: _pAtlModule | Documentos do Microsoft
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- devlang-cpp
ms.tgt_pltfrm: 
ms.topic: reference
f1_keywords:
- ATLBASE/_pAtlModule
- _pAtlModule
- ATL::_pAtlModule
- ATL._pAtlModule
dev_langs:
- C++
helpviewer_keywords:
- pAtlModule variable
- _pAtlModule variable
ms.assetid: 0ecde3a9-3f4d-4c7b-bb54-713ce05c4777
caps.latest.revision: 13
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
ms.sourcegitcommit: 5187996fc377bca8633360082d07f7ec8a68ee57
ms.openlocfilehash: b20c5010616323eac9438223df64af9960192e2b
ms.lasthandoff: 02/25/2017

---
# <a name="patlmodule"></a>_pAtlModule
Uma variável global armazenar um ponteiro para o módulo atual.  
  
## <a name="syntax"></a>Sintaxe  
  
```  
__declspec(selectany) CAtlModule* _pAtlModule  
```  
  
## <a name="remarks"></a>Comentários  
 Métodos nessa variável global podem ser usados para fornecer a funcionalidade que a classe (agora obsoleta) [CComModule](../../atl/reference/ccommodule-class.md) fornecido no Visual C++ 6.0.  
  
## <a name="example"></a>Exemplo  
 [!code-cpp[NVC_ATL_Windowing&#97;](../../atl/codesnippet/cpp/patlmodule_1.cpp)]  
  
## <a name="requirements"></a>Requisitos  
 **Cabeçalho:** atlbase. h  
  
## <a name="see-also"></a>Consulte também  
 [Variáveis globais](../../atl/reference/atl-global-variables.md)




