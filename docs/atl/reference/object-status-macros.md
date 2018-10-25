---
title: Macros de Status do objeto | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-atl
ms.topic: reference
f1_keywords:
- atlcom/ATL::DECLARE_OLEMISC_STATUS
dev_langs:
- C++
ms.assetid: 727dbef2-a342-4157-9d64-a421805d9747
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
ms.openlocfilehash: c4b8be9cf1b421a66081fcf650462447d3c0ef7e
ms.sourcegitcommit: a9dcbcc85b4c28eed280d8e451c494a00d8c4c25
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/25/2018
ms.locfileid: "50052532"
---
# <a name="object-status-macros"></a>Macros de Status do objeto

Essa macro define sinalizadores que pertencem aos controles ActiveX.

|||
|-|-|
|[DECLARE_OLEMISC_STATUS](#declare_olemisc_status)|Usado em controles ActiveX ATL para definir os sinalizadores OLEMISC.|

## <a name="requirements"></a>Requisitos

**Cabeçalho:** atlcom

##  <a name="declare_olemisc_status"></a>  DECLARE_OLEMISC_STATUS

Usado em controles ActiveX ATL para definir os sinalizadores OLEMISC.

```
DECLARE_OLEMISC_STATUS( miscstatus )
```

### <a name="parameters"></a>Parâmetros

*miscstatus*<br/>
Sinalizadores OLEMISC tudo aplicáveis.

### <a name="remarks"></a>Comentários

Essa macro é usada para definir os sinalizadores OLEMISC para um controle ActiveX. Consulte a [IOleObject::GetMiscStatus](/windows/desktop/api/oleidl/nf-oleidl-ioleobject-getmiscstatus) para obter mais detalhes.

### <a name="example"></a>Exemplo

[!code-cpp[NVC_ATL_Windowing#124](../../atl/codesnippet/cpp/object-status-macros_1.h)]

## <a name="see-also"></a>Consulte também

[Macros](../../atl/reference/atl-macros.md)
