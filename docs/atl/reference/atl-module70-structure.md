---
title: Estrutura _ATL_MODULE70
ms.date: 11/04/2016
f1_keywords:
- _ATL_MODULE70
- ATL::_ATL_MODULE70
- ATL._ATL_MODULE70
helpviewer_keywords:
- ATL_MODULE70 structure
- _ATL_MODULE70 structure
ms.assetid: b059b2c8-dfd1-4ac9-b07d-39df638cc7b3
ms.openlocfilehash: d05683383fab64f027f198d49bfbf42aa593d582
ms.sourcegitcommit: c3093251193944840e3d0a068ecc30e6449624ba
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 03/04/2019
ms.locfileid: "57263423"
---
# <a name="atlmodule70-structure"></a>Estrutura _ATL_MODULE70

Contém dados usados por cada módulo do ATL.

## <a name="syntax"></a>Sintaxe

```
struct _ATL_MODULE70 {
    UINT cbSize;
    LONG m_nLockCnt;
    _ATL_TERMFUNC_ELEM* m_pTermFuncs;
    CComCriticalSection m_csStaticDataInitAndTypeInfo;
};
```

## <a name="members"></a>Membros

`cbSize`<br/>
O tamanho da estrutura, usado para controle de versão.

`m_nLockCnt`<br/>
Contagem de referência para determinar quanto tempo o módulo deve permanecer ativo.

`m_pTermFuncs`<br/>
Funções de faixas que foram registradas para ser chamado quando o ATL é desligado.

`m_csStaticDataInitAndTypeInfo`<br/>
Usado para coordenar o acesso aos dados internos em situações de vários threads.

## <a name="remarks"></a>Comentários

[_ATL_MODULE](atl-typedefs.md#_atl_module) é definido como um typedef de `_ATL_MODULE70`.

## <a name="requirements"></a>Requisitos

**Cabeçalho:** atlbase. h

## <a name="see-also"></a>Consulte também

[Classes e structs](../../atl/reference/atl-classes.md)
