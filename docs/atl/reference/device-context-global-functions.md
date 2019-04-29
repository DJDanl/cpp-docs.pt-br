---
title: Funções globais de contexto de dispositivo
ms.date: 11/04/2016
f1_keywords:
- atlwin/ATL::AtlCreateTargetDC
ms.assetid: 08ec28f6-daff-4882-9544-e8a4639d05c4
ms.openlocfilehash: aeebec65def9364e56156f6bb323815da012e11f
ms.sourcegitcommit: 0ab61bc3d2b6cfbd52a16c6ab2b97a8ea1864f12
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/23/2019
ms.locfileid: "62276556"
---
# <a name="device-context-global-functions"></a>Funções globais de contexto de dispositivo

Essa função cria um contexto de dispositivo para um determinado dispositivo.

|||
|-|-|
|[AtlCreateTargetDC](#atlcreatetargetdc)|Cria um contexto de dispositivo.|

##  <a name="atlcreatetargetdc"></a>  AtlCreateTargetDC

Cria um contexto de dispositivo para o dispositivo especificado na [DVTARGETDEVICE](/windows/desktop/api/objidl/ns-objidl-tagdvtargetdevice) estrutura.

```
HDC AtlCreateTargetDC(HDC hdc, DVTARGETDEVICE* ptd);
```

### <a name="parameters"></a>Parâmetros

*hdc*<br/>
[in] O identificador existente de um contexto de dispositivo ou NULL.

*ptd*<br/>
[in] Um ponteiro para o `DVTARGETDEVICE` estrutura que contém informações sobre o dispositivo de destino.

### <a name="return-value"></a>Valor de retorno

Retorna o identificador para um contexto de dispositivo para o dispositivo especificado no `DVTARGETDEVICE`. Se nenhum dispositivo for especificado, retorna o identificador para o dispositivo de exibição padrão.

### <a name="remarks"></a>Comentários

Se a estrutura for NULL e *hdc* for NULL, cria um contexto de dispositivo para o dispositivo de exibição padrão.

Se *hdc* não for nulo e *ptd* for NULL, a função retorna existente *hdc*.

## <a name="requirements"></a>Requisitos

**Cabeçalho:** atlwin

## <a name="see-also"></a>Consulte também

[Funções](../../atl/reference/atl-functions.md)
