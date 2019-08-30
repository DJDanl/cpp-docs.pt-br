---
title: Classe CD2DEllipse
ms.date: 08/29/2019
f1_keywords:
- CD2DEllipse
- AFXRENDERTARGET/CD2DEllipse
- AFXRENDERTARGET/CD2DEllipse::CD2DEllipse
helpviewer_keywords:
- CD2DEllipse [MFC], CD2DEllipse
ms.assetid: e9f02f54-acf2-427e-b349-db50cd9a77df
ms.openlocfilehash: 21087682d40dac521cc949a39ef4b1aab23e7d71
ms.sourcegitcommit: e10a5feea193c249ddc5a6faba48e7c6d8784e73
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 08/30/2019
ms.locfileid: "70177217"
---
# <a name="cd2dellipse-class"></a>Classe CD2DEllipse

Um wrapper para `D2D1_ELLIPSE`.

## <a name="syntax"></a>Sintaxe

```
class CD2DEllipse : public D2D1_ELLIPSE;
```

## <a name="members"></a>Membros

### <a name="public-constructors"></a>Construtores públicos

|Nome|Descrição|
|----------|-----------------|
|[CD2DEllipse::CD2DEllipse](#cd2dellipse)|Sobrecarregado. Constrói um `CD2DEllipse` objeto do `D2D1_ELLIPSE` objeto.|

## <a name="inheritance-hierarchy"></a>Hierarquia de herança

`D2D1_ELLIPSE`

`CD2DEllipse`

## <a name="requirements"></a>Requisitos

**Cabeçalho:** afxrendertarget. h

##  <a name="cd2dellipse"></a>CD2DEllipse::CD2DEllipse

Constrói um objeto CD2DEllipse do objeto CD2DRectF.

```
CD2DEllipse(const CD2DRectF& rect);
CD2DEllipse(const D2D1_ELLIPSE& ellipse);
CD2DEllipse(const D2D1_ELLIPSE* ellipse);

CD2DEllipse(
    const CD2DPointF& ptCenter,
    const CD2DSizeF& sizeRadius);
```

### <a name="parameters"></a>Parâmetros

*rect*<br/>
retângulo de origem

*elipse*<br/>
elipse de origem

*ptCenter*<br/>
O ponto central da elipse.

*sizeRadius*<br/>
O raio X e Y da elipse.

## <a name="see-also"></a>Consulte também

[Classes](../../mfc/reference/mfc-classes.md)
