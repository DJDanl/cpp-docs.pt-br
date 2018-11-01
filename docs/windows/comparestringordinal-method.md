---
title: Método CompareStringOrdinal
ms.date: 11/04/2016
ms.topic: reference
f1_keywords:
- corewrappers/Microsoft::WRL::Wrappers::Details::CompareStringOrdinal
ms.assetid: ffa997fd-8cd7-40a5-b9e7-f55d40b072f4
ms.openlocfilehash: 61ca0cb6d8afc07b73e33a2e5bc3dc10daacc210
ms.sourcegitcommit: 6052185696adca270bc9bdbec45a626dd89cdcdd
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/31/2018
ms.locfileid: "50593358"
---
# <a name="comparestringordinal-method"></a>Método CompareStringOrdinal

Oferece suporte a infraestrutura do WRL e não se destina a ser usado diretamente do seu código.

## <a name="syntax"></a>Sintaxe

```cpp
inline INT32 CompareStringOrdinal(
   HSTRING lhs,
   HSTRING rhs)
```

### <a name="parameters"></a>Parâmetros

*LHS*<br/>
O HSTRING primeiro a ser comparado.

*rhs*<br/>
O segundo HSTRING para comparar.

## <a name="return-value"></a>Valor de retorno

|Valor|Condição|
|-----------|---------------|
|-1|*LHS* é menor que *rhs*.|
|0|*LHS* é igual a *rhs*.|
|1|*LHS* é maior que *rhs*.|

## <a name="remarks"></a>Comentários

Compara dois objetos HSTRING especificados e retorna um inteiro que indica sua posição relativa em uma ordem de classificação.

## <a name="requirements"></a>Requisitos

**Cabeçalho:** corewrappers. h

**Namespace:** Microsoft::WRL::Wrappers::Details

## <a name="see-also"></a>Consulte também

[Namespace Microsoft::WRL::Wrappers::Details](../windows/microsoft-wrl-wrappers-details-namespace.md)