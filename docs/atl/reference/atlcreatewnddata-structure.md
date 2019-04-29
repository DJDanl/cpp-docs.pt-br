---
title: _AtlCreateWndData Structure
ms.date: 11/04/2016
f1_keywords:
- ATL::_AtlCreateWndData
- ATL._AtlCreateWndData
- _AtlCreateWndData
helpviewer_keywords:
- _AtlCreateWndData structure
- AtlCreateWndData structure
ms.assetid: 76ed5382-bfbf-4b8b-8a29-912688dfd2ae
ms.openlocfilehash: d6e3168b5c86de5bce3c3b9d3b0fbdea28ae604f
ms.sourcegitcommit: 0ab61bc3d2b6cfbd52a16c6ab2b97a8ea1864f12
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/23/2019
ms.locfileid: "62261229"
---
# <a name="atlcreatewnddata-structure"></a>_AtlCreateWndData Structure

Essa estrutura contém dados de instância de classe no código de janelas no ATL.

## <a name="syntax"></a>Sintaxe

```
    struct _AtlCreateWndData{
    void* m_pThis;
    DWORD m_dwThreadID;
    _AtlCreateWndData* m_pNext;
};
```

## <a name="members"></a>Membros

`m_pThis`<br/>
O **isso** ponteiro usado para obter acesso à instância de classe em procedimentos de janela.

`m_dwThreadID`<br/>
A ID do thread da instância da classe atual.

`m_pNext`<br/>
Ponteiro para o próximo `_AtlCreateWndData` objeto.

## <a name="requirements"></a>Requisitos

**Cabeçalho:** atlbase. h

## <a name="see-also"></a>Consulte também

[Classes e structs](../../atl/reference/atl-classes.md)
