---
title: pilha (STL/CLR) | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology: cpp-windows
ms.tgt_pltfrm: 
ms.topic: reference
f1_keywords: cliext::stack
dev_langs: C++
helpviewer_keywords:
- <stack> header [STL/CLR]
- <cliext/stack> header [STL/CLR]
- stack class [STL/CLR]
ms.assetid: 6ee96b9f-8a33-4cf7-b7e0-6535c24bdefb
caps.latest.revision: "14"
author: mikeblome
ms.author: mblome
manager: ghogen
ms.workload:
- cplusplus
- dotnet
ms.openlocfilehash: c7f6d9eac97fa1907a0901c725645f29dcdd5d9e
ms.sourcegitcommit: 8fa8fdf0fbb4f57950f1e8f4f9b81b4d39ec7d7a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/21/2017
---
# <a name="stack-stlclr"></a>stack (STL/CLR)
A classe de modelo descreve um objeto que controla uma sequência de comprimento variável de elementos que tem acesso no último primeiro a sair. Usar o adaptador de contêiner `stack` para gerenciar um contêiner subjacente como uma pilha de rebaixamento.  
  
 Na descrição abaixo, `GValue` é o mesmo que `Value` , a menos que o último é um tipo de referência, caso em que é `Value^`. Da mesma forma, `GContainer` é o mesmo que `Container` , a menos que o último é um tipo de referência, caso em que é `Container^`.  
  
## <a name="syntax"></a>Sintaxe  
  
```  
template<typename Value,  
    typename Container>  
    ref class stack  
        :   public  
        System::ICloneable,  
        Microsoft::VisualC::StlClr::IStack<GValue, GContainer>  
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
|[stack::const_reference (STL/CLR)](../dotnet/stack-const-reference-stl-clr.md)|O tipo de uma referência de constante para um elemento.|  
|[stack::container_type (STL/CLR)](../dotnet/stack-container-type-stl-clr.md)|O tipo do contêiner subjacente.|  
|[stack::difference_type (STL/CLR)](../dotnet/stack-difference-type-stl-clr.md)|O tipo de uma distância com sinal entre dois elementos.|  
|[stack::generic_container (STL/CLR)](../dotnet/stack-generic-container-stl-clr.md)|O tipo da interface genérica para o adaptador de contêiner.|  
|[stack::generic_value (STL/CLR)](../dotnet/stack-generic-value-stl-clr.md)|O tipo de um elemento para a interface genérica para o adaptador de contêiner.|  
|[stack::reference (STL/CLR)](../dotnet/stack-reference-stl-clr.md)|O tipo de uma referência para um elemento.|  
|[stack::size_type (STL/CLR)](../dotnet/stack-size-type-stl-clr.md)|O tipo de uma distância com sinal entre dois elementos.|  
|[stack::value_type (STL/CLR)](../dotnet/stack-value-type-stl-clr.md)|O tipo de um elemento.|  
  
|Função membro|Descrição|  
|---------------------|-----------------|  
|[stack::assign (STL/CLR)](../dotnet/stack-assign-stl-clr.md)|Substitui todos os elementos.|  
|[stack::empty (STL/CLR)](../dotnet/stack-empty-stl-clr.md)|Testa se nenhum elemento está presente.|  
|[stack::get_container (STL/CLR)](../dotnet/stack-get-container-stl-clr.md)|Acessa o contêiner subjacente.|  
|[stack::pop (STL/CLR)](../dotnet/stack-pop-stl-clr.md)|Remove o último elemento.|  
|[stack::push (STL/CLR)](../dotnet/stack-push-stl-clr.md)|Adiciona um novo elemento de última.|  
|[stack::size (STL/CLR)](../dotnet/stack-size-stl-clr.md)|Conta o número de elementos.|  
|[stack::stack (STL/CLR)](../dotnet/stack-stack-stl-clr.md)|Constrói um objeto contêiner.|  
|[stack::top (STL/CLR)](../dotnet/stack-top-stl-clr.md)|Acessa o último elemento.|  
|[stack::to_array (STL/CLR)](../dotnet/stack-to-array-stl-clr.md)|Copia uma nova matriz sequência controlada.|  
  
|Propriedade|Descrição|  
|--------------|-----------------|  
|[stack::top_item (STL/CLR)](../dotnet/stack-top-item-stl-clr.md)|Acessa o último elemento.|  
  
|Operador|Descrição|  
|--------------|-----------------|  
|[stack::operator= (STL/CLR)](../dotnet/stack-operator-assign-stl-clr.md)|Substitui a sequência controlada.|  
|[operator!= (stack) (STL/CLR)](../dotnet/operator-inequality-stack-stl-clr.md)|Determina se um `stack` objeto não é igual a outro `stack` objeto.|  
|[operator< (stack) (STL/CLR)](../dotnet/operator-less-than-stack-stl-clr.md)|Determina se um `stack` objeto é menor que outro `stack` objeto.|  
|[operator<= (stack) (STL/CLR)](../dotnet/operator-less-or-equal-stack-stl-clr.md)|Determina se um `stack` objeto é menor ou igual a outro `stack` objeto.|  
|[operator== (stack) (STL/CLR)](../dotnet/operator-equality-stack-stl-clr.md)|Determina se um `stack` objeto é igual a outro `stack` objeto.|  
|[operator> (stack) (STL/CLR)](../dotnet/operator-greater-than-stack-stl-clr.md)|Determina se um `stack` objeto é maior que outro `stack` objeto.|  
|[operator>= (stack) (STL/CLR)](../dotnet/operator-greater-or-equal-stack-stl-clr.md)|Determina se um `stack` objeto é maior que ou igual a outro `stack` objeto.|  
  
## <a name="interfaces"></a>Interfaces  
  
|Interface|Descrição|  
|---------------|-----------------|  
|<xref:System.ICloneable>|Duplicar um objeto.|  
|IStack\<valor, o contêiner >|Manter o adaptador de contêiner genérico.|  
  
## <a name="remarks"></a>Comentários  
 O objeto aloca e libera o armazenamento para a sequência controla por meio de um contêiner subjacente, do tipo `Container`, que armazena `Value` elementos e sob demanda. O objeto restringe o acesso para enviar por push e exibir apenas o último elemento, a implementação de uma fila no último primeiro a sair (também conhecido como uma fila de UEPS ou pilha).  
  
## <a name="requirements"></a>Requisitos  
 **Cabeçalho:** \<cliext/pilha >  
  
 **Namespace:** cliext  
  
## <a name="see-also"></a>Consulte também  
 [deque (STL/CLR)](../dotnet/deque-stl-clr.md)   
 [lista (STL/CLR)](../dotnet/list-stl-clr.md)   
 [priority_queue (STL/CLR)](../dotnet/priority-queue-stl-clr.md)   
 [fila (STL/CLR)](../dotnet/queue-stl-clr.md)   
 [vetor (STL/CLR)](../dotnet/vector-stl-clr.md)   
 [Referência de biblioteca STL/CLR](../dotnet/stl-clr-library-reference.md)