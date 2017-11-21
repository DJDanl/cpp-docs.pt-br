---
title: Classe concurrent_queue | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology: cpp-windows
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
dev_langs: C++
helpviewer_keywords: concurrent_queue class
ms.assetid: c2218996-d0ea-40e9-b002-e9a15b085f51
caps.latest.revision: "21"
author: mikeblome
ms.author: mblome
manager: ghogen
ms.openlocfilehash: 9cb1f1618f140ad9183d50d8aaacc8e9cc59c75d
ms.sourcegitcommit: ebec1d449f2bd98aa851667c2bfeb7e27ce657b2
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/24/2017
---
# <a name="concurrentqueue-class"></a>Classe concurrent_queue
O `concurrent_queue` classe é uma classe de contêiner de sequência permite primeiro a entrar, primeiro a sair acesso para seus elementos. Ele permite que um conjunto limitado de operações com segurança de simultaneidade, como `push` e `try_pop`.  
  
## <a name="syntax"></a>Sintaxe  
  
```
template<typename T, class _Ax>
class concurrent_queue: public ::Concurrency::details::_Concurrent_queue_base_v4;
```  
  
#### <a name="parameters"></a>Parâmetros  
 `T`  
 O tipo de dados dos elementos a ser armazenado na fila.  
  
 `_Ax`  
 O tipo que representa o objeto de alocador armazenados que encapsula os detalhes sobre a alocação e desalocação de memória para essa fila simultânea. Esse argumento é opcional e o valor padrão é `allocator<T>`.  
  
## <a name="members"></a>Membros  
  
### <a name="public-typedefs"></a>Typedefs públicos  
  
|Nome|Descrição|  
|----------|-----------------|  
|`allocator_type`|Um tipo que representa a classe de alocador para a fila simultânea.|  
|`const_iterator`|Um tipo que representa um non-thread-safe `const` iterador sobre os elementos em uma fila simultânea.|  
|`const_reference`|Um tipo que fornece uma referência a um `const` elemento armazenado em uma fila simultânea para ler e executar `const` operações.|  
|`difference_type`|Um tipo que fornece a distância assinada entre dois elementos em uma fila simultânea.|  
|`iterator`|Um tipo que representa um iterador non-thread-safe sobre os elementos em uma fila simultânea.|  
|`reference`|Um tipo que fornece uma referência a um elemento armazenada em uma fila simultânea.|  
|`size_type`|Um tipo que conta o número de elementos em uma fila simultânea.|  
|`value_type`|Um tipo que representa o tipo de dados armazenado em uma fila simultânea.|  
  
### <a name="public-constructors"></a>Construtores públicos  
  
|Nome|Descrição|  
|----------|-----------------|  
|[concurrent_queue](#ctor)|Sobrecarregado. Constrói uma fila simultânea.|  
|[~ concurrent_queue destruidor](#dtor)|Destrói o simultâneos na fila.|  
  
### <a name="public-methods"></a>Métodos públicos  
  
|Nome|Descrição|  
|----------|-----------------|  
|[clear](#clear)|Limpa a fila simultânea, destruição de qualquer elementos de fila no momento. Este método não é seguro de simultaneidade.|  
|[empty](#empty)|Testa se a fila simultânea está vazia no momento em que este método é chamado. Esse método é seguro de simultaneidade.|  
|[get_allocator](#get_allocator)|Retorna uma cópia do alocador usado para construir o simultâneos na fila. Esse método é seguro de simultaneidade.|  
|[push](#push)|Sobrecarregado. Enfileira um item no final da fila simultânea. Esse método é seguro de simultaneidade.|  
|[try_pop](#try_pop)|Remove da fila um item da fila se houver um disponível. Esse método é seguro de simultaneidade.|  
|[unsafe_begin](#unsafe_begin)|Sobrecarregado. Retorna um iterador do tipo `iterator` ou `const_iterator` para o início da fila simultânea. Este método não é seguro de simultaneidade.|  
|[unsafe_end](#unsafe_end)|Sobrecarregado. Retorna um iterador do tipo `iterator` ou `const_iterator` ao final da fila simultânea. Este método não é seguro de simultaneidade.|  
|[unsafe_size](#unsafe_size)|Retorna o número de itens na fila. Este método não é seguro de simultaneidade.|  
  
## <a name="remarks"></a>Comentários  
 Para obter mais informações, consulte [objetos e contêineres paralelos](../../../parallel/concrt/parallel-containers-and-objects.md).  
  
## <a name="inheritance-hierarchy"></a>Hierarquia de herança  
 `concurrent_queue`  
  
## <a name="requirements"></a>Requisitos  
 **Cabeçalho:** concurrent_queue.h  
  
 **Namespace:** simultaneidade  
  
##  <a name="clear"></a>Limpar 

 Limpa a fila simultânea, destruição de qualquer elementos de fila no momento. Este método não é seguro de simultaneidade.  
  
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
 A fonte `concurrent_queue` objeto para copiar ou mover os elementos do.  
  
 `_Begin`  
 A posição do primeiro elemento no intervalo de elementos a ser copiado.  
  
 `_End`  
 A posição do primeiro elemento após o intervalo de elementos a ser copiado.  
  
### <a name="remarks"></a>Comentários  
 Todos os construtores armazenam um objeto de alocador `_Al` e inicializar a fila.  
  
 O primeiro construtor Especifica uma consulta inicial vazia e especifica explicitamente o tipo de alocador a ser usado.  
  
 O segundo construtor Especifica uma cópia da fila simultânea `_OtherQ`.  
  
 O terceiro construtor Especifica um movimento da fila simultânea `_OtherQ`.  
  
 O quarto construtor especifica valores fornecidos pelo intervalo iterator [ `_Begin`, `_End`).  
  
##  <a name="dtor"></a>~ concurrent_queue 

 Destrói o simultâneos na fila.  
  
```
~concurrent_queue();
```  
  
##  <a name="empty"></a>vazio 

 Testa se a fila simultânea está vazia no momento em que este método é chamado. Esse método é seguro de simultaneidade.  
  
```
bool empty() const;
```  
  
### <a name="return-value"></a>Valor de retorno  
 `true`Se a fila simultânea estava vazia no momento em que vimos, `false` caso contrário.  
  
### <a name="remarks"></a>Comentários  
 Embora esse método é seguro de simultaneidade em relação a chamadas para os métodos `push`, `try_pop`, e `empty`, o valor retornado pode estar incorreto no momento é inspecionado pelo thread de chamada.  
  
##  <a name="get_allocator"></a>get_allocator 

 Retorna uma cópia do alocador usado para construir o simultâneos na fila. Esse método é seguro de simultaneidade.  
  
```
allocator_type get_allocator() const;
```  
  
### <a name="return-value"></a>Valor de retorno  
 Uma cópia do alocador usado para construir o simultâneos na fila.  
  
##  <a name="push"></a>push 

 Enfileira um item no final da fila simultânea. Esse método é seguro de simultaneidade.  
  
```
void push(const T& _Src);

void push(T&& _Src);
```  
  
### <a name="parameters"></a>Parâmetros  
 `_Src`  
 O item a ser adicionado à fila.  
  
### <a name="remarks"></a>Comentários  
 `push`é seguro de simultaneidade em relação a chamadas para os métodos `push`, `try_pop`, e `empty`.  
  
##  <a name="try_pop"></a>try_pop 

 Remove da fila um item da fila se houver um disponível. Esse método é seguro de simultaneidade.  
  
```
bool try_pop(T& _Dest);
```  
  
### <a name="parameters"></a>Parâmetros  
 `_Dest`  
 Uma referência a um local para armazenar o item removidas da fila.  
  
### <a name="return-value"></a>Valor de retorno  
 `true`Se um item com êxito removidas da fila, `false` caso contrário.  
  
### <a name="remarks"></a>Comentários  
 Se um item com êxito removidas da fila, o parâmetro `_Dest` recebe o valor removidas da fila, o valor original mantido na fila é destruído e essa função retorna `true`. Se não havia nenhum item para remoção da fila, essa função retorna `false` sem bloqueio e o conteúdo do `_Dest` parâmetro são indefinidos.  
  
 `try_pop`é seguro de simultaneidade em relação a chamadas para os métodos `push`, `try_pop`, e `empty`.  
  
##  <a name="unsafe_begin"></a>unsafe_begin 

 Retorna um iterador do tipo `iterator` ou `const_iterator` para o início da fila simultânea. Este método não é seguro de simultaneidade.  
  
```
iterator unsafe_begin();

const_iterator unsafe_begin() const;
```  
  
### <a name="return-value"></a>Valor de retorno  
 Um iterador do tipo `iterator` ou `const_iterator` para o início do objeto simultâneos na fila.  
  
### <a name="remarks"></a>Comentários  
 Os iteradores para o `concurrent_queue` classe são principalmente para depuração, como eles estão lentos e iteração não é segura para simultaneidade em relação a outras operações de fila.  
  
##  <a name="unsafe_end"></a>unsafe_end 

 Retorna um iterador do tipo `iterator` ou `const_iterator` ao final da fila simultânea. Este método não é seguro de simultaneidade.  
  
```
iterator unsafe_end();

const_iterator unsafe_end() const;
```  
  
### <a name="return-value"></a>Valor de retorno  
 Um iterador do tipo `iterator` ou `const_iterator` ao final da fila simultânea.  
  
### <a name="remarks"></a>Comentários  
 Os iteradores para o `concurrent_queue` classe são principalmente para depuração, como eles estão lentos e iteração não é segura para simultaneidade em relação a outras operações de fila.  
  
##  <a name="unsafe_size"></a>unsafe_size 

 Retorna o número de itens na fila. Este método não é seguro de simultaneidade.  
  
```
size_type unsafe_size() const;
```  
  
### <a name="return-value"></a>Valor de retorno  
 O tamanho da fila simultânea.  
  
### <a name="remarks"></a>Comentários  
 `unsafe_size`não é seguro de simultaneidade e pode produzir resultados incorretos se chamado simultaneamente com chamadas para os métodos `push`, `try_pop`, e `empty`.  
  
## <a name="see-also"></a>Consulte também  
 [Namespace de simultaneidade](concurrency-namespace.md)
