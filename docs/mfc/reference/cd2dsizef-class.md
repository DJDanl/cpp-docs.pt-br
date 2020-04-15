---
title: Classe CD2DSizeF
ms.date: 08/29/2019
f1_keywords:
- CD2DSizeF
- AFXRENDERTARGET/CD2DSizeF
- AFXRENDERTARGET/CD2DSizeF::CD2DSizeF
- AFXRENDERTARGET/CD2DSizeF::IsNull
helpviewer_keywords:
- CD2DSizeF [MFC], CD2DSizeF
- CD2DSizeF [MFC], IsNull
ms.assetid: f486a1e1-997d-4286-8cb9-26369dc82055
ms.openlocfilehash: be050f98855e5af794166e1f86962111a23bfa2e
ms.sourcegitcommit: c123cc76bb2b6c5cde6f4c425ece420ac733bf70
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/14/2020
ms.locfileid: "81369065"
---
# <a name="cd2dsizef-class"></a>Classe CD2DSizeF

Um invólucro para D2D1_SIZE_F.

## <a name="syntax"></a>Sintaxe

```
class CD2DSizeF : public D2D1_SIZE_F;
```

## <a name="members"></a>Membros

### <a name="public-constructors"></a>Construtores públicos

|Nome|Descrição|
|----------|-----------------|
|[CD2DSizeF::CD2DSizeF](#cd2dsizef)|Sobrecarregado. Constrói um `CD2DSizeF` objeto `D2D1_SIZE_F` a partir do objeto.|

### <a name="public-methods"></a>Métodos públicos

|Nome|Descrição|
|----------|-----------------|
|[CD2DSizef::isnull](#isnull)|Retorna um valor **booleano** que indica se uma expressão não contém dados válidos (NULL).|

### <a name="public-operators"></a>Operadores públicos

|Nome|Descrição|
|----------|-----------------|
|[CD2DSizeF:operador CSize](#operator_csize)|`CD2DSizeF` Converte-se em `CSize` objeto.|

## <a name="inheritance-hierarchy"></a>Hierarquia de herança

`D2D1_SIZE_F`

[CD2DSizeF](../../mfc/reference/cd2dsizef-class.md)

## <a name="requirements"></a>Requisitos

**Cabeçalho:** afxrendertarget.h

## <a name="cd2dsizefcd2dsizef"></a><a name="cd2dsizef"></a>CD2DSizeF::CD2DSizeF

Constrói um objeto CD2DSizeF a partir do objeto CSize.

```
CD2DSizeF(const CSize& size);
CD2DSizeF(const D2D1_SIZE_F& size);
CD2DSizeF(const D2D1_SIZE_F* size);

CD2DSizeF(
    FLOAT cx = 0.,
    FLOAT cy = 0.);
```

### <a name="parameters"></a>Parâmetros

*Tamanho*<br/>
tamanho da fonte

*Cx*<br/>
largura de origem

*Cy*<br/>
altura da fonte

## <a name="cd2dsizefisnull"></a><a name="isnull"></a>CD2DSizef::isnull

Retorna um valor booleano que indica se uma expressão não contém dados válidos (Nulo).

```
BOOL IsNull() const;
```

### <a name="return-value"></a>Valor retornado

VERDADE se largura e altura estiverem vazias; caso contrário, FALSO.

## <a name="cd2dsizefoperator-csize"></a><a name="operator_csize"></a>CD2DSizeF:operador CSize

Converte CD2DSizeF em objeto CSize.

```
operator CSize();
```

### <a name="return-value"></a>Valor retornado

Valor atual do tamanho D2D.

## <a name="see-also"></a>Confira também

[Classes](../../mfc/reference/mfc-classes.md)
