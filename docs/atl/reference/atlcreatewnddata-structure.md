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
ms.openlocfilehash: 6453156a59b73bcb06c7c86920e1dc524874cef8
ms.sourcegitcommit: 2bc15c5b36372ab01fa21e9bcf718fa22705814f
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/27/2020
ms.locfileid: "82168534"
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
O **ponteiro usado** para obter acesso à instância de classe em procedimentos de janela.

`m_dwThreadID`<br/>
A ID de thread da instância de classe atual.

`m_pNext`<br/>
Ponteiro para o próximo `_AtlCreateWndData` objeto.

## <a name="requirements"></a>Requisitos

**Cabeçalho:** atlbase. h

## <a name="see-also"></a>Confira também

[Classes e structs](../../atl/reference/atl-classes.md)
