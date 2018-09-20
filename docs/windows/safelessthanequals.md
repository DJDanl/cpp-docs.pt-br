---
title: SafeLessThanEquals | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-windows
ms.topic: reference
f1_keywords:
- SafeLessThanEquals
dev_langs:
- C++
helpviewer_keywords:
- SafeLessThanEquals function
ms.assetid: cbd70526-faf2-4fbc-96a0-b61e8cf5f04a
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
- uwp
ms.openlocfilehash: f9de4e5f5ef8d3007cd60710617977e00f92679c
ms.sourcegitcommit: 799f9b976623a375203ad8b2ad5147bd6a2212f0
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/19/2018
ms.locfileid: "46380900"
---
# <a name="safelessthanequals"></a>SafeLessThanEquals

Compara dois números.

## <a name="syntax"></a>Sintaxe

```cpp
template <typename T, typename U>
inline bool SafeLessThanEquals (
   const T t,
   const U u
) throw ();
```

### <a name="parameters"></a>Parâmetros

*t*<br/>
[in] O primeiro número a ser comparado. Isso deve ser do tipo `T`.

*u*<br/>
[in] O segundo número a ser comparado. Isso deve ser do tipo `U`.

## <a name="return-value"></a>Valor de retorno

**Verdadeiro** se *t* é menor que ou igual a *u*; caso contrário **false**.

## <a name="remarks"></a>Comentários

**SafeLessThanEquals** estende o operador de comparação regular, permitindo que você comparar dois tipos diferentes de números.

Esse método é parte da [biblioteca SafeInt](../windows/safeint-library.md) e é projetado para uma operação de comparação única sem criar uma instância das [classe SafeInt](../windows/safeint-class.md).

> [!NOTE]
> Esse método só deve ser usado quando uma operação matemática única deve ser protegida. Se houver várias operações, você deve usar o `SafeInt` classe em vez de chamar as funções individuais de autônomas.

Para obter mais informações sobre os tipos de modelo `T` e `U`, consulte [funções SafeInt](../windows/safeint-functions.md).

## <a name="requirements"></a>Requisitos

**Cabeçalho:** safeint

**Namespace:** Microsoft::Utilities

## <a name="see-also"></a>Consulte também

[Funções SafeInt](../windows/safeint-functions.md)<br/>
[Biblioteca SafeInt](../windows/safeint-library.md)<br/>
[Classe SafeInt](../windows/safeint-class.md)<br/>
[SafeGreaterThan](../windows/safegreaterthan.md)<br/>
[SafeLessThan](../windows/safelessthan.md)<br/>
[SafeGreaterThanEquals](../windows/safegreaterthanequals.md)