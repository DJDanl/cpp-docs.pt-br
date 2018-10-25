---
title: Classe CD2DEllipse | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-mfc
ms.topic: reference
f1_keywords:
- CD2DEllipse
- AFXRENDERTARGET/CD2DEllipse
- AFXRENDERTARGET/CD2DEllipse::CD2DEllipse
dev_langs:
- C++
helpviewer_keywords:
- CD2DEllipse [MFC], CD2DEllipse
ms.assetid: e9f02f54-acf2-427e-b349-db50cd9a77df
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
ms.openlocfilehash: 93fc2b788d450b591ebd20be49f25133c95f22b6
ms.sourcegitcommit: a9dcbcc85b4c28eed280d8e451c494a00d8c4c25
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/25/2018
ms.locfileid: "50052835"
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
