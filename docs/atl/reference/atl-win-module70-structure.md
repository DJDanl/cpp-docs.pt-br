---
title: Estrutura _ATL_WIN_MODULE70 | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-atl
ms.topic: reference
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
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
ms.openlocfilehash: e330beda4770f60d5358ed8baf8d3b2fae260d3a
ms.sourcegitcommit: 7d68f8303e021e27dc8f4d36e764ed836e93d24f
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 07/06/2018
ms.locfileid: "37883028"
---
# <a name="atlwinmodule70-structure"></a>Estrutura _ATL_WIN_MODULE70
Usado pelo código de janelas na ATL.  
  
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
  
 `m_pCreateWndList`  
 Usado para ligar o windows para seus objetos. Usado internamente pelo ATL.  
  
 `m_rgWindowClassAtoms`  
 Usado para acompanhar os registros de classe de janela para que eles possam ser cancelados corretamente no encerramento. Usado internamente pelo ATL.  
  
## <a name="remarks"></a>Comentários  
 [_ATL_WIN_MODULE](atl-typedefs.md#_atl_win_module) é definido como um typedef de `_ATL_WIN_MODULE70`.  
  
## <a name="requirements"></a>Requisitos  
 **Cabeçalho:** atlbase. h  
  
## <a name="see-also"></a>Consulte também  
 [Classes e structs](../../atl/reference/atl-classes.md)





