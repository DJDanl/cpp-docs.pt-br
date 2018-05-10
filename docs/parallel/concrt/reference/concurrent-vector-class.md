---
title: Classe concurrent_vector | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-concrt
ms.topic: reference
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
dev_langs:
- C++
helpviewer_keywords:
- concurrent_vector class
ms.assetid: a217b4ac-af2b-4d41-94eb-09a75ee28622
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
ms.openlocfilehash: e120e072fb3f56788cbf39fbbc3887f5c816f4ef
ms.sourcegitcommit: 7019081488f68abdd5b2935a3b36e2a5e8c571f8
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/07/2018
---
# <a name="concurrentvector-class"></a>Classe concurrent_vector
O `concurrent_vector` classe é uma classe de contêiner de sequência que permite acesso aleatório para qualquer elemento. Habilita a simultaneidade-safe acrescentar, acesso de elemento, acesso de iterador e operações de passagem do iterador.  
  
## <a name="syntax"></a>Sintaxe  
  
```
template<typename T, class _Ax>
class concurrent_vector: protected details::_Allocator_base<T,
    _Ax>,
 private details::_Concurrent_vector_base_v4;
```  
  
#### <a name="parameters"></a>Parâmetros  
 `T`  
 O tipo de dados dos elementos a serem armazenados no vetor.  
  
 `_Ax`  
 O tipo que representa o objeto de alocador armazenados que encapsula os detalhes sobre a alocação e desalocação de memória para o vetor simultânea. Esse argumento é opcional e o valor padrão é `allocator<T>`.  
  
## <a name="members"></a>Membros  
  
### <a name="public-typedefs"></a>Typedefs públicos  
  
|Nome|Descrição|  
|----------|-----------------|  
|`allocator_type`|Um tipo que representa a classe de alocador de vetor simultânea.|  
|`const_iterator`|Um tipo que fornece um iterador de acesso aleatório que possa ler um `const` elemento em um vetor simultâneo.|  
|`const_pointer`|Um tipo que fornece um ponteiro para um `const` elemento em um vetor simultâneo.|  
|`const_reference`|Um tipo que fornece uma referência a um `const` elemento armazenado em um vetor simultâneo para ler e executar `const` operações.|  
|`const_reverse_iterator`|Um tipo que fornece um iterador de acesso aleatório que possa ler qualquer `const` elemento no vector simultâneo.|  
|`difference_type`|Um tipo que fornece a distância assinada entre dois elementos em um vetor simultâneo.|  
|`iterator`|Um tipo que fornece um iterador de acesso aleatório que pode ler qualquer elemento em um vetor simultâneo. A modificação de um elemento usando o iterador não é seguro de simultaneidade.|  
|`pointer`|Um tipo que fornece um ponteiro para um elemento em um vetor simultâneo.|  
|`reference`|Um tipo que fornece uma referência a um elemento armazenado em um vetor simultâneo.|  
|`reverse_iterator`|Um tipo que fornece um iterador de acesso aleatório que pode ler qualquer elemento em um vetor simultâneo invertido. A modificação de um elemento usando o iterador não é seguro de simultaneidade.|  
|`size_type`|Um tipo que conta o número de elementos em um vetor simultâneo.|  
|`value_type`|Um tipo que representa o tipo de dados armazenado em um vetor simultâneo.|  
  
### <a name="public-constructors"></a>Construtores públicos  
  
|Nome|Descrição|  
|----------|-----------------|  
|[concurrent_vector](#ctor)|Sobrecarregado. Constrói um vetor simultâneo.|  
|[~ concurrent_vector destruidor](#dtor)|Apaga todos os elementos e destrói esse vetor simultânea.|  
  
### <a name="public-methods"></a>Métodos públicos  
  
|Nome|Descrição|  
|----------|-----------------|  
|[assign](#assign)|Sobrecarregado. Apaga os elementos do vetor simultâneo e atribui a ele ou `_N` copia de `_Item`, ou valores especificados pelo intervalo iterator [ `_Begin`, `_End`). Este método não é seguro de simultaneidade.|  
|[at](#at)|Sobrecarregado. Fornece acesso ao elemento no índice especificado no vetor simultâneo. Esse método é seguro de simultaneidade para operações de leitura e também ao crescimento vetor, como certificar-se de que o valor `_Index` é menor que o tamanho do vetor simultâneo.|  
|[back](#back)|Sobrecarregado. Retorna uma referência ou uma `const` referência para o último elemento em vector simultâneo. Se o vetor simultâneo estiver vazio, o valor retornado é indefinido. Esse método é seguro de simultaneidade.|  
|[begin](#begin)|Sobrecarregado. Retorna um iterador do tipo `iterator` ou `const_iterator` para o início do vetor simultâneo. Esse método é seguro de simultaneidade.|  
|[capacity](#capacity)|Retorna o tamanho máximo que o vetor simultâneo pode atingir sem precisar alocar mais memória. Esse método é seguro de simultaneidade.|  
|[cbegin](#cbegin)|Retorna um iterador do tipo `const_iterator` para o início do vetor simultâneo. Esse método é seguro de simultaneidade.|  
|[cend](#cend)|Retorna um iterador do tipo `const_iterator` ao final do vector simultâneo. Esse método é seguro de simultaneidade.|  
|[clear](#clear)|Apaga todos os elementos no vector simultâneo. Este método não é seguro de simultaneidade.|  
|[crbegin](#crbegin)|Retorna um iterador do tipo `const_reverse_iterator` para o início do vetor simultâneo. Esse método é seguro de simultaneidade.|  
|[crend](#crend)|Retorna um iterador do tipo `const_reverse_iterator` ao final do vector simultâneo. Esse método é seguro de simultaneidade.|  
|[empty](#empty)|Testa se o vetor simultâneo está vazio no momento em que este método é chamado. Esse método é seguro de simultaneidade.|  
|[end](#end)|Sobrecarregado. Retorna um iterador do tipo `iterator` ou `const_iterator` ao final do vector simultâneo. Esse método é seguro de simultaneidade.|  
|[front](#front)|Sobrecarregado. Retorna uma referência ou uma `const` referência para o primeiro elemento no vector simultâneo. Se o vetor simultâneo estiver vazio, o valor retornado é indefinido. Esse método é seguro de simultaneidade.|  
|[get_allocator](#get_allocator)|Retorna uma cópia do alocador usado para construir o vetor simultâneo. Esse método é seguro de simultaneidade.|  
|[grow_by](#grow_by)|Sobrecarregado. Aumentar esse vetor simultânea por `_Delta` elementos. Esse método é seguro de simultaneidade.|  
|[grow_to_at_least](#grow_to_at_least)|Aumentar esse vetor simultânea até que tenha pelo menos `_N` elementos. Esse método é seguro de simultaneidade.|  
|[max_size](#max_size)|Retorna o número máximo de elementos de que vetor simultâneo pode conter. Esse método é seguro de simultaneidade.|  
|[push_back](#push_back)|Sobrecarregado. Anexa o item especificado ao final do vetor simultâneo. Esse método é seguro de simultaneidade.|  
|[rbegin](#rbegin)|Sobrecarregado. Retorna um iterador do tipo `reverse_iterator` ou `const_reverse_iterator` para o início do vetor simultâneo. Esse método é seguro de simultaneidade.|  
|[rend](#rend)|Sobrecarregado. Retorna um iterador do tipo `reverse_iterator` ou `const_reverse_iterator` ao final do vector simultâneo. Esse método é seguro de simultaneidade.|  
|[reserve](#reserve)|Aloca espaço suficiente para atingir o vetor simultâneo tamanho `_N` sem precisar alocar mais memória mais tarde. Este método não é seguro de simultaneidade.|  
|[resize](#resize)|Sobrecarregado. Altera o tamanho do vetor simultâneo para o tamanho solicitado, exclusão ou adição de elementos conforme necessário. Este método não é seguro de simultaneidade.|  
|[shrink_to_fit](#shrink_to_fit)|Compacta a representação interna do vetor simultâneo para reduzir a fragmentação e otimizar o uso de memória. Este método não é seguro de simultaneidade.|  
|[size](#size)|Retorna o número de elementos no vector simultâneo. Esse método é seguro de simultaneidade.|  
|[swap](#swap)|Troca o conteúdo dos dois vetores simultâneas. Este método não é seguro de simultaneidade.|  
  
### <a name="public-operators"></a>Operadores públicos  
  
|Nome|Descrição|  
|----------|-----------------|  
|[operator[]](#operator_at)|Sobrecarregado. Fornece acesso ao elemento no índice especificado no vetor simultâneo. Esse método é seguro de simultaneidade para operações de leitura e também ao crescimento vetor, desde que o certificar-se de que o valor `_Index` é menor que o tamanho do vetor simultâneo.|  
|[operator=](#operator_eq)|Sobrecarregado. Atribui o conteúdo de outro `concurrent_vector` deste objeto. Este método não é seguro de simultaneidade.|  
  
## <a name="remarks"></a>Comentários  
 Para obter informações detalhadas sobre o `concurrent_vector` de classe, consulte [objetos e contêineres paralelos](../../../parallel/concrt/parallel-containers-and-objects.md).  
  
## <a name="inheritance-hierarchy"></a>Hierarquia de herança  
 `_Concurrent_vector_base_v4`  
  
 `_Allocator_base`  
  
 `concurrent_vector`  
  
## <a name="requirements"></a>Requisitos  
 **Cabeçalho:** concurrent_vector.h  
  
 **Namespace:** simultaneidade  
  
##  <a name="assign"></a> atribuir 

 Apaga os elementos do vetor simultâneo e atribui a ele ou `_N` copia de `_Item`, ou valores especificados pelo intervalo iterator [ `_Begin`, `_End`). Este método não é seguro de simultaneidade.  
  
```
void assign(
    size_type _N,
    const_reference _Item);

template<class _InputIterator>
void assign(_InputIterator _Begin,
    _InputIterator _End);
```  
  
### <a name="parameters"></a>Parâmetros  
 `_InputIterator`  
 O tipo do iterador especificado.  
  
 `_N`  
 O número de itens que deseja copiar no vetor de simultâneas.  
  
 `_Item`  
 Referência a um valor usado para preencher o vetor simultâneo.  
  
 `_Begin`  
 Um iterador para o primeiro elemento do intervalo de origem.  
  
 `_End`  
 Um iterador para após o último elemento de intervalo de origem.  
  
### <a name="remarks"></a>Comentários  
 `assign` não é seguro de simultaneidade. Certifique-se de que nenhum outro thread está invocando métodos em vetor simultâneo quando você chamar esse método.  
  
##  <a name="at"></a> em 

 Fornece acesso ao elemento no índice especificado no vetor simultâneo. Esse método é seguro de simultaneidade para operações de leitura e também ao crescimento vetor, como certificar-se de que o valor `_Index` é menor que o tamanho do vetor simultâneo.  
  
```
reference at(size_type _Index);

const_reference at(size_type _Index) const;
```  
  
### <a name="parameters"></a>Parâmetros  
 `_Index`  
 O índice do elemento a ser recuperado.  
  
### <a name="return-value"></a>Valor de retorno  
 Uma referência para o item no índice especificado.  
  
### <a name="remarks"></a>Comentários  
 A versão da função `at` que retorna uma não - `const` referência não pode ser usada para gravar simultaneamente para o elemento de diversos threads. Um objeto de sincronização diferente deve ser usado para sincronizar leitura simultânea e operações de gravação para o mesmo elemento de dados.  
  
 O método gera `out_of_range` se `_Index` é maior que ou igual ao tamanho do vetor simultâneo, e `range_error` se o índice for para uma parte danificada do vetor. Para obter detalhes sobre como um vetor pode ficar corrompido, consulte [objetos e contêineres paralelos](../../../parallel/concrt/parallel-containers-and-objects.md).  
  
##  <a name="back"></a> Voltar 

 Retorna uma referência ou uma `const` referência para o último elemento em vector simultâneo. Se o vetor simultâneo estiver vazio, o valor retornado é indefinido. Esse método é seguro de simultaneidade.  
  
```
reference back();

const_reference back() const;
```  
  
### <a name="return-value"></a>Valor de retorno  
 Uma referência ou uma `const` referência para o último elemento em vector simultâneo.  
  
##  <a name="begin"></a> Começar 

 Retorna um iterador do tipo `iterator` ou `const_iterator` para o início do vetor simultâneo. Esse método é seguro de simultaneidade.  
  
```
iterator begin();

const_iterator begin() const;
```  
  
### <a name="return-value"></a>Valor de retorno  
 Um iterador do tipo `iterator` ou `const_iterator` para o início do vetor simultâneo.  
  
##  <a name="capacity"></a> Capacidade 

 Retorna o tamanho máximo que o vetor simultâneo pode atingir sem precisar alocar mais memória. Esse método é seguro de simultaneidade.  
  
```
size_type capacity() const;
```  
  
### <a name="return-value"></a>Valor de retorno  
 O tamanho máximo que o vetor simultâneo pode atingir sem precisar alocar mais memória.  
  
### <a name="remarks"></a>Comentários  
 Ao contrário de uma biblioteca padrão C++ `vector`, um `concurrent_vector` objeto não move os elementos existentes se aloca mais memória.  
  
##  <a name="cbegin"></a> cbegin 

 Retorna um iterador do tipo `const_iterator` para o início do vetor simultâneo. Esse método é seguro de simultaneidade.  
  
```
const_iterator cbegin() const;
```  
  
### <a name="return-value"></a>Valor de retorno  
 Um iterador do tipo `const_iterator` para o início do vetor simultâneo.  
  
##  <a name="cend"></a> cend 

 Retorna um iterador do tipo `const_iterator` ao final do vector simultâneo. Esse método é seguro de simultaneidade.  
  
```
const_iterator cend() const;
```  
  
### <a name="return-value"></a>Valor de retorno  
 Um iterador do tipo `const_iterator` ao final do vector simultâneo.  
  
##  <a name="clear"></a> Limpar 

 Apaga todos os elementos no vector simultâneo. Este método não é seguro de simultaneidade.  
  
```
void clear();
```  
  
### <a name="remarks"></a>Comentários  
 `clear` não é seguro de simultaneidade. Certifique-se de que nenhum outro thread está invocando métodos em vetor simultâneo quando você chamar esse método. `clear` não liberar matrizes internos. Para liberar matrizes internos, chame a função `shrink_to_fit` depois `clear`.  
  
##  <a name="ctor"></a> concurrent_vector 

 Constrói um vetor simultâneo.  
  
```
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
 `M`  
 O tipo do alocador de vetor de origem.  
  
 `_InputIterator`  
 O tipo do iterador de entrada.  
  
 `_Al`  
 A classe de alocador a ser usada com esse objeto.  
  
 `_Vector`  
 A fonte `concurrent_vector` objeto para copiar ou mover os elementos do.  
  
 `_N`  
 A capacidade inicial igual a `concurrent_vector` objeto.  
  
 `_Item`  
 O valor de elementos no objeto construído.  
  
 `_Begin`  
 A posição do primeiro elemento no intervalo de elementos a ser copiado.  
  
 `_End`  
 A posição do primeiro elemento após o intervalo de elementos a ser copiado.  
  
### <a name="remarks"></a>Comentários  
 Todos os construtores armazenam um objeto de alocador `_Al` e inicializar o vector.  
  
 O primeiro construtor Especifica um vetor inicial vazio e especifica explicitamente o tipo de alocador. para ser usado.  
  
 Os construtores de segundo e terceiro especificar uma cópia do vetor simultânea `_Vector`.  
  
 O quarto construtor Especifica um movimento do vetor simultâneo `_Vector`.  
  
 O quinto construtor Especifica uma repetição de um número especificado ( `_N`) dos elementos do valor padrão para a classe `T`.  
  
 O construtor sexto Especifica uma repetição de ( `_N`) elementos de valor `_Item`.  
  
 O construtor de último especifica valores fornecidos pelo intervalo iterador [ `_Begin`, `_End`).  
  
##  <a name="dtor"></a> ~ concurrent_vector 

 Apaga todos os elementos e destrói esse vetor simultânea.  
  
```
~concurrent_vector();
```  
  
##  <a name="crbegin"></a> crbegin 

 Retorna um iterador do tipo `const_reverse_iterator` para o início do vetor simultâneo. Esse método é seguro de simultaneidade.  
  
```
const_reverse_iterator crbegin() const;
```  
  
### <a name="return-value"></a>Valor de retorno  
 Um iterador do tipo `const_reverse_iterator` para o início do vetor simultâneo.  
  
##  <a name="crend"></a> crend 

 Retorna um iterador do tipo `const_reverse_iterator` ao final do vector simultâneo. Esse método é seguro de simultaneidade.  
  
```
const_reverse_iterator crend() const;
```  
  
### <a name="return-value"></a>Valor de retorno  
 Um iterador do tipo `const_reverse_iterator` ao final do vector simultâneo.  
  
##  <a name="empty"></a> vazio 

 Testa se o vetor simultâneo está vazio no momento em que este método é chamado. Esse método é seguro de simultaneidade.  
  
```
bool empty() const;
```  
  
### <a name="return-value"></a>Valor de retorno  
 `true` Se o vetor estava vazio no momento em que a função foi chamada, `false` caso contrário.  
  
##  <a name="end"></a> Final 

 Retorna um iterador do tipo `iterator` ou `const_iterator` ao final do vector simultâneo. Esse método é seguro de simultaneidade.  
  
```
iterator end();

const_iterator end() const;
```  
  
### <a name="return-value"></a>Valor de retorno  
 Um iterador do tipo `iterator` ou `const_iterator` ao final do vector simultâneo.  
  
##  <a name="front"></a> Frente 

 Retorna uma referência ou uma `const` referência para o primeiro elemento no vector simultâneo. Se o vetor simultâneo estiver vazio, o valor retornado é indefinido. Esse método é seguro de simultaneidade.  
  
```
reference front();

const_reference front() const;
```  
  
### <a name="return-value"></a>Valor de retorno  
 Uma referência ou uma `const` referência para o primeiro elemento no vector simultâneo.  
  
##  <a name="get_allocator"></a> get_allocator 

 Retorna uma cópia do alocador usado para construir o vetor simultâneo. Esse método é seguro de simultaneidade.  
  
```
allocator_type get_allocator() const;
```  
  
### <a name="return-value"></a>Valor de retorno  
 Uma cópia do alocador usado para construir o `concurrent_vector` objeto.  
  
##  <a name="grow_by"></a> grow_by 

 Aumentar esse vetor simultânea por `_Delta` elementos. Esse método é seguro de simultaneidade.  
  
```
iterator grow_by(
    size_type _Delta);

iterator grow_by(
    size_type _Delta,
    const_reference _Item);
```  
  
### <a name="parameters"></a>Parâmetros  
 `_Delta`  
 O número de elementos a acrescentar ao objeto.  
  
 `_Item`  
 O valor para inicializar os novos elementos com.  
  
### <a name="return-value"></a>Valor de retorno  
 Um iterador para o primeiro item anexado.  
  
### <a name="remarks"></a>Comentários  
 Se `_Item` não for especificado, os novos elementos são padrão construído.  
  
##  <a name="grow_to_at_least"></a> grow_to_at_least 

 Aumentar esse vetor simultânea até que tenha pelo menos `_N` elementos. Esse método é seguro de simultaneidade.  
  
```
iterator grow_to_at_least(size_type _N);
```  
  
### <a name="parameters"></a>Parâmetros  
 `_N`  
 O novo tamanho mínimo para o `concurrent_vector` objeto.  
  
### <a name="return-value"></a>Valor de retorno  
 Um iterador que aponta para o início da sequência anexado, ou para o elemento no índice `_N` se nenhum elemento foram acrescentado.  
  
##  <a name="max_size"></a> max_size 

 Retorna o número máximo de elementos de que vetor simultâneo pode conter. Esse método é seguro de simultaneidade.  
  
```
size_type max_size() const;
```  
  
### <a name="return-value"></a>Valor de retorno  
 O número máximo de elementos de `concurrent_vector` objeto pode conter.  
  
##  <a name="operator_eq"></a> operador = 

 Atribui o conteúdo de outro `concurrent_vector` deste objeto. Este método não é seguro de simultaneidade.  
  
```
concurrent_vector& operator= (
    const concurrent_vector& _Vector);

template<class M>
concurrent_vector& operator= (
    const concurrent_vector<T, M>& _Vector);

concurrent_vector& operator= (
    concurrent_vector&& _Vector);
```  
  
### <a name="parameters"></a>Parâmetros  
 `M`  
 O tipo do alocador de vetor de origem.  
  
 `_Vector`  
 A fonte `concurrent_vector` objeto.  
  
### <a name="return-value"></a>Valor de retorno  
 Uma referência a este `concurrent_vector` objeto.  
  
##  <a name="operator_at"></a> operador] 

 Fornece acesso ao elemento no índice especificado no vetor simultâneo. Esse método é seguro de simultaneidade para operações de leitura e também ao crescimento vetor, desde que o certificar-se de que o valor `_Index` é menor que o tamanho do vetor simultâneo.  
  
```
reference operator[](size_type _index);

const_reference operator[](size_type _index) const;
```  
  
### <a name="parameters"></a>Parâmetros  
 `_Index`  
 O índice do elemento a ser recuperado.  
  
### <a name="return-value"></a>Valor de retorno  
 Uma referência para o item no índice especificado.  
  
### <a name="remarks"></a>Comentários  
 A versão do `operator []` que retorna uma não - `const` referência não pode ser usada para gravar simultaneamente para o elemento de diversos threads. Um objeto de sincronização diferente deve ser usado para sincronizar leitura simultânea e operações de gravação para o mesmo elemento de dados.  
  
 Nenhuma verificação é executada para garantir que de limites `_Index` é um índice válido no vetor de simultâneas.  
  
##  <a name="push_back"></a> push_back 

 Anexa o item especificado ao final do vetor simultâneo. Esse método é seguro de simultaneidade.  
  
```
iterator push_back(const_reference _Item);

iterator push_back(T&& _Item);
```  
  
### <a name="parameters"></a>Parâmetros  
 `_Item`  
 O valor a ser anexado.  
  
### <a name="return-value"></a>Valor de retorno  
 Um iterador para item anexado.  
  
##  <a name="rbegin"></a> rbegin 

 Retorna um iterador do tipo `reverse_iterator` ou `const_reverse_iterator` para o início do vetor simultâneo. Esse método é seguro de simultaneidade.  
  
```
reverse_iterator rbegin();

const_reverse_iterator rbegin() const;
```  
  
### <a name="return-value"></a>Valor de retorno  
 Um iterador do tipo `reverse_iterator` ou `const_reverse_iterator` para o início do vetor simultâneo.  
  
##  <a name="rend"></a> rend 

 Retorna um iterador do tipo `reverse_iterator` ou `const_reverse_iterator` ao final do vector simultâneo. Esse método é seguro de simultaneidade.  
  
```
reverse_iterator rend();

const_reverse_iterator rend() const;
```  
  
### <a name="return-value"></a>Valor de retorno  
 Um iterador do tipo `reverse_iterator` ou `const_reverse_iterator` ao final do vector simultâneo.  
  
##  <a name="reserve"></a> reserva 

 Aloca espaço suficiente para atingir o vetor simultâneo tamanho `_N` sem precisar alocar mais memória mais tarde. Este método não é seguro de simultaneidade.  
  
```
void reserve(size_type _N);
```  
  
### <a name="parameters"></a>Parâmetros  
 `_N`  
 O número de elementos para reservar espaço para.  
  
### <a name="remarks"></a>Comentários  
 `reserve` não é seguro de simultaneidade. Certifique-se de que nenhum outro thread está invocando métodos em vetor simultâneo quando você chamar esse método. A capacidade do vetor simultânea depois que o método retorna pode ser maior do que a reserva solicitada.  
  
##  <a name="resize"></a> Redimensionar 

 Altera o tamanho do vetor simultâneo para o tamanho solicitado, exclusão ou adição de elementos conforme necessário. Este método não é seguro de simultaneidade.  
  
```
void resize(
    size_type _N);

void resize(
    size_type _N,
    const T& val);
```  
  
### <a name="parameters"></a>Parâmetros  
 `_N`  
 O novo tamanho do concurrent_vector.  
  
 `val`  
 O valor de novos elementos adicionados ao vetor se o novo tamanho seja maior que o tamanho original. Se o valor for omitido, os novos objetos recebem o valor padrão para seu tipo.  
  
### <a name="remarks"></a>Comentários  
 Se o tamanho do contêiner for menor que o tamanho solicitado, os elementos são adicionados ao vetor até atingir o tamanho solicitado. Se o tamanho do contêiner for maior do que o tamanho solicitado, os elementos mais próximos do fim do contêiner são excluídos até que o contêiner atinge o tamanho `_N`. Se o tamanho atual do contêiner for igual ao tamanho solicitado, nenhuma ação será realizada.  
  
 `resize` não é simultaneidade segura. Certifique-se de que nenhum outro thread está invocando métodos em vetor simultâneo quando você chamar esse método.  
  
##  <a name="shrink_to_fit"></a> shrink_to_fit 

 Compacta a representação interna do vetor simultâneo para reduzir a fragmentação e otimizar o uso de memória. Este método não é seguro de simultaneidade.  
  
```
void shrink_to_fit();
```  
  
### <a name="remarks"></a>Comentários  
 Esse método internamente novamente alocará elementos de movimentação de memória, invalidar todos os iteradores. `shrink_to_fit` não é seguro de simultaneidade. Certifique-se de que nenhum outro thread é invocar métodos em vetor simultâneo ao chamar essa função.  
  
##  <a name="size"></a> Tamanho 

 Retorna o número de elementos no vector simultâneo. Esse método é seguro de simultaneidade.  
  
```
size_type size() const;
```  
  
### <a name="return-value"></a>Valor de retorno  
 O número de elementos nesta `concurrent_vector` objeto.  
  
### <a name="remarks"></a>Comentários  
 O tamanho retornado é garantido para incluir todos os elementos adicionados por chamadas para a função `push_back`, ou aumentar as operações concluídas antes de chamar esse método. No entanto, ele também pode incluir elementos que estão alocados, mas ainda estão em construção por chamadas simultâneas para qualquer um dos métodos de crescimento.  
  
##  <a name="swap"></a> Swap 

 Troca o conteúdo dos dois vetores simultâneas. Este método não é seguro de simultaneidade.  
  
```
void swap(concurrent_vector& _Vector);
```  
  
### <a name="parameters"></a>Parâmetros  
 `_Vector`  
 O objeto `concurrent_vector` com o qual trocar conteúdo.  
  
## <a name="see-also"></a>Consulte também  
 [Namespace de simultaneidade](concurrency-namespace.md)   
 [Contêineres e objetos em paralelo](../../../parallel/concrt/parallel-containers-and-objects.md)



