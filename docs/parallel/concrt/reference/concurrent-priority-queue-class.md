---
title: Classe concurrent_priority_queue
ms.date: 11/04/2016
f1_keywords:
- concurrent_priority_queue
- CONCURRENT_PRIORITY_QUEUE/concurrency::concurrent_priority_queue
- CONCURRENT_PRIORITY_QUEUE/concurrency::concurrent_priority_queue::concurrent_priority_queue
- CONCURRENT_PRIORITY_QUEUE/concurrency::concurrent_priority_queue::clear
- CONCURRENT_PRIORITY_QUEUE/concurrency::concurrent_priority_queue::empty
- CONCURRENT_PRIORITY_QUEUE/concurrency::concurrent_priority_queue::get_allocator
- CONCURRENT_PRIORITY_QUEUE/concurrency::concurrent_priority_queue::push
- CONCURRENT_PRIORITY_QUEUE/concurrency::concurrent_priority_queue::size
- CONCURRENT_PRIORITY_QUEUE/concurrency::concurrent_priority_queue::swap
- CONCURRENT_PRIORITY_QUEUE/concurrency::concurrent_priority_queue::try_pop
helpviewer_keywords:
- concurrent_priority_queue class
ms.assetid: 3e740381-0f4e-41fc-8b66-ad0bb55f17a3
ms.openlocfilehash: 024bd2a100b8a0b871d98a5e6001858b55977565
ms.sourcegitcommit: 1f009ab0f2cc4a177f2d1353d5a38f164612bdb1
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 07/27/2020
ms.locfileid: "87230357"
---
# <a name="concurrent_priority_queue-class"></a>Classe concurrent_priority_queue

A `concurrent_priority_queue` classe é um contêiner que permite que vários threads enviem itens por push e pop simultaneamente. Os itens são retirados em ordem de prioridade em que a prioridade é determinada por um functor fornecido como um argumento de modelo.

## <a name="syntax"></a>Sintaxe

```cpp
template <typename T,
    typename _Compare= std::less<T>,
    typename _Ax = std::allocator<T>
>,
    typename _Ax = std::allocator<T>> class concurrent_priority_queue;
```

### <a name="parameters"></a>parâmetros

*T*<br/>
O tipo de dados dos elementos a serem armazenados na fila de prioridade.

*_Compare*<br/>
O tipo do objeto de função que pode comparar dois valores de elemento como chaves de classificação para determinar sua ordem relativa na fila de prioridade. Esse argumento é opcional e o predicado binário `less<T>` é o valor padrão.

*_Ax*<br/>
O tipo que representa o objeto de alocador armazenado que encapsula detalhes sobre a alocação e desalocação de memória para a fila de prioridade simultânea. Esse argumento é opcional e o valor padrão é `allocator<T>`.

## <a name="members"></a>Membros

### <a name="public-typedefs"></a>Typedefs públicos

|Nome|Descrição|
|----------|-----------------|
|`allocator_type`|Um tipo que representa a classe de alocador para a fila de prioridade simultânea.|
|`const_reference`|Um tipo que representa uma referência const a um elemento do tipo armazenado em uma fila de prioridade simultânea.|
|`reference`|Um tipo que representa uma referência a um elemento do tipo armazenado em uma fila de prioridade simultânea.|
|`size_type`|Um tipo que conta o número de elementos em uma fila de prioridade simultânea.|
|`value_type`|Um tipo que representa o tipo de dados armazenado em uma fila de prioridade simultânea.|

### <a name="public-constructors"></a>Construtores públicos

|Nome|Descrição|
|----------|-----------------|
|[concurrent_priority_queue](#ctor)|Sobrecarregado. Constrói uma fila de prioridade simultânea.|

### <a name="public-methods"></a>Métodos públicos

|Nome|Descrição|
|----------|-----------------|
|[formatação](#clear)|Apaga todos os elementos na prioridade simultânea. Esse método não é seguro para simultaneidade.|
|[empty](#empty)|Testa se a fila de prioridade simultânea está vazia no momento em que esse método é chamado. Esse método é seguro para simultaneidade.|
|[get_allocator](#get_allocator)|Retorna uma cópia do alocador usado para construir a fila de prioridade simultânea. Esse método é seguro para simultaneidade.|
|[push](#push)|Sobrecarregado. Adiciona um elemento à fila de prioridade simultânea. Esse método é seguro para simultaneidade.|
|[size](#size)|Retorna o número de elementos na fila de prioridade simultânea. Esse método é seguro para simultaneidade.|
|[permuta](#swap)|Permuta o conteúdo de duas filas de prioridade simultâneas. Esse método não é seguro para simultaneidade.|
|[try_pop](#try_pop)|Remove e retorna o elemento de prioridade mais alta da fila se a fila não estiver vazia. Esse método é seguro para simultaneidade.|

### <a name="public-operators"></a>Operadores públicos

|Nome|Descrição|
|----------|-----------------|
|[operador =](#operator_eq)|Sobrecarregado. Atribui o conteúdo de outro `concurrent_priority_queue` objeto a este. Esse método não é seguro para simultaneidade.|

## <a name="remarks"></a>Comentários

Para obter informações detalhadas sobre a `concurrent_priority_queue` classe, consulte [contêineres e objetos paralelos](../../../parallel/concrt/parallel-containers-and-objects.md).

## <a name="inheritance-hierarchy"></a>Hierarquia de herança

`concurrent_priority_queue`

## <a name="requirements"></a>Requisitos

**Cabeçalho:** concurrent_priority_queue. h

**Namespace:** simultaneidade

## <a name="clear"></a><a name="clear"></a>formatação

Apaga todos os elementos na prioridade simultânea. Esse método não é seguro para simultaneidade.

```cpp
void clear();
```

### <a name="remarks"></a>Comentários

`clear`Não é seguro para simultaneidade. Você deve garantir que nenhum outro thread esteja invocando métodos na fila de prioridade simultânea ao chamar esse método. `clear`não libera memória.

## <a name="concurrent_priority_queue"></a><a name="ctor"></a>concurrent_priority_queue

Constrói uma fila de prioridade simultânea.

```cpp
explicit concurrent_priority_queue(
    const allocator_type& _Al = allocator_type());

explicit concurrent_priority_queue(
    size_type _Init_capacity,
    const allocator_type& _Al = allocator_type());

template<typename _InputIterator>
concurrent_priority_queue(_InputIterator _Begin,
    _InputIterator _End,
    const allocator_type& _Al = allocator_type());

concurrent_priority_queue(
    const concurrent_priority_queue& _Src);

concurrent_priority_queue(
    const concurrent_priority_queue& _Src,
    const allocator_type& _Al);

concurrent_priority_queue(
    concurrent_priority_queue&& _Src);

concurrent_priority_queue(
    concurrent_priority_queue&& _Src,
    const allocator_type& _Al);
```

### <a name="parameters"></a>parâmetros

*_InputIterator*<br/>
O tipo do iterador de entrada.

*_Al*<br/>
A classe de alocador a ser usada com esse objeto.

*_Init_capacity*<br/>
A capacidade inicial do `concurrent_priority_queue` objeto.

*_Begin*<br/>
A posição do primeiro elemento no intervalo de elementos a serem copiados.

*_End*<br/>
A posição do primeiro elemento além do intervalo de elementos a serem copiados.

*_Src*<br/>
O `concurrent_priority_queue` objeto de origem do qual copiar ou mover elementos.

### <a name="remarks"></a>Comentários

Todos os construtores armazenam um objeto `_Al` de alocador e inicializam a fila de prioridade.

O primeiro construtor Especifica uma fila de prioridade inicial vazia e, opcionalmente, especifica um alocador.

O segundo construtor Especifica uma fila de prioridade com uma capacidade inicial `_Init_capacity` e, opcionalmente, especifica um alocador.

O terceiro construtor Especifica os valores fornecidos pelo intervalo do iterador [ `_Begin` , `_End` ) e, opcionalmente, especifica um alocador.

Os quarto e quinto construtores especificam uma cópia da fila de prioridade `_Src` .

O sexto e o sétimo construtores especificam uma movimentação da fila de prioridade `_Src` .

## <a name="empty"></a><a name="empty"></a>esvaziá

Testa se a fila de prioridade simultânea está vazia no momento em que esse método é chamado. Esse método é seguro para simultaneidade.

```cpp
bool empty() const;
```

### <a name="return-value"></a>Valor retornado

**`true`** se a fila de prioridade estava vazia no momento em que a função foi chamada, **`false`** caso contrário.

## <a name="get_allocator"></a><a name="get_allocator"></a>get_allocator

Retorna uma cópia do alocador usado para construir a fila de prioridade simultânea. Esse método é seguro para simultaneidade.

```cpp
allocator_type get_allocator() const;
```

### <a name="return-value"></a>Valor retornado

Uma cópia do alocador usado para construir o `concurrent_priority_queue` objeto.

## <a name="operator"></a><a name="operator_eq"></a>operador =

Atribui o conteúdo de outro `concurrent_priority_queue` objeto a este. Esse método não é seguro para simultaneidade.

```cpp
concurrent_priority_queue& operator= (const concurrent_priority_queue& _Src);

concurrent_priority_queue& operator= (concurrent_priority_queue&& _Src);
```

### <a name="parameters"></a>parâmetros

*_Src*<br/>
O objeto `concurrent_priority_queue` de origem.

### <a name="return-value"></a>Valor retornado

Uma referência a este `concurrent_priority_queue` objeto.

## <a name="push"></a><a name="push"></a>pressionado

Adiciona um elemento à fila de prioridade simultânea. Esse método é seguro para simultaneidade.

```cpp
void push(const value_type& _Elem);

void push(value_type&& _Elem);
```

### <a name="parameters"></a>parâmetros

*_Elem*<br/>
O elemento a ser adicionado à fila de prioridade simultânea.

## <a name="size"></a><a name="size"></a>tamanho

Retorna o número de elementos na fila de prioridade simultânea. Esse método é seguro para simultaneidade.

```cpp
size_type size() const;
```

### <a name="return-value"></a>Valor retornado

O número de elementos neste `concurrent_priority_queue` objeto.

### <a name="remarks"></a>Comentários

É garantido que o tamanho retornado inclua todos os elementos adicionados por chamadas à função `push` . No entanto, ele pode não refletir os resultados de operações simultâneas pendentes.

## <a name="swap"></a><a name="swap"></a>permuta

Permuta o conteúdo de duas filas de prioridade simultâneas. Esse método não é seguro para simultaneidade.

```cpp
void swap(concurrent_priority_queue& _Queue);
```

### <a name="parameters"></a>parâmetros

*_Queue*<br/>
O objeto `concurrent_priority_queue` com o qual trocar conteúdo.

## <a name="try_pop"></a><a name="try_pop"></a>try_pop

Remove e retorna o elemento de prioridade mais alta da fila se a fila não estiver vazia. Esse método é seguro para simultaneidade.

```cpp
bool try_pop(reference _Elem);
```

### <a name="parameters"></a>parâmetros

*_Elem*<br/>
Uma referência a uma variável que será populada com o elemento de prioridade mais alta, se a fila não estiver vazia.

### <a name="return-value"></a>Valor retornado

**`true`** se um valor tiver sido retirado, **`false`** caso contrário.

## <a name="see-also"></a>Confira também

[Namespace de simultaneidade](concurrency-namespace.md)<br/>
[Contêineres e objetos paralelos](../../../parallel/concrt/parallel-containers-and-objects.md)
