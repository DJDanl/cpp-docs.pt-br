---
title: vetor (STL/CLR) | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- cpp-windows
ms.tgt_pltfrm: 
ms.topic: reference
f1_keywords:
- cliext::vector
dev_langs:
- C++
helpviewer_keywords:
- vector class [STL/CLR]
- <cliext/vector> header [STL/CLR]
- <vector> header [STL/CLR]
ms.assetid: f90060d5-097a-4e9d-9a26-a634b5b9c6c2
caps.latest.revision: 
author: mikeblome
ms.author: mblome
manager: ghogen
ms.workload:
- cplusplus
- dotnet
ms.openlocfilehash: bbbded2cb679d1f55949095cae3508d658e020c5
ms.sourcegitcommit: 8fa8fdf0fbb4f57950f1e8f4f9b81b4d39ec7d7a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/21/2017
---
# <a name="vector-stlclr"></a>vector (STL/CLR)
A classe de modelo descreve um objeto que controla uma sequência de comprimento variável de elementos que tenha acesso aleatório. Você usa o contêiner `vector` para gerenciar uma sequência de elementos como um bloco contínuo de armazenamento. O bloco é implementado como uma matriz que cresce sob demanda.  
  
 Na descrição abaixo, `GValue` é o mesmo que `Value` , a menos que o último é um tipo de referência, caso em que é `Value^`.  
  
## <a name="syntax"></a>Sintaxe  
  
```  
template<typename Value>  
    ref class vector  
        :   public  
        System::ICloneable,  
        System::Collections::IEnumerable,  
        System::Collections::ICollection,  
        System::Collections::Generic::IEnumerable<GValue>,  
        System::Collections::Generic::ICollection<GValue>,  
        System::Collections::Generic::IList<GValue>,  
        Microsoft::VisualC::StlClr::IVector<GValue>  
    { ..... };  
```  
  
#### <a name="parameters"></a>Parâmetros  
 Valor  
 O tipo de um elemento na sequência controlada.  
  
## <a name="members"></a>Membros  
  
|Definição do tipo|Descrição|  
|---------------------|-----------------|  
|[vector::const_iterator (STL/CLR)](../dotnet/vector-const-iterator-stl-clr.md)|O tipo de um iterador de constante para a sequência controlada.|  
|[vector::const_reference (STL/CLR)](../dotnet/vector-const-reference-stl-clr.md)|O tipo de uma referência de constante para um elemento.|  
|[vector::const_reverse_iterator (STL/CLR)](../dotnet/vector-const-reverse-iterator-stl-clr.md)|O tipo de um iterador reverso de constante para a sequência controlada.|  
|[vector::difference_type (STL/CLR)](../dotnet/vector-difference-type-stl-clr.md)|O tipo de uma distância com sinal entre dois elementos.|  
|[vector::generic_container (STL/CLR)](../dotnet/vector-generic-container-stl-clr.md)|O tipo da interface genérica para o contêiner.|  
|[vector::generic_iterator (STL/CLR)](../dotnet/vector-generic-iterator-stl-clr.md)|O tipo de um iterador para a interface genérica para o contêiner.|  
|[vector::generic_reverse_iterator (STL/CLR)](../dotnet/vector-generic-reverse-iterator-stl-clr.md)|O tipo de um iterador inverso para a interface genérica para o contêiner.|  
|[vector::generic_value (STL/CLR)](../dotnet/vector-generic-value-stl-clr.md)|O tipo de um elemento para a interface genérica para o contêiner.|  
|[vector::iterator (STL/CLR)](../dotnet/vector-iterator-stl-clr.md)|O tipo de um iterador para a sequência controlada.|  
|[vector::reference (STL/CLR)](../dotnet/vector-reference-stl-clr.md)|O tipo de uma referência para um elemento.|  
|[vector::reverse_iterator (STL/CLR)](../dotnet/vector-reverse-iterator-stl-clr.md)|O tipo de um iterador inverso para a sequência controlada.|  
|[vector::size_type (STL/CLR)](../dotnet/vector-size-type-stl-clr.md)|O tipo de uma distância com sinal entre dois elementos.|  
|[vector::value_type (STL/CLR)](../dotnet/vector-value-type-stl-clr.md)|O tipo de um elemento.|  
  
|Função membro|Descrição|  
|---------------------|-----------------|  
|[vector::assign (STL/CLR)](../dotnet/vector-assign-stl-clr.md)|Substitui todos os elementos.|  
|[vector::at (STL/CLR)](../dotnet/vector-at-stl-clr.md)|Acessa um elemento em uma posição especificada.|  
|[vector::back (STL/CLR)](../dotnet/vector-back-stl-clr.md)|Acessa o último elemento.|  
|[vector::begin (STL/CLR)](../dotnet/vector-begin-stl-clr.md)|Designa o início da sequência controlada.|  
|[vector::capacity (STL/CLR)](../dotnet/vector-capacity-stl-clr.md)|Relata o tamanho do armazenamento alocado para o contêiner.|  
|[vector::clear (STL/CLR)](../dotnet/vector-clear-stl-clr.md)|Remove todos os elementos.|  
|[vector::empty (STL/CLR)](../dotnet/vector-empty-stl-clr.md)|Testa se nenhum elemento está presente.|  
|[vector::end (STL/CLR)](../dotnet/vector-end-stl-clr.md)|Designa o fim da sequência controlada.|  
|[vector::erase (STL/CLR)](../dotnet/vector-erase-stl-clr.md)|Remove os elementos em posições especificadas.|  
|[vector::front (STL/CLR)](../dotnet/vector-front-stl-clr.md)|Acessa o primeiro elemento.|  
|[vector::insert (STL/CLR)](../dotnet/vector-insert-stl-clr.md)|Adiciona os elementos em uma posição especificada.|  
|[vector::pop_back (STL/CLR)](../dotnet/vector-pop-back-stl-clr.md)|Remove o último elemento.|  
|[vector::push_back (STL/CLR)](../dotnet/vector-push-back-stl-clr.md)|Adiciona um novo elemento de última.|  
|[vector::rbegin (STL/CLR)](../dotnet/vector-rbegin-stl-clr.md)|Designa o início da sequência controlada invertida.|  
|[vector::rend (STL/CLR)](../dotnet/vector-rend-stl-clr.md)|Designa o fim da sequência controlada invertida.|  
|[vector::reserve (STL/CLR)](../dotnet/vector-reserve-stl-clr.md)|Garante a capacidade de crescimento mínimo para o contêiner.|  
|[vector::resize (STL/CLR)](../dotnet/vector-resize-stl-clr.md)|Altera o número de elementos.|  
|[vector::size (STL/CLR)](../dotnet/vector-size-stl-clr.md)|Conta o número de elementos.|  
|[vector::swap (STL/CLR)](../dotnet/vector-swap-stl-clr.md)|Alterna o conteúdo de dois contêineres.|  
|[vector::to_array (STL/CLR)](../dotnet/vector-to-array-stl-clr.md)|Copia uma nova matriz sequência controlada.|  
|[vector::vector (STL/CLR)](../dotnet/vector-vector-stl-clr.md)|Constrói um objeto contêiner.|  
  
|Propriedade|Descrição|  
|--------------|-----------------|  
|[vector::back_item (STL/CLR)](../dotnet/vector-back-item-stl-clr.md)|Acessa o último elemento.|  
|[vector::front_item (STL/CLR)](../dotnet/vector-front-item-stl-clr.md)|Acessa o primeiro elemento.|  
  
|Operador|Descrição|  
|--------------|-----------------|  
|[vector::operator= (STL/CLR)](../dotnet/vector-operator-assign-stl-clr.md)|Substitui a sequência controlada.|  
|[vector::operator(STL/CLR)](../dotnet/vector-operator-stl-clr.md)|Acessa um elemento em uma posição especificada.|  
|[operator!= (vector) (STL/CLR)](../dotnet/operator-inequality-vector-stl-clr.md)|Determina se um `vector` objeto não é igual a outro `vector` objeto.|  
|[operator< (vector) (STL/CLR)](../dotnet/operator-less-than-vector-stl-clr.md)|Determina se um `vector` objeto é menor que outro `vector` objeto.|  
|[operator<= (vector) (STL/CLR)](../dotnet/operator-less-or-equal-vector-stl-clr.md)|Determina se um `vector` objeto é menor ou igual a outro `vector` objeto.|  
|[operator== (vector) (STL/CLR)](../dotnet/operator-equality-vector-stl-clr.md)|Determina se um `vector` objeto é igual a outro `vector` objeto.|  
|[operator> (vector) (STL/CLR)](../dotnet/operator-greater-than-vector-stl-clr.md)|Determina se um `vector` objeto é maior que outro `vector` objeto.|  
|[operator>= (vector) (STL/CLR)](../dotnet/operator-greater-or-equal-vector-stl-clr.md)|Determina se um `vector` objeto é maior que ou igual a outro `vector` objeto.|  
  
## <a name="interfaces"></a>Interfaces  
  
|Interface|Descrição|  
|---------------|-----------------|  
|<xref:System.ICloneable>|Duplicar um objeto.|  
|<xref:System.Collections.IEnumerable>|Sequência de elementos.|  
|<xref:System.Collections.ICollection>|Manter o grupo de elementos.|  
|<xref:System.Collections.Generic.IEnumerable%601>|Sequência de elementos com tipo.|  
|<xref:System.Collections.Generic.ICollection%601>|Manter o grupo de elementos com tipo.|  
|<xref:System.Collections.Generic.IList%601>|Manter grupo ordenado de elementos com tipo.|  
|IVector < valor\>|Manter contêiner genérico.|  
  
## <a name="remarks"></a>Comentários  
 O objeto aloca e libera o armazenamento para a sequência em que ela controla, por meio de um conjunto armazenado de `Value` elementos, o que aumenta sob demanda. O crescimento ocorre de forma que o custo da anexação de um novo elemento é amortizado tempo constante. Em outras palavras, o custo de adição de elementos no final não aumenta, em média, como o comprimento do obtém sequência controlada maior. Assim, um vetor é um bom candidato para o contêiner subjacente para a classe de modelo [pilha (STL/CLR)](../dotnet/stack-stl-clr.md).  
  
 Um `vector` iteradores de acesso aleatório dá suporte a, que significa que você pode fazer referência a um elemento diretamente considerando sua posição numérica, contando a partir de zero para o primeiro elemento (frente), para `size() - 1` para o último elemento (back). Isso também significa que um vetor é um bom candidato para o contêiner subjacente para a classe de modelo [priority_queue (STL/CLR)](../dotnet/priority-queue-stl-clr.md).  
  
 Um iterador de vetor armazena um identificador para seu objeto de vetor associada, junto com a tendência do elemento que designa por ele. Você pode usar iteradores apenas com os objetos de contêiner associado. A diferença de um elemento de vetor é o mesmo que sua posição.  
  
 Inserindo ou apagar os elementos pode alterar o valor do elemento armazenado em uma posição especificada, portanto o valor designado por um iterador também pode alterar. (O contêiner pode ter que copiar os elementos para cima ou para baixo para criar um buraco antes de uma inserção ou para preencher um buraco após um apagamento). No entanto, um iterador de vetor permanece válido desde que o ajuste está no intervalo `[0, size()]`. Além disso, um iterador válido permanece dereferencable – você pode usá-lo para acessar ou alterar o valor do elemento ele designa – desde sua diferença não é igual a `size()`.  
  
 Apagar ou remover um elemento chama o destruidor para seu valor armazenado. Destruir o contêiner apaga todos os elementos. Assim, um contêiner cujo tipo de elemento é uma classe ref garante que nenhum elemento duram mais tempo o contêiner. No entanto, observe que um contêiner de identificadores não destrói seus elementos.  
  
## <a name="requirements"></a>Requisitos  
 **Cabeçalho:** \<cliext/vetor >  
  
 **Namespace:** cliext  
  
## <a name="see-also"></a>Consulte também  
 [deque (STL/CLR)](../dotnet/deque-stl-clr.md)   
 [lista (STL/CLR)](../dotnet/list-stl-clr.md)   
 [priority_queue (STL/CLR)](../dotnet/priority-queue-stl-clr.md)   
 [fila (STL/CLR)](../dotnet/queue-stl-clr.md)   
 [pilha (STL/CLR)](../dotnet/stack-stl-clr.md)   
 [vector::size (STL/CLR)](../dotnet/vector-size-stl-clr.md)  
 [Referência de biblioteca STL/CLR](../dotnet/stl-clr-library-reference.md)