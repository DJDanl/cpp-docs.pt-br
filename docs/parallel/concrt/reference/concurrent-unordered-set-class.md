---
title: Classe concurrent_unordered_set | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology: cpp-windows
ms.tgt_pltfrm: 
ms.topic: article
f1_keywords:
- concurrent_unordered_set
- CONCURRENT_UNORDERED_SET/concurrency::concurrent_unordered_set
- CONCURRENT_UNORDERED_SET/concurrency::concurrent_unordered_set::concurrent_unordered_set
- CONCURRENT_UNORDERED_SET/concurrency::concurrent_unordered_set::hash_function
- CONCURRENT_UNORDERED_SET/concurrency::concurrent_unordered_set::insert
- CONCURRENT_UNORDERED_SET/concurrency::concurrent_unordered_set::key_eq
- CONCURRENT_UNORDERED_SET/concurrency::concurrent_unordered_set::swap
- CONCURRENT_UNORDERED_SET/concurrency::concurrent_unordered_set::unsafe_erase
dev_langs: C++
helpviewer_keywords: concurrent_unordered_set class
ms.assetid: c61f9a9a-4fd9-491a-9251-e300737ecf4b
caps.latest.revision: "12"
author: mikeblome
ms.author: mblome
manager: ghogen
ms.openlocfilehash: cdf70daec8e357f6da456cab5fe71760b7734fe3
ms.sourcegitcommit: ebec1d449f2bd98aa851667c2bfeb7e27ce657b2
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/24/2017
---
# <a name="concurrentunorderedset-class"></a>Classe concurrent_unordered_set
O `concurrent_unordered_set` classe é um contêiner de simultaneidade-safe que controla uma sequência de comprimento variável de elementos do tipo K. A sequência é representada de forma que permite a simultaneidade safe acrescentar, acesso de elemento, acesso de iterador e operações de passagem de iterador.  
  
## <a name="syntax"></a>Sintaxe  
  
```
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
  
#### <a name="parameters"></a>Parâmetros  
 `K`  
 O tipo principal.  
  
 `_Hasher`  
 O tipo de objeto da função de hash. Esse argumento é opcional e o valor padrão é `std::hash<K>`.  
  
 `key_equality`  
 O tipo de objeto da função de comparação de igualdade. Esse argumento é opcional e o valor padrão é `std::equal_to<K>`.  
  
 `_Allocator_type`  
 O tipo que representa o objeto de alocador armazenados que encapsula os detalhes sobre a alocação e desalocação de memória para o conjunto não ordenado simultânea. Esse argumento é opcional e o valor padrão é `std::allocator<K>`.  
  
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
|[concurrent_unordered_set](#ctor)|Sobrecarregado. Constrói um conjunto não ordenado simultâneo.|  
  
### <a name="public-methods"></a>Métodos públicos  
  
|Nome|Descrição|  
|----------|-----------------|  
|[hash_function](#hash_function)|Retorna o objeto de função de hash armazenado.|  
|[insert](#insert)|Sobrecarregado. Adiciona os elementos para o `concurrent_unordered_set` objeto.|  
|[key_eq](#key_eq)|Retorna o objeto de função de comparação de igualdade armazenado.|  
|[swap](#swap)|Alterna o conteúdo de dois `concurrent_unordered_set` objetos. Este método não é seguro de simultaneidade.|  
|[unsafe_erase](#unsafe_erase)|Sobrecarregado. Remove os elementos do `concurrent_unordered_set` em posições especificadas. Este método não é seguro de simultaneidade.|  
  
### <a name="public-operators"></a>Operadores públicos  
  
|Nome|Descrição|  
|----------|-----------------|  
|[operator=](#operator_eq)|Sobrecarregado. Atribui o conteúdo de outro `concurrent_unordered_set` deste objeto. Este método não é seguro de simultaneidade.|  
  
## <a name="remarks"></a>Comentários  
 Para obter informações detalhadas sobre o `concurrent_unordered_set` de classe, consulte [objetos e contêineres paralelos](../../../parallel/concrt/parallel-containers-and-objects.md).  
  
## <a name="inheritance-hierarchy"></a>Hierarquia de herança  
 `_Traits`  
  
 `_Concurrent_hash`  
  
 `concurrent_unordered_set`  
  
## <a name="requirements"></a>Requisitos  
 **Cabeçalho:** concurrent_unordered_set.h  
  
 **Namespace:** simultaneidade  
  
##  <a name="begin"></a>começar 

 Retorna um iterador que aponta para o primeiro elemento no contêiner simultâneo. Esse método é seguro de simultaneidade.  
  
```
iterator begin();

const_iterator begin() const;
```  
  
### <a name="return-value"></a>Valor de retorno  
 Um iterador para o primeiro elemento no contêiner simultâneo.  
  
##  <a name="cbegin"></a>cbegin 

 Retorna um iterador const apontando para o primeiro elemento no contêiner simultâneo. Esse método é seguro de simultaneidade.  
  
```
const_iterator cbegin() const;
```  
  
### <a name="return-value"></a>Valor de retorno  
 Um iterador const para o primeiro elemento no contêiner simultâneo.  
  
##  <a name="cend"></a>cend 

 Retorna um iterador const apontando para o local de êxito do último elemento no contêiner simultâneo. Esse método é seguro de simultaneidade.  
  
```
const_iterator cend() const;
```  
  
### <a name="return-value"></a>Valor de retorno  
 Um iterador const para o local de êxito do último elemento no contêiner simultâneo.  
  
##  <a name="clear"></a>Limpar 

 Apaga todos os elementos no contêiner simultâneo. Essa função não é seguro de simultaneidade.  
  
```
void clear();
```  
  
##  <a name="ctor"></a>concurrent_unordered_set 

 Constrói um conjunto não ordenado simultâneo.  
  
```
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
  
### <a name="parameters"></a>Parâmetros  
 `_Iterator`  
 O tipo do iterador de entrada.  
  
 `_Number_of_buckets`  
 O número inicial de buckets para esse conjunto não ordenado.  
  
 `_Hasher`  
 A função de hash para este conjunto não ordenado.  
  
 `key_equality`  
 A função de comparação de igualdade para este conjunto não ordenado.  
  
 `_Allocator`  
 O alocador para este conjunto não ordenado.  
  
 `first`  
 `last`  
 `_Uset`  
 A fonte `concurrent_unordered_set` objeto para copiar ou mover os elementos do.  
  
### <a name="remarks"></a>Comentários  
 Todos os construtores armazenam um objeto de alocador `_Allocator` e inicializar o conjunto não ordenado.  
  
 O primeiro construtor Especifica um conjunto vazio de inicial e especifica explicitamente o número de buckets, tipo de função de hash, função de igualdade e alocador a ser usado.  
  
 O segundo construtor Especifica um alocador para o conjunto não ordenado.  
  
 O terceiro construtor especifica valores fornecidos pelo intervalo iterator [ `_Begin`, `_End`).  
  
 Os quarto e quinto construtores especificar uma cópia do conjunto não ordenado simultânea `_Uset`.  
  
 O construtor de último especifica um movimento do conjunto não ordenado simultâneo `_Uset`.  
  
##  <a name="count"></a>Contagem 

 Conta o número de elementos de correspondência de uma chave especificada. Essa função é seguro de simultaneidade.  
  
```
size_type count(const key_type& KVal) const;
```  
  
### <a name="parameters"></a>Parâmetros  
 `KVal`  
 A chave a ser pesquisada.  
  
### <a name="return-value"></a>Valor de retorno  
 O número de vezes o número de vezes que a chave aparece no contêiner.  
  
##  <a name="empty"></a>vazio 

 Testa se nenhum elemento está presente. Esse método é seguro de simultaneidade.  
  
```
bool empty() const;
```  
  
### <a name="return-value"></a>Valor de retorno  
 `true`Se o contêiner simultâneo estiver vazio, `false` caso contrário.  
  
### <a name="remarks"></a>Comentários  
 Na presença de inserções simultâneas, ou não o contêiner simultâneo está vazio pode alterar imediatamente após chamar essa função, antes que o valor de retorno é lido ainda.  
  
##  <a name="end"></a>final 

 Retorna um iterador apontando para o local de êxito do último elemento no contêiner simultâneo. Esse método é seguro de simultaneidade.  
  
```
iterator end();

const_iterator end() const;
```  
  
### <a name="return-value"></a>Valor de retorno  
 Um iterador para o local de êxito do último elemento no contêiner simultâneo.  
  
##  <a name="equal_range"></a>equal_range 

 Localiza um intervalo que corresponde a uma chave especificada. Essa função é seguro de simultaneidade.  
  
```
std::pair<iterator,
    iterator> equal_range(
    const key_type& KVal);

std::pair<const_iterator,
    const_iterator> equal_range(
    const key_type& KVal) const;
```  
  
### <a name="parameters"></a>Parâmetros  
 `KVal`  
 O valor da chave para pesquisar.  
  
### <a name="return-value"></a>Valor de retorno  
 Um [par](http://msdn.microsoft.com/en-us/32e72d66-3020-4cb9-92c3-f7a5fa7998ff) em que o primeiro elemento é um iterador para o início e o segundo elemento é um iterador até o final do intervalo.  
  
### <a name="remarks"></a>Comentários  
 É possível para inserções simultâneas fazer com que outras chaves a ser inserido após o iterador de begin e antes do iterador de término.  
  
##  <a name="find"></a>localizar 

 Localiza um elemento que corresponde a uma chave especificada. Essa função é seguro de simultaneidade.  
  
```
iterator find(const key_type& KVal);

const_iterator find(const key_type& KVal) const;
```  
  
### <a name="parameters"></a>Parâmetros  
 `KVal`  
 O valor da chave para pesquisar.  
  
### <a name="return-value"></a>Valor de retorno  
 Um iterador que aponta para o local do primeiro elemento que corresponde a chave fornecida ou o iterador `end()` se esse elemento não existe.  
  
##  <a name="get_allocator"></a>get_allocator 

 Retorna o objeto de alocador armazenados para este contêiner simultânea. Esse método é seguro de simultaneidade.  
  
```
allocator_type get_allocator() const;
```  
  
### <a name="return-value"></a>Valor de retorno  
 O objeto de alocador armazenados para este contêiner simultânea.  
  
##  <a name="hash_function"></a>hash_function 

 Retorna o objeto de função de hash armazenado.  
  
```
hasher hash_function() const;
```  
  
### <a name="return-value"></a>Valor de retorno  
 O objeto de função de hash armazenado.  
  
##  <a name="insert"></a>Inserir 

 Adiciona os elementos para o `concurrent_unordered_set` objeto.  
  
```
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
 `_Iterator`  
 O tipo de iterador usado para inserção.  
  
 `V`  
 O tipo do valor inserido no conjunto.  
  
 `value`  
 O valor a ser inserido.  
  
 `_Where`  
 O local inicial de pesquisa para um ponto de inserção.  
  
 `first`  
 O início do intervalo a ser inserido.  
  
 `last`  
 O fim do intervalo a ser inserido.  
  
### <a name="return-value"></a>Valor de retorno  
 Um par que contém um iterador e um valor booleano. Consulte a seção de comentários para obter mais detalhes.  
  
### <a name="remarks"></a>Comentários  
 A primeira função de membro determina se um elemento X existe na sequência cuja chave tem ordenação equivalente do `value`. Se não, ele cria esse elemento X e a inicializa com `value`. A função, em seguida, determina o iterador `where` que designa X. Se ocorreu uma inserção, a função retornará `std::pair(where, true)`. Caso contrário, retornará `std::pair(where, false)`.  
  
 A segunda função de membro retorna insert ( `value`) usando `_Where` como ponto de partida na sequência controlada para procurar o ponto de inserção.  
  
 A terceira função do membro insere a sequência de valores de elemento do intervalo [ `first`, `last`).  
  
 As funções de membro de dois últimos se comportam da mesma, como os dois primeiros, exceto que `value` é usado para construir o valor inserido.  
  
##  <a name="key_eq"></a>key_eq 

 Retorna o objeto de função de comparação de igualdade armazenado.  
  
```
key_equal key_eq() const;
```  
  
### <a name="return-value"></a>Valor de retorno  
 O objeto de função de comparação de igualdade armazenado.  
  
##  <a name="load_factor"></a>load_factor 

 Calcula e retorna o fator de carga atual do contêiner. O fator de carga é o número de elementos no contêiner dividido pelo número de buckets.  
  
```
float load_factor() const;
```  
  
### <a name="return-value"></a>Valor de retorno  
 O fator de carga para o contêiner.  
  
##  <a name="max_load_factor"></a>max_load_factor 

 Obtém ou define o fator de carga máxima do contêiner. O fator de carga máxima é o maior número de elementos que podem estar em qualquer bucket antes do contêiner aumenta sua tabela interna.  
  
```
float max_load_factor() const;

void max_load_factor(float _Newmax);
```  
  
### <a name="parameters"></a>Parâmetros  
 `_Newmax`  
  
### <a name="return-value"></a>Valor de retorno  
 A primeira função membro retorna o fator de carga máxima armazenado. A segunda função de membro não retorna um valor, mas gera um [out_of_range](../../../standard-library/out-of-range-class.md) exceção se o fator de carga fornecido é inválido.  
  
##  <a name="max_size"></a>max_size 

 Retorna o tamanho máximo do contêiner simultâneo, determinado pelo alocador de. Esse método é seguro de simultaneidade.  
  
```
size_type max_size() const;
```  
  
### <a name="return-value"></a>Valor de retorno  
 O número máximo de elementos que podem ser inseridas neste contêiner simultâneo.  
  
### <a name="remarks"></a>Comentários  
 Esse valor de limite superior, na verdade, deve ser maior que o contêiner, na verdade, pode manter.  
  
##  <a name="operator_eq"></a>operador = 

 Atribui o conteúdo de outro `concurrent_unordered_set` deste objeto. Este método não é seguro de simultaneidade.  
  
```
concurrent_unordered_set& operator= (const concurrent_unordered_set& _Uset);

concurrent_unordered_set& operator= (concurrent_unordered_set&& _Uset);
```  
  
### <a name="parameters"></a>Parâmetros  
 `_Uset`  
 A fonte `concurrent_unordered_set` objeto.  
  
### <a name="return-value"></a>Valor de retorno  
 Uma referência a este `concurrent_unordered_set` objeto.  
  
### <a name="remarks"></a>Comentários  
 Depois de apagar os elementos existentes em um conjunto não ordenado simultâneo, `operator=` copia ou move o conteúdo da `_Uset` na simultâneas não ordenados conjunto.  
  
##  <a name="rehash"></a>rehash 

 Recria a tabela de hash.  
  
```
void rehash(size_type _Buckets);
```  
  
### <a name="parameters"></a>Parâmetros  
 `_Buckets`  
 O número de buckets desejado.  
  
### <a name="remarks"></a>Comentários  
 A função membro altera o número de buckets para que seja pelo menos `_Buckets` e recria a tabela de hash, conforme necessário. O número de buckets deve ser uma potência de 2. Se não é uma potência de 2, ele será arredondado para a próxima maior potência de 2.  
  
 Ele gera um [out_of_range](../../../standard-library/out-of-range-class.md) exceção se o número de buckets é inválido (0 ou maior que o número máximo de buckets).  
  
##  <a name="size"></a>tamanho 

 Retorna o número de elementos neste contêiner simultâneas. Esse método é seguro de simultaneidade.  
  
```
size_type size() const;
```  
  
### <a name="return-value"></a>Valor de retorno  
 O número de itens no contêiner.  
  
### <a name="remarks"></a>Comentários  
 Na presença de inserções simultâneas, o número de elementos no contêiner simultâneo pode alterar imediatamente após chamar essa função, antes do valor de retorno é ler.  
  
##  <a name="swap"></a>swap 

 Alterna o conteúdo de dois `concurrent_unordered_set` objetos. Este método não é seguro de simultaneidade.  
  
```
void swap(concurrent_unordered_set& _Uset);
```  
  
### <a name="parameters"></a>Parâmetros  
 `_Uset`  
 O `concurrent_unordered_set` objeto para troca.  
  
##  <a name="unsafe_begin"></a>unsafe_begin 

 Retorna um iterador para o primeiro elemento neste contêiner para um bucket específico.  
  
```
local_iterator unsafe_begin(size_type _Bucket);

const_local_iterator unsafe_begin(size_type _Bucket) const;
```  
  
### <a name="parameters"></a>Parâmetros  
 `_Bucket`  
 O índice de bucket.  
  
### <a name="return-value"></a>Valor de retorno  
 Um iterador que aponta para o início da partição.  
  
##  <a name="unsafe_bucket"></a>unsafe_bucket 

 Retorna o índice de partição que mapeia uma chave específica neste contêiner.  
  
```
size_type unsafe_bucket(const key_type& KVal) const;
```  
  
### <a name="parameters"></a>Parâmetros  
 `KVal`  
 A chave de elemento que está sendo pesquisada.  
  
### <a name="return-value"></a>Valor de retorno  
 O índice de classificação para a chave neste contêiner.  
  
##  <a name="unsafe_bucket_count"></a>unsafe_bucket_count 

 Retorna o número atual de recipientes neste contêiner.  
  
```
size_type unsafe_bucket_count() const;
```  
  
### <a name="return-value"></a>Valor de retorno  
 O número atual de recipientes neste contêiner.  
  
##  <a name="unsafe_bucket_size"></a>unsafe_bucket_size 

 Retorna o número de itens em um bloco específico desse contêiner.  
  
```
size_type unsafe_bucket_size(size_type _Bucket);
```  
  
### <a name="parameters"></a>Parâmetros  
 `_Bucket`  
 O bucket para pesquisar.  
  
### <a name="return-value"></a>Valor de retorno  
 O número atual de recipientes neste contêiner.  
  
##  <a name="unsafe_cbegin"></a>unsafe_cbegin 

 Retorna um iterador para o primeiro elemento neste contêiner para um bucket específico.  
  
```
const_local_iterator unsafe_cbegin(size_type _Bucket) const;
```  
  
### <a name="parameters"></a>Parâmetros  
 `_Bucket`  
 O índice de bucket.  
  
### <a name="return-value"></a>Valor de retorno  
 Um iterador que aponta para o início da partição.  
  
##  <a name="unsafe_cend"></a>unsafe_cend 

 Retorna um iterador para o local de êxito do último elemento em um bloco específico.  
  
```
const_local_iterator unsafe_cend(size_type _Bucket) const;
```  
  
### <a name="parameters"></a>Parâmetros  
 `_Bucket`  
 O índice de bucket.  
  
### <a name="return-value"></a>Valor de retorno  
 Um iterador que aponta para o início da partição.  
  
##  <a name="unsafe_end"></a>unsafe_end 

 Retorna um iterador para o último elemento neste contêiner para um bucket específico.  
  
```
local_iterator unsafe_end(size_type _Bucket);

const_local_iterator unsafe_end(size_type _Bucket) const;
```  
  
### <a name="parameters"></a>Parâmetros  
 `_Bucket`  
 O índice de bucket.  
  
### <a name="return-value"></a>Valor de retorno  
 Um iterador que aponta para o final da partição.  
  
##  <a name="unsafe_erase"></a>unsafe_erase 

 Remove os elementos do `concurrent_unordered_set` em posições especificadas. Este método não é seguro de simultaneidade.  
  
```
iterator unsafe_erase(
    const_iterator _Where);

size_type unsafe_erase(
    const key_type& KVal);

iterator unsafe_erase(
    const_iterator first,
    const_iterator last);
```  
  
### <a name="parameters"></a>Parâmetros  
 `_Where`  
 A posição do iterador para apagar do.  
  
 `KVal`  
 O valor da chave para apagar.  
  
 `first`  
 `last`  
  
### <a name="return-value"></a>Valor de retorno  
 As funções de membro de dois primeiro retornam um iterador que designa o primeiro elemento restantes além de quaisquer elementos removidos, ou [final](#end)() se esse elemento não existe. A terceira função do membro retorna o número de elementos remove.  
  
### <a name="remarks"></a>Comentários  
 A primeira função de membro remove o elemento apontado pelo `_Where`. A segunda função de membro remove os elementos no intervalo [ `_Begin`, `_End`).  
  
 A terceira função do membro remove os elementos no intervalo delimitado por [equal_range](#equal_range)(KVal).  
  
##  <a name="unsafe_max_bucket_count"></a>unsafe_max_bucket_count 

 Retorna o número máximo de buckets neste contêiner.  
  
```
size_type unsafe_max_bucket_count() const;
```  
  
### <a name="return-value"></a>Valor de retorno  
 O número máximo de buckets neste contêiner.  
  
## <a name="see-also"></a>Consulte também  
 [Namespace de simultaneidade](concurrency-namespace.md)   
 [Contêineres e objetos em paralelo](../../../parallel/concrt/parallel-containers-and-objects.md)



