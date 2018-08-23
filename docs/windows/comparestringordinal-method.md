---
title: Método CompareStringOrdinal | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-windows
ms.topic: reference
f1_keywords:
- corewrappers/Microsoft::WRL::Wrappers::Details::CompareStringOrdinal
dev_langs:
- C++
ms.assetid: ffa997fd-8cd7-40a5-b9e7-f55d40b072f4
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
- uwp
ms.openlocfilehash: 952de0ca136d29eb0b170856410b18a1d65120c1
ms.sourcegitcommit: 6f8dd98de57bb80bf4c9852abafef1c35a7600f1
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 08/22/2018
ms.locfileid: "42612882"
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

*LHS*  
O HSTRING primeiro a ser comparado.

*rhs*  
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