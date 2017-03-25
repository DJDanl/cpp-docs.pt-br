---
title: Classe concurrent_queue | Documentos do Microsoft
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- devlang-cpp
ms.tgt_pltfrm: 
ms.topic: article
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
dev_langs:
- C++
helpviewer_keywords:
- concurrent_queue class
ms.assetid: c2218996-d0ea-40e9-b002-e9a15b085f51
caps.latest.revision: 21
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
ms.openlocfilehash: d2af8483f38a14454e3aa1aecf28864bab1c6a1a
ms.lasthandoff: 03/17/2017

---
# <a name="concurrentqueue-class"></a>Classe concurrent_queue
O `concurrent_queue` classe é uma classe de contêiner de sequência permite primeiro a entrar, PEPS acesso a seus elementos. Ele permite que um conjunto limitado de operações com segurança de simultaneidade, tais como `push` e `try_pop`.  
  
## <a name="syntax"></a>Sintaxe  
  
```
template<typename T, class _Ax>
class concurrent_queue: public ::Concurrency::details::_Concurrent_queue_base_v4;
```  
  
#### <a name="parameters"></a>Parâmetros  
 `T`  
 O tipo de dados dos elementos a ser armazenado na fila.  
  
 `_Ax`  
 O tipo que representa o objeto de alocador armazenado que encapsula detalhes sobre a alocação e desalocação de memória para essa fila simultânea. Esse argumento é opcional e o valor padrão é `allocator<``T``>`.  
  
## <a name="members"></a>Membros  
  
### <a name="public-typedefs"></a>Typedefs públicos  
  
|Nome|Descrição|  
|----------|-----------------|  
|`allocator_type`|Um tipo que representa a classe do alocador de fila simultânea.|  
|`const_iterator`|Um tipo que representa um não thread-safe `const` iterador sobre elementos em uma fila simultânea.|  
|`const_reference`|Um tipo que fornece uma referência a um `const` elemento armazenado em uma fila simultânea para leitura e execução `const` operações.|  
|`difference_type`|Um tipo que fornece a distância com sinal entre dois elementos em uma fila simultânea.|  
|`iterator`|Um tipo que representa um iterador não thread-safe sobre os elementos em uma fila simultânea.|  
|`reference`|Um tipo que fornece uma referência a um elemento armazenado em uma fila simultânea.|  
|`size_type`|Um tipo que conta o número de elementos em uma fila simultânea.|  
|`value_type`|Um tipo que representa o tipo de dados armazenado em uma fila simultânea.|  
  
### <a name="public-constructors"></a>Construtores públicos  
  
|Nome|Descrição|  
|----------|-----------------|  
|[concurrent_queue](#ctor)|Sobrecarregado. Constrói uma fila simultânea.|  
|[~ concurrent_queue destruidor](#dtor)|Destrói a fila simultânea.|  
  
### <a name="public-methods"></a>Métodos públicos  
  
|Nome|Descrição|  
|----------|-----------------|  
|[clear](#clear)|Limpa a fila simultânea, destruindo qualquer atualmente enfileiradas elementos. Esse método não é uma prova de simultaneidade.|  
|[empty](#empty)|Testa se a fila simultânea está vazia no momento em que este método é chamado. Esse método é uma prova de simultaneidade.|  
|[get_allocator](#get_allocator)|Retorna uma cópia do alocador usado para construir o simultâneos na fila. Esse método é uma prova de simultaneidade.|  
|[push](#push)|Sobrecarregado. Enfileira um item no final da fila simultânea. Esse método é uma prova de simultaneidade.|  
|[try_pop](#try_pop)|Remove um item da fila se houver uma disponível. Esse método é uma prova de simultaneidade.|  
|[unsafe_begin](#unsafe_begin)|Sobrecarregado. Retorna um iterador do tipo `iterator` ou `const_iterator` para o início da fila simultânea. Esse método não é uma prova de simultaneidade.|  
|[unsafe_end](#unsafe_end)|Sobrecarregado. Retorna um iterador do tipo `iterator` ou `const_iterator` ao final da fila simultânea. Esse método não é uma prova de simultaneidade.|  
|[unsafe_size](#unsafe_size)|Retorna o número de itens na fila. Esse método não é uma prova de simultaneidade.|  
  
## <a name="remarks"></a>Comentários  
 Para obter mais informações, consulte [paralela contêineres e objetos](../../../parallel/concrt/parallel-containers-and-objects.md).  
  
## <a name="inheritance-hierarchy"></a>Hierarquia de herança  
 `concurrent_queue`  
  
## <a name="requirements"></a>Requisitos  
 **Cabeçalho:** concurrent_queue.h  
  
 **Namespace:** simultaneidade  
  
##  <a name="clear"></a>Limpar 

 Limpa a fila simultânea, destruindo qualquer atualmente enfileiradas elementos. Esse método não é uma prova de simultaneidade.  
  
```
void clear();
```  
  
##  <a name="ctor"></a>concurrent_queue 

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
 `_InputIterator`  
 O tipo de iterador de entrada que especifica um intervalo de valores.  
  
 `_Al`  
 A classe de alocador a ser usada com esse objeto.  
  
 `_OtherQ`  
 A fonte `concurrent_queue` copiar ou mover elementos de objeto.  
  
 `_Begin`  
 A posição do primeiro elemento no intervalo de elementos a ser copiado.  
  
 `_End`  
 A posição do primeiro elemento após o intervalo de elementos a ser copiado.  
  
### <a name="remarks"></a>Comentários  
 Todos os construtores armazenam um objeto alocador `_Al` e inicializar a fila.  
  
 O primeiro construtor Especifica uma fila inicial vazia e especifica explicitamente o tipo de alocador a ser usado.  
  
 O segundo construtor Especifica uma cópia da fila simultânea `_OtherQ`.  
  
 O terceiro construtor Especifica uma movimentação da fila simultânea `_OtherQ`.  
  
 O quarto construtor especifica valores fornecidos pelo intervalo iterador [ `_Begin`, `_End`).  
  
##  <a name="dtor"></a>~ concurrent_queue 

 Destrói a fila simultânea.  
  
```
~concurrent_queue();
```  
  
##  <a name="empty"></a>vazio 

 Testa se a fila simultânea está vazia no momento em que este método é chamado. Esse método é uma prova de simultaneidade.  
  
```
bool empty() const;
```  
  
### <a name="return-value"></a>Valor de retorno  
 `true`Se a fila simultânea estava vazia no momento, vimos que, `false` caso contrário.  
  
### <a name="remarks"></a>Comentários  
 Embora esse método é a prova de simultaneidade em relação a chamadas para os métodos `push`, `try_pop`, e `empty`, o valor retornado pode estar incorreto no momento é inspecionado pelo thread de chamada.  
  
##  <a name="get_allocator"></a>get_allocator 

 Retorna uma cópia do alocador usado para construir o simultâneos na fila. Esse método é uma prova de simultaneidade.  
  
```
allocator_type get_allocator() const;
```  
  
### <a name="return-value"></a>Valor de retorno  
 Uma cópia do alocador usado para construir o simultâneos na fila.  
  
##  <a name="push"></a>envio por push 

 Enfileira um item no final da fila simultânea. Esse método é uma prova de simultaneidade.  
  
```
void push(const T& _Src);

void push(T&& _Src);
```  
  
### <a name="parameters"></a>Parâmetros  
 `_Src`  
 O item a ser adicionado à fila.  
  
### <a name="remarks"></a>Comentários  
 `push`é a prova de simultaneidade em relação a chamadas para os métodos `push`, `try_pop`, e `empty`.  
  
##  <a name="try_pop"></a>try_pop 

 Remove um item da fila se houver uma disponível. Esse método é uma prova de simultaneidade.  
  
```
bool try_pop(T& _Dest);
```  
  
### <a name="parameters"></a>Parâmetros  
 `_Dest`  
 Uma referência a um local para armazenar o item da fila.  
  
### <a name="return-value"></a>Valor de retorno  
 `true`Se um item da fila com êxito, `false` caso contrário.  
  
### <a name="remarks"></a>Comentários  
 Se um item da fila com êxito, o parâmetro `_Dest` recebe o valor da fila, o valor original mantido na fila é destruído, e essa função retornar `true`. Se não houvesse nenhum item para remover, esta função retorna `false` sem bloqueio e o conteúdo da `_Dest` parâmetro são indefinidos.  
  
 `try_pop`é a prova de simultaneidade em relação a chamadas para os métodos `push`, `try_pop`, e `empty`.  
  
##  <a name="unsafe_begin"></a>unsafe_begin 

 Retorna um iterador do tipo `iterator` ou `const_iterator` para o início da fila simultânea. Esse método não é uma prova de simultaneidade.  
  
```
iterator unsafe_begin();

const_iterator unsafe_begin() const;
```  
  
### <a name="return-value"></a>Valor de retorno  
 Um iterador do tipo `iterator` ou `const_iterator` para o início do objeto simultâneos na fila.  
  
### <a name="remarks"></a>Comentários  
 Os iteradores para o `concurrent_queue` classe se destinam principalmente para depuração, como eles são lentos e iteração não é segura para a simultaneidade em relação a outras operações de fila.  
  
##  <a name="unsafe_end"></a>unsafe_end 

 Retorna um iterador do tipo `iterator` ou `const_iterator` ao final da fila simultânea. Esse método não é uma prova de simultaneidade.  
  
```
iterator unsafe_end();

const_iterator unsafe_end() const;
```  
  
### <a name="return-value"></a>Valor de retorno  
 Um iterador do tipo `iterator` ou `const_iterator` ao final da fila simultânea.  
  
### <a name="remarks"></a>Comentários  
 Os iteradores para o `concurrent_queue` classe se destinam principalmente para depuração, como eles são lentos e iteração não é segura para a simultaneidade em relação a outras operações de fila.  
  
##  <a name="unsafe_size"></a>unsafe_size 

 Retorna o número de itens na fila. Esse método não é uma prova de simultaneidade.  
  
```
size_type unsafe_size() const;
```  
  
### <a name="return-value"></a>Valor de retorno  
 O tamanho da fila simultânea.  
  
### <a name="remarks"></a>Comentários  
 `unsafe_size`não é segura para a simultaneidade e pode produzir resultados incorretos se chamado simultaneamente com chamadas a métodos `push`, `try_pop`, e `empty`.  
  
## <a name="see-also"></a>Consulte também  
 [Namespace de simultaneidade](concurrency-namespace.md)

