---
title: priority_queue (STL/CLR) | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology: cpp-windows
ms.tgt_pltfrm: 
ms.topic: reference
f1_keywords: cliext::priority_queue
dev_langs: C++
helpviewer_keywords:
- priority_queue class [STL/CLR]
- <queue> header [STL/CLR]
- <cliext/queue> header [STL/CLR]
ms.assetid: 4d0000d3-68ff-4c4b-8157-7060540136f5
caps.latest.revision: "16"
author: mikeblome
ms.author: mblome
manager: ghogen
ms.workload:
- cplusplus
- dotnet
ms.openlocfilehash: b7d1459da07f7e392a2da1fbf5d6e9d72c8f4653
ms.sourcegitcommit: 8fa8fdf0fbb4f57950f1e8f4f9b81b4d39ec7d7a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/21/2017
---
# <a name="priorityqueue-stlclr"></a>priority_queue (STL/CLR)
A classe de modelo descreve um objeto que controla um comprimento variável ordenados de sequência de elementos com acesso limitado. Usar o adaptador de contêiner `priority_queue` para gerenciar um contêiner subjacente como uma fila de prioridade.  
  
 Na descrição abaixo, `GValue` é o mesmo que `Value` , a menos que o último é um tipo de referência, caso em que é `Value^`. Da mesma forma, `GContainer` é o mesmo que `Container` , a menos que o último é um tipo de referência, caso em que é `Container^`.  
  
## <a name="syntax"></a>Sintaxe  
  
```  
template<typename Value,  
    typename Container>  
    ref class priority_queue  
        System::ICloneable,  
        Microsoft::VisualC::StlClr::IPriorityQueue<GValue, GContainer>  
    { ..... };  
```  
  
#### <a name="parameters"></a>Parâmetros  
 Valor  
 O tipo de um elemento na sequência controlada.  
  
 Contêiner  
 O tipo do contêiner subjacente.  
  
## <a name="members"></a>Membros  
  
|Definição do tipo|Descrição|  
|---------------------|-----------------|  
|[priority_queue::const_reference (STL/CLR)](../dotnet/priority-queue-const-reference-stl-clr.md)|O tipo de uma referência de constante para um elemento.|  
|[priority_queue::container_type (STL/CLR)](../dotnet/priority-queue-container-type-stl-clr.md)|O tipo do contêiner subjacente.|  
|[priority_queue::difference_type (STL/CLR)](../dotnet/priority-queue-difference-type-stl-clr.md)|O tipo de uma distância com sinal entre dois elementos.|  
|[priority_queue::generic_container (STL/CLR)](../dotnet/priority-queue-generic-container-stl-clr.md)|O tipo da interface genérica para o adaptador de contêiner.|  
|[priority_queue::generic_value (STL/CLR)](../dotnet/priority-queue-generic-value-stl-clr.md)|O tipo de um elemento para a interface genérica para o adaptador de contêiner.|  
|[priority_queue::reference (STL/CLR)](../dotnet/priority-queue-reference-stl-clr.md)|O tipo de uma referência para um elemento.|  
|[priority_queue::size_type (STL/CLR)](../dotnet/priority-queue-size-type-stl-clr.md)|O tipo de uma distância com sinal entre dois elementos.|  
|[priority_queue::value_compare (STL/CLR)](../dotnet/priority-queue-value-compare-stl-clr.md)|O representante de ordenação para dois elementos.|  
|[priority_queue::value_type (STL/CLR)](../dotnet/priority-queue-value-type-stl-clr.md)|O tipo de um elemento.|  
  
|Função membro|Descrição|  
|---------------------|-----------------|  
|[priority_queue::assign (STL/CLR)](../dotnet/priority-queue-assign-stl-clr.md)|Substitui todos os elementos.|  
|[priority_queue::empty (STL/CLR)](../dotnet/priority-queue-empty-stl-clr.md)|Testa se nenhum elemento está presente.|  
|[priority_queue::get_container (STL/CLR)](../dotnet/priority-queue-get-container-stl-clr.md)|Acessa o contêiner subjacente.|  
|[priority_queue::pop (STL/CLR)](../dotnet/priority-queue-pop-stl-clr.md)|Remove o elemento hghest prioridade.|  
|[priority_queue::priority_queue (STL/CLR)](../dotnet/priority-queue-priority-queue-stl-clr.md)|Constrói um objeto contêiner.|  
|[priority_queue::push (STL/CLR)](../dotnet/priority-queue-push-stl-clr.md)|Adiciona um novo elemento.|  
|[priority_queue::size (STL/CLR)](../dotnet/priority-queue-size-stl-clr.md)|Conta o número de elementos.|  
|[priority_queue::top (STL/CLR)](../dotnet/priority-queue-top-stl-clr.md)|Acessa o elemento de prioridade mais alta.|  
|[priority_queue::to_array (STL/CLR)](../dotnet/priority-queue-to-array-stl-clr.md)|Copia uma nova matriz sequência controlada.|  
|[priority_queue::value_comp (STL/CLR)](../dotnet/priority-queue-value-comp-stl-clr.md)|Copia o delegado de ordenação para dois elementos.|  
  
|Propriedade|Descrição|  
|--------------|-----------------|  
|[priority_queue::top_item (STL/CLR)](../dotnet/priority-queue-top-item-stl-clr.md)|Acessa o elemento de prioridade mais alta.|  
  
|Operador|Descrição|  
|--------------|-----------------|  
|[priority_queue::operator= (STL/CLR)](../dotnet/priority-queue-operator-assign-stl-clr.md)|Substitui a sequência controlada.|  
  
## <a name="interfaces"></a>Interfaces  
  
|Interface|Descrição|  
|---------------|-----------------|  
|<xref:System.ICloneable>|Duplicar um objeto.|  
|IPriorityQueue\<valor, o contêiner >|Manter o adaptador de contêiner genérico.|  
  
## <a name="remarks"></a>Comentários  
 O objeto aloca e libera o armazenamento para a sequência controla por meio de um contêiner subjacente, do tipo `Container`, que armazena `Value` elementos e sob demanda. Isso mantém a sequência ordenada como um heap, com o elemento de prioridade mais alta (o elemento superior) prontamente acessível e removível. O objeto restringe o acesso a novos elementos de envio por push e exibir apenas o elemento de prioridade mais alta, a implementação de uma fila de prioridade.  
  
 O objeto classifica a sequência controla chamando um objeto de representante armazenado do tipo [priority_queue::value_compare (STL/CLR)](../dotnet/priority-queue-value-compare-stl-clr.md). Você pode especificar o objeto do representante armazenado quando você construir o priority_queue; Se você não especificar nenhum objeto do representante, o padrão é a comparação `operator<(value_type, value_type)`. Acessar esse objeto armazenado chamando a função de membro [priority_queue::value_comp (STL/CLR)](../dotnet/priority-queue-value-comp-stl-clr.md)`()`.  
  
 Esse é um objeto de representante deve impor uma ordenação fraca estrita em valores de tipo [priority_queue:: value_type (STL/CLR)](../dotnet/priority-queue-value-type-stl-clr.md). Isso significa que, para qualquer duas chaves `X` e `Y`:  
  
 `value_comp()(X, Y)`Retorna o mesmo Boolean resultar em cada chamada.  
  
 Se `value_comp()(X, Y)` for true, então `value_comp()(Y, X)` deve ser false.  
  
 Se `value_comp()(X, Y)` for true, em seguida, `X` deve ser ordenados antes `Y`.  
  
 Se `!value_comp()(X, Y) && !value_comp()(Y, X)` for true, em seguida, `X` e `Y` são deve ter ordenação equivalente.  
  
 Para qualquer elemento `X` que precede `Y` na sequência controlada, `key_comp()(Y, X)` é false. (Para o objeto do representante padrão, as chaves nunca diminuir em valor.)  
  
 O elemento de prioridade mais alto, portanto, é um dos elementos que não for ordenado antes de qualquer outro elemento.  
  
 Desde que o contêiner subjacente mantém ordenados como uma pilha de elementos:  
  
 O contêiner deve oferecer suporte a acesso aleatório iteradores.  
  
 Elementos com a ordenação equivalente podem ser exibidos em uma ordem diferente, que foram colocados. (A ordem não é estável.)  
  
 Portanto, os candidatos para o contêiner subjacente incluem [deque (STL/CLR)](../dotnet/deque-stl-clr.md) e [vetor (STL/CLR)](../dotnet/vector-stl-clr.md).  
  
## <a name="requirements"></a>Requisitos  
 **Cabeçalho:** \<cliext/fila >  
  
 **Namespace:** cliext  
  
## <a name="see-also"></a>Consulte também  
 [deque (STL/CLR)](../dotnet/deque-stl-clr.md)   
 [fila (STL/CLR)](../dotnet/queue-stl-clr.md)   
 [pilha (STL/CLR)](../dotnet/stack-stl-clr.md)   
 [vetor (STL/CLR)](../dotnet/vector-stl-clr.md)   
 [Referência de biblioteca STL/CLR](../dotnet/stl-clr-library-reference.md)