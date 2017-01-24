---
title: "deque (STL/CLR) | Microsoft Docs"
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
  - "cliext::deque"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "Cabeçalho &lt;cliext/deque&gt; [STL/CLR]"
  - "Cabeçalho &lt;deque&gt; [STL/CLR]"
  - "Classe deque [STL/CLR]"
ms.assetid: dd669da3-3c0e-45e9-8596-f6b483720941
caps.latest.revision: 22
caps.handback.revision: 22
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# deque (STL/CLR)
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

A classe do modelo descreve um objeto que controla uma sequência de variar\- comprimento dos elementos que tem de acesso aleatório.  Você usa o contêiner `deque` para gerenciar uma sequência de elementos que observa como um bloco contínuo de armazenamento, mas que pode crescer ou encolher em uma ou outra extremidade sem a necessidade de copiar todos os elementos restantes.  Isso pode implementar com eficiência `double-ended queue`. \(Como o nome.\)  
  
 Na descrição abaixo, `GValue` é o mesmo que `Value` a menos que o último é um tipo de referência, nesse caso é `Value^`.  
  
## Sintaxe  
  
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
  
#### Parâmetros  
 GValue  
 O tipo genérico de um elemento na sequência controlada.  
  
 Valor  
 O tipo de um elemento na sequência controlada.  
  
## Membros  
  
|Definição de tipo|Descrição|  
|-----------------------|---------------|  
|[deque::const\_iterator](../Topic/deque::const_iterator%20\(STL-CLR\).md)|O tipo de um iterador de constante para a sequência controlada.|  
|[deque::const\_reference](../dotnet/deque-const-reference-stl-clr.md)|O tipo de uma referência constante para um elemento.|  
|[deque::const\_reverse\_iterator](../dotnet/deque-const-reverse-iterator-stl-clr.md)|O tipo de um iterador invertido constante para a sequência controlada.|  
|[deque::difference\_type](../dotnet/deque-difference-type-stl-clr.md)|O tipo de uma distância assinada entre dois elementos.|  
|[deque::generic\_container](../Topic/deque::generic_container%20\(STL-CLR\).md)|O tipo de interface genérica para o contêiner.|  
|[deque::generic\_iterator](../dotnet/deque-generic-iterator-stl-clr.md)|O tipo de um iterador para a interface genérica para o contêiner.|  
|[deque::generic\_reverse\_iterator](../Topic/deque::generic_reverse_iterator%20\(STL-CLR\).md)|O tipo de um iterador de cima para baixo para a interface genérica para o contêiner.|  
|[deque::generic\_value](../Topic/deque::generic_value%20\(STL-CLR\).md)|O tipo de um elemento para a interface genérica para o contêiner.|  
|[deque::iterator](../dotnet/deque-iterator-stl-clr.md)|O tipo de um iterador para a sequência controlada.|  
|[deque::reference](../dotnet/deque-reference-stl-clr.md)|O tipo de uma referência para um elemento.|  
|[deque::reverse\_iterator](../dotnet/deque-reverse-iterator-stl-clr.md)|O tipo de um iterador de cima para baixo para a sequência controlada.|  
|[deque::size\_type](../dotnet/deque-size-type-stl-clr.md)|O tipo de uma distância assinada entre dois elementos.|  
|[deque::value\_type](../Topic/deque::value_type%20\(STL-CLR\).md)|O tipo de um elemento.|  
  
|Função de membro|Descrição|  
|----------------------|---------------|  
|[deque::assign](../dotnet/deque-assign-stl-clr.md)|Substitui todos os elementos.|  
|[deque::at](../dotnet/deque-at-stl-clr.md)|Acessa um elemento em uma posição especificada.|  
|[deque::back](../dotnet/deque-back-stl-clr.md)|Acessa o elemento pela última vez.|  
|[deque::begin](../dotnet/deque-begin-stl-clr.md)|Designa o início da sequência controlada.|  
|[deque::clear](../dotnet/deque-clear-stl-clr.md)|Remove todos os elementos.|  
|[deque::deque](../dotnet/deque-deque-stl-clr.md)|Cria um objeto contêiner.|  
|[deque::empty](../dotnet/deque-empty-stl-clr.md)|Testa se nenhum elemento estiver presente.|  
|[deque::end](../Topic/deque::end%20\(STL-CLR\).md)|Designa o término da sequência controlada.|  
|[deque::erase](../Topic/deque::erase%20\(STL-CLR\).md)|Remove os elementos nas posições especificadas.|  
|[deque::front](../Topic/deque::front%20\(STL-CLR\).md)|Acessa o primeiro elemento.|  
|[deque::insert](../dotnet/deque-insert-stl-clr.md)|Adiciona os elementos em uma posição especificada.|  
|[deque::pop\_back](../dotnet/deque-pop-back-stl-clr.md)|Remove o elemento pela última vez.|  
|[deque::pop\_front](../dotnet/deque-pop-front-stl-clr.md)|Remove o primeiro elemento.|  
|[deque::push\_back](../dotnet/deque-push-back-stl-clr.md)|Adiciona um novo elemento a última vez.|  
|[deque::push\_front](../dotnet/deque-push-front-stl-clr.md)|Adiciona um novo primeiro elemento.|  
|[deque::rbegin](../dotnet/deque-rbegin-stl-clr.md)|Designa o início da sequência controlada invertida.|  
|[deque::rend](../Topic/deque::rend%20\(STL-CLR\).md)|Designa o término da sequência controlada invertida.|  
|[deque::resize](../dotnet/deque-resize-stl-clr.md)|Altera o número de elementos.|  
|[deque::size](../Topic/deque::size%20\(STL-CLR\).md)|Conta o número de elementos.|  
|[deque::swap](../dotnet/deque-swap-stl-clr.md)|Alterna o conteúdo de dois contêineres.|  
|[deque::to\_array](../dotnet/deque-to-array-stl-clr.md)|Copia a sequência controlada a uma nova matriz.|  
  
|Propriedade|Descrição|  
|-----------------|---------------|  
|[deque::back\_item](../Topic/deque::back_item%20\(STL-CLR\).md)|Acessa o elemento pela última vez.|  
|[deque::front\_item](../dotnet/deque-front-item-stl-clr.md)|Acessa o primeiro elemento.|  
  
|Operador|Descrição|  
|--------------|---------------|  
|[deque::operator\!\=](../dotnet/deque-operator-inequality-stl-clr.md)|Determina se dois objetos de `deque` não são iguais.|  
|[deque::operator](../Topic/deque::operator\(STL-CLR\).md)|Acessa um elemento em uma posição especificada.|  
|[operador\< \(deque\)](../dotnet/operator-less-than-deque-stl-clr.md)|Determina se um objeto de `deque` é menor que outro objeto de `deque` .|  
|[operador\<\= \(deque\)](../dotnet/operator-less-or-equal-deque-stl-clr.md)|Determina se um objeto de `deque` é menor ou igual a outro objeto de `deque` .|  
|[operador\= \(deque\)](../dotnet/operator-assign-deque-stl-clr.md)|Substitui a sequência controlada.|  
|[operador\=\= \(deque\)](../dotnet/operator-equality-deque-stl-clr.md)|Determina se um objeto de `deque` é igual a outro objeto de `deque` .|  
|[operador\> \(deque\)](../dotnet/operator-greater-than-deque-stl-clr.md)|Determina se um objeto de `deque` é maior que outro objeto de `deque` .|  
|[operador\>\= \(deque\)](../dotnet/operator-greater-or-equal-deque-stl-clr.md)|Determina se um objeto de `deque` é maior ou igual a outro objeto de `deque` .|  
  
## Interfaces  
  
|Interface|Descrição|  
|---------------|---------------|  
|<xref:System.ICloneable>|Duplica um objeto.|  
|<xref:System.Collections.IEnumerable>|Sequência por meio dos elementos.|  
|<xref:System.Collections.ICollection>|Mantenha o grupo de elementos.|  
|<xref:System.Collections.Generic.IEnumerable%601>|Sequência por meio dos elementos digitados.|  
|<xref:System.Collections.Generic.ICollection%601>|Mantenha o grupo de elementos de tipo.|  
|<xref:System.Collections.Generic.IList%601>|Manter ordenou o grupo de elementos de tipo.|  
|IDequeValue\<\>|Mantenha o contêiner genérico.|  
  
## Comentários  
 O objeto aloca e libera armazenamento para a sequência que controla armazenada com uma matriz de identificadores que blocos designados de elementos de `Value` .  A matriz cresce sob demanda.  O crescimento ocorre de forma que o custo de acrescentando ou acrescentar um novo elemento de hora são constantes, e nenhum elemento restante é perturbado.  Você também pode remover um elemento em uma ou outra extremidade no momento, constantes e sem os outros elementos de perturbação.  Assim, um deque é uma boa candidata para o contêiner subjacente da classe [queue](../Topic/queue%20\(STL-CLR\).md) do modelo ou a classe [stack](../dotnet/stack-stl-clr.md)do modelo.  
  
 Um objeto de `deque` oferece suporte aos iteradores de acesso aleatório, que significa você pode recorrer a um determinado elemento diretamente a posição numérica, contando de zero do primeiro elemento \(\) para a frente, a [deque::size](../Topic/deque::size%20\(STL-CLR\).md)`() - 1` para o elemento \(\) na última vez.  Também significa que um deque é uma boa candidata para o contêiner subjacente da classe [priority\_queue](../Topic/priority_queue%20\(STL-CLR\).md)do modelo.  
  
 Um iterador de deque armazena um identificador para o objeto associado de deque, junto com a diferença que designa do elemento.  Você pode usar iteradores apenas com seus objetos de contêiner associados.  A diferença de um elemento de deque `not` é necessariamente o mesmo que sua posição.  O primeiro elemento inserido tem zeros diagonal, o elemento anexado seguir tem 1 diagonal, mas o elemento é pré\-anexado a seguir tem \-1 diagonal.  
  
 Inserir ou apagar os elementos em uma ou outra extremidade fazem `not` altere o valor de um elemento armazenado em qualquer diferença válido.  Inserindo ou apagando um elemento dentro, no entanto, a alteração de `can` o valor do elemento armazenado em uma diferença determinada, assim o valor designado por um iterador também pode ser alterada. \(O contêiner pode ter que copiar para cima ou para baixo nos elementos para criar um orifício antes de uma inserção ou para preencher um orifício depois de um erase.\) Entretanto, um iterador de deque permanece válido desde que a tendência designa um elemento válido.  Além disso, um iterador permanece válido dereferencable \-\- você pode usá\-lo para acessar ou modificar o valor do elemento que designa \-\- desde que a tendência é diferente da tendência para o iterador retornado por `end()`.  
  
 Apagando ou removendo um elemento chama o destruidor para seu valor armazenado.  Destruir o contêiner apaga todos os elementos.  Assim, um contêiner cujo tipo de elemento é uma classe de referência garante que nenhum elemento é maior que o contêiner.  A observe, entretanto, que manipula um contêiner faz `not` destrói seus elementos.  
  
## Requisitos  
 **Cabeçalho:** \<cliext\/deque\>  
  
 cliext de**Namespace:**  
  
## Consulte também  
 [list](../dotnet/list-stl-clr.md)   
 [priority\_queue](../Topic/priority_queue%20\(STL-CLR\).md)   
 [queue](../Topic/queue%20\(STL-CLR\).md)   
 [stack](../dotnet/stack-stl-clr.md)   
 [vector](../dotnet/vector-stl-clr.md)   
 [Biblioteca STL\/CLR](../dotnet/stl-clr-library-reference.md)