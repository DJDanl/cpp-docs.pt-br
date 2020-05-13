---
title: Classe CD2DSizeU
ms.date: 08/29/2019
f1_keywords:
- CD2DSizeU
- AFXRENDERTARGET/CD2DSizeU
- AFXRENDERTARGET/CD2DSizeU::CD2DSizeU
- AFXRENDERTARGET/CD2DSizeU::IsNull
helpviewer_keywords:
- CD2DSizeU [MFC], CD2DSizeU
- CD2DSizeU [MFC], IsNull
ms.assetid: 6e679ba8-2112-43c3-8275-70b660856f02
ms.openlocfilehash: a5b87fe2ddd8fb32ddbbb2884c630952afdb079c
ms.sourcegitcommit: c123cc76bb2b6c5cde6f4c425ece420ac733bf70
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/14/2020
ms.locfileid: "81359288"
---
# <a name="cd2dsizeu-class"></a>Classe CD2DSizeU

Um invólucro para D2D1_SIZE_U.

## <a name="syntax"></a>Sintaxe

```
class CD2DSizeU : public D2D1_SIZE_U;
```

## <a name="members"></a>Membros

### <a name="public-constructors"></a>Construtores públicos

|Nome|Descrição|
|----------|-----------------|
|[CD2DSizeu::Cd2DSizeu](#cd2dsizeu)|Sobrecarregado. Constrói um `CD2DSizeU` objeto `D2D1_SIZE_U` a partir do objeto.|

### <a name="public-methods"></a>Métodos públicos

|Nome|Descrição|
|----------|-----------------|
|[CD2dsizeu::isnull](#isnull)|Retorna um valor **booleano** que indica se uma expressão não contém dados válidos (NULL).|

### <a name="public-operators"></a>Operadores públicos

|Nome|Descrição|
|----------|-----------------|
|[CD2DSizeU:operador CSize](#operator_csize)|`CD2DSizeU` Converte-se em `CSize` objeto.|

## <a name="inheritance-hierarchy"></a>Hierarquia de herança

`D2D1_SIZE_U`

[CD2DSizeu](../../mfc/reference/cd2dsizeu-class.md)

## <a name="requirements"></a>Requisitos

**Cabeçalho:** afxrendertarget.h

## <a name="cd2dsizeucd2dsizeu"></a><a name="cd2dsizeu"></a>CD2DSizeu::Cd2DSizeu

Constrói um objeto CD2DSizeU a partir do objeto CSize.

```
CD2DSizeU(const CSize& size);
CD2DSizeU(const D2D1_SIZE_U& size);
CD2DSizeU(const D2D1_SIZE_U* size);

CD2DSizeU(
    UINT32 cx = 0,
    UINT32 cy = 0);
```

### <a name="parameters"></a>Parâmetros

*Tamanho*<br/>
tamanho da fonte

*Cx*<br/>
largura de origem

*Cy*<br/>
altura da fonte

## <a name="cd2dsizeuisnull"></a><a name="isnull"></a>CD2dsizeu::isnull

Retorna um valor booleano que indica se uma expressão não contém dados válidos (Nulo).

```
BOOL IsNull() const;
```

### <a name="return-value"></a>Valor retornado

VERDADE se largura e altura estiverem vazias; caso contrário, FALSO.

## <a name="cd2dsizeuoperator-csize"></a><a name="operator_csize"></a>CD2DSizeU:operador CSize

Converte CD2DSizeU em objeto CSize.

```
operator CSize();
```

### <a name="return-value"></a>Valor retornado

Valor atual do tamanho D2D.

## <a name="see-also"></a>Confira também

[Classes](../../mfc/reference/mfc-classes.md)
