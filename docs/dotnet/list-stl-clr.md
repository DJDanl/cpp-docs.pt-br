---
title: lista (STL/CLR) | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- cpp-windows
ms.tgt_pltfrm: 
ms.topic: reference
f1_keywords:
- cliext::list
dev_langs:
- C++
helpviewer_keywords:
- <cliext/list> header [STL/CLR]
- list class [STL/CLR]
- <list> header [STL/CLR]
ms.assetid: a70c45c8-a257-4f6b-8434-b27ff6685bac
caps.latest.revision: 
author: mikeblome
ms.author: mblome
manager: ghogen
ms.workload:
- cplusplus
- dotnet
ms.openlocfilehash: 40046e2b7263559765c2aab2bef13a17c341f7c8
ms.sourcegitcommit: 8fa8fdf0fbb4f57950f1e8f4f9b81b4d39ec7d7a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/21/2017
---
# <a name="list-stlclr"></a>list (STL/CLR)
A classe de modelo descreve um objeto que controla uma sequência de comprimento variável de elementos que tenha acesso bidirecional. Você usa o contêiner `list` para gerenciar uma sequência de elementos como uma lista vinculada bidirecional de nós, cada armazenamento de um elemento.  
  
 Na descrição abaixo, `GValue` é o mesmo que `Value` , a menos que o último é um tipo de referência, caso em que é `Value^`.  
  
## <a name="syntax"></a>Sintaxe  
  
```  
template<typename Value>  
    ref class list  
        :   public  
        System::ICloneable,  
        System::Collections::IEnumerable,  
        System::Collections::ICollection,  
        System::Collections::Generic::IEnumerable<GValue>,  
        System::Collections::Generic::ICollection<GValue>,  
        Microsoft::VisualC::StlClr::IList<GValue>  
    { ..... };  
```  
  
#### <a name="parameters"></a>Parâmetros  
 Valor  
 O tipo de um elemento na sequência controlada.  
  
## <a name="members"></a>Membros  
  
|Definição do tipo|Descrição|  
|---------------------|-----------------|  
|[list::const_iterator (STL/CLR)](../dotnet/list-const-iterator-stl-clr.md)|O tipo de um iterador de constante para a sequência controlada.|  
|[list::const_reference (STL/CLR)](../dotnet/list-const-reference-stl-clr.md)|O tipo de uma referência de constante para um elemento.|  
|[list::const_reverse_iterator (STL/CLR)](../dotnet/list-const-reverse-iterator-stl-clr.md)|O tipo de um iterador reverso de constante para a sequência controlada.|  
|[list::difference_type (STL/CLR)](../dotnet/list-difference-type-stl-clr.md)|O tipo de uma distância com sinal entre dois elementos.|  
|[list::generic_container (STL/CLR)](../dotnet/list-generic-container-stl-clr.md)|O tipo da interface genérica para o contêiner.|  
|[list::generic_iterator (STL/CLR)](../dotnet/list-generic-iterator-stl-clr.md)|O tipo de um iterador para a interface genérica para o contêiner.|  
|[list::generic_reverse_iterator (STL/CLR)](../dotnet/list-generic-reverse-iterator-stl-clr.md)|O tipo de um iterador inverso para a interface genérica para o contêiner.|  
|[list::generic_value (STL/CLR)](../dotnet/list-generic-value-stl-clr.md)|O tipo de um elemento para a interface genérica para o contêiner.|  
|[list::iterator (STL/CLR)](../dotnet/list-iterator-stl-clr.md)|O tipo de um iterador para a sequência controlada.|  
|[list::reference (STL/CLR)](../dotnet/list-reference-stl-clr.md)|O tipo de uma referência para um elemento.|  
|[list::reverse_iterator (STL/CLR)](../dotnet/list-reverse-iterator-stl-clr.md)|O tipo de um iterador inverso para a sequência controlada.|  
|[list::size_type (STL/CLR)](../dotnet/list-size-type-stl-clr.md)|O tipo de uma distância com sinal entre dois elementos.|  
|[list::value_type (STL/CLR)](../dotnet/list-value-type-stl-clr.md)|O tipo de um elemento.|  
  
|Função membro|Descrição|  
|---------------------|-----------------|  
|[list::assign (STL/CLR)](../dotnet/list-assign-stl-clr.md)|Substitui todos os elementos.|  
|[list::back (STL/CLR)](../dotnet/list-back-stl-clr.md)|Acessa o último elemento.|  
|[list::begin (STL/CLR)](../dotnet/list-begin-stl-clr.md)|Designa o início da sequência controlada.|  
|[list::clear (STL/CLR)](../dotnet/list-clear-stl-clr.md)|Remove todos os elementos.|  
|[list::empty (STL/CLR)](../dotnet/list-empty-stl-clr.md)|Testa se nenhum elemento está presente.|  
|[list::end (STL/CLR)](../dotnet/list-end-stl-clr.md)|Designa o fim da sequência controlada.|  
|[list::erase (STL/CLR)](../dotnet/list-erase-stl-clr.md)|Remove os elementos em posições especificadas.|  
|[list::front (STL/CLR)](../dotnet/list-front-stl-clr.md)|Acessa o primeiro elemento.|  
|[list::insert (STL/CLR)](../dotnet/list-insert-stl-clr.md)|Adiciona os elementos em uma posição especificada.|  
|[list::list (STL/CLR)](../dotnet/list-list-stl-clr.md)|Constrói um objeto contêiner.|  
|[list::merge (STL/CLR)](../dotnet/list-merge-stl-clr.md)|Mescla duas sequências controladas ordenadas.|  
|[list::pop_back (STL/CLR)](../dotnet/list-pop-back-stl-clr.md)|Remove o último elemento.|  
|[list::pop_front (STL/CLR)](../dotnet/list-pop-front-stl-clr.md)|Remove o primeiro elemento.|  
|[list::push_back (STL/CLR)](../dotnet/list-push-back-stl-clr.md)|Adiciona um novo elemento de última.|  
|[list::push_front (STL/CLR)](../dotnet/list-push-front-stl-clr.md)|Adiciona um novo elemento primeiro.|  
|[list::rbegin (STL/CLR)](../dotnet/list-rbegin-stl-clr.md)|Designa o início da sequência controlada invertida.|  
|[list::remove (STL/CLR)](../dotnet/list-remove-stl-clr.md)|Remove um elemento com um valor especificado.|  
|[list::remove_if (STL/CLR)](../dotnet/list-remove-if-stl-clr.md)|Remove os elementos que passa um teste especificado.|  
|[list::rend (STL/CLR)](../dotnet/list-rend-stl-clr.md)|Designa o fim da sequência controlada invertida.|  
|[list::resize (STL/CLR)](../dotnet/list-resize-stl-clr.md)|Altera o número de elementos.|  
|[list::reverse (STL/CLR)](../dotnet/list-reverse-stl-clr.md)|Inverte a sequência controlada.|  
|[list::size (STL/CLR)](../dotnet/list-size-stl-clr.md)|Conta o número de elementos.|  
|[list::sort (STL/CLR)](../dotnet/list-sort-stl-clr.md)|Ordena a sequência controlada.|  
|[list::splice (STL/CLR)](../dotnet/list-splice-stl-clr.md)|Costura novamente links entre os nós.|  
|[list::swap (STL/CLR)](../dotnet/list-swap-stl-clr.md)|Alterna o conteúdo de dois contêineres.|  
|[list::to_array (STL/CLR)](../dotnet/list-to-array-stl-clr.md)|Copia uma nova matriz sequência controlada.|  
|[list::unique (STL/CLR)](../dotnet/list-unique-stl-clr.md)|Remove elementos adjacentes que são passados a um teste especificado.|  
  
|Propriedade|Descrição|  
|--------------|-----------------|  
|[list::back_item (STL/CLR)](../dotnet/list-back-item-stl-clr.md)|Acessa o último elemento.|  
|[list::front_item (STL/CLR)](../dotnet/list-front-item-stl-clr.md)|Acessa o primeiro elemento.|  
  
|Operador|Descrição|  
|--------------|-----------------|  
|[list::operator= (STL/CLR)](../dotnet/list-operator-assign-stl-clr.md)|Substitui a sequência controlada.|  
|[operator!= (list) (STL/CLR)](../dotnet/operator-inequality-list-stl-clr.md)|Determina se um `list` objeto não é igual a outro `list` objeto.|  
|[operator< (list) (STL/CLR)](../dotnet/operator-less-than-list-stl-clr.md)|Determina se um `list` objeto é menor que outro `list` objeto.|  
|[operator<= (list) (STL/CLR)](../dotnet/operator-less-or-equal-list-stl-clr.md)|Determina se um `list` objeto é menor ou igual a outro `list` objeto.|  
|[operator== (list) (STL/CLR)](../dotnet/operator-equality-list-stl-clr.md)|Determina se um `list` objeto é igual a outro `list` objeto.|  
|[operator> (list) (STL/CLR)](../dotnet/operator-greater-than-list-stl-clr.md)|Determina se um `list` objeto é maior que outro `list` objeto.|  
|[operator>= (list) (STL/CLR)](../dotnet/operator-greater-or-equal-list-stl-clr.md)|Determina se um `list` objeto é maior que ou igual a outro `list` objeto.|  
  
## <a name="interfaces"></a>Interfaces  
  
|Interface|Descrição|  
|---------------|-----------------|  
|<xref:System.ICloneable>|Duplicar um objeto.|  
|<xref:System.Collections.IEnumerable>|Sequência de elementos.|  
|<xref:System.Collections.ICollection>|Manter o grupo de elementos.|  
|<xref:System.Collections.Generic.IEnumerable%601>|Sequência de elementos com tipo.|  
|<xref:System.Collections.Generic.ICollection%601>|Manter o grupo de elementos com tipo.|  
|IList\<valor >|Manter contêiner genérico.|  
  
## <a name="remarks"></a>Comentários  
 O objeto aloca e libera o armazenamento para a sequência em que ele controla como nós individuais em uma lista de links bidirecional. Ele reorganiza elementos alterando os links entre nós nunca copiando o conteúdo de um nó para outro. Isso significa que você pode inserir e remover elementos livremente, sem prejudicar elementos restantes. Assim, uma lista é um bom candidato para o contêiner subjacente para a classe de modelo [queue (STL/CLR)](../dotnet/queue-stl-clr.md) ou classe de modelo [pilha (STL/CLR)](../dotnet/stack-stl-clr.md).  
  
 Um `list` objeto suporta iteradores bidirecional, o que significa que você pode depurar a elementos adjacentes recebe um iterador que designa um elemento na sequência controlada. Um nó de cabeçalho especial corresponde para o iterador retornado por [List:: end (STL/CLR)](../dotnet/list-end-stl-clr.md)`()`. Você pode diminuir este iterador para alcançar o último elemento na sequência controlada, se presente. Você pode aumentar um iterador da lista para alcançar o nó principal e, em seguida, comparará igual a `end()`. Mas você não pode cancelar o iterador retornado por `end()`.  
  
 Observe que você não pode se referir a um elemento de lista fornecido diretamente sua posição numérica - que requer um iterador de acesso aleatório. Portanto, é uma lista `not` pode ser usado como o contêiner subjacente para a classe de modelo [priority_queue (STL/CLR)](../dotnet/priority-queue-stl-clr.md).  
  
 Um iterador da lista armazena um identificador para seu nó de lista associado, que por sua vez, armazena um identificador para o contêiner associado. Você pode usar iteradores apenas com os objetos de contêiner associado. Um iterador da lista permanece válido desde que o nó de lista associado seja associado a alguns lista. Além disso, um iterador válido é dereferencable - você pode usá-lo para acessar ou alterar o valor do elemento ele designa – desde que ele não é igual a `end()`.  
  
 Apagar ou remover um elemento chama o destruidor para seu valor armazenado. Destruir o contêiner apaga todos os elementos. Assim, um contêiner cujo tipo de elemento é uma classe ref garante que nenhum elemento duram mais tempo o contêiner. No entanto, observe que um contêiner de identificadores não `not` destruir seus elementos.  
  
## <a name="requirements"></a>Requisitos  
 **Cabeçalho:** \<cliext/lista >  
  
 **Namespace:** cliext  
  
## <a name="see-also"></a>Consulte também  
 [deque (STL/CLR)](../dotnet/deque-stl-clr.md)   
 [priority_queue (STL/CLR)](../dotnet/priority-queue-stl-clr.md)   
 [fila (STL/CLR)](../dotnet/queue-stl-clr.md)   
 [pilha (STL/CLR)](../dotnet/stack-stl-clr.md)   
 [vetor (STL/CLR)](../dotnet/vector-stl-clr.md)   
 [Referência de biblioteca STL/CLR](../dotnet/stl-clr-library-reference.md)