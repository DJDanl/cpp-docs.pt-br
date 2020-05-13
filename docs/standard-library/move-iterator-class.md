---
title: Classe move_iterator
ms.date: 03/27/2019
f1_keywords:
- iterator/std::move_iterator
- iterator/std::move_iterator::iterator_type
- iterator/std::move_iterator::iterator_category
- iterator/std::move_iterator::value_type
- iterator/std::move_iterator::difference_type
- iterator/std::move_iterator::pointer
- iterator/std::move_iterator::reference
- iterator/std::move_iterator::base
helpviewer_keywords:
- std::move_iterator [C++]
- std::move_iterator [C++], iterator_type
- std::move_iterator [C++], iterator_category
- std::move_iterator [C++], value_type
- std::move_iterator [C++], difference_type
- std::move_iterator [C++], pointer
- std::move_iterator [C++], reference
- std::move_iterator [C++], base
ms.assetid: a5e5cdd8-a264-4c6b-9f9c-68b0e8edaab7
ms.openlocfilehash: 17af246a85c4e3f1e0c7eb9d387161ad7b5123a1
ms.sourcegitcommit: c123cc76bb2b6c5cde6f4c425ece420ac733bf70
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/14/2020
ms.locfileid: "81377417"
---
# <a name="move_iterator-class"></a>Classe move_iterator

O modelo de classe `move_iterator` é um wrapper para um iterador. O move_iterator apresenta o mesmo comportamento do iterador que ele encapsula (armazena), exceto pelo fato de que transforma o operador de desreferência do iterador armazenado em uma referência rvalue, transformando uma cópia em um movimento. Para obter mais informações sobre rvalues, consulte [Declarador de referência Rvalue: &&](../cpp/rvalue-reference-declarator-amp-amp.md).

## <a name="syntax"></a>Sintaxe

```cpp
class move_iterator;
```

## <a name="remarks"></a>Comentários

O modelo de classe descreve um objeto que se comporta como um iterador, exceto quando desreferenciado. Ela armazena um iterador de acesso aleatório do tipo `Iterator`, acessado pela função membro `base()`. Todas as operações em um `move_iterator` são executadas diretamente no iterador armazenado, exceto pelo fato de que o resultado de `operator*` é implicitamente convertido em `value_type&&` para criar uma referência rvalue.

Um `move_iterator` pode ser capaz de operações que não são definidas pelo iterador encapsulado. Essas operações não devem ser usadas.

### <a name="constructors"></a>Construtores

|Construtor|Descrição|
|-|-|
|[move_iterator](#move_iterator)|O construtor para objetos do tipo `move_iterator`.|

### <a name="typedefs"></a>Typedefs

|Nome do tipo|Descrição|
|-|-|
|[iterator_type](#iterator_type)|Um sinônimo para o parâmetro de modelo `RandomIterator`.|
|[iterator_category](#iterator_category)|Um sinônimo para uma expressão de nome `iterator_category` de **tipo** mais longo de mesmo nome, identifica as habilidades gerais do ativador.|
|[Value_type](#value_type)|Um sinônimo para uma expressão de nome `value_type` de **tipo** mais longo de mesmo nome, descreve que tipo são os elementos do iterador.|
|[difference_type](#difference_type)|Um sinônimo para uma expressão de nome `difference_type` de **tipo** mais longo de mesmo nome, descreve o tipo integral necessário para expressar valores de diferença entre os elementos.|
|[ponteiro](#pointer)|Um sinônimo para o parâmetro de modelo `RandomIterator`.|
|[Referência](#reference)|Um sinônimo para a referência `rvalue``value_type&&`.|

### <a name="member-functions"></a>Funções de membro

|Função de membro|Descrição|
|-|-|
|[base](#base)|A função membro retorna o iterador armazenado encapsulado por esse `move_iterator`.|

### <a name="operators"></a>Operadores

|Operador|Descrição|
|-|-|
|[move_iterator:operador*](#op_star)|Retorna `(reference)*base().`|
|[move_iterator:operador++](#op_add_add)|Incrementa o iterador armazenado. O comportamento exato depende do tipo de operação: pré-incremento ou pós-incremento.|
|[move_iterator::operator--](#operator--)|Decrementa o iterador armazenado. O comportamento exato depende do tipo de operação: pré-decremento ou pós-decremento.|
|[move_iterator::operador-&gt;](#op_arrow)|Retorna `&**this`.|
|[move_iterator::operador-](#operator-)|Retorna `move_iterator(*this) -=` subtraindo primeiro o valor do lado direito da posição atual.|
|[move_iterator:operador[]](#op_at)|Retorna `(reference)*(*this + off)`. Permite especificar um deslocamento da base atual para obter o valor nessa posição.|
|[move_iterator:operador+](#op_add)|Retorna `move_iterator(*this) +=` do valor. Permite adicionar um deslocamento à base para obter o valor nessa posição.|
|[move_iterator:operador+=](#op_add_eq)|Adiciona o valor do lado direito ao iterador armazenado e retorna `*this`.|
|[move_iterator:operador-=](#operator-_eq)|Subtrai o valor do lado direito do iterador armazenado e retorna `*this`.|

## <a name="requirements"></a>Requisitos

**Cabeçalho:** \<iterator>

**Namespace:** std

## <a name="move_iteratorbase"></a><a name="base"></a>move_iterator:base

Retorna o iterador armazenado para este `move_iterator`.

```cpp
RandomIterator base() const;
```

### <a name="remarks"></a>Comentários

A função membro retorna o iterador armazenado.

## <a name="move_iteratordifference_type"></a><a name="difference_type"></a>move_iterator::difference_type

O tipo `difference_type` é um `move_iterator` `typedef` com base na característica de iterador `difference_type` e podem ser usados alternadamente com ele.

```cpp
typedef typename iterator_traits<RandomIterator>::difference_type difference_type;
```

### <a name="remarks"></a>Comentários

O tipo é um sinônimo para a característica do iterador `typename iterator_traits<RandomIterator>::pointer`.

## <a name="move_iteratoriterator_category"></a><a name="iterator_category"></a>move_iterator:iterator_category

O tipo `iterator_category` é um `move_iterator` `typedef` com base na característica de iterador `iterator_category` e podem ser usados alternadamente com ele.

```cpp
typedef typename iterator_traits<RandomIterator>::iterator_category  iterator_category;
```

### <a name="remarks"></a>Comentários

O tipo é um sinônimo para a característica do iterador `typename iterator_traits<RandomIterator>::iterator_category`.

## <a name="move_iteratoriterator_type"></a><a name="iterator_type"></a>move_iterator:iterator_type

O tipo `iterator_type` é baseado no parâmetro de modelo `RandomIterator` para o modelo de classe `move_iterator` e pode ser usado alternadamente em seu lugar.

```cpp
typedef RandomIterator iterator_type;
```

### <a name="remarks"></a>Comentários

O tipo é um sinônimo do parâmetro de modelo `RandomIterator`.

## <a name="move_iteratormove_iterator"></a><a name="move_iterator"></a>move_iterator:move_iterator

Constrói um iterador de movimentação. Usa o parâmetro como o iterador armazenado.

```cpp
move_iterator();
explicit move_iterator(RandomIterator right);
template <class Type>
move_iterator(const move_iterator<Type>& right);
```

### <a name="parameters"></a>Parâmetros

*Certo*\
O iterador a ser usado como o iterador armazenado.

### <a name="remarks"></a>Comentários

O primeiro construtor inicializa o iterador armazenado com o construtor padrão. Os construtores restantes inicializam o iterador armazenado com `base.base()`.

## <a name="move_iteratoroperator"></a><a name="op_add_eq"></a>move_iterator:operador+=

Adiciona um deslocamento ao iterador armazenado, para que o iterador armazenado aponte para o elemento no novo local atual. O operador move então o novo elemento atual.

```cpp
move_iterator& operator+=(difference_type _Off);
```

### <a name="parameters"></a>Parâmetros

*_Off*\
Um deslocamento para adicionar à posição atual para determinar a nova posição atual.

### <a name="return-value"></a>Valor retornado

Retorna o novo elemento atual.

### <a name="remarks"></a>Comentários

O operador adiciona *_Off* ao tempo réterizador armazenado. Em seguida, retorna `*this`.

## <a name="move_iteratoroperator-"></a><a name="operator-_eq"></a>move_iterator:operador-=

Move entre um número especificado de elementos anteriores. Este operador subtrai um deslocamento do iterador armazenado.

```cpp
move_iterator& operator-=(difference_type _Off);
```

### <a name="parameters"></a>Parâmetros

### <a name="remarks"></a>Comentários

O operador avalia `*this += -_Off`. Em seguida, retorna `*this`.

## <a name="move_iteratoroperator"></a><a name="op_add_add"></a>move_iterator:operador++

Incrementa o iterador armazenado que pertence a este `move_iterator.`. O elemento atual é acessado pelo operador pós-incremento. O próximo elemento é acessado pelo operador pré-incremento.

```cpp
move_iterator& operator++();
move_iterator operator++(int);
```

### <a name="parameters"></a>Parâmetros

### <a name="remarks"></a>Comentários

O primeiro operador (pré-incremento) incrementa o iterador armazenado. Em seguida, retorna `*this`.

O segundo operador (pós-incremento) faz uma cópia do `*this`, avalia `++*this`. E retorna a cópia.

## <a name="move_iteratoroperator"></a><a name="op_add"></a>move_iterator:operador+

Retorna a posição do iterador avançada por qualquer número de elementos.

```cpp
move_iterator operator+(difference_type _Off) const;
```

### <a name="parameters"></a>Parâmetros

### <a name="remarks"></a>Comentários

O operador `move_iterator(*this) +=` `_Off`retorna.

## <a name="move_iteratoroperator"></a><a name="op_at"></a>move_iterator:operador[]

Permite o acesso de índice de matriz a elementos em uma série do `move iterator`.

```cpp
reference operator[](difference_type _Off) const;
```

### <a name="parameters"></a>Parâmetros

### <a name="remarks"></a>Comentários

O operador retorna `(reference)*(*this + _Off)`.

## <a name="move_iteratoroperator--"></a><a name="operator--"></a>move_iterator::operador--

Os operadores de membro pré e pós-incremento realizam uma diminuição no iterador armazenado.

```cpp
move_iterator& operator--();
move_iterator operator--();
```

### <a name="parameters"></a>Parâmetros

### <a name="remarks"></a>Comentários

O primeiro operador de membro (pré-decremento) diminui o iterador armazenado. Em seguida, retorna `*this`.

O segundo operador (pós-decremento) faz uma cópia do `*this`, avalia `--*this`. E retorna a cópia.

## <a name="move_iteratoroperator-"></a><a name="operator-"></a>move_iterator::operador-

Diminui o iterador armazenado e retorna o valor indicado.

```cpp
move_iterator operator-(difference_type _Off) const;
```

### <a name="parameters"></a>Parâmetros

### <a name="remarks"></a>Comentários

O operador retorna `move_iterator(*this) -= _Off`.

## <a name="move_iteratoroperator"></a><a name="op_star"></a>move_iterator:operador*

Desreferencia o iterador armazenado e retorna o valor. Isso se comporta como um `rvalue reference` e realiza uma atribuição de movimentação. O operador transfere o elemento atual para fora do iterador de base. O elemento seguinte se torna o novo elemento atual.

```cpp
reference operator*() const;
```

### <a name="remarks"></a>Comentários

O operador retorna `(reference)*base()`.

## <a name="move_iteratoroperator-gt"></a><a name="op_arrow"></a>move_iterator::operador-&gt;

Como um `RandomIterator` `operator->` normal, ele fornece acesso aos campos que pertencem ao elemento atual.

```cpp
pointer operator->() const;
```

### <a name="remarks"></a>Comentários

O operador retorna `&**this`.

## <a name="move_iteratorpointer"></a><a name="pointer"></a>move_iterator::pointer

O `pointer` tipo é um **typedef** baseado `RandomIterator` no `move_iterator`iterador aleatório para , e pode ser usado de forma intercambiável.

```cpp
typedef RandomIterator  pointer;
```

### <a name="remarks"></a>Comentários

O tipo é um sinônimo de `RandomIterator`.

## <a name="move_iteratorreference"></a><a name="reference"></a>move_iterator::referência

O `reference` tipo é um **typedef** baseado em `value_type&&` , `move_iterator` `value_type&&`e pode ser usado intercambiavelmente com .

```cpp
typedef value_type&& reference;
```

### <a name="remarks"></a>Comentários

O tipo é um sinônimo para `value_type&&`, que é uma referência de rvalue.

## <a name="move_iteratorvalue_type"></a><a name="value_type"></a>move_iterator:value_type

O tipo `value_type` é um `move_iterator` `typedef` com base na característica de iterador `value_type` e podem ser usados alternadamente com ele.

```cpp
typedef typename iterator_traits<RandomIterator>::value_type   value_type;
```

### <a name="remarks"></a>Comentários

O tipo é um sinônimo para a característica do iterador `typename iterator_traits<RandomIterator>::value_type`.

## <a name="see-also"></a>Confira também

[\<>do tempo](../standard-library/iterator.md)\
[Valores e Valores](../cpp/lvalues-and-rvalues-visual-cpp.md)\
[Mover construtores e mover operadores de atribuição (C++)](../cpp/move-constructors-and-move-assignment-operators-cpp.md)\
[Referência da biblioteca padrão C++](../standard-library/cpp-standard-library-reference.md)
