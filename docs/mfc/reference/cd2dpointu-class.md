---
title: Classe CD2DpointU
ms.date: 08/29/2019
f1_keywords:
- CD2DPointU
- AFXRENDERTARGET/CD2DPointU
- AFXRENDERTARGET/CD2DPointU::CD2DPointU
helpviewer_keywords:
- CD2DPointU [MFC], CD2DPointU
ms.assetid: 04733f96-b6de-4a89-82e3-caad1e8087a9
ms.openlocfilehash: 8c6db55f1dde1fd054a1f75590f5969c097b2f90
ms.sourcegitcommit: c123cc76bb2b6c5cde6f4c425ece420ac733bf70
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/14/2020
ms.locfileid: "81369149"
---
# <a name="cd2dpointu-class"></a>Classe CD2DpointU

Um invólucro para. `D2D1_POINT_2U`

## <a name="syntax"></a>Sintaxe

```
class CD2DPointU : public D2D1_POINT_2U;
```

## <a name="members"></a>Membros

### <a name="public-constructors"></a>Construtores públicos

|Nome|Descrição|
|----------|-----------------|
|[CD2DpointU::Cd2DpointU](#cd2dpointu)|Sobrecarregado. Constrói um `CD2DPointU` objeto `D2D1_POINT_2U` a partir de objeto.|

### <a name="public-operators"></a>Operadores públicos

|Nome|Descrição|
|----------|-----------------|
|[CD2DPointU:operador CPoint](#operator_cpoint)|`CD2DPointU` Converte-se em `CPoint` objeto.|

## <a name="inheritance-hierarchy"></a>Hierarquia de herança

`D2D1_POINT_2U`

`CD2DPointU`

## <a name="requirements"></a>Requisitos

**Cabeçalho:** afxrendertarget.h

## <a name="cd2dpointucd2dpointu"></a><a name="cd2dpointu"></a>CD2DpointU::Cd2DpointU

Constrói um objeto CD2DPointU a partir do objeto CPoint.

```
CD2DPointU(const CPoint& pt);
CD2DPointU(const D2D1_POINT_2U& pt);
CD2DPointU(const D2D1_POINT_2U* pt);
CD2DPointU(UINT32 uX = 0, UINT32 uY = 0);
```

### <a name="parameters"></a>Parâmetros

*pt*<br/>
ponto de origem

*Ux*<br/>
fonte X

*Uy*<br/>
fonte Y

## <a name="cd2dpointuoperator-cpoint"></a><a name="operator_cpoint"></a>CD2DPointU:operador CPoint

Converte CD2DPointU para objeto CPoint.

```
operator CPoint();
```

### <a name="return-value"></a>Valor retornado

Valor atual do ponto D2D.

## <a name="see-also"></a>Confira também

[Classes](../../mfc/reference/mfc-classes.md)
