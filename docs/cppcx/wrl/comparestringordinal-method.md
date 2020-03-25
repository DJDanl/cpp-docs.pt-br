---
title: Método CompareStringOrdinal
ms.date: 11/04/2016
ms.topic: reference
f1_keywords:
- corewrappers/Microsoft::WRL::Wrappers::Details::CompareStringOrdinal
ms.assetid: ffa997fd-8cd7-40a5-b9e7-f55d40b072f4
ms.openlocfilehash: 1291084395b02602b7a3de9013df6720d2e237fc
ms.sourcegitcommit: 857fa6b530224fa6c18675138043aba9aa0619fb
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 03/24/2020
ms.locfileid: "80214091"
---
# <a name="comparestringordinal-method"></a>Método CompareStringOrdinal

O oferece suporte à infraestrutura WRL e não se destina a ser usado diretamente do seu código.

## <a name="syntax"></a>Sintaxe

```cpp
inline INT32 CompareStringOrdinal(
   HSTRING lhs,
   HSTRING rhs)
```

### <a name="parameters"></a>parâmetros

*lhs*<br/>
O primeiro HSTRING a ser comparado.

*rhs*<br/>
O segundo HSTRING a ser comparado.

## <a name="return-value"></a>Valor retornado

|Valor|Condição|
|-----------|---------------|
|-1|o *LHS* é menor do que o *RHS*.|
|0|*LHS* é igual a *RHS*.|
|1|o *LHS* é maior que o *RHS*.|

## <a name="remarks"></a>Comentários

Compara dois objetos HSTRING especificados e retorna um inteiro que indica sua posição relativa em uma ordem de classificação.

## <a name="requirements"></a>Requisitos

**Cabeçalho:** corewrappers. h

**Namespace:** Microsoft:: WRL:: wrappers::D etalhes

## <a name="see-also"></a>Confira também

[Namespace Microsoft::WRL::Wrappers::Details](microsoft-wrl-wrappers-details-namespace.md)
