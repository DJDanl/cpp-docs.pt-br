---
title: Funções globais de contexto de dispositivo
ms.date: 11/04/2016
f1_keywords:
- atlwin/ATL::AtlCreateTargetDC
ms.assetid: 08ec28f6-daff-4882-9544-e8a4639d05c4
ms.openlocfilehash: d225bd0cd996fd908479b5a93aad81ea0428900b
ms.sourcegitcommit: fcb48824f9ca24b1f8bd37d647a4d592de1cc925
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 08/15/2019
ms.locfileid: "69496094"
---
# <a name="device-context-global-functions"></a>Funções globais de contexto de dispositivo

Essa função cria um contexto de dispositivo para um determinado dispositivo.

|||
|-|-|
|[AtlCreateTargetDC](#atlcreatetargetdc)|Cria um contexto de dispositivo.|

##  <a name="atlcreatetargetdc"></a>  AtlCreateTargetDC

Cria um contexto de dispositivo para o dispositivo especificado na estrutura [DVTARGETDEVICE](/windows/win32/api/objidl/ns-objidl-dvtargetdevice) .

```
HDC AtlCreateTargetDC(HDC hdc, DVTARGETDEVICE* ptd);
```

### <a name="parameters"></a>Parâmetros

*hdc*<br/>
no O identificador existente de um contexto de dispositivo ou nulo.

*ptd*<br/>
no Um ponteiro para a `DVTARGETDEVICE` estrutura que contém informações sobre o dispositivo de destino.

### <a name="return-value"></a>Valor de retorno

Retorna o identificador para um contexto de dispositivo para o dispositivo especificado no `DVTARGETDEVICE`. Se nenhum dispositivo for especificado, o retornará o identificador para o dispositivo de vídeo padrão.

### <a name="remarks"></a>Comentários

Se a estrutura for nula e *HDC* for NULL, o criará um contexto de dispositivo para o dispositivo de vídeo padrão.

Se *HDC* não for NULL e *ptd* for NULL, a função retornará o *HDC*existente.

## <a name="requirements"></a>Requisitos

**Cabeçalho:** atlwin. h

## <a name="see-also"></a>Consulte também

[Funções](../../atl/reference/atl-functions.md)
