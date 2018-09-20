---
title: SafeLessThan | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-windows
ms.topic: reference
f1_keywords:
- SafeLessThan
dev_langs:
- C++
helpviewer_keywords:
- SafeLessThan function
ms.assetid: 9d85bc0d-8d94-4d59-9b72-ef3c63a120a0
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
- uwp
ms.openlocfilehash: a5824b1e3ba050cf8c6d9c0f7b56231211f1f59a
ms.sourcegitcommit: 799f9b976623a375203ad8b2ad5147bd6a2212f0
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/19/2018
ms.locfileid: "46377165"
---
# <a name="safelessthan"></a>SafeLessThan

Determina se um número é menor que outro.

## <a name="syntax"></a>Sintaxe

```cpp
template<typename T, typename U>
inline bool SafeLessThan (
   const T t,
   const U u
) throw ();
```

### <a name="parameters"></a>Parâmetros

*t*<br/>
[in] O primeiro número. Isso deve ser do tipo `T`.

*u*<br/>
[in] O segundo número. Isso deve ser do tipo `U`.

## <a name="return-value"></a>Valor de retorno

**Verdadeiro** se *t* é menor que *u*; caso contrário **false**.

## <a name="remarks"></a>Comentários

Esse método melhora o operador de comparação padrão, pois **SafeLessThan** permite comparar dois tipos diferentes de número.

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
[SafeLessThanEquals](../windows/safelessthanequals.md)<br/>
[SafeGreaterThan](../windows/safegreaterthan.md)<br/>
[SafeGreaterThanEquals](../windows/safegreaterthanequals.md)