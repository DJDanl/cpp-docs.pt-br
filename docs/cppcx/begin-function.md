---
title: Função begin
ms.date: 01/22/2017
f1_keywords:
- collection/Windows::Foundation::Collections::begin
helpviewer_keywords:
- begin Function
ms.assetid: 5a44fb33-e247-49fd-b7a1-4a5b42e9e1e4
ms.openlocfilehash: 5ff8765d759a14cab63e3c8ae0ba2bc419b00775
ms.sourcegitcommit: 6052185696adca270bc9bdbec45a626dd89cdcdd
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/31/2018
ms.locfileid: "50628521"
---
# <a name="begin-function"></a>Função begin

Retorna um iterador que aponta para o início de uma coleção que é acessada pelo parâmetro de interface especificado.

## <a name="syntax"></a>Sintaxe

```

template <typename T>
    ::Platform::Collections::VectorIterator<T>
    begin(
          IVector<T>^ v         );

template <typename T>
    ::Platform::Collections::VectorViewIterator<T>
    begin(
          IVectorView<T>^ v
         );

template <typename T>
    ::Platform::Collections::InputIterator<T>
    begin(
          IIterable<T>^ i         );
```

#### <a name="parameters"></a>Parâmetros

*T*<br/>
Um parâmetro de tipo de modelo.

*v*<br/>
Uma coleção de vetor\<T > ou VectorView\<T > objetos que são acessados por um IVector\<T > ou IVectorView\<T > interface.

*i*<br/>
Uma coleção de objetos arbitrários do tempo de execução do Windows que são acessados por um IIterable\<T > interface.

### <a name="return-value"></a>Valor de retorno

Um iterador que aponta para o início da coleção.

### <a name="remarks"></a>Comentários

Os primeiros dois iteradores de retorno de funções do modelo e a terceira função do modelo retornam um iterador de entrada.

O objeto que é retornado por begin de VectorIterator é um iterador proxy que armazena elementos do tipo VectorProxy\<T >. Entretanto, o objeto proxy quase nunca é visível ao código do usuário. Para obter mais informações, consulte [Coleções (C++/CX)](../cppcx/collections-c-cx.md).

### <a name="requirements"></a>Requisitos

**Cabeçalho:** collection.h

**Namespace:** Windows::Foundation::Collections

## <a name="see-also"></a>Consulte também

[Namespace Collections](../cppcx/windows-foundation-collections-namespace-c-cx.md)