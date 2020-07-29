---
title: Classe Platform::Collections::VectorIterator
ms.date: 03/27/2019
ms.topic: reference
f1_keywords:
- COLLECTION/Platform::Collections::VectorIterator::VectorIterator
helpviewer_keywords:
- VectorIterator Class
ms.assetid: d531cb42-27e0-48a6-bf5e-c265891a18ff
ms.openlocfilehash: bade67a104774c3ab6187e250c6faf6969002c0c
ms.sourcegitcommit: 1f009ab0f2cc4a177f2d1353d5a38f164612bdb1
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 07/27/2020
ms.locfileid: "87218410"
---
# <a name="platformcollectionsvectoriterator-class"></a>Classe Platform::Collections::VectorIterator

Fornece um iterador de biblioteca de modelos padrão para objetos derivados da interface Windows Runtime IVector.

VectorIterator é um iterador de proxy que armazena elementos do tipo VectorProxy \<T> . Entretanto, o objeto proxy quase nunca é visível ao código do usuário. Para obter mais informações, consulte [Coleções (C++/CX)](../cppcx/collections-c-cx.md).

## <a name="syntax"></a>Sintaxe

```
template <typename T>
class VectorIterator;
```

#### <a name="parameters"></a>parâmetros

*T*<br/>
O typename da classe de modelo de VectorIterator.

### <a name="members"></a>Membros

### <a name="public-typedefs"></a>Typedefs públicos

|Nome|Descrição|
|----------|-----------------|
|`difference_type`|Uma diferença de ponteiro (ptrdiff_t).|
|`iterator_category`|A categoria de um iterador de acesso aleatório (::std::random_access_iterator_tag).|
|`pointer`|Um ponteiro para um tipo interno, Platform:: Collections::D etalhes:: VectorProxy \<T> , que é necessário para a implementação de VectorIterator.|
|`reference`|Uma referência a um tipo interno, Platform:: Collections::D etalhes:: VectorProxy \<T> ,, que é necessário para a implementação de VectorIterator.|
|`value_type`|O typename `T` .|

### <a name="public-constructors"></a>Construtores públicos

|Nome|Descrição|
|----------|-----------------|
|[VectorIterator::VectorIterator](#ctor)|Inicializa uma nova instância da classe VectorIterator.|

### <a name="public-operators"></a>Operadores públicos

|Nome|Descrição|
|----------|-----------------|
|[Operador VectorIterator:: Operator](#operator-minus)|Subtrai um número especificado de elementos do iterador atual, gerando um novo iterador, ou um iterador especificado do iterador atual, gerando o número de elementos entre os iteradores.|
|[Operador VectorIterator:: Operator](#operator-decrement)|Decrementa o VectorIterator atual.|
|[Operador VectorIterator:: Operator! =](#operator-inequality)|Indica se o VectorIterator atual não é igual a um VectorIterator especificado.|
|[Operador VectorIterator:: Operator *](#operator-dereference)|Recupera uma referência ao elemento especificado pelo VectorIterator atual.|
|[Operador VectorIterator::\[\]](#operator-at)|Recupera uma referência ao elemento que é um deslocamento especificado de VectorIterator atual.|
|[Operador VectorIterator:: Operator +](#operator-plus)|Retorna um VectorIterator que referencia o elemento no deslocamento especificado do VectorIterator especificado.|
|[Operador VectorIterator:: Operator + +](#operator-increment)|Incrementa o VectorIterator atual.|
|[Operador VectorIterator:: Operator + =](#operator-plus-assign)|Incrementa o VectorIterator atual pelo deslocamento especificado.|
|[Operador VectorIterator:: Operator<](#operator-less-than)|Indica se o VectorIterator atual é menor que um VectorIterator especificado.|
|[Operador VectorIterator:: Operator \< =](#operator-less-than-or-equals)|Indica se o VectorIterator atual é menor ou igual a um VectorIterator especificado.|
|[Operador VectorIterator::operator-=](#operator-minus-equals)|Decrementa o VectorIterator atual pelo deslocamento especificado.|
|[Operador VectorIterator:: Operator = =](#operator-equality)|Indica se o VectorIterator atual é igual a um VectorIterator especificado.|
|[Operador VectorIterator:: Operator>](#operator-greater-than)|Indica se o VectorIterator atual é maior que um VectorIterator especificado.|
|[Operador VectorIterator:: Operator->](#operator-arrow)|Recupera o endereço do elemento referenciado pelo VectorIterator atual.|
|[Operador VectorIterator:: Operator>=](#operator-greater-than-or-equals)|Indica se o VectorIterator atual é maior ou igual a um VectorIterator especificado.|

## <a name="inheritance-hierarchy"></a>Hierarquia de herança

`VectorIterator`

### <a name="requirements"></a>Requisitos

**Cabeçalho:** collection.h

**Namespace:** Platform::Collections

## <a name="vectoriteratoroperator-gt-operator"></a><a name="operator-arrow"></a>Operador VectorIterator:: Operator &gt;

Recupera o endereço do elemento referenciado pelo VectorIterator atual.

### <a name="syntax"></a>Sintaxe

```
Detail::ArrowProxy<T> operator->() const;
```

### <a name="return-value"></a>Valor retornado

O valor do elemento que é referenciado pelo VectorIterator atual.

O tipo do valor retornado é um tipo interno não especificado que é necessário para a implementação desse operador.

## <a name="vectoriteratoroperator---operator"></a><a name="operator-decrement"></a>Operador VectorIterator:: Operator

Decrementa o VectorIterator atual.

### <a name="syntax"></a>Sintaxe

```

VectorIterator& operator--();
VectorIterator operator--(int);
```

### <a name="return-value"></a>Valor retornado

A primeira sintaxe diminui e, em seguida, retorna o VectorIterator atual. A segunda sintaxe retorna uma cópia do VectorIterator atual e, em seguida, diminui o VectorIterator atual.

### <a name="remarks"></a>Comentários

A primeira sintaxe de VectorIterator pré-diminui o VectorIterator atual.

A segunda sintaxe pós-diminui o VectorIterator atual. O **`int`** tipo na segunda sintaxe indica uma operação de pós-recuperação, não um operando de inteiro real.

## <a name="vectoriteratoroperator-operator"></a><a name="operator-dereference"></a>Operador VectorIterator:: Operator \*

Recupera o endereço do elemento especificado pelo VectorIterator atual.

### <a name="syntax"></a>Sintaxe

```
reference operator*() const;
```

### <a name="return-value"></a>Valor retornado

O elemento especificado pelo VectorIterator atual.

## <a name="vectoriteratoroperator-operator"></a><a name="operator-equality"></a>Operador VectorIterator:: Operator = =

Indica se o VectorIterator atual é igual a um VectorIterator especificado.

### <a name="syntax"></a>Sintaxe

```
bool operator==(const VectorIterator& other) const;
```

### <a name="parameters"></a>parâmetros

*outros*<br/>
Outro VectorIterator.

### <a name="return-value"></a>Valor retornado

**`true`** Se o VectorIterator atual for igual a *outro*; caso contrário, **`false`** .

## <a name="vectoriteratoroperatorgt-operator"></a><a name="operator-greater-than"></a>Operador VectorIterator:: Operator &gt;

Indica se o VectorIterator atual é maior que um VectorIterator especificado.

### <a name="syntax"></a>Sintaxe

```cpp
bool operator>(const VectorIterator& other) const
```

### <a name="parameters"></a>parâmetros

*outros*<br/>
Outro VectorIterator.

### <a name="return-value"></a>Valor retornado

**`true`** Se o VectorIterator atual for maior que o *outro*; caso contrário, **`false`** .

## <a name="vectoriteratoroperatorgt-operator"></a><a name="operator-greater-than-or-equals"></a>Operador VectorIterator:: Operator &gt; =

Indica se o VectorIterator atual é maior ou igual ao VectorIterator especificado.

### <a name="syntax"></a>Sintaxe

```cpp
bool operator>=(const VectorIterator& other) const
```

### <a name="parameters"></a>parâmetros

*outros*<br/>
Outro VectorIterator.

### <a name="return-value"></a>Valor retornado

**`true`** Se o VectorIterator atual for maior ou igual a *outro*; caso contrário, **`false`** .

## <a name="vectoriteratoroperator-operator"></a><a name="operator-increment"></a>Operador VectorIterator:: Operator + +

Incrementa o VectorIterator atual.

### <a name="syntax"></a>Sintaxe

```
VectorIterator& operator++();
VectorIterator operator++(int);
```

### <a name="return-value"></a>Valor retornado

A primeira sintaxe incrementa e, em seguida, retorna o VectorIterator atual. A segunda sintaxe retorna uma cópia de VectorIterator atual e, em seguida, incrementa VectorIterator atual.

### <a name="remarks"></a>Comentários

A primeira sintaxe de VectorIterator pré-incrementa o VectorIterator atual.

A segunda sintaxe pós-incrementa o VectorIterator atual. O **`int`** tipo na segunda sintaxe indica uma operação de incremento, não um operando de inteiro real.

## <a name="vectoriteratoroperator-operator"></a><a name="operator-inequality"></a>Operador VectorIterator:: Operator! =

Indica se o VectorIterator atual não é igual a um VectorIterator especificado.

### <a name="syntax"></a>Sintaxe

```
bool operator!=(const VectorIterator& other) const;
```

### <a name="parameters"></a>parâmetros

*outros*<br/>
Outro VectorIterator.

### <a name="return-value"></a>Valor retornado

**`true`** Se o VectorIterator atual não for igual a *outro*; caso contrário, **`false`** .

## <a name="vectoriteratoroperatorlt-operator"></a><a name="operator-less-than"></a>Operador VectorIterator:: Operator &lt;

Indica se o VectorIterator atual é menor que um VectorIterator especificado.

### <a name="syntax"></a>Sintaxe

```cpp
bool operator<(const VectorIterator& other) const
```

### <a name="parameters"></a>parâmetros

*outros*<br/>
Outro VectorIterator.

### <a name="return-value"></a>Valor retornado

**`true`** Se o VectorIterator atual for menor do que o *outro*; caso contrário, **`false`** .

## <a name="vectoriteratoroperatorlt-operator"></a><a name="operator-less-than-or-equals"></a>Operador VectorIterator:: Operator &lt; =

Indica se o VectorIterator atual é menor ou igual a um VectorIterator especificado.

### <a name="syntax"></a>Sintaxe

```cpp
bool operator<=(const VectorIterator& other) const
```

### <a name="parameters"></a>parâmetros

*outros*<br/>
Outro VectorIterator.

### <a name="return-value"></a>Valor retornado

**`true`** Se o VectorIterator atual for menor ou igual a *outro*; caso contrário, **`false`** .

## <a name="vectoriteratoroperator--operator"></a><a name="operator-minus"></a>Operador VectorIterator:: Operator

Subtrai um número especificado de elementos do iterador atual, gerando um novo iterador, ou um iterador especificado do iterador atual, gerando o número de elementos entre os iteradores.

### <a name="syntax"></a>Sintaxe

```

VectorIterator operator-(difference_type n) const;

difference_type operator-(const VectorIterator& other) const;
```

### <a name="parameters"></a>parâmetros

*n*<br/>
Um número de elementos.

*outros*<br/>
Outro VectorIterator.

### <a name="return-value"></a>Valor retornado

A primeira sintaxe do operador retorna um objeto VectorIterator que corresponde a elementos `n`, menos o VectorIterator atual. A segunda sintaxe do operador retorna o número de elementos entre o VectorIterator atual e `other`.

## <a name="vectoriteratoroperator-operator"></a><a name="operator-plus-assign"></a>Operador VectorIterator:: Operator + =

Incrementa o VectorIterator atual pelo deslocamento especificado.

### <a name="syntax"></a>Sintaxe

```
VectorIterator& operator+=(difference_type n);
```

### <a name="parameters"></a>parâmetros

*n*<br/>
Um deslocamento de inteiro.

### <a name="return-value"></a>Valor retornado

O VectorIterator atualizado.

## <a name="vectoriteratoroperator-operator"></a><a name="operator-plus"></a>Operador VectorIterator:: Operator +

Retorna um VectorIterator que referencia o elemento no deslocamento especificado do VectorIterator especificado.

### <a name="syntax"></a>Sintaxe

```

VectorIterator operator+(difference_type n);

template <typename T>
inline VectorIterator<T> operator+(
  ptrdiff_t n,
  const VectorIterator<T>& i);
```

### <a name="parameters"></a>parâmetros

*T*<br/>
Na segunda sintaxe, o typename de VectorIterator.

*n*<br/>
Um deslocamento de inteiro.

*i*<br/>
Na segunda sintaxe, um VectorIterator.

### <a name="return-value"></a>Valor retornado

Na primeira sintaxe, um VectorIterator que referencia o elemento no deslocamento especificado do VectorIterator atual.

Na segunda sintaxe, um VectorIterator que referencia o elemento no deslocamento especificado do início do parâmetro `i`.

### <a name="remarks"></a>Comentários

O primeiro exemplo de sintaxe

## <a name="vectoriteratoroperator--operator"></a><a name="operator-minus-equals"></a>Operador VectorIterator:: Operator-=

Decrementa o VectorIterator atual pelo deslocamento especificado.

### <a name="syntax"></a>Sintaxe

```
VectorIterator& operator-=(difference_type n);
```

### <a name="parameters"></a>parâmetros

*n*<br/>
Um deslocamento de inteiro.

### <a name="return-value"></a>Valor retornado

O VectorIterator atualizado.

## <a name="vectoriteratoroperator"></a><a name="operator-at"></a>Operador VectorIterator::\[\]

Recupera uma referência ao elemento que é um deslocamento especificado de VectorIterator atual.

### <a name="syntax"></a>Sintaxe

```
reference operator[](difference_type n) const;
```

### <a name="parameters"></a>parâmetros

*n*<br/>
Um deslocamento de inteiro.

### <a name="return-value"></a>Valor retornado

O elemento que é deslocado pelos elementos `n` de VectorIterator atual.

## <a name="vectoriteratorvectoriterator-constructor"></a><a name="ctor"></a>Construtor VectorIterator:: VectorIterator

Inicializa uma nova instância da classe VectorIterator.

### <a name="syntax"></a>Sintaxe

```
VectorIterator();

explicit VectorIterator(
   Windows::Foundation::Collections::IVector<T>^ v);
```

### <a name="parameters"></a>parâmetros

*l*<br/>
Um \<T> objeto IVector.

### <a name="remarks"></a>Comentários

O primeiro exemplo de sintaxe é o construtor padrão. O segundo exemplo de sintaxe é um construtor explícito que é usado para construir um VectorIterator de um \<T> objeto IVector.

## <a name="see-also"></a>Confira também

[Namespace da plataforma](platform-namespace-c-cx.md)
