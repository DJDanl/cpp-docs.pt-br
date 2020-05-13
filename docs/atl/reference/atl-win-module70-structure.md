---
title: Estrutura de _ATL_WIN_MODULE70
ms.date: 11/04/2016
f1_keywords:
- _ATL_WIN_MODULE70
- ATL::_ATL_WIN_MODULE70
- ATL._ATL_WIN_MODULE70
helpviewer_keywords:
- _ATL_WIN_MODULE70 structure
- ATL_WIN_MODULE70 structure
ms.assetid: a0aaf3ea-ca77-46ec-bd53-4dfb61dffbea
ms.openlocfilehash: 770e78e4ad87338528aa654f5ecaa08b45315846
ms.sourcegitcommit: 2bc15c5b36372ab01fa21e9bcf718fa22705814f
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/27/2020
ms.locfileid: "82168547"
---
# <a name="_atl_win_module70-structure"></a>Estrutura de _ATL_WIN_MODULE70

Usado pelo código de janela na ATL.

## <a name="syntax"></a>Sintaxe

```cpp
struct _ATL_WIN_MODULE70 {
    UNIT cbSize;
    CRITICAL_SECTION m_csWindowCreate;
    _AtlCreateWndData* m_pCreateWndList;
    CSimpleArray<ATOM> m_rgWindowClassAtoms;
};
```

## <a name="members"></a>Membros

`cbSize`<br/>
O tamanho da estrutura, usado para controle de versão.

`m_csWindowCreate`<br/>
Usado para serializar o acesso ao código de registro do Windows. Usado internamente pela ATL.

`m_pCreateWndList`<br/>
Usado para associar o Windows a seus objetos. Usado internamente pela ATL.

`m_rgWindowClassAtoms`<br/>
Usado para rastrear registros de classe de janela para que eles possam ter o registro correto cancelado no encerramento. Usado internamente pela ATL.

## <a name="remarks"></a>Comentários

[_ATL_WIN_MODULE](atl-typedefs.md#_atl_win_module) é definido como um typedef de `_ATL_WIN_MODULE70`.

## <a name="requirements"></a>Requisitos

**Cabeçalho:** atlbase. h

## <a name="see-also"></a>Confira também

[Classes e structs](../../atl/reference/atl-classes.md)
