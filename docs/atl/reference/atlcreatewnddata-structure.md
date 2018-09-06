---
title: Estrutura atlcreatewnddata | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-atl
ms.topic: reference
f1_keywords:
- ATL::_AtlCreateWndData
- ATL._AtlCreateWndData
- _AtlCreateWndData
dev_langs:
- C++
helpviewer_keywords:
- _AtlCreateWndData structure
- AtlCreateWndData structure
ms.assetid: 76ed5382-bfbf-4b8b-8a29-912688dfd2ae
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
ms.openlocfilehash: c5751fa3c5c8bc20f287ca3c48d885fc41c60ba0
ms.sourcegitcommit: 92dbc4b9bf82fda96da80846c9cfcdba524035af
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/05/2018
ms.locfileid: "43764323"
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

`m_pThis`  
O **isso** ponteiro usado para obter acesso à instância de classe em procedimentos de janela.

`m_dwThreadID`  
A ID do thread da instância da classe atual.

`m_pNext`  
Ponteiro para o próximo `_AtlCreateWndData` objeto.

## <a name="requirements"></a>Requisitos

**Cabeçalho:** atlbase. h

## <a name="see-also"></a>Consulte também

[Classes e structs](../../atl/reference/atl-classes.md)

