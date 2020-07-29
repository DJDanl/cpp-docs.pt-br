---
title: Classe Platform::Collections::VectorViewIterator
ms.date: 03/27/2019
ms.topic: reference
f1_keywords:
- COLLECTION/Platform::Collections::VectorViewIterator::VectorViewIterator
helpviewer_keywords:
- VectorViewIterator Class
ms.assetid: be3aa1ae-e6ba-4a06-8d6b-86d8128026f7
ms.openlocfilehash: 3fed25b975eefe33f9eb7014ca91a52ba419c936
ms.sourcegitcommit: 1f009ab0f2cc4a177f2d1353d5a38f164612bdb1
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 07/27/2020
ms.locfileid: "87211561"
---
# <a name="platformcollectionsvectorviewiterator-class"></a>Classe Platform::Collections::VectorViewIterator

Fornece um iterador de biblioteca de modelos padrão para objetos derivados da `IVectorView` interface Windows Runtime.

`ViewVectorIterator` é um iterador proxy que armazena elementos do tipo `VectorProxy<T>`. Entretanto, o objeto proxy quase nunca é visível ao código do usuário. Para obter mais informações, consulte [Coleções (C++/CX)](../cppcx/collections-c-cx.md).

## <a name="syntax"></a>Sintaxe

```
template <typename T>
class VectorViewIterator;
```

#### <a name="parameters"></a>parâmetros

*T*<br/>
O typename da classe de modelo de VectorViewIterator.

### <a name="members"></a>Membros

### <a name="public-typedefs"></a>Typedefs públicos

|Nome|Descrição|
|----------|-----------------|
|`difference_type`|Uma diferença de ponteiro (ptrdiff_t).|
|`iterator_category`|A categoria de um iterador de acesso aleatório (::std::random_access_iterator_tag).|
|`pointer`|Um ponteiro para um tipo interno que é necessário para a implementação de VectorViewIterator.|
|`reference`|Uma referência para um tipo interno que é necessário para a implementação de VectorViewIterator.|
|`value_type`|O typename `T` .|

### <a name="public-constructors"></a>Construtores públicos

|Nome|Descrição|
|----------|-----------------|
|[VectorViewIterator::VectorViewIterator](#ctor)|Inicializa uma nova instância da classe VectorViewIterator.|

### <a name="public-operators"></a>Operadores públicos

|Nome|Descrição|
|----------|-----------------|
|[Operador VectorViewIterator:: Operator](#operator-minus)|Subtrai um número especificado de elementos do iterador atual, gerando um novo iterador, ou um iterador especificado do iterador atual, gerando o número de elementos entre os iteradores.|
|[Operador VectorViewIterator:: Operator](#operator-decrement)|Decrementa o VectorViewIterator atual.|
|[Operador VectorViewIterator:: Operator! =](#operator-inequality)|Indica se o VectorViewIterator atual não é igual a um VectorViewIterator especificado.|
|[Operador VectorViewIterator:: Operator *](#operator-dereference)|Recupera uma referência ao elemento especificado pelo VectorViewIterator atual.|
|[Operador VectorViewIterator::\[\]](#operator-at)|Recupera uma referência ao elemento que é um deslocamento especificado de VectorViewIterator atual.|
|[Operador VectorViewIterator:: Operator +](#operator-plus)|Retorna um VectorViewIterator que referencia o elemento no deslocamento especificado do VectorViewIterator especificado.|
|[Operador VectorViewIterator:: Operator + +](#operator-increment)|Incrementa o VectorViewIterator atual.|
|[Operador VectorViewIterator:: Operator + =](#operator-plus-equals)|Incrementa o VectorViewIterator atual pelo deslocamento especificado.|
|[Operador VectorViewIterator:: Operator<](#operator-less-than)|Indica se o VectorViewIterator atual é menor que um VectorViewIterator especificado.|
|[Operador VectorViewIterator:: Operator \< =](#operator-less-than-or-equals)|Indica se o VectorViewIterator atual é menor ou igual a um VectorViewIterator especificado.|
|[Operador VectorViewIterator:: Operator-=](#operator-minus-assign)|Decrementa o VectorViewIterator atual pelo deslocamento especificado.|
|[Operador VectorViewIterator:: Operator = =](#operator-equality)|Indica se o VectorViewIterator atual é igual a um VectorViewIterator especificado.|
|[Operador VectorViewIterator:: Operator>](#operator-greater-than)|Indica se o VectorViewIterator atual é maior que um VectorViewIterator especificado.|
|[Operador VectorViewIterator::operator->](#operator-arrow)|Recupera o endereço do elemento referenciado pelo VectorViewIterator atual.|
|[Operador VectorViewIterator:: Operator>=](#operator-greater-than-or-equals)|Indica se o VectorViewIterator atual é maior ou igual a um VectorViewIterator especificado.|

## <a name="inheritance-hierarchy"></a>Hierarquia de herança

`VectorViewIterator`

### <a name="requirements"></a>Requisitos

**Cabeçalho:** collection.h

**Namespace:** Platform::Collections

## <a name="vectorviewiteratoroperator-gt-operator"></a><a name="operator-arrow"></a>Operador VectorViewIterator:: Operator &gt;

Recupera o endereço do elemento referenciado pelo VectorViewIterator atual.

### <a name="syntax"></a>Sintaxe

```
Detail::ArrowProxy<T> operator->() const;
```

### <a name="return-value"></a>Valor retornado

O valor do elemento que é referenciado pelo VectorViewIterator atual.

O tipo do valor retornado é um tipo interno não especificado que é necessário para a implementação desse operador.

## <a name="vectorviewiteratoroperator---operator"></a><a name="operator-decrement"></a>Operador VectorViewIterator:: Operator

Decrementa o VectorViewIterator atual.

### <a name="syntax"></a>Sintaxe

```
VectorViewIterator& operator--();
VectorViewIterator operator--(int);
```

### <a name="return-value"></a>Valor retornado

A primeira sintaxe diminui e, em seguida, retorna o VectorViewIterator atual. A segunda sintaxe retorna uma cópia do VectorViewIterator atual e, em seguida, diminui o VectorViewIterator atual.

### <a name="remarks"></a>Comentários

A primeira sintaxe de VectorViewIterator pré-diminui o VectorViewIterator atual.

A segunda sintaxe pós-diminui o VectorViewIterator atual. O **`int`** tipo na segunda sintaxe indica uma operação de pós-recuperação, não um operando de inteiro real.

## <a name="vectorviewiteratoroperator-operator"></a><a name="operator-dereference"></a>Operador VectorViewIterator:: Operator \*

Recupera uma referência ao elemento especificado pelo VectorViewIterator atual.

### <a name="syntax"></a>Sintaxe

```
reference operator*() const;
```

### <a name="return-value"></a>Valor retornado

O elemento especificado pelo VectorViewIterator atual.

## <a name="vectorviewiteratoroperator-operator"></a><a name="operator-equality"></a>Operador VectorViewIterator:: Operator = =

Indica se o VectorViewIterator atual é igual a um VectorViewIterator especificado.

### <a name="syntax"></a>Sintaxe

```
bool operator==(const VectorViewIterator& other) const;
```

### <a name="parameters"></a>parâmetros

*outros*<br/>
Outro VectorViewIterator.

### <a name="return-value"></a>Valor retornado

**`true`** Se o atual `VectorViewIterator` for igual a *outro*; caso contrário, **`false`** .

## <a name="vectorviewiteratoroperatorgt-operator"></a><a name="operator-greater-than"></a>Operador VectorViewIterator:: Operator &gt;

Indica se o VectorViewIterator atual é maior que um VectorViewIterator especificado.

### <a name="syntax"></a>Sintaxe

```

bool operator>(const VectorViewIterator& other) const;
```

### <a name="parameters"></a>parâmetros

*outros*<br/>
Outro VectorViewIterator.

### <a name="return-value"></a>Valor retornado

**`true`** Se o VectorViewIterator atual for maior que o *outro*; caso contrário, **`false`** .

## <a name="vectorviewiteratoroperatorgt-operator"></a><a name="operator-greater-than-or-equals"></a>Operador VectorViewIterator:: Operator &gt; =

Indica se o atual `VectorViewIterator` é maior ou igual ao especificado `VectorViewIterator` .

### <a name="syntax"></a>Sintaxe

```

bool operator>=(const VectorViewIterator& other) const;
```

### <a name="parameters"></a>parâmetros

*outros*<br/>
Outro VectorViewIterator.

### <a name="return-value"></a>Valor retornado

**`true`** Se o atual `VectorViewIterator` for maior ou igual a *outro*; caso contrário, **`false`** .

## <a name="vectorviewiteratoroperator-operator"></a><a name="operator-increment"></a>Operador VectorViewIterator:: Operator + +

Incrementa o VectorViewIterator atual.

### <a name="syntax"></a>Sintaxe

```

VectorViewIterator& operator++();
VectorViewIterator operator++(int);
```

### <a name="return-value"></a>Valor retornado

A primeira sintaxe incrementa e, em seguida, retorna o VectorViewIterator atual. A segunda sintaxe retorna uma cópia de VectorViewIterator atual e, em seguida, incrementa o VectorViewIterator atual.

### <a name="remarks"></a>Comentários

A primeira sintaxe de VectorViewIterator pré-incrementa o VectorViewIterator atual.

A segunda sintaxe pós-incrementa o VectorViewIterator atual. O **`int`** tipo na segunda sintaxe indica uma operação de incremento, não um operando de inteiro real.

## <a name="vectorviewiteratoroperator-operator"></a><a name="operator-inequality"></a>Operador VectorViewIterator:: Operator! =

Indica se o VectorViewIterator atual não é igual a um VectorViewIterator especificado.

### <a name="syntax"></a>Sintaxe

```
bool operator!=(const VectorViewIterator& other) const;
```

### <a name="parameters"></a>parâmetros

*outros*<br/>
Outro VectorViewIterator.

### <a name="return-value"></a>Valor retornado

**`true`** Se o atual `VectorViewIterator` não for igual a *outro*; caso contrário, **`false`** .

## <a name="vectorviewiteratoroperatorlt-operator"></a><a name="operator-less-than"></a>Operador VectorViewIterator:: Operator &lt;

Indica se o VectorIterator atual é menor que um VectorIterator especificado.

### <a name="syntax"></a>Sintaxe

```
bool operator<(const VectorViewIterator& other) const;
```

### <a name="parameters"></a>parâmetros

*outros*<br/>
Outro `VectorIterator`.

### <a name="return-value"></a>Valor retornado

**`true`** Se o atual `VectorIterator` for menor do que o *outro*; caso contrário, **`false`** .

## <a name="vectorviewiteratoroperatorlt-operator"></a><a name="operator-less-than-or-equals"></a>Operador VectorViewIterator:: Operator &lt; =

Indica se o atual `VectorIterator` é menor ou igual a um especificado `VectorIterator` .

### <a name="syntax"></a>Sintaxe

```

bool operator<=(const VectorViewIterator& other) const;
```

### <a name="parameters"></a>parâmetros

*outros*<br/>
Outro `VectorIterator`.

### <a name="return-value"></a>Valor retornado

**`true`** Se o atual `VectorIterator` for menor ou igual a *outro*; caso contrário, **`false`** .

## <a name="vectorviewiteratoroperator--operator"></a><a name="operator-minus"></a>Operador VectorViewIterator:: Operator

Subtrai um número especificado de elementos do iterador atual, gerando um novo iterador, ou um iterador especificado do iterador atual, gerando o número de elementos entre os iteradores.

### <a name="syntax"></a>Sintaxe

```

VectorViewIterator operator-(difference_type n) const;

difference_type operator-(const VectorViewIterator& other) const;
```

### <a name="parameters"></a>parâmetros

*n*<br/>
Um número de elementos.

*outros*<br/>
Outro VectorViewIterator.

### <a name="return-value"></a>Valor retornado

A primeira sintaxe do operador retorna um objeto VectorViewIterator que corresponde a `n` elementos menos o VectorViewIterator atual. A segunda sintaxe do operador retorna o número de elementos entre o VectorViewIterator atual e `other`.

## <a name="vectorviewiteratoroperator-operator"></a><a name="operator-plus-equals"></a>Operador VectorViewIterator:: Operator + =

Incrementa o VectorViewIterator atual pelo deslocamento especificado.

### <a name="syntax"></a>Sintaxe

```
VectorViewIterator& operator+=(difference_type n);
```

### <a name="parameters"></a>parâmetros

*n*<br/>
Um deslocamento de inteiro.

### <a name="return-value"></a>Valor retornado

O VectorViewIterator atualizado.

## <a name="vectorviewiteratoroperator-operator"></a><a name="operator-plus"></a>Operador VectorViewIterator:: Operator +

Retorna um VectorViewIterator que referencia o elemento no deslocamento especificado do VectorViewIterator especificado.

### <a name="syntax"></a>Sintaxe

```

VectorViewIterator operator+(difference_type n) const;

template <typename T>
inline VectorViewIterator<T> operator+
   (ptrdiff_t n,
   const VectorViewIterator<T>& i);
```

### <a name="parameters"></a>parâmetros

*T*<br/>
Na segunda sintaxe, o typename de VectorViewIterator.

*n*<br/>
Um deslocamento de inteiro.

*i*<br/>
Na segunda sintaxe, um VectorViewIterator.

### <a name="return-value"></a>Valor retornado

Na primeira sintaxe, um VectorViewIterator que referencia o elemento no deslocamento especificado do VectorViewIterator atual.

Na segunda sintaxe, um VectorViewIterator que referencia o elemento no deslocamento especificado do início do parâmetro `i`.

## <a name="vectorviewiteratoroperator--operator"></a><a name="operator-minus-assign"></a>Operador VectorViewIterator:: Operator-=

Decrementa o VectorIterator atual pelo deslocamento especificado.

### <a name="syntax"></a>Sintaxe

```
VectorViewIterator& operator-=(difference_type n);
```

### <a name="parameters"></a>parâmetros

*n*<br/>
Um deslocamento de inteiro.

### <a name="return-value"></a>Valor retornado

O VectorIterator atualizado.

## <a name="vectorviewiteratoroperator"></a><a name="operator-at"></a>Operador VectorViewIterator::\[\]

Recupera uma referência ao elemento que é um deslocamento especificado de VectorViewIterator atual.

### <a name="syntax"></a>Sintaxe

```
reference operator[](difference_type n) const;
```

### <a name="parameters"></a>parâmetros

*n*<br/>
Um deslocamento de inteiro.

### <a name="return-value"></a>Valor retornado

O elemento que é deslocado pelos elementos `n` de VectorViewIterator atual.

## <a name="vectorviewiteratorvectorviewiterator-constructor"></a><a name="ctor"></a>Construtor VectorViewIterator:: VectorViewIterator

Inicializa uma nova instância da classe VectorViewIterator.

### <a name="syntax"></a>Sintaxe

```

VectorViewIterator();

explicit VectorViewIterator(
   Windows::Foundation::Collections::IVectorView<T>^ v
);
```

### <a name="parameters"></a>parâmetros

*l*<br/>
Um \<T> objeto IVectorView.

### <a name="remarks"></a>Comentários

O primeiro exemplo de sintaxe é o construtor padrão. O segundo exemplo de sintaxe é um construtor explícito que é usado para construir um VectorViewIterator de um \<T> objeto IVectorView.

## <a name="see-also"></a>Confira também

[Namespace da plataforma](platform-namespace-c-cx.md)
