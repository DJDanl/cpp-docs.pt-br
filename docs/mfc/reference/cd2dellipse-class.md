---
title: Classe CD2DEllipse
ms.date: 11/04/2016
f1_keywords:
- CD2DEllipse
- AFXRENDERTARGET/CD2DEllipse
- AFXRENDERTARGET/CD2DEllipse::CD2DEllipse
helpviewer_keywords:
- CD2DEllipse [MFC], CD2DEllipse
ms.assetid: e9f02f54-acf2-427e-b349-db50cd9a77df
ms.openlocfilehash: aa280215aaac55e3aaa9542ca1ab2bd9d21655e8
ms.sourcegitcommit: 6052185696adca270bc9bdbec45a626dd89cdcdd
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/31/2018
ms.locfileid: "50642029"
---
# <a name="cd2dellipse-class"></a>Classe CD2DEllipse

Um wrapper para `D2D1_ELLIPSE`.

## <a name="syntax"></a>Sintaxe

```
class CD2DEllipse : public D2D1_ELLIPSE;
```

## <a name="members"></a>Membros

### <a name="public-constructors"></a>Construtores Públicos

|Nome|Descrição|
|----------|-----------------|
|[CD2DEllipse::CD2DEllipse](#cd2dellipse)|Sobrecarregado. Constrói uma `CD2DEllipse` do objeto de `D2D1_ELLIPSE` objeto.|

## <a name="inheritance-hierarchy"></a>Hierarquia de herança

`D2D1_ELLIPSE`

`CD2DEllipse`

## <a name="requirements"></a>Requisitos

**Cabeçalho:** afxrendertarget.h

##  <a name="cd2dellipse"></a>  CD2DEllipse::CD2DEllipse

Constrói um objeto CD2DEllipse CD2DRectF objeto.

```
CD2DEllipse(const CD2DRectF& rect);
CD2DEllipse(const D2D1_ELLIPSE& ellipse);
  CD2DEllipse(const D2D1_ELLIPSE* ellipse);

CD2DEllipse(
    const CD2DPointF& ptCenter,
    const CD2DSizeF& sizeRadius);
```

### <a name="parameters"></a>Parâmetros

*Rect*<br/>
retângulo de origem

*elipse*<br/>
elipse de origem

*ptCenter*<br/>
O ponto central da elipse.

*sizeRadius*<br/>
O raio X e o raio Y da elipse.

## <a name="see-also"></a>Consulte também

[Classes](../../mfc/reference/mfc-classes.md)
