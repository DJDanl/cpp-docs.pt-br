---
title: Classe CD2DSizeU
ms.date: 11/04/2016
f1_keywords:
- CD2DSizeU
- AFXRENDERTARGET/CD2DSizeU
- AFXRENDERTARGET/CD2DSizeU::CD2DSizeU
- AFXRENDERTARGET/CD2DSizeU::IsNull
helpviewer_keywords:
- CD2DSizeU [MFC], CD2DSizeU
- CD2DSizeU [MFC], IsNull
ms.assetid: 6e679ba8-2112-43c3-8275-70b660856f02
ms.openlocfilehash: bad73a53eabe0a4c75483e9871a4fdc4a361449b
ms.sourcegitcommit: 6052185696adca270bc9bdbec45a626dd89cdcdd
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/31/2018
ms.locfileid: "50512470"
---
# <a name="cd2dsizeu-class"></a>Classe CD2DSizeU

Um wrapper para D2D1_SIZE_U.

## <a name="syntax"></a>Sintaxe

```
class CD2DSizeU : public D2D1_SIZE_U;
```

## <a name="members"></a>Membros

### <a name="public-constructors"></a>Construtores Públicos

|Nome|Descrição|
|----------|-----------------|
|[CD2DSizeU::CD2DSizeU](#cd2dsizeu)|Sobrecarregado. Constrói uma `CD2DSizeU` do objeto de `D2D1_SIZE_U` objeto.|

### <a name="public-methods"></a>Métodos públicos

|Nome|Descrição|
|----------|-----------------|
|[CD2DSizeU::IsNull](#isnull)|Retorna um **boolean** valor que indica se uma expressão não contém dados válidos (nulo).|

### <a name="public-operators"></a>Operadores públicos

|Nome|Descrição|
|----------|-----------------|
|[CD2DSizeU::Operator CSize](#operator_csize)|Converte `CD2DSizeU` para `CSize` objeto.|

## <a name="inheritance-hierarchy"></a>Hierarquia de herança

`D2D1_SIZE_U`

[CD2DSizeU](../../mfc/reference/cd2dsizeu-class.md)

## <a name="requirements"></a>Requisitos

**Cabeçalho:** afxrendertarget.h

##  <a name="cd2dsizeu"></a>  CD2DSizeU::CD2DSizeU

Constrói um objeto CD2DSizeU CSize objeto.

```
CD2DSizeU(const CSize& size);
CD2DSizeU(const D2D1_SIZE_U& size);
  CD2DSizeU(const D2D1_SIZE_U* size);

CD2DSizeU(
    UINT32 cx = 0,
    UINT32 cy = 0);
```

### <a name="parameters"></a>Parâmetros

*size*<br/>
tamanho da fonte

*CX*<br/>
largura de origem

*Cy*<br/>
altura de origem

##  <a name="isnull"></a>  CD2DSizeU::IsNull

Retorna um valor booliano que indica se uma expressão não contém dados válidos (nulo).

```
BOOL IsNull() const;
```

### <a name="return-value"></a>Valor de retorno

TRUE se a largura e altura são vazios. Caso contrário, FALSE.

##  <a name="operator_csize"></a>  CD2DSizeU::Operator CSize

Converte CD2DSizeU CSize objeto.

```
operator CSize();
```

### <a name="return-value"></a>Valor de retorno

Valor atual de tamanho D2D.

## <a name="see-also"></a>Consulte também

[Classes](../../mfc/reference/mfc-classes.md)
