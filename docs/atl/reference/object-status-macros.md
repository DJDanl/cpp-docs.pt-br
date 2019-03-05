---
title: Macros de Status do objeto
ms.date: 11/04/2016
f1_keywords:
- atlcom/ATL::DECLARE_OLEMISC_STATUS
ms.assetid: 727dbef2-a342-4157-9d64-a421805d9747
ms.openlocfilehash: cb5ff6d7570b03b32852fc450f58043446f721f4
ms.sourcegitcommit: c3093251193944840e3d0a068ecc30e6449624ba
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 03/04/2019
ms.locfileid: "57267258"
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
