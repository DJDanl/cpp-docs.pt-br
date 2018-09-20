---
title: Classe CD2DPointF | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-mfc
ms.topic: reference
f1_keywords:
- CD2DPointF
- AFXRENDERTARGET/CD2DPointF
- AFXRENDERTARGET/CD2DPointF::CD2DPointF
dev_langs:
- C++
helpviewer_keywords:
- CD2DPointF [MFC], CD2DPointF
ms.assetid: 30f72083-1c8a-4f50-adb2-72dbbe3522d4
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
ms.openlocfilehash: f36756579a07692f190e0ea919d6d82e3cb4128d
ms.sourcegitcommit: 799f9b976623a375203ad8b2ad5147bd6a2212f0
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/19/2018
ms.locfileid: "46439842"
---
# <a name="cd2dpointf-class"></a>Classe CD2DPointF

Um wrapper para `D2D1_POINT_2F`.

## <a name="syntax"></a>Sintaxe

```
class CD2DPointF : public D2D1_POINT_2F;
```

## <a name="members"></a>Membros

### <a name="public-constructors"></a>Construtores Públicos

|Nome|Descrição|
|----------|-----------------|
|[CD2DPointF::CD2DPointF](#cd2dpointf)|Sobrecarregado. Constrói uma `CD2DPointF` do objeto de `D2D1_POINT_2F` objeto.|

### <a name="public-operators"></a>Operadores públicos

|Nome|Descrição|
|----------|-----------------|
|[CD2DPointF::Operator CPoint](#operator_cpoint)|Converte `CD2DPointF` para `CPoint` objeto.|

## <a name="inheritance-hierarchy"></a>Hierarquia de herança

`D2D1_POINT_2F`

`CD2DPointF`

## <a name="requirements"></a>Requisitos

**Cabeçalho:** afxrendertarget.h

##  <a name="cd2dpointf"></a>  CD2DPointF::CD2DPointF

Constrói um objeto CD2DPointF CPoint objeto.

```
CD2DPointF(const CPoint& pt);
CD2DPointF(const D2D1_POINT_2F& pt);
CD2DPointF(const D2D1_POINT_2F* pt);
CD2DPointF(FLOAT fX = 0., FLOAT fY = 0.);
```

### <a name="parameters"></a>Parâmetros

*pt*<br/>
ponto de origem

*fX*<br/>
origem X

*ano fiscal*<br/>
origem Y

##  <a name="operator_cpoint"></a>  CD2DPointF::Operator CPoint

Converte CD2DPointF CPoint objeto.

```
operator CPoint();
```

### <a name="return-value"></a>Valor de retorno

Valor atual do ponto de D2D.

## <a name="see-also"></a>Consulte também

[Classes](../../mfc/reference/mfc-classes.md)
