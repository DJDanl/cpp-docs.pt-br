---
title: Classe Platform::Collections::VectorViewIterator
ms.date: 03/27/2019
ms.topic: reference
f1_keywords:
- COLLECTION/Platform::Collections::VectorViewIterator::VectorViewIterator
helpviewer_keywords:
- VectorViewIterator Class
ms.assetid: be3aa1ae-e6ba-4a06-8d6b-86d8128026f7
ms.openlocfilehash: 01ae4286e996db9819cb697360f6de9c344edd21
ms.sourcegitcommit: c123cc76bb2b6c5cde6f4c425ece420ac733bf70
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/14/2020
ms.locfileid: "81363705"
---
# <a name="platformcollectionsvectorviewiterator-class"></a>Classe Platform::Collections::VectorViewIterator

Fornece um iterador de biblioteca de modelopadrão`IVectorView` para objetos derivados da interface Executar tempo de execução do Windows.

`ViewVectorIterator` é um iterador proxy que armazena elementos do tipo `VectorProxy<T>`. Entretanto, o objeto proxy quase nunca é visível ao código do usuário. Para obter mais informações, consulte [Coleções (C++/CX)](../cppcx/collections-c-cx.md).

## <a name="syntax"></a>Sintaxe

```
template <typename T>
class VectorViewIterator;
```

#### <a name="parameters"></a>Parâmetros

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
|[VectorViewIterator::operador- Operador](#operator-minus)|Subtrai um número especificado de elementos do iterador atual, gerando um novo iterador, ou um iterador especificado do iterador atual, gerando o número de elementos entre os iteradores.|
|[VectorViewIterator::operador-- Operador](#operator-decrement)|Decrementa o VectorViewIterator atual.|
|[VectorViewIterator::operador!= Operador](#operator-inequality)|Indica se o VectorViewIterator atual não é igual a um VectorViewIterator especificado.|
|[Ativador de vectorView::operador* Operador](#operator-dereference)|Recupera uma referência ao elemento especificado pelo VectorViewIterator atual.|
|[Orteridor VectorViewIterator::operador\[\]](#operator-at)|Recupera uma referência ao elemento que é um deslocamento especificado de VectorViewIterator atual.|
|[VectorViewIterator::operador+ operador](#operator-plus)|Retorna um VectorViewIterator que referencia o elemento no deslocamento especificado do VectorViewIterator especificado.|
|[VectorViewIterator::operador++ Operador](#operator-increment)|Incrementa o VectorViewIterator atual.|
|[VectorViewIterator::operador+= Operador](#operator-plus-equals)|Incrementa o VectorViewIterator atual pelo deslocamento especificado.|
|[VectorViewIterator::operador de<](#operator-less-than)|Indica se o VectorViewIterator atual é menor que um VectorViewIterator especificado.|
|[Orteridor VectorViewIterator::operador\<= Operador](#operator-less-than-or-equals)|Indica se o VectorViewIterator atual é menor ou igual a um VectorViewIterator especificado.|
|[Ativador vectorViewIterator::operador-= Operador](#operator-minus-assign)|Decrementa o VectorViewIterator atual pelo deslocamento especificado.|
|[Ordenador::operador== Operador](#operator-equality)|Indica se o VectorViewIterator atual é igual a um VectorViewIterator especificado.|
|[VectorViewIterator::operador de>](#operator-greater-than)|Indica se o VectorViewIterator atual é maior que um VectorViewIterator especificado.|
|[Operador VectorViewIterator::operator->](#operator-arrow)|Recupera o endereço do elemento referenciado pelo VectorViewIterator atual.|
|[Ordenador::operador>= Operador](#operator-greater-than-or-equals)|Indica se o VectorViewIterator atual é maior ou igual a um VectorViewIterator especificado.|

## <a name="inheritance-hierarchy"></a>Hierarquia de herança

`VectorViewIterator`

### <a name="requirements"></a>Requisitos

**Cabeçalho:** collection.h

**Namespace:** Platform::Collections

## <a name="vectorviewiteratoroperator-gt-operator"></a><a name="operator-arrow"></a>VectorViewIterator::operador-&gt; Operador

Recupera o endereço do elemento referenciado pelo VectorViewIterator atual.

### <a name="syntax"></a>Sintaxe

```
Detail::ArrowProxy<T> operator->() const;
```

### <a name="return-value"></a>Valor retornado

O valor do elemento que é referenciado pelo VectorViewIterator atual.

O tipo do valor retornado é um tipo interno não especificado que é necessário para a implementação desse operador.

## <a name="vectorviewiteratoroperator---operator"></a><a name="operator-decrement"></a>VectorViewIterator::operador-- Operador

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

A segunda sintaxe pós-diminui o VectorViewIterator atual. O tipo `int` na segunda sintaxe indica uma operação de pós-diminuição, não um operando de inteiro real.

## <a name="vectorviewiteratoroperator-operator"></a><a name="operator-dereference"></a>Orteridor VectorViewIterator::operador\*

Recupera uma referência ao elemento especificado pelo VectorViewIterator atual.

### <a name="syntax"></a>Sintaxe

```
reference operator*() const;
```

### <a name="return-value"></a>Valor retornado

O elemento especificado pelo VectorViewIterator atual.

## <a name="vectorviewiteratoroperator-operator"></a><a name="operator-equality"></a>Ordenador::operador== Operador

Indica se o VectorViewIterator atual é igual a um VectorViewIterator especificado.

### <a name="syntax"></a>Sintaxe

```
bool operator==(const VectorViewIterator& other) const;
```

### <a name="parameters"></a>Parâmetros

*Outros*<br/>
Outro VectorViewIterator.

### <a name="return-value"></a>Valor retornado

**verdade** se `VectorViewIterator` a corrente é igual a *outra;* caso contrário, **falso**.

## <a name="vectorviewiteratoroperatorgt-operator"></a><a name="operator-greater-than"></a>Orteridor VectorViewIterator::operador&gt;

Indica se o VectorViewIterator atual é maior que um VectorViewIterator especificado.

### <a name="syntax"></a>Sintaxe

```

bool operator>(const VectorViewIterator& other) const;
```

### <a name="parameters"></a>Parâmetros

*Outros*<br/>
Outro VectorViewIterator.

### <a name="return-value"></a>Valor retornado

**verdade** se o vectorViewIterator atual for maior do que *outros;* caso contrário, **falso**.

## <a name="vectorviewiteratoroperatorgt-operator"></a><a name="operator-greater-than-or-equals"></a>Orteridor VectorViewIterator::operador&gt;= Operador

Indica se `VectorViewIterator` a corrente é maior ou `VectorViewIterator`igual à especificada .

### <a name="syntax"></a>Sintaxe

```

bool operator>=(const VectorViewIterator& other) const;
```

### <a name="parameters"></a>Parâmetros

*Outros*<br/>
Outro VectorViewIterator.

### <a name="return-value"></a>Valor retornado

**verdade** se `VectorViewIterator` a corrente é maior ou igual a *outra;* caso contrário, **falso**.

## <a name="vectorviewiteratoroperator-operator"></a><a name="operator-increment"></a>VectorViewIterator::operador++ Operador

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

A segunda sintaxe pós-incrementa o VectorViewIterator atual. O tipo `int` na segunda sintaxe indica uma operação de pós-incremento, não um operando de inteiro real.

## <a name="vectorviewiteratoroperator-operator"></a><a name="operator-inequality"></a>VectorViewIterator::operador!= Operador

Indica se o VectorViewIterator atual não é igual a um VectorViewIterator especificado.

### <a name="syntax"></a>Sintaxe

```
bool operator!=(const VectorViewIterator& other) const;
```

### <a name="parameters"></a>Parâmetros

*Outros*<br/>
Outro VectorViewIterator.

### <a name="return-value"></a>Valor retornado

**verdade** se `VectorViewIterator` a corrente não é igual a *outra;* caso contrário, **falso**.

## <a name="vectorviewiteratoroperatorlt-operator"></a><a name="operator-less-than"></a>Orteridor VectorViewIterator::operador&lt;

Indica se o VectorIterator atual é menor que um VectorIterator especificado.

### <a name="syntax"></a>Sintaxe

```
bool operator<(const VectorViewIterator& other) const;
```

### <a name="parameters"></a>Parâmetros

*Outros*<br/>
Outro `VectorIterator`.

### <a name="return-value"></a>Valor retornado

**verdade** se `VectorIterator` a corrente é menor do que *outra;* caso contrário, **falso**.

## <a name="vectorviewiteratoroperatorlt-operator"></a><a name="operator-less-than-or-equals"></a>Orteridor VectorViewIterator::operador&lt;= Operador

Indica se `VectorIterator` a corrente é menor ou `VectorIterator`igual a uma especificada .

### <a name="syntax"></a>Sintaxe

```

bool operator<=(const VectorViewIterator& other) const;
```

### <a name="parameters"></a>Parâmetros

*Outros*<br/>
Outro `VectorIterator`.

### <a name="return-value"></a>Valor retornado

**verdade** se `VectorIterator` a corrente é menor ou igual a *outra;* caso contrário, **falso**.

## <a name="vectorviewiteratoroperator--operator"></a><a name="operator-minus"></a>VectorViewIterator::operador- Operador

Subtrai um número especificado de elementos do iterador atual, gerando um novo iterador, ou um iterador especificado do iterador atual, gerando o número de elementos entre os iteradores.

### <a name="syntax"></a>Sintaxe

```

VectorViewIterator operator-(difference_type n) const;

difference_type operator-(const VectorViewIterator& other) const;
```

### <a name="parameters"></a>Parâmetros

*n*<br/>
Um número de elementos.

*Outros*<br/>
Outro VectorViewIterator.

### <a name="return-value"></a>Valor retornado

A primeira sintaxe do operador retorna um objeto VectorViewIterator que corresponde a `n` elementos menos o VectorViewIterator atual. A segunda sintaxe do operador retorna o número de elementos entre o VectorViewIterator atual e `other`.

## <a name="vectorviewiteratoroperator-operator"></a><a name="operator-plus-equals"></a>VectorViewIterator::operador+= Operador

Incrementa o VectorViewIterator atual pelo deslocamento especificado.

### <a name="syntax"></a>Sintaxe

```
VectorViewIterator& operator+=(difference_type n);
```

### <a name="parameters"></a>Parâmetros

*n*<br/>
Um deslocamento de inteiro.

### <a name="return-value"></a>Valor retornado

O VectorViewIterator atualizado.

## <a name="vectorviewiteratoroperator-operator"></a><a name="operator-plus"></a>VectorViewIterator::operador+ operador

Retorna um VectorViewIterator que referencia o elemento no deslocamento especificado do VectorViewIterator especificado.

### <a name="syntax"></a>Sintaxe

```

VectorViewIterator operator+(difference_type n) const;

template <typename T>
inline VectorViewIterator<T> operator+
   (ptrdiff_t n,
   const VectorViewIterator<T>& i);
```

### <a name="parameters"></a>Parâmetros

*T*<br/>
Na segunda sintaxe, o typename de VectorViewIterator.

*n*<br/>
Um deslocamento de inteiro.

*Eu*<br/>
Na segunda sintaxe, um VectorViewIterator.

### <a name="return-value"></a>Valor retornado

Na primeira sintaxe, um VectorViewIterator que referencia o elemento no deslocamento especificado do VectorViewIterator atual.

Na segunda sintaxe, um VectorViewIterator que referencia o elemento no deslocamento especificado do início do parâmetro `i`.

## <a name="vectorviewiteratoroperator--operator"></a><a name="operator-minus-assign"></a>Ativador vectorViewIterator::operador-= Operador

Decrementa o VectorIterator atual pelo deslocamento especificado.

### <a name="syntax"></a>Sintaxe

```
VectorViewIterator& operator-=(difference_type n);
```

### <a name="parameters"></a>Parâmetros

*n*<br/>
Um deslocamento de inteiro.

### <a name="return-value"></a>Valor retornado

O VectorIterator atualizado.

## <a name="vectorviewiteratoroperator"></a><a name="operator-at"></a>Orteridor VectorViewIterator::operador\[\]

Recupera uma referência ao elemento que é um deslocamento especificado de VectorViewIterator atual.

### <a name="syntax"></a>Sintaxe

```
reference operator[](difference_type n) const;
```

### <a name="parameters"></a>Parâmetros

*n*<br/>
Um deslocamento de inteiro.

### <a name="return-value"></a>Valor retornado

O elemento que é deslocado pelos elementos `n` de VectorViewIterator atual.

## <a name="vectorviewiteratorvectorviewiterator-constructor"></a><a name="ctor"></a>Orterizador VectorViewIterator::Construtor vectorViewIterator

Inicializa uma nova instância da classe VectorViewIterator.

### <a name="syntax"></a>Sintaxe

```

VectorViewIterator();

explicit VectorViewIterator(
   Windows::Foundation::Collections::IVectorView<T>^ v
);
```

### <a name="parameters"></a>Parâmetros

*V*<br/>
Um objeto\<IVectorView T>.

### <a name="remarks"></a>Comentários

O primeiro exemplo de sintaxe é o construtor padrão. O segundo exemplo de sintaxe é um construtor explícito que é usado\<para construir um VectorViewIterator a partir de um objeto iVectorView T>.

## <a name="see-also"></a>Confira também

[Espaço de nome da plataforma](platform-namespace-c-cx.md)
