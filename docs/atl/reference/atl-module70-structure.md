---
title: Estrutura de _ATL_MODULE70
ms.date: 11/04/2016
f1_keywords:
- _ATL_MODULE70
- ATL::_ATL_MODULE70
- ATL._ATL_MODULE70
helpviewer_keywords:
- ATL_MODULE70 structure
- _ATL_MODULE70 structure
ms.assetid: b059b2c8-dfd1-4ac9-b07d-39df638cc7b3
ms.openlocfilehash: 8d39cdd281e09cdfe09546627aa630a11d12464e
ms.sourcegitcommit: 2bc15c5b36372ab01fa21e9bcf718fa22705814f
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/27/2020
ms.locfileid: "82168560"
---
# <a name="_atl_module70-structure"></a>Estrutura de _ATL_MODULE70

Contém dados usados por cada módulo ATL.

## <a name="syntax"></a>Sintaxe

```cpp
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
Contagem de referência para determinar por quanto tempo o módulo deve permanecer ativo.

`m_pTermFuncs`<br/>
Rastreia funções que foram registradas para serem chamadas quando a ATL é desligada.

`m_csStaticDataInitAndTypeInfo`<br/>
Usado para coordenar o acesso a dados internos em situações multi-threaded.

## <a name="remarks"></a>Comentários

[_ATL_MODULE](atl-typedefs.md#_atl_module) é definido como um typedef de `_ATL_MODULE70`.

## <a name="requirements"></a>Requisitos

**Cabeçalho:** atlbase. h

## <a name="see-also"></a>Confira também

[Classes e structs](../../atl/reference/atl-classes.md)
