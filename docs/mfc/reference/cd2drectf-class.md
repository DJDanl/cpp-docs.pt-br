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
ms.openlocfilehash: 33d3c5f9e795ad6c91b689436e8a3b1b56966dce
ms.sourcegitcommit: c123cc76bb2b6c5cde6f4c425ece420ac733bf70
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/14/2020
ms.locfileid: "81369116"
---
# <a name="cd2drectf-class"></a>Classe CD2DRectF

Um invólucro para. `D2D1_RECT_F`

## <a name="syntax"></a>Sintaxe

```
class CD2DRectF : public D2D1_RECT_F;
```

## <a name="members"></a>Membros

### <a name="public-constructors"></a>Construtores públicos

|Nome|Descrição|
|----------|-----------------|
|[CD2DRectF::CD2DRectF](#cd2drectf)|Sobrecarregado. Constrói um `CD2DRectF` objeto `D2D1_RECT_F` a partir do objeto.|

### <a name="public-methods"></a>Métodos públicos

|Nome|Descrição|
|----------|-----------------|
|[CD2DRectF::IsNull](#isnull)|Retorna um valor **booleano** que indica se uma expressão não contém dados válidos (NULL).|

### <a name="public-operators"></a>Operadores públicos

|Nome|Descrição|
|----------|-----------------|
|[CD2DRectF:operador CRect](#operator_crect)|`CD2DRectF` Converte-se em `CRect` objeto.|

## <a name="inheritance-hierarchy"></a>Hierarquia de herança

`D2D1_RECT_F`

`CD2DRectF`

## <a name="requirements"></a>Requisitos

**Cabeçalho:** afxrendertarget.h

## <a name="cd2drectfcd2drectf"></a><a name="cd2drectf"></a>CD2DRectF::CD2DRectF

Constrói um objeto CD2DRectF a partir do objeto CRect.

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

*Rect*<br/>
retângulo fonte

*fLeft*<br/>
fonte esquerda coordenada

*fTop*<br/>
fonte coordenada superior

*Susto*<br/>
fonte direita coordenada

*fBottom*<br/>
coordenada fundo fonte

## <a name="cd2drectfisnull"></a><a name="isnull"></a>CD2DRectF::IsNull

Retorna um valor booleano que indica se uma expressão não contém dados válidos (Nulo).

```
BOOL IsNull() const;
```

### <a name="return-value"></a>Valor retornado

VERDADE se os valores superior, esquerdo, inferior e direito do retângulo forem todos iguais a 0; caso contrário, FALSO.

## <a name="cd2drectfoperator-crect"></a><a name="operator_crect"></a>CD2DRectF:operador CRect

Converte CD2DRectF em objeto CRect.

```
operator CRect();
```

### <a name="return-value"></a>Valor retornado

Valor atual do retângulo D2D.

## <a name="see-also"></a>Confira também

[Classes](../../mfc/reference/mfc-classes.md)
