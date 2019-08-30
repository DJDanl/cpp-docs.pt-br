---
title: Classe CD2DPointU
ms.date: 08/29/2019
f1_keywords:
- CD2DPointU
- AFXRENDERTARGET/CD2DPointU
- AFXRENDERTARGET/CD2DPointU::CD2DPointU
helpviewer_keywords:
- CD2DPointU [MFC], CD2DPointU
ms.assetid: 04733f96-b6de-4a89-82e3-caad1e8087a9
ms.openlocfilehash: 6289d33aa0672d1ee423d91b11527dccfc868da7
ms.sourcegitcommit: e10a5feea193c249ddc5a6faba48e7c6d8784e73
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 08/30/2019
ms.locfileid: "70177167"
---
# <a name="cd2dpointu-class"></a>Classe CD2DPointU

Um wrapper para `D2D1_POINT_2U`.

## <a name="syntax"></a>Sintaxe

```
class CD2DPointU : public D2D1_POINT_2U;
```

## <a name="members"></a>Membros

### <a name="public-constructors"></a>Construtores públicos

|Nome|Descrição|
|----------|-----------------|
|[CD2DPointU::CD2DPointU](#cd2dpointu)|Sobrecarregado. Constrói um `CD2DPointU` objeto from Object `D2D1_POINT_2U` .|

### <a name="public-operators"></a>Operadores públicos

|Nome|Descrição|
|----------|-----------------|
|[Operador CD2DPointU:: Operator CPoint](#operator_cpoint)|Converte `CD2DPointU` para`CPoint` objeto.|

## <a name="inheritance-hierarchy"></a>Hierarquia de herança

`D2D1_POINT_2U`

`CD2DPointU`

## <a name="requirements"></a>Requisitos

**Cabeçalho:** afxrendertarget. h

##  <a name="cd2dpointu"></a>  CD2DPointU::CD2DPointU

Constrói um objeto CD2DPointU do objeto CPoint.

```
CD2DPointU(const CPoint& pt);
CD2DPointU(const D2D1_POINT_2U& pt);
CD2DPointU(const D2D1_POINT_2U* pt);
CD2DPointU(UINT32 uX = 0, UINT32 uY = 0);
```

### <a name="parameters"></a>Parâmetros

*pt*<br/>
ponto de origem

*uX*<br/>
origem X

*uY*<br/>
origem Y

##  <a name="operator_cpoint"></a>Operador CD2DPointU:: Operator CPoint

Converte CD2DPointU em objeto CPoint.

```
operator CPoint();
```

### <a name="return-value"></a>Valor de retorno

Valor atual do ponto de D2D.

## <a name="see-also"></a>Consulte também

[Classes](../../mfc/reference/mfc-classes.md)
