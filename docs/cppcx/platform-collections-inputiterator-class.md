---
title: Classe Platform::Collections::InputIterator
ms.date: 03/27/2019
ms.topic: reference
f1_keywords:
- COLLECTION/Platform::Collections::InputIterator::InputIterator
helpviewer_keywords:
- InputIterator Class
ms.assetid: ef72eea4-32a9-42b9-8119-ce87dbdcd3be
ms.openlocfilehash: 4aeef07a34c04bd1ab47acf808026024faada567
ms.sourcegitcommit: 1f009ab0f2cc4a177f2d1353d5a38f164612bdb1
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 07/27/2020
ms.locfileid: "87218423"
---
# <a name="platformcollectionsinputiterator-class"></a>Classe Platform::Collections::InputIterator

Fornece uma InputIterator de biblioteca de modelos padrão para coleções derivadas do Windows Runtime.

## <a name="syntax"></a>Sintaxe

```
template <typename X>
class InputIterator;
```

#### <a name="parameters"></a>parâmetros

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
|[Operador InputIterator:: Operator! =](#operator-inequality)|Indica se o InputIterator atual não é igual a um InputIterator especificado.|
|[Operador InputIterator::operator*](#operator-dereference)|Recupera uma referência ao elemento especificado pelo InputIterator atual.|
|[Operador InputIterator:: Operator + +](#operator-increment)|Incrementa o InputIterator atual.|
|[Operador InputIterator:: Operator = =](#operator-equality)|Indica se o InputIterator atual é igual a um InputIterator especificado.|
|[Operador InputIterator:: Operator->](#operator-arrow)|Recupera o endereço do elemento referenciado pelo InputIterator atual.|

## <a name="inheritance-hierarchy"></a>Hierarquia de herança

`InputIterator`

### <a name="requirements"></a>Requisitos

**Cabeçalho:** collection.h

**Namespace:** Platform::Collections

## <a name="inputiteratorinputiterator-constructor"></a><a name="ctor"></a>Construtor InputIterator:: InputIterator

Inicializa uma nova instância da classe InputIterator.

### <a name="syntax"></a>Sintaxe

```
InputIterator();
explicit InputIterator(Windows::Foundation::Collections<X>^ iterator);
```

### <a name="parameters"></a>parâmetros

*repeti*<br/>
Um objeto do iterador.

## <a name="inputiteratoroperator-gt-operator"></a><a name="operator-arrow"></a>Operador InputIterator:: Operator &gt;

Recupera o endereço do elemento especificado pelo InputIterator atual.

### <a name="syntax"></a>Sintaxe

```
pointer operator->() const;
```

### <a name="return-value"></a>Valor retornado

O endereço do elemento especificado pelo InputIterator atual.

## <a name="inputiteratoroperator-operator"></a><a name="operator-dereference"></a>Operador InputIterator:: Operator \*

Recupera uma referência ao elemento especificado pelo InputIterator atual.

### <a name="syntax"></a>Sintaxe

```
reference operator*() const;
```

### <a name="return-value"></a>Valor retornado

O elemento especificado pelo InputIterator atual.

## <a name="inputiteratoroperator-operator"></a><a name="operator-equality"></a>Operador InputIterator:: Operator = =

Indica se o InputIterator atual é igual a um InputIterator especificado.

### <a name="syntax"></a>Sintaxe

```
bool operator== (const InputIterator& other) const;
```

### <a name="parameters"></a>parâmetros

*outros*<br/>
Outro InputIterator.

### <a name="return-value"></a>Valor retornado

**`true`** Se o InputIterator atual for igual a *outro*; caso contrário, **`false`** .

## <a name="inputiteratoroperator-operator"></a><a name="operator-increment"></a>Operador InputIterator:: Operator + +

Incrementa o InputIterator atual.

### <a name="syntax"></a>Sintaxe

```
InputIterator& operator++();
InputIterator operator++(int);
```

### <a name="return-value"></a>Valor retornado

A primeira sintaxe incrementa e, em seguida, retorna o InputIterator atual. A segunda sintaxe retorna uma cópia de InputIterator atual e, em seguida, incrementa o InputIterator atual.

### <a name="remarks"></a>Comentários

A primeira sintaxe de InputIterator pré-incrementa o InputIterator atual.

A segunda sintaxe pós-incrementa o InputIterator atual. O **`int`** tipo na segunda sintaxe indica uma operação de incremento, não um operando de inteiro real.

## <a name="inputiteratoroperator-operator"></a><a name="operator-inequality"></a>Operador InputIterator:: Operator! =

Indica se o InputIterator atual não é igual a um InputIterator especificado.

### <a name="syntax"></a>Sintaxe

```
bool operator!=(const InputIterator& other) const;
```

### <a name="parameters"></a>parâmetros

*outros*<br/>
Outro InputIterator.

### <a name="return-value"></a>Valor retornado

**`true`** Se o InputIterator atual não for igual a *outro*; caso contrário, **`false`** .

## <a name="see-also"></a>Confira também

[Namespace da plataforma](platform-namespace-c-cx.md)
