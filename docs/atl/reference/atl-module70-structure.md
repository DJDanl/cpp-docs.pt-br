---
title: Estrutura _ATL_MODULE70 | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-atl
ms.topic: reference
f1_keywords:
- _ATL_MODULE70
- ATL::_ATL_MODULE70
- ATL._ATL_MODULE70
dev_langs:
- C++
helpviewer_keywords:
- ATL_MODULE70 structure
- _ATL_MODULE70 structure
ms.assetid: b059b2c8-dfd1-4ac9-b07d-39df638cc7b3
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
ms.openlocfilehash: e7afe6867f359b334654f58aad39ad7f143dd428
ms.sourcegitcommit: 92dbc4b9bf82fda96da80846c9cfcdba524035af
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/05/2018
ms.locfileid: "43764885"
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

`cbSize`  
O tamanho da estrutura, usado para controle de versão.

`m_nLockCnt`  
Contagem de referência para determinar quanto tempo o módulo deve permanecer ativo.

`m_pTermFuncs`  
Funções de faixas que foram registradas para ser chamado quando o ATL é desligado.

`m_csStaticDataInitAndTypeInfo`  
Usado para coordenar o acesso aos dados internos em situações de vários threads.

## <a name="remarks"></a>Comentários

[_ATL_MODULE](atl-typedefs.md#_atl_module) é definido como um typedef de `_ATL_MODULE70`.

## <a name="requirements"></a>Requisitos

**Cabeçalho:** atlbase. h

## <a name="see-also"></a>Consulte também

[Classes e structs](../../atl/reference/atl-classes.md)

