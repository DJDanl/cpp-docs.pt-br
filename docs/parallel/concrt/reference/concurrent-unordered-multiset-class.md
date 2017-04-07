---
title: Classe concurrent_unordered_multiset | Documentos do Microsoft
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- devlang-cpp
ms.tgt_pltfrm: 
ms.topic: article
f1_keywords:
- concurrent_unordered_multiset
- CONCURRENT_UNORDERED_SET/concurrency::concurrent_unordered_multiset
- CONCURRENT_UNORDERED_SET/concurrency::concurrent_unordered_multiset::concurrent_unordered_multiset
- CONCURRENT_UNORDERED_SET/concurrency::concurrent_unordered_multiset::hash_function
- CONCURRENT_UNORDERED_SET/concurrency::concurrent_unordered_multiset::insert
- CONCURRENT_UNORDERED_SET/concurrency::concurrent_unordered_multiset::key_eq
- CONCURRENT_UNORDERED_SET/concurrency::concurrent_unordered_multiset::swap
- CONCURRENT_UNORDERED_SET/concurrency::concurrent_unordered_multiset::unsafe_erase
dev_langs:
- C++
helpviewer_keywords:
- concurrent_unordered_multiset class
ms.assetid: 219d7d67-1ff0-45f4-9400-e9cc272991a4
caps.latest.revision: 12
author: mikeblome
ms.author: mblome
manager: ghogen
translation.priority.ht:
- cs-cz
- de-de
- es-es
- fr-fr
- it-it
- ja-jp
- ko-kr
- pl-pl
- pt-br
- ru-ru
- tr-tr
- zh-cn
- zh-tw
translationtype: Machine Translation
ms.sourcegitcommit: 5faef5bd1be6cc02d6614a6f6193c74167a8ff23
ms.openlocfilehash: 06c098d2ad38fbf4a7664f9046ac4f1e12b1044d
ms.lasthandoff: 03/17/2017

---
# <a name="concurrentunorderedmultiset-class"></a>Classe concurrent_unordered_multiset
O `concurrent_unordered_multiset` classe é um contêiner de prova de simultaneidade que controla uma sequência de comprimento variado de elementos do tipo K. A sequência é representada de forma que permite a prova de simultaneidade acrescentar, acesso de elemento, acesso de iterador e operações de passagem do iterador.  
  
## <a name="syntax"></a>Sintaxe  
  
```
template <typename K,
    typename _Hasher = std::hash<K>,
    typename key_equality = std::equal_to<K>,
    typename _Allocator_type = std::allocator<K>
>,
    typename key_equality = std::equal_to<K>,
    typename _Allocator_type = std::allocator<K>> class concurrent_unordered_multiset : public details::_Concurrent_hash<details::_Concurrent_unordered_set_traits<K,
    details::_Hash_compare<K,
 _Hasher,
    key_equality>,
 _Allocator_type,
    true>>;
```   
  
#### <a name="parameters"></a>Parâmetros  
 `K`  
 O tipo principal.  
  
 `_Hasher`  
 O tipo de objeto da função de hash. Esse argumento é opcional e o valor padrão é `std::hash<``K``>`.  
  
 `key_equality`  
 O tipo de objeto da função de comparação de igualdade. Esse argumento é opcional e o valor padrão é `std::equal_to<``K``>`.  
  
 `_Allocator_type`  
 O tipo que representa o objeto de alocador armazenado que encapsula detalhes sobre a alocação e desalocação de memória para o vetor simultânea. Esse argumento é opcional e o valor padrão é `std::allocator<``K``>`.  
  
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
|[concurrent_unordered_multiset](#ctor)|Sobrecarregado. Constrói um multiset não ordenado simultâneo.|  
  
### <a name="public-methods"></a>Métodos públicos  
  
|Nome|Descrição|  
|----------|-----------------|  
|[hash_function](#hash_function)|Retorna o objeto de função de hash armazenado.|  
|[insert](#insert)|Sobrecarregado. Adiciona elementos para o `concurrent_unordered_multiset` objeto.|  
|[key_eq](#key_eq)|O objeto de função de comparação de igualdade armazenado.|  
|[swap](#swap)|Troca o conteúdo dos dois `concurrent_unordered_multiset` objetos. Esse método não é uma prova de simultaneidade.|  
|[unsafe_erase](#unsafe_erase)|Sobrecarregado. Remove elementos do `concurrent_unordered_multiset` em posições especificadas. Esse método não é uma prova de simultaneidade.|  
  
### <a name="public-operators"></a>Operadores públicos  
  
|Nome|Descrição|  
|----------|-----------------|  
|[operator=](#operator_eq)|Sobrecarregado. Atribui o conteúdo de outro `concurrent_unordered_multiset` objeto a este. Esse método não é uma prova de simultaneidade.|  
  
## <a name="remarks"></a>Comentários  
 Para obter informações detalhadas sobre o `concurrent_unordered_multiset` classe, consulte [paralela contêineres e objetos](../../../parallel/concrt/parallel-containers-and-objects.md).  
  
## <a name="inheritance-hierarchy"></a>Hierarquia de herança  
 `_Traits`  
  
 `_Concurrent_hash`  
  
 `concurrent_unordered_multiset`  
  
## <a name="requirements"></a>Requisitos  
 **Cabeçalho:** concurrent_unordered_set.h  
  
 **Namespace:** simultaneidade  
  
##  <a name="begin"></a>começar 

 Retorna um iterador apontando para o primeiro elemento no contêiner simultâneo. Esse método é seguro de simultaneidade.  
  
```
iterator begin();

const_iterator begin() const;
```  
  
### <a name="return-value"></a>Valor de retorno  
 Um iterador para o primeiro elemento no contêiner simultâneo.  
  
##  <a name="cbegin"></a>cbegin 

 Retorna um iterador const que aponta para o primeiro elemento no contêiner simultâneo. Esse método é seguro de simultaneidade.  
  
```
const_iterator cbegin() const;
```  
  
### <a name="return-value"></a>Valor de retorno  
 Um iterador const para o primeiro elemento no contêiner simultâneo.  
  
##  <a name="cend"></a>cend 

 Retorna um iterador const apontando para o local após o último elemento no contêiner simultâneo. Esse método é seguro de simultaneidade.  
  
```
const_iterator cend() const;
```  
  
### <a name="return-value"></a>Valor de retorno  
 Um iterador const para o local após o último elemento no contêiner simultâneo.  
  
##  <a name="clear"></a>Limpar 

 Apaga todos os elementos no contêiner simultâneo. Essa função não é seguro de simultaneidade.  
  
```
void clear();
```  
  
##  <a name="ctor"></a>concurrent_unordered_multiset 

 Constrói um multiset não ordenado simultâneo.  
  
```
explicit concurrent_unordered_multiset(
    size_type _Number_of_buckets = 8,
    const hasher& _Hasher = hasher(),
    const key_equal& key_equality = key_equal(),
    const allocator_type& _Allocator = allocator_type());

concurrent_unordered_multiset(
    const allocator_type& _Allocator);

template <typename _Iterator>
concurrent_unordered_multiset(_Iterator first,
    _Iterator last,
    size_type _Number_of_buckets = 8,
    const hasher& _Hasher = hasher(),
    const key_equal& key_equality = key_equal(),
    const allocator_type& _Allocator = allocator_type());

concurrent_unordered_multiset(
    const concurrent_unordered_multiset& _Uset);

concurrent_unordered_multiset(
    const concurrent_unordered_multiset& _Uset,
    const allocator_type& _Allocator);

concurrent_unordered_multiset(
    concurrent_unordered_multiset&& _Uset);
```  
  
### <a name="parameters"></a>Parâmetros  
 `_Iterator`  
 O tipo do iterador de entrada.  
  
 `_Number_of_buckets`  
 O número inicial de buckets para esse multiset fora de ordem.  
  
 `_Hasher`  
 A função de hash para este multiset fora de ordem.  
  
 `key_equality`  
 A função de comparação de igualdade para este multiset fora de ordem.  
  
 `_Allocator`  
 O alocador para este multiset fora de ordem.  
  
 `first`  
 `last`  
 `_Uset`  
 A fonte `concurrent_unordered_multiset` objeto para mover elementos do.  
  
### <a name="remarks"></a>Comentários  
 Todos os construtores armazenam um objeto alocador `_Allocator` e inicializar o multiset fora de ordem.  
  
 O primeiro construtor Especifica um multiconjunto inicial vazio e explicitamente Especifica o número de buckets, tipo de função de hash, função de igualdade e alocador a ser usado.  
  
 O segundo construtor Especifica um alocador de multiset fora de ordem.  
  
 O terceiro construtor especifica valores fornecidos pelo intervalo iterador [ `_Begin`, `_End`).  
  
 Os construtores quarto e quinto especificam uma cópia simultânea multiset não ordenada `_Uset`.  
  
 O último construtor Especifica uma movimentação de multiset simultânea não ordenada `_Uset`.  
  
##  <a name="count"></a>Contagem 

 Conta o número de elementos que correspondem a uma chave especificada. Essa função é seguro de simultaneidade.  
  
```
size_type count(const key_type& KVal) const;
```  
  
### <a name="parameters"></a>Parâmetros  
 `KVal`  
 A chave para pesquisar.  
  
### <a name="return-value"></a>Valor de retorno  
 O número de vezes o número de vezes que a chave é exibida no contêiner.  
  
##  <a name="empty"></a>vazio 

 Testa se nenhum elemento está presente. Esse método é seguro de simultaneidade.  
  
```
bool empty() const;
```  
  
### <a name="return-value"></a>Valor de retorno  
 `true`Se o contêiner simultâneo estiver vazio, `false` caso contrário.  
  
### <a name="remarks"></a>Comentários  
 Na presença de inserções simultâneas, ou não o contêiner simultâneo está vazio pode alterar imediatamente depois de chamar essa função, antes que o valor de retorno é ler.  
  
##  <a name="end"></a>final 

 Retorna um iterador apontando para o local após o último elemento no contêiner simultâneo. Esse método é seguro de simultaneidade.  
  
```
iterator end();

const_iterator end() const;
```  
  
### <a name="return-value"></a>Valor de retorno  
 Um iterador para o local após o último elemento no contêiner simultâneo.  
  
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
 A [par](http://msdn.microsoft.com/en-us/32e72d66-3020-4cb9-92c3-f7a5fa7998ff) onde o primeiro elemento é um iterador para o início e o segundo elemento é um iterador para o final do intervalo.  
  
### <a name="remarks"></a>Comentários  
 É possível para inserções simultâneas fazer com que as chaves adicionais a serem inseridos após o iterador inicial e antes do iterador de fim.  
  
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
 Um iterador apontando para o local do primeiro elemento que corresponde à chave fornecida ou o iterador `end()` se esse elemento não existir.  
  
##  <a name="get_allocator"></a>get_allocator 

 Retorna o objeto de alocador armazenado para esse contêiner simultânea. Esse método é seguro de simultaneidade.  
  
```
allocator_type get_allocator() const;
```  
  
### <a name="return-value"></a>Valor de retorno  
 O objeto de alocador armazenado para esse contêiner simultânea.  
  
##  <a name="hash_function"></a>hash_function 

 Retorna o objeto de função de hash armazenado.  
  
```
hasher hash_function() const;
```  
  
### <a name="return-value"></a>Valor de retorno  
 O objeto de função de hash armazenado.  
  
##  <a name="insert"></a>Inserir 

 Adiciona elementos para o `concurrent_unordered_multiset` objeto.  
  
```
iterator insert(
    const value_type& value);

iterator insert(
    const_iterator _Where,
    const value_type& value);

template<class _Iterator>
void insert(_Iterator first,
    _Iterator last);

template<class V>
iterator insert(
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
 O tipo do valor inserido.  
  
 `value`  
 O valor a ser inserido.  
  
 `_Where`  
 O local inicial para procurar por um ponto de inserção.  
  
 `first`  
 O início do intervalo para inserir.  
  
 `last`  
 O final do intervalo para inserir.  
  
### <a name="return-value"></a>Valor de retorno  
 Um iterador apontando para o local de inserção.  
  
### <a name="remarks"></a>Comentários  
 A primeira função de membro insere o elemento `value` na sequência controlada, em seguida, retorna o iterador que designa o elemento inserido.  
  
 A segunda função de membro retorna insert ( `value`), usando `_Where` como um ponto de partida na sequência controlada para procurar o ponto de inserção.  
  
 A terceira função de membro insere a sequência de valores de elemento do intervalo [ `first`, `last`).  
  
 As funções de membro de dois últimos se comportam da mesma maneira como os dois primeiros, exceto que `value` é usado para construir o valor inserido.  
  
##  <a name="key_eq"></a>key_eq 

 O objeto de função de comparação de igualdade armazenado.  
  
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
 A primeira função membro retorna o fator de carga máxima armazenado. A segunda função de membro não retorna um valor, mas lança um [out_of_range](../../../standard-library/out-of-range-class.md) exceção se o fator de carga fornecido é inválido.  
  
##  <a name="max_size"></a>max_size 

 Retorna o tamanho máximo do contêiner simultâneo, determinado pelo alocador. Esse método é seguro de simultaneidade.  
  
```
size_type max_size() const;
```  
  
### <a name="return-value"></a>Valor de retorno  
 O número máximo de elementos que podem ser inseridas neste contêiner simultâneo.  
  
### <a name="remarks"></a>Comentários  
 Esse valor de limite superior, na verdade, pode ser maior que o contêiner pode realmente manter.  
  
##  <a name="operator_eq"></a>operador = 

 Atribui o conteúdo de outro `concurrent_unordered_multiset` objeto a este. Esse método não é uma prova de simultaneidade.  
  
```
concurrent_unordered_multiset& operator= (const concurrent_unordered_multiset& _Uset);

concurrent_unordered_multiset& operator= (concurrent_unordered_multiset&& _Uset);
```  
  
### <a name="parameters"></a>Parâmetros  
 `_Uset`  
 A fonte `concurrent_unordered_multiset` objeto.  
  
### <a name="return-value"></a>Valor de retorno  
 Uma referência a esta `concurrent_unordered_multiset` objeto.  
  
### <a name="remarks"></a>Comentários  
 Depois de apagar os elementos existentes em um multiconjunto simultâneo não ordenado, `operator=` copia ou move o conteúdo de `_Uset` para a simultâneas não ordenados multiset.  
  
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
  
 Ele gera um [out_of_range](../../../standard-library/out-of-range-class.md) exceção se o número de buckets é inválido (0 ou maior que o número máximo de segmentos).  
  
##  <a name="size"></a>tamanho 

 Retorna o número de elementos neste contêiner simultâneas. Esse método é seguro de simultaneidade.  
  
```
size_type size() const;
```  
  
### <a name="return-value"></a>Valor de retorno  
 O número de itens no contêiner.  
  
### <a name="remarks"></a>Comentários  
 Na presença de inserções simultâneas, o número de elementos no contêiner simultâneo pode alterar imediatamente depois de chamar essa função, antes que o valor de retorno é ler.  
  
##  <a name="swap"></a>troca 

 Troca o conteúdo dos dois `concurrent_unordered_multiset` objetos. Esse método não é uma prova de simultaneidade.  
  
```
void swap(concurrent_unordered_multiset& _Uset);
```  
  
### <a name="parameters"></a>Parâmetros  
 `_Uset`  
 O `concurrent_unordered_multiset` objeto para troca.  
  
##  <a name="unsafe_begin"></a>unsafe_begin 

 Retorna um iterador para o primeiro elemento neste contêiner para um bloco específico.  
  
```
local_iterator unsafe_begin(size_type _Bucket);

const_local_iterator unsafe_begin(size_type _Bucket) const;
```  
  
### <a name="parameters"></a>Parâmetros  
 `_Bucket`  
 O índice de bucket.  
  
### <a name="return-value"></a>Valor de retorno  
 Um iterador apontando para o início da partição.  
  
##  <a name="unsafe_bucket"></a>unsafe_bucket 

 Retorna o índice de bucket que mapeia uma chave específica neste contêiner.  
  
```
size_type unsafe_bucket(const key_type& KVal) const;
```  
  
### <a name="parameters"></a>Parâmetros  
 `KVal`  
 A chave do elemento que está sendo pesquisada.  
  
### <a name="return-value"></a>Valor de retorno  
 O índice de bucket para a chave neste contêiner.  
  
##  <a name="unsafe_bucket_count"></a>unsafe_bucket_count 

 Retorna o número atual de buckets neste contêiner.  
  
```
size_type unsafe_bucket_count() const;
```  
  
### <a name="return-value"></a>Valor de retorno  
 O número atual de buckets neste contêiner.  
  
##  <a name="unsafe_bucket_size"></a>unsafe_bucket_size 

 Retorna o número de itens em um bloco específico desse contêiner.  
  
```
size_type unsafe_bucket_size(size_type _Bucket);
```  
  
### <a name="parameters"></a>Parâmetros  
 `_Bucket`  
 O bucket para pesquisar.  
  
### <a name="return-value"></a>Valor de retorno  
 O número atual de buckets neste contêiner.  
  
##  <a name="unsafe_cbegin"></a>unsafe_cbegin 

 Retorna um iterador para o primeiro elemento neste contêiner para um bloco específico.  
  
```
const_local_iterator unsafe_cbegin(size_type _Bucket) const;
```  
  
### <a name="parameters"></a>Parâmetros  
 `_Bucket`  
 O índice de bucket.  
  
### <a name="return-value"></a>Valor de retorno  
 Um iterador apontando para o início da partição.  
  
##  <a name="unsafe_cend"></a>unsafe_cend 

 Retorna um iterador para o local após o último elemento em um bloco específico.  
  
```
const_local_iterator unsafe_cend(size_type _Bucket) const;
```  
  
### <a name="parameters"></a>Parâmetros  
 `_Bucket`  
 O índice de bucket.  
  
### <a name="return-value"></a>Valor de retorno  
 Um iterador apontando para o início da partição.  
  
##  <a name="unsafe_end"></a>unsafe_end 

 Retorna um iterador para o último elemento neste contêiner para um bloco específico.  
  
```
local_iterator unsafe_end(size_type _Bucket);

const_local_iterator unsafe_end(size_type _Bucket) const;
```  
  
### <a name="parameters"></a>Parâmetros  
 `_Bucket`  
 O índice de bucket.  
  
### <a name="return-value"></a>Valor de retorno  
 Um iterador apontando para o final da partição.  
  
##  <a name="unsafe_erase"></a>unsafe_erase 

 Remove elementos do `concurrent_unordered_multiset` em posições especificadas. Esse método não é uma prova de simultaneidade.  
  
```
iterator unsafe_erase(
    const_iterator _Where);

iterator unsafe_erase(
    const_iterator first,
    const_iterator last);

size_type unsafe_erase(
    const key_type& KVal);
```  
  
### <a name="parameters"></a>Parâmetros  
 `_Where`  
 A posição do iterador para apagar da.  
  
 `first`  
 `last`  
 `KVal`  
 O valor da chave para apagar.  
  
### <a name="return-value"></a>Valor de retorno  
 As funções de membro de dois primeiro retornam um iterador que designa o primeiro elemento restante além de quaisquer elementos removidos, ou [final](#end)() se esse elemento não existir. A terceira função de membro retorna o número de elementos remove.  
  
### <a name="remarks"></a>Comentários  
 A primeira função de membro remove o elemento apontado por `_Where`. A segunda função de membro remove os elementos no intervalo [ `_Begin`, `_End`).  
  
 A terceira função de membro remove os elementos no intervalo delimitado por [equal_range](#equal_range)(KVal).  
  
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




