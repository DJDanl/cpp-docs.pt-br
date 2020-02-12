---
title: Classe concurrent_unordered_map
ms.date: 11/04/2016
f1_keywords:
- concurrent_unordered_map
- CONCURRENT_UNORDERED_MAP/concurrency::concurrent_unordered_map
- CONCURRENT_UNORDERED_MAP/concurrency::concurrent_unordered_map::concurrent_unordered_map
- CONCURRENT_UNORDERED_MAP/concurrency::concurrent_unordered_map::at
- CONCURRENT_UNORDERED_MAP/concurrency::concurrent_unordered_map::hash_function
- CONCURRENT_UNORDERED_MAP/concurrency::concurrent_unordered_map::insert
- CONCURRENT_UNORDERED_MAP/concurrency::concurrent_unordered_map::key_eq
- CONCURRENT_UNORDERED_MAP/concurrency::concurrent_unordered_map::swap
- CONCURRENT_UNORDERED_MAP/concurrency::concurrent_unordered_map::unsafe_erase
helpviewer_keywords:
- concurrent_unordered_map class
ms.assetid: b2d879dd-87ef-4af9-a266-a5443fd538b8
ms.openlocfilehash: 04fdfb767645cb2db31a453a2378881a8b3e3a04
ms.sourcegitcommit: a8ef52ff4a4944a1a257bdaba1a3331607fb8d0f
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 02/11/2020
ms.locfileid: "77143162"
---
# <a name="concurrent_unordered_map-class"></a>Classe concurrent_unordered_map

A classe `concurrent_unordered_map` é um contêiner protegido por simultaneidade que controla uma sequência de comprimento variável de elementos do tipo `std::pair<const K, _Element_type>`. A sequência é representada de uma maneira que permite acréscimo seguro de simultaneidade, acesso a elemento, acesso de iterador e operações de percurso de iterador. Aqui, a simultaneidade segura significa que os ponteiros ou iteradores são sempre válidos. Não é uma garantia de inicialização de elemento ou de uma ordem de passagem específica.

## <a name="syntax"></a>Sintaxe

```cpp
template <typename K,
    typename _Element_type,
    typename _Hasher = std::hash<K>,
    typename key_equality = std::equal_to<K>,
    typename _Allocator_type = std::allocator<std::pair<const K,
    _Element_type>>
>,
typename key_equality = std::equal_to<K>,
    typename _Allocator_type = std::allocator<std::pair<const K,
    _Element_type>>> class concurrent_unordered_map : public details::_Concurrent_hash<details::_Concurrent_unordered_map_traits<K,
    _Element_type,
details::_Hash_compare<K,
    _Hasher,
key_equality>,
    _Allocator_type,
false>>;
```

### <a name="parameters"></a>Parâmetros

*K*<br/>
O tipo principal.

*_Element_type*<br/>
O tipo mapeado.

*_Hasher*<br/>
O tipo de objeto da função de hash. Esse argumento é opcional e o valor padrão é `std::hash<K>`.

*key_equality*<br/>
O tipo de objeto da função de comparação de igualdade. Esse argumento é opcional e o valor padrão é `std::equal_to<K>`.

*_Allocator_type*<br/>
O tipo que representa o objeto alocador armazenado que encapsula detalhes sobre a alocação e desalocação de memória para o mapa não ordenado simultâneo. Esse argumento é opcional e o valor padrão é `std::allocator<std::pair<K`, `_Element_type>>`.

## <a name="members"></a>Membros

### <a name="public-typedefs"></a>Typedefs Públicos

|{1&gt;Nome&lt;1}|Descrição|
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
|`mapped_type`|O tipo de um valor mapeado associado a cada chave.|
|`pointer`|O tipo de um ponteiro para um elemento.|
|`reference`|O tipo de uma referência para um elemento.|
|`size_type`|O tipo de uma distância sem sinal entre dois elementos.|
|`value_type`|O tipo de um elemento.|

### <a name="public-constructors"></a>Construtores públicos

|{1&gt;Nome&lt;1}|Descrição|
|----------|-----------------|
|[concurrent_unordered_map](#ctor)|Sobrecarregado. Constrói um mapa não ordenado simultâneo.|

### <a name="public-methods"></a>Métodos públicos

|{1&gt;Nome&lt;1}|Descrição|
|----------|-----------------|
|[at](#at)|Sobrecarregado. Localiza um elemento em um `concurrent_unordered_map` com um valor de chave especificado. Esse método é seguro para simultaneidade.|
|[hash_function](#hash_function)|Obtém o objeto armazenado da função de hash.|
|[insert](#insert)|Sobrecarregado. Adiciona elementos ao objeto `concurrent_unordered_map`.|
|[key_eq](#key_eq)|Obtém o objeto da função de comparação de igualdade armazenada.|
|[swap](#swap)|Alterna o conteúdo de dois objetos de `concurrent_unordered_map` . Esse método não é seguro para simultaneidade.|
|[unsafe_erase](#unsafe_erase)|Sobrecarregado. Remove elementos da `concurrent_unordered_map` em posições especificadas. Esse método não é seguro para simultaneidade.|

### <a name="public-operators"></a>Operadores públicos

|{1&gt;Nome&lt;1}|Descrição|
|----------|-----------------|
|[operator\[\]](#operator_at)|Sobrecarregado. Localiza ou insere um elemento com a chave especificada. Esse método é seguro para simultaneidade.|
|[operator=](#operator_eq)|Sobrecarregado. Atribui o conteúdo de outro objeto de `concurrent_unordered_map` a este. Esse método não é seguro para simultaneidade.|

## <a name="remarks"></a>Comentários

Para obter informações detalhadas sobre a classe `concurrent_unordered_map`, consulte [contêineres e objetos paralelos](../../../parallel/concrt/parallel-containers-and-objects.md).

## <a name="inheritance-hierarchy"></a>Hierarquia de herança

`_Traits`

`_Concurrent_hash`

`concurrent_unordered_map`

## <a name="requirements"></a>{1&gt;{2&gt;Requisitos&lt;2}&lt;1}

**Cabeçalho:** concurrent_unordered_map. h

**Namespace:** simultaneidade

## <a name="at"></a>no

Localiza um elemento em um `concurrent_unordered_map` com um valor de chave especificado. Esse método é seguro para simultaneidade.

```cpp
mapped_type& at(const key_type& KVal);

const mapped_type& at(const key_type& KVal) const;
```

### <a name="parameters"></a>Parâmetros

*KVal*<br/>
O valor de chave a ser localizado.

### <a name="return-value"></a>Valor retornado

Uma referência ao valor de dados do elemento encontrado.

### <a name="remarks"></a>Comentários

Se o valor da chave de argumento não for encontrado, a função lançará um objeto da classe `out_of_range`.

## <a name="begin"></a>Comece

Retorna um iterador que aponta para o primeiro elemento no contêiner simultâneo. Esse método é seguro em simultaneidade.

```cpp
iterator begin();

const_iterator begin() const;
```

### <a name="return-value"></a>Valor retornado

Um iterador para o primeiro elemento no contêiner simultâneo.

## <a name="cbegin"></a>cbegin

Retorna um iterador const apontando para o primeiro elemento no contêiner simultâneo. Esse método é seguro em simultaneidade.

```cpp
const_iterator cbegin() const;
```

### <a name="return-value"></a>Valor retornado

Um iterador const para o primeiro elemento no contêiner simultâneo.

## <a name="cend"></a>cend

Retorna um iterador const apontando para o local com sucesso do último elemento no contêiner simultâneo. Esse método é seguro em simultaneidade.

```cpp
const_iterator cend() const;
```

### <a name="return-value"></a>Valor retornado

Um iterador const para o local que obteve o último elemento no contêiner simultâneo.

## <a name="clear"></a>formatação

Apaga todos os elementos no contêiner simultâneo. Essa função não é segura para simultaneidade.

```cpp
void clear();
```

## <a name="ctor"></a>concurrent_unordered_map

Constrói um mapa não ordenado simultâneo.

```cpp
explicit concurrent_unordered_map(
    size_type _Number_of_buckets = 8,
    const hasher& _Hasher = hasher(),
    const key_equal& key_equality = key_equal(),
    const allocator_type& _Allocator = allocator_type());

concurrent_unordered_map(
    const allocator_type& _Allocator);

template <typename _Iterator>
concurrent_unordered_map(_Iterator _Begin,
    _Iterator _End,
    size_type _Number_of_buckets = 8,
    const hasher& _Hasher = hasher(),
    const key_equal& key_equality = key_equal(),
    const allocator_type& _Allocator = allocator_type());

concurrent_unordered_map(
    const concurrent_unordered_map& _Umap);

concurrent_unordered_map(
    const concurrent_unordered_map& _Umap,
    const allocator_type& _Allocator);

concurrent_unordered_map(
    concurrent_unordered_map&& _Umap);
```

### <a name="parameters"></a>Parâmetros

*_Iterator*<br/>
O tipo do iterador de entrada.

*_Number_of_buckets*<br/>
O número inicial de buckets para este mapa não ordenado.

*_Hasher*<br/>
A função de hash para este mapa não ordenado.

*key_equality*<br/>
A função de comparação de igualdade para este mapa não ordenado.

*_Allocator*<br/>
O alocador para este mapa não ordenado.

*_Begin*<br/>
A posição do primeiro elemento no intervalo de elementos a serem copiados.

*_End*<br/>
A posição do primeiro elemento além do intervalo de elementos a serem copiados.

*_Umap*<br/>
O objeto de `concurrent_unordered_map` de origem para copiar ou mover elementos.

### <a name="remarks"></a>Comentários

Todos os construtores armazenam um objeto de alocador `_Allocator` e inicializam o mapa não ordenado.

O primeiro construtor Especifica um mapa inicial vazio e especifica explicitamente o número de buckets, a função de hash, a função de igualdade e o tipo de alocador a ser usado.

O segundo construtor Especifica um alocador para o mapa não ordenado.

O terceiro construtor Especifica valores fornecidos pelo intervalo do iterador [`_Begin`, `_End`).

Os quarto e quinto construtores especificam uma cópia do `_Umap`do mapa não ordenado simultâneo.

O último construtor Especifica uma movimentação do `_Umap`do mapa não ordenado simultâneo.

## <a name="count"></a>contar

Conta o número de elementos que correspondem a uma chave especificada. Essa função é segura para simultaneidade.

```cpp
size_type count(const key_type& KVal) const;
```

### <a name="parameters"></a>Parâmetros

*KVal*<br/>
A chave a procurar.

### <a name="return-value"></a>Valor retornado

O número de vezes que o número de vezes que a chave aparece no contêiner.

## <a name="empty"></a>esvaziá

Testa se nenhum elemento está presente. Esse método é seguro em simultaneidade.

```cpp
bool empty() const;
```

### <a name="return-value"></a>Valor retornado

**true** se o contêiner simultâneo estiver vazio; caso contrário, **false** .

### <a name="remarks"></a>Comentários

Na presença de inserções simultâneas, se o contêiner simultâneo está ou não vazio, pode ser alterado imediatamente após chamar essa função, antes que o valor de retorno seja até mesmo lido.

## <a name="end"></a>completo

Retorna um iterador que aponta para o local com sucesso do último elemento no contêiner simultâneo. Esse método é seguro em simultaneidade.

```cpp
iterator end();

const_iterator end() const;
```

### <a name="return-value"></a>Valor retornado

Um iterador para o local que obteve o último elemento no contêiner simultâneo.

## <a name="equal_range"></a>equal_range

Localiza um intervalo que corresponde a uma chave especificada. Essa função é segura para simultaneidade.

```cpp
std::pair<iterator,
    iterator> equal_range(
    const key_type& KVal);

std::pair<const_iterator,
    const_iterator> equal_range(
    const key_type& KVal) const;
```

### <a name="parameters"></a>Parâmetros

*KVal*<br/>
O valor chave a ser pesquisado.

### <a name="return-value"></a>Valor retornado

Um [par](../../../standard-library/pair-structure.md) em que o primeiro elemento é um iterador para o início e o segundo elemento é um iterador até o final do intervalo.

### <a name="remarks"></a>Comentários

É possível que as inserções simultâneas façam com que chaves adicionais sejam inseridas após o iterador de início e antes do iterador final.

## <a name="find"></a>considerar

Localiza um elemento que corresponde a uma chave especificada. Essa função é segura para simultaneidade.

```cpp
iterator find(const key_type& KVal);

const_iterator find(const key_type& KVal) const;
```

### <a name="parameters"></a>Parâmetros

*KVal*<br/>
O valor chave a ser pesquisado.

### <a name="return-value"></a>Valor retornado

Um iterador apontando para o local do primeiro elemento que correspondeu à chave fornecida, ou o iterador `end()` se esse elemento não existir.

## <a name="get_allocator"></a>get_allocator

Retorna o objeto de alocador armazenado para esse contêiner simultâneo. Esse método é seguro em simultaneidade.

```cpp
allocator_type get_allocator() const;
```

### <a name="return-value"></a>Valor retornado

O objeto de alocador armazenado para esse contêiner simultâneo.

## <a name="hash_function"></a>hash_function

Obtém o objeto armazenado da função de hash.

```cpp
hasher hash_function() const;
```

### <a name="return-value"></a>Valor retornado

O objeto de função de hash armazenado.

## <a name="insert"></a>inserido

Adiciona elementos ao objeto `concurrent_unordered_map`.

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

### <a name="parameters"></a>Parâmetros

*_Iterator*<br/>
O tipo de iterador usado para inserção.

*V*<br/>
O tipo do valor inserido no mapa.

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

A primeira função de membro determina se um elemento X existe na sequência cuja chave tem uma ordenação equivalente à de `value`. Caso contrário, ele cria um elemento X e o inicializa com `value`. A função determina o iterador `where` que designa X. Se ocorrer uma inserção, a função retornará `std::pair(where, true)`. Caso contrário, ele retornará `std::pair(where, false)`.

A segunda função de membro retorna Insert (`value`), usando `_Where` como um local inicial dentro da sequência controlada para pesquisar o ponto de inserção.

A terceira função de membro insere a sequência de valores de elemento do intervalo [`first`, `last`).

As duas últimas funções de membro têm o mesmo comportamento que as duas primeiras, exceto que `value` é usada para construir o valor inserido.

## <a name="key_eq"></a>key_eq

Obtém o objeto da função de comparação de igualdade armazenada.

```cpp
key_equal key_eq() const;
```

### <a name="return-value"></a>Valor retornado

O objeto da função de comparação de igualdade armazenada.

## <a name="load_factor"></a>load_factor

Computa e retorna o fator de carga atual do contêiner. O fator de carga é o número de elementos no contêiner dividido pelo número de buckets.

```cpp
float load_factor() const;
```

### <a name="return-value"></a>Valor retornado

O fator de carga para o contêiner.

## <a name="max_load_factor"></a>max_load_factor

Obtém ou define o fator de carga máximo do contêiner. O fator de carga máximo é o maior número de elementos do que pode estar em qualquer Bucket antes que o contêiner aumente sua tabela interna.

```cpp
float max_load_factor() const;

void max_load_factor(float _Newmax);
```

### <a name="parameters"></a>Parâmetros

`_Newmax`

### <a name="return-value"></a>Valor retornado

A primeira função membro retorna o fator de carga máxima armazenado. A segunda função de membro não retorna um valor, mas gera uma exceção [out_of_range](../../../standard-library/out-of-range-class.md) se o fator de carga fornecido é inválido..

## <a name="max_size"></a>max_size

Retorna o tamanho máximo do contêiner simultâneo, determinado pelo alocador. Esse método é seguro em simultaneidade.

```cpp
size_type max_size() const;
```

### <a name="return-value"></a>Valor retornado

O número máximo de elementos que podem ser inseridos nesse contêiner simultâneo.

### <a name="remarks"></a>Comentários

Esse valor de limite superior pode realmente ser maior do que o que o contêiner pode realmente manter.

## <a name="operator_at"></a>operador []

Localiza ou insere um elemento com a chave especificada. Esse método é seguro para simultaneidade.

```cpp
mapped_type& operator[](const key_type& kval);

mapped_type& operator[](key_type&& kval);
```

### <a name="parameters"></a>Parâmetros

*KVal*<br/>
O valor de chave para

Localizar ou inserir.

### <a name="return-value"></a>Valor retornado

Uma referência ao valor de dados do elemento encontrado ou inserido.

### <a name="remarks"></a>Comentários

Se o valor de chave do argumento não for encontrado, ele será inserido juntamente com o valor padrão do tipo de dados.

`operator[]` pode ser usado para inserir elementos em um mapa `m` usando `m[key] = DataValue;`, em que `DataValue` é o valor da `mapped_type` do elemento com um valor de chave de `key`.

Ao usar `operator[]` para inserir elementos, a referência retornada não indica se uma inserção está alterando um elemento preexistente ou criando outro. As funções de membro `find` e [Insert](#insert) podem ser usadas para determinar se um elemento com uma chave especificada já está presente antes de uma inserção.

## <a name="operator_eq"></a>operador =

Atribui o conteúdo de outro objeto de `concurrent_unordered_map` a este. Esse método não é seguro para simultaneidade.

```cpp
concurrent_unordered_map& operator= (const concurrent_unordered_map& _Umap);

concurrent_unordered_map& operator= (concurrent_unordered_map&& _Umap);
```

### <a name="parameters"></a>Parâmetros

*_Umap*<br/>
O objeto `concurrent_unordered_map` de origem.

### <a name="return-value"></a>Valor retornado

Uma referência a este objeto de `concurrent_unordered_map`.

### <a name="remarks"></a>Comentários

Depois de apagar quaisquer elementos existentes de um vetor simultâneo, o `operator=` copiar ou mover o conteúdo de `_Umap` para o vetor simultâneo.

## <a name="rehash"></a>prolongar

Recria a tabela de hash.

```cpp
void rehash(size_type _Buckets);
```

### <a name="parameters"></a>Parâmetros

*_Buckets*<br/>
O número desejado de buckets.

### <a name="remarks"></a>Comentários

A função membro altera o número de buckets para que seja pelo menos `_Buckets` e recria a tabela de hash, conforme necessário. O número de buckets deve ser uma potência de 2. Se não for uma potência de 2, ela será arredondada para a próxima maior potência de 2.

Ele lançará uma exceção [out_of_range](../../../standard-library/out-of-range-class.md) se o número de buckets for inválido (0 ou maior que o número máximo de buckets).

## <a name="size"></a>tamanho

Retorna o número de elementos neste contêiner simultâneo. Esse método é seguro em simultaneidade.

```cpp
size_type size() const;
```

### <a name="return-value"></a>Valor retornado

O número de itens no contêiner.

### <a name="remarks"></a>Comentários

Na presença de inserções simultâneas, o número de elementos no contêiner simultâneo pode ser alterado imediatamente após chamar essa função, antes que o valor de retorno seja até mesmo lido.

## <a name="swap"></a>permuta

Alterna o conteúdo de dois objetos de `concurrent_unordered_map` . Esse método não é seguro para simultaneidade.

```cpp
void swap(concurrent_unordered_map& _Umap);
```

### <a name="parameters"></a>Parâmetros

*_Umap*<br/>
O objeto `concurrent_unordered_map` com o qual trocar.

## <a name="unsafe_begin"></a>unsafe_begin

Retorna um iterador para o primeiro elemento neste contêiner para um Bucket específico.

```cpp
local_iterator unsafe_begin(size_type _Bucket);

const_local_iterator unsafe_begin(size_type _Bucket) const;
```

### <a name="parameters"></a>Parâmetros

*_Bucket*<br/>
O índice de Bucket.

### <a name="return-value"></a>Valor retornado

Um iterador que aponta para o início do Bucket.

## <a name="unsafe_bucket"></a>unsafe_bucket

Retorna o índice de Bucket que uma chave específica mapeia para neste contêiner.

```cpp
size_type unsafe_bucket(const key_type& KVal) const;
```

### <a name="parameters"></a>Parâmetros

*KVal*<br/>
A chave de elemento que está sendo pesquisada.

### <a name="return-value"></a>Valor retornado

O índice de Bucket para a chave neste contêiner.

## <a name="unsafe_bucket_count"></a>unsafe_bucket_count

Retorna o número atual de buckets neste contêiner.

```cpp
size_type unsafe_bucket_count() const;
```

### <a name="return-value"></a>Valor retornado

O número atual de buckets neste contêiner.

## <a name="unsafe_bucket_size"></a>unsafe_bucket_size

Retorna o número de itens em um Bucket específico deste contêiner.

```cpp
size_type unsafe_bucket_size(size_type _Bucket);
```

### <a name="parameters"></a>Parâmetros

*_Bucket*<br/>
O Bucket a ser pesquisado.

### <a name="return-value"></a>Valor retornado

O número atual de buckets neste contêiner.

## <a name="unsafe_cbegin"></a>unsafe_cbegin

Retorna um iterador para o primeiro elemento neste contêiner para um Bucket específico.

```cpp
const_local_iterator unsafe_cbegin(size_type _Bucket) const;
```

### <a name="parameters"></a>Parâmetros

*_Bucket*<br/>
O índice de Bucket.

### <a name="return-value"></a>Valor retornado

Um iterador que aponta para o início do Bucket.

## <a name="unsafe_cend"></a>unsafe_cend

Retorna um iterador para o local com sucesso no último elemento em um Bucket específico.

```cpp
const_local_iterator unsafe_cend(size_type _Bucket) const;
```

### <a name="parameters"></a>Parâmetros

*_Bucket*<br/>
O índice de Bucket.

### <a name="return-value"></a>Valor retornado

Um iterador que aponta para o início do Bucket.

## <a name="unsafe_end"></a>unsafe_end

Retorna um iterador para o último elemento neste contêiner para um Bucket específico.

```cpp
local_iterator unsafe_end(size_type _Bucket);

const_local_iterator unsafe_end(size_type _Bucket) const;
```

### <a name="parameters"></a>Parâmetros

*_Bucket*<br/>
O índice de Bucket.

### <a name="return-value"></a>Valor retornado

Um iterador que aponta para o final do Bucket.

## <a name="unsafe_erase"></a>unsafe_erase

Remove elementos da `concurrent_unordered_map` em posições especificadas. Esse método não é seguro para simultaneidade.

```cpp
iterator unsafe_erase(
    const_iterator _Where);

iterator unsafe_erase(
    const_iterator _Begin,
    const_iterator _End);

size_type unsafe_erase(
    const key_type& KVal);
```

### <a name="parameters"></a>Parâmetros

*_Where*<br/>
A posição do iterador a ser apagada.

*_Begin*<br/>
A posição do primeiro elemento no intervalo de elementos a ser apagado.

*_End*<br/>
A posição do primeiro elemento além do intervalo de elementos a ser apagado.

*KVal*<br/>
O valor de chave a ser apagado.

### <a name="return-value"></a>Valor retornado

As duas primeiras funções de membro retornam um iterador que designa o primeiro elemento restante além de todos os elementos removidos, ou `concurrent_unordered_map::end`() se nenhum elemento desse tipo existir. A terceira função de membro retorna o número de elementos que ele remove.

### <a name="remarks"></a>Comentários

A primeira função de membro remove o elemento da sequência controlada apontada por `_Where`. A segunda função de membro remove os elementos no intervalo [`_Begin`, `_End`).

A terceira função de membro remove os elementos no intervalo delimitado por `concurrent_unordered_map::equal_range`(KVal).

## <a name="unsafe_max_bucket_count"></a>unsafe_max_bucket_count

Retorna o número máximo de buckets neste contêiner.

```cpp
size_type unsafe_max_bucket_count() const;
```

### <a name="return-value"></a>Valor retornado

O número máximo de buckets neste contêiner.

## <a name="see-also"></a>Consulte também

[Namespace de simultaneidade](concurrency-namespace.md)<br/>
[Contêineres e objetos em paralelo](../../../parallel/concrt/parallel-containers-and-objects.md)
