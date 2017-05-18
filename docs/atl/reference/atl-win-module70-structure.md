---
title: Estrutura de _ATL_WIN_MODULE70 | Documentos do Microsoft
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- cpp-windows
ms.tgt_pltfrm: 
ms.topic: article
f1_keywords:
- _ATL_WIN_MODULE70
- ATL::_ATL_WIN_MODULE70
- ATL._ATL_WIN_MODULE70
dev_langs:
- C++
helpviewer_keywords:
- _ATL_WIN_MODULE70 structure
- ATL_WIN_MODULE70 structure
ms.assetid: a0aaf3ea-ca77-46ec-bd53-4dfb61dffbea
caps.latest.revision: 15
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
ms.translationtype: Machine Translation
ms.sourcegitcommit: 4e393abb2a904a0f5e101efe3d78d0645664397b
ms.openlocfilehash: 383384c8f08b98592f92b5d38850137c1c0c6d54
ms.contentlocale: pt-br
ms.lasthandoff: 02/25/2017

---
# <a name="atlwinmodule70-structure"></a>Estrutura _ATL_WIN_MODULE70
Usado pelo código de janelas em ATL.  
  
## <a name="syntax"></a>Sintaxe  
  
```
struct _ATL_WIN_MODULE70 {
    UNIT cbSize; 
    CRITICAL_SECTION m_csWindowCreate;
    _AtlCreateWndData* m_pCreateWndList;
    CSimpleArray<ATOM> m_rgWindowClassAtoms;
};
```  
  
## <a name="members"></a>Membros  
 `cbSize`  
 O tamanho da estrutura, usado para controle de versão.  
  
 `m_csWindowCreate`  
 Usado para serializar o acesso a código de registro de janela. Usado internamente pelo ATL.  
  
 **m_pCreateWndList**  
 Usado para ligar o windows para seus objetos. Usado internamente pelo ATL.  
  
 **m_rgWindowClassAtoms**  
 Usado para controlar os registros de classe de janela para que eles possam ser registrados corretamente no encerramento. Usado internamente pelo ATL.  
  
## <a name="remarks"></a>Comentários  
 [_ATL_WIN_MODULE](atl-typedefs.md#_atl_win_module) é definido como um typedef de `_ATL_WIN_MODULE70`.  
  
## <a name="requirements"></a>Requisitos  
 **Cabeçalho:** atlbase. h  
  
## <a name="see-also"></a>Consulte também  
 [Estruturas](../../atl/reference/atl-structures.md)






