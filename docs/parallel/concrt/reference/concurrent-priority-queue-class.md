---
title: Classe concurrent_priority_queue | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-concrt
ms.topic: reference
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
dev_langs:
- C++
helpviewer_keywords:
- concurrent_priority_queue class
ms.assetid: 3e740381-0f4e-41fc-8b66-ad0bb55f17a3
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
ms.openlocfilehash: b87ac316c08f93a95f7791297b74cbbb20d5452a
ms.sourcegitcommit: 799f9b976623a375203ad8b2ad5147bd6a2212f0
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/19/2018
ms.locfileid: "46413868"
---
# <a name="concurrentpriorityqueue-class"></a>Classe concurrent_priority_queue

O `concurrent_priority_queue` classe é um contêiner que permite que vários threads simultaneamente os itens de push e pop. Itens são exibidos em ordem de prioridade em que a prioridade é determinada por um funtor fornecido como um argumento de modelo.

## <a name="syntax"></a>Sintaxe

```
template <typename T,
    typename _Compare= std::less<T>,
    typename _Ax = std::allocator<T>
>,
    typename _Ax = std::allocator<T>> class concurrent_priority_queue;
```

#### <a name="parameters"></a>Parâmetros

*T*<br/>
O tipo de dados dos elementos a ser armazenado na fila de prioridade.

*Comparar*<br/>
O tipo do objeto de função que pode comparar dois valores de elemento como chaves de classificação para determinar sua ordem relativa na fila de prioridade. Esse argumento é opcional e o predicado binário `less<T>` é o valor padrão.

*_Ax*<br/>
O tipo que representa o objeto de alocador armazenado que encapsula detalhes sobre a alocação e desalocação de memória para a fila de prioridade simultâneas. Esse argumento é opcional e o valor padrão é `allocator<T>`.

## <a name="members"></a>Membros

### <a name="public-typedefs"></a>Typedefs públicos

|Nome|Descrição|
|----------|-----------------|
|`allocator_type`|Um tipo que representa a classe de alocador para a fila de prioridade simultâneas.|
|`const_reference`|Um tipo que representa uma referência const para um elemento do tipo armazenado em uma fila de prioridade simultâneas.|
|`reference`|Um tipo que representa uma referência a um elemento do tipo armazenado em uma fila de prioridade simultâneas.|
|`size_type`|Um tipo que conta o número de elementos em uma fila de prioridade simultâneas.|
|`value_type`|Um tipo que representa o tipo de dados armazenado em uma fila de prioridade simultâneas.|

### <a name="public-constructors"></a>Construtores públicos

|Nome|Descrição|
|----------|-----------------|
|[concurrent_priority_queue](#ctor)|Sobrecarregado. Constrói uma fila de prioridade simultâneas.|

### <a name="public-methods"></a>Métodos públicos

|Nome|Descrição|
|----------|-----------------|
|[clear](#clear)|Apaga todos os elementos na ordem de prioridade simultânea. Esse método não é seguro em simultaneidade.|
|[empty](#empty)|Testa se a fila de prioridade simultâneos está vazia no momento em que esse método é chamado. Esse método é seguro em simultaneidade.|
|[get_allocator](#get_allocator)|Retorna uma cópia do alocador usado para construir a fila de prioridade simultâneas. Esse método é seguro em simultaneidade.|
|[push](#push)|Sobrecarregado. Adiciona um elemento à fila de prioridade simultâneas. Esse método é seguro em simultaneidade.|
|[size](#size)|Retorna o número de elementos na fila de prioridade simultâneas. Esse método é seguro em simultaneidade.|
|[swap](#swap)|Troca o conteúdo de duas filas de prioridade simultâneas. Esse método não é seguro em simultaneidade.|
|[try_pop](#try_pop)|Remove e retorna o elemento mais alto de prioridade da fila se a fila está vazio. Esse método é seguro em simultaneidade.|

### <a name="public-operators"></a>Operadores públicos

|Nome|Descrição|
|----------|-----------------|
|[operator=](#operator_eq)|Sobrecarregado. Atribui o conteúdo de outro `concurrent_priority_queue` objeto para esse outro. Esse método não é seguro em simultaneidade.|

## <a name="remarks"></a>Comentários

Para obter informações detalhadas sobre o `concurrent_priority_queue` classe, consulte [paralela contêineres e objetos](../../../parallel/concrt/parallel-containers-and-objects.md).

## <a name="inheritance-hierarchy"></a>Hierarquia de herança

`concurrent_priority_queue`

## <a name="requirements"></a>Requisitos

**Cabeçalho:** concurrent_priority_queue.h

**Namespace:** simultaneidade

##  <a name="clear"></a> Limpar

Apaga todos os elementos na ordem de prioridade simultânea. Esse método não é seguro em simultaneidade.

```
void clear();
```

### <a name="remarks"></a>Comentários

`clear` não é seguro em simultaneidade. Você deve garantir que nenhum outro thread estiver chamando métodos na fila de prioridade simultâneas quando você chama esse método. `clear` não libera memória.

##  <a name="ctor"></a> concurrent_priority_queue

Constrói uma fila de prioridade simultâneas.

```
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

### <a name="parameters"></a>Parâmetros

*_InputIterator*<br/>
O tipo do iterador de entrada.

*_Al*<br/>
A classe de alocador a ser usada com esse objeto.

*_Init_capacity*<br/>
A capacidade inicial do `concurrent_priority_queue` objeto.

*Iniciar*<br/>
A posição do primeiro elemento no intervalo de elementos a serem copiados.

*Encerrar*<br/>
A posição do primeiro elemento além do intervalo de elementos a serem copiados.

*_Src*<br/>
A fonte `concurrent_priority_queue` objeto para copiar ou mover elementos.

### <a name="remarks"></a>Comentários

Todos os construtores armazenam um objeto alocador `_Al` e inicializar a fila de prioridade.

O primeiro construtor Especifica uma fila de prioridade inicial vazio e, opcionalmente, especifica um alocador.

O segundo construtor Especifica uma fila de prioridade com uma capacidade inicial `_Init_capacity` e, opcionalmente, especifica um alocador.

O terceiro construtor especifica valores fornecidos pelo intervalo do iterador [ `_Begin`, `_End`) e, opcionalmente, especifica um alocador.

O quarto e quinto construtor Especifica uma cópia da fila de prioridade `_Src`.

Os sexto e sétimo construtores especificam um movimento de fila de prioridade `_Src`.

##  <a name="empty"></a> vazio

Testa se a fila de prioridade simultâneos está vazia no momento em que esse método é chamado. Esse método é seguro em simultaneidade.

```
bool empty() const;
```

### <a name="return-value"></a>Valor de retorno

`true` Se a fila de prioridade estava vazia no momento em que a função foi chamada, `false` caso contrário.

##  <a name="get_allocator"></a> get_allocator

Retorna uma cópia do alocador usado para construir a fila de prioridade simultâneas. Esse método é seguro em simultaneidade.

```
allocator_type get_allocator() const;
```

### <a name="return-value"></a>Valor de retorno

Uma cópia do alocador usado para construir o `concurrent_priority_queue` objeto.

##  <a name="operator_eq"></a> operador =

Atribui o conteúdo de outro `concurrent_priority_queue` objeto para esse outro. Esse método não é seguro em simultaneidade.

```
concurrent_priority_queue& operator= (const concurrent_priority_queue& _Src);

concurrent_priority_queue& operator= (concurrent_priority_queue&& _Src);
```

### <a name="parameters"></a>Parâmetros

*_Src*<br/>
A fonte `concurrent_priority_queue` objeto.

### <a name="return-value"></a>Valor de retorno

Uma referência a este `concurrent_priority_queue` objeto.

##  <a name="push"></a> envio por push

Adiciona um elemento à fila de prioridade simultâneas. Esse método é seguro em simultaneidade.

```
void push(const value_type& _Elem);

void push(value_type&& _Elem);
```

### <a name="parameters"></a>Parâmetros

*_Elem*<br/>
O elemento a ser adicionado à fila de prioridade simultâneas.

##  <a name="size"></a> Tamanho

Retorna o número de elementos na fila de prioridade simultâneas. Esse método é seguro em simultaneidade.

```
size_type size() const;
```

### <a name="return-value"></a>Valor de retorno

O número de elementos neste `concurrent_priority_queue` objeto.

### <a name="remarks"></a>Comentários

O tamanho retornado é garantido para incluir todos os elementos adicionados por chamadas para a função `push`. No entanto, ele pode não refletir os resultados de operações simultâneas pendentes.

##  <a name="swap"></a> troca

Troca o conteúdo de duas filas de prioridade simultâneas. Esse método não é seguro em simultaneidade.

```
void swap(concurrent_priority_queue& _Queue);
```

### <a name="parameters"></a>Parâmetros

*Adresa*<br/>
O objeto `concurrent_priority_queue` com o qual trocar conteúdo.

##  <a name="try_pop"></a> try_pop

Remove e retorna o elemento mais alto de prioridade da fila se a fila está vazio. Esse método é seguro em simultaneidade.

```
bool try_pop(reference _Elem);
```

### <a name="parameters"></a>Parâmetros

*_Elem*<br/>
Uma referência a uma variável que será preenchida com o elemento de prioridade mais alto, se a fila está vazio.

### <a name="return-value"></a>Valor de retorno

`true` Se um valor foi aparecido, `false` caso contrário.

## <a name="see-also"></a>Consulte também

[Namespace de simultaneidade](concurrency-namespace.md)<br/>
[Contêineres e objetos em paralelo](../../../parallel/concrt/parallel-containers-and-objects.md)

