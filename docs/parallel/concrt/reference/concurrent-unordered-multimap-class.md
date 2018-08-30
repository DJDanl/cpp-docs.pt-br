---
title: Classe concurrent_unordered_multimap | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-concrt
ms.topic: reference
f1_keywords:
- concurrent_unordered_multimap
- CONCURRENT_UNORDERED_MAP/concurrency::concurrent_unordered_multimap
- CONCURRENT_UNORDERED_MAP/concurrency::concurrent_unordered_multimap::concurrent_unordered_multimap
- CONCURRENT_UNORDERED_MAP/concurrency::concurrent_unordered_multimap::hash_function
- CONCURRENT_UNORDERED_MAP/concurrency::concurrent_unordered_multimap::insert
- CONCURRENT_UNORDERED_MAP/concurrency::concurrent_unordered_multimap::key_eq
- CONCURRENT_UNORDERED_MAP/concurrency::concurrent_unordered_multimap::swap
- CONCURRENT_UNORDERED_MAP/concurrency::concurrent_unordered_multimap::unsafe_erase
dev_langs:
- C++
helpviewer_keywords:
- concurrent_unordered_multimap class
ms.assetid: 4dada5d7-15df-4382-b9c9-348e75b2f3c1
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
ms.openlocfilehash: b9fe1bcce5290d7e977dc423f146bb3a5b66d484
ms.sourcegitcommit: 9a0905c03a73c904014ec9fd3d6e59e4fa7813cd
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 08/29/2018
ms.locfileid: "43216078"
---
# <a name="concurrentunorderedmultimap-class"></a>Classe concurrent_unordered_multimap
O `concurrent_unordered_multimap` classe é um contêiner protegido contra simultaneidade que controla uma sequência de comprimento variado de elementos do tipo `std::pair<const K, _Element_type>`. A sequência é representada de maneira que permite a prova de simultaneidade de acréscimo, acesso de elemento de iterador e operações de passagem de iterador.  
  
## <a name="syntax"></a>Sintaxe  
  
```
template <typename K,
    typename _Element_type,
    typename _Hasher = std::hash<K>,
    typename key_equality = std::equal_to<K>,
    typename _Allocator_type = std::allocator<std::pair<const K,
    _Element_type>>
>,
 typename key_equality = std::equal_to<K>,
    typename _Allocator_type = std::allocator<std::pair<const K,
    _Element_type>>> class concurrent_unordered_multimap : public details::_Concurrent_hash<details::_Concurrent_unordered_map_traits<K,
    _Element_type,
 details::_Hash_compare<K,
    _Hasher,
 key_equality>,
    _Allocator_type,
 true>>;
```  
  
#### <a name="parameters"></a>Parâmetros  
 `K`  
 O tipo principal.  
  
 `_Element_type`  
 O tipo mapeado.  
  
 `_Hasher`  
 O tipo de objeto da função de hash. Esse argumento é opcional e o valor padrão é `std::hash<K>`.  
  
 `key_equality`  
 O tipo de objeto da função de comparação de igualdade. Esse argumento é opcional e o valor padrão é `std::equal_to<K>`.  
  
 `_Allocator_type`  
 O tipo que representa o objeto de alocador armazenado que encapsula detalhes sobre a alocação e desalocação de memória para o vetor simultâneo. Esse argumento é opcional e o valor padrão é `std::allocator<std::pair<K`, `_Element_type>>`.  
  
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
|`mapped_type`|O tipo de um valor mapeado associado a cada chave.|  
|`pointer`|O tipo de um ponteiro para um elemento.|  
|`reference`|O tipo de uma referência para um elemento.|  
|`size_type`|O tipo de uma distância sem sinal entre dois elementos.|  
|`value_type`|O tipo de um elemento.|  
  
### <a name="public-constructors"></a>Construtores públicos  
  
|Nome|Descrição|  
|----------|-----------------|  
|[concurrent_unordered_multimap](#ctor)|Sobrecarregado. Constrói um multimapa simultâneo não ordenado.|  
  
### <a name="public-methods"></a>Métodos públicos  
  
|Nome|Descrição|  
|----------|-----------------|  
|[hash_function](#hash_function)|Retorna o objeto de função de hash armazenado.|  
|[insert](#insert)|Sobrecarregado. Adiciona elementos ao `concurrent_unordered_multimap` objeto.|  
|[key_eq](#key_eq)|Retorna o objeto de função de comparação de igualdade armazenado.|  
|[swap](#swap)|Troca o conteúdo de dois `concurrent_unordered_multimap` objetos. Esse método não é seguro em simultaneidade.|  
|[unsafe_erase](#unsafe_erase)|Sobrecarregado. Remove elementos do `concurrent_unordered_multimap` em posições especificadas. Esse método não é seguro em simultaneidade.|  
  
### <a name="public-operators"></a>Operadores públicos  
  
|Nome|Descrição|  
|----------|-----------------|  
|[operator=](#operator_eq)|Sobrecarregado. Atribui o conteúdo de outro `concurrent_unordered_multimap` objeto para esse outro. Esse método não é seguro em simultaneidade.|  
  
## <a name="remarks"></a>Comentários  
 Para obter informações detalhadas sobre o `concurrent_unordered_multimap` classe, consulte [paralela contêineres e objetos](../../../parallel/concrt/parallel-containers-and-objects.md).  
  
## <a name="inheritance-hierarchy"></a>Hierarquia de herança  
 `_Traits`  
  
 `_Concurrent_hash`  
  
 `concurrent_unordered_multimap`  
  
## <a name="requirements"></a>Requisitos  
 **Cabeçalho:** concurrent_unordered_map. h  
  
 **Namespace:** simultaneidade  
  
##  <a name="begin"></a> começar 

 Retorna um iterador que aponta para o primeiro elemento no contêiner simultâneo. Esse método é seguro de simultaneidade.  
  
```
iterator begin();

const_iterator begin() const;
```  
  
### <a name="return-value"></a>Valor de retorno  
 Um iterador para o primeiro elemento no contêiner simultâneo.  
  
##  <a name="cbegin"></a> cbegin 

 Retorna um iterador const que aponta para o primeiro elemento no contêiner simultâneo. Esse método é seguro de simultaneidade.  
  
```
const_iterator cbegin() const;
```  
  
### <a name="return-value"></a>Valor de retorno  
 Um iterador const para o primeiro elemento no contêiner simultâneo.  
  
##  <a name="cend"></a> cend 

 Retorna um iterador const que aponta para o local que sucede o último elemento no contêiner simultâneo. Esse método é seguro de simultaneidade.  
  
```
const_iterator cend() const;
```  
  
### <a name="return-value"></a>Valor de retorno  
 Um iterador const para o local que sucede o último elemento no contêiner simultâneo.  
  
##  <a name="clear"></a> Limpar 

 Apaga todos os elementos no contêiner simultâneo. Essa função não é seguro de simultaneidade.  
  
```
void clear();
```  
  
##  <a name="ctor"></a> concurrent_unordered_multimap 

 Constrói um multimapa simultâneo não ordenado.  
  
```
explicit concurrent_unordered_multimap(
    size_type _Number_of_buckets = 8,
    const hasher& _Hasher = hasher(),
    const key_equal& key_equality = key_equal(),
    const allocator_type& _Allocator = allocator_type());

concurrent_unordered_multimap(
    const allocator_type& _Allocator);

template <typename _Iterator>
concurrent_unordered_multimap(_Iterator _Begin,
    _Iterator _End,
    size_type _Number_of_buckets = 8,
    const hasher& _Hasher = hasher(),
    const key_equal& key_equality = key_equal(),
    const allocator_type& _Allocator = allocator_type());

concurrent_unordered_multimap(
    const concurrent_unordered_multimap& _Umap);

concurrent_unordered_multimap(
    const concurrent_unordered_multimap& _Umap,
    const allocator_type& _Allocator);

concurrent_unordered_multimap(
    concurrent_unordered_multimap&& _Umap);
```  
  
### <a name="parameters"></a>Parâmetros  
 `_Iterator`  
 O tipo do iterador de entrada.  
  
 `_Number_of_buckets`  
 O número inicial de buckets para esse multimap não ordenada.  
  
 `_Hasher`  
 A função de hash para este multimap não ordenada.  
  
 `key_equality`  
 A função de comparação de igualdade para este multimap não ordenada.  
  
 `_Allocator`  
 O alocador para este multimap não ordenada.  
  
 `_Begin`  
 A posição do primeiro elemento no intervalo de elementos a serem copiados.  
  
 `_End`  
 A posição do primeiro elemento além do intervalo de elementos a serem copiados.  
  
 `_Umap`  
 A fonte `concurrent_unordered_multimap` objeto do qual copiar elementos.  
  
### <a name="remarks"></a>Comentários  
 Todos os construtores armazenam um objeto alocador `_Allocator` e inicializar o multimap não ordenado.  
  
 O primeiro construtor Especifica um mapa inicial vazio e especifica explicitamente o número de buckets, tipo de alocador, a função de igualdade e a função de hash a ser usada.  
  
 O segundo construtor Especifica um alocador para o multimap não ordenado.  
  
 O terceiro construtor especifica valores fornecidos pelo intervalo do iterador [ `_Begin`, `_End`).  
  
 O quarto e quinto construtor Especifica uma cópia do multimapa simultâneo não ordenado `_Umap`.  
  
 O último construtor Especifica um movimento do multimapa simultâneo não ordenado `_Umap`.  
  
##  <a name="count"></a> Contagem 

 Conta o número de elementos que correspondem a uma chave especificada. Essa função é segura de simultaneidade.  
  
```
size_type count(const key_type& KVal) const;
```  
  
### <a name="parameters"></a>Parâmetros  
 `KVal`  
 A chave a ser pesquisada.  
  
### <a name="return-value"></a>Valor de retorno  
 O número de vezes o número de vezes que a chave é exibida no contêiner.  
  
##  <a name="empty"></a> vazio 

 Testa se nenhum elemento está presente. Esse método é seguro de simultaneidade.  
  
```
bool empty() const;
```  
  
### <a name="return-value"></a>Valor de retorno  
 `true` Se o contêiner simultâneo estiver vazio, `false` caso contrário.  
  
### <a name="remarks"></a>Comentários  
 Na presença de inserções simultâneas, ou o contêiner simultâneo não vazio pode mudar imediatamente após chamar essa função, antes que o valor retornado ainda seja lido.  
  
##  <a name="end"></a> final 

 Retorna um iterador que aponta para o local que sucede o último elemento no contêiner simultâneo. Esse método é seguro de simultaneidade.  
  
```
iterator end();

const_iterator end() const;
```  
  
### <a name="return-value"></a>Valor de retorno  
 Um iterador para o local que sucede o último elemento no contêiner simultâneo.  
  
##  <a name="equal_range"></a> equal_range 

 Localiza um intervalo que corresponde a uma chave especificada. Essa função é segura de simultaneidade.  
  
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
 O valor chave a ser pesquisado.  
  
### <a name="return-value"></a>Valor de retorno  
 Um [par](https://msdn.microsoft.com/32e72d66-3020-4cb9-92c3-f7a5fa7998ff) onde o primeiro elemento é um iterador para o início e o segundo elemento é um iterador para o fim do intervalo.  
  
### <a name="remarks"></a>Comentários  
 É possível para inserções simultâneas fazer com que as chaves adicionais a serem inseridos após o iterador de início e antes do iterador de fim.  
  
##  <a name="find"></a> localizar 

 Localiza um elemento que corresponde a uma chave especificada. Essa função é segura de simultaneidade.  
  
```
iterator find(const key_type& KVal);

const_iterator find(const key_type& KVal) const;
```  
  
### <a name="parameters"></a>Parâmetros  
 `KVal`  
 O valor chave a ser pesquisado.  
  
### <a name="return-value"></a>Valor de retorno  
 Um iterador que aponta para o local do primeiro elemento que corresponde à chave fornecida ou o iterador `end()` se não houver tal elemento.  
  
##  <a name="get_allocator"></a> get_allocator 

 Retorna o objeto de alocador armazenado para esse contêiner simultânea. Esse método é seguro de simultaneidade.  
  
```
allocator_type get_allocator() const;
```  
  
### <a name="return-value"></a>Valor de retorno  
 O objeto de alocador armazenado para esse contêiner simultânea.  
  
##  <a name="hash_function"></a> hash_function 

 Retorna o objeto de função de hash armazenado.  
  
```
hasher hash_function() const;
```  
  
### <a name="return-value"></a>Valor de retorno  
 O objeto de função de hash armazenado.  
  
##  <a name="insert"></a> Inserir 

 Adiciona elementos ao `concurrent_unordered_multimap` objeto.  
  
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
 O tipo do iterador usado para a inserção.  
  
 `V`  
 O tipo do valor inserido no mapa.  
  
 `value`  
 O valor a ser inserido.  
  
 `_Where`  
 O local inicial para procurar um ponto de inserção.  
  
 `first`  
 O início do intervalo a inserir.  
  
 `last`  
 O fim do intervalo a inserir.  
  
### <a name="return-value"></a>Valor de retorno  
 Um iterador que aponta para o local de inserção.  
  
### <a name="remarks"></a>Comentários  
 A primeira função membro insere o elemento `value` na sequência controlada, em seguida, retorna o iterador que designa o elemento inserido.  
  
 A segunda função membro retorna insert ( `value`), usando `_Where` como um ponto de partida dentro da sequência controlada para procurar o ponto de inserção.  
  
 A terceira função membro insere a sequência de valores de elemento do intervalo [ `first`, `last`).  
  
 As duas últimas funções membro se comportam da mesma forma as duas primeiras, exceto que `value` é usado para construir o valor inserido.  
  
##  <a name="key_eq"></a> key_eq 

 Retorna o objeto de função de comparação de igualdade armazenado.  
  
```
key_equal key_eq() const;
```  
  
### <a name="return-value"></a>Valor de retorno  
 O objeto de função de comparação de igualdade armazenado.  
  
##  <a name="load_factor"></a> load_factor 

 Calcula e retorna o fator de carga atual do contêiner. O fator de carga é o número de elementos no contêiner dividido pelo número de buckets.  
  
```
float load_factor() const;
```  
  
### <a name="return-value"></a>Valor de retorno  
 O fator de carga para o contêiner.  
  
##  <a name="max_load_factor"></a> max_load_factor 

 Obtém ou define o fator de carga máxima do contêiner. O fator de carga máxima é o maior número de elementos que podem estar em qualquer bucket antes que o contêiner aumenta sua tabela interna.  
  
```
float max_load_factor() const;

void max_load_factor(float _Newmax);
```  
  
### <a name="parameters"></a>Parâmetros  
 `_Newmax`  
  
### <a name="return-value"></a>Valor de retorno  
 A primeira função membro retorna o fator de carga máxima armazenado. A segunda função membro não retorna um valor, mas lança um [out_of_range](../../../standard-library/out-of-range-class.md) exceção se o fator de carga fornecido é inválido...  
  
##  <a name="max_size"></a> max_size 

 Retorna o tamanho máximo do contêiner simultâneo, determinado pelo alocador. Esse método é seguro de simultaneidade.  
  
```
size_type max_size() const;
```  
  
### <a name="return-value"></a>Valor de retorno  
 O número máximo de elementos que podem ser inseridas nesse contêiner simultâneo.  
  
### <a name="remarks"></a>Comentários  
 Esse valor de limite superior, na verdade, pode ser maior do que o que o contêiner, na verdade, pode conter.  
  
##  <a name="operator_eq"></a> operador = 

 Atribui o conteúdo de outro `concurrent_unordered_multimap` objeto para esse outro. Esse método não é seguro em simultaneidade.  
  
```
concurrent_unordered_multimap& operator= (const concurrent_unordered_multimap& _Umap);

concurrent_unordered_multimap& operator= (concurrent_unordered_multimap&& _Umap);
```  
  
### <a name="parameters"></a>Parâmetros  
 `_Umap`  
 A fonte `concurrent_unordered_multimap` objeto.  
  
### <a name="return-value"></a>Valor de retorno  
 Uma referência a este `concurrent_unordered_multimap` objeto.  
  
### <a name="remarks"></a>Comentários  
 Depois de apagar os elementos existentes em um multimapa simultâneo não ordenado `operator=` copiará ou moverá o conteúdo de `_Umap` no multimapa simultâneo não ordenado.  
  
##  <a name="rehash"></a> rehash 

 Recria a tabela de hash.  
  
```
void rehash(size_type _Buckets);
```  
  
### <a name="parameters"></a>Parâmetros  
 `_Buckets`  
 O número de buckets desejado.  
  
### <a name="remarks"></a>Comentários  
 A função membro altera o número de buckets para que seja pelo menos `_Buckets` e recria a tabela de hash, conforme necessário. O número de buckets deve ser uma potência de 2. Se não é uma potência de 2, ele será arredondado para a próxima maior potência de 2.  
  
 Ele gera uma [out_of_range](../../../standard-library/out-of-range-class.md) exceção se o número de buckets é inválido (0 ou maior que o número máximo de buckets).  
  
##  <a name="size"></a> Tamanho 

 Retorna o número de elementos neste contêiner simultâneas. Esse método é seguro de simultaneidade.  
  
```
size_type size() const;
```  
  
### <a name="return-value"></a>Valor de retorno  
 O número de itens no contêiner.  
  
### <a name="remarks"></a>Comentários  
 Na presença de inserções simultâneas, o número de elementos no contêiner simultâneo pode alterar imediatamente após chamar essa função, antes que o valor retornado ainda seja lido.  
  
##  <a name="swap"></a> troca 

 Troca o conteúdo de dois `concurrent_unordered_multimap` objetos. Esse método não é seguro em simultaneidade.  
  
```
void swap(concurrent_unordered_multimap& _Umap);
```  
  
### <a name="parameters"></a>Parâmetros  
 `_Umap`  
 O `concurrent_unordered_multimap` objeto com o qual trocar.  
  
##  <a name="unsafe_begin"></a> unsafe_begin 

 Retorna um iterador para o primeiro elemento nesse contêiner para um bloco específico.  
  
```
local_iterator unsafe_begin(size_type _Bucket);

const_local_iterator unsafe_begin(size_type _Bucket) const;
```  
  
### <a name="parameters"></a>Parâmetros  
 `_Bucket`  
 O índice de bucket.  
  
### <a name="return-value"></a>Valor de retorno  
 Um iterador que aponta para o início da partição.  
  
##  <a name="unsafe_bucket"></a> unsafe_bucket 

 Retorna o índice de compartimento de memória que uma chave específica é mapeado para neste contêiner.  
  
```
size_type unsafe_bucket(const key_type& KVal) const;
```  
  
### <a name="parameters"></a>Parâmetros  
 `KVal`  
 A chave do elemento que está sendo pesquisada.  
  
### <a name="return-value"></a>Valor de retorno  
 O índice de bucket para a chave neste contêiner.  
  
##  <a name="unsafe_bucket_count"></a> unsafe_bucket_count 

 Retorna o número atual de buckets neste contêiner.  
  
```
size_type unsafe_bucket_count() const;
```  
  
### <a name="return-value"></a>Valor de retorno  
 O número atual de buckets neste contêiner.  
  
##  <a name="unsafe_bucket_size"></a> unsafe_bucket_size 

 Retorna o número de itens em um bloco específico desse contêiner.  
  
```
size_type unsafe_bucket_size(size_type _Bucket);
```  
  
### <a name="parameters"></a>Parâmetros  
 `_Bucket`  
 O número de buckets a ser pesquisado.  
  
### <a name="return-value"></a>Valor de retorno  
 O número atual de buckets neste contêiner.  
  
##  <a name="unsafe_cbegin"></a> unsafe_cbegin 

 Retorna um iterador para o primeiro elemento nesse contêiner para um bloco específico.  
  
```
const_local_iterator unsafe_cbegin(size_type _Bucket) const;
```  
  
### <a name="parameters"></a>Parâmetros  
 `_Bucket`  
 O índice de bucket.  
  
### <a name="return-value"></a>Valor de retorno  
 Um iterador que aponta para o início da partição.  
  
##  <a name="unsafe_cend"></a> unsafe_cend 

 Retorna um iterador para o local que sucede o último elemento em um bloco específico.  
  
```
const_local_iterator unsafe_cend(size_type _Bucket) const;
```  
  
### <a name="parameters"></a>Parâmetros  
 `_Bucket`  
 O índice de bucket.  
  
### <a name="return-value"></a>Valor de retorno  
 Um iterador que aponta para o início da partição.  
  
##  <a name="unsafe_end"></a> unsafe_end 

 Retorna um iterador para o último elemento nesse contêiner para um bloco específico.  
  
```
local_iterator unsafe_end(size_type _Bucket);

const_local_iterator unsafe_end(size_type _Bucket) const;
```  
  
### <a name="parameters"></a>Parâmetros  
 `_Bucket`  
 O índice de bucket.  
  
### <a name="return-value"></a>Valor de retorno  
 Um iterador que aponta para o final da partição.  
  
##  <a name="unsafe_erase"></a> unsafe_erase 

 Remove elementos do `concurrent_unordered_multimap` em posições especificadas. Esse método não é seguro em simultaneidade.  
  
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
 A posição do iterador qual apagar.  
  
 `KVal`  
 O valor da chave para apagar.  
  
 `first`  
 `last`  
  
### <a name="return-value"></a>Valor de retorno  
 As duas primeiras funções membro retornam um iterador que designa o primeiro elemento restante além de todos os elementos removidos ou `concurrent_unordered_multimap::end`() se não houver tal elemento. A terceira função membro retorna o número de elementos que ela remove.  
  
### <a name="remarks"></a>Comentários  
 A primeira função membro remove o elemento da sequência controlada apontada por `_Where`. A segunda função membro remove os elementos no intervalo [ `_Begin`, `_End`).  
  
 A terceira função membro remove os elementos no intervalo delimitado por `concurrent_unordered_multimap::equal_range`(KVal).  
  
##  <a name="unsafe_max_bucket_count"></a> unsafe_max_bucket_count 

 Retorna o número máximo de buckets neste contêiner.  
  
```
size_type unsafe_max_bucket_count() const;
```  
  
### <a name="return-value"></a>Valor de retorno  
 O número máximo de buckets neste contêiner.  
  
## <a name="see-also"></a>Consulte também  
 [Namespace de simultaneidade](concurrency-namespace.md)   
 [Contêineres e objetos em paralelo](../../../parallel/concrt/parallel-containers-and-objects.md)



