---
title: deque (STL/CLR) | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-cli
ms.topic: reference
f1_keywords:
- cliext::deque
dev_langs:
- C++
helpviewer_keywords:
- deque class [STL/CLR]
- <deque> header [STL/CLR]
- <cliext/deque> header [STL/CLR]
ms.assetid: dd669da3-3c0e-45e9-8596-f6b483720941
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
- dotnet
ms.openlocfilehash: 11436466dadf4b06e604af6e2b5150a22c4ed241
ms.sourcegitcommit: 76b7653ae443a2b8eb1186b789f8503609d6453e
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/04/2018
---
# <a name="deque-stlclr"></a>deque (STL/CLR)
A classe de modelo descreve um objeto que controla uma sequência de comprimento variável de elementos que tenha acesso aleatório. Você usa o contêiner `deque` para gerenciar uma sequência de elementos que se parece com um bloco de contíguo de armazenamento, mas que pode aumentar ou diminuir em ambas as extremidades sem a necessidade de copiar todos os elementos restantes. Assim, ela pode implementar com eficiência um `double-ended queue`. (Portanto, o nome.)  
  
 Na descrição abaixo, `GValue` é o mesmo que `Value` , a menos que o último é um tipo de referência, caso em que é `Value^`.  
  
## <a name="syntax"></a>Sintaxe  
  
```  
template<typename Value>  
    ref class deque  
        :   public  
        System::ICloneable,  
        System::Collections::IEnumerable,  
        System::Collections::ICollection,  
        System::Collections::Generic::IEnumerable<GValue>,  
        System::Collections::Generic::ICollection<GValue>,  
        System::Collections::Generic::IList<GValue>,  
        Microsoft::VisualC::StlClr::IDeque<GValue>  
    { ..... };  
```  
  
#### <a name="parameters"></a>Parâmetros  
 GValue  
 O tipo genérico de um elemento na sequência controlada.  
  
 Valor  
 O tipo de um elemento na sequência controlada.  
  
## <a name="members"></a>Membros  
  
|Definição do tipo|Descrição|  
|---------------------|-----------------|  
|[deque::const_iterator (STL/CLR)](../dotnet/deque-const-iterator-stl-clr.md)|O tipo de um iterador de constante para a sequência controlada.|  
|[deque::const_reference (STL/CLR)](../dotnet/deque-const-reference-stl-clr.md)|O tipo de uma referência de constante para um elemento.|  
|[deque::const_reverse_iterator (STL/CLR)](../dotnet/deque-const-reverse-iterator-stl-clr.md)|O tipo de um iterador reverso de constante para a sequência controlada.|  
|[deque::difference_type (STL/CLR)](../dotnet/deque-difference-type-stl-clr.md)|O tipo de uma distância com sinal entre dois elementos.|  
|[deque::generic_container (STL/CLR)](../dotnet/deque-generic-container-stl-clr.md)|O tipo da interface genérica para o contêiner.|  
|[deque::generic_iterator (STL/CLR)](../dotnet/deque-generic-iterator-stl-clr.md)|O tipo de um iterador para a interface genérica para o contêiner.|  
|[deque::generic_reverse_iterator (STL/CLR)](../dotnet/deque-generic-reverse-iterator-stl-clr.md)|O tipo de um iterador inverso para a interface genérica para o contêiner.|  
|[deque::generic_value (STL/CLR)](../dotnet/deque-generic-value-stl-clr.md)|O tipo de um elemento para a interface genérica para o contêiner.|  
|[deque::iterator (STL/CLR)](../dotnet/deque-iterator-stl-clr.md)|O tipo de um iterador para a sequência controlada.|  
|[deque::reference (STL/CLR)](../dotnet/deque-reference-stl-clr.md)|O tipo de uma referência para um elemento.|  
|[deque::reverse_iterator (STL/CLR)](../dotnet/deque-reverse-iterator-stl-clr.md)|O tipo de um iterador inverso para a sequência controlada.|  
|[deque::size_type (STL/CLR)](../dotnet/deque-size-type-stl-clr.md)|O tipo de uma distância com sinal entre dois elementos.|  
|[deque::value_type (STL/CLR)](../dotnet/deque-value-type-stl-clr.md)|O tipo de um elemento.|  
  
|Função membro|Descrição|  
|---------------------|-----------------|  
|[deque::assign (STL/CLR)](../dotnet/deque-assign-stl-clr.md)|Substitui todos os elementos.|  
|[deque::at (STL/CLR)](../dotnet/deque-at-stl-clr.md)|Acessa um elemento em uma posição especificada.|  
|[deque::back (STL/CLR)](../dotnet/deque-back-stl-clr.md)|Acessa o último elemento.|  
|[deque::begin (STL/CLR)](../dotnet/deque-begin-stl-clr.md)|Designa o início da sequência controlada.|  
|[deque::clear (STL/CLR)](../dotnet/deque-clear-stl-clr.md)|Remove todos os elementos.|  
|[deque::deque (STL/CLR)](../dotnet/deque-deque-stl-clr.md)|Constrói um objeto contêiner.|  
|[deque::empty (STL/CLR)](../dotnet/deque-empty-stl-clr.md)|Testa se nenhum elemento está presente.|  
|[deque::end (STL/CLR)](../dotnet/deque-end-stl-clr.md)|Designa o fim da sequência controlada.|  
|[deque::erase (STL/CLR)](../dotnet/deque-erase-stl-clr.md)|Remove os elementos em posições especificadas.|  
|[deque::front (STL/CLR)](../dotnet/deque-front-stl-clr.md)|Acessa o primeiro elemento.|  
|[deque::insert (STL/CLR)](../dotnet/deque-insert-stl-clr.md)|Adiciona os elementos em uma posição especificada.|  
|[deque::pop_back (STL/CLR)](../dotnet/deque-pop-back-stl-clr.md)|Remove o último elemento.|  
|[deque::pop_front (STL/CLR)](../dotnet/deque-pop-front-stl-clr.md)|Remove o primeiro elemento.|  
|[deque::push_back (STL/CLR)](../dotnet/deque-push-back-stl-clr.md)|Adiciona um novo elemento de última.|  
|[deque::push_front (STL/CLR)](../dotnet/deque-push-front-stl-clr.md)|Adiciona um novo elemento primeiro.|  
|[deque::rbegin (STL/CLR)](../dotnet/deque-rbegin-stl-clr.md)|Designa o início da sequência controlada invertida.|  
|[deque::rend (STL/CLR)](../dotnet/deque-rend-stl-clr.md)|Designa o fim da sequência controlada invertida.|  
|[deque::resize (STL/CLR)](../dotnet/deque-resize-stl-clr.md)|Altera o número de elementos.|  
|[deque::size (STL/CLR)](../dotnet/deque-size-stl-clr.md)|Conta o número de elementos.|  
|[deque::swap (STL/CLR)](../dotnet/deque-swap-stl-clr.md)|Alterna o conteúdo de dois contêineres.|  
|[deque::to_array (STL/CLR)](../dotnet/deque-to-array-stl-clr.md)|Copia uma nova matriz sequência controlada.|  
  
|Propriedade|Descrição|  
|--------------|-----------------|  
|[deque::back_item (STL/CLR)](../dotnet/deque-back-item-stl-clr.md)|Acessa o último elemento.|  
|[deque::front_item (STL/CLR)](../dotnet/deque-front-item-stl-clr.md)|Acessa o primeiro elemento.|  
  
|Operador|Descrição|  
|--------------|-----------------|  
|[deque::operator!= (STL/CLR)](../dotnet/deque-operator-inequality-stl-clr.md)|Determina se dois `deque` objetos não são iguais.|  
|[deque::operator(STL/CLR)](../dotnet/deque-operator-stl-clr.md)|Acessa um elemento em uma posição especificada.|  
|[operator< (deque) (STL/CLR)](../dotnet/operator-less-than-deque-stl-clr.md)|Determina se um `deque` objeto é menor que outro `deque` objeto.|  
|[operator<= (deque) (STL/CLR)](../dotnet/operator-less-or-equal-deque-stl-clr.md)|Determina se um `deque` objeto é menor ou igual a outro `deque` objeto.|  
|[operator= (deque) (STL/CLR)](../dotnet/operator-assign-deque-stl-clr.md)|Substitui a sequência controlada.|  
|[operator== (deque) (STL/CLR)](../dotnet/operator-equality-deque-stl-clr.md)|Determina se um `deque` objeto é igual a outro `deque` objeto.|  
|[operator> (deque) (STL/CLR)](../dotnet/operator-greater-than-deque-stl-clr.md)|Determina se um `deque` objeto é maior que outro `deque` objeto.|  
|[operator>= (deque) (STL/CLR)](../dotnet/operator-greater-or-equal-deque-stl-clr.md)|Determina se um `deque` objeto é maior que ou igual a outro `deque` objeto.|  
  
## <a name="interfaces"></a>Interfaces  
  
|Interface|Descrição|  
|---------------|-----------------|  
|<xref:System.ICloneable>|Duplicar um objeto.|  
|<xref:System.Collections.IEnumerable>|Sequência de elementos.|  
|<xref:System.Collections.ICollection>|Manter o grupo de elementos.|  
|<xref:System.Collections.Generic.IEnumerable%601>|Sequência de elementos com tipo.|  
|<xref:System.Collections.Generic.ICollection%601>|Manter o grupo de elementos com tipo.|  
|<xref:System.Collections.Generic.IList%601>|Manter grupo ordenado de elementos com tipo.|  
|IDeque < valor\>|Manter contêiner genérico.|  
  
## <a name="remarks"></a>Comentários  
 O objeto aloca e libera o armazenamento para a sequência controla por meio de uma matriz armazenada de identificadores que designa blocos de `Value` elementos. A matriz aumenta sob demanda. O crescimento ocorre de forma que o custo de acrescentando ou acrescentar um novo elemento é tempo constante e não há elementos restantes são afetados. Você também pode remover um elemento na extremidade de tempo constante e sem prejudicar elementos restantes. Assim, um deque é um bom candidato para o contêiner subjacente para a classe de modelo [queue (STL/CLR)](../dotnet/queue-stl-clr.md) ou classe de modelo [pilha (STL/CLR)](../dotnet/stack-stl-clr.md).  
  
 Um `deque` objeto oferece suporte ao acesso aleatório iteradores, que significa que você pode fazer referência a um elemento diretamente considerando sua posição numérica, contando a partir de zero para o primeiro elemento (frontal), para [deque (STL/CLR)](../dotnet/deque-size-stl-clr.md) `() - 1` para o último elemento (Voltar). Isso também significa que um deque é um bom candidato para o contêiner subjacente para a classe de modelo [priority_queue (STL/CLR)](../dotnet/priority-queue-stl-clr.md).  
  
 Um iterador deque armazena um identificador para seu objeto deque associado, junto com a tendência do elemento que designa por ele. Você pode usar iteradores apenas com os objetos de contêiner associado. É a diferença de um elemento deque `not` necessariamente o mesmo que sua posição. O primeiro elemento inserido tem diferença zero, o próximo elemento acrescentado tem diferença 1, mas o próximo elemento antecedendo tem diferença -1.  
  
 Inserindo ou apagar os elementos em ambas as extremidades não `not` alterar o valor de um elemento armazenado em qualquer diferença válida. Inserir ou apagar um elemento interior, no entanto, `can` alterar o valor do elemento armazenado em uma determinado diferença, portanto também pode alterar o valor designado por um iterador. (O contêiner pode ter que copiar os elementos para cima ou para baixo para criar um buraco antes de uma inserção ou para preencher um buraco após um apagamento). No entanto, um iterador deque permanece válido desde que o ajuste designa um elemento válido. Além disso, um iterador válido permanece dereferencable – você pode usá-lo para acessar ou alterar o valor do elemento ele designa – desde sua diferença não é igual a tendência para o iterador retornado por `end()`.  
  
 Apagar ou remover um elemento chama o destruidor para seu valor armazenado. Destruir o contêiner apaga todos os elementos. Assim, um contêiner cujo tipo de elemento é uma classe ref garante que nenhum elemento duram mais tempo o contêiner. No entanto, observe que um contêiner de identificadores não `not` destruir seus elementos.  
  
## <a name="requirements"></a>Requisitos  
 **Cabeçalho:** \<cliext/deque >  
  
 **Namespace:** cliext  
  
## <a name="see-also"></a>Consulte também  
 [lista (STL/CLR)](../dotnet/list-stl-clr.md)   
 [priority_queue (STL/CLR)](../dotnet/priority-queue-stl-clr.md)   
 [fila (STL/CLR)](../dotnet/queue-stl-clr.md)   
 [pilha (STL/CLR)](../dotnet/stack-stl-clr.md)   
 [vetor (STL/CLR)](../dotnet/vector-stl-clr.md)   
 [Referência de biblioteca STL/CLR](../dotnet/stl-clr-library-reference.md)