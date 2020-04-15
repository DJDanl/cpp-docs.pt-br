---
title: Classe CD2DPointF
ms.date: 11/04/2016
f1_keywords:
- CD2DPointF
- AFXRENDERTARGET/CD2DPointF
- AFXRENDERTARGET/CD2DPointF::CD2DPointF
helpviewer_keywords:
- CD2DPointF [MFC], CD2DPointF
ms.assetid: 30f72083-1c8a-4f50-adb2-72dbbe3522d4
ms.openlocfilehash: 5d66c31289f9e17df99df4681cff1d5cf6a0ec86
ms.sourcegitcommit: c123cc76bb2b6c5cde6f4c425ece420ac733bf70
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/14/2020
ms.locfileid: "81369155"
---
# <a name="cd2dpointf-class"></a>Classe CD2DPointF

Um invólucro para. `D2D1_POINT_2F`

## <a name="syntax"></a>Sintaxe

```
class CD2DPointF : public D2D1_POINT_2F;
```

## <a name="members"></a>Membros

### <a name="public-constructors"></a>Construtores públicos

|Nome|Descrição|
|----------|-----------------|
|[CD2DPointF::CD2DPointF](#cd2dpointf)|Sobrecarregado. Constrói um `CD2DPointF` objeto `D2D1_POINT_2F` a partir do objeto.|

### <a name="public-operators"></a>Operadores públicos

|Nome|Descrição|
|----------|-----------------|
|[CD2DPointF:operador CPoint](#operator_cpoint)|`CD2DPointF` Converte-se em `CPoint` objeto.|

## <a name="inheritance-hierarchy"></a>Hierarquia de herança

`D2D1_POINT_2F`

`CD2DPointF`

## <a name="requirements"></a>Requisitos

**Cabeçalho:** afxrendertarget.h

## <a name="cd2dpointfcd2dpointf"></a><a name="cd2dpointf"></a>CD2DPointF::CD2DPointF

Constrói um objeto CD2DPointF a partir do objeto CPoint.

```
CD2DPointF(const CPoint& pt);
CD2DPointF(const D2D1_POINT_2F& pt);
CD2DPointF(const D2D1_POINT_2F* pt);
CD2DPointF(FLOAT fX = 0., FLOAT fY = 0.);
```

### <a name="parameters"></a>Parâmetros

*pt*<br/>
ponto de origem

*Fx*<br/>
fonte X

*Fy*<br/>
fonte Y

## <a name="cd2dpointfoperator-cpoint"></a><a name="operator_cpoint"></a>CD2DPointF:operador CPoint

Converte cd2DPointF em objeto CPoint.

```
operator CPoint();
```

### <a name="return-value"></a>Valor retornado

Valor atual do ponto D2D.

## <a name="see-also"></a>Confira também

[Classes](../../mfc/reference/mfc-classes.md)
