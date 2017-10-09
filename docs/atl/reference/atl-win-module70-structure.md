---
title: Estrutura de _ATL_WIN_MODULE70 | Microsoft Docs
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
ms.translationtype: MT
ms.sourcegitcommit: c55726a1728185f699afbac4ba68a6dc0f70c2bf
ms.openlocfilehash: 7f521b418b7d179eb506a5e9df2887addec059ef
ms.contentlocale: pt-br
ms.lasthandoff: 10/09/2017

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
 Usado para serializar o acesso ao código de registro de janela. Usado internamente pelo ATL.  
  
 **m_pCreateWndList**  
 Usado para associar o windows para seus objetos. Usado internamente pelo ATL.  
  
 **m_rgWindowClassAtoms**  
 Usado para controlar os registros de classe de janela para que eles possam ser corretamente seu registro cancelados no encerramento. Usado internamente pelo ATL.  
  
## <a name="remarks"></a>Comentários  
 [_ATL_WIN_MODULE](atl-typedefs.md#_atl_win_module) é definido como um typedef de `_ATL_WIN_MODULE70`.  
  
## <a name="requirements"></a>Requisitos  
 **Cabeçalho:** atlbase  
  
## <a name="see-also"></a>Consulte também  
 [Estruturas](../../atl/reference/atl-structures.md)






