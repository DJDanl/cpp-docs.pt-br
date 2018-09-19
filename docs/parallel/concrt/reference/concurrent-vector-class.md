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
ms.openlocfilehash: fe5ac6d819ed6f068095fe2abda5363686ed7dbd
ms.sourcegitcommit: 913c3bf23937b64b90ac05181fdff3df947d9f1c
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/18/2018
ms.locfileid: "46117420"
---
# <a name="concurrentvector-class"></a>Classe concurrent_vector
O `concurrent_vector` classe é uma classe de contêiner de sequência que permite acesso aleatório a qualquer elemento. Ele habilita a prova de simultaneidade de acréscimo, acesso de elemento, acesso de iterador e operações de passagem de iterador.  
  
## <a name="syntax"></a>Sintaxe  
  
```
template<typename T, class _Ax>
class concurrent_vector: protected details::_Allocator_base<T,
    _Ax>,
 private details::_Concurrent_vector_base_v4;
```  
  
#### <a name="parameters"></a>Parâmetros  
*T*<br/>
O tipo de dados dos elementos a ser armazenado no vetor.  
  
*_Ax*<br/>
O tipo que representa o objeto de alocador armazenado que encapsula detalhes sobre a alocação e desalocação de memória para o vetor simultâneo. Esse argumento é opcional e o valor padrão é `allocator<T>`.  
  
## <a name="members"></a>Membros  
  
### <a name="public-typedefs"></a>Typedefs públicos  
  
|Nome|Descrição|  
|----------|-----------------|  
|`allocator_type`|Um tipo que representa a classe de alocador do vetor simultâneo.|  
|`const_iterator`|Um tipo que fornece um iterador de acesso aleatório que pode ler um `const` elemento em um vetor simultâneo.|  
|`const_pointer`|Um tipo que fornece um ponteiro para um `const` elemento em um vetor simultâneo.|  
|`const_reference`|Um tipo que fornece uma referência a um `const` elemento armazenado em um vetor simultâneo para leitura e execução `const` operações.|  
|`const_reverse_iterator`|Um tipo que fornece um iterador de acesso aleatório que pode ler qualquer `const` elemento no vetor simultâneo.|  
|`difference_type`|Um tipo que fornece a distância com sinal entre dois elementos em um vetor simultâneo.|  
|`iterator`|Um tipo que fornece um iterador de acesso aleatório que pode ler qualquer elemento em um vetor simultâneo. Modificação de um elemento usando o iterador não é seguro em simultaneidade.|  
|`pointer`|Um tipo que fornece um ponteiro para um elemento em um vetor simultâneo.|  
|`reference`|Um tipo que fornece uma referência a um elemento armazenado em um vetor simultâneo.|  
|`reverse_iterator`|Um tipo que fornece um iterador de acesso aleatório que pode ler qualquer elemento em um vetor simultâneo invertido. Modificação de um elemento usando o iterador não é seguro em simultaneidade.|  
|`size_type`|Um tipo que conta o número de elementos em um vetor simultâneo.|  
|`value_type`|Um tipo que representa o tipo de dados armazenado em um vetor simultâneo.|  
  
### <a name="public-constructors"></a>Construtores públicos  
  
|Nome|Descrição|  
|----------|-----------------|  
|[concurrent_vector](#ctor)|Sobrecarregado. Constrói um vetor simultâneo.|  
|[~ concurrent_vector destruidor](#dtor)|Apaga todos os elementos e destrói esse vetor simultâneo.|  
  
### <a name="public-methods"></a>Métodos públicos  
  
|Nome|Descrição|  
|----------|-----------------|  
|[assign](#assign)|Sobrecarregado. Apaga os elementos do vetor simultâneo e atribui a ela ou `_N` copia de `_Item`, ou valores especificados pelo intervalo do iterador [ `_Begin`, `_End`). Esse método não é seguro em simultaneidade.|  
|[at](#at)|Sobrecarregado. Fornece acesso ao elemento no índice especificado no vetor simultâneo. Esse método é seguro em simultaneidade para operações de leitura e também ao mesmo tempo, aumentando o vetor, desde que você tiver assegurado que o valor `_Index` é menor que o tamanho do vetor simultâneo.|  
|[back](#back)|Sobrecarregado. Retorna uma referência ou uma `const` fazem referência ao último elemento no vetor simultâneo. Se o vetor simultâneo estiver vazio, o valor retornado será indefinido. Esse método é seguro em simultaneidade.|  
|[begin](#begin)|Sobrecarregado. Retorna um iterador do tipo `iterator` ou `const_iterator` para o início do vetor simultâneo. Esse método é seguro em simultaneidade.|  
|[capacity](#capacity)|Retorna o tamanho máximo para o qual o vetor simultâneo pode crescer sem a necessidade de alocar mais memória. Esse método é seguro em simultaneidade.|  
|[cbegin](#cbegin)|Retorna um iterador do tipo `const_iterator` para o início do vetor simultâneo. Esse método é seguro em simultaneidade.|  
|[cend](#cend)|Retorna um iterador do tipo `const_iterator` até o final do vetor simultâneo. Esse método é seguro em simultaneidade.|  
|[clear](#clear)|Apaga todos os elementos no vetor simultâneo. Esse método não é seguro em simultaneidade.|  
|[crbegin](#crbegin)|Retorna um iterador do tipo `const_reverse_iterator` para o início do vetor simultâneo. Esse método é seguro em simultaneidade.|  
|[crend](#crend)|Retorna um iterador do tipo `const_reverse_iterator` até o final do vetor simultâneo. Esse método é seguro em simultaneidade.|  
|[empty](#empty)|Testa se o vetor simultâneo está vazio no momento em que esse método é chamado. Esse método é seguro em simultaneidade.|  
|[end](#end)|Sobrecarregado. Retorna um iterador do tipo `iterator` ou `const_iterator` até o final do vetor simultâneo. Esse método é seguro em simultaneidade.|  
|[front](#front)|Sobrecarregado. Retorna uma referência ou uma `const` referência para o primeiro elemento no vetor simultâneo. Se o vetor simultâneo estiver vazio, o valor retornado será indefinido. Esse método é seguro em simultaneidade.|  
|[get_allocator](#get_allocator)|Retorna uma cópia do alocador usado para construir o vetor simultâneo. Esse método é seguro em simultaneidade.|  
|[grow_by](#grow_by)|Sobrecarregado. Aumenta esse vetor simultâneo por `_Delta` elementos. Esse método é seguro em simultaneidade.|  
|[grow_to_at_least](#grow_to_at_least)|Aumenta esse vetor simultâneo até que tenha pelo menos `_N` elementos. Esse método é seguro em simultaneidade.|  
|[max_size](#max_size)|Retorna o número máximo de elementos que do vetor simultâneo pode conter. Esse método é seguro em simultaneidade.|  
|[push_back](#push_back)|Sobrecarregado. Acrescenta o item fornecido ao final do vetor simultâneo. Esse método é seguro em simultaneidade.|  
|[rbegin](#rbegin)|Sobrecarregado. Retorna um iterador do tipo `reverse_iterator` ou `const_reverse_iterator` para o início do vetor simultâneo. Esse método é seguro em simultaneidade.|  
|[rend](#rend)|Sobrecarregado. Retorna um iterador do tipo `reverse_iterator` ou `const_reverse_iterator` até o final do vetor simultâneo. Esse método é seguro em simultaneidade.|  
|[reserve](#reserve)|Aloca espaço suficiente para atingir o vetor simultâneo tamanho `_N` sem a necessidade de alocar mais memória mais tarde. Esse método não é seguro em simultaneidade.|  
|[resize](#resize)|Sobrecarregado. Altera o tamanho do vetor simultâneo para o tamanho solicitado, excluir ou adicionar elementos conforme necessário. Esse método não é seguro em simultaneidade.|  
|[shrink_to_fit](#shrink_to_fit)|Compacta a representação interna do vetor simultâneo para reduzir a fragmentação e otimizar o uso de memória. Esse método não é seguro em simultaneidade.|  
|[size](#size)|Retorna o número de elementos no vetor simultâneo. Esse método é seguro em simultaneidade.|  
|[swap](#swap)|Troca o conteúdo de dois vetores simultâneas. Esse método não é seguro em simultaneidade.|  
  
### <a name="public-operators"></a>Operadores públicos  
  
|Nome|Descrição|  
|----------|-----------------|  
|[operator[]](#operator_at)|Sobrecarregado. Fornece acesso ao elemento no índice especificado no vetor simultâneo. Esse método é seguro em simultaneidade para operações de leitura e também ao mesmo tempo, aumentando o vetor, desde que a garantir que o valor `_Index` é menor que o tamanho do vetor simultâneo.|  
|[operator=](#operator_eq)|Sobrecarregado. Atribui o conteúdo de outro `concurrent_vector` objeto para esse outro. Esse método não é seguro em simultaneidade.|  
  
## <a name="remarks"></a>Comentários  
 Para obter informações detalhadas sobre o `concurrent_vector` classe, consulte [paralela contêineres e objetos](../../../parallel/concrt/parallel-containers-and-objects.md).  
  
## <a name="inheritance-hierarchy"></a>Hierarquia de herança  
 `_Concurrent_vector_base_v4`  
  
 `_Allocator_base`  
  
 `concurrent_vector`  
  
## <a name="requirements"></a>Requisitos  
 **Cabeçalho:** concurrent_vector. h  
  
 **Namespace:** simultaneidade  
  
##  <a name="assign"></a> Atribuir 

 Apaga os elementos do vetor simultâneo e atribui a ela ou `_N` copia de `_Item`, ou valores especificados pelo intervalo do iterador [ `_Begin`, `_End`). Esse método não é seguro em simultaneidade.  
  
```
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
  
*USO*<br/>
O número de itens a serem copiados para o vetor simultâneo.  
  
*Item*<br/>
Referência a um valor usado para preencher o vetor simultâneo.  
  
*Iniciar*<br/>
Um iterador para o primeiro elemento do intervalo de origem.  
  
*Encerrar*<br/>
Um iterador para a posição logo após o último elemento do intervalo de origem.  
  
### <a name="remarks"></a>Comentários  
 `assign` não é seguro em simultaneidade. Você deve garantir que nenhum outro thread estiver chamando métodos no vetor simultâneo quando você chama esse método.  
  
##  <a name="at"></a> em 

 Fornece acesso ao elemento no índice especificado no vetor simultâneo. Esse método é seguro em simultaneidade para operações de leitura e também ao mesmo tempo, aumentando o vetor, desde que você tiver assegurado que o valor `_Index` é menor que o tamanho do vetor simultâneo.  
  
```
reference at(size_type _Index);

const_reference at(size_type _Index) const;
```  
  
### <a name="parameters"></a>Parâmetros  
*Index*<br/>
O índice do elemento a ser recuperado.  
  
### <a name="return-value"></a>Valor de retorno  
 Uma referência para o item no índice especificado.  
  
### <a name="remarks"></a>Comentários  
 A versão da função `at` que retorna um não - `const` referência não pode ser usada para gravar simultaneamente para o elemento de diversos threads. Um objeto de sincronização diferente deve ser usado para sincronizar a leitura simultâneas e operações de gravação ao mesmo elemento de dados.  
  
 O método gerará `out_of_range` se `_Index` é maior que ou igual ao tamanho do vetor simultâneo, e `range_error` se o índice é uma parte interrompida do vetor. Para obter detalhes sobre como um vetor pode se tornar quebrado, consulte [paralela contêineres e objetos](../../../parallel/concrt/parallel-containers-and-objects.md).  
  
##  <a name="back"></a> Voltar 

 Retorna uma referência ou uma `const` fazem referência ao último elemento no vetor simultâneo. Se o vetor simultâneo estiver vazio, o valor retornado será indefinido. Esse método é seguro em simultaneidade.  
  
```
reference back();

const_reference back() const;
```  
  
### <a name="return-value"></a>Valor de retorno  
 Uma referência ou um `const` fazem referência ao último elemento no vetor simultâneo.  
  
##  <a name="begin"></a> começar 

 Retorna um iterador do tipo `iterator` ou `const_iterator` para o início do vetor simultâneo. Esse método é seguro em simultaneidade.  
  
```
iterator begin();

const_iterator begin() const;
```  
  
### <a name="return-value"></a>Valor de retorno  
 Um iterador do tipo `iterator` ou `const_iterator` para o início do vetor simultâneo.  
  
##  <a name="capacity"></a> capacidade 

 Retorna o tamanho máximo para o qual o vetor simultâneo pode crescer sem a necessidade de alocar mais memória. Esse método é seguro em simultaneidade.  
  
```
size_type capacity() const;
```  
  
### <a name="return-value"></a>Valor de retorno  
 O tamanho máximo para o qual o vetor simultâneo pode crescer sem a necessidade de alocar mais memória.  
  
### <a name="remarks"></a>Comentários  
 Ao contrário de uma biblioteca padrão C++ `vector`, um `concurrent_vector` objeto não move os elementos existentes se ele aloca mais memória.  
  
##  <a name="cbegin"></a> cbegin 

 Retorna um iterador do tipo `const_iterator` para o início do vetor simultâneo. Esse método é seguro em simultaneidade.  
  
```
const_iterator cbegin() const;
```  
  
### <a name="return-value"></a>Valor de retorno  
 Um iterador do tipo `const_iterator` para o início do vetor simultâneo.  
  
##  <a name="cend"></a> cend 

 Retorna um iterador do tipo `const_iterator` até o final do vetor simultâneo. Esse método é seguro em simultaneidade.  
  
```
const_iterator cend() const;
```  
  
### <a name="return-value"></a>Valor de retorno  
 Um iterador do tipo `const_iterator` até o final do vetor simultâneo.  
  
##  <a name="clear"></a> Limpar 

 Apaga todos os elementos no vetor simultâneo. Esse método não é seguro em simultaneidade.  
  
```
void clear();
```  
  
### <a name="remarks"></a>Comentários  
 `clear` não é seguro em simultaneidade. Você deve garantir que nenhum outro thread estiver chamando métodos no vetor simultâneo quando você chama esse método. `clear` não libera matrizes internas. Para liberar as matrizes internas, chame a função `shrink_to_fit` depois de `clear`.  
  
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
*M*<br/>
O tipo de alocador do vetor de origem.  
  
*_InputIterator*<br/>
O tipo do iterador de entrada.  
  
*_Al*<br/>
A classe de alocador a ser usada com esse objeto.  
  
*_Vector*<br/>
A fonte `concurrent_vector` objeto para copiar ou mover elementos.  
  
*USO*<br/>
A capacidade inicial do `concurrent_vector` objeto.  
  
*Item*<br/>
O valor dos elementos no objeto construído.  
  
*Iniciar*<br/>
A posição do primeiro elemento no intervalo de elementos a ser copiado.  
  
*Encerrar*<br/>
A posição do primeiro elemento após o intervalo de elementos a ser copiado.  
  
### <a name="remarks"></a>Comentários  
 Todos os construtores armazenam um objeto alocador `_Al` e inicializar o vector.  
  
 O primeiro construtor Especifica um vetor inicial vazio e especifica explicitamente o tipo de alocador. a ser usado.  
  
 Os segundo e terceiro construtores especificam uma cópia do vetor simultâneo `_Vector`.  
  
 O quarto construtor Especifica um movimento do vetor simultâneo `_Vector`.  
  
 O quinto construtor Especifica uma repetição de um número especificado ( `_N`) de elementos do valor padrão para a classe `T`.  
  
 O sexto construtor Especifica uma repetição de ( `_N`) elementos de valor `_Item`.  
  
 O último construtor especifica valores fornecidos pelo intervalo do iterador [ `_Begin`, `_End`).  
  
##  <a name="dtor"></a> ~ concurrent_vector 

 Apaga todos os elementos e destrói esse vetor simultâneo.  
  
```
~concurrent_vector();
```  
  
##  <a name="crbegin"></a> crbegin 

 Retorna um iterador do tipo `const_reverse_iterator` para o início do vetor simultâneo. Esse método é seguro em simultaneidade.  
  
```
const_reverse_iterator crbegin() const;
```  
  
### <a name="return-value"></a>Valor de retorno  
 Um iterador do tipo `const_reverse_iterator` para o início do vetor simultâneo.  
  
##  <a name="crend"></a> crend 

 Retorna um iterador do tipo `const_reverse_iterator` até o final do vetor simultâneo. Esse método é seguro em simultaneidade.  
  
```
const_reverse_iterator crend() const;
```  
  
### <a name="return-value"></a>Valor de retorno  
 Um iterador do tipo `const_reverse_iterator` até o final do vetor simultâneo.  
  
##  <a name="empty"></a> vazio 

 Testa se o vetor simultâneo está vazio no momento em que esse método é chamado. Esse método é seguro em simultaneidade.  
  
```
bool empty() const;
```  
  
### <a name="return-value"></a>Valor de retorno  
 `true` Se o vetor estiver vazio no momento em que a função foi chamada, `false` caso contrário.  
  
##  <a name="end"></a> final 

 Retorna um iterador do tipo `iterator` ou `const_iterator` até o final do vetor simultâneo. Esse método é seguro em simultaneidade.  
  
```
iterator end();

const_iterator end() const;
```  
  
### <a name="return-value"></a>Valor de retorno  
 Um iterador do tipo `iterator` ou `const_iterator` até o final do vetor simultâneo.  
  
##  <a name="front"></a> front 

 Retorna uma referência ou uma `const` referência para o primeiro elemento no vetor simultâneo. Se o vetor simultâneo estiver vazio, o valor retornado será indefinido. Esse método é seguro em simultaneidade.  
  
```
reference front();

const_reference front() const;
```  
  
### <a name="return-value"></a>Valor de retorno  
 Uma referência ou um `const` referência para o primeiro elemento no vetor simultâneo.  
  
##  <a name="get_allocator"></a> get_allocator 

 Retorna uma cópia do alocador usado para construir o vetor simultâneo. Esse método é seguro em simultaneidade.  
  
```
allocator_type get_allocator() const;
```  
  
### <a name="return-value"></a>Valor de retorno  
 Uma cópia do alocador usado para construir o `concurrent_vector` objeto.  
  
##  <a name="grow_by"></a> grow_by 

 Aumenta esse vetor simultâneo por `_Delta` elementos. Esse método é seguro em simultaneidade.  
  
```
iterator grow_by(
    size_type _Delta);

iterator grow_by(
    size_type _Delta,
    const_reference _Item);
```  
  
### <a name="parameters"></a>Parâmetros  
*_Delta*<br/>
O número de elementos a acrescentar ao objeto.  
  
*Item*<br/>
O valor para inicializar os novos elementos com.  
  
### <a name="return-value"></a>Valor de retorno  
 Um iterador para o primeiro item é anexado.  
  
### <a name="remarks"></a>Comentários  
 Se `_Item` não for especificado, os novos elementos são construídos por padrão.  
  
##  <a name="grow_to_at_least"></a> grow_to_at_least 

 Aumenta esse vetor simultâneo até que tenha pelo menos `_N` elementos. Esse método é seguro em simultaneidade.  
  
```
iterator grow_to_at_least(size_type _N);
```  
  
### <a name="parameters"></a>Parâmetros  
*USO*<br/>
O novo tamanho mínimo para o `concurrent_vector` objeto.  
  
### <a name="return-value"></a>Valor de retorno  
 Um iterador que aponta para o início da sequência acrescentado, ou para o elemento no índice `_N` se nenhum elemento foram acrescentado.  
  
##  <a name="max_size"></a> max_size 

 Retorna o número máximo de elementos que do vetor simultâneo pode conter. Esse método é seguro em simultaneidade.  
  
```
size_type max_size() const;
```  
  
### <a name="return-value"></a>Valor de retorno  
 O número máximo de elementos a `concurrent_vector` objeto pode conter.  
  
##  <a name="operator_eq"></a> operador = 

 Atribui o conteúdo de outro `concurrent_vector` objeto para esse outro. Esse método não é seguro em simultaneidade.  
  
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
*M*<br/>
O tipo de alocador do vetor de origem.  
  
*_Vector*<br/>
A fonte `concurrent_vector` objeto.  
  
### <a name="return-value"></a>Valor de retorno  
 Uma referência a este `concurrent_vector` objeto.  
  
##  <a name="operator_at"></a> operador] 

 Fornece acesso ao elemento no índice especificado no vetor simultâneo. Esse método é seguro em simultaneidade para operações de leitura e também ao mesmo tempo, aumentando o vetor, desde que a garantir que o valor `_Index` é menor que o tamanho do vetor simultâneo.  
  
```
reference operator[](size_type _index);

const_reference operator[](size_type _index) const;
```  
  
### <a name="parameters"></a>Parâmetros  
*Index*<br/>
O índice do elemento a ser recuperado.  
  
### <a name="return-value"></a>Valor de retorno  
 Uma referência para o item no índice especificado.  
  
### <a name="remarks"></a>Comentários  
 A versão do `operator []` que retorna um não - `const` referência não pode ser usada para gravar simultaneamente para o elemento de diversos threads. Um objeto de sincronização diferente deve ser usado para sincronizar a leitura simultâneas e operações de gravação ao mesmo elemento de dados.  
  
 Não há limites de verificação é realizada para garantir que `_Index` é um índice válido para o vetor simultâneo.  
  
##  <a name="push_back"></a> push_back 

 Acrescenta o item fornecido ao final do vetor simultâneo. Esse método é seguro em simultaneidade.  
  
```
iterator push_back(const_reference _Item);

iterator push_back(T&& _Item);
```  
  
### <a name="parameters"></a>Parâmetros  
*Item*<br/>
O valor a ser acrescentado.  
  
### <a name="return-value"></a>Valor de retorno  
 Um iterador para o item é anexado.  
  
##  <a name="rbegin"></a> rbegin 

 Retorna um iterador do tipo `reverse_iterator` ou `const_reverse_iterator` para o início do vetor simultâneo. Esse método é seguro em simultaneidade.  
  
```
reverse_iterator rbegin();

const_reverse_iterator rbegin() const;
```  
  
### <a name="return-value"></a>Valor de retorno  
 Um iterador do tipo `reverse_iterator` ou `const_reverse_iterator` para o início do vetor simultâneo.  
  
##  <a name="rend"></a> rend 

 Retorna um iterador do tipo `reverse_iterator` ou `const_reverse_iterator` até o final do vetor simultâneo. Esse método é seguro em simultaneidade.  
  
```
reverse_iterator rend();

const_reverse_iterator rend() const;
```  
  
### <a name="return-value"></a>Valor de retorno  
 Um iterador do tipo `reverse_iterator` ou `const_reverse_iterator` até o final do vetor simultâneo.  
  
##  <a name="reserve"></a> reservar 

 Aloca espaço suficiente para atingir o vetor simultâneo tamanho `_N` sem a necessidade de alocar mais memória mais tarde. Esse método não é seguro em simultaneidade.  
  
```
void reserve(size_type _N);
```  
  
### <a name="parameters"></a>Parâmetros  
*USO*<br/>
O número de elementos para reservar espaço para.  
  
### <a name="remarks"></a>Comentários  
 `reserve` não é seguro em simultaneidade. Você deve garantir que nenhum outro thread estiver chamando métodos no vetor simultâneo quando você chama esse método. A capacidade do vetor simultâneo depois que o método retorna pode ser maior que a reserva solicitada.  
  
##  <a name="resize"></a> redimensionar 

 Altera o tamanho do vetor simultâneo para o tamanho solicitado, excluir ou adicionar elementos conforme necessário. Esse método não é seguro em simultaneidade.  
  
```
void resize(
    size_type _N);

void resize(
    size_type _N,
    const T& val);
```  
  
### <a name="parameters"></a>Parâmetros  
*USO*<br/>
O novo tamanho do concurrent_vector.  
  
*Val*<br/>
O valor de novos elementos adicionados ao vetor se o novo tamanho for maior que o tamanho original. Se o valor for omitido, os novos objetos recebem o valor padrão para seu tipo.  
  
### <a name="remarks"></a>Comentários  
 Se o tamanho do contêiner for menor que o tamanho solicitado, os elementos são adicionados ao vetor até ele atingir o tamanho solicitado. Se o tamanho do contêiner for maior que o tamanho solicitado, os elementos mais próximos do final do contêiner são excluídos até o contêiner de atinge o tamanho `_N`. Se o tamanho atual do contêiner for igual ao tamanho solicitado, nenhuma ação será realizada.  
  
 `resize` não é simultaneidade seguro. Você deve garantir que nenhum outro thread estiver chamando métodos no vetor simultâneo quando você chama esse método.  
  
##  <a name="shrink_to_fit"></a> shrink_to_fit 

 Compacta a representação interna do vetor simultâneo para reduzir a fragmentação e otimizar o uso de memória. Esse método não é seguro em simultaneidade.  
  
```
void shrink_to_fit();
```  
  
### <a name="remarks"></a>Comentários  
 Esse método internamente novamente alocará elementos de movimentação de memória, invalidar todos os iteradores. `shrink_to_fit` não é seguro em simultaneidade. Você deve garantir que nenhum outro thread estiver chamando métodos no vetor simultâneo ao chamar essa função.  
  
##  <a name="size"></a> Tamanho 

 Retorna o número de elementos no vetor simultâneo. Esse método é seguro em simultaneidade.  
  
```
size_type size() const;
```  
  
### <a name="return-value"></a>Valor de retorno  
 O número de elementos neste `concurrent_vector` objeto.  
  
### <a name="remarks"></a>Comentários  
 O tamanho retornado é garantido para incluir todos os elementos acrescentados por chamadas para a função `push_back`, ou operações que foram concluídos antes de invocar esse método de crescimento. No entanto, ele também pode incluir elementos que são alocados, mas ainda estão em construção por chamadas simultâneas para qualquer um dos métodos de crescimento.  
  
##  <a name="swap"></a> troca 

 Troca o conteúdo de dois vetores simultâneas. Esse método não é seguro em simultaneidade.  
  
```
void swap(concurrent_vector& _Vector);
```  
  
### <a name="parameters"></a>Parâmetros  
*_Vector*<br/>
O objeto `concurrent_vector` com o qual trocar conteúdo.  
  
## <a name="see-also"></a>Consulte também  
 [Namespace de simultaneidade](concurrency-namespace.md)   
 [Contêineres e objetos em paralelo](../../../parallel/concrt/parallel-containers-and-objects.md)



