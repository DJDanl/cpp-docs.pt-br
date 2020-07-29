---
title: Classe concurrent_unordered_set
ms.date: 11/04/2016
f1_keywords:
- concurrent_unordered_set
- CONCURRENT_UNORDERED_SET/concurrency::concurrent_unordered_set
- CONCURRENT_UNORDERED_SET/concurrency::concurrent_unordered_set::concurrent_unordered_set
- CONCURRENT_UNORDERED_SET/concurrency::concurrent_unordered_set::hash_function
- CONCURRENT_UNORDERED_SET/concurrency::concurrent_unordered_set::insert
- CONCURRENT_UNORDERED_SET/concurrency::concurrent_unordered_set::key_eq
- CONCURRENT_UNORDERED_SET/concurrency::concurrent_unordered_set::swap
- CONCURRENT_UNORDERED_SET/concurrency::concurrent_unordered_set::unsafe_erase
helpviewer_keywords:
- concurrent_unordered_set class
ms.assetid: c61f9a9a-4fd9-491a-9251-e300737ecf4b
ms.openlocfilehash: 8dbce21efcd6c1df31d42702aa3e8eeecf6d9114
ms.sourcegitcommit: 1f009ab0f2cc4a177f2d1353d5a38f164612bdb1
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 07/27/2020
ms.locfileid: "87194037"
---
# <a name="concurrent_unordered_set-class"></a>Classe concurrent_unordered_set

A `concurrent_unordered_set` classe é um contêiner protegido por simultaneidade que controla uma sequência de comprimento variável de elementos do tipo K. A sequência é representada de uma maneira que permite acréscimo seguro de simultaneidade, acesso a elementos, acesso iterador e operações de percurso de iterador. Aqui, a simultaneidade segura significa que os ponteiros ou iteradores são sempre válidos. Não é uma garantia de inicialização de elemento ou de uma ordem de passagem específica.

## <a name="syntax"></a>Sintaxe

```cpp
template <typename K,
    typename _Hasher = std::hash<K>,
    typename key_equality = std::equal_to<K>,
    typename _Allocator_type = std::allocator<K>
>,
    typename key_equality = std::equal_to<K>,
    typename _Allocator_type = std::allocator<K>> class concurrent_unordered_set : public details::_Concurrent_hash<details::_Concurrent_unordered_set_traits<K,
    details::_Hash_compare<K,
_Hasher,
    key_equality>,
_Allocator_type,
    false>>;
```

### <a name="parameters"></a>parâmetros

*C*<br/>
O tipo principal.

*_Hasher*<br/>
O tipo de objeto da função de hash. Esse argumento é opcional e o valor padrão é `std::hash<K>`.

*key_equality*<br/>
O tipo de objeto da função de comparação de igualdade. Esse argumento é opcional e o valor padrão é `std::equal_to<K>`.

*_Allocator_type*<br/>
O tipo que representa o objeto de alocador armazenado que encapsula detalhes sobre a alocação e desalocação de memória para o conjunto não ordenado simultâneo. Esse argumento é opcional e o valor padrão é `std::allocator<K>`.

## <a name="members"></a>Membros

### <a name="public-typedefs"></a>Typedefs públicos

|Nome|Descrição|
|----------|-----------------|
|`allocator_type`|O tipo de um distribuidor para gerenciar o armazenamento.|
|`const_iterator`|O tipo de um iterador de constante para a sequência controlada.|
|`const_local_iterator`|O tipo de um iterador de bucket de constante para a sequência controlada.|
|`const_pointer`|O tipo de um ponteiro de constante para um elemento.|
|`const_reference`|O tipo de uma referência de constante para um elemento.|
|`difference_type`|O tipo de uma distância com sinal entre dois elementos.|
|`hasher`|O tipo de função de hash.|
|`iterator`|O tipo de um iterador para a sequência controlada.|
|`key_equal`|O tipo da função de comparação.|
|`key_type`|O tipo de uma chave de classificação.|
|`local_iterator`|O tipo de um iterador de bucket para a sequência controlada.|
|`pointer`|O tipo de um ponteiro para um elemento.|
|`reference`|O tipo de uma referência para um elemento.|
|`size_type`|O tipo de uma distância sem sinal entre dois elementos.|
|`value_type`|O tipo de um elemento.|

### <a name="public-constructors"></a>Construtores públicos

|Nome|Descrição|
|----------|-----------------|
|[concurrent_unordered_set](#ctor)|Sobrecarregado. Constrói um conjunto simultâneo não ordenado.|

### <a name="public-methods"></a>Métodos públicos

|Nome|Descrição|
|----------|-----------------|
|[hash_function](#hash_function)|Retorna o objeto de função de hash armazenado.|
|[insert](#insert)|Sobrecarregado. Adiciona elementos ao `concurrent_unordered_set` objeto.|
|[key_eq](#key_eq)|Retorna o objeto da função de comparação de igualdade armazenada.|
|[permuta](#swap)|Alterna o conteúdo de dois objetos de `concurrent_unordered_set` . Esse método não é seguro para simultaneidade.|
|[unsafe_erase](#unsafe_erase)|Sobrecarregado. Remove elementos do nas `concurrent_unordered_set` posições especificadas. Esse método não é seguro para simultaneidade.|

### <a name="public-operators"></a>Operadores públicos

|Nome|Descrição|
|----------|-----------------|
|[operador =](#operator_eq)|Sobrecarregado. Atribui o conteúdo de outro `concurrent_unordered_set` objeto a este. Esse método não é seguro para simultaneidade.|

## <a name="remarks"></a>Comentários

Para obter informações detalhadas sobre a `concurrent_unordered_set` classe, consulte [contêineres e objetos paralelos](../../../parallel/concrt/parallel-containers-and-objects.md).

## <a name="inheritance-hierarchy"></a>Hierarquia de herança

`_Traits`

`_Concurrent_hash`

`concurrent_unordered_set`

## <a name="requirements"></a>Requisitos

**Cabeçalho:** concurrent_unordered_set. h

**Namespace:** simultaneidade

## <a name="begin"></a><a name="begin"></a>Comece

Retorna um iterador que aponta para o primeiro elemento no contêiner simultâneo. Esse método é seguro em simultaneidade.

```cpp
iterator begin();

const_iterator begin() const;
```

### <a name="return-value"></a>Valor retornado

Um iterador para o primeiro elemento no contêiner simultâneo.

## <a name="cbegin"></a><a name="cbegin"></a>cbegin

Retorna um iterador const apontando para o primeiro elemento no contêiner simultâneo. Esse método é seguro em simultaneidade.

```cpp
const_iterator cbegin() const;
```

### <a name="return-value"></a>Valor retornado

Um iterador const para o primeiro elemento no contêiner simultâneo.

## <a name="cend"></a><a name="cend"></a>cend

Retorna um iterador const apontando para o local com sucesso do último elemento no contêiner simultâneo. Esse método é seguro em simultaneidade.

```cpp
const_iterator cend() const;
```

### <a name="return-value"></a>Valor retornado

Um iterador const para o local que obteve o último elemento no contêiner simultâneo.

## <a name="clear"></a><a name="clear"></a>formatação

Apaga todos os elementos no contêiner simultâneo. Essa função não é segura para simultaneidade.

```cpp
void clear();
```

## <a name="concurrent_unordered_set"></a><a name="ctor"></a>concurrent_unordered_set

Constrói um conjunto simultâneo não ordenado.

```cpp
explicit concurrent_unordered_set(
    size_type _Number_of_buckets = 8,
    const hasher& _Hasher = hasher(),
    const key_equal& key_equality = key_equal(),
    const allocator_type& _Allocator = allocator_type());

concurrent_unordered_set(
    const allocator_type& _Allocator);

template <typename _Iterator>
concurrent_unordered_set(_Iterator first,
    _Iterator last,
    size_type _Number_of_buckets = 8,
    const hasher& _Hasher = hasher(),
    const key_equal& key_equality = key_equal(),
    const allocator_type& _Allocator = allocator_type());

concurrent_unordered_set(
    const concurrent_unordered_set& _Uset);

concurrent_unordered_set(
    const concurrent_unordered_set& _Uset,
    const allocator_type& _Allocator);

concurrent_unordered_set(
    concurrent_unordered_set&& _Uset);
```

### <a name="parameters"></a>parâmetros

*_Iterator*<br/>
O tipo do iterador de entrada.

*_Number_of_buckets*<br/>
O número inicial de buckets para esse conjunto não ordenado.

*_Hasher*<br/>
A função de hash para esse conjunto não ordenado.

*key_equality*<br/>
A função de comparação de igualdade para esse conjunto não ordenado.

*_Allocator*<br/>
O alocador para esse conjunto não ordenado.

*first*<br/>
*last*<br/>
*_Uset*<br/>
O `concurrent_unordered_set` objeto de origem do qual copiar ou mover elementos.

### <a name="remarks"></a>Comentários

Todos os construtores armazenam um objeto `_Allocator` de alocador e inicializam o conjunto não ordenado.

O primeiro construtor Especifica um conjunto inicial vazio e especifica explicitamente o número de buckets, a função de hash, a função de igualdade e o tipo de alocador a ser usado.

O segundo construtor Especifica um alocador para o conjunto não ordenado.

O terceiro construtor Especifica valores fornecidos pelo intervalo do iterador [ `_Begin` , `_End` ).

Os quarto e quinto construtores especificam uma cópia do conjunto de não ordenado simultâneo `_Uset` .

O último construtor Especifica uma movimentação do conjunto simultâneo não ordenado `_Uset` .

## <a name="count"></a><a name="count"></a>contar

Conta o número de elementos que correspondem a uma chave especificada. Essa função é segura para simultaneidade.

```cpp
size_type count(const key_type& KVal) const;
```

### <a name="parameters"></a>parâmetros

*KVal*<br/>
A chave a ser pesquisada.

### <a name="return-value"></a>Valor retornado

O número de vezes que o número de vezes que a chave aparece no contêiner.

## <a name="empty"></a><a name="empty"></a>esvaziá

Testa se nenhum elemento está presente. Esse método é seguro em simultaneidade.

```cpp
bool empty() const;
```

### <a name="return-value"></a>Valor retornado

**`true`** Se o contêiner simultâneo estiver vazio, **`false`** caso contrário.

### <a name="remarks"></a>Comentários

Na presença de inserções simultâneas, se o contêiner simultâneo está ou não vazio, pode ser alterado imediatamente após chamar essa função, antes que o valor de retorno seja até mesmo lido.

## <a name="end"></a><a name="end"></a>completo

Retorna um iterador que aponta para o local com sucesso do último elemento no contêiner simultâneo. Esse método é seguro em simultaneidade.

```cpp
iterator end();

const_iterator end() const;
```

### <a name="return-value"></a>Valor retornado

Um iterador para o local que obteve o último elemento no contêiner simultâneo.

## <a name="equal_range"></a><a name="equal_range"></a>equal_range

Localiza um intervalo que corresponde a uma chave especificada. Essa função é segura para simultaneidade.

```cpp
std::pair<iterator,
    iterator> equal_range(
    const key_type& KVal);

std::pair<const_iterator,
    const_iterator> equal_range(
    const key_type& KVal) const;
```

### <a name="parameters"></a>parâmetros

*KVal*<br/>
O valor chave a ser pesquisado.

### <a name="return-value"></a>Valor retornado

Um [par](../../../standard-library/pair-structure.md) em que o primeiro elemento é um iterador para o início e o segundo elemento é um iterador até o final do intervalo.

### <a name="remarks"></a>Comentários

É possível que as inserções simultâneas façam com que chaves adicionais sejam inseridas após o iterador de início e antes do iterador final.

## <a name="find"></a><a name="find"></a>considerar

Localiza um elemento que corresponde a uma chave especificada. Essa função é segura para simultaneidade.

```cpp
iterator find(const key_type& KVal);

const_iterator find(const key_type& KVal) const;
```

### <a name="parameters"></a>parâmetros

*KVal*<br/>
O valor chave a ser pesquisado.

### <a name="return-value"></a>Valor retornado

Um iterador que aponta para o local do primeiro elemento que correspondeu à chave fornecida, ou o iterador, `end()` se esse elemento não existir.

## <a name="get_allocator"></a><a name="get_allocator"></a>get_allocator

Retorna o objeto de alocador armazenado para esse contêiner simultâneo. Esse método é seguro em simultaneidade.

```cpp
allocator_type get_allocator() const;
```

### <a name="return-value"></a>Valor retornado

O objeto de alocador armazenado para esse contêiner simultâneo.

## <a name="hash_function"></a><a name="hash_function"></a>hash_function

Retorna o objeto de função de hash armazenado.

```cpp
hasher hash_function() const;
```

### <a name="return-value"></a>Valor retornado

O objeto de função de hash armazenado.

## <a name="insert"></a><a name="insert"></a>inserido

Adiciona elementos ao `concurrent_unordered_set` objeto.

```cpp
std::pair<iterator,
    bool> insert(
    const value_type& value);

iterator insert(
    const_iterator _Where,
    const value_type& value);

template<class _Iterator>
void insert(_Iterator first,
    _Iterator last);

template<class V>
std::pair<iterator,
    bool> insert(
    V&& value);

template<class V>
typename std::enable_if<!std::is_same<const_iterator,
    typename std::remove_reference<V>::type>::value,
    iterator>::type insert(
    const_iterator _Where,
    V&& value);
```

### <a name="parameters"></a>parâmetros

*_Iterator*<br/>
O tipo de iterador usado para inserção.

*L*<br/>
O tipo do valor inserido no conjunto.

*value*<br/>
O valor a ser inserido.

*_Where*<br/>
O local inicial para procurar um ponto de inserção.

*first*<br/>
O início do intervalo a ser inserido.

*last*<br/>
O final do intervalo a ser inserido.

### <a name="return-value"></a>Valor retornado

Um par que contém um iterador e um valor booliano. Para obter mais detalhes, consulte a seção Comentários.

### <a name="remarks"></a>Comentários

A primeira função de membro determina se um elemento X existe na sequência cuja chave tem uma ordenação equivalente à de `value` . Caso contrário, ele cria um elemento X e o inicializa com `value` . A função determina o iterador `where` que designa X. Se ocorrer uma inserção, a função retornará `std::pair(where, true)` . Caso contrário, ele retornará `std::pair(where, false)`.

A segunda função de membro retorna Insert ( `value` ), usando `_Where` como um local inicial dentro da sequência controlada para pesquisar o ponto de inserção.

A terceira função de membro insere a sequência de valores de elemento do intervalo [ `first` , `last` ).

As duas últimas funções de membro têm o mesmo comportamento que as duas primeiras, exceto que `value` é usada para construir o valor inserido.

## <a name="key_eq"></a><a name="key_eq"></a>key_eq

Retorna o objeto da função de comparação de igualdade armazenada.

```cpp
key_equal key_eq() const;
```

### <a name="return-value"></a>Valor retornado

O objeto da função de comparação de igualdade armazenada.

## <a name="load_factor"></a><a name="load_factor"></a>load_factor

Computa e retorna o fator de carga atual do contêiner. O fator de carga é o número de elementos no contêiner dividido pelo número de buckets.

```cpp
float load_factor() const;
```

### <a name="return-value"></a>Valor retornado

O fator de carga para o contêiner.

## <a name="max_load_factor"></a><a name="max_load_factor"></a>max_load_factor

Obtém ou define o fator de carga máximo do contêiner. O fator de carga máximo é o maior número de elementos do que pode estar em qualquer Bucket antes que o contêiner aumente sua tabela interna.

```cpp
float max_load_factor() const;

void max_load_factor(float _Newmax);
```

### <a name="parameters"></a>parâmetros

`_Newmax`

### <a name="return-value"></a>Valor retornado

A primeira função membro retorna o fator de carga máxima armazenado. A segunda função de membro não retorna um valor, mas gera uma exceção [out_of_range](../../../standard-library/out-of-range-class.md) se o fator de carga fornecido é inválido..

## <a name="max_size"></a><a name="max_size"></a>max_size

Retorna o tamanho máximo do contêiner simultâneo, determinado pelo alocador. Esse método é seguro em simultaneidade.

```cpp
size_type max_size() const;
```

### <a name="return-value"></a>Valor retornado

O número máximo de elementos que podem ser inseridos nesse contêiner simultâneo.

### <a name="remarks"></a>Comentários

Esse valor de limite superior pode realmente ser maior do que o que o contêiner pode realmente manter.

## <a name="operator"></a><a name="operator_eq"></a>operador =

Atribui o conteúdo de outro `concurrent_unordered_set` objeto a este. Esse método não é seguro para simultaneidade.

```cpp
concurrent_unordered_set& operator= (const concurrent_unordered_set& _Uset);

concurrent_unordered_set& operator= (concurrent_unordered_set&& _Uset);
```

### <a name="parameters"></a>parâmetros

*_Uset*<br/>
O objeto `concurrent_unordered_set` de origem.

### <a name="return-value"></a>Valor retornado

Uma referência a este `concurrent_unordered_set` objeto.

### <a name="remarks"></a>Comentários

Depois de apagar todos os elementos existentes em um conjunto não ordenado simultâneo, o `operator=` copia ou move o conteúdo do `_Uset` para o conjunto não ordenado simultâneo.

## <a name="rehash"></a><a name="rehash"></a>prolongar

Recria a tabela de hash.

```cpp
void rehash(size_type _Buckets);
```

### <a name="parameters"></a>parâmetros

*_Buckets*<br/>
O número desejado de buckets.

### <a name="remarks"></a>Comentários

A função membro altera o número de buckets para que seja pelo menos `_Buckets` e recria a tabela de hash, conforme necessário. O número de buckets deve ser uma potência de 2. Se não for uma potência de 2, ela será arredondada para a próxima maior potência de 2.

Ele lançará uma exceção [out_of_range](../../../standard-library/out-of-range-class.md) se o número de buckets for inválido (0 ou maior que o número máximo de buckets).

## <a name="size"></a><a name="size"></a>tamanho

Retorna o número de elementos neste contêiner simultâneo. Esse método é seguro em simultaneidade.

```cpp
size_type size() const;
```

### <a name="return-value"></a>Valor retornado

O número de itens no contêiner.

### <a name="remarks"></a>Comentários

Na presença de inserções simultâneas, o número de elementos no contêiner simultâneo pode ser alterado imediatamente após chamar essa função, antes que o valor de retorno seja até mesmo lido.

## <a name="swap"></a><a name="swap"></a>permuta

Alterna o conteúdo de dois objetos de `concurrent_unordered_set` . Esse método não é seguro para simultaneidade.

```cpp
void swap(concurrent_unordered_set& _Uset);
```

### <a name="parameters"></a>parâmetros

*_Uset*<br/>
O `concurrent_unordered_set` objeto com o qual trocar.

## <a name="unsafe_begin"></a><a name="unsafe_begin"></a>unsafe_begin

Retorna um iterador para o primeiro elemento neste contêiner para um Bucket específico.

```cpp
local_iterator unsafe_begin(size_type _Bucket);

const_local_iterator unsafe_begin(size_type _Bucket) const;
```

### <a name="parameters"></a>parâmetros

*_Bucket*<br/>
O índice de Bucket.

### <a name="return-value"></a>Valor retornado

Um iterador que aponta para o início do Bucket.

## <a name="unsafe_bucket"></a><a name="unsafe_bucket"></a>unsafe_bucket

Retorna o índice de Bucket que uma chave específica mapeia para neste contêiner.

```cpp
size_type unsafe_bucket(const key_type& KVal) const;
```

### <a name="parameters"></a>parâmetros

*KVal*<br/>
A chave de elemento que está sendo pesquisada.

### <a name="return-value"></a>Valor retornado

O índice de Bucket para a chave neste contêiner.

## <a name="unsafe_bucket_count"></a><a name="unsafe_bucket_count"></a>unsafe_bucket_count

Retorna o número atual de buckets neste contêiner.

```cpp
size_type unsafe_bucket_count() const;
```

### <a name="return-value"></a>Valor retornado

O número atual de buckets neste contêiner.

## <a name="unsafe_bucket_size"></a><a name="unsafe_bucket_size"></a>unsafe_bucket_size

Retorna o número de itens em um Bucket específico deste contêiner.

```cpp
size_type unsafe_bucket_size(size_type _Bucket);
```

### <a name="parameters"></a>parâmetros

*_Bucket*<br/>
O Bucket a ser pesquisado.

### <a name="return-value"></a>Valor retornado

O número atual de buckets neste contêiner.

## <a name="unsafe_cbegin"></a><a name="unsafe_cbegin"></a>unsafe_cbegin

Retorna um iterador para o primeiro elemento neste contêiner para um Bucket específico.

```cpp
const_local_iterator unsafe_cbegin(size_type _Bucket) const;
```

### <a name="parameters"></a>parâmetros

*_Bucket*<br/>
O índice de Bucket.

### <a name="return-value"></a>Valor retornado

Um iterador que aponta para o início do Bucket.

## <a name="unsafe_cend"></a><a name="unsafe_cend"></a>unsafe_cend

Retorna um iterador para o local com sucesso no último elemento em um Bucket específico.

```cpp
const_local_iterator unsafe_cend(size_type _Bucket) const;
```

### <a name="parameters"></a>parâmetros

*_Bucket*<br/>
O índice de Bucket.

### <a name="return-value"></a>Valor retornado

Um iterador que aponta para o início do Bucket.

## <a name="unsafe_end"></a><a name="unsafe_end"></a>unsafe_end

Retorna um iterador para o último elemento neste contêiner para um Bucket específico.

```cpp
local_iterator unsafe_end(size_type _Bucket);

const_local_iterator unsafe_end(size_type _Bucket) const;
```

### <a name="parameters"></a>parâmetros

*_Bucket*<br/>
O índice de Bucket.

### <a name="return-value"></a>Valor retornado

Um iterador que aponta para o final do Bucket.

## <a name="unsafe_erase"></a><a name="unsafe_erase"></a>unsafe_erase

Remove elementos do nas `concurrent_unordered_set` posições especificadas. Esse método não é seguro para simultaneidade.

```cpp
iterator unsafe_erase(
    const_iterator _Where);

size_type unsafe_erase(
    const key_type& KVal);

iterator unsafe_erase(
    const_iterator first,
    const_iterator last);
```

### <a name="parameters"></a>parâmetros

*_Where*<br/>
A posição do iterador a ser apagada.

*KVal*<br/>
O valor de chave a ser apagado.

*first*<br/>
*last*<br/>
Iteradores.

### <a name="return-value"></a>Valor retornado

As duas primeiras funções de membro retornam um iterador que designa o primeiro elemento restante além de todos os elementos removidos, ou [end](#end)() se nenhum elemento desse tipo existir. A terceira função de membro retorna o número de elementos que ele remove.

### <a name="remarks"></a>Comentários

A primeira função de membro remove o elemento apontado por `_Where` . A segunda função de membro remove os elementos no intervalo [ `_Begin` , `_End` ).

A terceira função de membro remove os elementos no intervalo delimitado por [equal_range](#equal_range)(KVal).

## <a name="unsafe_max_bucket_count"></a><a name="unsafe_max_bucket_count"></a>unsafe_max_bucket_count

Retorna o número máximo de buckets neste contêiner.

```cpp
size_type unsafe_max_bucket_count() const;
```

### <a name="return-value"></a>Valor retornado

O número máximo de buckets neste contêiner.

## <a name="see-also"></a>Confira também

[Namespace de simultaneidade](concurrency-namespace.md)<br/>
[Contêineres e objetos paralelos](../../../parallel/concrt/parallel-containers-and-objects.md)
