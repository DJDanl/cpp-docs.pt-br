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
ms.openlocfilehash: 26e647ae01a498a6ad8ca2d7c866f33b01910881
ms.sourcegitcommit: c123cc76bb2b6c5cde6f4c425ece420ac733bf70
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/14/2020
ms.locfileid: "81369104"
---
# <a name="cd2drectu-class"></a>Classe CD2DRectU

Um invólucro para. `D2D1_RECT_U`

## <a name="syntax"></a>Sintaxe

```
class CD2DRectU : public D2D1_RECT_U;
```

## <a name="members"></a>Membros

### <a name="public-constructors"></a>Construtores públicos

|Nome|Descrição|
|----------|-----------------|
|[CD2DRectU::CD2DRectU](#cd2drectu)|Sobrecarregado. Constrói um `CD2DRectU` objeto `D2D1_RECT_U` a partir do objeto.|

### <a name="public-methods"></a>Métodos públicos

|Nome|Descrição|
|----------|-----------------|
|[CD2DRectU::IsNull](#isnull)|Retorna um valor **booleano** que indica se uma expressão não contém dados válidos (NULL).|

### <a name="public-operators"></a>Operadores públicos

|Nome|Descrição|
|----------|-----------------|
|[CD2DRectU:operador CRect](#operator_crect)|`CD2DRectU` Converte-se em `CRect` objeto.|

## <a name="inheritance-hierarchy"></a>Hierarquia de herança

`D2D1_RECT_U`

`CD2DRectU`

## <a name="requirements"></a>Requisitos

**Cabeçalho:** afxrendertarget.h

## <a name="cd2drectucd2drectu"></a><a name="cd2drectu"></a>CD2DRectU::CD2DRectU

Constrói um objeto CD2DRectU a partir do objeto CRect.

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
retângulo fonte

*uLeft*<br/>
fonte esquerda coordenada

*uTop*<br/>
fonte coordenada superior

*uDireito*<br/>
fonte direita coordenada

*uBottom*<br/>
coordenada fundo fonte

## <a name="cd2drectuisnull"></a><a name="isnull"></a>CD2DRectU::IsNull

Retorna um valor booleano que indica se uma expressão não contém dados válidos (Nulo).

```
BOOL IsNull() const;
```

### <a name="return-value"></a>Valor retornado

VERDADE se os valores superior, esquerdo, inferior e direito do retângulo forem todos iguais a 0; caso contrário, FALSO.

## <a name="cd2drectuoperator-crect"></a><a name="operator_crect"></a>CD2DRectU:operador CRect

Converte CD2DRectU em objeto CRect.

```
operator CRect();
```

### <a name="return-value"></a>Valor retornado

Valor atual do retângulo D2D.

## <a name="see-also"></a>Confira também

[Classes](../../mfc/reference/mfc-classes.md)
