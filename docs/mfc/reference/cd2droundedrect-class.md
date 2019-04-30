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
ms.openlocfilehash: 51913a0d261a0bc91aef8f8504547a10c3e1cf36
ms.sourcegitcommit: 0ab61bc3d2b6cfbd52a16c6ab2b97a8ea1864f12
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/23/2019
ms.locfileid: "62396256"
---
# <a name="cd2droundedrect-class"></a>Classe CD2DRoundedRect

Um wrapper para `D2D1_ROUNDED_RECT`.

## <a name="syntax"></a>Sintaxe

```
class CD2DRoundedRect : public D2D1_ROUNDED_RECT;
```

## <a name="members"></a>Membros

### <a name="public-constructors"></a>Construtores públicos

|Nome|Descrição|
|----------|-----------------|
|[CD2DRoundedRect::CD2DRoundedRect](#cd2droundedrect)|Sobrecarregado. Constrói uma `CD2DRoundedRect` do objeto de `D2D1_ROUNDED_RECT` objeto.|

## <a name="inheritance-hierarchy"></a>Hierarquia de herança

`D2D1_ROUNDED_RECT`

[CD2DRoundedRect](../../mfc/reference/cd2droundedrect-class.md)

## <a name="requirements"></a>Requisitos

**Cabeçalho:** afxrendertarget.h

##  <a name="cd2droundedrect"></a>  CD2DRoundedRect::CD2DRoundedRect

Constrói um objeto CD2DRoundedRect CD2DRectF objeto.

```
CD2DRoundedRect(
    const CD2DRectF& rectIn,
    const CD2DSizeF& sizeRadius);

CD2DRoundedRect(const D2D1_ROUNDED_RECT& rectIn);
CD2DRoundedRect(const D2D1_ROUNDED_RECT* rectIn);
```

### <a name="parameters"></a>Parâmetros

*rectIn*<br/>
retângulo de origem

*sizeRadius*<br/>
tamanho do raio

## <a name="see-also"></a>Consulte também

[Classes](../../mfc/reference/mfc-classes.md)
