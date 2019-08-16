---
title: Macros de status do objeto
ms.date: 11/04/2016
f1_keywords:
- atlcom/ATL::DECLARE_OLEMISC_STATUS
ms.assetid: 727dbef2-a342-4157-9d64-a421805d9747
ms.openlocfilehash: dc50825d6b6e74dc263a097e86d8ea0d42989825
ms.sourcegitcommit: fcb48824f9ca24b1f8bd37d647a4d592de1cc925
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 08/15/2019
ms.locfileid: "69495316"
---
# <a name="object-status-macros"></a>Macros de status do objeto

Essa macro define sinalizadores que pertencem a controles ActiveX.

|||
|-|-|
|[DECLARE_OLEMISC_STATUS](#declare_olemisc_status)|Usado em controles ActiveX do ATL para definir os sinalizadores OLEMISC.|

## <a name="requirements"></a>Requisitos

**Cabeçalho:** atlcom. h

##  <a name="declare_olemisc_status"></a>  DECLARE_OLEMISC_STATUS

Usado em controles ActiveX do ATL para definir os sinalizadores OLEMISC.

```
DECLARE_OLEMISC_STATUS( miscstatus )
```

### <a name="parameters"></a>Parâmetros

*miscstatus*<br/>
Todos os sinalizadores OLEMISC aplicáveis.

### <a name="remarks"></a>Comentários

Essa macro é usada para definir os sinalizadores OLEMISC para um controle ActiveX. Consulte [IOleObject:: GetMiscStatus](/windows/win32/api/oleidl/nf-oleidl-ioleobject-getmiscstatus) para obter mais detalhes.

### <a name="example"></a>Exemplo

[!code-cpp[NVC_ATL_Windowing#124](../../atl/codesnippet/cpp/object-status-macros_1.h)]

## <a name="see-also"></a>Consulte também

[Macros](../../atl/reference/atl-macros.md)
