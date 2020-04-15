---
title: Classe CD2DRoundedRect
ms.date: 11/04/2016
f1_keywords:
- CD2DRoundedRect
- AFXRENDERTARGET/CD2DRoundedRect
- AFXRENDERTARGET/CD2DRoundedRect::CD2DRoundedRect
helpviewer_keywords:
- CD2DRoundedRect [MFC], CD2DRoundedRect
ms.assetid: 06207fb5-e92b-41c0-bceb-b45d8f466531
ms.openlocfilehash: 5189f3d824c008845570eac6eead4a35be1e483d
ms.sourcegitcommit: c123cc76bb2b6c5cde6f4c425ece420ac733bf70
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/14/2020
ms.locfileid: "81369081"
---
# <a name="cd2droundedrect-class"></a>Classe CD2DRoundedRect

Um invólucro para. `D2D1_ROUNDED_RECT`

## <a name="syntax"></a>Sintaxe

```
class CD2DRoundedRect : public D2D1_ROUNDED_RECT;
```

## <a name="members"></a>Membros

### <a name="public-constructors"></a>Construtores públicos

|Nome|Descrição|
|----------|-----------------|
|[CD2DRoundedRect::CD2DRoundedRect](#cd2droundedrect)|Sobrecarregado. Constrói um `CD2DRoundedRect` objeto `D2D1_ROUNDED_RECT` a partir do objeto.|

## <a name="inheritance-hierarchy"></a>Hierarquia de herança

`D2D1_ROUNDED_RECT`

[CD2DRoundedRect](../../mfc/reference/cd2droundedrect-class.md)

## <a name="requirements"></a>Requisitos

**Cabeçalho:** afxrendertarget.h

## <a name="cd2droundedrectcd2droundedrect"></a><a name="cd2droundedrect"></a>CD2DRoundedRect::CD2DRoundedRect

Constrói um objeto CD2DRoundedRect a partir do objeto CD2DRectF.

```
CD2DRoundedRect(
    const CD2DRectF& rectIn,
    const CD2DSizeF& sizeRadius);

CD2DRoundedRect(const D2D1_ROUNDED_RECT& rectIn);
CD2DRoundedRect(const D2D1_ROUNDED_RECT* rectIn);
```

### <a name="parameters"></a>Parâmetros

*retina*<br/>
retângulo fonte

*sizeRadius*<br/>
tamanho do raio

## <a name="see-also"></a>Confira também

[Classes](../../mfc/reference/mfc-classes.md)
