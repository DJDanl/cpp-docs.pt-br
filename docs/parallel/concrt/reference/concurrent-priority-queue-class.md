---
title: Classe concurrent_priority_queue | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology: cpp-windows
ms.tgt_pltfrm: 
ms.topic: article
f1_keywords:
- concurrent_priority_queue
- CONCURRENT_PRIORITY_QUEUE/concurrency::concurrent_priority_queue
- CONCURRENT_PRIORITY_QUEUE/concurrency::concurrent_priority_queue::concurrent_priority_queue
- CONCURRENT_PRIORITY_QUEUE/concurrency::concurrent_priority_queue::clear
- CONCURRENT_PRIORITY_QUEUE/concurrency::concurrent_priority_queue::empty
- CONCURRENT_PRIORITY_QUEUE/concurrency::concurrent_priority_queue::get_allocator
- CONCURRENT_PRIORITY_QUEUE/concurrency::concurrent_priority_queue::push
- CONCURRENT_PRIORITY_QUEUE/concurrency::concurrent_priority_queue::size
- CONCURRENT_PRIORITY_QUEUE/concurrency::concurrent_priority_queue::swap
- CONCURRENT_PRIORITY_QUEUE/concurrency::concurrent_priority_queue::try_pop
dev_langs: C++
helpviewer_keywords: concurrent_priority_queue class
ms.assetid: 3e740381-0f4e-41fc-8b66-ad0bb55f17a3
caps.latest.revision: "9"
author: mikeblome
ms.author: mblome
manager: ghogen
ms.workload: cplusplus
ms.openlocfilehash: 1796351dc594712ef69ec5562f85501b30997104
ms.sourcegitcommit: 8fa8fdf0fbb4f57950f1e8f4f9b81b4d39ec7d7a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/21/2017
---
# <a name="concurrentpriorityqueue-class"></a>Classe concurrent_priority_queue
O `concurrent_priority_queue` classe é um contêiner que permite que vários threads para itens simultaneamente por push e pop. Itens são disparados em ordem de prioridade, onde a prioridade é determinada por um functor fornecido como um argumento de modelo.  
  
## <a name="syntax"></a>Sintaxe  
  
```
template <typename T,
    typename _Compare= std::less<T>,
    typename _Ax = std::allocator<T>
>,
    typename _Ax = std::allocator<T>> class concurrent_priority_queue;
```  
  
#### <a name="parameters"></a>Parâmetros  
 `T`  
 O tipo de dados dos elementos a ser armazenada na fila de prioridade.  
  
 `_Compare`  
 O tipo do objeto de função que pode comparar dois valores de elemento como chaves de classificação para determinar sua ordem relativa na fila de prioridade. Esse argumento é opcional e o predicado binário `less<T>` é o valor padrão.  
  
 `_Ax`  
 O tipo que representa o objeto de alocador armazenados que encapsula os detalhes sobre a alocação e desalocação de memória para a fila de prioridade simultâneas. Esse argumento é opcional e o valor padrão é `allocator<T>`.  
  
## <a name="members"></a>Membros  
  
### <a name="public-typedefs"></a>Typedefs públicos  
  
|Nome|Descrição|  
|----------|-----------------|  
|`allocator_type`|Um tipo que representa a classe de alocador para a fila de prioridade simultâneas.|  
|`const_reference`|Um tipo que representa uma constante fazem referência a um elemento do tipo armazenado em uma fila de prioridade simultâneas.|  
|`reference`|Um tipo que representa uma referência a um elemento do tipo armazenado em uma fila de prioridade simultâneas.|  
|`size_type`|Um tipo que conta o número de elementos em uma fila de prioridade simultâneas.|  
|`value_type`|Um tipo que representa o tipo de dados armazenado em uma fila de prioridade simultâneas.|  
  
### <a name="public-constructors"></a>Construtores públicos  
  
|Nome|Descrição|  
|----------|-----------------|  
|[concurrent_priority_queue](#ctor)|Sobrecarregado. Constrói uma fila de prioridade simultâneas.|  
  
### <a name="public-methods"></a>Métodos públicos  
  
|Nome|Descrição|  
|----------|-----------------|  
|[clear](#clear)|Apaga todos os elementos na prioridade de simultâneas. Este método não é seguro de simultaneidade.|  
|[empty](#empty)|Testa se a fila de prioridade simultâneas está vazia no momento em que este método é chamado. Esse método é seguro de simultaneidade.|  
|[get_allocator](#get_allocator)|Retorna uma cópia do alocador usado para construir a fila de prioridade simultâneas. Esse método é seguro de simultaneidade.|  
|[push](#push)|Sobrecarregado. Adiciona um elemento para a fila de prioridade simultâneas. Esse método é seguro de simultaneidade.|  
|[size](#size)|Retorna o número de elementos na fila de prioridade simultâneas. Esse método é seguro de simultaneidade.|  
|[swap](#swap)|Alterna o conteúdo de duas filas simultâneas de prioridade. Este método não é seguro de simultaneidade.|  
|[try_pop](#try_pop)|Remove e retorna o elemento mais alto de prioridade da fila se a fila não está vazio. Esse método é seguro de simultaneidade.|  
  
### <a name="public-operators"></a>Operadores públicos  
  
|Nome|Descrição|  
|----------|-----------------|  
|[operator=](#operator_eq)|Sobrecarregado. Atribui o conteúdo de outro `concurrent_priority_queue` deste objeto. Este método não é seguro de simultaneidade.|  
  
## <a name="remarks"></a>Comentários  
 Para obter informações detalhadas sobre o `concurrent_priority_queue` de classe, consulte [objetos e contêineres paralelos](../../../parallel/concrt/parallel-containers-and-objects.md).  
  
## <a name="inheritance-hierarchy"></a>Hierarquia de herança  
 `concurrent_priority_queue`  
  
## <a name="requirements"></a>Requisitos  
 **Cabeçalho:** concurrent_priority_queue.h  
  
 **Namespace:** simultaneidade  
  
##  <a name="clear"></a>Limpar 

 Apaga todos os elementos na prioridade de simultâneas. Este método não é seguro de simultaneidade.  
  
```
void clear();
```  
  
### <a name="remarks"></a>Comentários  
 `clear`não é seguro de simultaneidade. Certifique-se de que nenhum outro thread está chamando métodos na fila de prioridade simultâneas quando você chamar esse método. `clear`não liberar memória.  
  
##  <a name="ctor"></a>concurrent_priority_queue 

 Constrói uma fila de prioridade simultâneas.  
  
```
explicit concurrent_priority_queue(
    const allocator_type& _Al = allocator_type());

explicit concurrent_priority_queue(
    size_type _Init_capacity,
    const allocator_type& _Al = allocator_type());

template<typename _InputIterator>
concurrent_priority_queue(_InputIterator _Begin,
    _InputIterator _End,
    const allocator_type& _Al = allocator_type());

concurrent_priority_queue(
    const concurrent_priority_queue& _Src);

concurrent_priority_queue(
    const concurrent_priority_queue& _Src,
    const allocator_type& _Al);

concurrent_priority_queue(
    concurrent_priority_queue&& _Src);

concurrent_priority_queue(
    concurrent_priority_queue&& _Src,
    const allocator_type& _Al);
```  
  
### <a name="parameters"></a>Parâmetros  
 `_InputIterator`  
 O tipo do iterador de entrada.  
  
 `_Al`  
 A classe de alocador a ser usada com esse objeto.  
  
 `_Init_capacity`  
 A capacidade inicial igual a `concurrent_priority_queue` objeto.  
  
 `_Begin`  
 A posição do primeiro elemento no intervalo de elementos a serem copiados.  
  
 `_End`  
 A posição do primeiro elemento além do intervalo de elementos a serem copiados.  
  
 `_Src`  
 A fonte `concurrent_priority_queue` objeto para copiar ou mover os elementos do.  
  
### <a name="remarks"></a>Comentários  
 Todos os construtores armazenam um objeto de alocador `_Al` e inicializar a fila de prioridade.  
  
 O primeiro construtor Especifica uma fila de prioridade inicial vazio e, opcionalmente, especifica um alocador.  
  
 O segundo construtor Especifica uma fila de prioridade com uma capacidade inicial `_Init_capacity` e, opcionalmente, especifica um alocador.  
  
 O terceiro construtor especifica valores fornecidos pelo intervalo iterator [ `_Begin`, `_End`) e, opcionalmente, especifica um alocador.  
  
 Os quarto e quinto construtores especificar uma cópia da fila de prioridade `_Src`.  
  
 Os sexto e o sétimo construtores especificam um movimento da fila de prioridade `_Src`.  
  
##  <a name="empty"></a>vazio 

 Testa se a fila de prioridade simultâneas está vazia no momento em que este método é chamado. Esse método é seguro de simultaneidade.  
  
```
bool empty() const;
```  
  
### <a name="return-value"></a>Valor de retorno  
 `true`Se a fila de prioridade estava vazia no momento em que a função foi chamada, `false` caso contrário.  
  
##  <a name="get_allocator"></a>get_allocator 

 Retorna uma cópia do alocador usado para construir a fila de prioridade simultâneas. Esse método é seguro de simultaneidade.  
  
```
allocator_type get_allocator() const;
```  
  
### <a name="return-value"></a>Valor de retorno  
 Uma cópia do alocador usado para construir o `concurrent_priority_queue` objeto.  
  
##  <a name="operator_eq"></a>operador = 

 Atribui o conteúdo de outro `concurrent_priority_queue` deste objeto. Este método não é seguro de simultaneidade.  
  
```
concurrent_priority_queue& operator= (const concurrent_priority_queue& _Src);

concurrent_priority_queue& operator= (concurrent_priority_queue&& _Src);
```  
  
### <a name="parameters"></a>Parâmetros  
 `_Src`  
 A fonte `concurrent_priority_queue` objeto.  
  
### <a name="return-value"></a>Valor de retorno  
 Uma referência a este `concurrent_priority_queue` objeto.  
  
##  <a name="push"></a>push 

 Adiciona um elemento para a fila de prioridade simultâneas. Esse método é seguro de simultaneidade.  
  
```
void push(const value_type& _Elem);

void push(value_type&& _Elem);
```  
  
### <a name="parameters"></a>Parâmetros  
 `_Elem`  
 O elemento a ser adicionado à fila de prioridade simultâneas.  
  
##  <a name="size"></a>tamanho 

 Retorna o número de elementos na fila de prioridade simultâneas. Esse método é seguro de simultaneidade.  
  
```
size_type size() const;
```  
  
### <a name="return-value"></a>Valor de retorno  
 O número de elementos nesta `concurrent_priority_queue` objeto.  
  
### <a name="remarks"></a>Comentários  
 O tamanho retornado é garantido para incluir todos os elementos adicionados por chamadas para a função `push`. No entanto, ele pode não refletir resultados de operações simultâneas pendentes.  
  
##  <a name="swap"></a>swap 

 Alterna o conteúdo de duas filas simultâneas de prioridade. Este método não é seguro de simultaneidade.  
  
```
void swap(concurrent_priority_queue& _Queue);
```  
  
### <a name="parameters"></a>Parâmetros  
 `_Queue`  
 O objeto `concurrent_priority_queue` com o qual trocar conteúdo.  
  
##  <a name="try_pop"></a>try_pop 

 Remove e retorna o elemento mais alto de prioridade da fila se a fila não está vazio. Esse método é seguro de simultaneidade.  
  
```
bool try_pop(reference _Elem);
```  
  
### <a name="parameters"></a>Parâmetros  
 `_Elem`  
 Uma referência a uma variável que será preenchida com o elemento de prioridade mais alto, se a fila não está vazio.  
  
### <a name="return-value"></a>Valor de retorno  
 `true`Se um valor foi exibido, `false` caso contrário.  
  
## <a name="see-also"></a>Consulte também  
 [Namespace de simultaneidade](concurrency-namespace.md)   
 [Contêineres e objetos em paralelo](../../../parallel/concrt/parallel-containers-and-objects.md)



