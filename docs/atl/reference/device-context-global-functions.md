---
title: Funções globais do contexto do dispositivo
ms.date: 11/04/2016
f1_keywords:
- atlwin/ATL::AtlCreateTargetDC
ms.assetid: 08ec28f6-daff-4882-9544-e8a4639d05c4
ms.openlocfilehash: e640f310a1976c29a39f0ab7c2575dfd1073c889
ms.sourcegitcommit: c123cc76bb2b6c5cde6f4c425ece420ac733bf70
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/14/2020
ms.locfileid: "81330149"
---
# <a name="device-context-global-functions"></a>Funções globais do contexto do dispositivo

Esta função cria um contexto de dispositivo para um determinado dispositivo.

|||
|-|-|
|[AtlCreateTargetDC](#atlcreatetargetdc)|Cria um contexto de dispositivo.|

## <a name="atlcreatetargetdc"></a><a name="atlcreatetargetdc"></a>AtlCreateTargetDC

Cria um contexto de dispositivo para o dispositivo especificado na estrutura [DVTARGETDEVICE.](/windows/win32/api/objidl/ns-objidl-dvtargetdevice)

```
HDC AtlCreateTargetDC(HDC hdc, DVTARGETDEVICE* ptd);
```

### <a name="parameters"></a>Parâmetros

*Hdc*<br/>
[em] A alça existente de um contexto de dispositivo, ou NULL.

*Ptd*<br/>
[em] Um ponteiro `DVTARGETDEVICE` para a estrutura que contém informações sobre o dispositivo de destino.

### <a name="return-value"></a>Valor retornado

Retorna a alça a um contexto do `DVTARGETDEVICE`dispositivo para o dispositivo especificado no . Se nenhum dispositivo for especificado, a alça retorna a alça ao dispositivo de exibição padrão.

### <a name="remarks"></a>Comentários

Se a estrutura for NULL e *hdc* for NULL, criará um contexto de dispositivo para o dispositivo de exibição padrão.

Se *hdc* não for NULL e *ptd* for NULL, a função retorna o *hdc*existente .

## <a name="requirements"></a>Requisitos

**Cabeçalho:** atlwin.h

## <a name="see-also"></a>Confira também

[Funções](../../atl/reference/atl-functions.md)
