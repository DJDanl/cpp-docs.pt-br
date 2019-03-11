---
title: Classe Platform::Collections::BackInsertIterator
ms.date: 12/30/2016
ms.topic: reference
f1_keywords:
- COLLECTION/Platform::Collections::BackInsertIterator::BackInsertIterator
helpviewer_keywords:
- BackInsertIterator Class
ms.assetid: aecee1ff-100d-4129-b84b-1966f0923dbf
ms.openlocfilehash: 7478555b19bbe5c984fcbe531d2d8be1a0b865a9
ms.sourcegitcommit: dedd4c3cb28adec3793329018b9163ffddf890a4
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 03/11/2019
ms.locfileid: "57739532"
---
# <a name="platformcollectionsbackinsertiterator-class"></a>Classe Platform::Collections::BackInsertIterator

Representa um iterador que insere, em vez de substituir, os elementos no back-end de uma coleção sequencial.

## <a name="syntax"></a>Sintaxe

```
template <typename T>
class BackInsertIterator :
public ::std::iterator<::std::output_iterator_tag, void, void, void, void>;
```

#### <a name="parameters"></a>Parâmetros

*T*<br/>
O tipo de item na coleção atual.

### <a name="remarks"></a>Comentários

A classe BackInsertIterator implementa as regras necessárias para o [back_insert_iterator Class](../standard-library/back-insert-iterator-class.md).

### <a name="members"></a>Membros

### <a name="public-constructors"></a>Construtores Públicos

|Nome|Descrição|
|----------|-----------------|
|[BackInsertIterator::BackInsertIterator](#ctor)|Inicializa uma nova instância da classe BackInsertIterator.|

### <a name="public-operators"></a>Operadores públicos

|Nome|Descrição|
|----------|-----------------|
|[Operador BackInsertIterator::operator*](#operator-dereference)|Recupera uma referência ao BackInsertIterator atual.|
|[Operador BackInsertIterator::operator++](#operator-increment)|Retorna uma referência ao BackInsertIterator atual. O iterador é não modificado.|
|[Operador BackInsertIterator::operator=](#operator-assign)|Anexa o objeto especificado ao final da coleção sequencial atual.|

## <a name="inheritance-hierarchy"></a>Hierarquia de herança

`BackInsertIterator`

### <a name="requirements"></a>Requisitos

**Cabeçalho:** collection.h

**Namespace:** Platform::Collections

---
## <a name="ctor"></a>  Construtor backinsertiterator:: Backinsertiterator

Inicializa uma nova instância da classe `BackInsertIterator`.

## <a name="syntax"></a>Sintaxe

```

explicit BackInsertIterator(
   Windows::Foundation::Collections::IVector<T>^ v);
```

#### <a name="parameters"></a>Parâmetros

*v*<br/>
Um IVector\<T > objeto.

### <a name="remarks"></a>Comentários

Um `BackInsertIterator` insere elementos depois do último elemento do objeto especificado pelo parâmetro `v`.

## <a name="operator-assign"></a>  Backinsertiterator:: Operator operador =

Anexa o objeto especificado ao final da coleção sequencial atual.

## <a name="syntax"></a>Sintaxe

```
BackInsertIterator& operator=( const T& t);
```

#### <a name="parameters"></a>Parâmetros

*t*<br/>
O objeto a ser acrescentado à coleção atual.

### <a name="return-value"></a>Valor de retorno

Uma referência ao BackInsertIterator atual.

## <a name="operator-dereference"></a>  Operador backinsertiterator:: Operator *

Recupera uma referência ao BackInsertIterator atual.

## <a name="syntax"></a>Sintaxe

```
BackInsertIterator& operator*();
```

### <a name="return-value"></a>Valor de retorno

Uma referência ao BackInsertIterator atual.

### <a name="remarks"></a>Comentários

Esse operador retorna uma referência ao BackInsertIterator atual, não a qualquer elemento na coleção atual.

## <a name="operator-increment"></a>  Operador backinsertiterator:: Operator + +

Retorna uma referência ao BackInsertIterator atual. O iterador é não modificado.

## <a name="syntax"></a>Sintaxe

```

BackInsertIterator& operator++();

BackInsertIterator operator++(int);
```

### <a name="return-value"></a>Valor de retorno

Uma referência ao BackInsertIterator atual.

### <a name="remarks"></a>Comentários

Por design, o primeiro exemplo de sintaxe pré-incrementa o BackInsertIterator atual e a segunda sintaxe pós-incrementa o BackInsertIterator atual. O tipo `int` na segunda sintaxe indica uma operação de pós-incremento, não um operando de inteiro real.

No entanto, esse operador realmente não modifica o BackInsertIterator. Em vez disso, esse operador retorna uma referência para o iterador não modificado atual. Isso é o mesmo comportamento que [operador *](#dereference-operator).

## <a name="see-also"></a>Consulte também

[Namespace de plataforma](platform-namespace-c-cx.md)
