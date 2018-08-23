---
title: SafeMultiply | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-windows
ms.topic: reference
f1_keywords:
- SafeMultiply
dev_langs:
- C++
helpviewer_keywords:
- SafeMultiply function
ms.assetid: 81d988a5-fac7-4930-8c37-c24fa8e2c853
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
- uwp
ms.openlocfilehash: 79f2ae3edaf7f820008882e5ce035446f67b7ce9
ms.sourcegitcommit: 6f8dd98de57bb80bf4c9852abafef1c35a7600f1
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 08/22/2018
ms.locfileid: "42608131"
---
# <a name="safemultiply"></a>SafeMultiply

Multiplica dois números juntos de forma que protege contra estouro.

## <a name="syntax"></a>Sintaxe

```cpp
template<typename T, typename U>
inline bool SafeMultiply (
   T t,
   U u,
   T& result
) throw ();
```

### <a name="parameters"></a>Parâmetros

[in] *t*  
O primeiro número a multiplicar. Isso deve ser do tipo `T`.

[in] *u*  
O segundo número a multiplicar. Isso deve ser do tipo `U`.

[out] *resultado*  
O parâmetro em que **SafeMultiply** armazena o resultado.

## <a name="return-value"></a>Valor de retorno

**True** se nenhum erro ocorrer; **falsos** se ocorrer um erro.

## <a name="remarks"></a>Comentários

Esse método é parte da [biblioteca SafeInt](../windows/safeint-library.md) e é projetado para uma operação de multiplicação único sem criar uma instância das [classe SafeInt](../windows/safeint-class.md).

> [!NOTE]
> Esse método só deve ser usado quando uma operação matemática única deve ser protegida. Se houver várias operações, você deve usar o `SafeInt` classe em vez de chamar as funções individuais de autônomas.

Para obter mais informações sobre os tipos de modelo `T` e `U`, consulte [funções SafeInt](../windows/safeint-functions.md).

## <a name="requirements"></a>Requisitos

**Cabeçalho:** safeint

**Namespace:** Microsoft::Utilities

## <a name="see-also"></a>Consulte também

[Funções SafeInt](../windows/safeint-functions.md)  
[Biblioteca SafeInt](../windows/safeint-library.md)  
[Classe SafeInt](../windows/safeint-class.md)  
[SafeDivide](../windows/safedivide.md)