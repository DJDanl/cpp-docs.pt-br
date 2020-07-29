---
title: Estrutura de _AtlCreateWndData
ms.date: 11/04/2016
f1_keywords:
- ATL::_AtlCreateWndData
- ATL._AtlCreateWndData
- _AtlCreateWndData
helpviewer_keywords:
- _AtlCreateWndData structure
- AtlCreateWndData structure
ms.assetid: 76ed5382-bfbf-4b8b-8a29-912688dfd2ae
ms.openlocfilehash: a38ddb7e3575e883c11b14a9b01004bb54fcd4a4
ms.sourcegitcommit: 1f009ab0f2cc4a177f2d1353d5a38f164612bdb1
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 07/27/2020
ms.locfileid: "87230007"
---
# <a name="_atlcreatewnddata-structure"></a>Estrutura de _AtlCreateWndData

Essa estrutura contém dados de instância de classe em código de janelas na ATL.

## <a name="syntax"></a>Sintaxe

```cpp
    struct _AtlCreateWndData{
    void* m_pThis;
    DWORD m_dwThreadID;
    _AtlCreateWndData* m_pNext;
};
```

## <a name="members"></a>Membros

`m_pThis`<br/>
O **`this`** ponteiro usado para obter acesso à instância de classe em procedimentos de janela.

`m_dwThreadID`<br/>
A ID de thread da instância de classe atual.

`m_pNext`<br/>
Ponteiro para o próximo `_AtlCreateWndData` objeto.

## <a name="requirements"></a>Requisitos

**Cabeçalho:** atlbase. h

## <a name="see-also"></a>Confira também

[Classes e structs](../../atl/reference/atl-classes.md)
