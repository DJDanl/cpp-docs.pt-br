---
title: SafeInt::SafeInt | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-windows
ms.topic: reference
f1_keywords:
- SafeInt::SafeInt
- SafeInt
- SafeInt.SafeInt
dev_langs:
- C++
helpviewer_keywords:
- SafeInt class, constructor
ms.assetid: 39e6f632-a396-40e6-9ece-cc3d4c5a78ef
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
- uwp
ms.openlocfilehash: de318ab79638f63fae98856987340ad62534f695
ms.sourcegitcommit: 92f2fff4ce77387b57a4546de1bd4bd464fb51b6
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/17/2018
ms.locfileid: "45721339"
---
# <a name="safeintsafeint"></a>SafeInt::SafeInt

Constrói uma **SafeInt** objeto.

## <a name="syntax"></a>Sintaxe

```cpp
SafeInt() throw

SafeInt (
   const T& i
) throw ()

SafeInt (
   bool b
) throw ()

template <typename U>
SafeInt (
   const SafeInt <U, E>& u
)

I template <typename U>
SafeInt (
   const U& i
)  
```

### <a name="parameters"></a>Parâmetros

*i*<br/>
[in] O valor para o novo **SafeInt** objeto. Isso deve ser um parâmetro de tipo T ou U, dependendo do construtor.

*b*<br/>
[in] O valor booliano para a nova **SafeInt** objeto.

*u*<br/>
[in] Um **SafeInt** de u tipo. O novo **SafeInt** objeto terá o mesmo valor de *u*, mas será do tipo T.

O tipo de dados armazenados em do U os **SafeInt**. Isso pode ser o tipo de um valor booliano, caractere ou inteiro. Se for um tipo inteiro, pode ser assinado ou não assinado e ter entre 8 e 64 bits.

## <a name="remarks"></a>Comentários

Para obter mais informações sobre os tipos de modelo `T` e `E`, consulte [classe SafeInt](../windows/safeint-class.md).

O parâmetro de entrada para o construtor *eu* ou *u*, deve ser um tipo booliano, caractere ou inteiro. Se ele é outro tipo de parâmetro, o **SafeInt** chamado pela classe [static_assert](../cpp/static-assert.md) para indicar um parâmetro de entrada inválido.

Os construtores que usam o tipo de modelo `U` converter automaticamente o parâmetro de entrada para o tipo especificado pelo `T`. O **SafeInt** classe converte os dados sem qualquer perda de dados. Ele informa ao manipulador de erros `E` se ele não é possível converter os dados para o tipo `T` sem perda de dados.

Se você criar uma **SafeInt** de um parâmetro booliano, você precisa inicializar o valor imediatamente. Não é possível construir um **SafeInt** usando o código `SafeInt<bool> sb;`. Isso irá gerar um erro de compilação.

## <a name="requirements"></a>Requisitos

**Cabeçalho:** safeint

**Namespace:** MSL:: Utilities

## <a name="see-also"></a>Consulte também

[Biblioteca SafeInt](../windows/safeint-library.md)  
[Classe SafeInt](../windows/safeint-class.md)  
[Classe SafeIntException](../windows/safeintexception-class.md)