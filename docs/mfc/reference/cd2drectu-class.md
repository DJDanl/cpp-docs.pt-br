---
title: Classe CD2DRectU
ms.date: 11/04/2016
f1_keywords:
- CD2DRectU
- AFXRENDERTARGET/CD2DRectU
- AFXRENDERTARGET/CD2DRectU::CD2DRectU
- AFXRENDERTARGET/CD2DRectU::IsNull
helpviewer_keywords:
- CD2DRectU [MFC], CD2DRectU
- CD2DRectU [MFC], IsNull
ms.assetid: a62f17d1-011d-4867-8f51-fd7e7c00561d
ms.openlocfilehash: afcd328a8945853761fecfce8f3c14f73b2a96e2
ms.sourcegitcommit: 6052185696adca270bc9bdbec45a626dd89cdcdd
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/31/2018
ms.locfileid: "50514407"
---
# <a name="cd2drectu-class"></a>Classe CD2DRectU

Um wrapper para `D2D1_RECT_U`.

## <a name="syntax"></a>Sintaxe

```
class CD2DRectU : public D2D1_RECT_U;
```

## <a name="members"></a>Membros

### <a name="public-constructors"></a>Construtores Públicos

|Nome|Descrição|
|----------|-----------------|
|[CD2DRectU::CD2DRectU](#cd2drectu)|Sobrecarregado. Constrói uma `CD2DRectU` do objeto de `D2D1_RECT_U` objeto.|

### <a name="public-methods"></a>Métodos públicos

|Nome|Descrição|
|----------|-----------------|
|[CD2DRectU::IsNull](#isnull)|Retorna um **boolean** valor que indica se uma expressão não contém dados válidos (nulo).|

### <a name="public-operators"></a>Operadores públicos

|Nome|Descrição|
|----------|-----------------|
|[CD2DRectU::Operator CRect](#operator_crect)|Converte `CD2DRectU` para `CRect` objeto.|

## <a name="inheritance-hierarchy"></a>Hierarquia de herança

`D2D1_RECT_U`

`CD2DRectU`

## <a name="requirements"></a>Requisitos

**Cabeçalho:** afxrendertarget.h

##  <a name="cd2drectu"></a>  CD2DRectU::CD2DRectU

Constrói um objeto CD2DRectU objeto CRect.

```
CD2DRectU(const CRect& rect);
CD2DRectU(const D2D1_RECT_U& rect);
  CD2DRectU(const D2D1_RECT_U* rect);

CD2DRectU(
    UINT32 uLeft = 0,
    UINT32 uTop = 0,
    UINT32 uRight = 0,
    UINT32 uBottom = 0);
```

### <a name="parameters"></a>Parâmetros

*Rect*<br/>
retângulo de origem

*uLeft*<br/>
coordenada esquerda do código-fonte

*uTop*<br/>
coordenada superior do código-fonte

*uRight*<br/>
origem de coordenada direita

*uBottom*<br/>
coordenada inferior de origem

##  <a name="isnull"></a>  CD2DRectU::IsNull

Retorna um valor booliano que indica se uma expressão não contém dados válidos (nulo).

```
BOOL IsNull() const;
```

### <a name="return-value"></a>Valor de retorno

TRUE se a parte superior, esquerda, inferior e valores corretos do retângulo são todas iguais a 0; Caso contrário, FALSE.

##  <a name="operator_crect"></a>  CD2DRectU::Operator CRect

Converte CD2DRectU objeto CRect.

```
operator CRect();
```

### <a name="return-value"></a>Valor de retorno

Valor atual do retângulo D2D.

## <a name="see-also"></a>Consulte também

[Classes](../../mfc/reference/mfc-classes.md)
