---
title: Classe Platform::Collections::InputIterator
ms.date: 03/27/2019
ms.topic: reference
f1_keywords:
- COLLECTION/Platform::Collections::InputIterator::InputIterator
helpviewer_keywords:
- InputIterator Class
ms.assetid: ef72eea4-32a9-42b9-8119-ce87dbdcd3be
ms.openlocfilehash: 49b131b01fe3d9cad5f8366fd4cc0c110b5d060c
ms.sourcegitcommit: 0ab61bc3d2b6cfbd52a16c6ab2b97a8ea1864f12
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/23/2019
ms.locfileid: "62161791"
---
# <a name="platformcollectionsinputiterator-class"></a>Classe Platform::Collections::InputIterator

Fornece um InputIterator da biblioteca de modelo padrão para coleções derivadas o tempo de execução do Windows.

## <a name="syntax"></a>Sintaxe

```
template <typename X>
class InputIterator;
```

#### <a name="parameters"></a>Parâmetros

*X*<br/>
O typename da classe de modelo de InputIterator.

### <a name="members"></a>Membros

### <a name="public-typedefs"></a>Typedefs públicos

|Nome|Descrição|
|----------|-----------------|
|`difference_type`|Uma diferença de ponteiro (ptrdiff_t).|
|`iterator_category`|A categoria de um iterador de entrada (::std::input_iterator_tag).|
|`pointer`|Um ponteiro para um `const X`|
|`reference`|Uma referência a um `const X`|
|`value_type`|O typename `X` .|

### <a name="public-constructors"></a>Construtores públicos

|Nome|Descrição|
|----------|-----------------|
|[InputIterator::InputIterator](#ctor)|Inicializa uma nova instância da classe InputIterator.|

### <a name="public-operators"></a>Operadores públicos

|Nome|Descrição|
|----------|-----------------|
|[Operador InputIterator::operator!=](#operator-inequality)|Indica se o InputIterator atual não é igual a um InputIterator especificado.|
|[Operador InputIterator::operator*](#operator-dereference)|Recupera uma referência ao elemento especificado pelo InputIterator atual.|
|[Operador InputIterator::operator++](#operator-increment)|Incrementa o InputIterator atual.|
|[Operador InputIterator::operator==](#operator-equality)|Indica se o InputIterator atual é igual a um InputIterator especificado.|
|[Operador InputIterator::operator->](#operator-arrow)|Recupera o endereço do elemento referenciado pelo InputIterator atual.|

## <a name="inheritance-hierarchy"></a>Hierarquia de herança

`InputIterator`

### <a name="requirements"></a>Requisitos

**Cabeçalho:** collection.h

**Namespace:** Platform::Collections

## <a name="ctor"></a>  Construtor inputiterator:: Inputiterator

Inicializa uma nova instância da classe InputIterator.

### <a name="syntax"></a>Sintaxe

```
InputIterator();
explicit InputIterator(Windows::Foundation::Collections<X>^ iterator);
```

### <a name="parameters"></a>Parâmetros

*iterator*<br/>
Um objeto do iterador.

## <a name="operator-arrow"></a>  Operador inputiterator:: -&gt; operador

Recupera o endereço do elemento especificado pelo InputIterator atual.

### <a name="syntax"></a>Sintaxe

```
pointer operator->() const;
```

### <a name="return-value"></a>Valor de retorno

O endereço do elemento especificado pelo InputIterator atual.

## <a name="operator-dereference"></a>  Operador inputiterator::\* operador

Recupera uma referência ao elemento especificado pelo InputIterator atual.

### <a name="syntax"></a>Sintaxe

```
reference operator*() const;
```

### <a name="return-value"></a>Valor de retorno

O elemento especificado pelo InputIterator atual.

## <a name="operator-equality"></a>  Operador inputiterator:: Operator = =

Indica se o InputIterator atual é igual a um InputIterator especificado.

### <a name="syntax"></a>Sintaxe

```
bool operator== (const InputIterator& other) const;
```

### <a name="parameters"></a>Parâmetros

*other*<br/>
Outro InputIterator.

### <a name="return-value"></a>Valor de retorno

**Verdadeiro** se o InputIterator atual for igual a *outras*; caso contrário, **false**.

## <a name="operator-increment"></a>  Operador inputiterator:: Operator + +

Incrementa o InputIterator atual.

### <a name="syntax"></a>Sintaxe

```
InputIterator& operator++();
InputIterator operator++(int);
```

### <a name="return-value"></a>Valor de retorno

A primeira sintaxe incrementa e, em seguida, retorna o InputIterator atual. A segunda sintaxe retorna uma cópia de InputIterator atual e, em seguida, incrementa o InputIterator atual.

### <a name="remarks"></a>Comentários

A primeira sintaxe de InputIterator pré-incrementa o InputIterator atual.

A segunda sintaxe pós-incrementa o InputIterator atual. O tipo `int` na segunda sintaxe indica uma operação de pós-incremento, não um operando de inteiro real.

## <a name="operator-inequality"></a>  Inputiterator:: Operator! = operador

Indica se o InputIterator atual não é igual a um InputIterator especificado.

### <a name="syntax"></a>Sintaxe

```
bool operator!=(const InputIterator& other) const;
```

### <a name="parameters"></a>Parâmetros

*other*<br/>
Outro InputIterator.

### <a name="return-value"></a>Valor de retorno

**Verdadeiro** se o InputIterator atual não é igual a *outras*; caso contrário, **false**.

## <a name="see-also"></a>Consulte também

[Namespace de plataforma](platform-namespace-c-cx.md)
