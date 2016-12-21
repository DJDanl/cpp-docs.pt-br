---
title: "list (STL/CLR) | Microsoft Docs"
ms.custom: ""
ms.date: "12/03/2016"
ms.prod: "visual-studio-dev14"
ms.reviewer: ""
ms.suite: ""
ms.technology: 
  - "devlang-cpp"
ms.tgt_pltfrm: ""
ms.topic: "reference"
f1_keywords: 
  - "cliext::list"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "Cabeçalho &lt;cliext/list&gt; [STL/CLR]"
  - "Cabeçalho &lt;list&gt; [STL/CLR]"
  - "classe de lista [STL/CLR]"
ms.assetid: a70c45c8-a257-4f6b-8434-b27ff6685bac
caps.latest.revision: 17
caps.handback.revision: 17
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# list (STL/CLR)
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

A classe do modelo descreve um objeto que controla uma sequência de variar\- comprimento de elementos que tenha acesso bidirecional.  Você usa o contêiner `list` para gerenciar uma sequência de elementos como uma lista vinculada bidirecional de nós, cada um elemento armazenando.  
  
 Na descrição abaixo, `GValue` é o mesmo que `Value` a menos que o último é um tipo de referência, nesse caso é `Value^`.  
  
## Sintaxe  
  
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
  
#### Parâmetros  
 Valor  
 O tipo de um elemento na sequência controlada.  
  
## Membros  
  
|Definição de tipo|Descrição|  
|-----------------------|---------------|  
|[list::const\_iterator](../dotnet/list-const-iterator-stl-clr.md)|O tipo de um iterador de constante para a sequência controlada.|  
|[list::const\_reference](../dotnet/list-const-reference-stl-clr.md)|O tipo de uma referência constante para um elemento.|  
|[list::const\_reverse\_iterator](../dotnet/list-const-reverse-iterator-stl-clr.md)|O tipo de um iterador invertido constante para a sequência controlada.|  
|[list::difference\_type](../dotnet/list-difference-type-stl-clr.md)|O tipo de uma distância assinada entre dois elementos.|  
|[list::generic\_container](../dotnet/list-generic-container-stl-clr.md)|O tipo de interface genérica para o contêiner.|  
|[list::generic\_iterator \(STL\/CLR\)](../Topic/list::generic_iterator%20\(STL-CLR\).md)|O tipo de um iterador para a interface genérica para o contêiner.|  
|[list::generic\_reverse\_iterator](../dotnet/list-generic-reverse-iterator-stl-clr.md)|O tipo de um iterador de cima para baixo para a interface genérica para o contêiner.|  
|[list::generic\_value](../dotnet/list-generic-value-stl-clr.md)|O tipo de um elemento para a interface genérica para o contêiner.|  
|[list::iterator](../dotnet/list-iterator-stl-clr.md)|O tipo de um iterador para a sequência controlada.|  
|[list::reference](../dotnet/list-reference-stl-clr.md)|O tipo de uma referência para um elemento.|  
|[list::reverse\_iterator](../dotnet/list-reverse-iterator-stl-clr.md)|O tipo de um iterador de cima para baixo para a sequência controlada.|  
|[list::size\_type](../dotnet/list-size-type-stl-clr.md)|O tipo de uma distância assinada entre dois elementos.|  
|[list::value\_type](../dotnet/list-value-type-stl-clr.md)|O tipo de um elemento.|  
  
|Função de membro|Descrição|  
|----------------------|---------------|  
|[list::assign](../dotnet/list-assign-stl-clr.md)|Substitui todos os elementos.|  
|[list::back](../dotnet/list-back-stl-clr.md)|Acessa o elemento pela última vez.|  
|[list::begin](../Topic/list::begin%20\(STL-CLR\).md)|Designa o início da sequência controlada.|  
|[list::clear](../dotnet/list-clear-stl-clr.md)|Remove todos os elementos.|  
|[list::empty](../dotnet/list-empty-stl-clr.md)|Testa se nenhum elemento estiver presente.|  
|[list::end](../Topic/list::end%20\(STL-CLR\).md)|Designa o término da sequência controlada.|  
|[list::erase](../dotnet/list-erase-stl-clr.md)|Remove os elementos nas posições especificadas.|  
|[list::front](../dotnet/list-front-stl-clr.md)|Acessa o primeiro elemento.|  
|[list::insert](../dotnet/list-insert-stl-clr.md)|Adiciona os elementos em uma posição especificada.|  
|[list::list](../dotnet/list-list-stl-clr.md)|Cria um objeto contêiner.|  
|[list::merge](../dotnet/list-merge-stl-clr.md)|Mescla duas sequências ordenadas controladas.|  
|[list::pop\_back](../dotnet/list-pop-back-stl-clr.md)|Remove o elemento pela última vez.|  
|[list::pop\_front](../dotnet/list-pop-front-stl-clr.md)|Remove o primeiro elemento.|  
|[list::push\_back](../dotnet/list-push-back-stl-clr.md)|Adiciona um novo elemento a última vez.|  
|[list::push\_front](../Topic/list::push_front%20\(STL-CLR\).md)|Adiciona um novo primeiro elemento.|  
|[list::rbegin](../dotnet/list-rbegin-stl-clr.md)|Designa o início da sequência controlada invertida.|  
|[list::remove](../dotnet/list-remove-stl-clr.md)|Remove um elemento com um valor especificado.|  
|[list::remove\_if](../dotnet/list-remove-if-stl-clr.md)|Remove os elementos que passam um teste especificado.|  
|[list::rend \(STL\/CLR\)](../Topic/list::rend%20\(STL-CLR\).md)|Designa o término da sequência controlada invertida.|  
|[list::resize \(STL\/CLR\)](../dotnet/list-resize-stl-clr.md)|Altera o número de elementos.|  
|[list::reverse \(STL\/CLR\)](../dotnet/list-reverse-stl-clr.md)|Inverte a sequência controlada.|  
|[list::size \(STL\/CLR\)](../dotnet/list-size-stl-clr.md)|Conta o número de elementos.|  
|[list::sort](../dotnet/list-sort-stl-clr.md)|Classifica a sequência controlada.|  
|[list::splice](../Topic/list::splice%20\(STL-CLR\).md)|Links de Restitches entre nós.|  
|[list::swap](../Topic/list::swap%20\(STL-CLR\).md)|Alterna o conteúdo de dois contêineres.|  
|[list::to\_array](../dotnet/list-to-array-stl-clr.md)|Copia a sequência controlada a uma nova matriz.|  
|[list::unique](../dotnet/list-unique-stl-clr.md)|Remove os elementos adjacentes que passam um teste especificado.|  
  
|Propriedade|Descrição|  
|-----------------|---------------|  
|[list::back\_item](../Topic/list::back_item%20\(STL-CLR\).md)|Acessa o elemento pela última vez.|  
|[list::front\_item \(STL\/CLR\)](../dotnet/list-front-item-stl-clr.md)|Acessa o primeiro elemento.|  
  
|Operador|Descrição|  
|--------------|---------------|  
|[list::operator\= \(STL\/CLR\)](../dotnet/list-operator-assign-stl-clr.md)|Substitui a sequência controlada.|  
|[operador\!\= \(list\)](../dotnet/operator-inequality-list-stl-clr.md)|Determina se um objeto de `list` não é igual a outro objeto de `list` .|  
|[operador\< \(list\)](../dotnet/operator-less-than-list-stl-clr.md)|Determina se um objeto de `list` é menor que outro objeto de `list` .|  
|[operador\<\= \(list\)](../dotnet/operator-less-or-equal-list-stl-clr.md)|Determina se um objeto de `list` é menor ou igual a outro objeto de `list` .|  
|[operador\=\= \(list\)](../dotnet/operator-equality-list-stl-clr.md)|Determina se um objeto de `list` é igual a outro objeto de `list` .|  
|[operador\> \(list\)](../Topic/operator%3E%20\(list\)%20\(STL-CLR\).md)|Determina se um objeto de `list` é maior que outro objeto de `list` .|  
|[operador\>\= \(list\)](../dotnet/operator-greater-or-equal-list-stl-clr.md)|Determina se um objeto de `list` é maior ou igual a outro objeto de `list` .|  
  
## Interfaces  
  
|Interface|Descrição|  
|---------------|---------------|  
|<xref:System.ICloneable>|Duplica um objeto.|  
|<xref:System.Collections.IEnumerable>|Sequência por meio dos elementos.|  
|<xref:System.Collections.ICollection>|Mantenha o grupo de elementos.|  
|<xref:System.Collections.Generic.IEnumerable%601>|Sequência por meio dos elementos digitados.|  
|<xref:System.Collections.Generic.ICollection%601>|Mantenha o grupo de elementos de tipo.|  
|IListValue\<\>|Mantenha o contêiner genérico.|  
  
## Comentários  
 O objeto aloca e libera armazenamento para a sequência que controla como os nós individuais em um link bidirecional lista.  Reorganiza os elementos alterando os links entre nós, nunca copiar o conteúdo de um nó para outro.  Isso significa que você pode inserir e remover os elementos livremente sem os outros elementos de perturbação.  Portanto, uma lista é uma boa candidata para o contêiner subjacente da classe [queue](../Topic/queue%20\(STL-CLR\).md) do modelo ou a classe [stack](../dotnet/stack-stl-clr.md)do modelo.  
  
 Um objeto de `list` oferece suporte aos iteradores bidirecionais, o que significa que você pode avançar para os elementos adjacentes um iterador dados que designa um elemento na sequência controlada.  Um nó principal especial corresponde ao iterador retornado por [list::end](../Topic/list::end%20\(STL-CLR\).md)`()`.  Você pode diminuir este iterador para alcançar o elemento o mais recente na sequência controlada, se houver.  É possível incrementar um iterador da lista para alcançar o nó principal, e comparará no igual a `end()`.  Mas você não pode desreferenciar o iterador retornado por `end()`.  
  
 Observe que você não pode se referir a um elemento da lista determinado diretamente a posição numérica \-\- isso requer um iterador de acesso aleatório.  Para uma lista é útil `not` como o contêiner subjacente da classe [priority\_queue](../Topic/priority_queue%20\(STL-CLR\).md)do modelo.  
  
 Um iterador da lista armazena um identificador para o nó associado na lista, por sua vez que armazena um identificador para o contêiner associado.  Você pode usar iteradores apenas com seus objetos de contêiner associados.  Um iterador da lista permanece válido desde que o nó associado na lista é associado a qualquer lista.  Além disso, um iterador válido é dereferencable \-\- você pode usá\-lo para acessar ou modificar o valor do elemento que designa \-\- contanto que não é igual a `end()`.  
  
 Apagando ou removendo um elemento chama o destruidor para seu valor armazenado.  Destruir o contêiner apaga todos os elementos.  Assim, um contêiner cujo tipo de elemento é uma classe de referência garante que nenhum elemento é maior que o contêiner.  A observe, entretanto, que manipula um contêiner faz `not` destrói seus elementos.  
  
## Requisitos  
 cliext \<\/lista de**Cabeçalho:** \>  
  
 cliext de**Namespace:**  
  
## Consulte também  
 [deque](../dotnet/deque-stl-clr.md)   
 [priority\_queue](../Topic/priority_queue%20\(STL-CLR\).md)   
 [queue](../Topic/queue%20\(STL-CLR\).md)   
 [stack](../dotnet/stack-stl-clr.md)   
 [vector](../dotnet/vector-stl-clr.md)   
 [Biblioteca STL\/CLR](../dotnet/stl-clr-library-reference.md)