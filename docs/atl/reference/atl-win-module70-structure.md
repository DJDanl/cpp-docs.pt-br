---
title: Estrutura _ATL_WIN_MODULE70
ms.date: 11/04/2016
f1_keywords:
- _ATL_WIN_MODULE70
- ATL::_ATL_WIN_MODULE70
- ATL._ATL_WIN_MODULE70
helpviewer_keywords:
- _ATL_WIN_MODULE70 structure
- ATL_WIN_MODULE70 structure
ms.assetid: a0aaf3ea-ca77-46ec-bd53-4dfb61dffbea
ms.openlocfilehash: 4f1718c76d21f2e13b36c29db785fe989ff6108e
ms.sourcegitcommit: 6052185696adca270bc9bdbec45a626dd89cdcdd
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/31/2018
ms.locfileid: "50482505"
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

`cbSize`<br/>
O tamanho da estrutura, usado para controle de versão.

`m_csWindowCreate`<br/>
Usado para serializar o acesso ao código de registro de janela. Usado internamente pelo ATL.

`m_pCreateWndList`<br/>
Usado para ligar o windows para seus objetos. Usado internamente pelo ATL.

`m_rgWindowClassAtoms`<br/>
Usado para acompanhar os registros de classe de janela para que eles possam ser cancelados corretamente no encerramento. Usado internamente pelo ATL.

## <a name="remarks"></a>Comentários

[_ATL_WIN_MODULE](atl-typedefs.md#_atl_win_module) é definido como um typedef de `_ATL_WIN_MODULE70`.

## <a name="requirements"></a>Requisitos

**Cabeçalho:** atlbase. h

## <a name="see-also"></a>Consulte também

[Classes e structs](../../atl/reference/atl-classes.md)

