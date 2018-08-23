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
ms.openlocfilehash: 2ddb7092b1a5556485848d122e21ac54b6efe182
ms.sourcegitcommit: 6f8dd98de57bb80bf4c9852abafef1c35a7600f1
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 08/22/2018
ms.locfileid: "42606949"
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

[in] *eu*  
O valor para o novo **SafeInt** objeto. Isso deve ser um parâmetro de tipo T ou U, dependendo do construtor.

[in] *b*  
O valor booliano para a nova **SafeInt** objeto.

[in] *u*  
Um **SafeInt** de u tipo. O novo **SafeInt** objeto terá o mesmo valor de *u*, mas será do tipo T.

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