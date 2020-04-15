---
title: Classe Platform::Collections::VectorIterator
ms.date: 03/27/2019
ms.topic: reference
f1_keywords:
- COLLECTION/Platform::Collections::VectorIterator::VectorIterator
helpviewer_keywords:
- VectorIterator Class
ms.assetid: d531cb42-27e0-48a6-bf5e-c265891a18ff
ms.openlocfilehash: e649027c2ba3f637c42765af691f4d321913fb28
ms.sourcegitcommit: c123cc76bb2b6c5cde6f4c425ece420ac733bf70
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/14/2020
ms.locfileid: "81354361"
---
# <a name="platformcollectionsvectoriterator-class"></a>Classe Platform::Collections::VectorIterator

Fornece um iterador de biblioteca de modelopadrão para objetos derivados da interface IVector do Windows Runtime.

VectorIterator é um ativador proxy que armazena\<elementos do tipo VectorProxy T>. Entretanto, o objeto proxy quase nunca é visível ao código do usuário. Para obter mais informações, consulte [Coleções (C++/CX)](../cppcx/collections-c-cx.md).

## <a name="syntax"></a>Sintaxe

```
template <typename T>
class VectorIterator;
```

#### <a name="parameters"></a>Parâmetros

*T*<br/>
O typename da classe de modelo de VectorIterator.

### <a name="members"></a>Membros

### <a name="public-typedefs"></a>Typedefs públicos

|Nome|Descrição|
|----------|-----------------|
|`difference_type`|Uma diferença de ponteiro (ptrdiff_t).|
|`iterator_category`|A categoria de um iterador de acesso aleatório (::std::random_access_iterator_tag).|
|`pointer`|Um ponteiro para um tipo interno, Plataforma::Coleções::Details::VectorProxy\<T>, que é necessário para a implementação do VectorIterator.|
|`reference`|Uma referência a um tipo interno, Plataforma::Coleções::Details::VectorProxy\<T>,, que é necessária para a implementação do VectorIterator.|
|`value_type`|O typename `T` .|

### <a name="public-constructors"></a>Construtores públicos

|Nome|Descrição|
|----------|-----------------|
|[Iterator vetorial::VetorIterator](#ctor)|Inicializa uma nova instância da classe VectorIterator.|

### <a name="public-operators"></a>Operadores públicos

|Nome|Descrição|
|----------|-----------------|
|[Iterterizador vetorial::operador - Operador](#operator-minus)|Subtrai um número especificado de elementos do iterador atual, gerando um novo iterador, ou um iterador especificado do iterador atual, gerando o número de elementos entre os iteradores.|
|[Vetor::operador-- Operador](#operator-decrement)|Decrementa o VectorIterator atual.|
|[Ativador vetorial::operador!= Operador](#operator-inequality)|Indica se o VectorIterator atual não é igual a um VectorIterator especificado.|
|[Ativador vetorial::operador* Operador](#operator-dereference)|Recupera uma referência ao elemento especificado pelo VectorIterator atual.|
|[Iterterizador vetorial::operador\[\]](#operator-at)|Recupera uma referência ao elemento que é um deslocamento especificado de VectorIterator atual.|
|[Ativador vetorial::operador+ operador](#operator-plus)|Retorna um VectorIterator que referencia o elemento no deslocamento especificado do VectorIterator especificado.|
|[Ativador vetorial::operador++ operador](#operator-increment)|Incrementa o VectorIterator atual.|
|[Ativador vetorial::operador+= Operador](#operator-plus-assign)|Incrementa o VectorIterator atual pelo deslocamento especificado.|
|[Ativador vetorial::operador de<](#operator-less-than)|Indica se o VectorIterator atual é menor que um VectorIterator especificado.|
|[Iterterizador vetorial::operador\<= Operador](#operator-less-than-or-equals)|Indica se o VectorIterator atual é menor ou igual a um VectorIterator especificado.|
|[Operador VectorIterator::operator-=](#operator-minus-equals)|Decrementa o VectorIterator atual pelo deslocamento especificado.|
|[Iterterizador vetorial::operador== Operador](#operator-equality)|Indica se o VectorIterator atual é igual a um VectorIterator especificado.|
|[Ativador vetorial::operador de>](#operator-greater-than)|Indica se o VectorIterator atual é maior que um VectorIterator especificado.|
|[Ativador vetorial::operador de > de operador](#operator-arrow)|Recupera o endereço do elemento referenciado pelo VectorIterator atual.|
|[Iterterizador vetorial::operador>= Operador](#operator-greater-than-or-equals)|Indica se o VectorIterator atual é maior ou igual a um VectorIterator especificado.|

## <a name="inheritance-hierarchy"></a>Hierarquia de herança

`VectorIterator`

### <a name="requirements"></a>Requisitos

**Cabeçalho:** collection.h

**Namespace:** Platform::Collections

## <a name="vectoriteratoroperator-gt-operator"></a><a name="operator-arrow"></a>Iterterizador vetorial::operador -&gt; Operador

Recupera o endereço do elemento referenciado pelo VectorIterator atual.

### <a name="syntax"></a>Sintaxe

```
Detail::ArrowProxy<T> operator->() const;
```

### <a name="return-value"></a>Valor retornado

O valor do elemento que é referenciado pelo VectorIterator atual.

O tipo do valor retornado é um tipo interno não especificado que é necessário para a implementação desse operador.

## <a name="vectoriteratoroperator---operator"></a><a name="operator-decrement"></a>Vetor::operador-- Operador

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

A segunda sintaxe pós-diminui o VectorIterator atual. O tipo `int` na segunda sintaxe indica uma operação de pós-diminuição, não um operando de inteiro real.

## <a name="vectoriteratoroperator-operator"></a><a name="operator-dereference"></a>Iterizador vetorial::operador\* operador

Recupera o endereço do elemento especificado pelo VectorIterator atual.

### <a name="syntax"></a>Sintaxe

```
reference operator*() const;
```

### <a name="return-value"></a>Valor retornado

O elemento especificado pelo VectorIterator atual.

## <a name="vectoriteratoroperator-operator"></a><a name="operator-equality"></a>Iterterizador vetorial::operador== Operador

Indica se o VectorIterator atual é igual a um VectorIterator especificado.

### <a name="syntax"></a>Sintaxe

```
bool operator==(const VectorIterator& other) const;
```

### <a name="parameters"></a>Parâmetros

*Outros*<br/>
Outro VectorIterator.

### <a name="return-value"></a>Valor retornado

**verdade** se o vetor atual for igual a *outro;* caso contrário, **falso**.

## <a name="vectoriteratoroperatorgt-operator"></a><a name="operator-greater-than"></a>Iterizador vetorial::operador&gt; operador

Indica se o VectorIterator atual é maior que um VectorIterator especificado.

### <a name="syntax"></a>Sintaxe

```cpp
bool operator>(const VectorIterator& other) const
```

### <a name="parameters"></a>Parâmetros

*Outros*<br/>
Outro VectorIterator.

### <a name="return-value"></a>Valor retornado

**verdade** se o vetor atual for maior do que *outros;* caso contrário, **falso**.

## <a name="vectoriteratoroperatorgt-operator"></a><a name="operator-greater-than-or-equals"></a>Iterterizador vetorial::operador&gt;= Operador

Indica se o VectorIterator atual é maior ou igual ao VectorIterator especificado.

### <a name="syntax"></a>Sintaxe

```cpp
bool operator>=(const VectorIterator& other) const
```

### <a name="parameters"></a>Parâmetros

*Outros*<br/>
Outro VectorIterator.

### <a name="return-value"></a>Valor retornado

**verdade** se o vetor atual for maior ou igual a *outro;* caso contrário, **falso**.

## <a name="vectoriteratoroperator-operator"></a><a name="operator-increment"></a>Ativador vetorial::operador++ operador

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

A segunda sintaxe pós-incrementa o VectorIterator atual. O tipo `int` na segunda sintaxe indica uma operação de pós-incremento, não um operando de inteiro real.

## <a name="vectoriteratoroperator-operator"></a><a name="operator-inequality"></a>Ativador vetorial::operador!= Operador

Indica se o VectorIterator atual não é igual a um VectorIterator especificado.

### <a name="syntax"></a>Sintaxe

```
bool operator!=(const VectorIterator& other) const;
```

### <a name="parameters"></a>Parâmetros

*Outros*<br/>
Outro VectorIterator.

### <a name="return-value"></a>Valor retornado

**verdade** se o vetor atual não for igual a *outro;* caso contrário, **falso**.

## <a name="vectoriteratoroperatorlt-operator"></a><a name="operator-less-than"></a>Iterizador vetorial::operador&lt; operador

Indica se o VectorIterator atual é menor que um VectorIterator especificado.

### <a name="syntax"></a>Sintaxe

```cpp
bool operator<(const VectorIterator& other) const
```

### <a name="parameters"></a>Parâmetros

*Outros*<br/>
Outro VectorIterator.

### <a name="return-value"></a>Valor retornado

**verdade** se o vetor atual for menor do que *outros;* caso contrário, **falso**.

## <a name="vectoriteratoroperatorlt-operator"></a><a name="operator-less-than-or-equals"></a>Iterterizador vetorial::operador&lt;= Operador

Indica se o VectorIterator atual é menor ou igual a um VectorIterator especificado.

### <a name="syntax"></a>Sintaxe

```cpp
bool operator<=(const VectorIterator& other) const
```

### <a name="parameters"></a>Parâmetros

*Outros*<br/>
Outro VectorIterator.

### <a name="return-value"></a>Valor retornado

**verdade** se o vetor atual for menor ou igual a *outro;* caso contrário, **falso**.

## <a name="vectoriteratoroperator--operator"></a><a name="operator-minus"></a>Iterterizador vetorial::operador - Operador

Subtrai um número especificado de elementos do iterador atual, gerando um novo iterador, ou um iterador especificado do iterador atual, gerando o número de elementos entre os iteradores.

### <a name="syntax"></a>Sintaxe

```

VectorIterator operator-(difference_type n) const;

difference_type operator-(const VectorIterator& other) const;
```

### <a name="parameters"></a>Parâmetros

*n*<br/>
Um número de elementos.

*Outros*<br/>
Outro VectorIterator.

### <a name="return-value"></a>Valor retornado

A primeira sintaxe do operador retorna um objeto VectorIterator que corresponde a elementos `n`, menos o VectorIterator atual. A segunda sintaxe do operador retorna o número de elementos entre o VectorIterator atual e `other`.

## <a name="vectoriteratoroperator-operator"></a><a name="operator-plus-assign"></a>Ativador vetorial::operador+= Operador

Incrementa o VectorIterator atual pelo deslocamento especificado.

### <a name="syntax"></a>Sintaxe

```
VectorIterator& operator+=(difference_type n);
```

### <a name="parameters"></a>Parâmetros

*n*<br/>
Um deslocamento de inteiro.

### <a name="return-value"></a>Valor retornado

O VectorIterator atualizado.

## <a name="vectoriteratoroperator-operator"></a><a name="operator-plus"></a>Ativador vetorial::operador+ operador

Retorna um VectorIterator que referencia o elemento no deslocamento especificado do VectorIterator especificado.

### <a name="syntax"></a>Sintaxe

```

VectorIterator operator+(difference_type n);

template <typename T>
inline VectorIterator<T> operator+(
  ptrdiff_t n,
  const VectorIterator<T>& i);
```

### <a name="parameters"></a>Parâmetros

*T*<br/>
Na segunda sintaxe, o typename de VectorIterator.

*n*<br/>
Um deslocamento de inteiro.

*Eu*<br/>
Na segunda sintaxe, um VectorIterator.

### <a name="return-value"></a>Valor retornado

Na primeira sintaxe, um VectorIterator que referencia o elemento no deslocamento especificado do VectorIterator atual.

Na segunda sintaxe, um VectorIterator que referencia o elemento no deslocamento especificado do início do parâmetro `i`.

### <a name="remarks"></a>Comentários

O primeiro exemplo de sintaxe

## <a name="vectoriteratoroperator--operator"></a><a name="operator-minus-equals"></a>Ativador vetorial::operador-= Operador

Decrementa o VectorIterator atual pelo deslocamento especificado.

### <a name="syntax"></a>Sintaxe

```
VectorIterator& operator-=(difference_type n);
```

### <a name="parameters"></a>Parâmetros

*n*<br/>
Um deslocamento de inteiro.

### <a name="return-value"></a>Valor retornado

O VectorIterator atualizado.

## <a name="vectoriteratoroperator"></a><a name="operator-at"></a>Iterterizador vetorial::operador\[\]

Recupera uma referência ao elemento que é um deslocamento especificado de VectorIterator atual.

### <a name="syntax"></a>Sintaxe

```
reference operator[](difference_type n) const;
```

### <a name="parameters"></a>Parâmetros

*n*<br/>
Um deslocamento de inteiro.

### <a name="return-value"></a>Valor retornado

O elemento que é deslocado pelos elementos `n` de VectorIterator atual.

## <a name="vectoriteratorvectoriterator-constructor"></a><a name="ctor"></a>Vetor::Construtor vetorial

Inicializa uma nova instância da classe VectorIterator.

### <a name="syntax"></a>Sintaxe

```
VectorIterator();

explicit VectorIterator(
   Windows::Foundation::Collections::IVector<T>^ v);
```

### <a name="parameters"></a>Parâmetros

*V*<br/>
Um objeto\<iVector T>.

### <a name="remarks"></a>Comentários

O primeiro exemplo de sintaxe é o construtor padrão. O segundo exemplo de sintaxe é um construtor explícito que é\<usado para construir um VectorIterator a partir de um objeto IVector T>.

## <a name="see-also"></a>Confira também

[Espaço de nome da plataforma](platform-namespace-c-cx.md)
