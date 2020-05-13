---
title: Classe Platform::Collections::InputIterator
ms.date: 03/27/2019
ms.topic: reference
f1_keywords:
- COLLECTION/Platform::Collections::InputIterator::InputIterator
helpviewer_keywords:
- InputIterator Class
ms.assetid: ef72eea4-32a9-42b9-8119-ce87dbdcd3be
ms.openlocfilehash: 92f9b15f474a5aa3d063f0ccfb663f56baf8de31
ms.sourcegitcommit: c123cc76bb2b6c5cde6f4c425ece420ac733bf70
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/14/2020
ms.locfileid: "81354559"
---
# <a name="platformcollectionsinputiterator-class"></a>Classe Platform::Collections::InputIterator

Fornece um ativador de entrada de biblioteca de modelopadrão para coleções derivadas do Tempo de execução do Windows.

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
|[Inseriterator::InputIterator](#ctor)|Inicializa uma nova instância da classe InputIterator.|

### <a name="public-operators"></a>Operadores públicos

|Nome|Descrição|
|----------|-----------------|
|[Insumator::operador!= Operador](#operator-inequality)|Indica se o InputIterator atual não é igual a um InputIterator especificado.|
|[Operador InputIterator::operator*](#operator-dereference)|Recupera uma referência ao elemento especificado pelo InputIterator atual.|
|[Initerator::operador++ Operador](#operator-increment)|Incrementa o InputIterator atual.|
|[Inseridor::operador== Operador](#operator-equality)|Indica se o InputIterator atual é igual a um InputIterator especificado.|
|[Interator::operador > operador](#operator-arrow)|Recupera o endereço do elemento referenciado pelo InputIterator atual.|

## <a name="inheritance-hierarchy"></a>Hierarquia de herança

`InputIterator`

### <a name="requirements"></a>Requisitos

**Cabeçalho:** collection.h

**Namespace:** Platform::Collections

## <a name="inputiteratorinputiterator-constructor"></a><a name="ctor"></a>Initerator::Construtor de entrada

Inicializa uma nova instância da classe InputIterator.

### <a name="syntax"></a>Sintaxe

```
InputIterator();
explicit InputIterator(Windows::Foundation::Collections<X>^ iterator);
```

### <a name="parameters"></a>Parâmetros

*Iterador*<br/>
Um objeto do iterador.

## <a name="inputiteratoroperator-gt-operator"></a><a name="operator-arrow"></a>Interator::operador -&gt; Operador

Recupera o endereço do elemento especificado pelo InputIterator atual.

### <a name="syntax"></a>Sintaxe

```
pointer operator->() const;
```

### <a name="return-value"></a>Valor retornado

O endereço do elemento especificado pelo InputIterator atual.

## <a name="inputiteratoroperator-operator"></a><a name="operator-dereference"></a>Interator::operador\* operador

Recupera uma referência ao elemento especificado pelo InputIterator atual.

### <a name="syntax"></a>Sintaxe

```
reference operator*() const;
```

### <a name="return-value"></a>Valor retornado

O elemento especificado pelo InputIterator atual.

## <a name="inputiteratoroperator-operator"></a><a name="operator-equality"></a>Inseridor::operador== Operador

Indica se o InputIterator atual é igual a um InputIterator especificado.

### <a name="syntax"></a>Sintaxe

```
bool operator== (const InputIterator& other) const;
```

### <a name="parameters"></a>Parâmetros

*Outros*<br/>
Outro InputIterator.

### <a name="return-value"></a>Valor retornado

**verdade** se o insumo de entrada atual for igual a *outro;* caso contrário, **falso**.

## <a name="inputiteratoroperator-operator"></a><a name="operator-increment"></a>Initerator::operador++ Operador

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

A segunda sintaxe pós-incrementa o InputIterator atual. O tipo `int` na segunda sintaxe indica uma operação de pós-incremento, não um operando de inteiro real.

## <a name="inputiteratoroperator-operator"></a><a name="operator-inequality"></a>Insumator::operador!= Operador

Indica se o InputIterator atual não é igual a um InputIterator especificado.

### <a name="syntax"></a>Sintaxe

```
bool operator!=(const InputIterator& other) const;
```

### <a name="parameters"></a>Parâmetros

*Outros*<br/>
Outro InputIterator.

### <a name="return-value"></a>Valor retornado

**verdade** se o insumo de entrada atual não for igual a *outro;* caso contrário, **falso**.

## <a name="see-also"></a>Confira também

[Espaço de nome da plataforma](platform-namespace-c-cx.md)
