---
title: fila (STL/CLR) | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.reviewer: ''
ms.suite: ''
ms.technology:
- cpp-windows
ms.tgt_pltfrm: ''
ms.topic: reference
f1_keywords:
- cliext::queue
dev_langs:
- C++
helpviewer_keywords:
- <queue> header [STL/CLR]
- queue class [STL/CLR]
- <cliext/queue> header [STL/CLR]
ms.assetid: 9ea7dec3-ea98-48ff-87d0-a5afc924aaf2
caps.latest.revision: 18
author: mikeblome
ms.author: mblome
manager: ghogen
ms.workload:
- cplusplus
- dotnet
ms.openlocfilehash: d5b91a2556a93f3cd74a24ea57306d70f2cbdb41
ms.sourcegitcommit: 8fa8fdf0fbb4f57950f1e8f4f9b81b4d39ec7d7a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/21/2017
---
# <a name="queue-stlclr"></a>queue (STL/CLR)
A classe de modelo descreve um objeto que controla uma sequência de comprimento variável de elementos que tenha acesso primeiro na fila. Usar o adaptador de contêiner `queue` para gerenciar um contêiner subjacente como uma fila.  
  
 Na descrição abaixo, `GValue` é o mesmo que `Value` , a menos que o último é um tipo de referência, caso em que é `Value^`. Da mesma forma, `GContainer` é o mesmo que `Container` , a menos que o último é um tipo de referência, caso em que é `Container^`.  
  
## <a name="syntax"></a>Sintaxe  
  
```  
template<typename Value,  
    typename Container>  
    ref class queue  
        :   public  
        System::ICloneable,  
        Microsoft::VisualC::StlClr::IQueue<GValue, GContainer>  
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
|[queue::const_reference (STL/CLR)](../dotnet/queue-const-reference-stl-clr.md)|O tipo de uma referência de constante para um elemento.|  
|[queue::container_type (STL/CLR)](../dotnet/queue-container-type-stl-clr.md)|O tipo do contêiner subjacente.|  
|[queue::difference_type (STL/CLR)](../dotnet/queue-difference-type-stl-clr.md)|O tipo de uma distância com sinal entre dois elementos.|  
|[queue::generic_container (STL/CLR)](../dotnet/queue-generic-container-stl-clr.md)|O tipo da interface genérica para o adaptador de contêiner.|  
|[queue::generic_value (STL/CLR)](../dotnet/queue-generic-value-stl-clr.md)|O tipo de um elemento para a interface genérica para o adaptador de contêiner.|  
|[queue::reference (STL/CLR)](../dotnet/queue-reference-stl-clr.md)|O tipo de uma referência para um elemento.|  
|[queue::size_type (STL/CLR)](../dotnet/queue-size-type-stl-clr.md)|O tipo de uma distância com sinal entre dois elementos.|  
|[queue::value_type (STL/CLR)](../dotnet/queue-value-type-stl-clr.md)|O tipo de um elemento.|  
  
|Função membro|Descrição|  
|---------------------|-----------------|  
|[queue::assign (STL/CLR)](../dotnet/queue-assign-stl-clr.md)|Substitui todos os elementos.|  
|[queue::back (STL/CLR)](../dotnet/queue-back-stl-clr.md)|Acessa o último elemento.|  
|[queue::empty (STL/CLR)](../dotnet/queue-empty-stl-clr.md)|Testa se nenhum elemento está presente.|  
|[queue::front (STL/CLR)](../dotnet/queue-front-stl-clr.md)|Acessa o primeiro elemento.|  
|[queue::get_container (STL/CLR)](../dotnet/queue-get-container-stl-clr.md)|Acessa o contêiner subjacente.|  
|[queue::pop (STL/CLR)](../dotnet/queue-pop-stl-clr.md)|Remove o primeiro elemento.|  
|[queue::push (STL/CLR)](../dotnet/queue-push-stl-clr.md)|Adiciona um novo elemento de última.|  
|[queue::queue (STL/CLR)](../dotnet/queue-queue-stl-clr.md)|Constrói um objeto contêiner.|  
|[queue::size (STL/CLR)](../dotnet/queue-size-stl-clr.md)|Conta o número de elementos.|  
|[queue::to_array (STL/CLR)](../dotnet/queue-to-array-stl-clr.md)|Copia uma nova matriz sequência controlada.|  
  
|Propriedade|Descrição|  
|--------------|-----------------|  
|[queue::back_item (STL/CLR)](../dotnet/queue-back-item-stl-clr.md)|Acessa o último elemento.|  
|[queue::front_item (STL/CLR)](../dotnet/queue-front-item-stl-clr.md)|Acessa o primeiro elemento.|  
  
|Operador|Descrição|  
|--------------|-----------------|  
|[queue::operator= (STL/CLR)](../dotnet/queue-operator-assign-stl-clr.md)|Substitui a sequência controlada.|  
|[operator!= (queue) (STL/CLR)](../dotnet/operator-inequality-queue-stl-clr.md)|Determina se um `queue` objeto não é igual a outro `queue` objeto.|  
|[operator< (queue) (STL/CLR)](../dotnet/operator-less-than-queue-stl-clr.md)|Determina se um `queue` objeto é menor que outro `queue` objeto.|  
|[operator<= (queue) (STL/CLR)](../dotnet/operator-less-or-equal-queue-stl-clr.md)|Determina se um `queue` objeto é menor ou igual a outro `queue` objeto.|  
|[operator== (queue) (STL/CLR)](../dotnet/operator-equality-queue-stl-clr.md)|Determina se um `queue` objeto é igual a outro `queue` objeto.|  
|[operator> (queue) (STL/CLR)](../dotnet/operator-greater-than-queue-stl-clr.md)|Determina se um `queue` objeto é maior que outro `queue` objeto.|  
|[operator>= (queue) (STL/CLR)](../dotnet/operator-greater-or-equal-queue-stl-clr.md)|Determina se um `queue` objeto é maior que ou igual a outro `queue` objeto.|  
  
## <a name="interfaces"></a>Interfaces  
  
|Interface|Descrição|  
|---------------|-----------------|  
|<xref:System.ICloneable>|Duplicar um objeto.|  
|IFila\<valor, o contêiner >|Manter o adaptador de contêiner genérico.|  
  
## <a name="remarks"></a>Comentários  
 O objeto aloca e libera o armazenamento para a sequência controla por meio de um contêiner subjacente, do tipo `Container`, que armazena `Value` elementos e sob demanda. O objeto restringe o acesso ao enviar apenas o primeiro elemento e retirar o último elemento, implementando uma primeiro a sair na primeira fila (também conhecido como uma fila FIFO, ou simplesmente uma fila).  
  
## <a name="requirements"></a>Requisitos  
 **Cabeçalho:** \<cliext/fila >  
  
 **Namespace:** cliext  
  
## <a name="see-also"></a>Consulte também  
 [deque (STL/CLR)](../dotnet/deque-stl-clr.md)   
 [lista (STL/CLR)](../dotnet/list-stl-clr.md)   
 [priority_queue (STL/CLR)](../dotnet/priority-queue-stl-clr.md)   
 [pilha (STL/CLR)](../dotnet/stack-stl-clr.md)   
 [vetor (STL/CLR)](../dotnet/vector-stl-clr.md)   
 [Referência de biblioteca STL/CLR](../dotnet/stl-clr-library-reference.md)