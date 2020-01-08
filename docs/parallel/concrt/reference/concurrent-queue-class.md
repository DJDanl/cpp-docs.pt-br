---
title: Classe concurrent_queue
ms.date: 11/04/2016
f1_keywords:
- concurrent_queue
- CONCURRENT_QUEUE/concurrency::concurrent_queue
- CONCURRENT_QUEUE/concurrency::concurrent_queue::concurrent_queue
- CONCURRENT_QUEUE/concurrency::concurrent_queue::clear
- CONCURRENT_QUEUE/concurrency::concurrent_queue::empty
- CONCURRENT_QUEUE/concurrency::concurrent_queue::get_allocator
- CONCURRENT_QUEUE/concurrency::concurrent_queue::push
- CONCURRENT_QUEUE/concurrency::concurrent_queue::try_pop
- CONCURRENT_QUEUE/concurrency::concurrent_queue::unsafe_begin
- CONCURRENT_QUEUE/concurrency::concurrent_queue::unsafe_end
- CONCURRENT_QUEUE/concurrency::concurrent_queue::unsafe_size
helpviewer_keywords:
- concurrent_queue class
ms.assetid: c2218996-d0ea-40e9-b002-e9a15b085f51
ms.openlocfilehash: 7f87ead486d635c933ad356f9868c22344601eda
ms.sourcegitcommit: a5fa9c6f4f0c239ac23be7de116066a978511de7
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/20/2019
ms.locfileid: "75298606"
---
# <a name="concurrent_queue-class"></a>Classe concurrent_queue

A classe `concurrent_queue` é uma classe de contêiner de sequência que permite o acesso de primeiro a entrar, primeiro a sair para seus elementos. Ele permite um conjunto limitado de operações protegidas por simultaneidade, como `push` e `try_pop`. Aqui, a simultaneidade segura significa que os ponteiros ou iteradores são sempre válidos. Não é uma garantia de inicialização de elemento ou de uma ordem de passagem específica.

## <a name="syntax"></a>Sintaxe

```
template<typename T, class _Ax>
class concurrent_queue: public ::Concurrency::details::_Concurrent_queue_base_v4;
```

#### <a name="parameters"></a>Parâmetros

*T*<br/>
O tipo de dados dos elementos a serem armazenados na fila.

*_Ax*<br/>
O tipo que representa o objeto alocador armazenado que encapsula detalhes sobre a alocação e desalocação de memória para essa fila simultânea. Esse argumento é opcional e o valor padrão é `allocator<T>`.

## <a name="members"></a>Membros

### <a name="public-typedefs"></a>Typedefs Públicos

|Name|Descrição|
|----------|-----------------|
|`allocator_type`|Um tipo que representa a classe de alocador para a fila simultânea.|
|`const_iterator`|Um tipo que representa um iterador de `const` não seguro para thread sobre elementos em uma fila simultânea.|
|`const_reference`|Um tipo que fornece uma referência a um elemento `const` armazenado em uma fila simultânea para leitura e execução de operações de `const`.|
|`difference_type`|Um tipo que fornece a distância assinada entre dois elementos em uma fila simultânea.|
|`iterator`|Um tipo que representa um iterador não seguro para thread nos elementos em uma fila simultânea.|
|`reference`|Um tipo que fornece uma referência a um elemento armazenado em uma fila simultânea.|
|`size_type`|Um tipo que conta o número de elementos em uma fila simultânea.|
|`value_type`|Um tipo que representa o tipo de dados armazenado em uma fila simultânea.|

### <a name="public-constructors"></a>Construtores Públicos

|Name|Descrição|
|----------|-----------------|
|[concurrent_queue](#ctor)|Sobrecarregado. Constrói uma fila simultânea.|
|[~concurrent_queue Destructor](#dtor)|Destrói a fila simultânea.|

### <a name="public-methods"></a>Métodos Públicos

|Name|Descrição|
|----------|-----------------|
|[clear](#clear)|Limpa a fila simultânea, destruindo todos os elementos atualmente enfileirados. Esse método não é seguro para simultaneidade.|
|[empty](#empty)|Testa se a fila simultânea está vazia no momento em que esse método é chamado. Esse método é seguro para simultaneidade.|
|[get_allocator](#get_allocator)|Retorna uma cópia do alocador usado para construir a fila simultânea. Esse método é seguro para simultaneidade.|
|[push](#push)|Sobrecarregado. Enfileira um item na extremidade final da fila simultânea. Esse método é seguro para simultaneidade.|
|[try_pop](#try_pop)|Removerá uma fila de um item da fila se houver um disponível. Esse método é seguro para simultaneidade.|
|[unsafe_begin](#unsafe_begin)|Sobrecarregado. Retorna um iterador do tipo `iterator` ou `const_iterator` ao início da fila simultânea. Esse método não é seguro para simultaneidade.|
|[unsafe_end](#unsafe_end)|Sobrecarregado. Retorna um iterador do tipo `iterator` ou `const_iterator` ao final da fila simultânea. Esse método não é seguro para simultaneidade.|
|[unsafe_size](#unsafe_size)|Retorna o número de itens na fila. Esse método não é seguro para simultaneidade.|

## <a name="remarks"></a>Comentários

Para obter mais informações, consulte [contêineres e objetos paralelos](../../../parallel/concrt/parallel-containers-and-objects.md).

## <a name="inheritance-hierarchy"></a>Hierarquia de Herança

`concurrent_queue`

## <a name="requirements"></a>Requisitos do

**Cabeçalho:** concurrent_queue. h

**Namespace:** simultaneidade

##  <a name="clear"></a>formatação

Limpa a fila simultânea, destruindo todos os elementos atualmente enfileirados. Esse método não é seguro para simultaneidade.

```
void clear();
```

##  <a name="ctor"></a> concurrent_queue

Constrói uma fila simultânea.

```
explicit concurrent_queue(
    const allocator_type& _Al = allocator_type());

concurrent_queue(
    const concurrent_queue& _OtherQ,
    const allocator_type& _Al = allocator_type());

concurrent_queue(
    concurrent_queue&& _OtherQ,
    const allocator_type& _Al = allocator_type());

template<typename _InputIterator>
concurrent_queue(_InputIterator _Begin,
    _InputIterator _End);
```

### <a name="parameters"></a>Parâmetros

*_InputIterator*<br/>
O tipo do iterador de entrada que especifica um intervalo de valores.

*_Al*<br/>
A classe de alocador a ser usada com esse objeto.

*_OtherQ*<br/>
O objeto de `concurrent_queue` de origem para copiar ou mover elementos.

*_Begin*<br/>
A posição do primeiro elemento no intervalo de elementos a ser copiado.

*_End*<br/>
A posição do primeiro elemento após o intervalo de elementos a ser copiado.

### <a name="remarks"></a>Comentários

Todos os construtores armazenam um objeto de alocador `_Al` e inicializam a fila.

O primeiro construtor Especifica uma fila inicial vazia e especifica explicitamente o tipo de alocador a ser usado.

O segundo construtor Especifica uma cópia da fila simultânea `_OtherQ`.

O terceiro construtor Especifica uma movimentação da fila simultânea `_OtherQ`.

O quarto construtor Especifica valores fornecidos pelo intervalo do iterador [`_Begin`, `_End`).

##  <a name="dtor"></a> ~concurrent_queue

Destrói a fila simultânea.

```
~concurrent_queue();
```

##  <a name="empty"></a>esvaziá

Testa se a fila simultânea está vazia no momento em que esse método é chamado. Esse método é seguro para simultaneidade.

```
bool empty() const;
```

### <a name="return-value"></a>Valor de retorno

**true** se a fila simultânea estava vazia no momento que olhamos; caso contrário, **false** .

### <a name="remarks"></a>Comentários

Embora esse método seja seguro para simultaneidade em relação a chamadas para os métodos `push`, `try_pop`e `empty`, o valor retornado pode estar incorreto no momento em que é inspecionado pelo thread de chamada.

##  <a name="get_allocator"></a>get_allocator

Retorna uma cópia do alocador usado para construir a fila simultânea. Esse método é seguro para simultaneidade.

```
allocator_type get_allocator() const;
```

### <a name="return-value"></a>Valor de retorno

Uma cópia do alocador usado para construir a fila simultânea.

##  <a name="push"></a>pressionado

Enfileira um item na extremidade final da fila simultânea. Esse método é seguro para simultaneidade.

```
void push(const T& _Src);

void push(T&& _Src);
```

### <a name="parameters"></a>Parâmetros

*_Src*<br/>
O item a ser adicionado à fila.

### <a name="remarks"></a>Comentários

`push` é seguro à simultaneidade em relação a chamadas para os métodos `push`, `try_pop`e `empty`.

##  <a name="try_pop"></a> try_pop

Removerá uma fila de um item da fila se houver um disponível. Esse método é seguro para simultaneidade.

```
bool try_pop(T& _Dest);
```

### <a name="parameters"></a>Parâmetros

*_Dest*<br/>
Uma referência a um local para armazenar o item removido da fila.

### <a name="return-value"></a>Valor de retorno

**true** se um item tiver sido removido com êxito da fila; caso contrário, **false** .

### <a name="remarks"></a>Comentários

Se um item foi removido com êxito da fila, o parâmetro `_Dest` receberá o valor removido da fila, o valor original mantido na fila será destruído e essa função retornará **true**. Se não houver nenhum item para remover da fila, essa função retornará `false` sem bloqueio e o conteúdo do parâmetro `_Dest` será indefinido.

`try_pop` é seguro à simultaneidade em relação a chamadas para os métodos `push`, `try_pop`e `empty`.

##  <a name="unsafe_begin"></a> unsafe_begin

Retorna um iterador do tipo `iterator` ou `const_iterator` ao início da fila simultânea. Esse método não é seguro para simultaneidade.

```
iterator unsafe_begin();

const_iterator unsafe_begin() const;
```

### <a name="return-value"></a>Valor de retorno

Um iterador do tipo `iterator` ou `const_iterator` ao início do objeto de fila simultâneo.

### <a name="remarks"></a>Comentários

Os iteradores para a classe `concurrent_queue` são destinados principalmente para depuração, pois são lentos e a iteração não é segura para simultaneidade em relação a outras operações de fila.

##  <a name="unsafe_end"></a> unsafe_end

Retorna um iterador do tipo `iterator` ou `const_iterator` ao final da fila simultânea. Esse método não é seguro para simultaneidade.

```
iterator unsafe_end();

const_iterator unsafe_end() const;
```

### <a name="return-value"></a>Valor de retorno

Um iterador do tipo `iterator` ou `const_iterator` ao final da fila simultânea.

### <a name="remarks"></a>Comentários

Os iteradores para a classe `concurrent_queue` são destinados principalmente para depuração, pois são lentos e a iteração não é segura para simultaneidade em relação a outras operações de fila.

##  <a name="unsafe_size"></a> unsafe_size

Retorna o número de itens na fila. Esse método não é seguro para simultaneidade.

```
size_type unsafe_size() const;
```

### <a name="return-value"></a>Valor de retorno

O tamanho da fila simultânea.

### <a name="remarks"></a>Comentários

`unsafe_size` não é segura para simultaneidade e pode produzir resultados incorretos se chamados simultaneamente com chamadas para os métodos `push`, `try_pop`e `empty`.

## <a name="see-also"></a>Veja também

[Namespace de simultaneidade](concurrency-namespace.md)
