---
title: Macros de status do objeto
ms.date: 11/04/2016
f1_keywords:
- atlcom/ATL::DECLARE_OLEMISC_STATUS
ms.assetid: 727dbef2-a342-4157-9d64-a421805d9747
ms.openlocfilehash: d9e2223739dc3d0636337e2e2f713c80dff50131
ms.sourcegitcommit: ec6dd97ef3d10b44e0fedaa8e53f41696f49ac7b
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 08/25/2020
ms.locfileid: "88835227"
---
# <a name="object-status-macros"></a>Macros de status do objeto

Essa macro define sinalizadores que pertencem a controles ActiveX.

|Nome|Descrição|
|-|-|
|[DECLARE_OLEMISC_STATUS](#declare_olemisc_status)|Usado em controles ActiveX do ATL para definir os sinalizadores OLEMISC.|

## <a name="requirements"></a>Requisitos

**Cabeçalho:** atlcom. h

## <a name="declare_olemisc_status"></a><a name="declare_olemisc_status"></a> DECLARE_OLEMISC_STATUS

Usado em controles ActiveX do ATL para definir os sinalizadores OLEMISC.

```
DECLARE_OLEMISC_STATUS( miscstatus )
```

### <a name="parameters"></a>parâmetros

*miscstatus*<br/>
Todos os sinalizadores OLEMISC aplicáveis.

### <a name="remarks"></a>Comentários

Essa macro é usada para definir os sinalizadores OLEMISC para um controle ActiveX. Consulte [IOleObject:: GetMiscStatus](/windows/win32/api/oleidl/nf-oleidl-ioleobject-getmiscstatus) para obter mais detalhes.

### <a name="example"></a>Exemplo

[!code-cpp[NVC_ATL_Windowing#124](../../atl/codesnippet/cpp/object-status-macros_1.h)]

## <a name="see-also"></a>Confira também

[Macros](../../atl/reference/atl-macros.md)
