---
title: Classe CD2DPointU
ms.date: 11/04/2016
f1_keywords:
- CD2DPointU
- AFXRENDERTARGET/CD2DPointU
- AFXRENDERTARGET/CD2DPointU::CD2DPointU
helpviewer_keywords:
- CD2DPointU [MFC], CD2DPointU
ms.assetid: 04733f96-b6de-4a89-82e3-caad1e8087a9
ms.openlocfilehash: 138916efe781d8bef69a1c4eb61a73c5a405be67
ms.sourcegitcommit: 6052185696adca270bc9bdbec45a626dd89cdcdd
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/31/2018
ms.locfileid: "50551847"
---
# <a name="cd2dpointu-class"></a>Classe CD2DPointU

Um wrapper para `D2D1_POINT_2U`.

## <a name="syntax"></a>Sintaxe

```
class CD2DPointU : public D2D1_POINT_2U;
```

## <a name="members"></a>Membros

### <a name="public-constructors"></a>Construtores Públicos

|Nome|Descrição|
|----------|-----------------|
|[CD2DPointU::CD2DPointU](#cd2dpointu)|Sobrecarregado. Constrói uma `CD2DPointU` do objeto `D2D1_POINT_2U` objeto.|

### <a name="public-operators"></a>Operadores públicos

|Nome|Descrição|
|----------|-----------------|
|[CD2DPointU::Operator CPoint](#operator_cpoint)|Converte `CD2DPointU` para `CPoint` objeto.|

## <a name="inheritance-hierarchy"></a>Hierarquia de herança

`D2D1_POINT_2U`

`CD2DPointU`

## <a name="requirements"></a>Requisitos

**Cabeçalho:** afxrendertarget.h

##  <a name="cd2dpointu"></a>  CD2DPointU::CD2DPointU

Constrói um objeto CD2DPointU CPoint objeto.

```
CD2DPointU(const CPoint& pt);
CD2DPointU(const D2D1_POINT_2U& pt);
  CD2DPointU(const D2D1_POINT_2U* pt);
CD2DPointU(UINT32 uX = 0, UINT32 uY = 0);
```

### <a name="parameters"></a>Parâmetros

*pt*<br/>
ponto de origem

*experiência do usuário*<br/>
origem X

*uY*<br/>
origem Y

##  <a name="operator_cpoint"></a>  CD2DPointU::Operator CPoint

Converte CD2DPointU CPoint objeto.

```
operator CPoint();
```

### <a name="return-value"></a>Valor de retorno

Valor atual do ponto de D2D.

## <a name="see-also"></a>Consulte também

[Classes](../../mfc/reference/mfc-classes.md)
