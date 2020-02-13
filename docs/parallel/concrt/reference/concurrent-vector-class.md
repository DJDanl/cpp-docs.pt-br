---
title: Classe concurrent_vector
ms.date: 11/04/2016
f1_keywords:
- concurrent_vector
- CONCURRENT_VECTOR/concurrency::concurrent_vector
- CONCURRENT_VECTOR/concurrency::concurrent_vector::concurrent_vector
- CONCURRENT_VECTOR/concurrency::concurrent_vector::assign
- CONCURRENT_VECTOR/concurrency::concurrent_vector::at
- CONCURRENT_VECTOR/concurrency::concurrent_vector::back
- CONCURRENT_VECTOR/concurrency::concurrent_vector::begin
- CONCURRENT_VECTOR/concurrency::concurrent_vector::capacity
- CONCURRENT_VECTOR/concurrency::concurrent_vector::cbegin
- CONCURRENT_VECTOR/concurrency::concurrent_vector::cend
- CONCURRENT_VECTOR/concurrency::concurrent_vector::clear
- CONCURRENT_VECTOR/concurrency::concurrent_vector::crbegin
- CONCURRENT_VECTOR/concurrency::concurrent_vector::crend
- CONCURRENT_VECTOR/concurrency::concurrent_vector::empty
- CONCURRENT_VECTOR/concurrency::concurrent_vector::end
- CONCURRENT_VECTOR/concurrency::concurrent_vector::front
- CONCURRENT_VECTOR/concurrency::concurrent_vector::get_allocator
- CONCURRENT_VECTOR/concurrency::concurrent_vector::grow_by
- CONCURRENT_VECTOR/concurrency::concurrent_vector::grow_to_at_least
- CONCURRENT_VECTOR/concurrency::concurrent_vector::max_size
- CONCURRENT_VECTOR/concurrency::concurrent_vector::push_back
- CONCURRENT_VECTOR/concurrency::concurrent_vector::rbegin
- CONCURRENT_VECTOR/concurrency::concurrent_vector::rend
- CONCURRENT_VECTOR/concurrency::concurrent_vector::reserve
- CONCURRENT_VECTOR/concurrency::concurrent_vector::resize
- CONCURRENT_VECTOR/concurrency::concurrent_vector::shrink_to_fit
- CONCURRENT_VECTOR/concurrency::concurrent_vector::size
- CONCURRENT_VECTOR/concurrency::concurrent_vector::swap
helpviewer_keywords:
- concurrent_vector class
ms.assetid: a217b4ac-af2b-4d41-94eb-09a75ee28622
ms.openlocfilehash: 002f1e3f691de3315810efed8f7d8f6c547cf653
ms.sourcegitcommit: a8ef52ff4a4944a1a257bdaba1a3331607fb8d0f
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 02/11/2020
ms.locfileid: "77143144"
---
# <a name="concurrent_vector-class"></a>Classe concurrent_vector

A classe `concurrent_vector` é uma classe de contêiner de sequência que permite o acesso aleatório a qualquer elemento. Ele permite acréscimo seguro de simultaneidade, acesso a elementos, acesso iterador e operações de percurso de iterador. Aqui, a simultaneidade segura significa que os ponteiros ou iteradores são sempre válidos. Não é uma garantia de inicialização de elemento ou de uma ordem de passagem específica.

## <a name="syntax"></a>Sintaxe

```cpp
template<typename T, class _Ax>
class concurrent_vector: protected details::_Allocator_base<T,
    _Ax>,
private details::_Concurrent_vector_base_v4;
```

### <a name="parameters"></a>Parâmetros

*T*<br/>
O tipo de dados dos elementos a serem armazenados no vetor.

*_Ax*<br/>
O tipo que representa o objeto alocador armazenado que encapsula detalhes sobre a alocação e desalocação de memória para o vetor simultâneo. Esse argumento é opcional e o valor padrão é `allocator<T>`.

## <a name="members"></a>Membros

### <a name="public-typedefs"></a>Typedefs Públicos

|{1&gt;Nome&lt;1}|Descrição|
|----------|-----------------|
|`allocator_type`|Um tipo que representa a classe de alocador para o vetor simultâneo.|
|`const_iterator`|Um tipo que fornece um iterador de acesso aleatório que pode ler um elemento `const` em um vetor simultâneo.|
|`const_pointer`|Um tipo que fornece um ponteiro para um elemento `const` em um vetor simultâneo.|
|`const_reference`|Um tipo que fornece uma referência a um elemento `const` armazenado em um vetor simultâneo para leitura e execução de operações de `const`.|
|`const_reverse_iterator`|Um tipo que fornece um iterador de acesso aleatório que pode ler qualquer elemento `const` no vetor simultâneo.|
|`difference_type`|Um tipo que fornece a distância assinada entre dois elementos em um vetor simultâneo.|
|`iterator`|Um tipo que fornece um iterador de acesso aleatório que pode ler qualquer elemento em um vetor simultâneo. A modificação de um elemento que usa o iterador não é segura para simultaneidade.|
|`pointer`|Um tipo que fornece um ponteiro para um elemento em um vetor simultâneo.|
|`reference`|Um tipo que fornece uma referência a um elemento armazenado em um vetor simultâneo.|
|`reverse_iterator`|Um tipo que fornece um iterador de acesso aleatório que pode ler qualquer elemento em um vetor simultâneo invertido. A modificação de um elemento que usa o iterador não é segura para simultaneidade.|
|`size_type`|Um tipo que conta o número de elementos em um vetor simultâneo.|
|`value_type`|Um tipo que representa o tipo de dados armazenado em um vetor simultâneo.|

### <a name="public-constructors"></a>Construtores públicos

|{1&gt;Nome&lt;1}|Descrição|
|----------|-----------------|
|[concurrent_vector](#ctor)|Sobrecarregado. Constrói um vetor simultâneo.|
|[~ concurrent_vector destruidor](#dtor)|Apaga todos os elementos e destrói esse vetor simultâneo.|

### <a name="public-methods"></a>Métodos públicos

|{1&gt;Nome&lt;1}|Descrição|
|----------|-----------------|
|[assign](#assign)|Sobrecarregado. Apaga os elementos do vetor simultâneo e atribui a ele `_N` cópias de `_Item`ou valores especificados pelo intervalo do iterador [`_Begin``_End`). Esse método não é seguro para simultaneidade.|
|[at](#at)|Sobrecarregado. Fornece acesso ao elemento no índice especificado no vetor simultâneo. Esse método é protegido contra simultaneidade para operações de leitura e também aumenta o vetor, desde que você tenha garantido que o valor `_Index` seja menor que o tamanho do vetor simultâneo.|
|[back](#back)|Sobrecarregado. Retorna uma referência ou uma `const` referência ao último elemento no vetor simultâneo. Se o vetor simultâneo estiver vazio, o valor de retorno será indefinido. Esse método é seguro para simultaneidade.|
|[begin](#begin)|Sobrecarregado. Retorna um iterador do tipo `iterator` ou `const_iterator` ao início do vetor simultâneo. Esse método é seguro para simultaneidade.|
|[capacidade](#capacity)|Retorna o tamanho máximo para o qual o vetor simultâneo pode crescer sem a necessidade de alocar mais memória. Esse método é seguro para simultaneidade.|
|[cbegin](#cbegin)|Retorna um iterador do tipo `const_iterator` para o início do vetor simultâneo. Esse método é seguro para simultaneidade.|
|[cend](#cend)|Retorna um iterador do tipo `const_iterator` ao final do vetor simultâneo. Esse método é seguro para simultaneidade.|
|[clear](#clear)|Apaga todos os elementos no vetor simultâneo. Esse método não é seguro para simultaneidade.|
|[crbegin](#crbegin)|Retorna um iterador do tipo `const_reverse_iterator` para o início do vetor simultâneo. Esse método é seguro para simultaneidade.|
|[crend](#crend)|Retorna um iterador do tipo `const_reverse_iterator` ao final do vetor simultâneo. Esse método é seguro para simultaneidade.|
|[empty](#empty)|Testa se o vetor simultâneo está vazio no momento em que esse método é chamado. Esse método é seguro para simultaneidade.|
|[end](#end)|Sobrecarregado. Retorna um iterador do tipo `iterator` ou `const_iterator` ao final do vetor simultâneo. Esse método é seguro para simultaneidade.|
|[front](#front)|Sobrecarregado. Retorna uma referência ou uma `const` referência ao primeiro elemento no vetor simultâneo. Se o vetor simultâneo estiver vazio, o valor de retorno será indefinido. Esse método é seguro para simultaneidade.|
|[get_allocator](#get_allocator)|Retorna uma cópia do alocador usado para construir o vetor simultâneo. Esse método é seguro para simultaneidade.|
|[grow_by](#grow_by)|Sobrecarregado. Aumenta esse vetor simultâneo por elementos de `_Delta`. Esse método é seguro para simultaneidade.|
|[grow_to_at_least](#grow_to_at_least)|Aumenta esse vetor simultâneo até que tenha pelo menos `_N` elementos. Esse método é seguro para simultaneidade.|
|[max_size](#max_size)|Retorna o número máximo de elementos que o vetor simultâneo pode conter. Esse método é seguro para simultaneidade.|
|[push_back](#push_back)|Sobrecarregado. Acrescenta o item fornecido ao final do vetor simultâneo. Esse método é seguro para simultaneidade.|
|[rbegin](#rbegin)|Sobrecarregado. Retorna um iterador do tipo `reverse_iterator` ou `const_reverse_iterator` ao início do vetor simultâneo. Esse método é seguro para simultaneidade.|
|[rend](#rend)|Sobrecarregado. Retorna um iterador do tipo `reverse_iterator` ou `const_reverse_iterator` ao final do vetor simultâneo. Esse método é seguro para simultaneidade.|
|[reserve](#reserve)|Aloca espaço suficiente para aumentar o vetor simultâneo para o tamanho `_N` sem precisar alocar mais memória posteriormente. Esse método não é seguro para simultaneidade.|
|[resize](#resize)|Sobrecarregado. Altera o tamanho do vetor simultâneo para o tamanho solicitado, excluindo ou adicionando elementos conforme necessário. Esse método não é seguro para simultaneidade.|
|[shrink_to_fit](#shrink_to_fit)|Compacta a representação interna do vetor simultâneo para reduzir a fragmentação e otimizar o uso da memória. Esse método não é seguro para simultaneidade.|
|[size](#size)|Retorna o número de elementos no vetor simultâneo. Esse método é seguro para simultaneidade.|
|[swap](#swap)|Permuta o conteúdo de dois vetores simultâneos. Esse método não é seguro para simultaneidade.|

### <a name="public-operators"></a>Operadores públicos

|{1&gt;Nome&lt;1}|Descrição|
|----------|-----------------|
|[operator\[\]](#operator_at)|Sobrecarregado. Fornece acesso ao elemento no índice especificado no vetor simultâneo. Esse método é protegido por simultaneidade para operações de leitura e também ao aumentar o vetor, desde que você tenha garantido que o valor `_Index` seja menor que o tamanho do vetor simultâneo.|
|[operator=](#operator_eq)|Sobrecarregado. Atribui o conteúdo de outro objeto de `concurrent_vector` a este. Esse método não é seguro para simultaneidade.|

## <a name="remarks"></a>Comentários

Para obter informações detalhadas sobre a classe `concurrent_vector`, consulte [contêineres e objetos paralelos](../../../parallel/concrt/parallel-containers-and-objects.md).

## <a name="inheritance-hierarchy"></a>Hierarquia de herança

`_Concurrent_vector_base_v4`

`_Allocator_base`

`concurrent_vector`

## <a name="requirements"></a>{1&gt;{2&gt;Requisitos&lt;2}&lt;1}

**Cabeçalho:** concurrent_vector. h

**Namespace:** simultaneidade

## <a name="assign"></a>Cancele

Apaga os elementos do vetor simultâneo e atribui a ele `_N` cópias de `_Item`ou valores especificados pelo intervalo do iterador [`_Begin``_End`). Esse método não é seguro para simultaneidade.

```cpp
void assign(
    size_type _N,
    const_reference _Item);

template<class _InputIterator>
void assign(_InputIterator _Begin,
    _InputIterator _End);
```

### <a name="parameters"></a>Parâmetros

*_InputIterator*<br/>
O tipo do iterador especificado.

*_N*<br/>
O número de itens a serem copiados para o vetor simultâneo.

*_Item*<br/>
Referência a um valor usado para preencher o vetor simultâneo.

*_Begin*<br/>
Um iterador para o primeiro elemento do intervalo de origem.

*_End*<br/>
Um iterador para um após o último elemento do intervalo de origem.

### <a name="remarks"></a>Comentários

`assign` não é seguro para simultaneidade. Você deve garantir que nenhum outro thread esteja invocando métodos no vetor simultâneo ao chamar esse método.

## <a name="at"></a>no

Fornece acesso ao elemento no índice especificado no vetor simultâneo. Esse método é protegido contra simultaneidade para operações de leitura e também aumenta o vetor, desde que você tenha garantido que o valor `_Index` seja menor que o tamanho do vetor simultâneo.

```cpp
reference at(size_type _Index);

const_reference at(size_type _Index) const;
```

### <a name="parameters"></a>Parâmetros

*_Index*<br/>
O índice do elemento a ser recuperado.

### <a name="return-value"></a>Valor retornado

Uma referência ao item no índice especificado.

### <a name="remarks"></a>Comentários

A versão da função `at` que retorna uma referência não `const` não pode ser usada para gravar simultaneamente no elemento de threads diferentes. Um objeto de sincronização diferente deve ser usado para sincronizar operações simultâneas de leitura e gravação no mesmo elemento de dados.

O método gera `out_of_range` se `_Index` é maior ou igual ao tamanho do vetor simultâneo e `range_error` se o índice é para uma parte quebrada do vetor. Para obter detalhes sobre como um vetor pode ser quebrado, consulte [contêineres e objetos paralelos](../../../parallel/concrt/parallel-containers-and-objects.md).

## <a name="back"></a>Voltar

Retorna uma referência ou uma `const` referência ao último elemento no vetor simultâneo. Se o vetor simultâneo estiver vazio, o valor de retorno será indefinido. Esse método é seguro para simultaneidade.

```cpp
reference back();

const_reference back() const;
```

### <a name="return-value"></a>Valor retornado

Uma referência ou uma `const` referência ao último elemento no vetor simultâneo.

## <a name="begin"></a>Comece

Retorna um iterador do tipo `iterator` ou `const_iterator` ao início do vetor simultâneo. Esse método é seguro para simultaneidade.

```cpp
iterator begin();

const_iterator begin() const;
```

### <a name="return-value"></a>Valor retornado

Um iterador do tipo `iterator` ou `const_iterator` ao início do vetor simultâneo.

## <a name="capacity"></a>recurso

Retorna o tamanho máximo para o qual o vetor simultâneo pode crescer sem a necessidade de alocar mais memória. Esse método é seguro para simultaneidade.

```cpp
size_type capacity() const;
```

### <a name="return-value"></a>Valor retornado

O tamanho máximo para o qual o vetor simultâneo pode crescer sem a necessidade de alocar mais memória.

### <a name="remarks"></a>Comentários

Ao contrário C++ de uma biblioteca padrão `vector`, um objeto `concurrent_vector` não move elementos existentes se aloca mais memória.

## <a name="cbegin"></a>cbegin

Retorna um iterador do tipo `const_iterator` para o início do vetor simultâneo. Esse método é seguro para simultaneidade.

```cpp
const_iterator cbegin() const;
```

### <a name="return-value"></a>Valor retornado

Um iterador do tipo `const_iterator` ao início do vetor simultâneo.

## <a name="cend"></a>cend

Retorna um iterador do tipo `const_iterator` ao final do vetor simultâneo. Esse método é seguro para simultaneidade.

```cpp
const_iterator cend() const;
```

### <a name="return-value"></a>Valor retornado

Um iterador do tipo `const_iterator` ao final do vetor simultâneo.

## <a name="clear"></a>formatação

Apaga todos os elementos no vetor simultâneo. Esse método não é seguro para simultaneidade.

```cpp
void clear();
```

### <a name="remarks"></a>Comentários

`clear` não é seguro para simultaneidade. Você deve garantir que nenhum outro thread esteja invocando métodos no vetor simultâneo ao chamar esse método. `clear` não libera matrizes internas. Para liberar matrizes internas, chame a função `shrink_to_fit` após `clear`.

## <a name="ctor"></a>concurrent_vector

Constrói um vetor simultâneo.

```cpp
explicit concurrent_vector(
    const allocator_type& _Al = allocator_type());

concurrent_vector(
    const concurrent_vector& _Vector);

template<class M>
concurrent_vector(
    const concurrent_vector<T,
    M>& _Vector,
    const allocator_type& _Al = allocator_type());

concurrent_vector(
    concurrent_vector&& _Vector);

explicit concurrent_vector(
    size_type _N);

concurrent_vector(
    size_type _N,
    const_reference _Item,
    const allocator_type& _Al = allocator_type());

template<class _InputIterator>
concurrent_vector(_InputIterator _Begin,
    _InputIterator _End,
    const allocator_type& _Al = allocator_type());
```

### <a name="parameters"></a>Parâmetros

*M*<br/>
O tipo de alocador do vetor de origem.

*_InputIterator*<br/>
O tipo do iterador de entrada.

*_Al*<br/>
A classe de alocador a ser usada com esse objeto.

*_Vector*<br/>
O objeto de `concurrent_vector` de origem para copiar ou mover elementos.

*_N*<br/>
A capacidade inicial do objeto de `concurrent_vector`.

*_Item*<br/>
O valor dos elementos no objeto construído.

*_Begin*<br/>
A posição do primeiro elemento no intervalo de elementos a ser copiado.

*_End*<br/>
A posição do primeiro elemento após o intervalo de elementos a ser copiado.

### <a name="remarks"></a>Comentários

Todos os construtores armazenam um objeto de alocador `_Al` e inicializam o vetor.

O primeiro construtor Especifica um vetor inicial vazio e especifica explicitamente o tipo de alocador. a ser usado.

O segundo e o terceiro construtores especificam uma cópia do vetor simultâneo `_Vector`.

O quarto construtor Especifica uma movimentação do vetor simultâneo `_Vector`.

O quinto Construtor especifica uma repetição de um número especificado (`_N`) de elementos do valor padrão para a classe `T`.

O sexto Construtor especifica uma repetição de elementos (`_N`) do valor `_Item`.

O último construtor Especifica valores fornecidos pelo intervalo do iterador [`_Begin`, `_End`).

## <a name="dtor"></a>~ concurrent_vector

Apaga todos os elementos e destrói esse vetor simultâneo.

```cpp
~concurrent_vector();
```

## <a name="crbegin"></a>crbegin

Retorna um iterador do tipo `const_reverse_iterator` para o início do vetor simultâneo. Esse método é seguro para simultaneidade.

```cpp
const_reverse_iterator crbegin() const;
```

### <a name="return-value"></a>Valor retornado

Um iterador do tipo `const_reverse_iterator` ao início do vetor simultâneo.

## <a name="crend"></a>crend

Retorna um iterador do tipo `const_reverse_iterator` ao final do vetor simultâneo. Esse método é seguro para simultaneidade.

```cpp
const_reverse_iterator crend() const;
```

### <a name="return-value"></a>Valor retornado

Um iterador do tipo `const_reverse_iterator` ao final do vetor simultâneo.

## <a name="empty"></a>esvaziá

Testa se o vetor simultâneo está vazio no momento em que esse método é chamado. Esse método é seguro para simultaneidade.

```cpp
bool empty() const;
```

### <a name="return-value"></a>Valor retornado

**true** se o vetor estava vazio no momento em que a função foi chamada; caso contrário, **false** .

## <a name="end"></a>completo

Retorna um iterador do tipo `iterator` ou `const_iterator` ao final do vetor simultâneo. Esse método é seguro para simultaneidade.

```cpp
iterator end();

const_iterator end() const;
```

### <a name="return-value"></a>Valor retornado

Um iterador do tipo `iterator` ou `const_iterator` ao final do vetor simultâneo.

## <a name="front"></a>dianteiro

Retorna uma referência ou uma `const` referência ao primeiro elemento no vetor simultâneo. Se o vetor simultâneo estiver vazio, o valor de retorno será indefinido. Esse método é seguro para simultaneidade.

```cpp
reference front();

const_reference front() const;
```

### <a name="return-value"></a>Valor retornado

Uma referência ou uma `const` referência ao primeiro elemento no vetor simultâneo.

## <a name="get_allocator"></a>get_allocator

Retorna uma cópia do alocador usado para construir o vetor simultâneo. Esse método é seguro para simultaneidade.

```cpp
allocator_type get_allocator() const;
```

### <a name="return-value"></a>Valor retornado

Uma cópia do alocador usado para construir o objeto de `concurrent_vector`.

## <a name="grow_by"></a>grow_by

Aumenta esse vetor simultâneo por elementos de `_Delta`. Esse método é seguro para simultaneidade.

```cpp
iterator grow_by(
    size_type _Delta);

iterator grow_by(
    size_type _Delta,
    const_reference _Item);
```

### <a name="parameters"></a>Parâmetros

*_Delta*<br/>
O número de elementos a serem acrescentados ao objeto.

*_Item*<br/>
O valor com o qual inicializar os novos elementos.

### <a name="return-value"></a>Valor retornado

Um iterador para o primeiro item acrescentado.

### <a name="remarks"></a>Comentários

Se `_Item` não for especificado, os novos elementos serão construídos por padrão.

## <a name="grow_to_at_least"></a>grow_to_at_least

Aumenta esse vetor simultâneo até que tenha pelo menos `_N` elementos. Esse método é seguro para simultaneidade.

```cpp
iterator grow_to_at_least(size_type _N);
```

### <a name="parameters"></a>Parâmetros

*_N*<br/>
O novo tamanho mínimo para o objeto `concurrent_vector`.

### <a name="return-value"></a>Valor retornado

Um iterador que aponta para o início da sequência acrescentada ou para o elemento no índice `_N` se nenhum elemento foi acrescentado.

## <a name="max_size"></a>max_size

Retorna o número máximo de elementos que o vetor simultâneo pode conter. Esse método é seguro para simultaneidade.

```cpp
size_type max_size() const;
```

### <a name="return-value"></a>Valor retornado

O número máximo de elementos que o objeto de `concurrent_vector` pode conter.

## <a name="operator_eq"></a>operador =

Atribui o conteúdo de outro objeto de `concurrent_vector` a este. Esse método não é seguro para simultaneidade.

```cpp
concurrent_vector& operator= (
    const concurrent_vector& _Vector);

template<class M>
concurrent_vector& operator= (
    const concurrent_vector<T, M>& _Vector);

concurrent_vector& operator= (
    concurrent_vector&& _Vector);
```

### <a name="parameters"></a>Parâmetros

*M*<br/>
O tipo de alocador do vetor de origem.

*_Vector*<br/>
O objeto `concurrent_vector` de origem.

### <a name="return-value"></a>Valor retornado

Uma referência a este objeto de `concurrent_vector`.

## <a name="operator_at"></a>operador []

Fornece acesso ao elemento no índice especificado no vetor simultâneo. Esse método é protegido por simultaneidade para operações de leitura e também ao aumentar o vetor, desde que você tenha garantido que o valor `_Index` seja menor que o tamanho do vetor simultâneo.

```cpp
reference operator[](size_type _index);

const_reference operator[](size_type _index) const;
```

### <a name="parameters"></a>Parâmetros

*_Index*<br/>
O índice do elemento a ser recuperado.

### <a name="return-value"></a>Valor retornado

Uma referência ao item no índice especificado.

### <a name="remarks"></a>Comentários

A versão do `operator []` que retorna uma referência não `const` não pode ser usada para gravar simultaneamente no elemento de threads diferentes. Um objeto de sincronização diferente deve ser usado para sincronizar operações simultâneas de leitura e gravação no mesmo elemento de dados.

Nenhuma verificação de limites é executada para garantir que `_Index` seja um índice válido no vetor simultâneo.

## <a name="push_back"></a>push_back

Acrescenta o item fornecido ao final do vetor simultâneo. Esse método é seguro para simultaneidade.

```cpp
iterator push_back(const_reference _Item);

iterator push_back(T&& _Item);
```

### <a name="parameters"></a>Parâmetros

*_Item*<br/>
O valor a ser acrescentado.

### <a name="return-value"></a>Valor retornado

Um iterador para o item anexado.

## <a name="rbegin"></a>rbegin

Retorna um iterador do tipo `reverse_iterator` ou `const_reverse_iterator` ao início do vetor simultâneo. Esse método é seguro para simultaneidade.

```cpp
reverse_iterator rbegin();

const_reverse_iterator rbegin() const;
```

### <a name="return-value"></a>Valor retornado

Um iterador do tipo `reverse_iterator` ou `const_reverse_iterator` ao início do vetor simultâneo.

## <a name="rend"></a>rend

Retorna um iterador do tipo `reverse_iterator` ou `const_reverse_iterator` ao final do vetor simultâneo. Esse método é seguro para simultaneidade.

```cpp
reverse_iterator rend();

const_reverse_iterator rend() const;
```

### <a name="return-value"></a>Valor retornado

Um iterador do tipo `reverse_iterator` ou `const_reverse_iterator` ao final do vetor simultâneo.

## <a name="reserve"></a>reservado

Aloca espaço suficiente para aumentar o vetor simultâneo para o tamanho `_N` sem precisar alocar mais memória posteriormente. Esse método não é seguro para simultaneidade.

```cpp
void reserve(size_type _N);
```

### <a name="parameters"></a>Parâmetros

*_N*<br/>
O número de elementos para os quais reservar espaço.

### <a name="remarks"></a>Comentários

`reserve` não é seguro para simultaneidade. Você deve garantir que nenhum outro thread esteja invocando métodos no vetor simultâneo ao chamar esse método. A capacidade do vetor simultâneo após o retorno do método pode ser maior do que a reserva solicitada.

## <a name="resize"></a>alonga

Altera o tamanho do vetor simultâneo para o tamanho solicitado, excluindo ou adicionando elementos conforme necessário. Esse método não é seguro para simultaneidade.

```cpp
void resize(
    size_type _N);

void resize(
    size_type _N,
    const T& val);
```

### <a name="parameters"></a>Parâmetros

*_N*<br/>
O novo tamanho do concurrent_vector.

*val*<br/>
O valor dos novos elementos adicionados ao vetor se o novo tamanho for maior do que o tamanho original. Se o valor for omitido, os novos objetos receberão o valor padrão para seu tipo.

### <a name="remarks"></a>Comentários

Se o tamanho do contêiner for menor que o tamanho solicitado, os elementos serão adicionados ao vetor até atingir o tamanho solicitado. Se o tamanho do contêiner for maior que o tamanho solicitado, os elementos mais próximos ao final do contêiner serão excluídos até que o contêiner atinja o tamanho `_N`. Se o tamanho atual do contêiner for igual ao tamanho solicitado, nenhuma ação será realizada.

`resize` não é seguro em simultaneidade. Você deve garantir que nenhum outro thread esteja invocando métodos no vetor simultâneo ao chamar esse método.

## <a name="shrink_to_fit"></a>shrink_to_fit

Compacta a representação interna do vetor simultâneo para reduzir a fragmentação e otimizar o uso da memória. Esse método não é seguro para simultaneidade.

```cpp
void shrink_to_fit();
```

### <a name="remarks"></a>Comentários

Esse método realocará internamente os elementos de movimentação de memória, invalidando todos os iteradores. `shrink_to_fit` não é seguro para simultaneidade. Você deve garantir que nenhum outro thread esteja invocando métodos no vetor simultâneo ao chamar essa função.

## <a name="size"></a>tamanho

Retorna o número de elementos no vetor simultâneo. Esse método é seguro para simultaneidade.

```cpp
size_type size() const;
```

### <a name="return-value"></a>Valor retornado

O número de elementos neste `concurrent_vector` objeto.

### <a name="remarks"></a>Comentários

É garantido que o tamanho retornado inclua todos os elementos acrescentados por chamadas à função `push_back`ou aumente as operações que foram concluídas antes de invocar esse método. No entanto, ele também pode incluir elementos que são alocados, mas ainda em construção por chamadas simultâneas para qualquer um dos métodos de crescimento.

## <a name="swap"></a>permuta

Permuta o conteúdo de dois vetores simultâneos. Esse método não é seguro para simultaneidade.

```cpp
void swap(concurrent_vector& _Vector);
```

### <a name="parameters"></a>Parâmetros

*_Vector*<br/>
O objeto `concurrent_vector` com o qual trocar conteúdo.

## <a name="see-also"></a>Consulte também

[Namespace de simultaneidade](concurrency-namespace.md)<br/>
[Contêineres e objetos em paralelo](../../../parallel/concrt/parallel-containers-and-objects.md)
