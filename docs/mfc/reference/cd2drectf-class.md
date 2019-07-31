---
title: Classe CD2DRectF
ms.date: 11/04/2016
f1_keywords:
- CD2DRectF
- AFXRENDERTARGET/CD2DRectF
- AFXRENDERTARGET/CD2DRectF::CD2DRectF
- AFXRENDERTARGET/CD2DRectF::IsNull
helpviewer_keywords:
- CD2DRectF [MFC], CD2DRectF
- CD2DRectF [MFC], IsNull
ms.assetid: 87c12d87-9d18-4a19-ba14-0f51d6b6835a
ms.openlocfilehash: 9b91cfaec3827a61152c4116b56e817a436606be
ms.sourcegitcommit: 725e86dabe2901175ecc63261c3bf05802dddff4
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 07/31/2019
ms.locfileid: "68682396"
---
# <a name="cd2drectf-class"></a>Classe CD2DRectF

Um wrapper para `D2D1_RECT_F`.

## <a name="syntax"></a>Sintaxe

```
class CD2DRectF : public D2D1_RECT_F;
```

## <a name="members"></a>Membros

### <a name="public-constructors"></a>Construtores públicos

|Nome|Descrição|
|----------|-----------------|
|[CD2DRectF::CD2DRectF](#cd2drectf)|Sobrecarregado. Constrói um `CD2DRectF` objeto do `D2D1_RECT_F` objeto.|

### <a name="public-methods"></a>Métodos públicos

|Nome|Descrição|
|----------|-----------------|
|[CD2DRectF::IsNull](#isnull)|Retorna um valor booliano que indica se uma expressão não contém dados válidos (nulo).|

### <a name="public-operators"></a>Operadores públicos

|Nome|Descrição|
|----------|-----------------|
|[Operador CD2DRectF:: Operator CRect](#operator_crect)|Converte `CD2DRectF` para`CRect` objeto.|

## <a name="inheritance-hierarchy"></a>Hierarquia de herança

`D2D1_RECT_F`

`CD2DRectF`

## <a name="requirements"></a>Requisitos

**Cabeçalho:** afxrendertarget. h

##  <a name="cd2drectf"></a>  CD2DRectF::CD2DRectF

Constrói um objeto CD2DRectF do objeto CRect.

```
CD2DRectF(const CRect& rect);
CD2DRectF(const D2D1_RECT_F& rect);
CD2DRectF(const D2D1_RECT_F* rect);

CD2DRectF(
    FLOAT fLeft = 0.,
    FLOAT fTop = 0.,
    FLOAT fRight = 0.,
    FLOAT fBottom = 0.);
```

### <a name="parameters"></a>Parâmetros

*rect*<br/>
retângulo de origem

*fLeft*<br/>
coordenada esquerda de origem

*fTop*<br/>
coordenada superior de origem

*fRight*<br/>
coordenada direita de origem

*fBottom*<br/>
coordenada inferior de origem

##  <a name="isnull"></a>  CD2DRectF::IsNull

Retorna um valor booliano que indica se uma expressão não contém dados válidos (nulo).

```
BOOL IsNull() const;
```

### <a name="return-value"></a>Valor de retorno

TRUE se os valores superior, esquerdo, inferior e direito do retângulo forem todos iguais a 0; caso contrário, FALSE.

##  <a name="operator_crect"></a>Operador CD2DRectF:: Operator CRect

Converte CD2DRectF em objeto CRect.

```
operator CRect();
```

### <a name="return-value"></a>Valor de retorno

Valor atual do retângulo D2D.

## <a name="see-also"></a>Consulte também

[Classes](../../mfc/reference/mfc-classes.md)
