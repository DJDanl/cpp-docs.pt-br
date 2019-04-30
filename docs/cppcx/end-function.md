---
title: Função end
ms.date: 01/22/2017
f1_keywords:
- collection/Windows::Foundation::Collections::end
helpviewer_keywords:
- end Function
ms.assetid: fb837bff-fc76-4bae-9096-facf0e03041c
ms.openlocfilehash: c46c601be2b2ed78cf79641a7fcf5324e615a771
ms.sourcegitcommit: 0ab61bc3d2b6cfbd52a16c6ab2b97a8ea1864f12
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/23/2019
ms.locfileid: "62375802"
---
# <a name="end-function"></a>Função end

Retorna um iterador que aponta além do fim de uma coleção que é acessada pelo parâmetro de interface especificado.

## <a name="syntax"></a>Sintaxe

```

template <typename T>
    ::Platform::Collections::VectorIterator<T>
    end(
        IVector<T>^ v       );

template <typename T>
    ::Platform::Collections::VectorViewIterator<T>
    end(
        IVectorView<T>^ v
       );
template <typename T>
    ::Platform::Collections::InputIterator<T>
    end(
        IIterable<T>^ i
       );
```

#### <a name="parameters"></a>Parâmetros

*T*<br/>
Um parâmetro de tipo de modelo.

*v*<br/>
Uma coleção de vetor\<T > ou VectorView\<T > objetos que são acessados por um IVector\<T >, ou IVectorView\<T > interface.

*i*<br/>
Objetos de uma coleção de arbitrários em tempo de execução do Windows que são acessados por um IIterable\<T > interface.

### <a name="return-value"></a>Valor de retorno

Um iterador que aponta para além do fim da coleção.

### <a name="remarks"></a>Comentários

Os primeiros dois iteradores de retorno de funções do modelo e a terceira função do modelo retornam um iterador de entrada.

O objeto [Platform::Collections::VectorViewIterator](../cppcx/platform-collections-vectorviewiterator-class.md) que é retornado por `end` é um iterador proxy que armazena elementos do tipo `VectorProxy<T>`. Entretanto, o objeto proxy quase nunca é visível ao código do usuário. Para obter mais informações, consulte [Coleções (C++/CX)](../cppcx/collections-c-cx.md).

### <a name="requirements"></a>Requisitos

**Cabeçalho:** collection.h

**Namespace:** Windows::Foundation::Collections

## <a name="see-also"></a>Consulte também

[Namespace Windows::Foundation::Collections](../cppcx/windows-foundation-collections-namespace-c-cx.md)
